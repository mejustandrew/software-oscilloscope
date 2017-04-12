///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SignalSourceForm.h"

///////////////////////////////////////////////////////////////////////////

MyDialog1::MyDialog1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxGridBagSizer* gbSizer6;
	gbSizer6 = new wxGridBagSizer( 0, 0 );
	gbSizer6->SetFlexibleDirection( wxBOTH );
	gbSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString signalChoiceRadioBoxChoices[] = { wxT("Audio"), wxT("Custom") };
	int signalChoiceRadioBoxNChoices = sizeof( signalChoiceRadioBoxChoices ) / sizeof( wxString );
	signalChoiceRadioBox = new wxRadioBox( this, wxID_ANY, wxT("Signal Choice"), wxDefaultPosition, wxDefaultSize, signalChoiceRadioBoxNChoices, signalChoiceRadioBoxChoices, 1, wxRA_SPECIFY_COLS );
	signalChoiceRadioBox->SetSelection( 0 );
	gbSizer6->Add( signalChoiceRadioBox, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	signalTypeLabel = new wxStaticText( this, wxID_ANY, wxT("Signal type"), wxDefaultPosition, wxDefaultSize, 0 );
	signalTypeLabel->Wrap( -1 );
	gbSizer6->Add( signalTypeLabel, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString signalTypeChoiceChoices[] = { wxT("Sinusoidal"), wxT("Noise"), wxT("DC") };
	int signalTypeChoiceNChoices = sizeof( signalTypeChoiceChoices ) / sizeof( wxString );
	signalTypeChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, signalTypeChoiceNChoices, signalTypeChoiceChoices, 0 );
	signalTypeChoice->SetSelection( 0 );
	gbSizer6->Add( signalTypeChoice, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	amplitudeLabel = new wxStaticText( this, wxID_ANY, wxT("Amplitude"), wxDefaultPosition, wxDefaultSize, 0 );
	amplitudeLabel->Wrap( -1 );
	gbSizer6->Add( amplitudeLabel, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString amplitudeChoiceChoices[] = { wxT("1"), wxT("2"), wxT("5"), wxT("10") };
	int amplitudeChoiceNChoices = sizeof( amplitudeChoiceChoices ) / sizeof( wxString );
	amplitudeChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 82,-1 ), amplitudeChoiceNChoices, amplitudeChoiceChoices, 0 );
	amplitudeChoice->SetSelection( 0 );
	gbSizer6->Add( amplitudeChoice, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString varianceChoiceChoices[] = { wxT("0.1"), wxT("0.2"), wxT("0.5"), wxT("1.0"), wxT("1") };
	int varianceChoiceNChoices = sizeof( varianceChoiceChoices ) / sizeof( wxString );
	varianceChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 82,-1 ), varianceChoiceNChoices, varianceChoiceChoices, 0 );
	varianceChoice->SetSelection( 0 );
	gbSizer6->Add( varianceChoice, wxGBPosition( 3, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString countinousValueChoiceChoices[] = { wxT("-50"), wxT("-10"), wxT("0"), wxT("10"), wxT("50") };
	int countinousValueChoiceNChoices = sizeof( countinousValueChoiceChoices ) / sizeof( wxString );
	countinousValueChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 82,-1 ), countinousValueChoiceNChoices, countinousValueChoiceChoices, 0 );
	countinousValueChoice->SetSelection( 0 );
	gbSizer6->Add( countinousValueChoice, wxGBPosition( 3, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	frequencyLabel = new wxStaticText( this, wxID_ANY, wxT("Frequncy"), wxDefaultPosition, wxDefaultSize, 0 );
	frequencyLabel->Wrap( -1 );
	gbSizer6->Add( frequencyLabel, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString frequencyChoiceChoices[] = { wxT("1"), wxT("2"), wxT("5"), wxT("10"), wxT("50") };
	int frequencyChoiceNChoices = sizeof( frequencyChoiceChoices ) / sizeof( wxString );
	frequencyChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 82,-1 ), frequencyChoiceNChoices, frequencyChoiceChoices, 0 );
	frequencyChoice->SetSelection( 0 );
	gbSizer6->Add( frequencyChoice, wxGBPosition( 4, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString meanChoiceChoices[] = { wxT("-2"), wxT("-1"), wxT("  0"), wxT("  1"), wxT("  2") };
	int meanChoiceNChoices = sizeof( meanChoiceChoices ) / sizeof( wxString );
	meanChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 82,-1 ), meanChoiceNChoices, meanChoiceChoices, 0 );
	meanChoice->SetSelection( 0 );
	gbSizer6->Add( meanChoice, wxGBPosition( 4, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	this->SetSizer( gbSizer6 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	signalChoiceRadioBox->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MyDialog1::OnRadioBoxButtonClicked ), NULL, this );
	signalTypeChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::OnSignalTypeChoice ), NULL, this );
	amplitudeChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::OnAmplitudeChoice ), NULL, this );
	varianceChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::OnVarianceChoice ), NULL, this );
	countinousValueChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::OnContinousValueChoice ), NULL, this );
	frequencyChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::OnFrequencyChoice ), NULL, this );
	meanChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::OnMeanChoice ), NULL, this );
}

MyDialog1::~MyDialog1()
{
	// Disconnect Events
	signalChoiceRadioBox->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MyDialog1::OnRadioBoxButtonClicked ), NULL, this );
	signalTypeChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::OnSignalTypeChoice ), NULL, this );
	amplitudeChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::OnAmplitudeChoice ), NULL, this );
	varianceChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::OnVarianceChoice ), NULL, this );
	countinousValueChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::OnContinousValueChoice ), NULL, this );
	frequencyChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::OnFrequencyChoice ), NULL, this );
	meanChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::OnMeanChoice ), NULL, this );
	
}
