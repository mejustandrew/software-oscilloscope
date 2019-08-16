#pragma once
#include "WorkingFrame.h" 
#include "Imported.h"
#include<thread>
#include <iomanip>
#include <sstream>

bool WorkingFrame::audioStreamInitializedSuccessfully = false;


WorkingFrame::WorkingFrame(wxWindow* parent)
	:
	BuiltFrame(parent)
{
	Initialize();

	prev_seconds_selection = 1;
	prev_volt_selection = 1;
	prev_seconds_selection2 = 1;
	prev_volt_selection2 = 1;

	panel1_specs = new PanelSpecs(m_panel1, GetSignalLeftSamples);
	panel2_specs = new PanelSpecs(m_panel1, GetSignalRightSamples);

	audioStreamInitializedSuccessfully = InitializeAudioStream();
	if (audioStreamInitializedSuccessfully)
	{
		panel1_specs->active = true;
		panel2_specs->active = true;
	}
	else
	{
		DisplayInitializeErrorMessage();
	}

	spectrumManager = new SpectrumManager;
	delete panel2_specs->back_mem;
	panel2_specs->back_mem = panel1_specs->back_mem;
	manager = new Manager(panel1_specs, panel2_specs);
	manager->StartProcessingData();
	signalSourceForm = new SignalSourceFormLogic(this);
}

bool WorkingFrame::IsAudioStreamInitialized()
{
	return audioStreamInitializedSuccessfully;
}


std::string GetTruncatedDecimalsStringFromDouble(double value)
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << value;
	return stream.str();
}

void WorkingFrame::VerifyValues(wxMouseEvent& event)
{
	wxPoint current_position = m_panel1->ScreenToClient(wxGetMousePosition());
	wxString s;
	s = GetTruncatedDecimalsStringFromDouble((panel1_specs->TimeBase * 1000) / panel1_specs->panel_width * current_position.x);
	timeLeftChannel->SetLabelText(s);

	s = GetTruncatedDecimalsStringFromDouble((panel1_specs->VerticalSize * 1000) / panel1_specs->panel_height * (panel1_specs->panel_mid - current_position.y));
	amplitudeLabelLeftChannel->SetLabelText(s);

	s = GetTruncatedDecimalsStringFromDouble((panel2_specs->TimeBase * 1000 / panel2_specs->panel_width * current_position.x));
	timeLabel->SetLabelText(s);

	s = GetTruncatedDecimalsStringFromDouble((panel2_specs->VerticalSize * 1000) / panel2_specs->panel_height * (panel2_specs->panel_mid - current_position.y));
	amplitudeLabel->SetLabelText(s);
}

void WorkingFrame::PanelLeave(wxMouseEvent& event)
{
	timeLabel->SetLabelText("0.00");
	amplitudeLabel->SetLabelText("0.00");
}

void WorkingFrame::OnPanelPaint(wxPaintEvent& event)
{
	wxPaintDC paint(m_panel1);
	paint.Blit(0, 0, panel1_specs->panel_width, panel1_specs->panel_height, panel1_specs->paint_mem, 0, 0);
}

void WorkingFrame::OnPositionChanged(wxSpinEvent& event)
{
	panel1_specs->panel_mid = panel1_specs->panel_height / 2 - PositionValue->GetValue();
}

void WorkingFrame::OnPosition2Changed(wxSpinEvent& event)
{
	panel2_specs->panel_mid = panel2_specs->panel_height / 2 - PositionValueChannel2->GetValue();
}

void WorkingFrame::OnSignalSource(wxCommandEvent & event)
{
	signalSourceForm->ShowModal();
	SignalSource signalSource = signalSourceForm->GetChosenSignalSource();
	SignalType signalType = signalSourceForm->GetChosenSignalType();
	if (signalSource == SignalSource::Audio)
	{
		manager->SwitchSignalSourceToAudio();
		spectrumManager->SwitchSignalSourceToAudio();
	}
	else
	{
		if (signalType == SignalType::Sinusoidal)
		{
			SinusoidalSignal sinusoidalLeftSignalModel = signalSourceForm->GetSinusoidalSignalProperties();
			SinusoidalSignal sinusoidalRightSignalModel = signalSourceForm->GetSinusoidalSignalProperties();

			manager->SwitchSignalSourceToCustomSinusoidal(sinusoidalLeftSignalModel, sinusoidalRightSignalModel);
			spectrumManager->SwitchSignalSourceToCustomSinusoidal(sinusoidalLeftSignalModel, sinusoidalRightSignalModel);
		}
		else if (signalType == SignalType::Noise)
		{
			GaussianNoise gaussianNoiseLeftSignalModel = signalSourceForm->GetGaussianNoiseProperties();
			GaussianNoise gaussianNoiseRightSignalModel = signalSourceForm->GetGaussianNoiseProperties();

			manager->SwitchSignalSourceToCustomGaussianNoise(gaussianNoiseLeftSignalModel, gaussianNoiseRightSignalModel);
			spectrumManager->SwitchSignalSourceToCustomGaussianNoise(gaussianNoiseLeftSignalModel, gaussianNoiseRightSignalModel);
		}
		else if (signalType == SignalType::PWM)
		{

		}
	}
}

