#pragma once
#include "SignalSourceForm.h"
#include "SignalModels.h"
#include "SignalTypesAvaiableProperties.h"

enum SignalSource 
{
	Audio,
	Custom
};

enum SignalType
{
	Sinusoidal,
	Noise,
	PWM
};

struct SignalSettings
{
	SignalSource Source;
	SignalType Type;
	int SinusoidalAmplitudeChoice;
	int FrequencyChoice;
	int VarianceChoice;
	int MeanChoice;
	int PwmAmplitudeChoice;
	int DutyCycleChoice;
};

class SignalSourceFormLogic : public SignalSourceForm
{
	virtual void OnRadioBoxButtonClicked(wxCommandEvent& event);
	virtual void OnSignalTypeChoice(wxCommandEvent& event);
	virtual void OnSecondSignalOptionChoice(wxCommandEvent& event);
	virtual void OnFirstSignalOptionChoice(wxCommandEvent& event);
	virtual void OnOkayClick(wxCommandEvent& event);
	virtual void OnClose(wxCloseEvent& event);
	virtual void OnInitializeDialog(wxInitDialogEvent& event);
	virtual void OnActivateDialog(wxActivateEvent& event);
	virtual void OnCancelClick(wxCommandEvent& event);

	void ProcessSignalSourceChoice();
	void ProcessSignalTypeChoice();
	void InitializeLabels();
	void SetLabelsForSelection(int selection);
	void DisableControls();
	void EnableControls();
	void PopulateControlsForSinusoidalSignal();
	void PopulateControlsForNoiseSignal();
	void PopulateControlsForPWMSignal();
	void CopySignalSettingsFromDialog();
	void CopySignalSettingsToDialog();
	void PopulateChoiceOptions(wxChoice* choice, std::vector<std::string> source);
	void Cancel();

	SignalSettings signalSettings;
	SinusoidalTypeAvaiableProperties sinusoidalProperties;
	GaussianNoiseTypeAvaiableProperties gaussianNoiseProperties;
	PWMTypeAvaiableProperties pwmProperties;

	std::string firstColumnLabels[3];
	std::string secondColumnLabels[3];

public:
	SignalSourceFormLogic(wxWindow* parent);
	~SignalSourceFormLogic();
	SignalSource GetChosenSignalSource();
	SignalType GetChosenSignalType();
	SinusoidalSignal GetSinusoidalSignalProperties();
	GaussianNoise GetGaussianNoiseProperties();
	PwmSignal GetPwmSignalProperties();
};