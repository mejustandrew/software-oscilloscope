#include "SignalSourceFormLogic.h"


SignalSourceFormLogic::SignalSourceFormLogic(wxWindow * parent) : SignalSourceForm(parent)
{
	InitializeLabels();
	InitializePositionsOfElements();
	ProcessSignalSourceChoice();
	ProcessSignalTypeChoice();
}

SignalSourceFormLogic::~SignalSourceFormLogic()
{
}

void SignalSourceFormLogic::OnRadioBoxButtonClicked(wxCommandEvent & event)
{
	ProcessSignalSourceChoice();
}

void SignalSourceFormLogic::OnSignalTypeChoice(wxCommandEvent & event)
{
	ProcessSignalTypeChoice();
}

void SignalSourceFormLogic::OnAmplitudeChoice(wxCommandEvent & event)
{
}

void SignalSourceFormLogic::OnVarianceChoice(wxCommandEvent & event)
{
}

void SignalSourceFormLogic::OnContinousValueChoice(wxCommandEvent & event)
{
}

void SignalSourceFormLogic::OnFrequencyChoice(wxCommandEvent & event)
{
}

void SignalSourceFormLogic::OnMeanChoice(wxCommandEvent & event)
{
}

void SignalSourceFormLogic::OnApplyClick(wxCommandEvent & event)
{
}

void SignalSourceFormLogic::OnClose(wxCloseEvent & event)
{
	this->EndModal(true);
}

void SignalSourceFormLogic::ProcessSignalSourceChoice()
{
	int selection = signalChoiceRadioBox->GetSelection();
	if (selection == 0)
	{
		DisableControls();
	}
	else
	{
		EnableControls();
	}
}

void SignalSourceFormLogic::ProcessSignalTypeChoice()
{
	int selection = signalTypeChoice->GetSelection();
	SetLabelsForSelection(selection);

	if (selection == 0)
	{
		ShowControlsForSinusoidalSignal();
	}
	else if (selection == 1)
	{
		ShowControlsForNoiseSignal();
	}
	else if (selection == 2)
	{
		ShowControlsForDCSignal();
	}
}

void SignalSourceFormLogic::InitializePositionsOfElements()
{
	varianceChoice->Move(amplitudeChoice->GetPosition());
	meanChoice->Move(frequencyChoice->GetPosition());
	countinousValueChoice->Move(amplitudeChoice->GetPosition());
}

void SignalSourceFormLogic::InitializeLabels()
{
	firstColumnLabels[0] = "Amplitude";
	firstColumnLabels[1] = "Variance";
	firstColumnLabels[2] = "Amplitude";

	secondColumnLabels[0] = "Frequency";
	secondColumnLabels[1] = "Mean";
	secondColumnLabels[2] = "";
}

void SignalSourceFormLogic::SetLabelsForSelection(int selection)
{
	amplitudeLabel->SetLabelText(firstColumnLabels[selection]);
	frequencyLabel->SetLabelText(secondColumnLabels[selection]);
}

void SignalSourceFormLogic::DisableControls()
{
	signalTypeChoice->Disable();
	amplitudeChoice->Disable();
	varianceChoice->Disable();
	countinousValueChoice->Disable();
	frequencyChoice->Disable();
	meanChoice->Disable();
}

void SignalSourceFormLogic::EnableControls()
{
	signalTypeChoice->Enable();
	amplitudeChoice->Enable();
	varianceChoice->Enable();
	countinousValueChoice->Enable();
	frequencyChoice->Enable();
	meanChoice->Enable();
}

void SignalSourceFormLogic::ShowControlsForSinusoidalSignal()
{
	amplitudeChoice->Show();
	frequencyChoice->Show();
	varianceChoice->Hide();
	meanChoice->Hide();
	countinousValueChoice->Hide();
}

void SignalSourceFormLogic::ShowControlsForNoiseSignal()
{
	varianceChoice->Show();
	meanChoice->Show();
	amplitudeChoice->Hide();
	frequencyChoice->Hide();
	countinousValueChoice->Hide();
}

void SignalSourceFormLogic::ShowControlsForDCSignal()
{
	countinousValueChoice->Show();
	amplitudeChoice->Hide();
	frequencyChoice->Hide();
	varianceChoice->Hide();
	meanChoice->Hide();
}

void SignalSourceFormLogic::CopySignalSettingsFromDialog()
{
	signalSettings.Source = (SignalSource)signalChoiceRadioBox->GetSelection();
	signalSettings.Type = (SignalType)signalTypeChoice->GetSelection();
	signalSettings.SinusoidalAmplitudeChoice = amplitudeChoice->GetSelection();
	signalSettings.FrequencyChoice = frequencyChoice->GetSelection();
	signalSettings.VarianceChoice = varianceChoice->GetSelection();
	signalSettings.MeanChoice = meanChoice->GetSelection();
	signalSettings.DCAmplitudeChoice = countinousValueChoice->GetSelection();
}

void SignalSourceFormLogic::CopySignalSettingsToDialog()
{
	signalChoiceRadioBox->SetSelection(signalSettings.Source);
	signalTypeChoice->SetSelection(signalSettings.Type);
	amplitudeChoice->SetSelection(signalSettings.SinusoidalAmplitudeChoice);
	frequencyChoice->SetSelection(signalSettings.FrequencyChoice);
	varianceChoice->SetSelection(signalSettings.VarianceChoice);
	meanChoice->SetSelection(signalSettings.MeanChoice);
	countinousValueChoice->SetSelection(signalSettings.DCAmplitudeChoice);
}
