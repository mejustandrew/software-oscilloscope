#include "AudioDualChannelDataProvider.h"
#include "Imported.h"
#include <thread>
#include"WorkingFrame.h"


DataContainer * AudioDualChannelDataProvider::GetNewData(IDataRequest * leftChannelRequest, IDataRequest * rightChannelRequest)
{
	if (!WorkingFrame::IsAudioStreamInitialized())
		return container;

	container->LeftChannelData = GetSignalLeftSamples(leftChannelRequest);
	container->RightChannelData = GetSignalRightSamples(rightChannelRequest);

	return container;
}

void AudioDualChannelDataProvider::SetLeftSlope(bool positive)
{
	SetLeftSignalSlope(positive);
}

void AudioDualChannelDataProvider::SetRightSlope(bool positive)
{
	SetRightSignalSlope(positive);
}