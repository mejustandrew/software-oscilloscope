#pragma once
#include <wx/dcclient.h>
#include <wx/brush.h>
#include <wx/colour.h>
#include <wx/wx.h>
#include <wx/utils.h> 
#include <mutex>
class IDataRequest;
class IDataResponse;

struct PanelSpecs
{
	int panel_width, panel_height, maxPanel_width, panel_mid, horizontalPosition;
	double TimeBase, Treshold, VerticalSize;
	bool active;
	wxMemoryDC *back_mem, *grid_mem, *paint_mem;
	wxPanel *panel;
	PanelSpecs(wxPanel*panel, IDataResponse* (*GetSamples)(IDataRequest*));
	IDataResponse* (*GetSamples)(IDataRequest*);
	void Invalidate();

private:
	wxBitmap *grid_bitmap;
	wxBitmap *wave_bitmap, *wave_bitmap2;
	void DrawGridLines();
};