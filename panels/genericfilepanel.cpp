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
  mainVSizer->SetSizeHints(this);
}

void genericFilePanel::fillSizers()
{
  descriptionBox->Add(descriptionInput);

  categoryHSizerL->Add(newCategoryText, 1, wxALIGN_CENTER, 0);
  categoryButtonSizer->Add(categoryInput, 1, wxALIGN_CENTER, 0);
  categoryButtonSizer->Add(categoryAdd, 1, wxALIGN_CENTER, 0);
  categoryHSizerL->Add(categoryButtonSizer, 1, wxALIGN_CENTER, 0);
  categoryHSizerL->Add(selectedText, 1, wxALIGN_CENTER, 0);
  categoryHSizerR->Add(oldCategoryText, 1, wxALIGN_CENTER, 0);
  categoryHSizerR->Add(categoryOldList, 1, wxALIGN_CENTER, 0);

  labelHSizerL->Add(newLabelText, 1, wxALIGN_CENTER, 0);
  labelButtonSizer->Add(labelInput, 1, wxALIGN_CENTER, 0);
  labelButtonSizer->Add(labelAdd, 1, wxALIGN_CENTER, 0);
  labelHSizerL->Add(labelButtonSizer, 1, wxALIGN_CENTER, 0);
  labelHSizerL->Add(selectedText, 1, wxALIGN_CENTER, 0);
  labelHSizerR->Add(labelSelected, 1, wxALIGN_CENTER, 0);
  labelHSizerR->Add(labelOldList, 1, wxALIGN_CENTER, 0);

  personHSizerL->Add(newPersonText, 1, wxALIGN_CENTER, 0);
  personButtonSizer->Add(personInput, 1, wxALIGN_CENTER, 0);
  personButtonSizer->Add(personAdd, 1, wxALIGN_CENTER, 0);
  personHSizerL->Add(personButtonSizer, 1, wxALIGN_CENTER, 0);
  personHSizerL->Add(selectedText, 1, wxALIGN_CENTER, 0);
  personHSizerR->Add(personSelected, 1, wxALIGN_CENTER, 0);
  personHSizerR->Add(personOldList, 1, wxALIGN_CENTER, 0);

  objectHSizerL->Add(newObjectText, 1, wxALIGN_CENTER, 0);
  objectButtonSizer->Add(objectInput, 1, wxALIGN_CENTER, 0);
  objectButtonSizer->Add(objectAdd, 1, wxALIGN_CENTER, 0);
  objectHSizerL->Add(objectButtonSizer, 1, wxALIGN_CENTER, 0);
  objectHSizerL->Add(selectedText, 1, wxALIGN_CENTER, 0);
  objectHSizerR->Add(objectSelected, 1, wxALIGN_CENTER, 0);
  objectHSizerR->Add(objectOldList, 1, wxALIGN_CENTER, 0);

  locationHSizerL->Add(newLocationText, 1, wxALIGN_CENTER, 0);
  locationButtonSizer->Add(locationInput, 1, wxALIGN_CENTER, 0);
  locationButtonSizer->Add(locationAdd, 1, wxALIGN_CENTER, 0);
  locationHSizerL->Add(locationButtonSizer, 1, wxALIGN_CENTER, 0);
  locationHSizerL->Add(selectedText, 1, wxALIGN_CENTER, 0);
  locationHSizerR->Add(locationSelected, 1, wxALIGN_CENTER, 0);
  locationHSizerR->Add(locationOldList, 1, wxALIGN_CENTER, 0);

  positionHSizerL->Add(newPositionText, 1, wxALIGN_CENTER, 0);
  positionButtonSizer->Add(positionInput, 1, wxALIGN_CENTER, 0);
  positionButtonSizer->Add(positionAdd, 1, wxALIGN_CENTER, 0);
  positionHSizerL->Add(positionButtonSizer, 1, wxALIGN_CENTER, 0);
  positionHSizerL->Add(selectedText, 1, wxALIGN_CENTER, 0);
  positionHSizerR->Add(positionSelected, 1, wxALIGN_CENTER, 0);
  positionHSizerR->Add(positionOldList, 1, wxALIGN_CENTER, 0);

  
}

void genericFilePanel::placeSizers()
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
  
  categoryBox->Add(categoryHSizerL);
  categoryBox->Add(categoryHSizerR);
  
  labelBox->Add(labelHSizerL);
  labelBox->Add(labelHSizerR);
  
  objectBox->Add(objectHSizerR);
  objectBox->Add(objectHSizerL);

  personBox->Add(personHSizerR);
  personBox->Add(personHSizerL);
  
  locationBox->Add(locationHSizerR);
  locationBox->Add(locationHSizerL);

  positionBox->Add(positionHSizerR);
  positionBox->Add(positionHSizerL);

}

void genericFilePanel::initPrimitives()
{
  //  pathText = new wxStaticText(this, -1, _(""));
  //  titleText = new wxStaticText(this, -1, _(""));
  
  descriptionInput = new wxTextCtrl(this, -1, _(""));
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
  categorySelectedText = new wxStaticText(this, -1, _(""));
  personSelectedText = new wxStaticText(this, -1, _(""));
  objectSelectedText = new wxStaticText(this, -1, _(""));
  locationSelectedText = new wxStaticText(this, -1, _(""));
  positionSelectedText = new wxStaticText(this, -1, _(""));

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

  labelButtonSizer = new wxBoxSizer(wxVERTICAL);
  personButtonSizer = new wxBoxSizer(wxVERTICAL);
  objectButtonSizer = new wxBoxSizer(wxVERTICAL);
  locationButtonSizer = new wxBoxSizer(wxVERTICAL);
  positionButtonSizer = new wxBoxSizer(wxVERTICAL);
  categoryButtonSizer = new wxBoxSizer(wxVERTICAL);

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
