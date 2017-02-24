#pragma once
#include "DataProvider.h"
#include "DataSocketSender.h"
#include "DataDrawer.h"
#include "PanelSpecs.h"
#include<vector>

class Manager
{
	PanelSpecs *panelSpecsLeft, *panelSpecsRight;
	DataProvider* dataProvider;
	DataSocketSender * dataSocketSender;
	DataDrawer * dataDrawer;
	bool isActive;
	void ProcessData();
	std::vector<float> ConvertToMaxSizedVector(IDataResponse *response, int maxSize);

public:
	Manager(PanelSpecs *panelSpecsLeft, PanelSpecs *panelSpecsRight);
	void StartProcessingData();
	void StopProcessingData();
};
