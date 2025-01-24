/******************************************/
/*
  rtplay_wave.cpp
  WIP by Majorx234

  This program will output someting soon
*/
/******************************************/
#include "RtAudio.h"
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <signal.h>

#include "rtaudio.hpp"

typedef double MY_TYPE;

#include <unistd.h>
#define SLEEP(milliseconds) usleep((unsigned long)(milliseconds * 1000.0))

// Interrupt handler function
bool done;
static void finish(int /*ignore*/) { done = true; }

#define TIME 1.0

struct WaveData {
  float *data;
  size_t length;
};

void errorCallback(RtAudioErrorType /*type*/, const std::string &errorText) {
  // This example error handling function simply outputs the error message to
  // stderr.
  std::cerr << "\nerrorCallback: " << errorText << "\n\n";
}

unsigned int getDeviceIndex(std::vector<std::string> deviceNames) {
  unsigned int i;
  std::string keyHit;
  std::cout << '\n';
  for (i = 0; i < deviceNames.size(); i++)
    std::cout << "  Device #" << i << ": " << deviceNames[i] << '\n';
  do {
    std::cout << "\nChoose a device #: ";
    std::cin >> i;
  } while (i >= deviceNames.size());
  std::getline(std::cin, keyHit); // used to clear out stdin
  return i;
}

unsigned int channels;
RtAudio::StreamOptions options;
unsigned int frameCounter = 0;
bool checkCount = false;
unsigned int nFrames = 0;
const unsigned int callbackReturnValue = 1; // 1 = stop and drain, 2 = abort
double streamTimePrintIncrement = 1.0;      // seconds
double streamTimePrintTime = 1.0;           // seconds

// Interleaved buffers
int process(void *outputBuffer, void * /*inputBuffer*/,
            unsigned int nBufferFrames, double streamTime,
            RtAudioStreamStatus status, void *wave_data_raw) {

  WaveData *wave_data = (WaveData *)wave_data_raw;
  extern unsigned int channels;
  MY_TYPE *buffer = (MY_TYPE *)outputBuffer;
  double *lastValues = (double *)wave_data->data;

  for (size_t i = 0; i < nBufferFrames; i++) {
    *buffer++ = (MY_TYPE)(lastValues[i]);
  }

  frameCounter += nBufferFrames;
  if (frameCounter >= nFrames)
    return callbackReturnValue;
  return 0;
}

int main(int argc, char *argv[]) {
  unsigned int bufferFrames = 512;
  unsigned int fs = 48000;
  unsigned int device = 0;
  unsigned int offset = 0;
  channels = 2;

  size_t size = 0;
  // float* data = einlesen(&size);
  std::vector samples = read_data();

  // Specify our own error callback function.
  RtAudio dac(RtAudio::UNSPECIFIED, &errorCallback);

  std::vector<unsigned int> deviceIds = dac.getDeviceIds();
  if (deviceIds.size() < 1) {
    std::cout << "\nNo audio devices found!\n";
    exit(1);
  }

  WaveData wave_data = {samples.data(), samples.size()};
  nFrames = samples.size();

  // Tell RtAudio to output all messages, even warnings.
  dac.showWarnings(true);

  // Set our stream parameters for output only.
  bufferFrames = 512;
  RtAudio::StreamParameters oParams;
  oParams.nChannels = channels;
  oParams.firstChannel = offset;

  if (device == 0)
    oParams.deviceId = dac.getDefaultOutputDevice();
  else {
    if (device >= deviceIds.size())
      device = getDeviceIndex(dac.getDeviceNames());
    oParams.deviceId = deviceIds[device];
  }

  options.flags = RTAUDIO_HOG_DEVICE;
  options.flags |= RTAUDIO_SCHEDULE_REALTIME;
  options.flags |= RTAUDIO_NONINTERLEAVED;

  // An error in the openStream() function can be detected either by
  // checking for a non-zero return value OR by a subsequent call to
  // isStreamOpen().
  if (dac.openStream(&oParams, NULL, RTAUDIO_FLOAT32, fs, &bufferFrames,
                     &process, (void *)&wave_data, &options)) {
    std::cout << dac.getErrorText() << std::endl;
    goto cleanup;
  }
  if (dac.isStreamOpen() == false)
    goto cleanup;

  // std::cout << "Stream latency = " << dac.getStreamLatency() << "\n" <<
  // std::endl;

  // Stream is open ... now start it.
  if (dac.startStream()) {
    std::cout << dac.getErrorText() << std::endl;
    goto cleanup;
  }

  if (checkCount) {
    while (dac.isStreamRunning() == true)
      SLEEP(100);
  } else {
    std::cout << "\nPlaying ... quit with Ctrl-C (buffer size = "
              << bufferFrames << ").\n";

    // Install an interrupt handler function.
    done = false;
    (void)signal(SIGINT, finish);

    while (!done && dac.isStreamRunning())
      SLEEP(100);

    // Block released ... stop the stream
    if (dac.isStreamRunning())
      dac.stopStream(); // or could call dac.abortStream();
  }

cleanup:
  if (dac.isStreamOpen())
    dac.closeStream();

  return 0;
}
