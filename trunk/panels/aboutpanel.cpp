#include "aboutpanel.h"

aboutPanel::aboutPanel(wxWindow* parent)
  : wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _("AboutPanel"))
{

  logoText = new wxStaticText(this, -1, _("Bijutsukan"));
  aboutText = new wxStaticText(this, -1, _("Bijutsukan lets you categorize, describe, and find your pictures"));
  descText = new wxStaticText(this, -1, _("Gallery Categorizer"));
  contactText = new wxStaticText(this, -1, _("Contact via web: http://developer.berlios.de/projects/bijutsukan/\nContact via E-Mail: bijutsukan@kanojo.de"));

  logoText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

  mainSizer = new wxBoxSizer(wxVERTICAL);

  mainSizer->Add(logoText, 3, wxALIGN_CENTER, 0);
  mainSizer->Add(descText, 2, wxALIGN_CENTER, 0);
  mainSizer->Add(aboutText, 2, wxALIGN_CENTER, 0);
  mainSizer->Add(contactText, 1, wxALIGN_CENTER, 0);
  
  SetSizer(mainSizer);
  mainSizer->SetSizeHints(this);
};



