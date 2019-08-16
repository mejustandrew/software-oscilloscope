#include "DataSocketSender.h"
#include <thread>
#include "ConnectionHandler.h"
#include "StringDTOBuilder.h"
#include <string>
#include "ConnectionHandler.h"

void DataSocketSender::StartSendingData(std::vector<float> &leftBufferSamples, std::vector<float> &rightBufferSamples)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	std::string stringDTOModel = sb.BuildStringModel(leftBufferSamples, rightBufferSamples);
	ch->Send(stringDTOModel);
	sendingDataFinished = true;
}

DataSocketSender::DataSocketSender()
{
	ch = new ConnectionHandler;
	sendingDataFinished = true;
}

DataSocketSender::~DataSocketSender()
{
	delete ch;
}

bool DataSocketSender::HasFinishedSendingData()
{
	return sendingDataFinished;
}

/// This method sends data asynchronously to server through web sockets.
/// Check HasFinishedSendingData() method to ensure this method can be called.
/// The vectors sent through it should not be modified until the sending succeeds so it is recommended to make a copy of them before.
void DataSocketSender::SendData(std::vector<float> leftBufferSamples, std::vector<float> rightBufferSamples)
{
	if (!sendingDataFinished)return;
	sendingDataFinished = false;
	std::thread sendingThread(&DataSocketSender::StartSendingData, this, leftBufferSamples, rightBufferSamples);
	sendingThread.detach();
}
