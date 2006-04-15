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
  void placeElements();

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
    *positionHSizerR;

    
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
    *titleText;


  wxTextCtrl
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
    *locationOldList;

  wxStaticText *categorySelected;
  
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
