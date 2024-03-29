#ifndef __WorkingFrame__
#define __WorkingFrame__
#pragma once
#include"PanelSpecs.h"
#include "IDataRequest.h"
#include "../DataAcquisition/IDataResponse.h"
#include "OscilloscopeUI.h"
#include <atomic>
#include "Manager.h"
#include "SignalSourceFormLogic.h"
#include "SpectrumManager.h"

class WorkingFrame : public BuiltFrame
{
protected:
	// Handlers for BuildedFrame events.
	void VerifyValues(wxMouseEvent& event);
	void PanelLeave(wxMouseEvent& event);
	void OnPanelResized(wxSizeEvent& event);
	void VerticalSizeChanged(wxCommandEvent& event);
	void TimeBaseChanged(wxCommandEvent& event);
	void TresholdChanged(wxSpinEvent& event);
	void OnStateChanged(wxMouseEvent& event);
	void OnSecondsChanged(wxCommandEvent& event);
	void OnVoltsChanged(wxCommandEvent& event);
	void OnPositionChanged(wxSpinEvent& event);
	void OnSpectrumClick(wxCommandEvent& event);
	void OnPanelPaint(wxPaintEvent& event);
	void OnSpectrumClickChannel2(wxCommandEvent& event);
	void OnStateChangedChannel2(wxMouseEvent& event);
	virtual void VerticalSize2Changed(wxCommandEvent& event);
	virtual void OnVolts2Changed(wxCommandEvent& event);
	virtual void TimeBase2Changed(wxCommandEvent& event);
	virtual void OnSeconds2Changed(wxCommandEvent& event);
	virtual void Treshold2Changed(wxSpinEvent& event);
	virtual void OnPosition2Changed(wxSpinEvent& event);
	virtual void OnSignalSource(wxCommandEvent& event);
	virtual void OnHorizontalPositionChanged(wxSpinEvent& event);
	virtual void OnHorizontalPosition2Changed(wxSpinEvent& event);
	virtual void OnLeftSlopeChoice(wxCommandEvent& event);
	virtual void OnRightSlopeChoice(wxCommandEvent& event);
	void Close(wxCloseEvent& event);

	void WorkingFrame::DisplayInitializeErrorMessage();
	bool WorkingFrame::InitializeAudioStream();

	std::atomic_bool active, isResizing;
	int prev_seconds_selection, prev_seconds_selection2, prev_volt_selection, prev_volt_selection2;
	static bool audioStreamInitializedSuccessfully;
	wxString display_frequency;
	PanelSpecs *panel1_specs, *panel2_specs;
	Manager *manager;
	SpectrumManager *spectrumManager;
	SignalSourceFormLogic* signalSourceForm;

public:
	static bool IsAudioStreamInitialized();
	WorkingFrame(wxWindow* parent);
	~WorkingFrame();
};

#endif
