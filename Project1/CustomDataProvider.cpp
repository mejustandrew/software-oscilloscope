#include "CustomDataProvider.h"

CustomDataProvider::CustomDataProvider(SignalGenerator * leftChannelGenerator, SignalGenerator * rightChannelGenerator) : 
	leftChannelGenerator(leftChannelGenerator), rightChannelGenerator(rightChannelGenerator)
{
}

void CustomDataProvider::ChangeLeftChannelGenerator(SignalGenerator * signalGenerator)
{
	this->leftChannelGenerator = signalGenerator;
}

void CustomDataProvider::ChangeRightChannelGenerator(SignalGenerator * signalGenerator)
{
	this->rightChannelGenerator = signalGenerator;
}

DataContainer * CustomDataProvider::GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest)
{
	container->LeftChannelData = leftChannelGenerator->GetSignal(leftChannelRequest);
	container->RightChannelData = rightChannelGenerator->GetSignal(rightChannelRequest);

	return container;
}
