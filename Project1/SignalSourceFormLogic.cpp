#include "SignalSourceFormLogic.h"


SignalSourceFormLogic::SignalSourceFormLogic(wxWindow * parent) : SignalSourceForm(parent)
{
	InitializeLabels();
}

SignalSourceFormLogic::~SignalSourceFormLogic()
{
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
	CopySignalSettingsFromDialog();
	ProcessSignalSourceChoice();
	ProcessSignalTypeChoice();
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
	firstSignalOptionChoice->SetSelection(1);
	secondSignalOptionChoice->SetSelection(1);
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
	PopulateChoiceOptions(firstSignalOptionChoice, pwmPeoperties.amplitudeLevels);
	PopulateChoiceOptions(secondSignalOptionChoice, pwmPeoperties.dutyCycleLevels);
}

void SignalSourceFormLogic::CopySignalSettingsFromDialog()
{
	signalSettings.Source = (SignalSource)signalChoiceRadioBox->GetSelection();
	signalSettings.Type = (SignalType)signalTypeChoice->GetSelection();
}

void SignalSourceFormLogic::CopySignalSettingsToDialog()
{
	signalChoiceRadioBox->SetSelection(signalSettings.Source);
	signalTypeChoice->SetSelection(signalSettings.Type);
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
