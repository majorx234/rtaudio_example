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
#include <stdlib.h>
#define FS 48000

int main(int argc, char *argv[]) {
  int freq(atoi(argv[1]));
  float duration(atof(argv[2]));
  unsigned int n = 0;
  int end = FS * duration;
  float fmax = end/freq;
  unsigned int max = static_cast<unsigned int>(fmax);
  float s = 1.0f;

  printf("%d\n",end);
  
  while(n < end) {
    if((n % (max>>1)) == 0) {
      s *= -1.0f;
    }
    printf("%f \n", s);
    n++;
  }
  return 0;
}
