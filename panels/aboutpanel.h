#ifndef ABOUTPANEL_H
#define ABOUTPANEL_H 1

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/font.h>

class aboutPanel: public wxPanel
{

 public:
  aboutPanel(wxWindow *parent);

 private:
  wxBoxSizer *mainSizer;
  wxStaticText *logoText;
  wxStaticText *aboutText;
  wxStaticText *descText;
  wxStaticText *contactText;

};

#endif
