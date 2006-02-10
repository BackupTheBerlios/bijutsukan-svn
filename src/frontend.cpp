#include "frontend.h"
#include <iostream>

using namespace std;

BEGIN_EVENT_TABLE(mainFrame, wxFrame)
EVT_MENU(ID_fileAbout, mainFrame::eventHandler )
EVT_MENU(ID_fileExit, mainFrame::eventHandler )
EVT_MENU(ID_findFileList, mainFrame::eventHandler )
EVT_MENU(ID_findLabelList, mainFrame::eventHandler )
EVT_MENU(ID_findPersonList, mainFrame::eventHandler )
EVT_MENU(ID_findPositionList, mainFrame::eventHandler )
EVT_MENU(ID_findBy, mainFrame::eventHandler )
EVT_MENU(ID_findByFileName, mainFrame::eventHandler )
EVT_MENU(ID_findByName, mainFrame::eventHandler )
EVT_MENU(ID_findByLabel, mainFrame::eventHandler )
EVT_MENU(ID_findByCategory, mainFrame::eventHandler )
EVT_MENU(ID_findByPersons, mainFrame::eventHandler )
EVT_MENU(ID_findByObjects, mainFrame::eventHandler )
EVT_MENU(ID_findByLocations, mainFrame::eventHandler )
EVT_MENU(ID_findByPositions, mainFrame::eventHandler )
EVT_MENU(ID_findByDescription, mainFrame::eventHandler )
EVT_MENU(ID_findByComments, mainFrame::eventHandler )
EVT_MENU(ID_optionsEmpty, mainFrame::eventHandler )
EVT_MENU(ID_categoryEmpty, mainFrame::eventHandler )
EVT_MENU(ID_inputInputPath, mainFrame::eventHandler )
EVT_MENU(ID_inputDirectory, mainFrame::eventHandler )
EVT_MENU(ID_inputURL, mainFrame::eventHandler )
EVT_MENU(ID_inputULRMirror, mainFrame::eventHandler )
EVT_MENU(ID_inputWizard, mainFrame::eventHandler )
END_EVENT_TABLE()



mainFrame::mainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
  :wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
  currentEvent=0;
  dbIsOpen=false;
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

  fileMenu->AppendSeparator();
  fileMenu->Append(ID_fileAbout, _("About"));
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

  inputMenu->Append(ID_inputWizard, _("Input Wizard"));
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

void mainFrame::eventHandler(wxCommandEvent &event)
{

  int eventId = event.GetId();
  
  deletePanel();

  switch (eventId)
    {

    case ID_fileExit:
      Close(true);

    case ID_fileAbout:
      {
	currentEvent = ID_fileAbout;
	myAboutPanel = new aboutPanel(this);
	myAboutPanel->Show(true);
	break;
      }
    }
}

void mainFrame::deletePanel()
{
  if(currentEvent!=0)
    {
      switch(currentEvent)
	{
	  case ID_fileAbout:
	    {
	      myAboutPanel->Show(false);
	      myAboutPanel->Destroy();
	      break;
	    }
	}
    }
  currentEvent = 0;
}
