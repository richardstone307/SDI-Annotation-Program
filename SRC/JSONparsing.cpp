#include <string>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "GUI.h"
#include "Classlist.h"
#include "JSONparsing.h"

using namespace std;
using json = nlohmann::json;


/** Converts system string to std::string.
	 */
string SystemToStdString(String^ inputString) {
	char* cstr = (char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(inputString)).ToPointer();
	string convertedString = cstr;
	System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)cstr));
	return convertedString;
}


/** Formats and exports the current annotation
	*data as JSON.
	 */
void SaveJson(string filePath) 
{
	json file;
	int imageCount = 0;
	file["annotatedImages"] = json::array();
	std::string tempString;
	for (int i = 0; i < GUI::loadedImages->Count; i++) {
		if (GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal->Count != 0) {
			
			tempString = SystemToStdString(GUI::loadedImages[i]->displayFileName);
			file["annotatedImages"][imageCount] = json::object();
			file["annotatedImages"][imageCount]["filename"] = tempString;
			file["annotatedImages"][imageCount]["shapeCount"] = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal->Count;
			file["annotatedImages"][imageCount]["shapes"] = json::array();
			for (int j = 0; j < GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal->Count; j++) {
				tempString = SystemToStdString(GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->label);
				int Point1X = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->vertices[0];
				int Point1Y = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->vertices[1];
				int Point2X = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->vertices[2];
				int Point2Y = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->vertices[3];
				auto jsonObject = json::object();
				jsonObject["label"] = tempString;
				jsonObject["point1"] = { Point1X, Point1Y };
				jsonObject["point2"] = { Point2X, Point2Y };
				file["annotatedImages"][imageCount]["shapes"].push_back(jsonObject);
			}
			imageCount += 1;
		}
	}
	file["imageCount"] = imageCount;
	ofstream writeFile(filePath);
	writeFile << file << endl;
	writeFile.close();
}

/** Loads a JSON / .annotations file and parses the data.
	 */
void LoadJson(string filePath)
{
	ifstream reader(filePath);
	json file;
	file = json::parse(reader);
	int imageCount = file["imageCount"].get<int>();
	for (int i = 0; i < imageCount; i++) {
		auto tempImage = json::object();
		for (int j = 0; j < GUI::loadedImages->Count; j++) {
			if (SystemToStdString(GUI::loadedImages[j]->displayFileName) == file["annotatedImages"][i]["filename"].get<string>()) {
				String^ tempName;
				string tempString;
				for (int k = 0; k < file["annotatedImages"][i]["shapeCount"]; k++)
				{
					vector<int> tempPoint1 = file["annotatedImages"][i]["shapes"][k]["point1"].get<vector<int>>();
					vector<int> tempPoint2 = file["annotatedImages"][i]["shapes"][k]["point2"].get<vector<int>>();
					List<int>^ tempVertices = gcnew List<int>;
					tempVertices->Add(tempPoint1[0]);
					tempVertices->Add(tempPoint1[1]);
					tempVertices->Add(tempPoint2[0]);
					tempVertices->Add(tempPoint2[1]);
					tempString = file["annotatedImages"][i]["shapes"][k]["label"].get<string>();
					tempName = gcnew String(tempString.c_str());
					PolygonalAnnotation^ tempAnnotation = gcnew PolygonalAnnotation;
					tempAnnotation->vertices = tempVertices;
					tempAnnotation->label = tempName;
					GUI::loadedImages[j]->annotationFiles[0]->annotationsPolygonal->Add(tempAnnotation);
				}
			}
		}
	}
}