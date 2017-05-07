#include "CustomDataProvider.h"

CustomDataProvider::CustomDataProvider(SignalGenerator * signalGenerator) : signalGenerator(signalGenerator)
{
}

void CustomDataProvider::ChangeSignalGenerator(SignalGenerator * signalGenerator)
{
	this->signalGenerator = signalGenerator;
}

DataContainer * CustomDataProvider::GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest)
{
	container->LeftChannelData = signalGenerator->GetSignal(leftChannelRequest);
	container->RightChannelData = signalGenerator->GetSignal(rightChannelRequest);

	return container;
}
