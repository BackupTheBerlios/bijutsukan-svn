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
  mainVSizer->SetSizeHints(this);
  SetSizer(mainVSizer);
  mainVSizer->Layout();
}

void genericFilePanel::fillSizers()
{
  descriptionBox->Add(descriptionInput, wxEXPAND, 1);

  categoryHSizerL->Add(newCategoryText, 1, wxEXPAND, 1);
  categoryButtonSizer->Add(categoryInput, 1, wxEXPAND, 1);
  categoryButtonSizer->Add(categoryAdd, 1, wxEXPAND, 1);
  categoryHSizerL->Add(categoryButtonSizer, 1, wxEXPAND, 1);
  categoryHSizerL->Add(selectedText, 1, wxEXPAND, 1);
  categoryHSizerR->Add(oldCategoryText, 1, wxEXPAND, 1);
  categoryHSizerR->Add(categoryOldList, 1, wxEXPAND, 1);

  labelHSizerL->Add(newLabelText, 1, wxEXPAND, 1);
  labelButtonSizer->Add(labelInput, 1, wxEXPAND, 1);
  labelButtonSizer->Add(labelAdd, 1, wxEXPAND, 1);
  labelHSizerL->Add(labelButtonSizer, 1, wxEXPAND, 1);
  labelHSizerL->Add(selectedText, 1, wxEXPAND, 1);
  labelHSizerL->Add(labelSelected, 1, wxEXPAND, 1);
  labelHSizerR->Add(oldLabelText, 1, wxEXPAND, 1);
  labelHSizerR->Add(labelOldList, 1, wxEXPAND, 1);
  labelHSizerR->Add(labelSelect, 1, wxEXPAND, 1);

  personHSizerL->Add(newPersonText, 1, wxEXPAND, 1);
  personButtonSizer->Add(personInput, 1, wxEXPAND, 1);
  personButtonSizer->Add(personAdd, 1, wxEXPAND, 1);
  personHSizerL->Add(personButtonSizer, 1, wxEXPAND, 1);
  personHSizerL->Add(selectedText, 1, wxEXPAND, 1);
  personHSizerL->Add(personSelected, 1, wxEXPAND, 1);
  personHSizerR->Add(oldPersonText, 1, wxEXPAND, 1);
  personHSizerR->Add(personOldList, 1, wxEXPAND, 1);
  personHSizerR->Add(personSelect, 1, wxEXPAND, 1);

  objectHSizerL->Add(newObjectText, 1, wxEXPAND, 1);
  objectButtonSizer->Add(objectInput, 1, wxEXPAND, 1);
  objectButtonSizer->Add(objectAdd, 1, wxEXPAND, 1);
  objectHSizerL->Add(objectButtonSizer, 1, wxEXPAND, 1);
  objectHSizerL->Add(selectedText, 1, wxEXPAND, 1);
  objectHSizerL->Add(objectSelected, 1, wxEXPAND, 1);
  objectHSizerR->Add(oldObjectText, 1, wxEXPAND, 1);
  objectHSizerR->Add(objectOldList, 1, wxEXPAND, 1);
  objectHSizerR->Add(objectSelect, 1, wxEXPAND, 1);

  locationHSizerL->Add(newLocationText, 1, wxEXPAND, 1);
  locationButtonSizer->Add(locationInput, 1, wxEXPAND, 1);
  locationButtonSizer->Add(locationAdd, 1, wxEXPAND, 1);
  locationHSizerL->Add(locationButtonSizer, 1, wxEXPAND, 1);
  locationHSizerL->Add(selectedText, 1, wxEXPAND, 1);
  locationHSizerL->Add(locationSelected, 1, wxEXPAND, 1);
  locationHSizerR->Add(oldLocationText, 1, wxEXPAND, 1);
  locationHSizerR->Add(locationOldList, 1, wxEXPAND, 1);
  locationHSizerR->Add(locationSelect, 1, wxEXPAND, 1);

  positionHSizerL->Add(newPositionText, 1, wxEXPAND, 1);
  positionButtonSizer->Add(positionInput, 1, wxEXPAND, 1);
  positionButtonSizer->Add(positionAdd, 1, wxEXPAND, 1);
  positionHSizerL->Add(positionButtonSizer, 1, wxEXPAND, 1);
  positionHSizerL->Add(selectedText, 1, wxEXPAND, 1);
  positionHSizerL->Add(positionSelected, 1, wxEXPAND, 1);
  positionHSizerR->Add(oldPositionText, 1, wxEXPAND, 1);
  positionHSizerR->Add(positionOldList, 1, wxEXPAND, 1);
  positionHSizerR->Add(positionSelect, 1, wxEXPAND, 1);
 
}

