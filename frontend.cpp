#include "frontend.hh"

BEGIN_EVENT_TABLE(mainFrame, wxFrame)
  EVT_MENU(ID_Quit, mainFrame::onQuit)
END_EVENT_TABLE()


mainFrame::mainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
  :wxFrame((wxFrame *)NULL, -1, title, pos, size)
{

}


void mainFrame::onQuit(wxCommandEvent& WXUNUSED(event))
{
  Close(true);
}
