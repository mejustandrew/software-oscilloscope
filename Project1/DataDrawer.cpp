#include "DataDrawer.h"

void DataDrawer::Draw(PanelSpecs * panelSpecs, std::vector<float> buffer)
{
	if (!panelSpecs->active)return;

	float Y1, Y2;
	float iteratii = buffer.size();
	float pas; //avem nevoie de o variabila pas pentru a vedea care este distanta pe x dintre puncte

	float k = panelSpecs->panel_height * 0.5 / panelSpecs->VerticalSize;
	// vertical size represents maximum voltage to be displayed on the screen
	// since the signal can go frm max voltage to -max voltage,
	// the screen height represents 2 times the max voltage
	// then, the amplitude, in pixels is:
	// Value[px] = Value[V] * panel_height / (2 * max voltage)

	if (iteratii < panelSpecs->panel_width)
	{
		pas = panelSpecs->panel_width / iteratii;
		--iteratii;
		if (panelSpecs->isAntiAlise)
		{
			//for (int i = 0; i < iteratii; ++i)
			//{
			//	Y1 = panelSpecs->panel_mid - buffer[i] * k;
			//	Y2 = panelSpecs->panel_mid - buffer[i + 1] * k;
			//	panelSpecs->antiAlise_mem->DrawLine(i*pas, Y1 + 1, (i + 1)*pas, Y2 + 1);
			//	panelSpecs->antiAlise_mem->DrawLine(i*pas, Y1 - 1, (i + 1)*pas, Y2 - 1);
			//}
			//panelSpecs->back_mem->Blit(0, 0, panelSpecs->panel_width, panelSpecs->panel_height, (panelSpecs->antiAlise_mem), 0, 0);
			//for (int i = 0; i < iteratii; ++i)
			//{
			//	Y1 = panelSpecs->panel_mid - buffer[i] * k;
			//	Y2 = panelSpecs->panel_mid - buffer[i + 1] * k;
			//	panelSpecs->back_mem->DrawLine(i*pas, Y1, (i + 1)*pas, Y2);
			//}
		}
		else
		{
			for (int i = 0; i < iteratii; ++i)
			{
				Y1 = panelSpecs->panel_mid - buffer[i] * k;
				Y2 = panelSpecs->panel_mid - buffer[i + 1] * k;
				panelSpecs->back_mem->DrawLine(i*pas, Y1, (i + 1)*pas, Y2);
			}
		}
	}
	else
	{
		pas = iteratii / panelSpecs->panel_width;
		float prag = panelSpecs->panel_width - 1;
		if (panelSpecs->isAntiAlise)
		{
			//for (float i = 0; i < prag; ++i)
			//{
			//	Y1 = panelSpecs->panel_mid - buffer[i*pas] * k;
			//	Y2 = panelSpecs->panel_mid - buffer[(i + 1)*pas] * k;
			//	panelSpecs->antiAlise_mem->DrawLine(i, Y1 + 1, (i + 1), Y2 + 1);
			//	panelSpecs->antiAlise_mem->DrawLine(i, Y1 - 1, (i + 1), Y2 - 1);
			//}
			//panelSpecs->back_mem->Blit(0, 0, panelSpecs->panel_width, panelSpecs->panel_height, (panelSpecs->antiAlise_mem), 0, 0);
			//for (float i = 0; i < prag; ++i)
			//{
			//	Y1 = panelSpecs->panel_mid - buffer[i*pas] * k;
			//	Y2 = panelSpecs->panel_mid - buffer[(i + 1)*pas] * k;
			//	panelSpecs->back_mem->DrawLine(i, Y1, (i + 1), Y2);
			//}
		}
		else
		{
			for (float i = 0; i < prag; ++i)
			{
				Y1 = panelSpecs->panel_mid - buffer[i*pas] * k;
				Y2 = panelSpecs->panel_mid - buffer[(i + 1)*pas] * k;
				panelSpecs->back_mem->DrawLine(i, Y1, (i + 1), Y2);
			}
		}
	}
}

void DataDrawer::ClearPanel()
{
	if (panelSpecsLeftChannel->isAntiAlise)
	{
		panelSpecsLeftChannel->antiAlise_mem->Blit(0, 0, panelSpecsLeftChannel->maxPanel_width, panelSpecsLeftChannel->panel_height, (panelSpecsLeftChannel->grid_mem), 0, 0);
	}
	else
	{
		panelSpecsLeftChannel->back_mem->Blit(0, 0, panelSpecsLeftChannel->maxPanel_width, panelSpecsLeftChannel->panel_height, (panelSpecsLeftChannel->grid_mem), 0, 0);
	}
}

DataDrawer::DataDrawer(PanelSpecs * panelSpecsLeftChannel, PanelSpecs * panelSpecsRightChannel)
	: panelSpecsLeftChannel(panelSpecsLeftChannel), panelSpecsRightChannel(panelSpecsRightChannel)
{
}

void DataDrawer::DrawData(std::vector<float> leftBuffer, std::vector<float> rightBufer)
{
	ClearPanel();
	Draw(panelSpecsLeftChannel, leftBuffer);
	Draw(panelSpecsRightChannel, rightBufer);
	panelSpecsLeftChannel->paint_mem->Blit(0, 0, panelSpecsLeftChannel->panel_width, panelSpecsLeftChannel->panel_height, panelSpecsLeftChannel->back_mem, 0, 0);
	panelSpecsLeftChannel->Invalidate();
}