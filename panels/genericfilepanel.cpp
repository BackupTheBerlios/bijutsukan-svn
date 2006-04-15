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
  initPrimitives();
  placeElements();
}

void genericFilePanel::placeElements()
{
  mainVSizer->Add(mainHSizerL);
  mainVSizer->Add(mainHSizerR);
  
  mainHSizerR->Add(descriptionBox);
  mainHSizerR->Add(labelBox);
  mainHSizerR->Add(personBox);
  mainHSizerR->Add(positionBox);
  
  mainHSizerL->Add(categoryBox);
  mainHSizerL->Add(objectBox);
  mainHSizerL->Add(locationBox);
}

void genericFilePanel::initPrimitives()
{
  pathText = new wxStaticText(this, -1, _(""));
  titleText = new wxStaticText(this, -1, _(""));
  
  descriptionInput = new wxTextCtrl(this, -1, _(""));
  categoryInput = new wxTextCtrl(this, -1, _(""));
  labelInput = new wxTextCtrl(this, -1, _(""));
  personInput = new wxTextCtrl(this, -1, _(""));
  locationInput = new wxTextCtrl(this, -1, _(""));
  positionInput = new wxTextCtrl(this, -1, _(""));

  categoryOldList = new wxListCtrl(this, -1);
  labelOldList = new wxListCtrl(this, -1);
  personOldList = new wxListCtrl(this, -1);
  objectOldList = new wxListCtrl(this, -1);
  locationOldList = new wxListCtrl(this, -1);

  categoryAdd = new wxButton(this, ID_categoryAdd);
  labelAdd = new wxButton(this, ID_labelAdd);
  personAdd = new wxButton(this, ID_personAdd);
  objectAdd = new wxButton(this, ID_objectAdd);
  locationAdd = new wxButton(this, ID_locationAdd);
  positionAdd = new wxButton(this, ID_positionAdd);

  labelSelect = new wxButton(this, ID_labelSelect);
  personSelect = new wxButton(this, ID_personSelect);
  objectSelect = new wxButton(this, ID_objectSelect);
  locationSelect = new wxButton(this, ID_locationSelect);
  positionSelect = new wxButton(this, ID_positionSelect);

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
