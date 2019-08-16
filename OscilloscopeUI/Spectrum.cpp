#include"Spectrum.h"
#include<thread>

SpectrumFrame::SpectrumFrame(wxWindow* parent, ISingleChannelDataProvider * dataProvider)
	:
	GeneratedFrame(parent), data_provider(dataProvider)
{
	active = false;
	Maximize();
	SetMinSize(GetSize());
	scaling_factor = 1;
	add_pos = 0;
	shown_pos = 0;
	first_resized = true;
	isFFT_spectrum = true;
	info_frequency->SetLabel("");
	frequency_text->SetLabel("");
	number_in_base2 = 1024 * 16;
	timeBase_value = 0.1;

	converted_samples = new double[number_in_base2];
	info_frequency->SetLabel("Frequency");
	grid_mem.Clear();
	StartSpectrumDisplayThread(this);
}
std::mutex guard;

void SpectrumFrame::MaxFrequencyChanged(wxCommandEvent& event)
{
	wxString string_value = frequnciesChoice->GetString(frequnciesChoice->GetSelection());
	long converted_value;
	string_value.ToLong(&converted_value);
	req = new DataRequest((double)panel_width / ((double)converted_value), 0.001);
	RefreshContainers();
}

void SpectrumFrame::OnSpectrumChoice(wxCommandEvent& event)
{
	if (spectrum_Choice->GetSelection() == 0)
	{
		isFFT_spectrum = true;
		for (int i = 0; i < panel_width; ++i)
		{
			freq_container[i] = 0;
		}
	}
	else
	{
		isFFT_spectrum = false;
		mu.lock();
		back_mem.Blit(0, 0, panel_width, panel_height, &grid_mem, 0, 0);
		mu.unlock();
		info_frequency->SetLabel("Frequency");
	}
}

void SpectrumFrame::OnScalingFactor(wxCommandEvent& event)
{
	wxString returned = scalingFactorChoice->GetString(scalingFactorChoice->GetSelection());
	returned.ToDouble(&scaling_factor);
}

void SpectrumFrame::OnClick(wxMouseEvent& event)
{
	if (active)active = false;
	else
	{
		Start();
	}
}

void SpectrumFrame::Start()
{
	active = true;
}

void SpectrumFrame::SetDataProvider(ISingleChannelDataProvider * dataProvider)
{
	data_provider = dataProvider;
}

void SpectrumFrame::SetSampleRate(double sampleRate)
{
	sample_rate = sampleRate;
}

void SpectrumFrame::StartSpectrumDisplayThread(SpectrumFrame*frame)
{
	std::thread Display(Refresh, this);
	Display.detach();
}

