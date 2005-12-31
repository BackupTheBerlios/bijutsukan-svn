#include "frontend.h"

BEGIN_EVENT_TABLE(mainFrame, wxFrame)
  EVT_MENU(ID_Quit, mainFrame::onQuit)
END_EVENT_TABLE()


mainFrame::mainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
  :wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
  makeMenu();
}

void mainFrame::makeMenu()
{
  menuBar = new wxMenuBar;
  fileMenu = new wxMenu;
  findMenu = new wxMenu;
  findBySubMenu = new wxMenu;
  inputMenu = new wxMenu;
  categoryMenu = new wxMenu;
  optionsMenu = new wxMenu;

  fileMenu->Append(ID_fileOpenDB, _("Open Database"));
  fileMenu->Append(ID_fileExit, _("Exit"));
  

  findBySubMenu->Append(0, _("Filename"));
  findBySubMenu->Append(1, _("Name"));
  findBySubMenu->Append(2, _("Label"));
  findBySubMenu->Append(3, _("Category"));
  findBySubMenu->Append(4, _("Persons"));
  findBySubMenu->Append(5, _("Objects"));
  findBySubMenu->Append(6, _("Locations"));
  findBySubMenu->Append(7, _("Positions"));
  findBySubMenu->Append(8, _("Description"));
  findBySubMenu->Append(9, _("Comments"));

  findMenu->Append(0, _("File List"));
  findMenu->Append(1, _("Label List"));
  findMenu->Append(2, _("Person List"));
  findMenu->Append(3, _("Position List"));
  findMenu->AppendSeparator();
  findMenu->Append(4, _("Find By"), findBySubMenu);
  
  menuBar->Append(fileMenu, _("File"));
  menuBar->Append(findMenu, _("Find"));
  
  SetMenuBar(menuBar);
}


void mainFrame::onQuit(wxCommandEvent& WXUNUSED(event))
{
  Close(true);
}
