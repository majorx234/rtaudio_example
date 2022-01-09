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

int main(int argc, char *argv[])
{
  unsigned int freq = atoi(argv[1]);
  float duration(atof(argv[2]));
  const unsigned int sample_rate = 48000;
  unsigned int end = static_cast<unsigned int>(sample_rate * duration);
  unsigned int n = 0;
  float fmax = sample_rate/freq; //->480

  unsigned int max = static_cast<unsigned int>(fmax);
  float s = 0;

  printf("%d\n",end);
  while(n < end) {
    s = 2*(((n % (max)) / fmax) - 0.5);
    printf("%f \n", s);
    n++;
  }
  return 0;
}
