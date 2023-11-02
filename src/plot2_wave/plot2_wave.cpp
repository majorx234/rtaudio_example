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
#include <math.h>
#include <iostream>

#define COLS 80
#define LINS 24


void plot(float *data, int ymin, int ymax, int nx) {
  int n, m;
  /* for each value in the range [ymin, ymax] */
  for (m = ymax; m >= ymin; m--) {
    /* on each column */
    for (n = 0; n < nx; n++) {
      /* print zero line */
      if (m == 0) printf("-");
      /* print star if rounded value matches */
      else if (lround(data[n]*ymax) == m)
        printf("*");
      /* else print blank */
      else printf(" ");
    }
    /* jmp a line */
    printf("\n");
  }
}

/*
int main(int argc, char *argv[]) {
  // Check the number of parameters
  if (argc < 3) {
    // Tell the user how to run the program
    std::cerr << "Usage: " << argv[0] << " <cols> <lins>" << std::endl;
     // "Usage messages" are a conventional way of telling the user
     // how to run a program if they enter the command incorrectly.
     //
   return 1;
  }
  int cols = atoi(argv[1]);
  int lins = atoi(argv[2]);
  printf("cols %d lins %d\n", cols, lins);    
  float sample;
  const unsigned int sample_rate = 48000;
  unsigned int samples;
  float duration = 0.0f; 
  int nsampl = 0;
  int err = scanf("%d", &samples);

  float* buffer = (float*)malloc(cols * sizeof(float));
  int n;
  
  //  do {
    // get data input from stdin into buffer //
    for(n=0; n < cols; n++)
      err = scanf("%f", &buffer[n]);

    plot(buffer, -(lins-1)/2, (lins-1)/2, cols);
    //plot(buffer, -12,12,80);
    // clear buffer //

    //for(n=0; n < cols; n++)
    //  buffer[n] = 0;
    //} while(err != EOF);
  delete buffer;
  return 0;
}
*/
#define COLS 80
#define LINS 24
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

int main() {
  float buffer[COLS];
  int err, n;
  do {
    /* get data input from stdin into buffer */
    for (n = 0; n < COLS; n++)
      err = scanf("%f", &buffer[n]);
    plot(buffer, -(LINS - 1) / 2, (LINS - 1) / 2, COLS);
    /* clear buffer */
    for (n = 0; n < COLS; n++)
      buffer[n] = 0;
  } while (err != EOF);
  return 0;
}
