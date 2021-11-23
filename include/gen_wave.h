#ifndef GEN_WAVE_H_
#define GEN_WAVE_H_ 
#include <cstdlib>

class GenWave {
protected:
  GenWave();
public:
  virtual ~GenWave();
  virtual void print() = 0;

protected:
  int freq;
  int num_samples;
  float* values;
      
};

#endif // GEN_WAVE_H_
