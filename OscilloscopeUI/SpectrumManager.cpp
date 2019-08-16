#include "SpectrumManager.h"
#include "Imported.h"

SpectrumManager::SpectrumManager()
{
	audioLeftChannelDataProvider = new AudioSingleChannelDataProvider(GetSpectrumLeftSamples);
	audioRightChannelDataProvider = new AudioSingleChannelDataProvider(GetSpectrumRightSamples);
	sinusiodalLeftSignalGenerator = new SinusoidalSignalGenerator(0, 0);
	sinusiodalRightSignalGenerator = new SinusoidalSignalGenerator(0, 0);

	gaussianNoiseLeftSignalGenerator = new GaussianNoiseGenerator(0, 0);
	gaussianNoiseRightSignalGenerator = new GaussianNoiseGenerator(0, 0);

	customLeftDataProvider = new CustomSingleChannelDataProvider(sinusiodalLeftSignalGenerator);
	customRightDataProvider = new CustomSingleChannelDataProvider(sinusiodalRightSignalGenerator);

	spectrumLeft = new SpectrumFrame(nullptr, audioLeftChannelDataProvider);
	spectrumRight = new SpectrumFrame(nullptr, audioRightChannelDataProvider);
	spectrumLeft->SetSampleRate(96000);
	spectrumRight->SetSampleRate(96000);
}

void SpectrumManager::ShowLeftChannelSpectrum()
{
	if (spectrumLeft->IsShown()) return;
	spectrumLeft->Show();
	spectrumLeft->Start();
}

void SpectrumManager::ShowRightChannelSpectrum()
{
	if (spectrumRight->IsShown()) return;
	spectrumRight->Show();
	spectrumRight->Start();
}

void SpectrumManager::SwitchSignalSourceToAudio()
{
	spectrumLeft->SetDataProvider(audioLeftChannelDataProvider);
	spectrumRight->SetDataProvider(audioRightChannelDataProvider);
}

void SpectrumManager::SwitchSignalSourceToCustomSinusoidal(SinusoidalSignal sinusoidalLeftChannelSignal, SinusoidalSignal sinusoidalRightChannelSignal)
{
	sinusiodalLeftSignalGenerator->SetAmplitude(sinusoidalLeftChannelSignal.GetAmplitude() / 1000); //convert to mV
	sinusiodalLeftSignalGenerator->SetFrequency(sinusoidalLeftChannelSignal.GetFrequency());
	sinusiodalRightSignalGenerator->SetAmplitude(sinusoidalRightChannelSignal.GetAmplitude() / 1000); //convert to mV
	sinusiodalRightSignalGenerator->SetFrequency(sinusoidalRightChannelSignal.GetFrequency());
	customLeftDataProvider->ChangeSignalGenerator(sinusiodalLeftSignalGenerator);
	customRightDataProvider->ChangeSignalGenerator(sinusiodalRightSignalGenerator);

	spectrumLeft->SetDataProvider(customLeftDataProvider);
	spectrumRight->SetDataProvider(customRightDataProvider);
}

void SpectrumManager::SwitchSignalSourceToCustomGaussianNoise(GaussianNoise gaussianNoiseLeftChannel, GaussianNoise gaussianNoiseRightChannel)
{
	gaussianNoiseLeftSignalGenerator->SetMean(gaussianNoiseLeftChannel.GetMean());
	gaussianNoiseLeftSignalGenerator->SetVariance(gaussianNoiseLeftChannel.GetVariance());
	gaussianNoiseRightSignalGenerator->SetMean(gaussianNoiseRightChannel.GetMean());
	gaussianNoiseRightSignalGenerator->SetVariance(gaussianNoiseRightChannel.GetVariance());
	customLeftDataProvider->ChangeSignalGenerator(gaussianNoiseLeftSignalGenerator);
	customRightDataProvider->ChangeSignalGenerator(gaussianNoiseRightSignalGenerator);

	spectrumLeft->SetDataProvider(customLeftDataProvider);
	spectrumRight->SetDataProvider(customRightDataProvider);
}

void SpectrumManager::SwitchSignalSourceToCustomPWM(PwmSignal pwmSignal)
{
}

void SpectrumManager::Close()
{
	if (spectrumLeft->IsShown())
	{
		spectrumLeft->Hide();
		spectrumLeft->Stop();
	}

	if (spectrumRight->IsShown())
	{
		spectrumRight->Hide();
		spectrumRight->Stop();
	}
}
