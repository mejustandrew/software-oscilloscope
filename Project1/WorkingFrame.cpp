#include "WorkingFrame.h" 
#include "Imported.h"
#include<thread>

static std::mutex *mu = new std::mutex;

WorkingFrame::WorkingFrame( wxWindow* parent )
	:
	BuiltFrame( parent )
{
	Initialize();
	spectrumLeft=new SpectrumFrame(nullptr,GetSpectrumLeftSamples);
	spectrumRight=new SpectrumFrame(nullptr,GetSpectrumRightSamples);

	prev_seconds_selection=1;
	prev_volt_selection=1;
	prev_seconds_selection2=1;
	prev_volt_selection2=1;

	panel1_specs=new PanelSpecs(m_panel1,GetSignalLeftSamples);
	panel2_specs=new PanelSpecs(m_panel2,GetSignalRightSamples);

	Create(panel1_specs);
	Create(panel2_specs);
}

void WorkingFrame::VerifyValues( wxMouseEvent& event )
{
	wxPoint current_position=m_panel1->ScreenToClient(wxGetMousePosition());
	wxString s;
	s<<panel1_specs->TimeBase*1000/panel1_specs->panel_width*current_position.x;
	timeLabel->SetLabelText(s);
	s="";
	s<<(panel1_specs->VerticalSize*1000)/panel1_specs->panel_height*(panel1_specs->panel_mid-current_position.y);
	amplitudeLabel->SetLabelText(s);
}

void WorkingFrame::VerifyValues2( wxMouseEvent& event )
{
	wxPoint current_position=m_panel2->ScreenToClient(wxGetMousePosition());
	wxString s;
	s<<panel2_specs->TimeBase*1000/panel2_specs->panel_width*current_position.x;
	timeLabel->SetLabelText(s);
	s="";
	s<<(panel2_specs->VerticalSize*1000)/panel2_specs->panel_height*(panel2_specs->panel_mid-current_position.y);
	amplitudeLabel->SetLabelText(s);
}

void WorkingFrame::PanelLeave( wxMouseEvent& event )
{
	timeLabel->SetLabelText("0.00");
	amplitudeLabel->SetLabelText("0.00");
}

void WorkingFrame::PanelLeave2( wxMouseEvent& event )
{
	timeLabel->SetLabelText("0.00");
	amplitudeLabel->SetLabelText("0.00");
}

void WorkingFrame::OnPanelPaint( wxPaintEvent& event )
{
	wxPaintDC paint(m_panel1);
	paint.Blit(0,0,panel1_specs->panel_width,panel1_specs->panel_height,panel1_specs->back_mem,0,0);
}

void WorkingFrame::OnPanelPaint2( wxPaintEvent& event )
{
	wxPaintDC paint(m_panel2);
	paint.Blit(0,0,panel2_specs->panel_width,panel2_specs->panel_height,panel2_specs->back_mem,0,0);
}

void WorkingFrame::OnAntiAliase( wxCommandEvent& event )
{
	panel1_specs->isAntiAlise=!panel1_specs->isAntiAlise;
}

void WorkingFrame::OnPositionChanged( wxSpinEvent& event )
{
	panel1_specs->panel_mid=panel1_specs->panel_height*0.5-5*PositionValue->GetValue();
}

void WorkingFrame::OnPosition2Changed( wxSpinEvent& event )
{
	panel2_specs->panel_mid=panel2_specs->panel_height*0.5-5*PositionValueChannel2->GetValue();
}

void WorkingFrame::OnSpectrumClick( wxCommandEvent& event )
{
	if(spectrumLeft->IsShown()) return;
	spectrumLeft->Show();
	spectrumLeft->Start();
}

void WorkingFrame::OnSpectrumClickChannel2( wxCommandEvent& event )
{
	if(spectrumRight->IsShown()) return;
	spectrumRight->Show();
	spectrumRight->Start();
}

WorkingFrame::~WorkingFrame()
{ 

}

