#pragma once
#include "AudioDataProvider.h"
#include "DataSocketSender.h"
#include "DataDrawer.h"
#include "PanelSpecs.h"
#include "CustomDataProvider.h"
#include "SinusoidalSignalGenerator.h"
#include "SignalModels.h"
#include <vector>

class Manager
{
	PanelSpecs *panelSpecsLeft, *panelSpecsRight;
	AudioDataProvider *audioDataProvider;
	CustomDataProvider *customDataProvider;
	SinusoidalSignalGenerator *sinusoidalSignalGenerator;
	IDataProvider *dataProvider;
	DataSocketSender *dataSocketSender;
	DataDrawer *dataDrawer;
	bool isActive;
	void ProcessData();
	std::vector<float> ConvertToMaxSizedVectorWithScaling(IDataResponse * response, int maxSize, float scalingFactor, int offset);

	DataContainer * oldResponse;
	DataContainer * MakeCallForData();
public:
	Manager(PanelSpecs *panelSpecsLeft, PanelSpecs *panelSpecsRight);
	~Manager();
	void StartProcessingData();
	void StopProcessingData();
	void SwitchSignalSourceToAudio();
	void SwitchSignalSourceToCustomSinusoidal(SinusoidalSignal sinusoidalSignal);
	void SwitchSignalSourceToCustomGaussianNoise(GaussianNoise gaussianNoise);
	void SwitchSignalSourceToCustomPWM(PwmSignal pwmSignal);
};
