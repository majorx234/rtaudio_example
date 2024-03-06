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

#include "RtAudio.h"

int main() {
  RtAudio *audio = 0;

  // Default RtAudio constructor
  try {
    audio = new RtAudio();
  }
  catch (RtAudioErrorType &error) {
    // Handle the exception here
    //error.printMessage();
    printf("some audio error happens");
  }

  // Clean up
  delete audio;
}