void WorkingFrame::VerticalSizeChanged(wxCommandEvent& event)
{
	wxString returned = VerticalSize->GetString(VerticalSize->GetSelection());
	double converted;
	returned.ToDouble(&converted);
	if(voltSelection->GetSelection()==1)converted*=0.001;
	panel1_specs->VerticalSize=converted;
}

void WorkingFrame::VerticalSize2Changed(wxCommandEvent& event)
{
	wxString returned = VerticalSize->GetString(VerticalSize->GetSelection());
	double converted;
	returned.ToDouble(&converted);
	if(voltSelection->GetSelection()==1)converted*=0.001;
	panel2_specs->VerticalSize=converted;
}

void WorkingFrame::TimeBaseChanged( wxCommandEvent& event )
{
	wxString returned = timeBase->GetString(timeBase->GetSelection());
	double converted;
	returned.ToDouble(&converted);
	if(secondSelection->GetSelection()==1)converted*=0.001;
	panel1_specs->TimeBase=converted;
}

void WorkingFrame::TimeBase2Changed( wxCommandEvent& event )
{
	wxString returned = timeBaseChannel2->GetString(timeBaseChannel2->GetSelection());
	double converted;
	returned.ToDouble(&converted);
	if(secondSelection->GetSelection()==1)converted*=0.001;
	panel2_specs->TimeBase=converted;
}

void WorkingFrame::TresholdChanged( wxSpinEvent& event )
{
	panel1_specs->Treshold = Treshold->GetValue()*0.001;
}

void WorkingFrame::Treshold2Changed( wxSpinEvent& event )
{
	panel2_specs->Treshold = Treshold->GetValue()*0.001;
}

void WorkingFrame::OnSecondsChanged( wxCommandEvent& event )
{
	if(secondSelection->GetSelection()==0 && prev_seconds_selection!=0)
	{
		int selections_nuber=timeBase->GetCount();
		double newValue;
		wxString newSring;
		for(int i=0;i<selections_nuber;++i)
		{
			timeBase->GetString(i).ToDouble(&newValue);
			newValue*=0.001;
			newSring<<newValue;
			timeBase->SetString(i,newSring);
			newSring="";
		}
		prev_seconds_selection=0;
	}
	else if(secondSelection->GetSelection()==1 && prev_seconds_selection!=1)
	{
		int selections_nuber=timeBase->GetCount();
		double newValue;
		wxString newSring;
		for(int i=0;i<selections_nuber;++i)
		{
			timeBase->GetString(i).ToDouble(&newValue);
			newValue*=1000;
			newSring<<newValue;
			timeBase->SetString(i,newSring);
			newSring="";
		}
		prev_seconds_selection=1;
	}
}

void WorkingFrame::OnSeconds2Changed( wxCommandEvent& event )
{
	if(secondSelectionChannel2->GetSelection()==0 && prev_seconds_selection2!=0)
	{
		int selections_nuber=timeBaseChannel2->GetCount();
		double newValue;
		wxString newSring;
		for(int i=0;i<selections_nuber;++i)
		{
			timeBaseChannel2->GetString(i).ToDouble(&newValue);
			newValue*=0.001;
			newSring<<newValue;
			timeBaseChannel2->SetString(i,newSring);
			newSring="";
		}
		prev_seconds_selection2=0;
	}
	else if(secondSelectionChannel2->GetSelection()==1 && prev_seconds_selection2!=1)
	{
		int selections_nuber=timeBaseChannel2->GetCount();
		double newValue;
		wxString newSring;
		for(int i=0;i<selections_nuber;++i)
		{
			timeBaseChannel2->GetString(i).ToDouble(&newValue);
			newValue*=1000;
			newSring<<newValue;
			timeBaseChannel2->SetString(i,newSring);
			newSring="";
		}
		prev_seconds_selection2=1;
	}
}

