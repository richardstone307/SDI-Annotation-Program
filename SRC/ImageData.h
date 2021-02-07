#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

///Class containing a loaded image and all relevant data (label names, annotations, filename)
public ref class imageData {
public:
	Bitmap^ srcImage; /// Image file to render
	List<List<int>^>^ boxList; /// List of co-ordinates of the two opposing corners of each annotation
	List<String^>^ boxNameList; /// Name of the label associated with the annotation */
	List<String^>^ labelList; /// Names of all labels associated with this image
	String^ fileName; /// Filename to display in the list
};