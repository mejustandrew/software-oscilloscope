#include "WorkingFrame.h" 
#include "Imported.h"
#include<thread>

WorkingFrame::WorkingFrame( wxWindow* parent )
:
BuiltFrame( parent )
{
	spectrum=new SpectrumFrame(NULL);
	vertical_value=0.05;
	timeBase_value=0.001;
	treshold_value=0.001;
	grid_div=50;
	prev_seconds_selection=1;
	prev_volt_selection=1;
	m_panel1->GetSize(&panel_width,&panel_height);
	panel_mid=panel_height*0.5;
	isAntiAlise=false;
	antiAlise_pen=new wxPen;
	antiAlise_pen->SetColour(77,100,33);
	wave_bitmap=new wxBitmap;
	grid_bitmap=new wxBitmap;
	antiAlise_bitmap=new wxBitmap;
	back_mem=new wxMemoryDC;
	back_mem2=new wxMemoryDC;
	antiAlise_mem2=new wxMemoryDC;
	grid_mem=new wxMemoryDC;

	antiAlise_mem=new wxMemoryDC;
	antiAlise_mem2=new wxMemoryDC;
	maxPanel_width=m_panel1->GetMaxSize().GetWidth();
	antiAlise_bitmap->Create(maxPanel_width,panel_height);
	wave_bitmap->Create(maxPanel_width,panel_height);
	grid_bitmap->Create(maxPanel_width,panel_height);

	antiAlise_mem->SetPen(*antiAlise_pen);
	antiAlise_mem->SetBackground(*wxBLACK_BRUSH);	
	antiAlise_mem->SelectObject(*antiAlise_bitmap);
	antiAlise_mem2->SetPen(*antiAlise_pen);
	antiAlise_mem2->SetBackground(*wxBLACK_BRUSH);	
	antiAlise_mem2->SelectObject(*antiAlise_bitmap);
	back_mem->SetPen(*wxGREEN_PEN);
	back_mem->SetBackground(*wxBLACK_BRUSH);
	back_mem->SelectObject(*wave_bitmap);
	back_mem2->SetPen(*wxGREEN_PEN);
	back_mem2->SetBackground(*wxBLACK_BRUSH);
	back_mem2->SelectObject(*wave_bitmap);
	grid_mem->SetPen(*wxGREEN_PEN);
	grid_mem->SetBackground(*wxBLACK_BRUSH);
	grid_mem->SelectObject(*grid_bitmap);
	DrawGrid();
	back_mem->Blit(0,0,panel_width,panel_height,grid_mem,0,0);
	back_mem2->Blit(0,0,panel_width,panel_height,grid_mem,0,0);
}

 //std::mutex WorkingFrame::mu;

 void WorkingFrame::VerifyValues( wxMouseEvent& event )
 {
	 wxPoint current_position=m_panel1->ScreenToClient(wxGetMousePosition());
	 wxString s;
	 s<<GetTimeBase()*1000/panel_width*current_position.x;
	 timeLabel->SetLabelText(s);
	 s="";
	 s<<(GetVerticalSize()*1000)/panel_height*(panel_mid-current_position.y);
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

void WorkingFrame::VerifyValues2( wxMouseEvent& event )
{
	 wxPoint current_position=m_panel2->ScreenToClient(wxGetMousePosition());
	 wxString s;
	 s<<GetTimeBase()*1000/panel_width*current_position.x;
	 timeLabel->SetLabelText(s);
	 s="";
	 s<<(GetVerticalSize()*1000)/panel_height*(panel_mid-current_position.y);
	 amplitudeLabel->SetLabelText(s);
}

void WorkingFrame::OnPanelPaint2( wxPaintEvent& event )
{
	wxPaintDC paint(m_panel1);
	paint.Blit(0,0,panel_width,panel_height,back_mem2,0,0);
}

void WorkingFrame::OnAntiAliase( wxCommandEvent& event )
{
	isAntiAlise=!isAntiAlise;
}

void WorkingFrame::OnPositionChanged( wxSpinEvent& event )
{
	panel_mid=panel_height*0.5-5*PositionValue->GetValue();
}

 void WorkingFrame::DrawGrid()
 {
	  grid_mem->Clear();
	 for(int i=0;i<maxPanel_width;i+=5)
	 {
		 for(int j=0;j<maxPanel_width;j+=grid_div)
		 {
			 grid_mem->DrawLine(i,j,i,j+1);
		 }
	 }
	 for(int i=0;i<maxPanel_width;i+=5)
	 {
		 for(int j=0;j<maxPanel_width;j+=grid_div)
		 {
			 grid_mem->DrawLine(j,i,j,i+1);
		 }
	 }
 }

 void WorkingFrame::OnSpecterClick( wxCommandEvent& event )
 {
	 if(spectrum->IsShown())
	 {
		 return;
	 }
	 else
	 {
		  spectrum->Show();
		  spectrum->Start();
	 }
 }

WorkingFrame::~WorkingFrame()
	{ 
		delete back_mem;
		delete grid_mem;
		delete grid_bitmap;
		delete wave_bitmap;
	}

void WorkingFrame::VerticalSizeChanged(wxCommandEvent& event)
{
	 wxString returned = VerticalSize->GetString(VerticalSize->GetSelection());
	 double converted;
	 returned.ToDouble(&converted);
	 if(voltSelection->GetSelection()==1)converted*=0.001;
	 vertical_value=converted;
}

void WorkingFrame::TimeBaseChanged( wxCommandEvent& event )
{
	wxString returned = timeBase->GetString(timeBase->GetSelection());
	double converted;
	returned.ToDouble(&converted);
	if(secondSelection->GetSelection()==1)converted*=0.001;
	timeBase_value=converted;
}

void WorkingFrame::TresholdChanged( wxSpinEvent& event )
{
	treshold_value = Treshold->GetValue()*0.001;
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

void WorkingFrame::OnPanelResized( wxSizeEvent& event )
{
	m_panel1->GetSize(&panel_width,&panel_height);
	panel_mid=panel_height*0.5;
}

void WorkingFrame::DisplayFrequency(WorkingFrame*frame,IDataResponse *values)
{
	bool crescator=true,new_max=false,new_min=false;
	double frequency=0,max,min,prag=0.005;
	if(values==NULL)return;
	int size=values->size()-1;
	for(int i=0;i<size;i+=2)
	{
		if((*values)[i+1]>(*values)[i] && crescator==false)
			{
				crescator=true;
				min=(*values)[i];
				new_min=true;
				if(new_max && new_min)
				{
					new_max=false;
					new_min=false;
					if(max-min>prag)
						++frequency;
				}
			}
			if((*values)[i+1]<(*values)[i] && crescator==true)
			{
				crescator=false;
				max=(*values)[i];
				new_max=true;
				if(new_max && new_min)
				{
					new_max=false;
					new_min=false;
					if(max-min>prag)
						++frequency;
				}
			}
	}
	frequency/=frame->timeBase_value;
	frame->display_frequency<<(int)frequency;
	frame->FrequencyDisplayText->SetLabel(frame->display_frequency);
	frame->display_frequency="";
}

void WorkingFrame::OnStateChanged( wxMouseEvent& event )
{
	if(active)
	{
		active=false;
		state_button->SetLabel("On");
	}
	else
	{
		Create(this);
		state_button->SetLabel("Off");
	}
}

void WorkingFrame::Create(WorkingFrame* frame)
{
	if(Initialize())
	{
		frame->active=true;
		std::thread refreshThread(Refresh,frame);
		refreshThread.detach();
	}
	else wxMessageBox("Opening PortAudio stream did not succeed,\nreopen application after verify Recording Devices\nmay solve this problem");
}

void WorkingFrame::Refresh(WorkingFrame* frame)
{
	frame->finished=false;
	while(frame->active)
	{
		Draw(frame);
		Sleep(1);
	}
	frame->finished=true;
}

void WorkingFrame::Draw(WorkingFrame* frame)
{
	if(!frame->active)return;
	DataRequest req(frame->GetTimeBase(),frame->GetTreshold());
	IDataResponse* response=GetSignalSamples(&req);
	if(response==NULL)return;
	std::thread freqThread(frame->DisplayFrequency,frame,response);
	freqThread.join();

	float Y1,Y2;
	float iteratii=response->size();
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
		
	float k=frame->panel_height*0.5/frame->GetVerticalSize();
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
	wxClientDC client(frame->m_panel1);
	client.Blit(0,0,frame->panel_width,frame->panel_height,frame->back_mem,0,0);
}

void WorkingFrame::OnPanelPaint( wxPaintEvent& event )
{
	wxPaintDC paint(m_panel1);
	paint.Blit(0,0,panel_width,panel_height,back_mem,0,0);
}

void WorkingFrame::Close( wxCloseEvent& event )
{
	active=false;
	this->Hide();
	 if(spectrum->IsShown())
	 {
		 spectrum->Hide();
		 spectrum->Stop();
	 }
	int countClose=0;
	while(!finished)
	{
		Sleep(150);
		if(countClose==30)break;
		//this is usefull because the program dosen't stop running this loop sometimes even if the 
		//threads finished their working
		++countClose;
	}
	exit(0);
}