void WorkingFrame::OnVoltsChanged( wxCommandEvent& event )
{
	if(voltSelection->GetSelection()==0 && prev_volt_selection!=0)
	{
		int selections_nuber=VerticalSize->GetCount();
		double newValue;
		wxString newSring;
		for(int i=0;i<selections_nuber;++i)
		{
			VerticalSize->GetString(i).ToDouble(&newValue);
			newValue*=0.001;
			newSring<<newValue;
			VerticalSize->SetString(i,newSring);
			newSring="";
		}
		prev_volt_selection=0;
	}
	else if(voltSelection->GetSelection()==1 && prev_volt_selection!=1)
	{
		int selections_nuber=VerticalSize->GetCount();
		double newValue;
		wxString newSring;
		for(int i=0;i<selections_nuber;++i)
		{
			VerticalSize->GetString(i).ToDouble(&newValue);
			newValue*=1000;
			newSring<<newValue;
			VerticalSize->SetString(i,newSring);
			newSring="";
		}
		prev_volt_selection=1;
	}
}

void WorkingFrame::OnVolts2Changed( wxCommandEvent& event )
{
	if(voltSelectionChannel2->GetSelection()==0 && prev_volt_selection2!=0)
	{
		int selections_nuber=VerticalSizeChannel2->GetCount();
		double newValue;
		wxString newSring;
		for(int i=0;i<selections_nuber;++i)
		{
			VerticalSizeChannel2->GetString(i).ToDouble(&newValue);
			newValue*=0.001;
			newSring<<newValue;
			VerticalSizeChannel2->SetString(i,newSring);
			newSring="";
		}
		prev_volt_selection2=0;
	}
	else if(voltSelectionChannel2->GetSelection()==1 && prev_volt_selection2!=1)
	{
		int selections_nuber=VerticalSizeChannel2->GetCount();
		double newValue;
		wxString newSring;
		for(int i=0;i<selections_nuber;++i)
		{
			VerticalSizeChannel2->GetString(i).ToDouble(&newValue);
			newValue*=1000;
			newSring<<newValue;
			VerticalSizeChannel2->SetString(i,newSring);
			newSring="";
		}
		prev_volt_selection2=1;
	}
}

void WorkingFrame::OnPanelResized( wxSizeEvent& event )
{
	m_panel1->GetSize(&panel1_specs-> panel_width,&panel1_specs->panel_height);
	panel1_specs->panel_mid=panel1_specs->panel_height*0.5;
}

void WorkingFrame::OnPanelResized2( wxSizeEvent& event )
{
	m_panel2->GetSize(&panel2_specs-> panel_width,&panel2_specs->panel_height);
	panel2_specs->panel_mid=panel2_specs->panel_height*0.5;
}

void WorkingFrame::OnStateChanged( wxMouseEvent& event )
{
	if(panel1_specs->active)
	{
		panel1_specs->active=false;
		state_button->SetLabel("On");
	}
	else
	{
		Create(panel1_specs);
		state_button->SetLabel("Off");
	}
}

void WorkingFrame::OnStateChangedChannel2( wxMouseEvent& event )
{
	if(panel2_specs->active)
	{
		panel2_specs->active=false;
		state_button2->SetLabel("On");
	}
	else
	{
		Create(panel2_specs);
		state_button2->SetLabel("Off");
	}
}

void WorkingFrame::Create(PanelSpecs* frame)
{
	if(Initialize())
	{
		frame->active=true;
		std::thread refreshThread(Refresh,frame);
		refreshThread.detach();
	}
	else wxMessageBox("Opening PortAudio stream did not succeed,\nreopen application after verify Recording Devices\nmay solve this problem");
}

void WorkingFrame::Refresh(PanelSpecs* frame)
{
	while(frame->active)
	{
		Draw(frame);
		Sleep(1);
	}
}

