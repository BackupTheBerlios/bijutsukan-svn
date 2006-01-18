#include "fileIndex.h"

#include <wx/wx.h>
#include <wx/arrstr.h>
#include <wx/string.h>
#include <wx/dynarray.h>


wxArrayString fileIndex::returnPathIndex()
{
  return pathIndex;
}

int fileIndex::findValue(wxString value, bool caseSensitive)
{
  return pathIndex.Index(value, caseSensitive);
}

int fileIndex::findValue(wxString value)
{

  return pathIndex.Index(value);
}


void fileIndex::addFile(wxString filePath)
{
  pathIndex.Add( filePath.wc_str() ); // maybe mb_str instead of wc_str
}

void fileIndex::delFile(wxString filePath)
{
  pathIndex.Remove( filePath.wc_str() );
}
