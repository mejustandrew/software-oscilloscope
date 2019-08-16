#include <wx/app.h>
#include"WorkingFrame.h"
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
DECLARE_APP(MyApp)

IMPLEMENT_APP(MyApp)
bool MyApp::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;
	WorkingFrame *frame = new WorkingFrame(NULL);
	frame->Show(true);
 
    return true;
}
