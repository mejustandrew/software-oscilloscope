#ifndef __WorkingFrame__
#define __WorkingFrame__
#include <wx/dcclient.h>
#include <wx/brush.h>
#include <wx/colour.h>
#include <wx/wx.h>
#include <wx/utils.h> 
#include "IDataRequest.h"
#include "IDataResponse.h"
#include "Project.h"
#include "Spectrum.h"
#include <atomic>

class WorkingFrame : public BuiltFrame
{
protected:
	// Handlers for BuildedFrame events.
	void VerifyValues( wxMouseEvent& event );
	void PanelLeave( wxMouseEvent& event );
	void OnPanelResized( wxSizeEvent& event );
	void VerticalSizeChanged( wxCommandEvent& event );
	void TimeBaseChanged( wxCommandEvent& event );
	void TresholdChanged( wxSpinEvent& event );
	void OnStateChanged( wxMouseEvent& event );
	void OnSecondsChanged( wxCommandEvent& event );
	void OnVoltsChanged( wxCommandEvent& event );
	void OnPositionChanged( wxSpinEvent& event );
	void OnSpecterClick( wxCommandEvent& event );
	void OnAntiAliase( wxCommandEvent& event );
	void OnPanelPaint( wxPaintEvent& event );
	virtual void PanelLeave2( wxMouseEvent& event );
	virtual void VerifyValues2( wxMouseEvent& event );
	virtual void OnPanelPaint2( wxPaintEvent& event );
	void Close( wxCloseEvent& event );

	void DrawGrid();
	SpectrumFrame* spectrum;
	std::atomic_bool active;
	std::atomic_bool finished;
	double vertical_value,timeBase_value,treshold_value;
	int prev_seconds_selection, prev_volt_selection;
	int grid_div;
	int panel_width,panel_height,panel_mid,maxPanel_width;
	bool isAntiAlise;
	wxString display_frequency;
	wxBitmap *grid_bitmap;
	wxBitmap *wave_bitmap,*wave_bitmap2;
	wxBitmap *antiAlise_bitmap,*antiAlise_bitmap2;
	wxPen *antiAlise_pen;
	wxMemoryDC *back_mem,*back_mem2;
	wxMemoryDC *grid_mem;
	wxMemoryDC *antiAlise_mem,*antiAlise_mem2;
public:
	WorkingFrame( wxWindow* parent );
	~WorkingFrame(); 

	double GetTimeBase(){ return timeBase_value; }
	double GetTreshold(){ return treshold_value; }
	double GetVerticalSize(){ return vertical_value; }
	static void DisplayFrequency(WorkingFrame*frame,IDataResponse *values);
	static void Refresh(WorkingFrame* frame);
	static void Create(WorkingFrame* frame);
	static void Draw(WorkingFrame* frame);
};

#endif
