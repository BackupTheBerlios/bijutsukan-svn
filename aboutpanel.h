#ifndef MAINPANEL_H
#define MAINPANEL_H 1

#include <wx/wx.h>
#include <wx/panel.h>

class aboutPanel: public wxPanel
{

 public:
  aboutPanel(wxWindow *parent);


 private:
  wxBoxSizer *mainSizer;
  wxBoxSizer *textSizer;
  wxStaticText *logoText;
  wxStaticText *aboutText;

};

#endif
