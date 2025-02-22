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

#include <pulse/pulseaudio.h>
#include <pulse/simple.h>

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

#include "rtaudio.hpp"
// #include <pulse/rtclock.h> // zukunftslaura und marc werden sich freuen
#define BUFSIZE 1000
//1024

pa_sample_spec sample_spec = {
    .format = PA_SAMPLE_FLOAT32LE,
    .rate = 48000,
    .channels = 1
};

int playback(float* in_audio, size_t size, char *argv[]) {
  // need a autochoose default device
  // pacmd list-sources | grep -e 'index:' -e device.string -e 'name:'
  // const char *device = "alsa_output.pci-0000_00_1f.3.analog-stereo";
  // diffrent device  (alsa_output.pci-0000_00_1b.0.analog-stereo)
  const char *device = "alsa_output.pci-0000_00_1f.3.analog-stereo";
  pa_simple *stream = NULL;;
  int error;
  
  // open a playback stream
  if (!(stream = pa_simple_new(NULL, argv[0], PA_STREAM_PLAYBACK, device, "playback", &sample_spec, NULL, NULL, &error))) {
     printf("pa_simple_new() failed: %s\n", pa_strerror(error));
  }
  
  if(pa_simple_write(stream, in_audio, size * sizeof(float) , &error) < 0){
      printf("pa_simple_write() failed: %s \n", pa_strerror(error) );
  }
  /* Make sure that every single sample was played */
  if (pa_simple_drain(stream, &error) < 0) {
   printf("pa_simple_drain() failed: %s\n", pa_strerror(error));
  }
  pa_simple_free(stream);
  return 0;
}

int main(int argc, char *argv[])
{
  //float* data = (float*)malloc(48000*sizeof(float));
  //memset(data,0 ,48000*sizeof(float));
  size_t size = 0;
  //float* data = einlesen(&size);
  std::vector samples = read_data();
  /* do sth with data */
  playback(samples.data(), samples.size(), argv);
  //  delete data;
  return 0;
}
