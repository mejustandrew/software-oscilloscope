#include"Initialize.h"


static int Callback( const void *inputBuffer, void *outputBuffer,
                             unsigned long framesPerBuffer,
                             const PaStreamCallbackTimeInfo* timeInfo,
                             PaStreamCallbackFlags statusFlags,
                             void *userData )
  {
        SAMPLE *out = (SAMPLE*)outputBuffer;
//        const SAMPLE *in = (const SAMPLE*)inputBuffer;
		short* in=(short*)inputBuffer;
        unsigned long i;
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
	double k=(request->GetTimeBase());
	return c->GetSamples(k,request->GetTreshold());
}

IDataResponse* GetSpectrumSamples(IDataRequest* request)
{
	Container *c=Singletone::GetContainer();
	double k=(request->GetTimeBase());
	return c->GetSamples(k);
}

void Initialize(Container* c)
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
       inputParameters.channelCount = 1;       /* stereo input */
       inputParameters.sampleFormat = PA_SAMPLE_TYPE;
       inputParameters.suggestedLatency = Pa_GetDeviceInfo( inputParameters.device )->defaultLowInputLatency;
       inputParameters.hostApiSpecificStreamInfo = NULL;
	   double sample_rate=GetSampleRate(&inputParameters,nullptr);
	   c->SetSampleRate(sample_rate);
       err = Pa_OpenStream(
                 &stream,
                 &inputParameters,
                 nullptr,
				 sample_rate,
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

double GetSampleRate( const PaStreamParameters *inputParameters , const PaStreamParameters * )
{
	PaError err;
	double standardSampleRates[] = {
		8000.0, 9600.0, 11025.0, 12000.0, 16000.0, 22050.0, 24000.0, 32000.0,
		44100.0, 48000.0, 88200.0, 96000.0, 192000.0, -1 /* negative terminated  list */
	};
	double sampleRate;
	for( int i = 0; standardSampleRates[i] > 0; i++ )
	{
		err = Pa_IsFormatSupported( inputParameters, NULL, standardSampleRates[i] );
		if( err == paFormatIsSupported )
		{
			sampleRate = standardSampleRates[i];
		}
		else
			break;
	}
	return sampleRate;
}

double Get_sample_rate()
{
	return Singletone::GetContainer()->GetSampleRate();
}