#pragma once
#include "SignalGenerator.h"

class SinusoidalSignalGenerator : public SignalGenerator
{
private:
	double amplitude;
	double frequency;
public:
	SinusoidalSignalGenerator(float amplitude, float frequency, float sampleRate = 192000);
	void SetAmplitude(float amplitude);
	void SetFrequency(float frequency);
	virtual IDataResponse * GetSignal(IDataRequest * request) override;
	virtual IDataResponse * GetSignal(int numberOfSamples);
};