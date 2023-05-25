/* 
 * This file is part of the rtaudio_example distribution (https://github.com/majorx234/rtaudio_example ).
 * Copyright (c) 2021 Majorx234
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SINE_AMP_MOD_WAVE_HPP_
#define  SINE_AMP_MOD_WAVE_HPP_

#include "gen_wave.hpp"

class SineAmpModWave : public GenWave {
public:
  SineAmpModWave(int freq, float duration, int frew_amp = 10, int offset = 0);
  ~SineAmpModWave();
  void print();      
};

#endif // SINE_AMP_MOD_WAVE_HPP_
