#include "frontend.h"
#include "main.h"

bool bijutsukan::OnInit()
{
  mainFrame *myMainFrame = new mainFrame(_("Bijutsukan-Main"), wxPoint(500,300), wxSize(200,400));
  myMainFrame->Show(true);
  SetTopWindow(myMainFrame);
  return true;
};

IMPLEMENT_APP(bijutsukan)
