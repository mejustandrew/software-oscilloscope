#pragma once
#include "AudioDualChannelDataProvider.h"
#include "DataSocketSender.h"
#include "DataDrawer.h"
#include "PanelSpecs.h"
#include "CustomDualChannelDataProvider.h"
#include "SinusoidalSignalGenerator.h"
#include "GaussianNoiseGenerator.h"
#include "SignalModels.h"
#include <vector>

class Manager
{
	PanelSpecs *panelSpecsLeft, *panelSpecsRight;
	AudioDualChannelDataProvider *audioDualChannelDataProvider;
	CustomDualChannelDataProvider *customDualChannelDataProvider;
	SinusoidalSignalGenerator *sinusoidalSignalLeftChannelGenerator;
	SinusoidalSignalGenerator *sinusoidalSignalRightChannelGenerator;
	GaussianNoiseGenerator *gaussianNoiseLeftChannelGenerator;
	GaussianNoiseGenerator *gaussianNoiseRightChannelGenerator;

	IDualChannelDataProvider *dataProvider;
	DataSocketSender *dataSocketSender;
	DataDrawer *dataDrawer;
	bool isActive;
	bool leftSignalSlope, rightSignalSlope;

	void EnsureSlopeIsUpdated();
	void ProcessData();
	void ConvertResponseToVector(DataContainer * responseContainer);

	DataContainer * oldResponse;
	DataContainer * MakeCallForData();
	std::vector<float> leftBuffer, rightBuffer;

public:
	Manager(PanelSpecs *panelSpecsLeft, PanelSpecs *panelSpecsRight);
	~Manager();
	void StartProcessingData();
	void StopProcessingData();
	void SwitchSignalSourceToAudio();
	void SwitchSignalSourceToCustomSinusoidal(SinusoidalSignal sinusoidalLeftChannelSignal, SinusoidalSignal sinusoidalRightChannelSignal);
	void SwitchSignalSourceToCustomGaussianNoise(GaussianNoise gaussianNoiseLeftChannelSignal, GaussianNoise gaussianNoiseRightChannelSignal);
	void SwitchSignalSourceToCustomPWM(PwmSignal pwmSignal);
	void SetLeftSlope(bool positive);
	void SetRightSlope(bool positive);
};
