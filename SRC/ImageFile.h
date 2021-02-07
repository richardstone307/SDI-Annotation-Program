#pragma once
#include "AnnotationFile.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
///Class containing an image and its annotations.
public ref class ImageFile
{
public:
	Image^ imageID;
	String^ displayFileName;
	List<AnnotationFile^>^ annotationFiles = gcnew List<AnnotationFile^>;
	Point^ dimensions;
	DateTime^ creationDate = gcnew DateTime;
	void replaceImage(Image^ imageToLoad) {
		imageID = imageToLoad;
	}
	void createAnnotationFile() {
		AnnotationFile^ tempAnnotationFile = gcnew AnnotationFile;
		annotationFiles->Add(tempAnnotationFile);
	}
	void checkCompatibility() {

	}
};