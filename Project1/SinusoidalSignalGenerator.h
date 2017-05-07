#pragma once
#include "SignalGenerator.h"

class SinusoidalSignalGenerator : public SignalGenerator
{
private:
	double amplitude;
	double frequency;
public:
	SinusoidalSignalGenerator(float sampleRate, float amplitude, float frequency);
	void SetAmplitude(float amplitude);
	void SetFrequency(float frequency);
	virtual IDataResponse * GetSignal(IDataRequest * request) override;
};