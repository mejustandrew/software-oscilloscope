#pragma once
#include "Spectrum.h"
#include "AudioSingleChannelDataProvider.h"
#include "CustomSingleChannelDataProvider.h"
#include "SinusoidalSignalGenerator.h"
#include "SignalModels.h"
#include "GaussianNoiseGenerator.h"

class SpectrumManager
{
	SpectrumFrame *spectrumLeft, *spectrumRight;
	AudioSingleChannelDataProvider *audioLeftChannelDataProvider, *audioRightChannelDataProvider;
	CustomSingleChannelDataProvider *customLeftDataProvider, *customRightDataProvider;
	SinusoidalSignalGenerator *sinusiodalLeftSignalGenerator, *sinusiodalRightSignalGenerator;
	GaussianNoiseGenerator *gaussianNoiseLeftSignalGenerator, *gaussianNoiseRightSignalGenerator;


public:
	SpectrumManager();
	void ShowLeftChannelSpectrum();
	void ShowRightChannelSpectrum();
	void SwitchSignalSourceToAudio();
	void SwitchSignalSourceToCustomSinusoidal(SinusoidalSignal sinusoidalLeftChannelSignal, SinusoidalSignal sinusoidalRightChannelSignal);
	void SwitchSignalSourceToCustomGaussianNoise(GaussianNoise gaussianNoiseLeftChannel, GaussianNoise gaussianNoiseRightChannel);
	void SwitchSignalSourceToCustomPWM(PwmSignal pwmSignal);
	void Close();
};