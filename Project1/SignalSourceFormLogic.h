#pragma once
#include "SignalSourceForm.h"

class SignalSourceFormLogic : public SignalSourceForm
{
	virtual void OnRadioBoxButtonClicked(wxCommandEvent& event);
	virtual void OnSignalTypeChoice(wxCommandEvent& event);
	virtual void OnAmplitudeChoice(wxCommandEvent& event);
	virtual void OnVarianceChoice(wxCommandEvent& event);
	virtual void OnContinousValueChoice(wxCommandEvent& event);
	virtual void OnFrequencyChoice(wxCommandEvent& event);
	virtual void OnMeanChoice(wxCommandEvent& event);

public:
	SignalSourceFormLogic(wxWindow* parent);
	~SignalSourceFormLogic();
};