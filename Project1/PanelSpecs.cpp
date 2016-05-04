#include"PanelSpecs.h"

PanelSpecs::PanelSpecs(wxPanel*panel,IDataResponse* (*GetSamples)(IDataRequest*)):panel(panel),GetSamples(GetSamples)
{
	TimeBase=0.001;
	Treshold=0.001;
	VerticalSize=0.05;
	panel->GetSize(&panel_width,&panel_height);
	panel_mid=panel_height*0.5;
	antiAlise_pen=new wxPen;
	antiAlise_pen->SetColour(77,100,33);
	isAntiAlise=false;
	wave_bitmap=new wxBitmap;
	grid_bitmap=new wxBitmap;
	antiAlise_bitmap=new wxBitmap;
	back_mem=new wxMemoryDC;
	antiAlise_mem=new wxMemoryDC;
	grid_mem=new wxMemoryDC;
	maxPanel_width=panel->GetMaxSize().GetWidth();
	antiAlise_bitmap->Create(maxPanel_width,panel_height);
	wave_bitmap->Create(maxPanel_width,panel_height);
	grid_bitmap->Create(maxPanel_width,panel_height);
	antiAlise_mem->SetPen(*antiAlise_pen);
	antiAlise_mem->SetBackground(*wxBLACK_BRUSH);	
	antiAlise_mem->SelectObject(*antiAlise_bitmap);
	back_mem->SetPen(*wxGREEN_PEN);
	back_mem->SetBackground(*wxBLACK_BRUSH);
	back_mem->SelectObject(*wave_bitmap);
	grid_mem->SetPen(*wxGREEN_PEN);
	grid_mem->SetBackground(*wxBLACK_BRUSH);
	grid_mem->SelectObject(*grid_bitmap);
	DrawGridLines();
	back_mem->Blit(0,0,panel_width,panel_height,grid_mem,0,0);
}

void PanelSpecs::DrawGridLines()
{
	int	grid_div=50;
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