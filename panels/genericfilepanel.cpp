#include "genericfilepanel.h"

/**
 *aboutPanel::aboutPanel(wxWindow* parent)
 *  : wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _("AboutPanel"))
 *{
 *
 * logoText = new wxStaticText(this, -1, _("Bijutsukan"));
 * aboutText = new wxStaticText(this, -1, _("Bijutsukan lets you categorize, describe, and find your pictures"));
 * descText = new wxStaticText(this, -1, _("Gallery Categorizer"));
 * contactText = new wxStaticText(this, -1, _("Contact via web: http://developer.berlios.de/projects/bijutsukan/\nContact via E-Mail: bijutsukan@kanojo.de"));
 *
 *logoText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
 *
 *mainSizer = new wxBoxSizer(wxVERTICAL);
 *
 *mainSizer->Add(logoText, 3, wxALIGN_CENTER, 0);
 *mainSizer->Add(descText, 2, wxALIGN_CENTER, 0);
 *mainSizer->Add(aboutText, 2, wxALIGN_CENTER, 0);
 *mainSizer->Add(contactText, 1, wxALIGN_CENTER, 0);
 *
 *SetSizer(mainSizer);
 *mainSizer->SetSizeHints(this);
 *}
**/

using namespace std;

BEGIN_EVENT_TABLE(genericFilePanel, wxPanel)
EVT_BUTTON(ID_categoryAdd, genericFilePanel::eventHandler)
EVT_BUTTON(ID_labelAdd, genericFilePanel::eventHandler)
EVT_BUTTON(ID_personAdd, genericFilePanel::eventHandler)
EVT_BUTTON(ID_objectAdd, genericFilePanel::eventHandler)
EVT_BUTTON(ID_locationAdd, genericFilePanel::eventHandler)
EVT_BUTTON(ID_positionAdd, genericFilePanel::eventHandler)
EVT_BUTTON(ID_labelSelect, genericFilePanel::eventHandler)
EVT_BUTTON(ID_personSelect, genericFilePanel::eventHandler)
EVT_BUTTON(ID_objectSelect, genericFilePanel::eventHandler)
EVT_BUTTON(ID_locationSelect, genericFilePanel::eventHandler)
EVT_BUTTON(ID_positionSelect, genericFilePanel::eventHandler)
END_EVENT_TABLE()

genericFilePanel::genericFilePanel(wxWindow* parent)
  : wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _("genericFilePanel"))
{
  initSizers();
}

void genericFilePanel::initSizers()
{
  mainVSizer = new wxBoxSizer(wxVERTICAL);
  mainHSizerL = new wxBoxSizer(wxHORIZONTAL);
  mainHSizerR = new wxBoxSizer(wxHORIZONTAL);

  categoryHSizerL = new wxBoxSizer(wxHORIZONTAL);
  categoryHSizerR = new wxBoxSizer(wxHORIZONTAL);

  labelHSizerL = new wxBoxSizer(wxHORIZONTAL);
  labelHSizerR = new wxBoxSizer(wxHORIZONTAL);

  objectHSizerL = new wxBoxSizer(wxHORIZONTAL);
  objectHSizerR = new wxBoxSizer(wxHORIZONTAL);

  locationHSizerL = new wxBoxSizer(wxHORIZONTAL);
  locationHSizerR = new wxBoxSizer(wxHORIZONTAL);

  personHSizerL = new wxBoxSizer(wxHORIZONTAL);
  personHSizerR = new wxBoxSizer(wxHORIZONTAL);
  
  positionHSizerR = new wxBoxSizer(wxHORIZONTAL);
  positionHSizerL = new wxBoxSizer(wxHORIZONTAL);

  descriptionBox = new wxStaticBoxSizer(wxVERTICAL, this, _("Description"));
  categoryBox = new wxStaticBoxSizer(wxVERTICAL, this, _("Category"));
  labelBox = new wxStaticBoxSizer(wxVERTICAL, this, _("Label"));
  objectBox = new wxStaticBoxSizer(wxVERTICAL, this, _("Objects"));
  personBox = new wxStaticBoxSizer(wxVERTICAL, this, _("Persons"));
  locationBox = new wxStaticBoxSizer(wxVERTICAL, this, _("Locations"));
  positionBox = new wxStaticBoxSizer(wxVERTICAL, this, _("Positions"));
  

}


void genericFilePanel::eventHandler(wxCommandEvent &event)
{

}
