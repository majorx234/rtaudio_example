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
#include <sndfile.hh>

int main(int argc, char *argv[]) {
  const unsigned int samplerate = 48000;
  float duration = 1.0;
  unsigned int num_samples = static_cast<unsigned int>(duration * samplerate);
  
  char* filename = argv[1];

  SndfileHandle wave_file;
  wave_file = SndfileHandle(filename);

  /*
  printf("Opened file %s\n",filename);
  printf("Samplerate: %d\n",wave_file.samplerate() );
  printf("Channels %d\n",wave_file.channels() );
  */
  float* buffer = reinterpret_cast<float*>(malloc(num_samples * sizeof(float)));

  wave_file.readf(buffer,num_samples);

  printf("%d\n",num_samples);
  unsigned int i = 0;
  while(i < num_samples) {
    printf("%f\n", buffer[i]);
    i++;
  }
  free(buffer);

}
    
