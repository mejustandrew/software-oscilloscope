  #include <math.h>
  #include "portaudio.h"
  #include"Singletone.h"
  #include"Exported.h"
  #include<iostream>
  #define SAMPLE_RATE         (192000)
  #define PA_SAMPLE_TYPE      paInt16
  #define FRAMES_PER_BUFFER   (64)
  
  typedef float SAMPLE;


  static int Callback( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData );

  void Initialize();