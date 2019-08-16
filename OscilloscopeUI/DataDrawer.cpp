#include "DataDrawer.h"

void DataDrawer::Draw(PanelSpecs * panelSpecs, std::vector<float> buffer)
{
	if (!panelSpecs->active)return;

	float iteratii = buffer.size();
	float scalingFactor = panelSpecs->panel_height / 2 / panelSpecs->VerticalSize;
	float step;
	float Y1, Y2;
	int xOffset = panelSpecs->horizontalPosition;
	step = panelSpecs->panel_width / iteratii;
	--iteratii;

	for (int i = 0; i < iteratii; ++i)
	{
		Y1 = panelSpecs->panel_mid - buffer[i] * scalingFactor;
		Y2 = panelSpecs->panel_mid - buffer[i + 1] * scalingFactor;
		panelSpecs->back_mem->DrawLine(i*step + xOffset, Y1, (i + 1)*step + xOffset, Y2);
	}
}

void DataDrawer::DrawBothBuffersSameTime(std::vector<float> leftBuffer, std::vector<float> rightBuffer)
{
	float iteratii = leftBuffer.size();
	float step;
	int xLeftSignalOffset = panelSpecsLeftChannel->horizontalPosition;
	int xRightSignalOffset = panelSpecsRightChannel->horizontalPosition;
	float scalingLeftFactor = panelSpecsLeftChannel->panel_height / 2 / panelSpecsLeftChannel->VerticalSize;
	float scalingRightFactor = panelSpecsRightChannel->panel_height / 2 / panelSpecsRightChannel->VerticalSize;
	float leftY1, leftY2, rightY1, rightY2;
	step = panelSpecsLeftChannel->panel_width / iteratii;
	--iteratii;

	for (int i = 0; i < iteratii; ++i)
	{
		leftY1 = panelSpecsLeftChannel->panel_mid - leftBuffer[i] * scalingLeftFactor;
		leftY2 = panelSpecsLeftChannel->panel_mid - leftBuffer[i + 1] * scalingLeftFactor;
		rightY1 = panelSpecsRightChannel->panel_mid - rightBuffer[i] * scalingRightFactor;
		rightY2 = panelSpecsRightChannel->panel_mid - rightBuffer[i + 1] * scalingRightFactor;

		panelSpecsLeftChannel->back_mem->DrawLine(i*step + xLeftSignalOffset, leftY1, (i + 1)*step + xLeftSignalOffset, leftY2);
		panelSpecsRightChannel->back_mem->DrawLine(i*step + xRightSignalOffset, rightY1, (i + 1)*step + xRightSignalOffset, rightY2);
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
	if (leftBuffer.size() == rightBufer.size() && panelSpecsLeftChannel->active && panelSpecsRightChannel->active)
		DrawBothBuffersSameTime(leftBuffer, rightBufer);
	else
	{
		if (panelSpecsLeftChannel->active)
			Draw(panelSpecsLeftChannel, leftBuffer);
		if (panelSpecsRightChannel->active)
			Draw(panelSpecsRightChannel, rightBufer);
	}

	panelSpecsLeftChannel->paint_mem->Blit(0, 0, panelSpecsLeftChannel->panel_width, panelSpecsLeftChannel->panel_height, panelSpecsLeftChannel->back_mem, 0, 0);
	panelSpecsLeftChannel->Invalidate();
}