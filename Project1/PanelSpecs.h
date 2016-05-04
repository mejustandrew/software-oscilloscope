#include <wx/dcclient.h>
#include <wx/brush.h>
#include <wx/colour.h>
#include <wx/wx.h>
#include <wx/utils.h> 

class IDataRequest;
class IDataResponse;

struct PanelSpecs
{
	int panel_width,panel_height,maxPanel_width,panel_mid;
	double TimeBase,Treshold,VerticalSize;
	bool active,isAntiAlise;
	wxMemoryDC*antiAlise_mem,*back_mem,*grid_mem;
	wxPanel *panel;
	PanelSpecs(wxPanel*panel,IDataResponse* (*GetSamples)(IDataRequest*));
	IDataResponse* (*GetSamples)(IDataRequest*);

private:
	wxBitmap *grid_bitmap;
	wxBitmap *wave_bitmap,*wave_bitmap2;
	wxBitmap *antiAlise_bitmap,*antiAlise_bitmap2;
	wxPen *antiAlise_pen;
	void DrawGridLines();
};