#pragma once
#include "SignalSourceForm.h"

enum SignalSource 
{
	Audio,
	Custom
};

enum SignalType
{
	Sinusoidal,
	Noise,
	DC
};

struct SignalSettings
{
	SignalSource Source;
	SignalType Type;
	int SinusoidalAmplitudeChoice;
	int FrequencyChoice;
	int VarianceChoice;
	int MeanChoice;
	int DCAmplitudeChoice;
};

class SignalSourceFormLogic : public SignalSourceForm
{
	virtual void OnRadioBoxButtonClicked(wxCommandEvent& event);
	virtual void OnSignalTypeChoice(wxCommandEvent& event);
	virtual void OnAmplitudeChoice(wxCommandEvent& event);
	virtual void OnVarianceChoice(wxCommandEvent& event);
	virtual void OnContinousValueChoice(wxCommandEvent& event);
	virtual void OnFrequencyChoice(wxCommandEvent& event);
	virtual void OnMeanChoice(wxCommandEvent& event);
	virtual void OnApplyClick(wxCommandEvent& event);
	virtual void OnClose(wxCloseEvent& event);

	void ProcessSignalSourceChoice();
	void ProcessSignalTypeChoice();
	void InitializePositionsOfElements();
	void InitializeLabels();
	void SetLabelsForSelection(int selection);
	void DisableControls();
	void EnableControls();
	void ShowControlsForSinusoidalSignal();
	void ShowControlsForNoiseSignal();
	void ShowControlsForDCSignal();
	void CopySignalSettingsFromDialog();
	void CopySignalSettingsToDialog();

	SignalSettings signalSettings;
	std::string firstColumnLabels[3];
	std::string secondColumnLabels[3];

public:
	SignalSourceFormLogic(wxWindow* parent);
	~SignalSourceFormLogic();
};