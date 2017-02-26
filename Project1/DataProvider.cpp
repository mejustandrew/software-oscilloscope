#include "DataProvider.h"
#include "Imported.h"
DataContainer * DataProvider::GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest)
{
	while (true)
	{
		container->LeftChannelData = GetSignalLeftSamples(leftChannelRequest);
		container->RightChannelData = GetSignalRightSamples(rightChannelRequest);

		if (container->LeftChannelData || container->RightChannelData)
			return container;
	}
}


DataProvider::DataProvider()
{
	leftBufferResponse = nullptr;
	rightBufferResponse = nullptr;

	container = new DataContainer;
}

DataProvider::~DataProvider()
{
	delete container;
}