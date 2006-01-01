#ifndef FRONTEND_H
#define FRONTEND_H 1

#include <wx/wx.h>
#include <wx/panel.h>

#include "panels/aboutpanel.h"
#include "panels/mainpanel.h"

class mainFrame: public wxFrame
{
public:
  mainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
  void onQuit(wxCommandEvent& event);
  void eventHandler(wxCommandEvent& event);
private:
  void makeMenu();
  void deletePanel();

  int currentEvent;
  aboutPanel *myAboutPanel;

  wxMenuBar *menuBar;
  wxMenu *fileMenu;
  wxMenu *findMenu;
  wxMenu *findBySubMenu;
  wxMenu *inputMenu;
  wxMenu *categoryMenu;
  wxMenu *optionsMenu;

  DECLARE_EVENT_TABLE();
};


enum
  {
    ID_fileOpenDB = 1,
    ID_fileAbout,
    ID_fileExit,
    ID_findFileList,
    ID_findLabelList,
    ID_findPersonList,
    ID_findPositionList,
    ID_findBy,
    ID_findByFileName,
    ID_findByName,
    ID_findByLabel,
    ID_findByCategory,
    ID_findByPersons,
    ID_findByObjects,
    ID_findByLocations,
    ID_findByPositions,
    ID_findByDescription,
    ID_findByComments,
    ID_optionsEmpty,
    ID_categoryEmpty,
    ID_inputInputPath,
    ID_inputDirectory,
    ID_inputURL,
    ID_inputULRMirror,
    ID_inputWizard
  };

#endif
