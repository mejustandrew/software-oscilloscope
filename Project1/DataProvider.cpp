#include "DataProvider.h"
#include "Imported.h"
#include <thread>

DataContainer * DataProvider::GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest)
{
	while (true)
	{
		container->LeftChannelData = GetSignalLeftSamples(leftChannelRequest);
		container->RightChannelData = GetSignalRightSamples(rightChannelRequest);

		if (container->LeftChannelData || container->RightChannelData)
			return container;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
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