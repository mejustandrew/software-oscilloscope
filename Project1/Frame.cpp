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
	m_panel1->SetMinSize( wxSize( 600,400 ) );
	m_panel1->SetMaxSize( wxSize( 1350,800 ) );
	
	bSizer1->Add( m_panel1, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GeneratedFrame::OnExit ) );
	m_panel1->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GeneratedFrame::OnClick ), NULL, this );
	m_panel1->Connect( wxEVT_PAINT, wxPaintEventHandler( GeneratedFrame::OnPaint ), NULL, this );
	m_panel1->Connect( wxEVT_SIZE, wxSizeEventHandler( GeneratedFrame::OnResize ), NULL, this );
}

GeneratedFrame::~GeneratedFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GeneratedFrame::OnExit ) );
	m_panel1->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( GeneratedFrame::OnClick ), NULL, this );
	m_panel1->Disconnect( wxEVT_PAINT, wxPaintEventHandler( GeneratedFrame::OnPaint ), NULL, this );
	m_panel1->Disconnect( wxEVT_SIZE, wxSizeEventHandler( GeneratedFrame::OnResize ), NULL, this );
	
}
