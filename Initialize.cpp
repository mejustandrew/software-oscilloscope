#include"Initialize.h"


static int Callback( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
  {
        SAMPLE *out = (SAMPLE*)outputBuffer;
        const SAMPLE *in = (const SAMPLE*)inputBuffer;
        unsigned int i;
        (void) timeInfo; /* Prevent unused variable warnings. */
        (void) statusFlags;
       (void) userData;
	   double to_export;
	   Container *cont=Singletone::GetContainer();
       if( inputBuffer != NULL )
       {
           for( i=0; i<framesPerBuffer; i++ )
		   {
				 to_export=(*in++);
				 cont->Add(to_export);
		   }
       }
       
       return paContinue;
   }

IDataResponse* GetSignalSamples(IDataRequest* request)
{
	Container *c=Singletone::GetContainer();
	return c->GetSamples(request->GetTimeBase()*SAMPLE_RATE+1);
}

void Initialize()
{
	PaStreamParameters inputParameters;
       PaStream *stream;
       PaError err;

       err = Pa_Initialize();
       if( err != paNoError ) goto error;
   
       inputParameters.device = Pa_GetDefaultInputDevice(); /* default input device */
       if (inputParameters.device == paNoDevice) {
         std::cout<<"Error: No default input device.\n";
         goto error;
       }
       inputParameters.channelCount = 2;       /* stereo input */
       inputParameters.sampleFormat = PA_SAMPLE_TYPE;
       inputParameters.suggestedLatency = Pa_GetDeviceInfo( inputParameters.device )->defaultLowInputLatency;
       inputParameters.hostApiSpecificStreamInfo = NULL;
  
   
       err = Pa_OpenStream(
                 &stream,
                 &inputParameters,
                 nullptr,
                 SAMPLE_RATE,
                 FRAMES_PER_BUFFER,
                 0, /* paClipOff, */  /* we won't output out of range samples so don't bother clipping them */
                 Callback,
                 NULL );
       if( err != paNoError ) goto error;
   
       err = Pa_StartStream( stream );
       if( err != paNoError ) goto error;
		
       /*std::cout<<"Hit ENTER to stop program.\n";
       getchar();
       err = Pa_CloseStream( stream );
       if( err != paNoError ) goto error;
   
       Pa_Terminate();
       return;*/
   
   error:
//       Pa_Terminate();
       std::cout<<  "An error occured while using the portaudio stream\n";
       std::cout<<"Error number:"<< err<<"\n" ;
       std::cout<<"Error message:"<< Pa_GetErrorText( err )<<"\n";

}