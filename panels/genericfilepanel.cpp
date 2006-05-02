#include "genericfilepanel.h"

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
  placeSizers();
  fillSizers();
  SetSizer(mainVSizer);
  mainVSizer->Layout();
  mainVSizer->SetSizeHints(this);
}

void genericFilePanel::fillSizers()
{
  descriptionBox->Add(descriptionInput, wxEXPAND, 1);

  categoryHSizerL->Add(newCategoryText, wxEXPAND, 1);
  categoryButtonSizer->Add(categoryInput, wxEXPAND, 1);
  categoryButtonSizer->Add(categoryAdd, wxEXPAND, 1);
  categoryHSizerL->Add(categoryButtonSizer, wxEXPAND, 1);
  categoryHSizerL->Add(selectedText, wxEXPAND, 1);
  categoryHSizerR->Add(oldCategoryText, wxEXPAND, 1);
  categoryHSizerR->Add(categoryOldList, wxEXPAND, 1);

  labelHSizerL->Add(newLabelText, wxEXPAND, 1);
  labelButtonSizer->Add(labelInput, wxEXPAND, 1);
  labelButtonSizer->Add(labelAdd, wxEXPAND, 1);
  labelHSizerL->Add(labelButtonSizer, wxEXPAND, 1);
  labelHSizerL->Add(selectedText, wxEXPAND, 1);
  labelHSizerL->Add(labelSelected, wxEXPAND, 1);
  labelHSizerR->Add(oldLabelText, wxEXPAND, 1);
  labelHSizerR->Add(labelOldList, wxEXPAND, 1);
  labelHSizerR->Add(labelSelect, wxEXPAND, 1);

  personHSizerL->Add(newPersonText, wxEXPAND, 1);
  personButtonSizer->Add(personInput, wxEXPAND, 1);
  personButtonSizer->Add(personAdd, wxEXPAND, 1);
  personHSizerL->Add(personButtonSizer, wxEXPAND, 1);
  personHSizerL->Add(selectedText, wxEXPAND, 1);
  personHSizerL->Add(personSelected, wxEXPAND, 1);
  personHSizerR->Add(oldPersonText, wxEXPAND, 1);
  personHSizerR->Add(personOldList, wxEXPAND, 1);
  personHSizerR->Add(personSelect, wxEXPAND, 1);

  objectHSizerL->Add(newObjectText, wxEXPAND, 1);
  objectButtonSizer->Add(objectInput, wxEXPAND, 1);
  objectButtonSizer->Add(objectAdd, wxEXPAND, 1);
  objectHSizerL->Add(objectButtonSizer, wxEXPAND, 1);
  objectHSizerL->Add(selectedText, wxEXPAND, 1);
  objectHSizerL->Add(objectSelected, wxEXPAND, 1);
  objectHSizerR->Add(oldObjectText, wxEXPAND, 1);
  objectHSizerR->Add(objectOldList, wxEXPAND, 1);
  objectHSizerR->Add(objectSelect, wxEXPAND, 1);

  locationHSizerL->Add(newLocationText, wxEXPAND, 1);
  locationButtonSizer->Add(locationInput, wxEXPAND, 1);
  locationButtonSizer->Add(locationAdd, wxEXPAND, 1);
  locationHSizerL->Add(locationButtonSizer, wxEXPAND, 1);
  locationHSizerL->Add(selectedText, wxEXPAND, 1);
  locationHSizerL->Add(locationSelected, wxEXPAND, 1);
  locationHSizerR->Add(oldLocationText, wxEXPAND, 1);
  locationHSizerR->Add(locationOldList, wxEXPAND, 1);
  locationHSizerR->Add(locationSelect, wxEXPAND, 1);

  positionHSizerL->Add(newPositionText, wxEXPAND, 1);
  positionButtonSizer->Add(positionInput, wxEXPAND, 1);
  positionButtonSizer->Add(positionAdd, wxEXPAND, 1);
  positionHSizerL->Add(positionButtonSizer, wxEXPAND, 1);
  positionHSizerL->Add(selectedText, wxEXPAND, 1);
  positionHSizerL->Add(positionSelected, wxEXPAND, 1);
  positionHSizerR->Add(oldPositionText, wxEXPAND, 1);
  positionHSizerR->Add(positionOldList, wxEXPAND, 1);
  positionHSizerR->Add(positionSelect, wxEXPAND, 1);

  
}

void genericFilePanel::placeSizers()
{
  mainVSizer->Add(mainHSizerL, wxEXPAND, 1);
  mainVSizer->Add(mainHSizerR, wxEXPAND, 1);
  
  mainHSizerR->Add(descriptionBox, wxEXPAND, 1);
  mainHSizerR->Add(labelBox, wxEXPAND, 1);
  mainHSizerR->Add(personBox, wxEXPAND, 1);
  mainHSizerR->Add(positionBox, wxEXPAND, 1);
  
  mainHSizerL->Add(categoryBox, wxEXPAND, 1);
  mainHSizerL->Add(objectBox, wxEXPAND, 1);
  mainHSizerL->Add(locationBox, wxEXPAND, 1);
  
  categoryBox->Add(categoryHSizerL, wxEXPAND, 1);
  categoryBox->Add(categoryHSizerR, wxEXPAND, 1);
  
  labelBox->Add(labelHSizerL, wxEXPAND, 1);
  labelBox->Add(labelHSizerR, wxEXPAND, 1);
  
  objectBox->Add(objectHSizerL, wxEXPAND, 1);
  objectBox->Add(objectHSizerR, wxEXPAND, 1);

  personBox->Add(personHSizerL, wxEXPAND, 1);
  personBox->Add(personHSizerR, wxEXPAND, 1);
  
  locationBox->Add(locationHSizerL, wxEXPAND, 1);
  locationBox->Add(locationHSizerR, wxEXPAND, 1);

  positionBox->Add(positionHSizerL, wxEXPAND, 1);
  positionBox->Add(positionHSizerR, wxEXPAND, 1);

}

