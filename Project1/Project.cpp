///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
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
	
	state_button = new wxButton( this, wxID_ANY, wxT("Off"), wxDefaultPosition, wxSize( 45,23 ), 0 );
	gbSizer41->Add( state_button, wxGBPosition( 7, 5 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer1->Add( gbSizer41, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* gbSizer42;
	gbSizer42 = new wxGridBagSizer( 0, 0 );
	gbSizer42->SetFlexibleDirection( wxBOTH );
	gbSizer42->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString VerticalSizeChannel2Choices[] = { wxT("50"), wxT("100"), wxT("500") };
	int VerticalSizeChannel2NChoices = sizeof( VerticalSizeChannel2Choices ) / sizeof( wxString );
	VerticalSizeChannel2 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), VerticalSizeChannel2NChoices, VerticalSizeChannel2Choices, 0 );
	VerticalSizeChannel2->SetSelection( 0 );
	gbSizer42->Add( VerticalSizeChannel2, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString voltSelectionChannel2Choices[] = { wxT("Volts"), wxT("mV") };
	int voltSelectionChannel2NChoices = sizeof( voltSelectionChannel2Choices ) / sizeof( wxString );
	voltSelectionChannel2 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, voltSelectionChannel2NChoices, voltSelectionChannel2Choices, 0 );
	voltSelectionChannel2->SetSelection( 1 );
	gbSizer42->Add( voltSelectionChannel2, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("VerticalSize"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	gbSizer42->Add( m_staticText13, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString timeBaseChannel2Choices[] = { wxT("1"), wxT("5"), wxT("25"), wxT("125"), wxT("250") };
	int timeBaseChannel2NChoices = sizeof( timeBaseChannel2Choices ) / sizeof( wxString );
	timeBaseChannel2 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), timeBaseChannel2NChoices, timeBaseChannel2Choices, 0 );
	timeBaseChannel2->SetSelection( 0 );
	gbSizer42->Add( timeBaseChannel2, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString secondSelectionChannel2Choices[] = { wxT("Sec"), wxT("mSec") };
	int secondSelectionChannel2NChoices = sizeof( secondSelectionChannel2Choices ) / sizeof( wxString );
	secondSelectionChannel2 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, secondSelectionChannel2NChoices, secondSelectionChannel2Choices, 0 );
	secondSelectionChannel2->SetSelection( 1 );
	gbSizer42->Add( secondSelectionChannel2, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("TimeBase"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	gbSizer42->Add( m_staticText14, wxGBPosition( 3, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	TresholdChannel2 = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, -500, 500, 0 );
	gbSizer42->Add( TresholdChannel2, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("mVolts"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	gbSizer42->Add( m_staticText15, wxGBPosition( 5, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Treshold"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	gbSizer42->Add( m_staticText16, wxGBPosition( 5, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	PositionValueChannel2 = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, -10, 10, 0 );
	gbSizer42->Add( PositionValueChannel2, wxGBPosition( 7, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Position"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	gbSizer42->Add( m_staticText17, wxGBPosition( 7, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	SpectrumButton2 = new wxButton( this, wxID_ANY, wxT("Spectrum"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer42->Add( SpectrumButton2, wxGBPosition( 7, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	state_button2 = new wxButton( this, wxID_ANY, wxT("Off"), wxDefaultPosition, wxSize( 45,23 ), 0 );
	gbSizer42->Add( state_button2, wxGBPosition( 7, 5 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer1->Add( gbSizer42, wxGBPosition( 0, 15 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	bSizer1->Add( gbSizer1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxPoint( 0,0 ), wxSize( 400,450 ), wxTAB_TRAVERSAL );
	m_panel1->SetMinSize( wxSize( 400,450 ) );
	m_panel1->SetMaxSize( wxSize( 1350,450 ) );
	
	bSizer2->Add( m_panel1, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	wxGridBagSizer* gbSizer4;
	gbSizer4 = new wxGridBagSizer( 0, 0 );
	gbSizer4->SetFlexibleDirection( wxHORIZONTAL );
	gbSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxGridBagSizer* gbSizer5;
	gbSizer5 = new wxGridBagSizer( 0, 0 );
	gbSizer5->SetFlexibleDirection( wxBOTH );
	gbSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	msText1 = new wxStaticText( this, wxID_ANY, wxT("ms:"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	msText1->Wrap( -1 );
	gbSizer5->Add( msText1, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	timeLeftChannel = new wxStaticText( this, wxID_ANY, wxT("0.00"), wxDefaultPosition, wxDefaultSize, 0 );
	timeLeftChannel->Wrap( -1 );
	gbSizer5->Add( timeLeftChannel, wxGBPosition( 0, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	mvText28 = new wxStaticText( this, wxID_ANY, wxT("mv:"), wxDefaultPosition, wxDefaultSize, 0 );
	mvText28->Wrap( -1 );
	gbSizer5->Add( mvText28, wxGBPosition( 0, 4 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	amplitudeLabelLeftChannel = new wxStaticText( this, wxID_ANY, wxT("0.00"), wxDefaultPosition, wxDefaultSize, 0 );
	amplitudeLabelLeftChannel->Wrap( -1 );
	gbSizer5->Add( amplitudeLabelLeftChannel, wxGBPosition( 0, 8 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer4->Add( gbSizer5, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	timeLabel = new wxStaticText( this, wxID_ANY, wxT("0.00"), wxDefaultPosition, wxDefaultSize, 0 );
	timeLabel->Wrap( -1 );
	gbSizer4->Add( timeLabel, wxGBPosition( 0, 45 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	amplitudeLabel = new wxStaticText( this, wxID_ANY, wxT("0.00"), wxDefaultPosition, wxDefaultSize, 0 );
	amplitudeLabel->Wrap( -1 );
	gbSizer4->Add( amplitudeLabel, wxGBPosition( 0, 53 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	msText = new wxStaticText( this, wxID_ANY, wxT("ms:"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	msText->Wrap( -1 );
	gbSizer4->Add( msText, wxGBPosition( 0, 42 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	mvText = new wxStaticText( this, wxID_ANY, wxT("mv:"), wxDefaultPosition, wxDefaultSize, 0 );
	mvText->Wrap( -1 );
	gbSizer4->Add( mvText, wxGBPosition( 0, 48 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	bSizer1->Add( gbSizer4, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	m_menubar2 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* signalSourceMenuItem;
	signalSourceMenuItem = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( signalSourceMenuItem );
	
	m_menubar2->Append( m_menu1, wxT("Menu") ); 
	
	this->SetMenuBar( m_menubar2 );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( BuiltFrame::Close ) );
	VerticalSize->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::VerticalSizeChanged ), NULL, this );
	timeBase->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::TimeBaseChanged ), NULL, this );
	Treshold->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BuiltFrame::TresholdChanged ), NULL, this );
	voltSelection->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::OnVoltsChanged ), NULL, this );
	secondSelection->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::OnSecondsChanged ), NULL, this );
	PositionValue->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BuiltFrame::OnPositionChanged ), NULL, this );
	SpectrumButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BuiltFrame::OnSpectrumClick ), NULL, this );
	state_button->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( BuiltFrame::OnStateChanged ), NULL, this );
	VerticalSizeChannel2->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::VerticalSize2Changed ), NULL, this );
	voltSelectionChannel2->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::OnVolts2Changed ), NULL, this );
	timeBaseChannel2->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::TimeBase2Changed ), NULL, this );
	secondSelectionChannel2->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::OnSeconds2Changed ), NULL, this );
	TresholdChannel2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BuiltFrame::Treshold2Changed ), NULL, this );
	PositionValueChannel2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BuiltFrame::OnPosition2Changed ), NULL, this );
	SpectrumButton2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BuiltFrame::OnSpectrumClickChannel2 ), NULL, this );
	state_button2->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( BuiltFrame::OnStateChangedChannel2 ), NULL, this );
	m_panel1->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( BuiltFrame::PanelLeave ), NULL, this );
	m_panel1->Connect( wxEVT_MOTION, wxMouseEventHandler( BuiltFrame::VerifyValues ), NULL, this );
	m_panel1->Connect( wxEVT_PAINT, wxPaintEventHandler( BuiltFrame::OnPanelPaint ), NULL, this );
	m_panel1->Connect( wxEVT_SIZE, wxSizeEventHandler( BuiltFrame::OnPanelResized ), NULL, this );
	this->Connect( signalSourceMenuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BuiltFrame::OnSignalSource ) );
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
	SpectrumButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BuiltFrame::OnSpectrumClick ), NULL, this );
	state_button->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( BuiltFrame::OnStateChanged ), NULL, this );
	VerticalSizeChannel2->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::VerticalSize2Changed ), NULL, this );
	voltSelectionChannel2->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::OnVolts2Changed ), NULL, this );
	timeBaseChannel2->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::TimeBase2Changed ), NULL, this );
	secondSelectionChannel2->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BuiltFrame::OnSeconds2Changed ), NULL, this );
	TresholdChannel2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BuiltFrame::Treshold2Changed ), NULL, this );
	PositionValueChannel2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BuiltFrame::OnPosition2Changed ), NULL, this );
	SpectrumButton2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BuiltFrame::OnSpectrumClickChannel2 ), NULL, this );
	state_button2->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( BuiltFrame::OnStateChangedChannel2 ), NULL, this );
	m_panel1->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( BuiltFrame::PanelLeave ), NULL, this );
	m_panel1->Disconnect( wxEVT_MOTION, wxMouseEventHandler( BuiltFrame::VerifyValues ), NULL, this );
	m_panel1->Disconnect( wxEVT_PAINT, wxPaintEventHandler( BuiltFrame::OnPanelPaint ), NULL, this );
	m_panel1->Disconnect( wxEVT_SIZE, wxSizeEventHandler( BuiltFrame::OnPanelResized ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( BuiltFrame::OnSignalSource ) );
	
}
