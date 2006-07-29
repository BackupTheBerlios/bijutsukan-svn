#ifndef GENERICFILEPANEL_H
#define GENERICFILEPANEL_H 1

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/font.h>
#include <wx/sizer.h>

class genericFilePanel: public wxPanel
{

 public:
  genericFilePanel(wxWindow *parent);
  void eventHandler(wxCommandEvent &event);


 private:

  void initSizers();
  void initPrimitives();
  void placeSizers();
  void fillSizers();

  wxBoxSizer
    *mainVSizer,
    *mainHSizerL,
    *mainHSizerR,
    
    *categoryHSizerL,
    *categoryHSizerR,
    
    *labelHSizerL,
    *labelHSizerR,

    *objectHSizerL,
    *objectHSizerR,

    *locationHSizerL,
    *locationHSizerR,
    
    *personHSizerL,
    *personHSizerR,
    
    *positionHSizerL,
    *positionHSizerR,

    *categoryButtonSizer,
    *labelButtonSizer,
    *personButtonSizer,
    *objectButtonSizer,
    *locationButtonSizer,
    *positionButtonSizer;


    
  wxStaticBoxSizer
    *descriptionBox,
    *categoryBox,
    *labelBox,
    *personBox,
    *objectBox,
    *locationBox,
    *positionBox;

  wxStaticText
    *pathText,
    *titleText,
    *newCategoryText,
    *newLabelText,
    *newPersonText,
    *newLocationText,
    *newPositionText,
    *newObjectText,
    *categorySelectedText,
    *personSelectedText,
    *objectSelectedText,
    *locationSelectedText,
    *positionSelectedText,
    *oldCategoryText,
    *oldLabelText,
    *oldPersonText,
    *oldLocationText,
    *oldPositionText,
    *oldObjectText,
    *selectedText;


  wxTextCtrl
    *objectInput,
    *descriptionInput,
    *categoryInput,
    *labelInput,
    *personInput,
    *locationInput,
    *positionInput;

  wxListCtrl
    *categoryOldList,
    *labelOldList,
    *personOldList,
    *objectOldList,
    *locationOldList,
    *positionOldList;
  
  wxListCtrl
    *labelSelected,
    *personSelected,
    *objectSelected,
    *locationSelected,
    *positionSelected;

  wxButton
    *categoryAdd,
    *labelAdd,
    *personAdd,
    *objectAdd,
    *locationAdd,
    *positionAdd,
    *labelSelect,
    *personSelect,
    *objectSelect,
    *locationSelect,
    *positionSelect;

  DECLARE_EVENT_TABLE();
};

enum
  {
    ID_categoryAdd=0,
    ID_labelAdd,
    ID_personAdd,
    ID_objectAdd,
    ID_locationAdd,
    ID_positionAdd,
    ID_labelSelect,
    ID_personSelect,
    ID_objectSelect,
    ID_locationSelect,
    ID_positionSelect    
  };

#endif
