#pragma once

#include <iostream>
#include <fstream>
#include <string>
//#include <msclr\marshal_cppstd.h>
#include "Annotation.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class AnnotationFile
{
public:
	String^ annotationFileID;
	List<PolygonalAnnotation^>^ annotationsPolygonal = gcnew List<PolygonalAnnotation^>;
	List<CircularAnnotation^>^ annotationsCircular = gcnew List<CircularAnnotation^>;
	int numericalIDPool;

	AnnotationFile()
	{
		numericalIDPool = 0;
	}


	void createCircularAnnotation(String^ labelName) {
		CircularAnnotation^ tempAnnotation = gcnew CircularAnnotation;
		tempAnnotation->label = labelName;
		tempAnnotation->creationDate = DateTime::Now;
		tempAnnotation->annotationID = numericalIDPool;
		numericalIDPool++;
		annotationsCircular->Add(tempAnnotation);
	}

	void createPolygonalAnnotation(String^ labelName, List<int>^ vertices) {
		PolygonalAnnotation^ tempAnnotation = gcnew PolygonalAnnotation;
		tempAnnotation->label = labelName;
		tempAnnotation->creationDate = DateTime::Now;
		tempAnnotation->annotationID = numericalIDPool;
		numericalIDPool++;
		annotationsPolygonal->Add(tempAnnotation);
	}

	//void saveFile(std::string filePath) {
	//	String^ currentLine;
	//	std::string currentLineStd;
	//	ofstream saveFile;
	//	CircularAnnotation^ tempCircularAnnotation;
	//	PolygonalAnnotation^ tempPolygonalAnnotation;
	//	String^ vertexString;
	//	int tempVertex;
	//	saveFile.open(filePath);
	//	for (int i = 0; i < annotationsCircular->Count; i++)
	//	{
	//		tempCircularAnnotation = annotationsCircular[i];
	//		currentLine = gcnew String(tempCircularAnnotation->label + "," + tempCircularAnnotation->creationDate->Date + "," + tempCircularAnnotation->origin + "," + tempCircularAnnotation->radius);
	//		
	//		saveFile << currentLineStd;
	//	}

	//	for (int i = 0; i < annotationsPolygonal->Count; i++)
	//	{
	//		tempPolygonalAnnotation = annotationsPolygonal[i];
	//		vertexString = "";
	//		for (int j = 0; j < 4; j++) {
	//			tempVertex = tempPolygonalAnnotation->vertices[j];
	//			vertexString = vertexString + tempVertex.ToString() + ",";
	//		}
	//		currentLine = gcnew String(tempPolygonalAnnotation->label + "," + tempPolygonalAnnotation->creationDate->Date + "," + vertexString);
	//		saveFile << currentLineStd;
	//	}

	//	saveFile.close();

	//}

};