#include "SinusoidalSignalGenerator.h"
#include <math.h>

SinusoidalSignalGenerator::SinusoidalSignalGenerator(float sampleRate, float amplitude, float frequency) :
	SignalGenerator(sampleRate), amplitude(amplitude), frequency(frequency)
{
}

IDataResponse * SinusoidalSignalGenerator::GetSignal(IDataRequest * request)
{
	response->Destroy();
	float pi = atan(1) * 4;
	float step = pi * 2 * frequency / sampleRate;
	for (float i = 0; i < responseSize; i++)
	{
		response->AddValue(amplitude * sin(step * i));
	}

	return response->GetBufferWithLoopSize(request->GetTimeBase() * sampleRate, request->GetTreshold());
}
