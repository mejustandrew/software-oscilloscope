#include "Manager.h"
#include <thread>
#include "DataRequest.h"

Manager::Manager(PanelSpecs * panelSpecsLeft, PanelSpecs * panelSpecsRight):
	panelSpecsLeft(panelSpecsLeft), panelSpecsRight(panelSpecsRight)
{
	dataProvider = new DataProvider;
	dataSocketSender = new DataSocketSender;
	dataDrawer = new DataDrawer(panelSpecsLeft, panelSpecsRight);
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

		std::vector<float> leftBuffer = ConvertToMaxSizedVector(responseContainer->LeftChannelData, panelSpecsLeft->panel_width);
		std::vector<float> rightBuffer = ConvertToMaxSizedVector(responseContainer->RightChannelData, panelSpecsLeft->panel_width);

		dataDrawer->DrawData(leftBuffer, rightBuffer);

		
		if (dataSocketSender->HasFinishedSendingData())
			dataSocketSender->SendData(leftBuffer, rightBuffer);
	}
}

std::vector<float> Manager::ConvertToMaxSizedVector(IDataResponse * response, int maxSize)
{
	std::vector<float> result;
	if (!response)
		return result;
	if(maxSize > response->size())
	for (int i = 0; i < response->size(); i++)
	{
		result.push_back((*response)[i]);
	}
	else
	{
		float step = response->size() / maxSize;
		for (int i = 0; i < response->size(); i++)
		{
			result.push_back((*response)[i * step]);
		}
	}
	return result;
}
