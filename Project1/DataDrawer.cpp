#include "DataDrawer.h"

void DataDrawer::Draw(PanelSpecs * panelSpecs, std::vector<float> &buffer)
{
	if (!panelSpecs->active)return;

	float Y1, Y2;
	float iteratii = buffer.size();
	if (!iteratii)return;

	float step;
	int xOffset = panelSpecs->horizontalPosition;
	step = panelSpecs->panel_width / iteratii;
	--iteratii;

	for (int i = 0; i < iteratii; ++i)
	{
		panelSpecs->back_mem->DrawLine(i*step + xOffset, buffer[i], (i + 1)*step + xOffset, buffer[i + 1]);
	}
}

void DataDrawer::DrawBothBuffersSameTime(std::vector<float> &leftBuffer, std::vector<float> &rightBuffer)
{
	if (!panelSpecsLeftChannel->active)return;

	float Y1, Y2;
	float iteratii = leftBuffer.size();
	if (!iteratii)return;
	float step;
	int xLeftSignalOffset = panelSpecsLeftChannel->horizontalPosition;
	int xRightSignalOffset = panelSpecsRightChannel->horizontalPosition;

	step = panelSpecsLeftChannel->panel_width / iteratii;
	--iteratii;

	for (int i = 0; i < iteratii; ++i)
	{
		panelSpecsLeftChannel->back_mem->DrawLine(i*step + xLeftSignalOffset, leftBuffer[i], (i + 1)*step + xLeftSignalOffset, leftBuffer[i + 1]);
		panelSpecsRightChannel->back_mem->DrawLine(i*step + xRightSignalOffset, rightBuffer[i], (i + 1)*step + xRightSignalOffset, rightBuffer[i + 1]);
	}
}

void DataDrawer::ClearPanel()
{
	panelSpecsLeftChannel->back_mem->Blit(0, 0, panelSpecsLeftChannel->maxPanel_width, panelSpecsLeftChannel->panel_height, (panelSpecsLeftChannel->grid_mem), 0, 0);
}

DataDrawer::DataDrawer(PanelSpecs * panelSpecsLeftChannel, PanelSpecs * panelSpecsRightChannel)
	: panelSpecsLeftChannel(panelSpecsLeftChannel), panelSpecsRightChannel(panelSpecsRightChannel)
{
}

void DataDrawer::DrawData(std::vector<float> leftBuffer, std::vector<float> rightBufer)
{
	ClearPanel();
	if (leftBuffer.size() == rightBufer.size())
	{
		DrawBothBuffersSameTime(leftBuffer, rightBufer);
	}
	else
	{
		Draw(panelSpecsLeftChannel, leftBuffer);
		Draw(panelSpecsRightChannel, rightBufer);
	}
	panelSpecsLeftChannel->paint_mem->Blit(0, 0, panelSpecsLeftChannel->panel_width, panelSpecsLeftChannel->panel_height, panelSpecsLeftChannel->back_mem, 0, 0);
	panelSpecsLeftChannel->Invalidate();
}