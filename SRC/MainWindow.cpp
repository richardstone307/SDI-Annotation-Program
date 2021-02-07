#include <string>
#include "ImageData.h"
#include "GlobalImageList.h"
#include "MainWindow.h"
#include <filesystem>
#include "Annotation.h"
#include "AnnotationFile.h"
#include "ImageFile.h"
#include "PositionCalculation.h"
#include "GUI.h"
#include <fstream>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace SDIMaster;
using namespace GlobalList;
using namespace std;
using namespace PositionCalculation;

namespace SDIMaster
{

	/** Selects and passes back a location to save a file.
	 *  In the case of this application, the file saved using
	 *  this feature will be the .annotations file (formatted
	 *  as json).
	 */
	System::String^ MainWindow::SaveFile(String^ filter) 
	{
		System::String^ namesPath = "";
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog;
		{
			saveFileDialog->InitialDirectory = "c:\\";
			saveFileDialog->Filter = filter;
			saveFileDialog->FilterIndex = 0;
			saveFileDialog->RestoreDirectory = true;
			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				//Get the path of specified file
				namesPath = saveFileDialog->FileName;
				return namesPath;
			}
		}
	}

	/** Loads the contents of the selected folder into the GUI.
	 *  In the case of this application, the images to be annotated
	 *  will be loaded into the GUI, and can in theory load an
	 *  unlimited amount of images, depending on the user's
	 *  installed memory.
	 */
	System::Void MainWindow::BrowseFolder() {
		System::String^ folderPath;
		FolderBrowserDialog^ folderBrowserDialog = gcnew FolderBrowserDialog;
		{
			if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				folderPath = folderBrowserDialog->SelectedPath;
				GUI::workingFolderPath = folderPath;
				LoadFolder(folderPath);
			}
		}
	}

	/** Loads the contents of the selected folder into the GUI.
	 *  In the case of this application, the images to be annotated
	 *  will be loaded into the GUI, and can in theory load an
	 *  unlimited amount of images, depending on the user's
	 *  installed memory.
	 */
	System::Void MainWindow::LoadFolder(String^ folderPath)
	{
		cli::array<System::String^>^ fileArray = System::IO::Directory::GetFiles(folderPath);
		ClearImages();
		for (int i = 0; i < fileArray->Length; i++) {
			if (fileArray[i]->EndsWith(".jpg") || fileArray[i]->EndsWith(".png") || fileArray[i]->EndsWith(".jpeg") || fileArray[i]->EndsWith(".bmp"))
			{
				AddImage(fileArray[i]);
			}
		}
	}

	/** Adds the current image to the GUI. The image
	 *  name will be added to the list on the left panel,
	 *  and the image itself will be drawn to the canvas
	 *  when clicked.
	 */
	System::Void MainWindow::AddImage(String^ filePath)
	{
		FileInfo^ tempFileInfo = gcnew FileInfo(filePath);
		ImageFile^ tempImage = gcnew ImageFile;
		tempImage->displayFileName = Path::GetFileName(filePath);
		tempImage->imageID = gcnew Bitmap(filePath);
		tempImage->dimensions = gcnew Point(tempImage->imageID->Width, tempImage->imageID->Height);
		tempImage->annotationFiles->Add(gcnew AnnotationFile);
		tempImage->creationDate = tempFileInfo->LastWriteTime;
		GUI::LoadImageToList(tempImage);
	}

	/** Clears the images currently loaded from memory.
	 */
	System::Void MainWindow::ClearImages()
	{
		GUI::loadedImages->Clear();
	}

	/** Opens the file browsing dialog for selecting a file.
	 *  This will be used for selecting a .names file for the
	 *  classification of different annotations using the default
	 *  Windows file browser.
	 */
	System::String^ MainWindow::BrowseFile(String^ filter) {
		System::String^ namesPath = "";
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
		{
			openFileDialog->InitialDirectory = "c:\\";
			openFileDialog->Filter = filter;
			openFileDialog->FilterIndex = 0;
			openFileDialog->RestoreDirectory = true;
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				//Get the path of specified file
				namesPath = openFileDialog->FileName;
				return namesPath;
			}
		}
	}

	/** Reads through the .names file and loads them to the panel.
	 *  This utilises StreamReader for opening and loading the
	 *  .names file to display all relevant classes found into
	 *  the user interface.
	 */
	System::Void MainWindow::LoadClasses(String^ filePath) {
		StreamReader^ nameFile = gcnew StreamReader(filePath);
		String^ line;
		while (!nameFile->EndOfStream) {
			line = nameFile->ReadLine();
			GUI::labelNames->Add(line);
		}
		nameFile->Close();
	}

	/** Clears the classes currently loaded from memory.
	 */
	System::Void MainWindow::ClearClasses()
	{
		GUI::labelNames->Clear();
		GUI::labelIndices->Clear();
	}

	/** Allows the user to add a new classification.
	 *  This function will be called when the user clicks
	 *  the 'Add Class' button after typing in a name for
	 *  the class. This will then be added to the GUI.
	 */
	System::Void MainWindow::AddClass(String^ className) {
		GUI::labelNames->Add(className);
		WriteClass(className);
	}

	/** Writes the previously added class to the .names file.
	 *  Makes use of file handling to do so, and will add the
	 *  class to a new line in the .names file.
	 */
	System::Void MainWindow::WriteClass(String^ className) {
		StreamWriter^ nameFile = gcnew StreamWriter(GUI::labelFile, true);
		nameFile->WriteLine(className);
		nameFile->Close();
	}

	/** Removes a class from the GUI and .names file.
	 *  When the user clicks on a class in the GUI,
	 *  they can then click the 'Remove Class' button
	 *  removing it from both the GUI panel and the
	 *  .names file.
	 */
	System::Void MainWindow::RemoveClass(int classIndex) {
		StreamWriter^ nameFile = gcnew StreamWriter(GUI::labelFile);
		String^ className = GUI::labelNames[classIndex];

		//Remove annotations that match
		for (int i = 0; i < GUI::loadedImages->Count; i++) {
			for (int j = GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal->Count; j > 0; j--) {
				if (GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal[j]->label = className)
				{
					GUI::loadedImages[i]->annotationFiles[0]->annotationsPolygonal->RemoveAt(j);
					j -= 1;
				}
			}
		}

		GUI::labelNames->RemoveAt(classIndex);
		for (int i = 0; i < GUI::labelNames->Count; i++) {
			nameFile->WriteLine(GUI::labelNames[i]);
		}
		nameFile->Close();
	}

	/** Sorts the images by name. Uses the implementation
	 *  found in SortAndSearch.cpp, allowing the images to
	 *  be sorted ascending or descending by name.
	 */
	System::Void MainWindow::SortImageByName(String^ order) {
		GUI::imageIndices->Clear();
		GroupBox_Images->Items->Clear();
		//sort
		for (int i = 0; i < GUI::loadedImages->Count; i++) {
			if (GUI::loadedImages[i]->displayFileName->Contains(GUI::imageSearchTerm))
			{
				GUI::imageIndices->Add(i);
			}
		}

		int n = GUI::imageIndices->Count;
		bool swap = true;
		int tempIndex;
		while (swap) {
			swap = false;
			for (int i = 1; i < n; i++) {
				if (System::String::Compare(GUI::loadedImages[GUI::imageIndices[i - 1]]->displayFileName, GUI::loadedImages[GUI::imageIndices[i]]->displayFileName) > 0) {
					tempIndex = GUI::imageIndices[i];
					GUI::imageIndices[i - 1] = GUI::imageIndices[i];
					GUI::imageIndices[i - 1] = tempIndex;
					swap = true;
				}
			}
		}
		if (order == "DESCENDING") 
		{
			GUI::imageIndices->Reverse();
		}

		for (int i = 0; i < GUI::imageIndices->Count; i++) 
		{
			GroupBox_Images->Items->Add(GUI::loadedImages[GUI::imageIndices[i]]->displayFileName);
		}
	}

	/** Sorts the image by date. Uses the implementation
	 *  found in SortAndSearch.cpp, allowing the images to
	 *  be sorted ascending or descending by date.
	 */
	System::Void MainWindow::SortImageByDate(String^ order) {
		GUI::imageIndices->Clear();
		//sort
		for (int i = 0; i < GUI::loadedImages->Count; i++) {

		}
	}

	/** Sorts the class pane by name. Uses the implementation
	 *  found in SortAndSearch.cpp, allowing the images to be
	 *  sorted ascending or descending by name.
	 */
	System::Void MainWindow::SortClassPane(String^ order) {
		GUI::labelIndices->Clear();
		GroupBox_Classes->Items->Clear();
		//sort
		for (int i = 0; i < GUI::labelNames->Count; i++) {
			if (GUI::labelNames[i]->Contains(GUI::labelSearchTerm))
			{
				GroupBox_Classes->Items->Add(GUI::labelNames[i]);
				GUI::labelIndices->Add(i);
			}
		}
	}

	/**  List all current annotations in the GUI. Shows
	 *   all annotations, whether loaded from a file or
	 *   created in the current session.
	 */
	System::Void MainWindow::ListAnnotations() {
		GroupBox_Annotations->Items->Clear();
		//sort
		for (int i = 0; i < GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal->Count; i++) {
			List<int>^ tempVertices = GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[i]->vertices;
			String^ tempLabel = GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[i]->label;
			String^ displayName = "{" + tempLabel + "} [" + System::Convert::ToString(tempVertices[0]) + ", " + System::Convert::ToString(tempVertices[1]) + "] - [" + System::Convert::ToString(tempVertices[2]) + ", " + System::Convert::ToString(tempVertices[3]) + "]";
			GroupBox_Annotations->Items->Add(displayName);
		}
	}

	/** Removes a rectangular annotation.
	 */
	System::Void MainWindow::RemovePolygonalAnnotation(int imageIndex, int annotationIndex) {
		GUI::loadedImages[imageIndex]->annotationFiles[0]->annotationsPolygonal->RemoveAt(annotationIndex);
	}

	/** Draws all current annotations to the screen.
	 *  Adds the annotations to the current image in the canvas
	 *  including both annotations drawn in the current session
	 *  and loaded from the .names file.
	 */
	System::Void MainWindow::RenderAnnotations(int imageIndex)
	{
		GUI::boxCanvas = imageDisplay->CreateGraphics();
		imageDisplay->BackgroundImage = GUI::loadedImages[GUI::drawnImage]->imageID;
		GUI::boxCanvas->Clear(Color::Black);

		//Calculate scaling of image
		GUI::imageScale = float(imageDisplay->Width) / float(imageDisplay->BackgroundImage->Width);
		if (float(imageDisplay->Height) / float(imageDisplay->BackgroundImage->Height) < GUI::imageScale)
		{
			GUI::imageScale = float(imageDisplay->Height) / float(imageDisplay->BackgroundImage->Height);
			GUI::yOffset = 0;
			GUI::xOffset = floor((imageDisplay->Width - float(imageDisplay->BackgroundImage->Width) * GUI::imageScale) / 2);
		}
		else
		{
			GUI::yOffset = floor((imageDisplay->Height - float(imageDisplay->BackgroundImage->Height) * GUI::imageScale) / 2);
			GUI::xOffset = 0;
		}
		GUI::boxCanvas->DrawImage(imageDisplay->BackgroundImage, float(GUI::xOffset), float(GUI::yOffset), float(imageDisplay->BackgroundImage->Width) * GUI::imageScale, float(imageDisplay->BackgroundImage->Height) * GUI::imageScale);
		//Draw boxes
		Color boxColour = Color::FromArgb(128, 255, 0, 0);
		Color boxColourSelected = Color::FromArgb(128, 0, 0, 255);
		Pen^ boxBrush = gcnew Pen(boxColour, 2);
		Pen^ boxBrushSelected = gcnew Pen(boxColourSelected, 2);
		for (int i = 0; i < GUI::loadedImages[imageIndex]->annotationFiles[0]->annotationsPolygonal->Count; i++)
		{
			Pen^ boxBrushCurrent = boxBrush;
			if (i == GroupBox_Annotations->SelectedIndex)
			{
				Pen^ boxBrushCurrent = boxBrushSelected;

			}
			List<int>^ coordinates = GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[i]->vertices;
			Rectangle polygonalAnnotation = Rectangle(CalculatePos(coordinates[0], GUI::xOffset, GUI::imageScale), CalculatePos(coordinates[1], GUI::yOffset, GUI::imageScale), CalculatePos(coordinates[2], GUI::xOffset, GUI::imageScale) - CalculatePos(coordinates[0], GUI::xOffset, GUI::imageScale), CalculatePos(coordinates[3], GUI::yOffset, GUI::imageScale) - CalculatePos(coordinates[1], GUI::yOffset, GUI::imageScale));
			GUI::boxCanvas->DrawRectangle(boxBrush, polygonalAnnotation);
		}
	}
}
