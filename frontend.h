#ifndef FRONTEND_H
#define FRONTEND_H 1

#include "wx/wx.h"

class mainFrame: public wxFrame
{
public:
  mainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
  void onQuit(wxCommandEvent& event);

private:
  DECLARE_EVENT_TABLE();
};


enum
  {
    ID_Quit = 1,
  };


#endif
