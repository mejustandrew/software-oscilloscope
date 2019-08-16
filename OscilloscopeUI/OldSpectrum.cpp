#include"Spectrum.h"
#include"DataRequest.h"
#include "IDataResponse.h"
#include"Imported.h"
#include<thread>

SpectrumFrame::SpectrumFrame( wxWindow* parent )
:
GeneratedFrame( parent )
{
	m_panel1->GetSize(&panel_width,&panel_height);
	MaxPanel_height=m_panel1->GetMaxHeight();
	MaxPanel_width=m_panel1->GetMaxWidth();
	panel_mid=panel_height/2;
	specter_bmp.Create(MaxPanel_width,MaxPanel_height);
	pen=new wxPen(*wxGREEN_PEN);
	back_mem.SelectObject(specter_bmp);
	back_mem.SetBackground(*wxBLACK_BRUSH);
	back_mem.SetPen(*pen);
	grid_bmp.Create(MaxPanel_width,MaxPanel_height);
	grid_mem.SelectObject(grid_bmp);
	grid_mem.SetBackground(*wxBLACK_BRUSH);
	grid_mem.Clear();
}

void SpectrumFrame::OnClick( wxMouseEvent& event )
{
	if(active)active=false;
	else 
	{
		Start();
	}
}

void SpectrumFrame::Start()
{
	active=true;
	std::thread Display(Refresh,this);
	Display.detach();
}

void SpectrumFrame::Refresh(SpectrumFrame*frame)
{
	while(frame->active)
	{
		Draw(frame);
		Sleep(1);
	}
}

void SpectrumFrame::OnResize( wxSizeEvent& event )
{
	m_panel1->GetSize(&panel_width,&panel_height);
	panel_mid=panel_height/2;
}

void SpectrumFrame::Draw(SpectrumFrame*frame)
{
	DataRequest r(0.25,0.001);
	IDataResponse* samples=GetSpectrumSamples(&r);
	if(samples==NULL)return;
	int verify_number=400;
	double frequency=0,k=samples->size()/verify_number,amplify_factor=3,max=0,min=0,discretizing_factor=0.005;
	float distance=(float)frame->GetPanelWidth()/verify_number,x=0,step=0;
	int size,iterations;
	if(distance<1)distance=1;
	bool new_max=false,new_min=false;
	size=samples->size()-k;
	frame->back_mem.Blit(0,0,frame->MaxPanel_width,frame->MaxPanel_height,&frame->grid_mem,0,0);
	for(int i=0;i<size;i+=k)
	{
		iterations=i+k;
		for(int j=i;j<iterations;++j)
		{
			if((*samples)[j]>(*samples)[j+1] && (*samples)[j+1]<(*samples)[j+2])
			{
				min=(*samples)[j+1];
				new_min=true;
				if(new_max&&new_min)
				{
					if(max-min>discretizing_factor)
					{
						++frequency;	new_max=false;		new_min=false;
					}
				}
			}
			if((*samples)[j]<(*samples)[j+1] && (*samples)[j+1]>(*samples)[j+2])
			{
				max=(*samples)[j+1];
				new_max=true;
				if(new_max&&new_min)
				{
					if(max-min>discretizing_factor)
					{
						++frequency;	new_max=false;		new_min=false;
					}
				}
			}
		}
		frequency/=0.25;
		frame->back_mem.DrawLine(x,frame->panel_mid-frequency*amplify_factor,x,frame->panel_mid+frequency*amplify_factor);
		x=step;
		step+=distance;
		frequency=0;
	}
	wxClientDC client(frame->m_panel1);
	client.Blit(0,0,frame->panel_width,frame->panel_height,&frame->back_mem,0,0);
	samples->Destroy();
}

void SpectrumFrame::OnPaint( wxPaintEvent& event )
{
	wxPaintDC panel(m_panel1);
	panel.Blit(0,0,panel_width,panel_height,&back_mem,0,0);
}

void SpectrumFrame::OnExit( wxCloseEvent& event )
{
	if(active)active=false;
	this->Hide();
}