#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class Annotation
{
public:
	int annotationID;
	String^ label;
	DateTime^ creationDate;
	Annotation() {

	}
	void setLabel(String^ labelName) {

	}
	void deleteAnnotation() {

	}
	void copyAnnotation() {
		Annotation^ tempAnnotation = gcnew Annotation;
		tempAnnotation->label = label;

	}

};

public ref class CircularAnnotation : Annotation
{
public:
	Point^ origin;
	int radius;
};

public ref class PolygonalAnnotation : Annotation
{
public:
	List<int>^ vertices;
};