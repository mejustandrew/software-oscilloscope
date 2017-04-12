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
	std::vector<float> ConvertToMaxSizedVectorWithScaling(IDataResponse * response, int maxSize, float scalingFactor, int offset);

	DataContainer * oldResponse;
	DataContainer * MakeCallForData();	
public:
	Manager(PanelSpecs *panelSpecsLeft, PanelSpecs *panelSpecsRight);
	~Manager();
	void StartProcessingData();
	void StopProcessingData();
};