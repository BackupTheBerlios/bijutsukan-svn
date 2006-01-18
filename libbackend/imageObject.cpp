#include "imageObject.h"

imageObject::imageObject()
{
}

imageObject::imageObject(wxString path)
{
  filePath = path.Append( _(".bdf").wc_str() );
  readInfo()
}

wxString imageObject::getFilePath();
{
  return filePath;
}
wxString imageObject::getFileName();
{
  return fileName;
}
wxString imageObject::getFileDescription();
{
  return fileDescription;
}
wxString imageObject::getFileCategory();
{
  return fileCategory;
}

wxString imageObject::setFilePath(wxString nfilePath);
{
  filePath = nfilePath;
}
wxString imageObject::setFileName(wxString nfileName);
{
  fileName = nfileName
}
wxString imageObject::setFileDescription(wxString nfileDescription);
{
  fileDescription = nfileDescription;
}
wxString imageObject::setFileCategory(wxString nfileCategory);
{
  if(checkCategory(nfileCategory)=1)
    {
      fileCategory = nfileCategory;
    }
  else
    {
      // do something?
    }
}


wxArrayString imageObject::getFileLabels();
{
  return fileLabels;
}
wxArrayString imageObject::getFilePersons();
{
  return filePersons;
}
wxArrayString imageObject::getFileObjects();
{
  return fileObjects;
}
wxArrayString imageObject::getFileLocations();
{
  return fileLocations;
}
wxArrayString imageObject::getFilePositions();
{
  return filePositions;
}


wxArrayString imageObject::addFileLabels(wxString nfileLabel);
{
  fileLabel.Append( nfileLabel.wc_str() );
}
wxArrayString imageObject::addFilePersons(wxString nfilePerson);
{
  filePersons.Append( nfilePerson.wc_str() );
}
wxArrayString imageObject::addFileObjects(wxString nfileObject);
{
  fileObjects.Append( nfileObject.wc_str() );
}
wxArrayString imageObject::addFileLocations(wxString nfileLocation);
{
  fileLocations.Append( nfileLocation.wc_str() );
}
wxArrayString imageObject::addFilePositions(wxString nfilePosition);
{
  filePositions.Append( nfilePosition.wc_str() );
}


wxArrayString imageObject::delFileLabels(wxString nfileLabel);
{
  fileLabels.Remove( nfileLabel.wc_str() );
}
wxArrayString imageObject::delFilePersons(wxString nfilePerson);
{
  filePersons.Remove( nfilePerson.wc_str() );
}
wxArrayString imageObject::delFileObjects(wxString nfileObject);
{
  fileObjects.Remove( nfileObject.wc_str() );
}
wxArrayString imageObject::delFileLocations(wxString nfileLocation);
{
  fileLocations.Remove( nfileLocation.wc_str() );
}
wxArrayString imageObject::delFilePositions(wxString nfilePosition);
{
  filePositions.Remove( nfilePosition.wc_str() );
}
