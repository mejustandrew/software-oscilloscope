///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __FRAME_H__
#define __FRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/gbsizer.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GeneratedFrame
///////////////////////////////////////////////////////////////////////////////
class GeneratedFrame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel1;
		wxStaticText* info_frequency;
		wxStaticText* frequency_text;
		wxChoice* spectrum_Choice;
		wxStaticText* scalingFactor_text;
		wxChoice* scalingFactorChoice;
		wxChoice* frequnciesChoice;
		wxStaticText* m_staticText4;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnExit( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void VerifyFrequency( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void OnResize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnSpectrumChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnScalingFactor( wxCommandEvent& event ) { event.Skip(); }
		virtual void MaxFrequencyChanged( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GeneratedFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Frequnecy Display"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~GeneratedFrame();
	
};

#endif //__FRAME_H__
