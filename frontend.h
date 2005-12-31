#ifndef FRONTEND_H
#define FRONTEND_H 1

#include "wx/wx.h"

class mainFrame: public wxFrame
{
public:
  mainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
  void onQuit(wxCommandEvent& event);

private:
  void makeMenu();
  
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
    ID_fileOpenDB = 0,
    ID_fileExit,
    ID_findFileList,
    ID_findLabelList,
    ID_findPersonList,
    ID_findPositionList,
    ID_findByFileName,
    ID_findByName,
    ID_findByLabel,
    ID_findByCategory,
    ID_findByPersons,
    ID_findByyObjects,
    ID_findByLocations,
    ID_findByPositions,
    ID_findByDescription,
    ID_findByComments,
    ID_,
    ID_,
    ID_,
    ID_,
    ID_,
    ID_,
    ID_,
  };


#endif
