#include "SinusoidalSignalGenerator.h"
#include <math.h>

SinusoidalSignalGenerator::SinusoidalSignalGenerator(float amplitude, float frequency,float sampleRate) :
	SignalGenerator(sampleRate), amplitude(amplitude), frequency(frequency)
{
}

void SinusoidalSignalGenerator::SetAmplitude(float amplitude)
{
	this->amplitude = amplitude;
}

void SinusoidalSignalGenerator::SetFrequency(float frequency)
{
	this->frequency = frequency;
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

IDataResponse * SinusoidalSignalGenerator::GetSignal(int numberOfSamples)
{
	response->Destroy();
	float pi = atan(1) * 4;
	float step = pi * 2 * frequency / sampleRate;
	for (float i = 0; i < responseSize; i++)
	{
		response->AddValue(amplitude * sin(step * i));
	}

	return response->GetBufferWithLoopSize(numberOfSamples);
}
