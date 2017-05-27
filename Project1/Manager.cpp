#include "Manager.h"
#include <thread>
#include "DataRequest.h"

Manager::Manager(PanelSpecs * panelSpecsLeft, PanelSpecs * panelSpecsRight):
	panelSpecsLeft(panelSpecsLeft), panelSpecsRight(panelSpecsRight)
{
	audioDualChannelDataProvider = new AudioDualChannelDataProvider;//TODO: Ensure that audio data provider is successfuly initialized and can provide data
	dataProvider = audioDualChannelDataProvider;
	sinusoidalSignalLeftChannelGenerator = new SinusoidalSignalGenerator(0, 0);
	sinusoidalSignalRightChannelGenerator = new SinusoidalSignalGenerator(0, 0);
	gaussianNoiseLeftChannelGenerator = new GaussianNoiseGenerator(0, 0);
	gaussianNoiseRightChannelGenerator = new GaussianNoiseGenerator(0, 0);

	customDualChannelDataProvider = new CustomDualChannelDataProvider(sinusoidalSignalLeftChannelGenerator, sinusoidalSignalRightChannelGenerator);

	//dataSocketSender = new DataSocketSender;
	dataDrawer = new DataDrawer(panelSpecsLeft, panelSpecsRight);
	oldResponse = new DataContainer;
}

Manager::~Manager()
{
	delete audioDualChannelDataProvider;
	delete dataSocketSender;
	delete dataDrawer;
	delete oldResponse;
}

void Manager::StartProcessingData()
{
	isActive = true;
	std::thread processingThread(&Manager::ProcessData, this);
	processingThread.detach();
}

void Manager::StopProcessingData()
{
	isActive = false;
}

void Manager::SwitchSignalSourceToAudio()
{
	dataProvider = audioDualChannelDataProvider;
}

void Manager::SwitchSignalSourceToCustomSinusoidal(SinusoidalSignal sinusoidalLeftChannelSignal, SinusoidalSignal sinusoidalRightChannelSignal)
{
	sinusoidalSignalLeftChannelGenerator->SetAmplitude(sinusoidalLeftChannelSignal.GetAmplitude() / 1000); //convert to mV
	sinusoidalSignalLeftChannelGenerator->SetFrequency(sinusoidalLeftChannelSignal.GetFrequency());
	sinusoidalSignalRightChannelGenerator->SetAmplitude(sinusoidalRightChannelSignal.GetAmplitude() / 1000); //convert to mV
	sinusoidalSignalRightChannelGenerator->SetFrequency(sinusoidalRightChannelSignal.GetFrequency());
	customDualChannelDataProvider->ChangeLeftChannelGenerator(sinusoidalSignalLeftChannelGenerator);
	customDualChannelDataProvider->ChangeRightChannelGenerator(sinusoidalSignalRightChannelGenerator);

	dataProvider = customDualChannelDataProvider;
}

void Manager::SwitchSignalSourceToCustomGaussianNoise(GaussianNoise gaussianNoiseLeftChannelSignal, GaussianNoise gaussianNoiseRightChannelSignal)
{
	gaussianNoiseLeftChannelGenerator->SetMean(gaussianNoiseLeftChannelSignal.GetMean());
	gaussianNoiseLeftChannelGenerator->SetVariance(gaussianNoiseLeftChannelSignal.GetVariance());
	gaussianNoiseRightChannelGenerator->SetMean(gaussianNoiseRightChannelSignal.GetMean());
	gaussianNoiseRightChannelGenerator->SetVariance(gaussianNoiseRightChannelSignal.GetVariance());
	customDualChannelDataProvider->ChangeLeftChannelGenerator(gaussianNoiseLeftChannelGenerator);
	customDualChannelDataProvider->ChangeRightChannelGenerator(gaussianNoiseRightChannelGenerator);

	dataProvider = customDualChannelDataProvider;
}

void Manager::SwitchSignalSourceToCustomPWM(PwmSignal pwmSignal)
{
}

void Manager::ProcessData()
{
	DataContainer * responseContainer = new DataContainer;
	std::vector<float> leftBuffer, rightBuffer;

	while (isActive)
	{
		responseContainer = MakeCallForData();

		dataDrawer->DrawData(responseContainer->LeftChannelData, responseContainer->RightChannelData);

		if(responseContainer->LeftChannelData)responseContainer->LeftChannelData->Destroy();
		if(responseContainer->RightChannelData)responseContainer->RightChannelData->Destroy();

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	delete responseContainer;
}

DataContainer * Manager::MakeCallForData()
{
	DataRequest leftBufferRequest(panelSpecsLeft->TimeBase, panelSpecsLeft->Treshold);
	DataRequest rightBufferRequest(panelSpecsRight->TimeBase, panelSpecsRight->Treshold);

	return dataProvider->GetNewData(&leftBufferRequest, &rightBufferRequest);
}
