#include <string>
#include "sine_wave.h"
#include "gen_wave_factory.h"

GenWave* GenWaveFactory::getInstance(std::string wave_form) {
  GenWave* pWave = nullptr;
  if(wave_form == "sine")
  {
    pWave = new SineWave();
    /* } else if (wave_form == "saw") {
       pWave = new SawWave();*/
  }
  return pWave;
}
