#pragma once

class SinusoidalSignal
{
	double frequency;
	double amplitude;

public:
	double GetFrequency();
	double GetAmplitude();
	SinusoidalSignal(double amplitude, double frequency);
}; 

class GaussianNoise
{
	double variance;
	double mean;

public:
	double GetVariance();
	double GetMean();
	GaussianNoise(double variance, double mean);
};

class PwmSignal
{
	double amplitude;
	double dutyCycle;

public:
	double GetAmplitude();
	double GetDutyCycle();
	PwmSignal(double amplitude, double dutyCycle);
};