#include "AudioDualChannelDataProvider.h"
#include "Imported.h"
#include <thread>
#include"WorkingFrame.h"

DataContainer * AudioDualChannelDataProvider::GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest)
{
	if (!WorkingFrame::IsAudioStreamInitialized())
		return container;

	while (true)
	{
		container->LeftChannelData = GetSignalLeftSamples(leftChannelRequest);
		container->RightChannelData = GetSignalRightSamples(rightChannelRequest);

		if (container->LeftChannelData || container->RightChannelData)
			return container;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}