  
#include <math.h>
  #include "portaudio.h"
  #include"BufferManagerSingleton.h"
  #include"Exported.h"


  #define PA_SAMPLE_TYPE      paInt16
  #define FRAMES_PER_BUFFER   (8)
  
  typedef float SAMPLE;


  static int Callback( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData );

  bool InternInitialize();

double  GetSampleRate( const PaStreamParameters *inputParameters , const PaStreamParameters * );
