#include "GaussianNoiseGenerator.h"
#include <random>

GaussianNoiseGenerator::GaussianNoiseGenerator(float variance, float mean, float sampleRate)
	: SignalGenerator(sampleRate), variance(variance), mean(mean)
{
}

void GaussianNoiseGenerator::SetVariance(float variance)
{
	this->variance = variance;
}

void GaussianNoiseGenerator::SetMean(float mean)
{
	this->mean = mean;
}

IDataResponse * GaussianNoiseGenerator::GetSignal(IDataRequest * request)
{
	PopulateResponseBuffer();

	return response->GetBufferWithLoopSize(request->GetTimeBase()*sampleRate, request->GetTreshold());
}

IDataResponse * GaussianNoiseGenerator::GetSignal(int numberOfSamples)
{
	PopulateResponseBuffer();

	return response->GetBufferWithLoopSize(numberOfSamples);
}

void GaussianNoiseGenerator::PopulateResponseBuffer()
{
	std::random_device rd;
	std::mt19937 e2(rd());
	std::normal_distribution<float> distribution(mean, variance);
	int i = 0;
	float number;
	float distributionMean = distribution.mean();
	while (i < responseSize)
	{
		number = distribution(e2);
		i++;
		response->AddValue((number - distributionMean) / 100); //patch: scalling output
	}
}
