#include "Manager.h"
#include <thread>
#include "DataRequest.h"

Manager::Manager(PanelSpecs * panelSpecsLeft, PanelSpecs * panelSpecsRight):
	panelSpecsLeft(panelSpecsLeft), panelSpecsRight(panelSpecsRight)
{
	float sampleRate = 192000;
	audioDataProvider = new AudioDataProvider;//TODO: Ensure that audio data provider is successfuly initialized and can provide data
	dataProvider = audioDataProvider;
	sinusoidalSignalLeftChannelGenerator = new SinusoidalSignalGenerator(sampleRate, 0, 0);
	sinusoidalSignalRightChannelGenerator = new SinusoidalSignalGenerator(sampleRate, 0, 0);
	customDataProvider = new CustomDataProvider(sinusoidalSignalLeftChannelGenerator, sinusoidalSignalRightChannelGenerator);

	//dataSocketSender = new DataSocketSender;
	dataDrawer = new DataDrawer(panelSpecsLeft, panelSpecsRight);
	oldResponse = new DataContainer;
}

Manager::~Manager()
{
	delete audioDataProvider;
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
	dataProvider = audioDataProvider;
}

void Manager::SwitchSignalSourceToCustomSinusoidal(SinusoidalSignal sinusoidalLeftChannelSignal, SinusoidalSignal sinusoidalRightChannelSignal)
{
	sinusoidalSignalLeftChannelGenerator->SetAmplitude(sinusoidalLeftChannelSignal.GetAmplitude() / 1000); //convert to mV
	sinusoidalSignalLeftChannelGenerator->SetFrequency(sinusoidalLeftChannelSignal.GetFrequency());
	sinusoidalSignalRightChannelGenerator->SetAmplitude(sinusoidalRightChannelSignal.GetAmplitude() / 1000); //convert to mV
	sinusoidalSignalRightChannelGenerator->SetFrequency(sinusoidalRightChannelSignal.GetFrequency());
	customDataProvider->ChangeLeftChannelGenerator(sinusoidalSignalLeftChannelGenerator);
	customDataProvider->ChangeRightChannelGenerator(sinusoidalSignalRightChannelGenerator);

	dataProvider = customDataProvider;
}

void Manager::SwitchSignalSourceToCustomGaussianNoise(GaussianNoise gaussianNoise)
{
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


		/*if (dataSocketSender->HasFinishedSendingData())
			dataSocketSender->SendData(leftBuffer, rightBuffer);*/
	}
	delete responseContainer;
}

DataContainer * Manager::MakeCallForData()
{
	DataRequest leftBufferRequest(panelSpecsLeft->TimeBase, panelSpecsLeft->Treshold);
	DataRequest rightBufferRequest(panelSpecsRight->TimeBase, panelSpecsRight->Treshold);

	return dataProvider->GetNewData(&leftBufferRequest, &rightBufferRequest);
}