void genericFilePanel::placeSizers()
{
  mainVSizer->Add(mainHSizerL, 1, wxEXPAND, 1);
  mainVSizer->Add(mainHSizerR, 1, wxEXPAND, 1);

  mainHSizerR->Add(descriptionBox, 1, wxEXPAND, 1);
  
  categoryBox->Add(categoryHSizerL, 1, wxEXPAND, 1);
  categoryBox->Add(categoryHSizerR, 1, wxEXPAND, 1);
  mainHSizerL->Add(categoryBox, 1, wxEXPAND, 1);
  
  labelBox->Add(labelHSizerL, 1, wxEXPAND, 1);
  labelBox->Add(labelHSizerR, 1, wxEXPAND, 1);
  mainHSizerR->Add(labelBox, 1, wxEXPAND, 1);
  
  objectBox->Add(objectHSizerL, 1, wxEXPAND, 1);
  objectBox->Add(objectHSizerR, 1, wxEXPAND, 1);
  mainHSizerL->Add(objectBox, 1, wxEXPAND, 1);
  
  personBox->Add(personHSizerL, 1, wxEXPAND, 1);
  personBox->Add(personHSizerR, 1, wxEXPAND, 1);
  mainHSizerR->Add(personBox, 1, wxEXPAND, 1);
  
  locationBox->Add(locationHSizerL, 1, wxEXPAND, 1);
  locationBox->Add(locationHSizerR, 1, wxEXPAND, 1);
  mainHSizerL->Add(locationBox, 1, wxEXPAND, 1);
  
  positionBox->Add(positionHSizerL, 1, wxEXPAND, 1);
  positionBox->Add(positionHSizerR, 1, wxEXPAND, 1);
  mainHSizerR->Add(positionBox, 1, wxEXPAND, 1);
}

