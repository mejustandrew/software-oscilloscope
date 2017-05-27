#pragma once
#include "DataContainer.h"
#include "PanelSpecs.h"
#include <vector> 

class DataDrawer
{
	PanelSpecs* panelSpecsLeftChannel, *panelSpecsRightChannel;

	void Draw(PanelSpecs* panelSpecs, IDataResponse *buffer);
	void DrawBothBuffersSameTime(IDataResponse *leftBuffer, IDataResponse *rightBuffer);
	void ClearPanel();
public:
	DataDrawer(PanelSpecs* panelSpecsLeftChannel, PanelSpecs* panelSpecsRightChannel);
	void DrawData(IDataResponse *leftBuffer, IDataResponse *rightBufer);
};