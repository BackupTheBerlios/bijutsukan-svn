#include "fileIndex.h"
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
  pathIndex.Add( filePath.wc_str() ); // maybe mb_str instead of wc_str
}

/**
 * Deletes filename specified by <wxString filePath> from pathIndex.
 * TODO: what happens if filePath is empty?
**/
void fileIndex::delFile(wxString filePath)
{
  pathIndex.Remove( filePath.wc_str() );
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
