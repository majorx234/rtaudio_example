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
#include <math.h> /* needed for round() function */

int main(int argc, char *argv[]) {
  float sample;
  int i = 0;
  int s;
  int nsampl = 0;

  do {
    /* read in float value between -1 and 1 */
    i = scanf("%f" , &sample);
    /* scale to get value between 0 and 100 */
    s = static_cast<int>(round((sample+1) * 50));
    printf("[%5d]",nsampl );
    nsampl++;
    while( s > 0) {
      printf("-");
      s = s-1;
    }
    printf("*\n");
  }
  while(i != EOF);    
  
  return 0;
}

                     
