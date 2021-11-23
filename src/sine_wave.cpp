#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES

#include "sine_wave.h"

SineWave::SineWave()
{
  float duration = 1.0;
  const unsigned int sample_rate = 48000;

  freq = 440;
  num_samples = static_cast<int>(duration * sample_rate);
  values = (float*)malloc(num_samples*sizeof(float));
  for(int i = 0;i<num_samples;i++)
  {
    values[i] =  sin((2 * M_PI * freq * i) / sample_rate)  ;
  }
}

SineWave::~SineWave() {
  if (values) {
    delete values;
  }
}

void SineWave::print() {
  for(int i = 0; i<num_samples; i++){
    printf("%f\n", values[i]); 
  }
}
