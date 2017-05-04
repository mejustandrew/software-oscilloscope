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
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/choice.h>
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
		wxButton* okayButton;
		wxButton* cancelButton;
		wxStaticText* frequencyLabel;
		wxStaticText* amplitudeLabel;
		wxChoice* secondSignalOptionChoice;
		wxChoice* firstSignalOptionChoice;
		wxStaticText* signalTypeText;
		wxChoice* signalTypeChoice;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnActivateDialog( wxActivateEvent& event ) { event.Skip(); }
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnInitializeDialog( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnRadioBoxButtonClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkayClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSecondSignalOptionChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFirstSignalOptionChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSignalTypeChoice( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SignalSourceForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Signal Source"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 334,355 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SignalSourceForm();
	
};

#endif //__SIGNALSOURCEFORM_H__
