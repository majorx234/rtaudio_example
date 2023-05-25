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

#ifndef GEN_WAVE_FACTORY_HPP_
#define  GEN_WAVE_FACTORY_HPP_

#include "gen_wave.hpp"
#include <string>

class GenWaveFactory {
public:
  static GenWave* getInstance(std::string wave_form, int freq, float duration, char* filename = nullptr);
};

#endif  // GEN_WAVE_FACTORY_HPP_