void genericFilePanel::initPrimitives()
{
  //  pathText = new wxStaticText(this, -1, _(""));
  //  titleText = new wxStaticText(this, -1, _(""));

  descriptionInput = new wxTextCtrl(this, -1, _(""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
  selectedText = new wxStaticText(this, -1, _("Selected"));

  categoryInput = new wxTextCtrl(this, -1, _(""));
  categoryAdd = new wxButton(this, ID_categoryAdd, _("Add Category"));
  newCategoryText = new wxStaticText(this, -1, _("New Category"));
  categoryOldList = new wxListCtrl(this, -1);
  oldCategoryText = new wxStaticText(this, -1, _("Old Categories"));
  // categorySelectedText = new wxStaticText(this, -1, _(""));

  labelInput = new wxTextCtrl(this, -1, _(""));
  labelAdd = new wxButton(this, ID_labelAdd, _("Add Label"));
  labelSelect = new wxButton(this, ID_labelSelect, _("Select Label"));
  newLabelText = new wxStaticText(this, -1, _("New Label"));
  labelSelected = new wxListCtrl(this, -1);  
  labelOldList = new wxListCtrl(this, -1);
  oldLabelText = new wxStaticText(this, -1, _("Old Labels"));

  personInput = new wxTextCtrl(this, -1, _(""));
  personAdd = new wxButton(this, ID_personAdd, _("Add Person"));
  personSelect = new wxButton(this, ID_personSelect, _("Select Person"));
  newPersonText = new wxStaticText(this, -1, _("New Person"));
  personOldList = new wxListCtrl(this, -1);
  personSelected = new wxListCtrl(this, -1);
  oldPersonText = new wxStaticText(this, -1, _("Old Persons"));
  // personSelectedText = new wxStaticText(this, -1, _(""));

  locationInput = new wxTextCtrl(this, -1, _(""));
  locationOldList = new wxListCtrl(this, -1);
  locationSelected = new wxListCtrl(this, -1);
  locationAdd = new wxButton(this, ID_locationAdd, _("Add Location"));
  locationSelect = new wxButton(this, ID_locationSelect, _("Select Location"));
  newLocationText = new wxStaticText(this, -1, _("New Location"));
  oldLocationText = new wxStaticText(this, -1, _("Old Locations"));
  // locationSelectedText = new wxStaticText(this, -1, _(""));

  positionInput = new wxTextCtrl(this, -1, _(""));
  positionSelected = new wxListCtrl(this, -1);
  positionOldList = new wxListCtrl(this, -1);
  positionAdd = new wxButton(this, ID_positionAdd);
  positionSelect = new wxButton(this, ID_positionSelect, _("Select Position"));
  newPositionText = new wxStaticText(this, -1, _("New Position"));
  oldPositionText = new wxStaticText(this, -1, _("Old Positions"));
  // positionSelectedText = new wxStaticText(this, -1, _(""));

  objectInput = new wxTextCtrl(this, -1, _(""));
  objectSelected = new wxListCtrl(this, -1);
  objectAdd = new wxButton(this, ID_objectAdd, _("Add Object"));
  objectSelect = new wxButton(this, ID_objectSelect, _("Select Object"));
  newObjectText = new wxStaticText(this, -1, _("New Object"));
  objectOldList = new wxListCtrl(this, -1);
  oldObjectText = new wxStaticText(this, -1, _("Old Objects"));
  // objectSelectedText = new wxStaticText(this, -1, _("")); 
}

void genericFilePanel::initSizers()
{
  mainVSizer = new wxBoxSizer(wxHORIZONTAL);
  mainHSizerL = new wxBoxSizer(wxVERTICAL);
  mainHSizerR = new wxBoxSizer(wxVERTICAL);

  categoryHSizerL = new wxBoxSizer(wxVERTICAL);
  categoryHSizerR = new wxBoxSizer(wxVERTICAL);
  categoryButtonSizer = new wxBoxSizer(wxHORIZONTAL);
  categoryBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Category"));

  labelHSizerL = new wxBoxSizer(wxVERTICAL);
  labelHSizerR = new wxBoxSizer(wxVERTICAL);
  labelButtonSizer = new wxBoxSizer(wxHORIZONTAL);
  labelBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Label"));

  objectHSizerL = new wxBoxSizer(wxVERTICAL);
  objectHSizerR = new wxBoxSizer(wxVERTICAL);
  objectButtonSizer = new wxBoxSizer(wxHORIZONTAL);
  objectBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Objects"));

  locationHSizerL = new wxBoxSizer(wxVERTICAL);
  locationHSizerR = new wxBoxSizer(wxVERTICAL);
  locationButtonSizer = new wxBoxSizer(wxHORIZONTAL);
  locationBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Locations"));

  personHSizerL = new wxBoxSizer(wxVERTICAL);
  personHSizerR = new wxBoxSizer(wxVERTICAL);
  personButtonSizer = new wxBoxSizer(wxHORIZONTAL);
  personBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Persons"));

  positionHSizerR = new wxBoxSizer(wxVERTICAL);
  positionHSizerL = new wxBoxSizer(wxVERTICAL);
  positionButtonSizer = new wxBoxSizer(wxHORIZONTAL);
  positionBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Positions"));

  descriptionBox = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Description")); 
}


void genericFilePanel::eventHandler(wxCommandEvent &event)
{

}
