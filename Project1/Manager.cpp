#include "Manager.h"
#include <thread>
#include "DataRequest.h"

Manager::Manager(PanelSpecs * panelSpecsLeft, PanelSpecs * panelSpecsRight, wxPanel *panel):
	panelSpecsLeft(panelSpecsLeft), panelSpecsRight(panelSpecsRight)
{
	dataProvider = new DataProvider;
	dataSocketSender = new DataSocketSender;
	dataDrawer = new DataDrawer(panelSpecsLeft, panelSpecsRight);
	this->panel = panel;
}

void Manager::StartProcessingData()
{
	isActive = true;
	std::thread processingThread(&Manager::ProcessData, this);
	processingThread.detach();
}

void Manager::StopProcessingData()
{
	isActive = false;
}

void Manager::ProcessData()
{
	DataContainer * responseContainer;
	while (isActive)
	{
		DataRequest leftBufferRequest(panelSpecsLeft->TimeBase, panelSpecsLeft->Treshold);
		DataRequest rightBufferRequest(panelSpecsRight->TimeBase, panelSpecsRight->Treshold);

		responseContainer = dataProvider->GetNewData(&leftBufferRequest, &rightBufferRequest);

		float leftScalingFactor = panelSpecsLeft->panel_height / 2 / panelSpecsLeft->VerticalSize;
		float rightScalingFactor = panelSpecsRight->panel_height / 2 / panelSpecsRight->VerticalSize;
		std::vector<float> leftBuffer = ConvertToMaxSizedVectorWithScaling(responseContainer->LeftChannelData, panelSpecsLeft->panel_width, leftScalingFactor, panelSpecsLeft->panel_mid);
		std::vector<float> rightBuffer = ConvertToMaxSizedVectorWithScaling(responseContainer->RightChannelData, panelSpecsLeft->panel_width, rightScalingFactor, panelSpecsRight->panel_mid);

		if(responseContainer->LeftChannelData)responseContainer->LeftChannelData->Destroy();
		if(responseContainer->RightChannelData)responseContainer->RightChannelData->Destroy();

		std::this_thread::sleep_for(std::chrono::milliseconds(1));

		dataDrawer->DrawData(leftBuffer, rightBuffer, panel);

		if (dataSocketSender->HasFinishedSendingData())
			dataSocketSender->SendData(leftBuffer, rightBuffer);
	}
}

std::vector<float> Manager::ConvertToMaxSizedVectorWithScaling(IDataResponse * response, int maxSize, float scalingFactor, int offset)
{
	std::vector<float> result;
	if (!response)
		return result;
	if(maxSize > response->size())
	for (int i = 0; i < response->size(); i++)
	{
		result.push_back(offset - (*response)[i] * scalingFactor);
	}
	else
	{
		float step = response->size() / maxSize;
		for (int i = 0; i < maxSize; i++)
		{
			result.push_back(offset - (*response)[i * step] * scalingFactor);
		}
	}
	return result;
}
