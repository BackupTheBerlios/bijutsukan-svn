#ifndef FILEINDEX_H
#define FILEINDEX_H 1

#include <wx/wx.h>
#include <wx/arrstr.h>
#include <wx/string.h>
#include <wx/dynarray.h>
#include "imageObject.h"
// #include "wxArchive.h" // doesnt compile cleanly


class fileIndex
{

 public:
  fileIndex();
  wxArrayString returnPathIndex();
  int findValue(wxString value, bool caseSensitive);
  int findValue(wxString value);

  void addFile(wxString filePath);
  void delFile(wxString filePath);
  imageObject makeImageObject(wxString filePath);

 private:
  wxArrayString pathIndex;


};


#endif
