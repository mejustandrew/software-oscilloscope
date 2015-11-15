///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __PROJECT_H__
#define __PROJECT_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/choice.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/gbsizer.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BuiltFrame
///////////////////////////////////////////////////////////////////////////////
class BuiltFrame : public wxFrame 
{
	private:
	
	protected:
		wxChoice* VerticalSize;
		wxChoice* timeBase;
		wxSpinCtrl* Treshold;
		wxChoice* voltSelection;
		wxChoice* secondSelection;
		wxStaticText* m_staticText8;
		wxStaticText* TresholdText;
		wxStaticText* TimeBaseText;
		wxStaticText* VerticalSizeText;
		wxSpinCtrl* PositionValue;
		wxStaticText* positionText;
		wxButton* SpectrumButton;
		wxButton* state_button;
		wxChoice* VerticalSizeChannel2;
		wxChoice* voltSelectionChannel2;
		wxStaticText* m_staticText13;
		wxChoice* timeBaseChannel2;
		wxChoice* secondSelectionChannel2;
		wxStaticText* m_staticText14;
		wxSpinCtrl* TresholdChannel2;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText16;
		wxSpinCtrl* PositionValueChannel2;
		wxStaticText* m_staticText17;
		wxButton* state_button2;
		wxPanel* m_panel1;
		wxPanel* m_panel2;
		wxCheckBox* antiAliseCheckBox;
		wxStaticText* textFrequency;
		wxStaticText* FrequencyDisplayText;
		wxStaticText* HzUnitsText;
		wxStaticText* timeLabel;
		wxStaticText* amplitudeLabel;
		wxStaticText* msText;
		wxStaticText* mvText;
		
		// Virtual event handlers, overide them in your derived class
		virtual void Close( wxCloseEvent& event ) { event.Skip(); }
		virtual void VerticalSizeChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void TimeBaseChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void TresholdChanged( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnVoltsChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSecondsChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPositionChanged( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnSpecterClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStateChanged( wxMouseEvent& event ) { event.Skip(); }
		virtual void VerticalSize2Changed( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnVolts2Changed( wxCommandEvent& event ) { event.Skip(); }
		virtual void TimeBase2Changed( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSeconds2Changed( wxCommandEvent& event ) { event.Skip(); }
		virtual void Treshold2Changed( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnPosition2Changed( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnStateChangedChannel2( wxMouseEvent& event ) { event.Skip(); }
		virtual void PanelLeave( wxMouseEvent& event ) { event.Skip(); }
		virtual void VerifyValues( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnPanelPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void OnPanelResized( wxSizeEvent& event ) { event.Skip(); }
		virtual void PanelLeave2( wxMouseEvent& event ) { event.Skip(); }
		virtual void VerifyValues2( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnPanelPaint2( wxPaintEvent& event ) { event.Skip(); }
		virtual void OnAntiAliase( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		BuiltFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Oscilloscope"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 840,718 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~BuiltFrame();
	
};

#endif //__PROJECT_H__
