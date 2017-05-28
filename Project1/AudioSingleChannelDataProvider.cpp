#include "AudioSingleChannelDataProvider.h"

void AudioSingleChannelDataProvider::SetDataSourceFuntion(IDataResponse *(*GetSamples)(int numberOfSamples))
{
	this->GetSamples = GetSamples;
}

IDataResponse * AudioSingleChannelDataProvider::GetNewData(int numberOfSamples)
{
	return GetSamples(numberOfSamples);
}

AudioSingleChannelDataProvider::AudioSingleChannelDataProvider(IDataResponse *(*GetSamples)(int numberOfSamples)) 
	: GetSamples(GetSamples)
{
}
