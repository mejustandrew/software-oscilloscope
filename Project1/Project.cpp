///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Project.h"

///////////////////////////////////////////////////////////////////////////

BuiltFrame::BuiltFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,553 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer( 0, 0 );
	gbSizer1->SetFlexibleDirection( wxBOTH );
	gbSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxGridBagSizer* gbSizer41;
	gbSizer41 = new wxGridBagSizer( 0, 12 );
	gbSizer41->SetFlexibleDirection( wxBOTH );
	gbSizer41->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString VerticalSizeChoices[] = { wxT("50"), wxT("100"), wxT("500") };
	int VerticalSizeNChoices = sizeof( VerticalSizeChoices ) / sizeof( wxString );
	VerticalSize = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), VerticalSizeNChoices, VerticalSizeChoices, 0 );
	VerticalSize->SetSelection( 0 );
	gbSizer41->Add( VerticalSize, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString timeBaseChoices[] = { wxT("1"), wxT("5"), wxT("25"), wxT("125"), wxT("250") };
	int timeBaseNChoices = sizeof( timeBaseChoices ) / sizeof( wxString );
	timeBase = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), timeBaseNChoices, timeBaseChoices, 0 );
	timeBase->SetSelection( 0 );
	gbSizer41->Add( timeBase, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	Treshold = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, -500, 500, 1 );
	gbSizer41->Add( Treshold, wxGBPosition( 5, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString voltSelectionChoices[] = { wxT("Volts"), wxT("mV") };
	int voltSelectionNChoices = sizeof( voltSelectionChoices ) / sizeof( wxString );
	voltSelection = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 55,-1 ), voltSelectionNChoices, voltSelectionChoices, 0 );
	voltSelection->SetSelection( 1 );
	gbSizer41->Add( voltSelection, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString secondSelectionChoices[] = { wxT("Sec"), wxT("mSec") };
	int secondSelectionNChoices = sizeof( secondSelectionChoices ) / sizeof( wxString );
	secondSelection = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 55,-1 ), secondSelectionNChoices, secondSelectionChoices, 0 );
	secondSelection->SetSelection( 1 );
	gbSizer41->Add( secondSelection, wxGBPosition( 3, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("mVolts"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	gbSizer41->Add( m_staticText8, wxGBPosition( 5, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	TresholdText = new wxStaticText( this, wxID_ANY, wxT("Treshold"), wxDefaultPosition, wxDefaultSize, 0 );
	TresholdText->Wrap( -1 );
	gbSizer41->Add( TresholdText, wxGBPosition( 5, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	TimeBaseText = new wxStaticText( this, wxID_ANY, wxT("TimeBase"), wxDefaultPosition, wxDefaultSize, 0 );
	TimeBaseText->Wrap( -1 );
	gbSizer41->Add( TimeBaseText, wxGBPosition( 3, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	VerticalSizeText = new wxStaticText( this, wxID_ANY, wxT("VerticalSize"), wxDefaultPosition, wxDefaultSize, 0 );
	VerticalSizeText->Wrap( -1 );
	gbSizer41->Add( VerticalSizeText, wxGBPosition( 1, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	PositionValue = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, -10, 10, 0 );
	gbSizer41->Add( PositionValue, wxGBPosition( 7, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	positionText = new wxStaticText( this, wxID_ANY, wxT("Position"), wxDefaultPosition, wxDefaultSize, 0 );
	positionText->Wrap( -1 );
	gbSizer41->Add( positionText, wxGBPosition( 7, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	SpectrumButton = new wxButton( this, wxID_ANY, wxT("Spectrum"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer41->Add( SpectrumButton, wxGBPosition( 7, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer1->Add( gbSizer41, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	bSizer1->Add( gbSizer1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxPoint( 0,0 ), wxSize( 400,200 ), wxTAB_TRAVERSAL );
	m_panel1->SetMinSize( wxSize( 400,200 ) );
	m_panel1->SetMaxSize( wxSize( 1350,200 ) );
	
	bSizer2->Add( m_panel1, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	wxGridBagSizer* gbSizer4;
	gbSizer4 = new wxGridBagSizer( 0, 0 );
	gbSizer4->SetFlexibleDirection( wxHORIZONTAL );
	gbSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	antiAliseCheckBox = new wxCheckBox( this, wxID_ANY, wxT("Anti Aliasing"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer4->Add( antiAliseCheckBox, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_BOTTOM|wxALL, 5 );
	
	textFrequency = new wxStaticText( this, wxID_ANY, wxT("Frequency:"), wxDefaultPosition, wxDefaultSize, 0 );
	textFrequency->Wrap( -1 );
	gbSizer4->Add( textFrequency, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	FrequencyDisplayText = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	FrequencyDisplayText->Wrap( -1 );
	gbSizer4->Add( FrequencyDisplayText, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	HzUnitsText = new wxStaticText( this, wxID_ANY, wxT("Hz"), wxDefaultPosition, wxDefaultSize, 0 );
	HzUnitsText->Wrap( -1 );
	gbSizer4->Add( HzUnitsText, wxGBPosition( 2, 5 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	timeLabel = new wxStaticText( this, wxID_ANY, wxT("0.00"), wxDefaultPosition, wxDefaultSize, 0 );
	timeLabel->Wrap( -1 );
	gbSizer4->Add( timeLabel, wxGBPosition( 1, 40 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	amplitudeLabel = new wxStaticText( this, wxID_ANY, wxT("0.00"), wxDefaultPosition, wxDefaultSize, 0 );
	amplitudeLabel->Wrap( -1 );
	gbSizer4->Add( amplitudeLabel, wxGBPosition( 1, 45 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	msText = new wxStaticText( this, wxID_ANY, wxT("ms:"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	msText->Wrap( -1 );
	gbSizer4->Add( msText, wxGBPosition( 1, 37 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	mvText = new wxStaticText( this, wxID_ANY, wxT("mv:"), wxDefaultPosition, wxDefaultSize, 0 );
	mvText->Wrap( -1 );
	gbSizer4->Add( mvText, wxGBPosition( 1, 44 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	state_button = new wxButton( this, wxID_ANY, wxT("Off"), wxDefaultPosition, wxSize( 45,23 ), 0 );
	gbSizer4->Add( state_button, wxGBPosition( 1, 53 ), wxGBSpan( 1, 1 ), wxRIGHT, 5 );
	
	
	bSizer1->Add( gbSizer4, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( BuiltFrame::Close ) );
	VerticalSize->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::VerticalSizeChanged ), NULL, this );
	timeBase->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::TimeBaseChanged ), NULL, this );
	Treshold->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BuiltFrame::TresholdChanged ), NULL, this );
	voltSelection->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::OnVoltsChanged ), NULL, this );
	secondSelection->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::OnSecondsChanged ), NULL, this );
	PositionValue->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BuiltFrame::OnPositionChanged ), NULL, this );
	SpectrumButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BuiltFrame::OnSpecterClick ), NULL, this );
	m_panel1->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( BuiltFrame::PanelLeave ), NULL, this );
	m_panel1->Connect( wxEVT_MOTION, wxMouseEventHandler( BuiltFrame::VerifyValues ), NULL, this );
	m_panel1->Connect( wxEVT_PAINT, wxPaintEventHandler( BuiltFrame::OnPanelPaint ), NULL, this );
	m_panel1->Connect( wxEVT_SIZE, wxSizeEventHandler( BuiltFrame::OnPanelResized ), NULL, this );
	antiAliseCheckBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( BuiltFrame::OnAntiAliase ), NULL, this );
	state_button->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( BuiltFrame::OnStateChanged ), NULL, this );
}

BuiltFrame::~BuiltFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( BuiltFrame::Close ) );
	VerticalSize->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::VerticalSizeChanged ), NULL, this );
	timeBase->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::TimeBaseChanged ), NULL, this );
	Treshold->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BuiltFrame::TresholdChanged ), NULL, this );
	voltSelection->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::OnVoltsChanged ), NULL, this );
	secondSelection->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::OnSecondsChanged ), NULL, this );
	PositionValue->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BuiltFrame::OnPositionChanged ), NULL, this );
	SpectrumButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BuiltFrame::OnSpecterClick ), NULL, this );
	m_panel1->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( BuiltFrame::PanelLeave ), NULL, this );
	m_panel1->Disconnect( wxEVT_MOTION, wxMouseEventHandler( BuiltFrame::VerifyValues ), NULL, this );
	m_panel1->Disconnect( wxEVT_PAINT, wxPaintEventHandler( BuiltFrame::OnPanelPaint ), NULL, this );
	m_panel1->Disconnect( wxEVT_SIZE, wxSizeEventHandler( BuiltFrame::OnPanelResized ), NULL, this );
	antiAliseCheckBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( BuiltFrame::OnAntiAliase ), NULL, this );
	state_button->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( BuiltFrame::OnStateChanged ), NULL, this );
	
}
