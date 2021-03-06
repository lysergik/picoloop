/* Copyright 2013-2016 Matt Tytel
 *
 * mopo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mopo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mopo.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#ifndef TWYTCH_RESONANCE_LOOKUP_H
#define TWYTCH_RESONANCE_LOOKUP_H

#include "twytch_common.h"
#include "twytch_utils.h"

#include <cmath>

namespace mopotwytchsynth {

  namespace {
    const int Q_RESOLUTION = 2046;
  } // namespace

  class ResonanceLookupSingleton {
    public:
      ResonanceLookupSingleton() {
        for (int i = 0; i < Q_RESOLUTION + 2; ++i) {
          q_lookup_[i] = twytchutils::magnitudeToQ((1.0 * i) / Q_RESOLUTION);
        }
      }

      mopo_float qLookup(mopo_float magnitude) const {
        mopo_float index = Q_RESOLUTION * twytchutils::clamp(magnitude, 0.0, 1.0);
        int int_index = index;
        mopo_float fraction = index - int_index;

        return INTERPOLATE(q_lookup_[int_index],
                           q_lookup_[int_index + 1], fraction);
      }

    private:
      mopo_float q_lookup_[Q_RESOLUTION + 2];
  };

  class ResonanceLookup {
    public:
      static mopo_float qLookup(mopo_float magnitude) {
        return lookup_.qLookup(magnitude);
      }

    private:
      static const ResonanceLookupSingleton lookup_;
  };
} // namespace mopo

#endif // RESONANCE_LOOKUP_H
