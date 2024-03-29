#pragma once
#include<vector>
#include "StringDTOBuilder.h"
class ConnectionHandler;
class DataSocketSender
{
	bool sendingDataFinished;
	ConnectionHandler *ch;
	StringDTOBuilder sb;
	void StartSendingData(std::vector<float> &leftBufferSamples, std::vector<float> &rightBufferSamples);
public:
	DataSocketSender();
	~DataSocketSender();
	bool HasFinishedSendingData();
	void SendData(std::vector<float> leftBufferSamples, std::vector<float> rightBufferSamples);
};