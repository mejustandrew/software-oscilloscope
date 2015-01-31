#include"Spectrum.h"
#include"Imported.h"
#include<thread>

SpectrumFrame::SpectrumFrame( wxWindow* parent )
:
GeneratedFrame( parent )
{

	active=true;
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

	req=new DataRequest(0.1,0.001);
	IDataResponse* samples=GetSpectrumSamples(req);
	while(samples==nullptr)
	{
		samples=GetSpectrumSamples(req);
	}
	number_in_base2=1;
	int size=samples->size();
	while(number_in_base2<size)
	{
		number_in_base2*=2;
	}
	converted_samples=new double[number_in_base2];

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
		//Sleep(1);
	}
}

void SpectrumFrame::OnResize( wxSizeEvent& event )
{
	m_panel1->GetSize(&panel_width,&panel_height);
	panel_mid=panel_height>>1;
}

void SpectrumFrame::four1(double* data, unsigned long nn)
{
    unsigned long n, mmax, m, j, istep, i;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi,aux;
 
    // reverse-binary reindexing
    n = nn<<1;
    j=1;
    for (i=1; i<n; i+=2) {
        if (j>i) {
            //swap(data[j-1], data[i-1]);
			aux=data[j-1];
			data[j-1]=data[i-1];
			data[i-1]=aux;
            //swap(data[j], data[i]);
			aux=data[j];
			data[j]=data[i];
			data[i]=aux;
        }
        m = nn;
        while (m>=2 && j>m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    };
 
    // here begins the Danielson-Lanczos section
    mmax=2;
    while (n>mmax) {
        istep = mmax<<1;
        theta = -(2*M_PI/mmax);
        wtemp = sin(0.5*theta);
        wpr = -2.0*wtemp*wtemp;
        wpi = sin(theta);
        wr = 1.0;
        wi = 0.0;
        for (m=1; m < mmax; m += 2) {
            for (i=m; i <= n; i += istep) {
                j=i+mmax;
                tempr = wr*data[j-1] - wi*data[j];
                tempi = wr * data[j] + wi*data[j-1];
 
                data[j-1] = data[i-1] - tempr;
                data[j] = data[i] - tempi;
                data[i-1] += tempr;
                data[i] += tempi;
            }
            wtemp=wr;
            wr += wr*wpr - wi*wpi;
            wi += wi*wpr + wtemp*wpi;
        }
        mmax=istep;
    }
}

void SpectrumFrame::ConvertSamples(IDataResponse *source,double *dest,int n)
{
	int iteratii=source->size();
	for(int i=0;i<iteratii;++i)
	{
		dest[i]=(*source)[i];
	}
	for(iteratii;iteratii<n;++iteratii)
	{
		dest[iteratii]=0;
	}
}

void SpectrumFrame::Draw(SpectrumFrame*frame)
{
	IDataResponse* samples=GetSpectrumSamples(frame->req);
	if(samples==nullptr)return;	
	float scalling_factor=4;
	frame->ConvertSamples(samples,frame->converted_samples,frame->number_in_base2);
	
	frame->four1(frame->converted_samples,frame->number_in_base2>>1);//divideing by 2
	
	frame->back_mem.Blit(0,0,frame->MaxPanel_width,frame->MaxPanel_height,&frame->grid_mem,0,0);

	for(int i=0;i<frame->panel_width;++i)
	{
		frame->back_mem.DrawLine(i,frame->panel_mid+frame->converted_samples[i]*scalling_factor,i,frame->panel_mid-frame->converted_samples[i]*scalling_factor);
	}

	wxClientDC client(frame->m_panel1);

	client.Blit(0,0,frame->panel_width,frame->panel_height,&frame->back_mem,0,0);
	
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