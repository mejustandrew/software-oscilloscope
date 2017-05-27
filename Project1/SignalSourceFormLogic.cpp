#include "SignalSourceFormLogic.h"


SignalSourceFormLogic::SignalSourceFormLogic(wxWindow * parent) : SignalSourceForm(parent)
{
	InitializeLabels();
}

SignalSourceFormLogic::~SignalSourceFormLogic()
{
}

SignalSource SignalSourceFormLogic::GetChosenSignalSource()
{
	return signalSettings.Source;
}

SignalType SignalSourceFormLogic::GetChosenSignalType()
{
	return signalSettings.Type;
}

SinusoidalSignal SignalSourceFormLogic::GetSinusoidalSignalProperties()
{
	int amplitudeSelection = signalSettings.SinusoidalAmplitudeChoice;
	string amplitudeText = sinusoidalProperties.amplitudeLevels[amplitudeSelection];
	double amplitudeValue = stod(amplitudeText);

	int frequencySelection = signalSettings.FrequencyChoice;
	string frequencyText = sinusoidalProperties.frequencyLevels[frequencySelection];
	double frequencyValue = stod(frequencyText);

	return SinusoidalSignal(amplitudeValue, frequencyValue);
}

GaussianNoise SignalSourceFormLogic::GetGaussianNoiseProperties()
{
	int varianceSelection = signalSettings.VarianceChoice;
	string varianceText = gaussianNoiseProperties.varianceLevels[varianceSelection];
	double varianceValue = stod(varianceText);

	int meanSelection = signalSettings.MeanChoice;
	string meanText = gaussianNoiseProperties.meanLevels[meanSelection];
	double meanValue = stod(meanText);

	return GaussianNoise(varianceValue, meanValue);
}

PwmSignal SignalSourceFormLogic::GetPwmSignalProperties()
{
	int amplitudeSelection = signalSettings.PwmAmplitudeChoice;
	string amplitudeText = pwmProperties.amplitudeLevels[amplitudeSelection];
	double amplitudeValue = stod(amplitudeText);

	int dutyCycleSelection = signalSettings.DutyCycleChoice;
	string dutyCycleText = pwmProperties.dutyCycleLevels[dutyCycleSelection];
	double dutyCycleValue = stod(dutyCycleText);

	return PwmSignal(amplitudeValue, dutyCycleValue);
}

void SignalSourceFormLogic::OnRadioBoxButtonClicked(wxCommandEvent & event)
{
	ProcessSignalSourceChoice();
	okayButton->Enable();
}

void SignalSourceFormLogic::OnSignalTypeChoice(wxCommandEvent & event)
{
	ProcessSignalTypeChoice();
	okayButton->Enable();
}

void SignalSourceFormLogic::OnSecondSignalOptionChoice(wxCommandEvent & event)
{
	okayButton->Enable();
}

void SignalSourceFormLogic::OnFirstSignalOptionChoice(wxCommandEvent & event)
{
	okayButton->Enable();
}

void SignalSourceFormLogic::OnOkayClick(wxCommandEvent & event)
{
	CopySignalSettingsFromDialog();
	this->EndModal(true);
}

void SignalSourceFormLogic::OnClose(wxCloseEvent & event)
{
	Cancel();
}

void SignalSourceFormLogic::OnCancelClick(wxCommandEvent & event)
{
	Cancel();
}

void SignalSourceFormLogic::OnInitializeDialog(wxInitDialogEvent & event)
{
	ProcessSignalTypeChoice();
	CopySignalSettingsToDialog();
	ProcessSignalSourceChoice();
	okayButton->Disable();
}

void SignalSourceFormLogic::OnActivateDialog(wxActivateEvent & event)
{
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
		PopulateControlsForSinusoidalSignal();
	}
	else if (selection == 1)
	{
		PopulateControlsForNoiseSignal();
	}
	else if (selection == 2)
	{
		PopulateControlsForPWMSignal();
	}
	firstSignalOptionChoice->SetSelection(0);
	secondSignalOptionChoice->SetSelection(0);
}

