#include "frontend.h"
#include <iostream>

using namespace std;

BEGIN_EVENT_TABLE(mainFrame, wxFrame)
     EVT_MENU( ID_fileOpenDB, mainFrame::empty )
     EVT_MENU( ID_fileExit, mainFrame::empty )
     EVT_MENU( ID_findFileList, mainFrame::empty )
     EVT_MENU( ID_findLabelList, mainFrame::empty )
     EVT_MENU( ID_findPersonList, mainFrame::empty )
     EVT_MENU( ID_findPositionList, mainFrame::empty )
     EVT_MENU( ID_findBy, mainFrame::empty )
     EVT_MENU( ID_findByFileName, mainFrame::empty )
     EVT_MENU( ID_findByName, mainFrame::empty )
     EVT_MENU( ID_findByLabel, mainFrame::empty )
     EVT_MENU( ID_findByCategory, mainFrame::empty )
     EVT_MENU( ID_findByPersons, mainFrame::empty )
     EVT_MENU( ID_findByObjects, mainFrame::empty )
     EVT_MENU( ID_findByLocations, mainFrame::empty )
     EVT_MENU( ID_findByPositions, mainFrame::empty )
     EVT_MENU( ID_findByDescription, mainFrame::empty )
     EVT_MENU( ID_findByComments, mainFrame::empty )
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
  

  findBySubMenu->Append(ID_findByFileName, _("Filename"));
  findBySubMenu->Append(ID_findByName, _("Name"));
  findBySubMenu->Append(ID_findByLabel, _("Label"));
  findBySubMenu->Append(ID_findByCategory, _("Category"));
  findBySubMenu->Append(ID_findByPersons, _("Persons"));
  findBySubMenu->Append(ID_findByObjects, _("Objects"));
  findBySubMenu->Append(ID_findByLocations, _("Locations"));
  findBySubMenu->Append(ID_findByPositions, _("Positions"));
  findBySubMenu->Append(ID_findByDescription, _("Description"));
  findBySubMenu->Append(ID_findByComments, _("Comments"));

  findMenu->Append(ID_findFileList, _("File List"));
  findMenu->Append(ID_findLabelList, _("Label List"));
  findMenu->Append(ID_findPersonList, _("Person List"));
  findMenu->Append(ID_findPositionList, _("Position List"));
  findMenu->AppendSeparator();
  findMenu->Append(ID_findBy, _("Find By"), findBySubMenu);
  
  menuBar->Append(fileMenu, _("File"));
  menuBar->Append(findMenu, _("Find"));
  
  SetMenuBar(menuBar);
}

void mainFrame::empty(wxCommandEvent &event)
{
  wxCommandEvent *myEvent = &event;
  cout<<myEvent->GetId()<<endl;
}

void mainFrame::onQuit(wxCommandEvent& WXUNUSED(event))
{
  Close(true);
}
