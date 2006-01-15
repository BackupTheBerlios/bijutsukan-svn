#ifndef BACKEND_H
#define BACKEND_H 1

#include "../tinyxml/tinyxml.h"
#include <wx/wx.h>
#include <wx/filename.h>
#include <wx/utils.h>
#include <wx/string.h>


class fileIndex
{
 public:
  void fileIndex();
  void setNewFile(wxString path);
  wxString getFiles();

 private:
  wxFileName myIndex;
  TiXmlDocument fileIndex;

  void makeXmlDoc();
}

#endif
