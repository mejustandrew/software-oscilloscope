#pragma once
#include "Spectrum.h"
#include "AudioSingleChannelDataProvider.h"
#include "CustomSingleChannelDataProvider.h"
#include "SinusoidalSignalGenerator.h"
#include "SignalModels.h"

class SpectrumManager
{
	SpectrumFrame* spectrumLeft, *spectrumRight;
	AudioSingleChannelDataProvider *audioLeftChannelDataProvider, *audioRightChannelDataProvider;
	CustomSingleChannelDataProvider *customLeftDataProvider, *customRightDataProvider;
	SinusoidalSignalGenerator * sinusiodalLeftSignalGenerator, *sinusiodalRightSignalGenerator;

public:
	SpectrumManager();
	void ShowLeftChannelSpectrum();
	void ShowRightChannelSpectrum();
	void SwitchSignalSourceToAudio();
	void SwitchSignalSourceToCustomSinusoidal(SinusoidalSignal sinusoidalLeftChannelSignal, SinusoidalSignal sinusoidalRightChannelSignal);
	void SwitchSignalSourceToCustomGaussianNoise(GaussianNoise gaussianNoise);
	void SwitchSignalSourceToCustomPWM(PwmSignal pwmSignal);
	void Close();
};