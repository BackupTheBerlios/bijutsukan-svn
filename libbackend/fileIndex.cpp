#include "fileIndex.h"

fileIndex::fileIndex()
{
	//TODO: do something useful here :)
}

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

imageObject makeImageObject(wxString filePath)
{

}
