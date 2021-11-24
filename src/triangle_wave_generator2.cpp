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
#define END 48000

int main() {
  unsigned int n = 0;
  unsigned int max = END/480;
  int number = 0;
  bool switcher = true;
  while (n < END) {    
    if((n % max) == 0) {
      if(switcher == true) {
        switcher = false;
      } else {
        switcher = true;
      }
    }
    float output = (number/50.0)+1;
    printf("%f \n",output );
    if(switcher == true) {
      number++;
    } else {
      number--;
    }
    n++;
  } 
  return 0;
}
