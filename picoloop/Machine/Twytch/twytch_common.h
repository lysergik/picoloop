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
#ifndef TWYTCH_COMMON_H
#define TWYTCH_COMMON_H

// Utilities.
#define UNUSED(x) (void)(x)
#define INTERPOLATE(s, e, f) ((s) + (f) * ((e) - (s)))

// Debugging.
//#if DEBUG
//#include <cassert>
//#define TWYTCH_MOPO_ASSERT(x) assert(x)
//#else
#define TWYTCH_MOPO_ASSERT(x) ((void)0)
//#endif // DEBUG

namespace mopotwytchsynth {

  typedef double mopo_float;

  const mopo_float TWYTCH_PI = 3.1415926535897932384626433832795;
  const int MAX_BUFFER_SIZE = 256;
  const int DEFAULT_BUFFER_SIZE = 256;
  const int DEFAULT_SAMPLE_RATE = 44100;
  const int MIDI_SIZE = 128;
  const int PPQ = 960; // Pulses per quarter note.
  const mopo_float VOICE_KILL_TIME = 0.02;
  const int NUM_MIDI_CHANNELS = 16;

  // Common types of events across different Processors.
  enum VoiceEvent {
    kVoiceOff,     // Stop. (e.g. release in an envelope)
    kVoiceOn,      // Start. (e.g. start attack in an envelope)
    kVoiceReset,   // Reset. Immediately reset to initial state and play.
    kVoiceKill,   // Kill. Silence voice as fast as possible.
  };
} // namespace mopo

#endif // COMMON_H
