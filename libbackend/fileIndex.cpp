#include "fileIndex.h"
#include "wxArchive.h"

/**
 * fileIndex class constructor
**/
fileIndex::fileIndex()
{
	//TODO: do something useful here :)
}

fileIndex::~fileIndex()
{
	//TODO: do something useful here
}

/**
 * Returns a wxArrayString pointee to pathIndex of our fileIndex class.
**/
wxArrayString* fileIndex::returnPathIndex()
{
  return &pathIndex;
}

/**
 * Looks for <wxString value> inside pathIndex.
 * <bool caseSensitive> enables/disables case sensitive search.
 * TODO: what happens if value is empty?
**/
int fileIndex::findValue(wxString value, bool caseSensitive)
{
  return pathIndex.Index(value, caseSensitive);
}

/**
 * linuxcommando: i think this should be removed completely because the function above offers more control.
 * The behavior of this function concerning case sensitivity might be unexpected due to wxWidgets API changes 
**/
/*
int fileIndex::findValue(wxString value)
{

  return pathIndex.Index(value);
}
*/

/**
 * Adds filename specified by <wxString filePath> to pathIndex.
 * TODO: what happens if filePath is empty?
**/
void fileIndex::addFile(wxString filePath)
{
  pathIndex.Add( filePath ); 
  imageObjectArray.Add(makeImageObject(filePath));
}

/**
 * Deletes filename specified by <wxString filePath> from pathIndex.
 * TODO: what happens if filePath is empty?
**/
void fileIndex::delFile(wxString filePath)
{
  pathIndex.Remove( filePath );
}

/**
 * Creates a imageObject for file specified by <wxString filePath>
 * Returns: pointee to imageObject
 * TODO: what happens if filePath is empty?
**/
imageObject* fileIndex::makeImageObject(wxString filePath)
{
	return new imageObject(filePath);
}

ArrayOfImageObjects* fileIndex::getImageObjects()
{
	return &imageObjectArray;	
}

void fileIndex::saveIndex(wxString path)
{
	wxFileOutputStream bdf_output(path);
	if (bdf_output.Ok() == false) return;

	wxArchive bdf_archive(bdf_output, BDF_INDEX_VERSION, _T("BDF INDEX"));
	if ((bdf_archive.IsOk() == false) or (bdf_archive.Eof() == true)) return;
	
	bdf_archive << pathIndex;
}

void fileIndex::loadIndex(wxString path)
{
	wxFileInputStream bdf_input(path);
	if (bdf_input.Ok() == false) return;
	
	wxArchive bdf_archive(bdf_input, BDF_INDEX_VERSION, _T("BDF INDEX"));
	if ((bdf_archive.IsOk() == false) or (bdf_archive.Eof())) return;
	
	bdf_archive >> pathIndex;
}

void fileIndex::loadImageObjects()
{
	for (int item = 0; item<pathIndex.GetCount(); item++)
	{
		imageObject* temp_imageobject;
		temp_imageobject = makeImageObject(pathIndex[item]);
		imageObjectArray.Add(temp_imageobject);	
	}
}
