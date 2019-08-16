#pragma once
#include "DataContainer.h"
#include "PanelSpecs.h"
#include <vector> 

class DataDrawer
{
	PanelSpecs* panelSpecsLeftChannel, *panelSpecsRightChannel;

	void Draw(PanelSpecs* panelSpecs, std::vector<float> buffer);
	void DrawBothBuffersSameTime(std::vector<float> leftBuffer, std::vector<float> rightBuffer);
	void ClearPanel();
public:
	DataDrawer(PanelSpecs* panelSpecsLeftChannel, PanelSpecs* panelSpecsRightChannel);
	void DrawData(std::vector<float> leftBuffer, std::vector<float> rightBufer);
};