void SignalSourceFormLogic::InitializeLabels()
{
	firstColumnLabels[0] = "Amplitude";
	firstColumnLabels[1] = "Variance";
	firstColumnLabels[2] = "Amplitude";

	secondColumnLabels[0] = "Frequency";
	secondColumnLabels[1] = "Mean";
	secondColumnLabels[2] = "Duty Cycle";
}

void SignalSourceFormLogic::SetLabelsForSelection(int selection)
{
	amplitudeLabel->SetLabelText(firstColumnLabels[selection]);
	frequencyLabel->SetLabelText(secondColumnLabels[selection]);
}

void SignalSourceFormLogic::DisableControls()
{
	signalTypeChoice->Disable();
	firstSignalOptionChoice->Disable();
	secondSignalOptionChoice->Disable();
}

void SignalSourceFormLogic::EnableControls()
{
	signalTypeChoice->Enable();
	firstSignalOptionChoice->Enable();
	secondSignalOptionChoice->Enable();
}

void SignalSourceFormLogic::PopulateControlsForSinusoidalSignal()
{
	PopulateChoiceOptions(firstSignalOptionChoice, sinusoidalProperties.amplitudeLevels);
	PopulateChoiceOptions(secondSignalOptionChoice, sinusoidalProperties.frequencyLevels);
}

void SignalSourceFormLogic::PopulateControlsForNoiseSignal()
{
	PopulateChoiceOptions(firstSignalOptionChoice, gaussianNoiseProperties.varianceLevels);
	PopulateChoiceOptions(secondSignalOptionChoice, gaussianNoiseProperties.meanLevels);
}

void SignalSourceFormLogic::PopulateControlsForPWMSignal()
{
	PopulateChoiceOptions(firstSignalOptionChoice, pwmProperties.amplitudeLevels);
	PopulateChoiceOptions(secondSignalOptionChoice, pwmProperties.dutyCycleLevels);
}

void SignalSourceFormLogic::PopulateChoiceOptions(wxChoice * choice, std::vector<string> source)
{
	choice->Clear();
	for (int i = 0; i < source.size(); i++)
	{
		choice->Append(source[i]);
	}
}

void SignalSourceFormLogic::Cancel()
{
	CopySignalSettingsToDialog();
	this->EndModal(true);
}

void SignalSourceFormLogic::CopySignalSettingsToDialog()
{
	signalChoiceRadioBox->SetSelection(signalSettings.Source);
	signalTypeChoice->SetSelection(signalSettings.Type);
	if (signalSettings.Type == 0)
	{
		firstSignalOptionChoice->SetSelection(signalSettings.SinusoidalAmplitudeChoice);
		secondSignalOptionChoice->SetSelection(signalSettings.FrequencyChoice);
	}
	else if (signalSettings.Type == 1)
	{
		firstSignalOptionChoice->SetSelection(signalSettings.VarianceChoice);
		secondSignalOptionChoice->SetSelection(signalSettings.MeanChoice);
	}
	else if (signalSettings.Type == 2)
	{
		firstSignalOptionChoice->SetSelection(signalSettings.PwmAmplitudeChoice);
		secondSignalOptionChoice->SetSelection(signalSettings.DutyCycleChoice);
	}
	firstSignalOptionChoice->Refresh();
	secondSignalOptionChoice->Refresh();
}

void SignalSourceFormLogic::CopySignalSettingsFromDialog()
{
	signalSettings.Source = (SignalSource)signalChoiceRadioBox->GetSelection();
	signalSettings.Type = (SignalType)signalTypeChoice->GetSelection();
	if (signalSettings.Type == 0)
	{
		signalSettings.SinusoidalAmplitudeChoice = firstSignalOptionChoice->GetSelection();
		signalSettings.FrequencyChoice = secondSignalOptionChoice->GetSelection();
	}
	else if (signalSettings.Type == 1)
	{
		signalSettings.VarianceChoice = firstSignalOptionChoice->GetSelection();
		signalSettings.MeanChoice = secondSignalOptionChoice->GetSelection();
	}
	else if (signalSettings.Type == 2)
	{
		signalSettings.PwmAmplitudeChoice = firstSignalOptionChoice->GetSelection();
		signalSettings.DutyCycleChoice = secondSignalOptionChoice->GetSelection();
	}
}