#pragma once
#include <string>;
#include "ImageFile.h"
#include "GUI.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace std;

List<String^>^ FilterList(List<String^>^, String^);

List<String^>^ SortList(List<String^>^, int);

List<String^>^ FilterAndSort(List<String^>^, String^, int);