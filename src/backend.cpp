#include "backend.h"


void fileIndex::fileIndex()
{
  wxString tmpcwd = wxGetCwd();
  myIndex = wxFileName(tmpcwd);
  makeXmlDoc()
}


void fileIndex::makeXmlDoc()
{
  fileIndex = TiXmlDocument(myIndex.GetFullPath());
  bool fileIndexOkay = fileIndex.LoadFile();
  if (!fileIndexOkay)
    {
      wxString tmpStr;
      tmpStr.Printf(_("error loading xml document ... Oo"));
      Close(true)
    }
}

void fileIndex::saveXmlDoc()
{

}
