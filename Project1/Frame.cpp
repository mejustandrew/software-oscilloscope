///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Frame.h"

///////////////////////////////////////////////////////////////////////////

GeneratedFrame::GeneratedFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 600,400 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer1->Add( m_panel1, 1, wxALL|wxEXPAND, 5 );
	
	wxGridBagSizer* gbSizer3;
	gbSizer3 = new wxGridBagSizer( 0, 0 );
	gbSizer3->SetFlexibleDirection( wxBOTH );
	gbSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	info_frequency = new wxStaticText( this, wxID_ANY, wxT("Frequency: "), wxDefaultPosition, wxDefaultSize, 0 );
	info_frequency->Wrap( -1 );
	gbSizer3->Add( info_frequency, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	frequency_text = new wxStaticText( this, wxID_ANY, wxT(" 000.0"), wxDefaultPosition, wxDefaultSize, 0 );
	frequency_text->Wrap( -1 );
	gbSizer3->Add( frequency_text, wxGBPosition( 0, 10 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString spectrum_ChoiceChoices[] = { wxT("FFT"), wxT("time/Freq") };
	int spectrum_ChoiceNChoices = sizeof( spectrum_ChoiceChoices ) / sizeof( wxString );
	spectrum_Choice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, spectrum_ChoiceNChoices, spectrum_ChoiceChoices, 0 );
	spectrum_Choice->SetSelection( 0 );
	gbSizer3->Add( spectrum_Choice, wxGBPosition( 0, 20 ), wxGBSpan( 1, 1 ), wxBOTTOM, 5 );
	
	
	bSizer1->Add( gbSizer3, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GeneratedFrame::OnExit ) );
	m_panel1->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GeneratedFrame::OnClick ), NULL, this );
	m_panel1->Connect( wxEVT_MOTION, wxMouseEventHandler( GeneratedFrame::VerifyFrequency ), NULL, this );
	m_panel1->Connect( wxEVT_PAINT, wxPaintEventHandler( GeneratedFrame::OnPaint ), NULL, this );
	m_panel1->Connect( wxEVT_SIZE, wxSizeEventHandler( GeneratedFrame::OnResize ), NULL, this );
	spectrum_Choice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GeneratedFrame::OnSpectrumChoice ), NULL, this );
}

GeneratedFrame::~GeneratedFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GeneratedFrame::OnExit ) );
	m_panel1->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GeneratedFrame::OnClick ), NULL, this );
	m_panel1->Disconnect( wxEVT_MOTION, wxMouseEventHandler( GeneratedFrame::VerifyFrequency ), NULL, this );
	m_panel1->Disconnect( wxEVT_PAINT, wxPaintEventHandler( GeneratedFrame::OnPaint ), NULL, this );
	m_panel1->Disconnect( wxEVT_SIZE, wxSizeEventHandler( GeneratedFrame::OnResize ), NULL, this );
	spectrum_Choice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GeneratedFrame::OnSpectrumChoice ), NULL, this );
	
}
