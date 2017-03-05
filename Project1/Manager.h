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
	wxPanel *panel;
public:
	Manager(PanelSpecs *panelSpecsLeft, PanelSpecs *panelSpecsRight, wxPanel *panel);
	void StartProcessingData();
	void StopProcessingData();
};
