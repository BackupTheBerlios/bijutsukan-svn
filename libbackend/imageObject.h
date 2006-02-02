#ifndef IMGOBJECT_H
#define IGMOBJECT_H 1

#include <wx/wx.h>
#include <wx/string.h>

class imageObject{

 public:
  imageObject();
  	// Default Constructor: initializes empty imageObject
		  
  imageObject(wxString path);
  	// Constructor: sets class member <wxString filePath> to <wxString path>
  
  wxString getFilePath();
  	// Initializes and returns new <wxString> object with value of class member <wxString filePath>

  wxString getFileTitle();
  	// Initializes and returns new <wxString> object with value of class member <wxString fileName>
  	
  wxString getFileDescription();
  	// Initializes and returns new <wxString> object with value of class member<wxString fileDescription>
  wxString getFileCategory();
  	// Initializes and returns new <wxString> object with value of class member <wxString fileCategory>
  
  void setFilePath(wxString nfilePath);
  	// Sets value of class member <wxString filePath> to <wxString nfilePath>
  
  void setFileTitle(wxString nfileTitle);
  	// Sets value of class member <wxString fileName> to <wxString nfileName>

  void setFileDescription(wxString nfileDescription);
  	// Sets value of class member <wxString fileDescription> to <wxString nfileDescription>
  
  void setFileCategory(wxString nfileCategory);
  	// Sets value of class member <wxString fileCategory> to <wxString nfileCategory>
  
  wxArrayString getFileLabels();
  	// Initializes and returns new <wxArrayString> Object  with values of class member <wxArrayString fileLabels>
  
  wxArrayString getFilePersons();
  	// Initializes and returns new <wxArrayString> Object  with values of class member <wxArrayString filePersons>
  
  wxArrayString getFileObjects();
  	// Initializes and returns new <wxArrayString> Object  with values of class member <wxArrayString fileObjects>
  
  wxArrayString getFileLocations();
  	// Initializes and returns new <wxArrayString> Object  with values of class member <wxArrayString fileLocations>
  
  wxArrayString getFilePositions();
  	// Initializes and returns new <wxArrayString> Object  with values of class member <wxArrayString filePositions>

  void addFileLabels(wxString nfileLabel);
  	// Adds <wxString nfileLabel> to class member <wxArrayString fileLabels>
  
  void addFilePersons(wxString nfilePerson);
  	// Adds <wxString nfilePerson> to class member <wxArrayString filePersons>
  
  void addFileObjects(wxString nfileObject);
  	// Adds <wxString nfileObject> to class member <wxArrayString fileObjects>
  
  void addFileLocations(wxString nfileLocation);
  	// Adds <wxString nfileLocation> to class member<wxArrayString fileLocations>
  
  void addFilePositions(wxString nfilePosition);
  	// Adds <wxString nFilePosition> to class member <wxArrayString filePositions>
  
  void delFileLabels(wxString nfileLabel);
  	// Removes <wxString nfileLabel> from class member <wxArrayString fileLabels>
  
  void delFilePersons(wxString nfilePerson);
  	// Removes <wxString nfilePerson> from class member <wxArrayString filePersons>
  
  void delFileObjects(wxString nfileObject);
  	// Removes <wxString nfileObject> from class member <wxArrayString fileObjects>
  void delFileLocations(wxString nfileLocation);
  	// Removes <wxString nfileLocation> from class member <wxArrayString fileLocations>
  void delFilePositions(wxString nfilePosition);
  	// Removes <wxString nfilePosition> from class member <wxArrayString filePositions>

 private:
  wxString filePath; //path to file
  wxString fileTitle; //title for file content
  wxString fileDescription; //description for file content
  wxString fileCategory; //category for file content

  wxArrayString fileLabels;
  wxArrayString filePersons;
  wxArrayString fileObjects;
  wxArrayString fileLocations;
  wxArrayString filePositions;
  

};

#endif
