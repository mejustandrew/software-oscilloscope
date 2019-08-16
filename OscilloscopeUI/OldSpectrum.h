#include "Frame.h"
#include<wx/wx.h>
#include <wx/utils.h> 


class SpectrumFrame: public GeneratedFrame
{
protected:
	//std::atomic_bool active;
	bool active;
	static void Draw(SpectrumFrame*frame);
	static void Refresh(SpectrumFrame*frame);
	void OnResize( wxSizeEvent& event );
	void OnClick( wxMouseEvent& event );
	void OnPaint( wxPaintEvent& event );
	void OnExit( wxCloseEvent& event );
	wxMemoryDC back_mem,grid_mem;
	wxBitmap specter_bmp,grid_bmp;
	wxPen* pen;
	int panel_width,panel_height,MaxPanel_height,MaxPanel_width,panel_mid;
	int GetPanelWidth(){ return panel_width; }
	int GetPanelHeight(){ return panel_height; }
public:
	SpectrumFrame( wxWindow* parent );
	void Start();
	void Stop(){ active=false; }
};