void SpectrumFrame::Refresh(SpectrumFrame*frame)
{
	while (true)
	{
		if (frame->active)
		{
			if (frame->isFFT_spectrum)DrawFFT(frame);
			else Draw(frame);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void SpectrumFrame::OnResize(wxSizeEvent& event)
{
	if (first_resized)
	{
		m_panel1->GetSize(&panel_width, &panel_height);
		panel_mid = panel_height / 2;

		specter_bmp.Create(panel_width, panel_height);
		pen = new wxPen(*wxGREEN_PEN);
		back_mem.SelectObject(specter_bmp);
		back_mem.SetBackground(*wxBLACK_BRUSH);
		back_mem.SetPen(*pen);
		grid_bmp.Create(panel_width, panel_height);
		grid_mem.SelectObject(grid_bmp);
		grid_mem.SetBackground(*wxBLACK_BRUSH);
		grid_mem.Clear();
		paint_mem.SelectObject(grid_bmp);
		paint_mem.SetBackground(*wxBLACK_BRUSH);
		paint_mem.Clear();
		RefreshContainers();
		first_resized = false;
	}
}

void SpectrumFrame::RefreshContainers()
{
	freq_container = new double[panel_width];
	spectrum_container = new double[panel_width];
	for (int i = 0; i < panel_width; ++i)
	{
		freq_container[i] = 0;
		spectrum_container[i] = i*sample_rate / number_in_base2;
	}
}

void SpectrumFrame::four1(double* data, unsigned long nn)
{
	unsigned long n, mmax, m, j, istep, i;
	double wtemp, wr, wpr, wpi, wi, theta;
	double tempr, tempi, aux;

	// reverse-binary reindexing
	n = nn << 1;
	j = 1;
	for (i = 1; i < n; i += 2) {
		if (j > i) {
			//swap(data[j-1], data[i-1]);
			aux = data[j - 1];
			data[j - 1] = data[i - 1];
			data[i - 1] = aux;
			//swap(data[j], data[i]);
			aux = data[j];
			data[j] = data[i];
			data[i] = aux;
		}
		m = nn;
		while (m >= 2 && j > m) {
			j -= m;
			m >>= 1;
		}
		j += m;
	};

	// here begins the Danielson-Lanczos section
	mmax = 2;
	while (n > mmax) {
		istep = mmax << 1;
		theta = -(2 * M_PI / mmax);
		wtemp = sin(0.5*theta);
		wpr = -2.0*wtemp*wtemp;
		wpi = sin(theta);
		wr = 1.0;
		wi = 0.0;
		for (m = 1; m < mmax; m += 2) {
			for (i = m; i <= n; i += istep) {
				j = i + mmax;
				tempr = wr*data[j - 1] - wi*data[j];
				tempi = wr * data[j] + wi*data[j - 1];

				data[j - 1] = data[i - 1] - tempr;
				data[j] = data[i] - tempi;
				data[i - 1] += tempr;
				data[i] += tempi;
			}
			wtemp = wr;
			wr += wr*wpr - wi*wpi;
			wi += wi*wpr + wtemp*wpi;
		}
		mmax = istep;
	}
}

void SpectrumFrame::VerifyFrequency(wxMouseEvent& event)
{
	if (isFFT_spectrum)
	{
		wxPoint current_position = m_panel1->ScreenToClient(wxGetMousePosition());
		showFreq = "";
		showFreq << spectrum_container[current_position.x];
		frequency_text->SetLabel(showFreq);
	}
	else
	{
		wxPoint current_position = m_panel1->ScreenToClient(wxGetMousePosition());
		shown_pos = add_pos - panel_width + current_position.x;
		if (shown_pos < 0)shown_pos += panel_width;
		showFreq = "";
		showFreq << freq_container[shown_pos];
		frequency_text->SetLabel(showFreq);
	}
}

void SpectrumFrame::ConvertSamples(IDataResponse *source, double *dest, int n)
{
	for (int i = 0; i < n; ++i)
	{
		dest[i] = (*source)[i];
	}
}

void SpectrumFrame::DrawFFT(SpectrumFrame*frame)
{
	IDataResponse* samples = frame->data_provider->GetNewData(frame->number_in_base2);
	if (samples == nullptr)
		return;
	int magnitude;
	frame->ConvertSamples(samples, frame->converted_samples, frame->number_in_base2);

	frame->four1(frame->converted_samples, frame->number_in_base2 / 2);
	samples->Destroy();
	frame->back_mem.Blit(0, 0, frame->panel_width, frame->panel_height, &frame->grid_mem, 0, 0);

	for (int i = 0, j = 0; j < frame->number_in_base2 / 4; i += 2, ++j)
	{
		magnitude = sqrt(frame->converted_samples[i] * frame->converted_samples[i] + frame->converted_samples[i + 1] * frame->converted_samples[i + 1]);
		frame->back_mem.DrawLine(j, frame->panel_height, j, frame->panel_height - magnitude*frame->scaling_factor);
	}
	frame->paint_mem.Blit(0, 0, frame->panel_width, frame->panel_height, &frame->back_mem, 0, 0);
	frame->m_panel1->Refresh(false);
}

float SpectrumFrame::GetFrequency(SpectrumFrame*frame, double *values, int size)
{
	bool crescator = true, new_max = false, new_min = false;
	double max = 0, min = 0, prag = 0.005;
	float frequency = 0;
	for (int i = 0; i < size; i += 2)
	{
		if (values[i + 1] > values[i] && crescator == false)
		{
			crescator = true;
			min = values[i];
			new_min = true;
			if (new_max && new_min)
			{
				new_max = false;
				new_min = false;
				if (max - min > prag)
					++frequency;
			}
		}
		if (values[i + 1] < values[i] && crescator == true)
		{
			crescator = false;
			max = values[i];
			new_max = true;
			if (new_max && new_min)
			{
				new_max = false;
				new_min = false;
				if (max - min > prag)
					++frequency;
			}
		}
	}
	frequency /= frame->timeBase_value;
	return frequency;
}

void SpectrumFrame::Draw(SpectrumFrame*frame)
{
	IDataResponse* samples = frame->data_provider->GetNewData(frame->number_in_base2);
	if (samples == nullptr)
		return;
	frame->ConvertSamples(samples, frame->converted_samples, samples->size() - 1);
	double recieved_freq = frame->GetFrequency(frame, frame->converted_samples, samples->size() - 1);
	int frequency = recieved_freq / 40;
	int maximumFrequency = frame->GetMaximumFrequency();
	int blitHeight = maximumFrequency > recieved_freq ? maximumFrequency / 40 : frequency;

	frame->back_mem.Blit(0, frame->panel_height - blitHeight, frame->panel_width, blitHeight, &frame->back_mem, 1, frame->panel_height - blitHeight);
	frame->back_mem.Blit(frame->panel_width - 1, frame->panel_height - blitHeight, 1, blitHeight, &frame->grid_mem, 0, frame->panel_height - blitHeight);
	frame->back_mem.DrawLine(frame->panel_width - 1, frame->panel_height - frequency, frame->panel_width - 1, frame->panel_height);
	frame->paint_mem.Blit(0, frame->panel_height - blitHeight, frame->panel_width, blitHeight, &frame->back_mem, 0, frame->panel_height - blitHeight);
	frame->m_panel1->Refresh(false);
	frame->freq_container[frame->add_pos] = recieved_freq;

	if (frame->add_pos + 1 == frame->panel_width)frame->add_pos = 0;
	else
	{
		frame->add_pos++;
	}
}

double SpectrumFrame::GetMaximumFrequency()
{
	double max = 0;
	for (int i = 0; i < panel_width; ++i)
	{
		if (max < freq_container[i]) max = freq_container[i];
	}
	return max;
}

void SpectrumFrame::OnPaint(wxPaintEvent& event)
{
	wxPaintDC panel(m_panel1);
	panel.Blit(0, 0, panel_width, panel_height, &paint_mem, 0, 0);
}

void SpectrumFrame::OnExit(wxCloseEvent& event)
{
	if (active)active = false;
	this->Hide();
}