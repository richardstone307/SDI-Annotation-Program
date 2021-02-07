#pragma once

#include "ImageFile.h"
#include "Annotation.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class GUI
{
public:
	static int drawnImage;
	static List<ImageFile^>^ loadedImages = gcnew List<ImageFile^>;
	static List<Annotation^>^ annotations = gcnew List<Annotation^>;
	static Point^ mouseDownLocation = gcnew Point;
	static int xCornerSelected;
	static int yCornerSelected;
	static int annotationToResize;
	static List<int>^ imageIndices = gcnew List<int>;
	static List<int>^ labelIndices = gcnew List<int>;
	static List<String^>^ labelNames = gcnew List<String^>;
	static String^ workingFolderPath = "";
	static String^ labelFile = "";
	static String^ imageSearchTerm = "";
	static String^ labelSearchTerm = "";
	static Graphics^ boxCanvas;
	static String^ annotationFilePath = "";
	static float imageScale;
	static int xOffset;
	static int yOffset;

	static void LoadImageToList(ImageFile^ file)
	{
		loadedImages->Add(file);
	}

	static void LoadImageToCanvas(int imageIndex)
	{
		drawnImage = imageIndex;
	}

	static void CreateLabel(String^ labelName)
	{

	}

	static void DrawImage() {

	}

};