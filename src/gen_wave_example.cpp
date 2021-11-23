#include "gen_wave_factory.h"

int main(int argc, char *argv[])
{
  std::string wave_form(argv[1]);
  GenWave* my_wave = GenWaveFactory::getInstance(wave_form);
  my_wave->print();
  //delete my_wave;
  return 0;
}
