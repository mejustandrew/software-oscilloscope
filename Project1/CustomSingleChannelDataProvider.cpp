#include "CustomSingleChannelDataProvider.h"

CustomSingleChannelDataProvider::CustomSingleChannelDataProvider(SignalGenerator * signalGenerator)
	: signalGenerator(signalGenerator)
{
}

void CustomSingleChannelDataProvider::ChangeSignalGenerator(SignalGenerator * signalGenerator)
{
	this->signalGenerator = signalGenerator;
}

IDataResponse * CustomSingleChannelDataProvider::GetNewData(int numberOfSamples)
{
	return signalGenerator->GetSignal(numberOfSamples);
}
