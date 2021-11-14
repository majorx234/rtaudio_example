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

#include <stdio.h>
#define END 44100

int main() {
  unsigned int offset = 400;
  unsigned int n = offset;
  unsigned int max = END/441;
  float fmax = static_cast<float>(max);
  float s = 0;
  float factor = 1.0;
  
  while(n < END + offset) {
    //s = ((n % (2*max)) / fmax)-1;
    if((n % (2 * max)) == 0){
      factor *= -1.0;
    }
    s = factor * (((n % (2 * max)) / fmax) - 1);
    printf("%f \n", s);
    n++;
  }
  return 0;
}
