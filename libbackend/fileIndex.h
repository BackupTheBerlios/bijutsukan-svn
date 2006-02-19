#ifndef FILEINDEX_H
#define FILEINDEX_H 1

//#include <wx/wx.h>
#include <wx/arrstr.h>
#include <wx/dynarray.h>
#include <wx/string.h>
#include <wx/dynarray.h>
#include "imageObject.h"
#include "wxArchive.h" 

WX_DECLARE_OBJARRAY(imageObject, ArrayOfImageObjects);


class fileIndex
{

 public:

  fileIndex();
  	/**
	 * fileIndex class constructor
	**/
  
  ~fileIndex();
  	/**
	 * fileIndex class destructor
	**/
  
  wxArrayString* returnPathIndex();
  	/**
	 * Returns a wxArrayString pointee to pathIndex of our fileIndex class.
	**/
  int findValue(wxString value, bool caseSensitive);
  	/**
	 * Looks for <wxString value> inside pathIndex.
  	 * <bool caseSensitive> enables/disables case sensitive search.
	**/
  //int findValue(wxString value);
  	// linuxcommando: this function should be removed, see source file for details

  void addFile(wxString filePath);
	/**
	 * Adds filename specified by <wxString filepath> to pathIndex.
	**/
  void delFile(wxString filePath);
  	/**
  	 * Deletes filename specified by <wxString filepath> from pathIndex.
  	**/
  imageObject* makeImageObject(wxString filePath);
 	 /**
	  *
	 **/

  ArrayOfImageObjects* getImageObjects();
  
 private:
  wxArrayString pathIndex;
  ArrayOfImageObjects imageObjectArray;

};

#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(ArrayOfImageObjects);

#endif
