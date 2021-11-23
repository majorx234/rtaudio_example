#ifndef GEN_WAVE_FACTORY_H_
#define  GEN_WAVE_FACTORY_H_

#include "gen_wave.h"
#include <string>

class GenWaveFactory
{
public:
  static GenWave* getInstance(std::string wave_form);
};

#endif  // GEN_WAVE_FACTORY_H_
