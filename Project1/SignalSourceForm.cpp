///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SignalSourceForm.h"

///////////////////////////////////////////////////////////////////////////

SignalSourceForm::SignalSourceForm( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxGridBagSizer* gbSizer6;
	gbSizer6 = new wxGridBagSizer( 0, 0 );
	gbSizer6->SetFlexibleDirection( wxBOTH );
	gbSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxGridBagSizer* gbSizer4;
	gbSizer4 = new wxGridBagSizer( 0, 0 );
	gbSizer4->SetFlexibleDirection( wxBOTH );
	gbSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString signalChoiceRadioBoxChoices[] = { wxT("Audio"), wxT("Custom") };
	int signalChoiceRadioBoxNChoices = sizeof( signalChoiceRadioBoxChoices ) / sizeof( wxString );
	signalChoiceRadioBox = new wxRadioBox( this, wxID_ANY, wxT("Signal Choice"), wxDefaultPosition, wxDefaultSize, signalChoiceRadioBoxNChoices, signalChoiceRadioBoxChoices, 1, wxRA_SPECIFY_COLS );
	signalChoiceRadioBox->SetSelection( 0 );
	gbSizer4->Add( signalChoiceRadioBox, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer6->Add( gbSizer4, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* gbSizer2;
	gbSizer2 = new wxGridBagSizer( 0, 0 );
	gbSizer2->SetFlexibleDirection( wxBOTH );
	gbSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	okayButton = new wxButton( this, wxID_ANY, wxT("Okay"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( okayButton, wxGBPosition( 1, 3 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	cancelButton = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( cancelButton, wxGBPosition( 1, 4 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer6->Add( gbSizer2, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxGridBagSizer* gbSizer3;
	gbSizer3 = new wxGridBagSizer( 0, 0 );
	gbSizer3->SetFlexibleDirection( wxBOTH );
	gbSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	frequencyLabel = new wxStaticText( this, wxID_ANY, wxT("Frequncy"), wxDefaultPosition, wxDefaultSize, 0 );
	frequencyLabel->Wrap( -1 );
	gbSizer3->Add( frequencyLabel, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	amplitudeLabel = new wxStaticText( this, wxID_ANY, wxT("Amplitude"), wxDefaultPosition, wxDefaultSize, 0 );
	amplitudeLabel->Wrap( -1 );
	gbSizer3->Add( amplitudeLabel, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxArrayString secondSignalOptionChoiceChoices;
	secondSignalOptionChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, secondSignalOptionChoiceChoices, 0 );
	secondSignalOptionChoice->SetSelection( 0 );
	secondSignalOptionChoice->SetMinSize( wxSize( 110,-1 ) );
	
	gbSizer3->Add( secondSignalOptionChoice, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxArrayString firstSignalOptionChoiceChoices;
	firstSignalOptionChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, firstSignalOptionChoiceChoices, 0 );
	firstSignalOptionChoice->SetSelection( 0 );
	firstSignalOptionChoice->SetMinSize( wxSize( 110,-1 ) );
	
	gbSizer3->Add( firstSignalOptionChoice, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	signalTypeText = new wxStaticText( this, wxID_ANY, wxT("Signal Type"), wxDefaultPosition, wxDefaultSize, 0 );
	signalTypeText->Wrap( -1 );
	gbSizer3->Add( signalTypeText, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxString signalTypeChoiceChoices[] = { wxT("Sinusoidal"), wxT("Gaussian Noise"), wxT("PWM") };
	int signalTypeChoiceNChoices = sizeof( signalTypeChoiceChoices ) / sizeof( wxString );
	signalTypeChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, signalTypeChoiceNChoices, signalTypeChoiceChoices, 0 );
	signalTypeChoice->SetSelection( 0 );
	signalTypeChoice->SetMinSize( wxSize( 110,-1 ) );
	
	gbSizer3->Add( signalTypeChoice, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	
	gbSizer6->Add( gbSizer3, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	this->SetSizer( gbSizer6 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( SignalSourceForm::OnActivateDialog ) );
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( SignalSourceForm::OnClose ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( SignalSourceForm::OnInitializeDialog ) );
	signalChoiceRadioBox->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SignalSourceForm::OnRadioBoxButtonClicked ), NULL, this );
	okayButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SignalSourceForm::OnOkayClick ), NULL, this );
	cancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SignalSourceForm::OnCancelClick ), NULL, this );
	secondSignalOptionChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SignalSourceForm::OnSecondSignalOptionChoice ), NULL, this );
	firstSignalOptionChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SignalSourceForm::OnFirstSignalOptionChoice ), NULL, this );
	signalTypeChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SignalSourceForm::OnSignalTypeChoice ), NULL, this );
}

SignalSourceForm::~SignalSourceForm()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( SignalSourceForm::OnActivateDialog ) );
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( SignalSourceForm::OnClose ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( SignalSourceForm::OnInitializeDialog ) );
	signalChoiceRadioBox->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SignalSourceForm::OnRadioBoxButtonClicked ), NULL, this );
	okayButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SignalSourceForm::OnOkayClick ), NULL, this );
	cancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SignalSourceForm::OnCancelClick ), NULL, this );
	secondSignalOptionChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SignalSourceForm::OnSecondSignalOptionChoice ), NULL, this );
	firstSignalOptionChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SignalSourceForm::OnFirstSignalOptionChoice ), NULL, this );
	signalTypeChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SignalSourceForm::OnSignalTypeChoice ), NULL, this );
	
}
