#include"Initialize.h"
#include<chrono>
#include<thread>


bool InitializeResult=false;

static int Callback( const void *inputBuffer, void *outputBuffer,
					unsigned long framesPerBuffer,
					const PaStreamCallbackTimeInfo* timeInfo,
					PaStreamCallbackFlags statusFlags,
					void *userData )
{
//	SAMPLE *out = (SAMPLE*)outputBuffer;
	//        const SAMPLE *in = (const SAMPLE*)inputBuffer;
	short* in=(short*)inputBuffer;
	unsigned long i;
	(void) timeInfo; /* Prevent unused variable warnings. */
	(void) statusFlags;
	(void) userData;
	ContainersManager *cont=Singletone::GetContainer();
	if( inputBuffer != NULL )
	{
		for( i=0; i<framesPerBuffer; i+=2 )
		{
			cont->AddToLeftBuffer(*in++);//adding left sample
			cont->AddToRightBuffer(*in++);//adding right sample
		}
	}

	return paContinue;
}

IDataResponse* GetSignalLeftSamples(IDataRequest* request)
{
	ContainersManager *c=Singletone::GetContainer();
	double k=(request->GetTimeBase());
	return c->GetLeftSamples(k,request->GetTreshold());
}

IDataResponse* GetSignalRightSamples(IDataRequest* request)
{
	ContainersManager *c=Singletone::GetContainer();
	double k=(request->GetTimeBase());
	return c->GetRightSamples(k,request->GetTreshold());
}

bool Initialize()
{
	if(!InitializeResult)
		return InternInitialize();
	else return InitializeResult;
}

IDataResponse* GetSpectrumRightSamples(IDataRequest* request)
{
	ContainersManager *c=Singletone::GetContainer();
	double k=(request->GetTimeBase());
	return c->GetRightSamples(k);
}

IDataResponse* GetSpectrumLeftSamples(IDataRequest* request)
{
	ContainersManager *c=Singletone::GetContainer();
	double k=(request->GetTimeBase());
	return c->GetLeftSamples(k);
}

void StartVerify(PaStream * stream);

bool InternInitialize()
{
	PaStreamParameters inputParameters;
	PaStream *stream;
	PaError err;

	err = Pa_Initialize();
	if( err==paNoError )
	{
		inputParameters.device = Pa_GetDefaultInputDevice(); /* default input device */
		if (inputParameters.device != paNoDevice) 
		{

			inputParameters.channelCount = 1;       /* stereo input */
			inputParameters.sampleFormat = PA_SAMPLE_TYPE;
			inputParameters.suggestedLatency = Pa_GetDeviceInfo( inputParameters.device )->defaultLowInputLatency;
			inputParameters.hostApiSpecificStreamInfo = NULL;
			ContainersManager::SampleRate=GetSampleRate(&inputParameters,nullptr);

			err = Pa_OpenStream(
				&stream,
				&inputParameters,
				nullptr,
				ContainersManager::SampleRate,
				FRAMES_PER_BUFFER,
				0, /* paClipOff, */  /* we won't output out of range samples so don't bother clipping them */
				Callback,
				NULL );
			if( err == paNoError )
			{
				err = Pa_StartStream( stream );
			}
			if( err != paNoError )
			{
				InitializeResult=false;
				return false;
			}
			else
			{
				StartVerify(stream);
				InitializeResult=true;
				return true;
			}
		}
		else 
		{
			InitializeResult=false;
			return false;
		}
	}
	else 
	{
		InitializeResult=false;
		return false;
	}
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
	return ContainersManager::SampleRate/2;
}

void Verify(PaStream * stream)
{
	bool is_working=true;

	while (is_working)
	{
		std::chrono::milliseconds m(100);
		std::this_thread::sleep_for(m);
		if(Pa_IsStreamStopped(stream)==1 || Pa_IsStreamStopped(stream)<0|| Pa_IsStreamActive(stream)==0)
		{
			is_working=false;
			Pa_StopStream(stream);
			InternInitialize();
		}
	}
}

void StartVerify(PaStream * stream)
{
	std::thread t(Verify,stream);
	t.detach();
}