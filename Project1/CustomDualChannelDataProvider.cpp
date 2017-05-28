#include "CustomDualChannelDataProvider.h"

CustomDualChannelDataProvider::CustomDualChannelDataProvider(SignalGenerator * leftChannelGenerator, SignalGenerator * rightChannelGenerator) : 
	leftChannelGenerator(leftChannelGenerator), rightChannelGenerator(rightChannelGenerator)
{
}

void CustomDualChannelDataProvider::ChangeLeftChannelGenerator(SignalGenerator * signalGenerator)
{
	this->leftChannelGenerator = signalGenerator;
}

void CustomDualChannelDataProvider::ChangeRightChannelGenerator(SignalGenerator * signalGenerator)
{
	this->rightChannelGenerator = signalGenerator;
}

DataContainer * CustomDualChannelDataProvider::GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest)
{
	container->LeftChannelData = leftChannelGenerator->GetSignal(leftChannelRequest);
	container->RightChannelData = rightChannelGenerator->GetSignal(rightChannelRequest);

	return container;
}

void CustomDualChannelDataProvider::SetLeftSlope(bool positive)
{
	leftChannelGenerator->SetSignalSlope(positive);
}

void CustomDualChannelDataProvider::SetRightSlope(bool positive)
{
	rightChannelGenerator->SetSignalSlope(positive);
}
