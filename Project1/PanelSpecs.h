#include <wx/dcclient.h>
#include <wx/brush.h>
#include <wx/colour.h>
#include <wx/wx.h>
#include <wx/utils.h> 


struct PanelSpecs
{
	int panel_width,panel_height,TimeBase,Treshold,VerticalSize,maxPanel_width,panel_mid;
	bool active,isAntiAlise;
	wxMemoryDC*antiAlise_mem,*back_mem,*grid_mem;
	wxPanel *panel;
	PanelSpecs(wxPanel*panel);
private:
	wxBitmap *grid_bitmap;
	wxBitmap *wave_bitmap,*wave_bitmap2;
	wxBitmap *antiAlise_bitmap,*antiAlise_bitmap2;
	wxPen *antiAlise_pen;
	void DrawGridLines();
};