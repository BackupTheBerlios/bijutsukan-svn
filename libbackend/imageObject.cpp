#include "imageObject.h"

/**
 * Default Constructor: initializes empty imageObject
**/
imageObject::imageObject()
{
	//TODO: do something useful here
}

/**
 * Constructor: sets class member <wxString filePath> to <wxString path>
**/
imageObject::imageObject(wxString path)
{
  filePath = path.Append( _(".bdf") );
  // readInfo() // or something
}

/**
 * Initializes and returns new <wxString> object with value of class member <wxString filePath>
**/
wxString imageObject::getFilePath()
{
  return filePath;
}

/**
 * Initializes and returns new <wxString> object with value of class member <wxString fileName>
**/
wxString imageObject::getFileName()
{
  return fileName;
}

/**
 * Initializes and returns new <wxString> object with value of class member<wxString fileDescription>
**/
wxString imageObject::getFileDescription()
{
  return fileDescription;
}

/**
 * Initializes and returns new <wxString> object with value of class member <wxString fileCategory>
**/
wxString imageObject::getFileCategory()
{
  return fileCategory;
}

/**
 * Sets value of class member <wxString filePath> to <wxString nfilePath>
**/
void imageObject::setFilePath(wxString nfilePath)
{
  filePath = nfilePath;
}

/**
 * Sets value of class member <wxString fileName> to <wxString nfileName>
**/
void imageObject::setFileName(wxString nfileName)
{
  fileName = nfileName;
}

/**
 * Sets value of class member <wxString fileDescription> to <wxString nfileDescription>
**/
void imageObject::setFileDescription(wxString nfileDescription)
{
  fileDescription = nfileDescription;
}

/**
 * Sets value of class member <wxString fileCategory> to <wxString nfileCategory>
**/
void imageObject::setFileCategory(wxString nfileCategory)
{
  fileCategory = nfileCategory; // TODO: errorchecking if the category really exists
}

/**
 * Initializes and returns new <wxArrayString> Object  with values of class member <wxArrayString fileLabels>
**/
wxArrayString imageObject::getFileLabels()
{
  return fileLabels;
}

/**
 * Initializes and returns new <wxArrayString> Object  with values of class member <wxArrayString filePersons>
 **/
wxArrayString imageObject::getFilePersons()
{
  return filePersons;
}

/**
 * Initializes and returns new <wxArrayString> Object  with values of class member <wxArrayString fileObjects>
 **/
wxArrayString imageObject::getFileObjects()
{
  return fileObjects;
}

/**
 * Initializes and returns new <wxArrayString> Object  with values of class member <wxArrayString fileLocations>
 **/
wxArrayString imageObject::getFileLocations()
{
  return fileLocations;
}

/**
 * Initializes and returns new <wxArrayString> Object  with values of class member <wxArrayString filePositions>
 **/
wxArrayString imageObject::getFilePositions()
{
  return filePositions;
}

/**
 * Adds <wxString nfileLabel> to class member <wxArrayString fileLabels>
**/
void imageObject::addFileLabels(wxString nfileLabel)
{
  fileLabels.Add( nfileLabel.wc_str() );
}

/**
 * Adds <wxString nfilePerson> to class member <wxArrayString filePersons>
**/
void imageObject::addFilePersons(wxString nfilePerson)
{
  filePersons.Add( nfilePerson.wc_str() );
}

/**
 * Adds <wxString nfileObject> to class member <wxArrayString fileObjects>
**/
void imageObject::addFileObjects(wxString nfileObject)
{
  fileObjects.Add( nfileObject.wc_str() );
}

/**
 * Adds <wxString nfileLocation> to class member<wxArrayString fileLocations>
**/
void imageObject::addFileLocations(wxString nfileLocation)
{
  fileLocations.Add( nfileLocation.wc_str() );
}

/**
 * Adds <wxString nFilePosition> to class member <wxArrayString filePositions>
**/
void imageObject::addFilePositions(wxString nfilePosition)
{
  filePositions.Add( nfilePosition.wc_str() );
}

/**
 * Removes <wxString nfileLabel> from class member <wxArrayString fileLabels>
**/
void imageObject::delFileLabels(wxString nfileLabel)
{
  fileLabels.Remove( nfileLabel.wc_str() );
}

/**
 * Removes <wxString nfilePerson> from class member <wxArrayString filePersons>
**/
void imageObject::delFilePersons(wxString nfilePerson)
{
  filePersons.Remove( nfilePerson.wc_str() );
}

/**
 * Removes <wxString nfileObject> from class member <wxArrayString fileObjects>
**/
void imageObject::delFileObjects(wxString nfileObject)
{
  fileObjects.Remove( nfileObject.wc_str() );
}

/**
 * Removes <wxString nfileLocation> from class member <wxArrayString fileLocations>
**/
void imageObject::delFileLocations(wxString nfileLocation)
{
  fileLocations.Remove( nfileLocation.wc_str() );
}

/**
 * Removes <wxString nfilePosition> from class member <wxArrayString filePositions>
**/
void imageObject::delFilePositions(wxString nfilePosition)
{
  filePositions.Remove( nfilePosition.wc_str() );
}
