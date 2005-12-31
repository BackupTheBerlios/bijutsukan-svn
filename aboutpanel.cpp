#include "aboutpanel.h"

aboutPanel::aboutPanel(wxWindow* parent)
  : wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _("AboutPanel"))
{

  logoText = new wxStaticText(this, -1, _("Bijutsukan - Gallery Categorization"));
  aboutText = new wxStaticText(this, -1, _("Bijutsukan lets you categorize, describe, and find your pictures"));
  mainSizer = new wxBoxSizer(wxVERTICAL);
  textSizer = new wxBoxSizer(wxHORIZONTAL);
  mainSizer->Add(textSizer, 1, wxEXPAND, 0);
  textSizer->Add(logoText, 1, wxEXPAND, 0);
  mainSizer->Add(aboutText, 1, wxEXPAND, 0);
  
  SetSizer(mainSizer);
  mainSizer->SetSizeHints(this);
}