void genericFilePanel::initPrimitives()
{
  //  pathText = new wxStaticText(this, -1, _(""));
  //  titleText = new wxStaticText(this, -1, _(""));
  
  descriptionInput = new wxTextCtrl(this, -1, _(""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
  categoryInput = new wxTextCtrl(this, -1, _(""));
  labelInput = new wxTextCtrl(this, -1, _(""));
  personInput = new wxTextCtrl(this, -1, _(""));
  locationInput = new wxTextCtrl(this, -1, _(""));
  positionInput = new wxTextCtrl(this, -1, _(""));
  objectInput = new wxTextCtrl(this, -1, _(""));

  labelSelected = new wxListCtrl(this, -1);
  personSelected = new wxListCtrl(this, -1);
  objectSelected = new wxListCtrl(this, -1);
  locationSelected = new wxListCtrl(this, -1);
  positionSelected = new wxListCtrl(this, -1);
  categoryOldList = new wxListCtrl(this, -1);
  labelOldList = new wxListCtrl(this, -1);
  personOldList = new wxListCtrl(this, -1);
  objectOldList = new wxListCtrl(this, -1);
  locationOldList = new wxListCtrl(this, -1);
  positionOldList = new wxListCtrl(this, -1);

  categoryAdd = new wxButton(this, ID_categoryAdd, _("Add Category"));
  labelAdd = new wxButton(this, ID_labelAdd, _("Add Label"));
  personAdd = new wxButton(this, ID_personAdd, _("Add Person"));
  objectAdd = new wxButton(this, ID_objectAdd, _("Add Object"));
  locationAdd = new wxButton(this, ID_locationAdd, _("Add Location"));
  positionAdd = new wxButton(this, ID_positionAdd);

  labelSelect = new wxButton(this, ID_labelSelect, _("Select Label"));
  personSelect = new wxButton(this, ID_personSelect, _("Select Person"));
  objectSelect = new wxButton(this, ID_objectSelect, _("Select Object"));
  locationSelect = new wxButton(this, ID_locationSelect, _("Select Location"));
  positionSelect = new wxButton(this, ID_positionSelect, _("Select Position"));

  newCategoryText = new wxStaticText(this, -1, _("New Category"));
  newLabelText = new wxStaticText(this, -1, _("New Label"));
  newPersonText = new wxStaticText(this, -1, _("New Person"));
  newLocationText = new wxStaticText(this, -1, _("New Location"));
  newPositionText = new wxStaticText(this, -1, _("New Position"));
  newObjectText = new wxStaticText(this, -1, _("New Object"));
  selectedText = new wxStaticText(this, -1, _("Selected"));
  oldCategoryText = new wxStaticText(this, -1, _("Old Categories"));
  oldLabelText = new wxStaticText(this, -1, _("Old Labels"));
  oldPersonText = new wxStaticText(this, -1, _("Old Persons"));
  oldLocationText = new wxStaticText(this, -1, _("Old Locations"));
  oldPositionText = new wxStaticText(this, -1, _("Old Positions"));
  oldObjectText = new wxStaticText(this, -1, _("Old Objects"));
  // categorySelectedText = new wxStaticText(this, -1, _(""));
  // personSelectedText = new wxStaticText(this, -1, _(""));
  // objectSelectedText = new wxStaticText(this, -1, _(""));
  // locationSelectedText = new wxStaticText(this, -1, _(""));
  // positionSelectedText = new wxStaticText(this, -1, _(""));

}

void genericFilePanel::initSizers()
{
  mainVSizer = new wxBoxSizer(wxHORIZONTAL);
  mainHSizerL = new wxBoxSizer(wxVERTICAL);
  mainHSizerR = new wxBoxSizer(wxVERTICAL);

  categoryHSizerL = new wxBoxSizer(wxVERTICAL);
  categoryHSizerR = new wxBoxSizer(wxVERTICAL);

  labelHSizerL = new wxBoxSizer(wxVERTICAL);
  labelHSizerR = new wxBoxSizer(wxVERTICAL);

  objectHSizerL = new wxBoxSizer(wxVERTICAL);
  objectHSizerR = new wxBoxSizer(wxVERTICAL);

  locationHSizerL = new wxBoxSizer(wxVERTICAL);
  locationHSizerR = new wxBoxSizer(wxVERTICAL);

  personHSizerL = new wxBoxSizer(wxVERTICAL);
  personHSizerR = new wxBoxSizer(wxVERTICAL);
  
  positionHSizerR = new wxBoxSizer(wxVERTICAL);
  positionHSizerL = new wxBoxSizer(wxVERTICAL);

  labelButtonSizer = new wxBoxSizer(wxHORIZONTAL);
  personButtonSizer = new wxBoxSizer(wxHORIZONTAL);
  objectButtonSizer = new wxBoxSizer(wxHORIZONTAL);
  locationButtonSizer = new wxBoxSizer(wxHORIZONTAL);
  positionButtonSizer = new wxBoxSizer(wxHORIZONTAL);
  categoryButtonSizer = new wxBoxSizer(wxHORIZONTAL);

  descriptionBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Description"));
  categoryBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Category"));
  labelBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));
  objectBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Objects"));
  personBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Persons"));
  locationBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Locations"));
  positionBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Positions"));
  

}


void genericFilePanel::eventHandler(wxCommandEvent &event)
{

}