void WorkingFrame::Draw(PanelSpecs* frame)
{
	if(!frame->active)return;
	DataRequest req(frame->TimeBase,frame->Treshold);
	IDataResponse* response=frame->GetSamples(&req);
	if(!response)return;

	float Y1,Y2;
	float iteratii = response->size();
	float pas;
	//avem nevoie de o variabila pas pentru a vedea care este distanta pe x dintre puncte
	if(frame->isAntiAlise)
	{
		frame->antiAlise_mem->Blit(0, 0, frame->maxPanel_width,frame->panel_height, (frame->grid_mem), 0, 0);
	}
	else
	{
		frame->back_mem->Blit(0, 0, frame->maxPanel_width,frame->panel_height, (frame->grid_mem), 0, 0);
	}

	float k=frame->panel_height*0.5/frame->VerticalSize;
	// vertical size represents maximum voltage to be displayed on the screen
	// since the signal can go frm max voltage to -max voltage,
	// the screen height represents 2 times the max voltage
	// then, the amplitude, in pixels is:
	// Value[px] = Value[V] * panel_height / (2 * max voltage)

	if(iteratii<frame->panel_width)
	{
		pas=frame->panel_width/iteratii;
		--iteratii;
		if(frame->isAntiAlise)
		{
			for(int i=0;i<iteratii;++i)
			{
				Y1=frame->panel_mid-(*response)[i]*k;
				Y2=frame->panel_mid-(*response)[i+1]*k;
				frame->antiAlise_mem->DrawLine(i*pas,Y1+1,(i+1)*pas,Y2+1);
				frame->antiAlise_mem->DrawLine(i*pas,Y1-1,(i+1)*pas,Y2-1);
			}
			frame->back_mem->Blit(0, 0, frame->panel_width,frame->panel_height, (frame->antiAlise_mem), 0, 0);
			for(int i=0;i<iteratii;++i)
			{
				Y1=frame->panel_mid-(*response)[i]*k;
				Y2=frame->panel_mid-(*response)[i+1]*k;
				frame->back_mem->DrawLine(i*pas,Y1,(i+1)*pas,Y2);
			}
		}
		else
		{
			for(int i=0;i<iteratii;++i)
			{
				Y1=frame->panel_mid-(*response)[i]*k;
				Y2=frame->panel_mid-(*response)[i+1]*k;
				frame->back_mem->DrawLine(i*pas,Y1,(i+1)*pas,Y2);
			}
		}
	}
	else
	{
		pas=iteratii/frame->panel_width;
		float prag=frame->panel_width-1;
		if(frame->isAntiAlise)
		{
			for(float i=0;i<prag;++i)
			{		
				Y1=frame->panel_mid-(*response)[i*pas]*k;
				Y2=frame->panel_mid-(*response)[(i+1)*pas]*k;
				frame->antiAlise_mem->DrawLine(i,Y1+1,(i+1),Y2+1);
				frame->antiAlise_mem->DrawLine(i,Y1-1,(i+1),Y2-1);
			}
			frame->back_mem->Blit(0, 0, frame->panel_width,frame->panel_height, (frame->antiAlise_mem), 0, 0);
			for(float i=0;i<prag;++i)
			{		
				Y1=frame->panel_mid-(*response)[i*pas]*k;
				Y2=frame->panel_mid-(*response)[(i+1)*pas]*k;
				frame->back_mem->DrawLine(i,Y1,(i+1),Y2);
			}
		}
		else
		{
			for(float i=0;i<prag;++i)
			{		
				Y1=frame->panel_mid-(*response)[i*pas]*k;
				Y2=frame->panel_mid-(*response)[(i+1)*pas]*k;
				frame->back_mem->DrawLine(i,Y1,(i+1),Y2);
			}
		}
	} 

	response->Destroy();
	mu->lock();
	{
		wxClientDC client(frame->panel);
		client.Blit(0,0,frame->panel_width,frame->panel_height,frame->back_mem,0,0);
	}
	mu->unlock();
}

void WorkingFrame::Close( wxCloseEvent& event )
{
	panel1_specs->active=false;
	panel2_specs->active=false;
	this->Hide();

	if(spectrumLeft->IsShown())
	{
		spectrumLeft->Hide();
		spectrumLeft->Stop();
	}

	if(spectrumRight->IsShown())
	{
		spectrumRight->Hide();
		spectrumRight->Stop();
	}

	Sleep(500);
	exit(0);
}