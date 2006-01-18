#ifndef IMGOBJECT_H
#define IGMOBJECT_H 1

#include <wx/wx.h>
#include <wx/string.h>

class imageObject{

 public:
  imageObject();
  imageObject(wxString path);

  wxString getFilePath();
  wxString getFileName();
  wxString getFileDescription();
  wxString getFileCategory();
  
  wxString setFilePath(wxString filePath);
  wxString setFileName(wxString fileName);
  wxString setFileDescription(wxString fileDescription);
  wxString setFileCategory(wxString fileCategory);
  

  wxArrayString getFileLabels();
  wxArrayString getFilePersons();
  wxArrayString getFileObjects();
  wxArrayString getFileLocations();
  wxArrayString getFilePositions();

  wxArrayString addFileLabels(wxString fileLabel);
  wxArrayString addFilePersons(wxString filePerson);
  wxArrayString addFileObjects(wxString fileObject);
  wxArrayString addFileLocations(wxString fileLocation);
  wxArrayString addFilePositions(wxString filePosition);

  wxArrayString delFileLabels(wxString fileLabel);
  wxArrayString delFilePersons(wxString filePerson);
  wxArrayString delFileObjects(wxString fileObject);
  wxArrayString delFileLocations(wxString fileLocation);
  wxArrayString delFilePositions(wxString filePosition);

 private:
  wxString filePath;
  wxString fileName;
  wxString fileDescription;
  wxString fileCategory;

  wxArrayString fileLabels;
  wxArrayString filePersons;
  wxArrayString fileObjects;
  wxArrayString fileLocations;
  wxArrayString filePositions;
  

};

#endif
