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
  
  descriptionInput = new wxTextCtrl(&descriptionBox, -1, _(""));
  categoryInput = new wxTextCtrl(&categoryButtonSizer, -1, _(""));
  labelInput = new wxTextCtrl(&labelButtonSizer, -1, _(""));
  personInput = new wxTextCtrl(&personButtonSizer, -1, _(""));
  locationInput = new wxTextCtrl(&locationButtonSizer, -1, _(""));
  positionInput = new wxTextCtrl(&positionButtonSizer, -1, _(""));

  labelSelected = new wxListCtrl(&labelHSizerL, -1);
  categoryOldList = new wxListCtrl(&categoryHSizerR, -1);
  labelOldList = new wxListCtrl(&labelHSizerR, -1);
  personOldList = new wxListCtrl(&personHSizerR, -1);
  objectOldList = new wxListCtrl(&objectHSizerR, -1);
  locationOldList = new wxListCtrl(&locationHSizerR, -1);

  categoryAdd = new wxButton(&categoryButtonSizer, ID_categoryAdd);
  labelAdd = new wxButton(&labelButtonSizer, ID_labelAdd);
  personAdd = new wxButton(&personButtonSizer, ID_personAdd);
  objectAdd = new wxButton(&objectButtonSizer, ID_objectAdd);
  locationAdd = new wxButton(&locationButtonSizer, ID_locationAdd);
  positionAdd = new wxButton(&positionButtonSizer, ID_positionAdd);

  labelSelect = new wxButton(&labelHSizerR, ID_labelSelect);
  personSelect = new wxButton(&personHSizerR, ID_personSelect);
  objectSelect = new wxButton(&objectHSizerR, ID_objectSelect);
  locationSelect = new wxButton(&locationHSizerR, ID_locationSelect);
  positionSelect = new wxButton(&positionHSizerR, ID_positionSelect);

  newCategoryText = new wxStaticText(&categoryHSizerL, -1, _("New Category"));
  newLabelText = new wxStaticText(&labelHSizerL, -1, _("New Label"));
  newPersonText = new wxStaticText(&personHSizerL, -1, _("New Person"));
  newLocationText = new wxStaticText(&locationHSizerL, -1, _("New Location"));
  newPositionText = new wxStaticText(&positionHSizerL, -1, _("New Position"));
  newObjectText = new wxStaticText(&objectHSizerL, -1, _("New Object"));
  selectedText = new wxStaticText(&-1, -1, _("Selected"));
  oldCategoryText = new wxStaticText(&categoryHSizerR, -1, _("Old Categories"));
  oldLabelText = new wxStaticText(&labelHSizerR, -1, _("Old Labels"));
  oldPersonText = new wxStaticText(&personHSizerR, -1, _("Old Persons"));
  oldLocationText = new wxStaticText(&locationHSizerR, -1, _("Old Locations"));
  oldPositionText = new wxStaticText(&positionHSizerR, -1, _("Old Positions"));
  oldObjectText = new wxStaticText(&objectHSizerR, -1, _("Old Objects"));
  categorySelectedText = new wxStaticText(&categoryHSizerL, -1, _(""));
  personSelectedText = new wxStaticText(&personHSizerL, -1, _(""));
  objectSelectedText = new wxStaticText(&objectHSizerL, -1, _(""));
  locationSelectedText = new wxStaticText(&locationHSizerL, -1, _(""));
  positionSelectedText = new wxStaticText(&positionHSizerL, -1, _(""));

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
