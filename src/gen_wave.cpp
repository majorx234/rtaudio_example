#include "gen_wave.h"

GenWave::GenWave() {}
GenWave::~GenWave() {
    if (values) {
      delete values;
    }
 }
