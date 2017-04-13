///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __SIGNALSOURCEFORM_H__
#define __SIGNALSOURCEFORM_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/radiobox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/gbsizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class SignalSourceForm
///////////////////////////////////////////////////////////////////////////////
class SignalSourceForm : public wxDialog 
{
	private:
	
	protected:
		wxRadioBox* signalChoiceRadioBox;
		wxStaticText* signalTypeLabel;
		wxChoice* signalTypeChoice;
		wxStaticText* amplitudeLabel;
		wxChoice* amplitudeChoice;
		wxChoice* varianceChoice;
		wxChoice* countinousValueChoice;
		wxStaticText* frequencyLabel;
		wxChoice* frequencyChoice;
		wxChoice* meanChoice;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnRadioBoxButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSignalTypeChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAmplitudeChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnVarianceChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnContinousValueChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFrequencyChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMeanChoice( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SignalSourceForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 476,302 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SignalSourceForm();
	
};

#endif //__SIGNALSOURCEFORM_H__