void WorkingFrame::OnSpectrumClick(wxCommandEvent& event)
{
	spectrumManager->ShowLeftChannelSpectrum();
}

void WorkingFrame::OnSpectrumClickChannel2(wxCommandEvent& event)
{
	spectrumManager->ShowRightChannelSpectrum();
}

WorkingFrame::~WorkingFrame()
{

}

void WorkingFrame::VerticalSizeChanged(wxCommandEvent& event)
{
	wxString returned = VerticalSize->GetString(VerticalSize->GetSelection());
	double converted;
	returned.ToDouble(&converted);
	if (voltSelection->GetSelection() == 1)converted *= 0.001;
	panel1_specs->VerticalSize = converted;
}

void WorkingFrame::VerticalSize2Changed(wxCommandEvent& event)
{
	wxString returned = VerticalSizeChannel2->GetString(VerticalSizeChannel2->GetSelection());
	double converted;
	returned.ToDouble(&converted);
	if (voltSelectionChannel2->GetSelection() == 1)converted *= 0.001;
	panel2_specs->VerticalSize = converted;
}

void WorkingFrame::TimeBaseChanged(wxCommandEvent& event)
{
	wxString returned = timeBase->GetString(timeBase->GetSelection());
	double converted;
	returned.ToDouble(&converted);
	if (secondSelection->GetSelection() == 1)converted *= 0.001;
	panel1_specs->TimeBase = converted;
}

void WorkingFrame::TimeBase2Changed(wxCommandEvent& event)
{
	wxString returned = timeBaseChannel2->GetString(timeBaseChannel2->GetSelection());
	double converted;
	returned.ToDouble(&converted);
	if (secondSelection->GetSelection() == 1)converted *= 0.001;
	panel2_specs->TimeBase = converted;
}

void WorkingFrame::TresholdChanged(wxSpinEvent& event)
{
	panel1_specs->Treshold = Treshold->GetValue()*0.001;
}

void WorkingFrame::Treshold2Changed(wxSpinEvent& event)
{
	panel2_specs->Treshold = TresholdChannel2->GetValue()*0.001;
}

void WorkingFrame::OnSecondsChanged(wxCommandEvent& event)
{
	if (secondSelection->GetSelection() == 0 && prev_seconds_selection != 0)
	{
		int selections_nuber = timeBase->GetCount();
		double newValue;
		wxString newSring;
		for (int i = 0; i < selections_nuber; ++i)
		{
			timeBase->GetString(i).ToDouble(&newValue);
			newValue *= 0.001;
			newSring << newValue;
			timeBase->SetString(i, newSring);
			newSring = "";
		}
		prev_seconds_selection = 0;
	}
	else if (secondSelection->GetSelection() == 1 && prev_seconds_selection != 1)
	{
		int selections_nuber = timeBase->GetCount();
		double newValue;
		wxString newSring;
		for (int i = 0; i < selections_nuber; ++i)
		{
			timeBase->GetString(i).ToDouble(&newValue);
			newValue *= 1000;
			newSring << newValue;
			timeBase->SetString(i, newSring);
			newSring = "";
		}
		prev_seconds_selection = 1;
	}
}

void WorkingFrame::OnSeconds2Changed(wxCommandEvent& event)
{
	if (secondSelectionChannel2->GetSelection() == 0 && prev_seconds_selection2 != 0)
	{
		int selections_nuber = timeBaseChannel2->GetCount();
		double newValue;
		wxString newSring;
		for (int i = 0; i < selections_nuber; ++i)
		{
			timeBaseChannel2->GetString(i).ToDouble(&newValue);
			newValue *= 0.001;
			newSring << newValue;
			timeBaseChannel2->SetString(i, newSring);
			newSring = "";
		}
		prev_seconds_selection2 = 0;
	}
	else if (secondSelectionChannel2->GetSelection() == 1 && prev_seconds_selection2 != 1)
	{
		int selections_nuber = timeBaseChannel2->GetCount();
		double newValue;
		wxString newSring;
		for (int i = 0; i < selections_nuber; ++i)
		{
			timeBaseChannel2->GetString(i).ToDouble(&newValue);
			newValue *= 1000;
			newSring << newValue;
			timeBaseChannel2->SetString(i, newSring);
			newSring = "";
		}
		prev_seconds_selection2 = 1;
	}
}

