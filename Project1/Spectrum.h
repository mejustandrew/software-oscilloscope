#include "Frame.h"
#include<wx/wx.h>
#include <wx/utils.h> 
#include<atomic>
#include"DataRequest.h"
#include "IDataResponse.h"
#include<mutex>

class SpectrumFrame: public GeneratedFrame
{
protected:
	//std::atomic_bool active;
	std::mutex mu;
	bool active,first_resized,isFFT_spectrum;
	double*converted_samples,*freq_container,timeBase_value,*spectrum_container,sample_rate,scaling_factor;

	int number_in_base2;
	DataRequest*req;
	wxMemoryDC back_mem,grid_mem,paint_mem;
	wxBitmap specter_bmp,grid_bmp;
	wxPen* pen;
	wxString showFreq;
	int panel_width,panel_height,panel_mid,add_pos,shown_pos;

	static void DrawFFT(SpectrumFrame*frame);
	static void Draw(SpectrumFrame*frame);
	static void Refresh(SpectrumFrame*frame);
	void OnResize( wxSizeEvent& event );
	void OnClick( wxMouseEvent& event );
	void OnPaint( wxPaintEvent& event );
	void VerifyFrequency( wxMouseEvent& event );
	void OnSpectrumChoice( wxCommandEvent& event );
	void OnExit( wxCloseEvent& event );
	void OnScalingFactor( wxCommandEvent& event );
	void MaxFrequencyChanged( wxCommandEvent& event );

	float GetFrequency(SpectrumFrame*frame,double *values, int size);
	void ConvertSamples(IDataResponse *source,double *dest,int n);
	void four1(double* data, unsigned long nn);
	int GetPanelWidth(){ return panel_width; }
	int GetPanelHeight(){ return panel_height; }
	void RefreshContainers();
	IDataResponse* (*GetSamples)(int numberOfSamples);
	void StartSpectrumDisplayThread(SpectrumFrame*frame);
public:
	SpectrumFrame( wxWindow* parent ,IDataResponse* (*GetSamples)(int numberOfSamples));
	void Start();
	void Stop(){ active=false; }
	bool IsRunning(){ return active; }
};