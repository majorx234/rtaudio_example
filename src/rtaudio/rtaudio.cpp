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

#include "rtaudio.hpp"
#include <stdio.h>

using namespace std;

std::vector<float> read_data(){
  std::vector<float> values_data{};
  float sample = 0.0;
  int i = 0;
  do {
    i = scanf("%f" , &sample);
    if(i!=EOF)
    {
      values_data.push_back(sample);
    }
    // Einfügen! abbruch wenn speicher voll
  } while (i != EOF);

  return values_data;
}

void write_data(std::vector<float> values_data){
  size_t num_samples = values_data.size();
  // not needed
  // printf("%d\n", num_samples_);
  for(int i = 0; i<num_samples; i++) {
    printf("%f\n", values_data[i]);
  }
}