void WorkingFrame::OnVoltsChanged(wxCommandEvent& event)
{
	if (voltSelection->GetSelection() == 0 && prev_volt_selection != 0)
	{
		int selections_nuber = VerticalSize->GetCount();
		double newValue;
		wxString newSring;
		for (int i = 0; i < selections_nuber; ++i)
		{
			VerticalSize->GetString(i).ToDouble(&newValue);
			newValue *= 0.001;
			newSring << newValue;
			VerticalSize->SetString(i, newSring);
			newSring = "";
		}
		prev_volt_selection = 0;
	}
	else if (voltSelection->GetSelection() == 1 && prev_volt_selection != 1)
	{
		int selections_nuber = VerticalSize->GetCount();
		double newValue;
		wxString newSring;
		for (int i = 0; i < selections_nuber; ++i)
		{
			VerticalSize->GetString(i).ToDouble(&newValue);
			newValue *= 1000;
			newSring << newValue;
			VerticalSize->SetString(i, newSring);
			newSring = "";
		}
		prev_volt_selection = 1;
	}
}

void WorkingFrame::OnVolts2Changed(wxCommandEvent& event)
{
	if (voltSelectionChannel2->GetSelection() == 0 && prev_volt_selection2 != 0)
	{
		int selections_nuber = VerticalSizeChannel2->GetCount();
		double newValue;
		wxString newSring;
		for (int i = 0; i < selections_nuber; ++i)
		{
			VerticalSizeChannel2->GetString(i).ToDouble(&newValue);
			newValue *= 0.001;
			newSring << newValue;
			VerticalSizeChannel2->SetString(i, newSring);
			newSring = "";
		}
		prev_volt_selection2 = 0;
	}
	else if (voltSelectionChannel2->GetSelection() == 1 && prev_volt_selection2 != 1)
	{
		int selections_nuber = VerticalSizeChannel2->GetCount();
		double newValue;
		wxString newSring;
		for (int i = 0; i < selections_nuber; ++i)
		{
			VerticalSizeChannel2->GetString(i).ToDouble(&newValue);
			newValue *= 1000;
			newSring << newValue;
			VerticalSizeChannel2->SetString(i, newSring);
			newSring = "";
		}
		prev_volt_selection2 = 1;
	}
}

void WorkingFrame::OnPanelResized(wxSizeEvent& event)
{
	isResizing = true;
	m_panel1->GetSize(&panel1_specs->panel_width, &panel1_specs->panel_height);
	panel2_specs->panel_width = panel1_specs->panel_width;
	panel2_specs->panel_height = panel1_specs->panel_height;
	isResizing = false;
}

void WorkingFrame::OnStateChanged(wxMouseEvent& event)
{
	if (panel1_specs->active)
	{
		panel1_specs->active = false;
		state_button->SetLabel("On");
	}
	else
	{
		panel1_specs->active = true;
		state_button->SetLabel("Off");
	}
}

void WorkingFrame::OnStateChangedChannel2(wxMouseEvent& event)
{
	if (panel2_specs->active)
	{
		panel2_specs->active = false;
		state_button2->SetLabel("On");
	}
	else
	{
		panel2_specs->active = true;
		state_button2->SetLabel("Off");
	}
}

void WorkingFrame::DisplayInitializeErrorMessage()
{
	wxMessageBox("Opening PortAudio stream did not succeed,\nreopening application after verify Recording Devices\nmay solve this problem");
}

bool WorkingFrame::InitializeAudioStream()
{
	return Initialize();
}

void WorkingFrame::OnHorizontalPositionChanged(wxSpinEvent & event)
{
	panel1_specs->horizontalPosition = horizontalPosition->GetValue();
}

void WorkingFrame::OnHorizontalPosition2Changed(wxSpinEvent & event)
{
	panel2_specs->horizontalPosition = horizontalPositionChannell2->GetValue();
}

void WorkingFrame::OnLeftSlopeChoice(wxCommandEvent & event)
{
	int selection = leftSlopeChoice->GetSelection();
	bool isPositiveSlope = selection == 0;
	manager->SetLeftSlope(isPositiveSlope);
}

void WorkingFrame::OnRightSlopeChoice(wxCommandEvent & event)
{
	int selection = rightSlopeChoice->GetSelection();
	bool isPositiveSlope = selection == 0;
	manager->SetRightSlope(isPositiveSlope);
}

void WorkingFrame::Close(wxCloseEvent& event)
{
	panel1_specs->active = false;
	panel2_specs->active = false;
	this->Hide();

	spectrumManager->Close();

	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	exit(0);
}