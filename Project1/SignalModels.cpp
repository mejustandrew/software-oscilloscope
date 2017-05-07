#include "SignalModels.h"

double SinusoidalSignal::GetFrequency()
{
	return frequency;
}

double SinusoidalSignal::GetAmplitude()
{
	return amplitude;
}

SinusoidalSignal::SinusoidalSignal(double amplitude, double frequency):amplitude(amplitude), frequency(frequency)
{
}

double GaussianNoise::GetVariance()
{
	return variance;
}

double GaussianNoise::GetMean()
{
	return mean;
}

GaussianNoise::GaussianNoise(double variance, double mean) : variance(variance), mean(mean)
{
}

double PwmSignal::GetAmplitude()
{
	return amplitude;
}

double PwmSignal::GetDutyCycle()
{
	return dutyCycle;
}

PwmSignal::PwmSignal(double amplitude, double dutyCycle) : amplitude(amplitude), dutyCycle(dutyCycle)
{
}
