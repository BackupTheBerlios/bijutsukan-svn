#include <iostream>
#include "imageObject-test.h"
#include "../imageObject.h"

using namespace std;

void imageObject_test()
{
	cout << "===============================" << endl;
	cout << " Testing imageObject functions " << endl;
	cout << "===============================" << endl;
	cout << "- Initializing empty imageObject" << endl;
	imageObject my_imageObject;
	cout << "- Filling in values" << endl;
	
	cout << "Setting FilePath" << endl;
	my_imageObject.setFilePath(_("testpath.ext.bdf"));
	
	cout << "Getting FilePath" << endl;
	wxString testbuffer = my_imageObject.getFilePath();
	
	cout << "Comparing FilePath I/O: "; 
	if (testbuffer == _("testpath.ext.bdf")) 
		cout << "[OK]" << endl;
	else
		cout << "[!!]" << endl;

	cout << "Setting FileTitle" << endl;
	my_imageObject.setFileTitle(_("Test Path Picture"));

	cout << "Getting FileTitle" << endl;
	testbuffer = my_imageObject.getFileTitle();

	cout << "Comparing FileTitle I/O: "; 
	if (testbuffer == _("Test Path Picture")) 
		cout << "[OK]" << endl;
	else
		cout << "[!!]" << endl;

	cout << "Setting FileDescription" << endl;
	my_imageObject.setFileDescription(_("my testpath description"));

	cout << "Getting FileDescription" << endl;
	testbuffer = my_imageObject.getFileDescription();

	cout << "Comparing FileDescription I/O: "; 
	if (testbuffer == _("my testpath description")) 
		cout << "[OK]" << endl;
	else
		cout << "[!!]" << endl;

	cout << "Setting FileCategory" << endl;
	my_imageObject.setFileCategory(_("Other"));

	cout << "Getting FileCategory" << endl;
	testbuffer = my_imageObject.getFileCategory();

	cout << "Comparing FileCategory I/O: ";
	if (testbuffer == _("Other")) 
		cout << "[OK]" << endl;
	else
		cout << "[!!]" << endl;
	
	cout << "-- Writing BDF data" << endl;
	my_imageObject.saveBdfData();

	cout << "-- Reading BDF data" << endl;
	imageObject new_imageObject(_("testpath.ext"));

	cout << "-- Comparing BDF I/O data" << endl;
	if (my_imageObject.getFilePath() ==  new_imageObject.getFilePath())
		cout << "FilePath: [OK]" << endl;
	else
		cout << "FilePath: [!!]" << endl;
	
	if (my_imageObject.getFileTitle() ==  new_imageObject.getFileTitle())
		cout << "FileTitle: [OK]" << endl;
	else
		cout << "FileTitle: [!!]" << endl;
	
	if (my_imageObject.getFileDescription() ==  new_imageObject.getFileDescription())
		cout << "FileDescription: [OK]" << endl;
	else
		cout << "FileDescription: [!!]" << endl;
		
	cout << "Finished." << endl;
}
