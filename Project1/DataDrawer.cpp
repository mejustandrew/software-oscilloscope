#include "DataDrawer.h"

void DataDrawer::Draw(PanelSpecs * panelSpecs, std::vector<float> &buffer)
{
	if (!panelSpecs->active)return;

	float Y1, Y2;
	float iteratii = buffer.size();
	if (!iteratii)return;

	float step;

	if (iteratii < panelSpecs->panel_width)
	{
		step = panelSpecs->panel_width / iteratii;
		--iteratii;

		for (int i = 0; i < iteratii; ++i)
		{
			panelSpecs->back_mem->DrawLine(i*step, buffer[i], (i + 1)*step, buffer[i + 1]);
		}
	}
	else
	{
		step = iteratii / panelSpecs->panel_width;
		float prag = panelSpecs->panel_width - 1;

		for (float i = 0; i < prag; ++i)
		{
			panelSpecs->back_mem->DrawLine(i, buffer[i*step], (i + 1), buffer[(i + 1)*step]);
		}
	}
}

void DataDrawer::DrawBothBuffersSameTime(PanelSpecs * panelSpecs, std::vector<float> &leftBuffer, std::vector<float> &rightBuffer)
{
	if (!panelSpecs->active)return;

	float Y1, Y2;
	float iteratii = leftBuffer.size();
	if (!iteratii)return;
	float step;

	if (iteratii < panelSpecs->panel_width)
	{
		step = panelSpecs->panel_width / iteratii;
		--iteratii;

		for (int i = 0; i < iteratii; ++i)
		{
			panelSpecs->back_mem->DrawLine(i*step, leftBuffer[i], (i + 1)*step, leftBuffer[i + 1]);
			panelSpecs->back_mem->DrawLine(i*step, rightBuffer[i], (i + 1)*step, rightBuffer[i + 1]);
		}
	}
	else
	{
		step = iteratii / panelSpecs->panel_width;
		float prag = panelSpecs->panel_width - 1;

		for (float i = 0; i < prag; ++i)
		{
			panelSpecs->back_mem->DrawLine(i, leftBuffer[i*step], (i + 1), leftBuffer[(i + 1)*step]);
			panelSpecs->back_mem->DrawLine(i, rightBuffer[i*step], (i + 1), rightBuffer[(i + 1)*step]);
		}
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
		DrawBothBuffersSameTime(panelSpecsLeftChannel, leftBuffer, rightBufer);
	}
	else
	{
		Draw(panelSpecsLeftChannel, leftBuffer);
		Draw(panelSpecsRightChannel, rightBufer);
	}
	panelSpecsLeftChannel->paint_mem->Blit(0, 0, panelSpecsLeftChannel->panel_width, panelSpecsLeftChannel->panel_height, panelSpecsLeftChannel->back_mem, 0, 0);
	panelSpecsLeftChannel->Invalidate();
}