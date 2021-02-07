#include <string>;
#include "GUI.h"
#include "ImageFile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

using namespace std;

/** Basic search functionality using a linear search. 
 *  Matches the search criteria to whatever the user
 *  enters. This does not have to be a complete search
 *  term, and will filter the list as the user types
 *  For instance, if a user types 'Kit' when searching
 *  for 'Kittens.jpg', it will filter out irrelevant items in the
 *  list. Search critera may also be in the middle, for instance
 *  'tte' will also filter down to 'Kittens.jpg'.
 */
List<String^>^ FilterList(List<String^>^ stringList, String^ filterTerm) {
	List<String^>^ returnList = gcnew List<String^>;
	for (int i = 0; i < stringList->Count; i++) {
		if (stringList[i]->Contains(filterTerm))
		{
			returnList->Add(stringList[i]);
		}
	}
	return returnList;
}

/** Basic sort functionality using a bubble sort.
 *  Sorts all items in the list by name with the
 *  ability to be applied inversely, so the function
 *  will sort by name both ascending and descending.
 */
List<String^>^ SortList(List<String^>^ stringList, int order) {
	int n = stringList->Count;
	bool swap = true;
	String^ tempString;
	while (swap) {
		swap = false;
		for (int i = 1; i < n; i++) {
			if (System::String::Compare(stringList[i - 1], stringList[i]) > 0) {
				tempString = stringList[i - 1];
				stringList[i - 1] = stringList[i];
				stringList[i] = tempString;
				swap = true;
			}
		}
	}
	if (order < 0) {
		stringList->Reverse();
	}
	return stringList;
}

//! 
List<String^>^ FilterAndSort(List<String^>^ stringList, String^ filterTerm, int order) {
	stringList = FilterList(stringList, filterTerm);
	stringList = SortList(stringList, order);
	return stringList;
}