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

#include <string>
#include "sine_wave.hpp"
#include "saw_wave.hpp"
#include "insaw_wave.hpp"
#include "sample_wave.hpp"
#include "tri_wave.hpp"
#include "sine_amp_mod_wave.hpp"
#include "gen_wave_factory.hpp"

GenWave* GenWaveFactory::getInstance(std::string wave_form, int freq, float duration, char* filename) {
  GenWave* pWave = nullptr;
  if(wave_form == "sine") {
    pWave = new SineWave(freq, duration);
  }else if (wave_form == "saw") {
    pWave = new SawWave(freq, duration);
  }else if (wave_form == "insaw") {
    pWave = new InSawWave(freq, duration);  
  }else if (wave_form == "tri") {
    pWave = new TriWave(freq, duration);  
  }else if (wave_form == "sample") {
    pWave = new SampleWave(filename);
  } else if(wave_form == "sine_amp_mod") {
    pWave = new SineAmpModWave(freq, duration,10,0);
  } else {
    // todo: Zonk soundwave generieren 
  }
  return pWave;
}
