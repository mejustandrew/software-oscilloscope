#include "AudioDataProvider.h"
#include "Imported.h"
#include <thread>

DataContainer * AudioDataProvider::GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest)
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