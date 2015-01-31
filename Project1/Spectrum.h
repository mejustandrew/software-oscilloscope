#include "Frame.h"
#include<wx/wx.h>
#include <wx/utils.h> 
#include<atomic>
#include"DataRequest.h"
#include "IDataResponse.h"

class SpectrumFrame: public GeneratedFrame
{
protected:
	//std::atomic_bool active;
	bool active;
	double*converted_samples;
	int number_in_base2;
	DataRequest*req;
	wxMemoryDC back_mem,grid_mem;
	wxBitmap specter_bmp,grid_bmp;
	wxPen* pen;
	int panel_width,panel_height,MaxPanel_height,MaxPanel_width,panel_mid;

	static void Draw(SpectrumFrame*frame);
	static void Refresh(SpectrumFrame*frame);
	void OnResize( wxSizeEvent& event );
	void OnClick( wxMouseEvent& event );
	void OnPaint( wxPaintEvent& event );
	void OnExit( wxCloseEvent& event );
	
	void ConvertSamples(IDataResponse *source,double *dest,int n);
	void four1(double* data, unsigned long nn);
	int GetPanelWidth(){ return panel_width; }
	int GetPanelHeight(){ return panel_height; }

public:
	SpectrumFrame( wxWindow* parent );
	void Start();
	void Stop(){ active=false; }
	bool IsRunning(){ return active; }
};