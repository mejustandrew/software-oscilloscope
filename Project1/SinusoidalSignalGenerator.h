#pragma once
#include "SignalGenerator.h"

class SinusoidalSignalGenerator : public SignalGenerator
{
private:
	double amplitude;
	double frequency;
public:
	SinusoidalSignalGenerator(float sampleRate, float amplitude, float frequency);
	virtual IDataResponse * GetSignal(IDataRequest * request) override;
};