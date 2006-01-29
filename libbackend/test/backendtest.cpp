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
	cout << "=============================" << endl;
	cout << " Testing fileIndex functions " << endl;
	cout << "=============================" << endl;
	cout << "- Initializing Constructor" << endl;
	fileIndex my_fileIndex;
	cout << "- Adding Files: test1, Test2, TEST3"<<endl;
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
			cout << "-- Item 1 == \"Test2\" [OK]" << endl;
		else
			cout << "-- Item 1 != \"Test2\" [!!]" << endl;
		
		current_item = my_PathIndex.Item(2);
		cmp_value = current_item.Cmp(_("TEST3"));

				
		if (cmp_value == 0) 
			cout << "-- Item 2 == \"TEST3\" [OK]" << endl;
		else
			cout << "-- Item 2 != \"TEST3\" [!!]" << endl;
	}
	else
		cout << "-- Path Index Count =! 3 [!!]" << endl;

	//==============================================================
	
	cout << "- findValue (non case sensitive)" << endl;
	int match = my_fileIndex.findValue(_("test"), false);
if (match == wxNOT_FOUND)
		cout << "-- test: not found [OK]" << endl; 
	else
		cout << "-- test: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("test1"), false);
	if (match == 0)
		cout << "-- test1: 0 [OK]" << endl; 
	else if (match == wxNOT_FOUND)
		cout << "-- test1: not found [!!]" << endl;
	else
		cout << "-- test1: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("test2"), false);
	if (match == 1)
		cout << "-- test2: 1 [OK]" << endl; 
	else if (match == wxNOT_FOUND)
		cout << "-- test2: not found [!!]" << endl;
	else
		cout << "-- test2: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("test3"), false);
	if (match == 2)
		cout << "-- test3: 2 [OK]" << endl; 
	else if (match == wxNOT_FOUND)
		cout << "-- test3: not found [!!]" << endl;
	else
		cout << "-- test3: " << match << " [!!]" << endl;

	//---------------------------------------------------------------
	
	match = my_fileIndex.findValue(_("Test"), false);
	if (match == wxNOT_FOUND)
		cout << "-- Test: not found [OK]" << endl;
	else
		cout << "-- Test: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("Test1"), false);
	if (match == 0)
		cout << "-- Test1: 0 [OK]" << endl; 
	else if (match == wxNOT_FOUND)
		cout << "-- Test1: not found [!!]" << endl;
	else
		cout << "-- Test1: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("Test2"), false);
	if (match == 1)
		cout << "-- Test2: 1 [OK]" << endl; 
	else if (match == wxNOT_FOUND)
		cout << "-- Test2: not found [!!]" << endl;
	else
		cout << "-- Test2: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("Test3"), false);
	if (match == 2)
		cout << "-- Test3: 2 [OK]" << endl; 
	else if (match == wxNOT_FOUND)
		cout << "-- Test3: not found [!!]" << endl;
	else
		cout << "-- Test3: " << match << " [!!]" << endl;

	//---------------------------------------------------------------
	
	match = my_fileIndex.findValue(_("TEST"), false);
	if (match == wxNOT_FOUND)
		cout << "-- TEST: not found [OK]" << endl;
	else
		cout << "-- TEST: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("TEST1"), false);
	if (match == 0)
		cout << "-- TEST1: 0 [OK]" << endl; 
	else if (match == wxNOT_FOUND)
		cout << "-- TEST1: not found [!!]" << endl;
	else
		cout << "-- TEST1: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("TEST2"), false);
	if (match == 1)
		cout << "-- TEST2: 1 [OK]" << endl; 
	else if (match == wxNOT_FOUND)
		cout << "-- TEST2: not found [!!]" << endl;
	else
		cout << "-- TEST2: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("TEST3"), false);
	if (match == 2)
		cout << "-- TEST3: 2 [OK]" << endl; 
	else if (match == wxNOT_FOUND)
		cout << "-- TEST3: not found [!!]" << endl;
	else
		cout << "-- TEST3: " << match << " [!!]" << endl;

	//============================================================
	
	cout << "- findValue (case sensitive)" << endl;
	match = my_fileIndex.findValue(_("test"), true);
	if (match == wxNOT_FOUND)
		cout << "-- test: not found [OK]" << endl;
	else
		cout << "-- test: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("test1"), true);
	if (match == 0)
		cout << "-- test1: 0 [OK]" << endl; 
	else if (match == wxNOT_FOUND)
		cout << "-- test1: not found [!!]" << endl;
	else
		cout << "-- test1: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("test2"), true);
	if (match == wxNOT_FOUND)
		cout << "-- test2: not found [OK]" << endl;
	else
		cout << "-- test2: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("test3"), true);
	if (match == wxNOT_FOUND)
		cout << "-- test3: not found [OK]" << endl;
	else
		cout << "-- test3: " << match << " [!!]" << endl;

	//-------------------------------------------------------------
	
	match = my_fileIndex.findValue(_("Test"), true);
	if (match == wxNOT_FOUND)
		cout << "-- Test: not found [OK]" << endl;
	else
		cout << "-- Test: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("Test1"), true);
	if (match == wxNOT_FOUND)
		cout << "-- Test1: not found [OK]" << endl;
	else
		cout << "-- Test1: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("Test2"), true);
	if (match == 1)
		cout << "-- Test2: 1 [OK]" << endl; 
	else if (match == wxNOT_FOUND)
		cout << "-- Test2: not found [!!]" << endl;
	else
		cout << "-- Test2: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("Test3"), true);
	if (match == wxNOT_FOUND)
		cout << "-- Test3: not found [OK]" << endl;
	else
		cout << "-- Test3: " << match << " [!!]" << endl;

	//--------------------------------------------------------------
	
	match = my_fileIndex.findValue(_("TEST"), true);
	if (match == wxNOT_FOUND)
		cout << "-- TEST: not found [OK]" << endl;
	else
		cout << "-- TEST: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("TEST1"), true);
	if (match == wxNOT_FOUND)
		cout << "-- TEST1: not found [OK]" << endl;
	else
		cout << "-- TEST1: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("TEST2"), true);
	if (match == wxNOT_FOUND)
		cout << "-- TEST2: not found [OK]" << endl;
	else
		cout << "-- TEST2: " << match << " [!!]" << endl;

	match = my_fileIndex.findValue(_("TEST3"), true);
	if (match == 2)
		cout << "-- TEST3: 2 [OK]" << endl;
	else if (match == wxNOT_FOUND)
		cout << "-- TEST3: not found [!!]" << endl;
	else
		cout << "-- TEST3: " << match << " [!!]" << endl;
	//==============================================================
	
	cout << "- delete Files " << endl;
	my_fileIndex.delFile(_("test1"));
	match = my_fileIndex.findValue(_("test1"), true);
	if (match = wxNOT_FOUND)
		cout << "-- test1: deleted [OK]" << endl;
	else
		cout << "-- test1: still found: " << match << " [!!]" << endl;

	my_fileIndex.delFile(_("Test2"));
	match = my_fileIndex.findValue(_("Test2"), true);
	if (match = wxNOT_FOUND)
		cout << "-- Test2: deleted [OK]" << endl;
	else
		cout << "-- Test2: still found: " << match << " [!!]" << endl;

	my_fileIndex.delFile(_("TEST3"));
	match = my_fileIndex.findValue(_("TEST3"), true);
	if (match == wxNOT_FOUND)
		cout << "-- TEST3: deleted [OK]" << endl;
	else
		cout << "-- TEST3 : still found: " << match << "[!!]" << endl;
	
	cout << "Finished." << endl;
}

void imageObject_test()
{
	cout << "===============================" << endl;
	cout << " Testing imageObject functions " << endl;
	cout << "===============================" << endl;
	cout << "Finished." << endl;
}

void wxArchive_test()
{
	cout << "=============================" << endl;
	cout << " Testing wxArchive functions " << endl;
	cout << "=============================" << endl;
	cout << "Finished." << endl;
}

int main()
{	
	fileIndex_test();
	imageObject_test();
	wxArchive_test();
	
	return 0;
}
