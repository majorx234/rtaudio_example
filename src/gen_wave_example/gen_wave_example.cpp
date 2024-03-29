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

#include "gen_wave_factory.hpp"

int main(int argc, char *argv[]) {
  std::string wave_form(argv[1]);
  GenWave* my_wave;
  
  if(argc == 4 )
  {
    int freq(atoi(argv[2]));
    float duration(atof(argv[3]));
    my_wave = GenWaveFactory::getInstance(wave_form, freq, duration);
  } else if (argc == 3) {
    char* filename = argv[2];
    my_wave = GenWaveFactory::getInstance(wave_form, 0, 0.0, filename);
  }
  my_wave->print(); 
  //delete my_wave;
  return 0;
}
