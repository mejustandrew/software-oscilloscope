#pragma once
#include "SignalGenerator.h"


class GaussianNoiseGenerator : public SignalGenerator
{
private:
	float variance;
	float mean;

	void PopulateResponseBuffer();

public:
	GaussianNoiseGenerator(float variance, float mean, float sampleRate = 192000);
	void SetVariance(float variance);
	void SetMean(float mean);
	virtual IDataResponse * GetSignal(IDataRequest * request) override;
	virtual IDataResponse * GetSignal(int numberOfSamples);
};