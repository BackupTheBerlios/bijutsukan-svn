/*******************************
 * libbackend test application *
 *******************************/

#include <iostream>
#include <wx/wx.h>

#include "../fileIndex.h"
#include "../wxArchive.h"

using namespace std;

void fileIndex_test()
{
	cout << "Testing fileIndex functions" << endl;
	cout << "============================";
	cout << "- Initializing Constructor" << endl;
	fileIndex my_fileIndex;
	cout << "- Adding Files: TEST, test1, Test2, TEST3"<<endl;
	my_fileIndex.addFile(_("test1"));
	my_fileIndex.addFile(_("Test2"));
	my_fileIndex.addFile(_("TEST3"));

	cout << "- Getting Path Index" << endl;
	wxArrayString my_PathIndex;
	my_PathIndex = my_fileIndex.returnPathIndex();
	if ( my_PathIndex.GetCount() == 3 )
	{
		wxString current_item;
		cout << "-- Path Index Count == 3 [OK]" << endl;
		current_item = my_PathIndex.Item(0);
		int cmp_value = current_item.Cmp(_("test1"));
		
		if (cmp_value == 0) 
			cout << "-- Item 0 == \"test1\" [OK]" << endl;
		else
			cout << "-- Item 0 != \"test1\" [!!]" << endl;

		current_item = my_PathIndex.Item(1);
		cmp_value = current_item.Cmp(_("Test2"));

		if (cmp_value == 0) 
			cout << "-- Item 2 == \"Test2\" [OK]" << endl;
		else
			cout << "-- Item 2 != \"Test2\" [!!]" << endl;
		
		current_item = my_PathIndex.Item(2);
		cmp_value = current_item.Cmp(_("TEST3"));

				
		if (cmp_value == 0) 
			cout << "-- Item 3 == \"TEST3\" [OK]" << endl;
		else
			cout << "-- Item 2 != \"TEST3\" [!!]" << endl;

		
	
		
	}
	else
		cout << "-- Path Index Count =! 3 [!!]" << endl;
	
	
	cout << "============================";
	cout << "Finished." << endl;
}

void imageObject_test()
{
	cout << "Testing imageObject functions" << endl;
	cout << "Finished." << endl;
}

void wxArchive_test()
{
	cout << "Testing wxArchive functions" << endl;
	cout << "Finished." << endl;
}

int main()
{	
	fileIndex_test();
	imageObject_test();
	wxArchive_test();
	
	return 0;
}
