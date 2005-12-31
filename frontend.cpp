#include "frontend.h"
#include <iostream>

using namespace std;

BEGIN_EVENT_TABLE(mainFrame, wxFrame)

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

  inputMenu->Append(ID_inputInputPath, _("Input New File"));
  inputMenu->Append(ID_inputDirectory, _("Input New Directory"));
  inputMenu->Append(ID_inputURL, _("Input New URL"));
  inputMenu->Append(ID_inputULRMirror, _("Input New URL Directory"));

  categoryMenu->Append(ID_categoryEmpty, _("Empty"));

  optionsMenu->Append(ID_optionsEmpty, _("Empty"));

  menuBar->Append(fileMenu, _("File"));
  menuBar->Append(findMenu, _("Find"));
  menuBar->Append(inputMenu, _("New"));
  menuBar->Append(categoryMenu, _("Manage Categories"));
  menuBar->Append(optionsMenu, _("Options"));
  
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
