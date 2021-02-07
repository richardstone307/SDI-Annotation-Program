#pragma once
#include <string>;
#include "ImageData.h"
#include "GlobalImageList.h"
#include <filesystem>
#include "Annotation.h"
#include "AnnotationFile.h"
#include "ImageFile.h"
#include "GUI.h"
#include "JSONparsing.h"
#include "PositionCalculation.h"
#include "ResizeAnnotation.h"


namespace SDIMaster
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace GlobalList;
	using namespace PositionCalculation;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	protected:


	public: System::Windows::Forms::PictureBox^ imageDisplay;


	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	public: System::Windows::Forms::ListBox^ GroupBox_Images;
	private:










	private: System::Windows::Forms::SplitContainer^ splitContainer3;
	private: System::Windows::Forms::GroupBox^ classescontainer;

	private: System::Windows::Forms::Button^ Button_RemoveClass;


	private: System::Windows::Forms::Button^ Button_AddClass;


	private: System::Windows::Forms::Button^ Button_LoadClasses;
	public: System::Windows::Forms::ListBox^ GroupBox_Classes;
	private:








	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ buttonRemoveAnnotation;
	public: System::Windows::Forms::ListBox^ GroupBox_Annotations;
	private:










	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ Combobox_SortImages;
	private: System::Windows::Forms::Label^ Label_FolderPath;
	private: System::Windows::Forms::Button^ Button_ChangeDir;
	private: System::Windows::Forms::TextBox^ TextBox_ClassName;
	private: System::Windows::Forms::TextBox^ TextBox_SearchImages;

	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::ComboBox^ ComboBox_SortClasses;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ TextBox_SearchClasses;
	private: System::Windows::Forms::ComboBox^ ComboBox_ToolSelection;
	private: System::Windows::Forms::Button^ Button_SaveAnnotations;
	private: System::Windows::Forms::Button^ Button_LoadAnnotations;
	private: System::Windows::Forms::Label^ Label_AnnotationPath;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ NumericBox_YScale;
	private: System::Windows::Forms::NumericUpDown^ NumericBox_XScale;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ NumericBox_YScale2;
	private: System::Windows::Forms::NumericUpDown^ NumericBox_XScale2;
private: System::Windows::Forms::Button^ Button_ResizeConfirm;
private: System::Windows::Forms::Timer^ Timer_AutosaveTimer;
private: System::Windows::Forms::Label^ Label_Autosave;
private: System::ComponentModel::IContainer^ components;




	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->TextBox_SearchImages = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Button_ChangeDir = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Combobox_SortImages = (gcnew System::Windows::Forms::ComboBox());
			this->Label_FolderPath = (gcnew System::Windows::Forms::Label());
			this->GroupBox_Images = (gcnew System::Windows::Forms::ListBox());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->classescontainer = (gcnew System::Windows::Forms::GroupBox());
			this->TextBox_SearchClasses = (gcnew System::Windows::Forms::TextBox());
			this->ComboBox_SortClasses = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->TextBox_ClassName = (gcnew System::Windows::Forms::TextBox());
			this->Button_RemoveClass = (gcnew System::Windows::Forms::Button());
			this->Button_AddClass = (gcnew System::Windows::Forms::Button());
			this->Button_LoadClasses = (gcnew System::Windows::Forms::Button());
			this->GroupBox_Classes = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->Button_ResizeConfirm = (gcnew System::Windows::Forms::Button());
			this->NumericBox_YScale2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->NumericBox_XScale2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->NumericBox_YScale = (gcnew System::Windows::Forms::NumericUpDown());
			this->NumericBox_XScale = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->buttonRemoveAnnotation = (gcnew System::Windows::Forms::Button());
			this->GroupBox_Annotations = (gcnew System::Windows::Forms::ListBox());
			this->Label_Autosave = (gcnew System::Windows::Forms::Label());
			this->Label_AnnotationPath = (gcnew System::Windows::Forms::Label());
			this->Button_SaveAnnotations = (gcnew System::Windows::Forms::Button());
			this->Button_LoadAnnotations = (gcnew System::Windows::Forms::Button());
			this->ComboBox_ToolSelection = (gcnew System::Windows::Forms::ComboBox());
			this->imageDisplay = (gcnew System::Windows::Forms::PictureBox());
			this->Timer_AutosaveTimer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->classescontainer->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericBox_YScale2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericBox_XScale2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericBox_YScale))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericBox_XScale))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageDisplay))->BeginInit();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(2);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->splitContainer2);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->Label_Autosave);
			this->splitContainer1->Panel2->Controls->Add(this->Label_AnnotationPath);
			this->splitContainer1->Panel2->Controls->Add(this->Button_SaveAnnotations);
			this->splitContainer1->Panel2->Controls->Add(this->Button_LoadAnnotations);
			this->splitContainer1->Panel2->Controls->Add(this->ComboBox_ToolSelection);
			this->splitContainer1->Panel2->Controls->Add(this->imageDisplay);
			this->splitContainer1->Size = System::Drawing::Size(979, 642);
			this->splitContainer1->SplitterDistance = 317;
			this->splitContainer1->SplitterWidth = 3;
			this->splitContainer1->TabIndex = 0;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Margin = System::Windows::Forms::Padding(2);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->tableLayoutPanel2);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->splitContainer3);
			this->splitContainer2->Size = System::Drawing::Size(317, 642);
			this->splitContainer2->SplitterDistance = 187;
			this->splitContainer2->SplitterWidth = 3;
			this->splitContainer2->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(317, 187);
			this->tableLayoutPanel2->TabIndex = 8;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->TextBox_SearchImages);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->Button_ChangeDir);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->Combobox_SortImages);
			this->groupBox1->Controls->Add(this->Label_FolderPath);
			this->groupBox1->Controls->Add(this->GroupBox_Images);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(2, 2);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(313, 183);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Images";
			// 
			// TextBox_SearchImages
			// 
			this->TextBox_SearchImages->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->TextBox_SearchImages->Location = System::Drawing::Point(151, 154);
			this->TextBox_SearchImages->Name = L"TextBox_SearchImages";
			this->TextBox_SearchImages->Size = System::Drawing::Size(161, 20);
			this->TextBox_SearchImages->TabIndex = 6;
			this->TextBox_SearchImages->TextChanged += gcnew System::EventHandler(this, &MainWindow::TextBox_SearchImages_TextChanged);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 158);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Search:";
			// 
			// Button_ChangeDir
			// 
			this->Button_ChangeDir->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Button_ChangeDir->Location = System::Drawing::Point(201, 14);
			this->Button_ChangeDir->Name = L"Button_ChangeDir";
			this->Button_ChangeDir->Size = System::Drawing::Size(111, 23);
			this->Button_ChangeDir->TabIndex = 4;
			this->Button_ChangeDir->Text = L"Change Directory";
			this->Button_ChangeDir->UseVisualStyleBackColor = true;
			this->Button_ChangeDir->Click += gcnew System::EventHandler(this, &MainWindow::Button_ChangeDir_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 130);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Sort:";
			// 
			// Combobox_SortImages
			// 
			this->Combobox_SortImages->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Combobox_SortImages->FormattingEnabled = true;
			this->Combobox_SortImages->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Name ⯅", L"Name ⯆" });
			this->Combobox_SortImages->Location = System::Drawing::Point(218, 127);
			this->Combobox_SortImages->Name = L"Combobox_SortImages";
			this->Combobox_SortImages->Size = System::Drawing::Size(94, 21);
			this->Combobox_SortImages->TabIndex = 2;
			this->Combobox_SortImages->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::Combobox_SortImages_SelectedIndexChanged);
			// 
			// Label_FolderPath
			// 
			this->Label_FolderPath->AutoSize = true;
			this->Label_FolderPath->Location = System::Drawing::Point(5, 19);
			this->Label_FolderPath->Name = L"Label_FolderPath";
			this->Label_FolderPath->Size = System::Drawing::Size(32, 13);
			this->Label_FolderPath->TabIndex = 1;
			this->Label_FolderPath->Text = L"Path:";
			// 
			// GroupBox_Images
			// 
			this->GroupBox_Images->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GroupBox_Images->FormattingEnabled = true;
			this->GroupBox_Images->Location = System::Drawing::Point(4, 39);
			this->GroupBox_Images->Margin = System::Windows::Forms::Padding(2);
			this->GroupBox_Images->Name = L"GroupBox_Images";
			this->GroupBox_Images->Size = System::Drawing::Size(307, 82);
			this->GroupBox_Images->TabIndex = 0;
			this->GroupBox_Images->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::GroupBox_Images_SelectedIndexChanged);
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->Location = System::Drawing::Point(0, 0);
			this->splitContainer3->Margin = System::Windows::Forms::Padding(2);
			this->splitContainer3->Name = L"splitContainer3";
			this->splitContainer3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->tableLayoutPanel1);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->tableLayoutPanel3);
			this->splitContainer3->Size = System::Drawing::Size(317, 452);
			this->splitContainer3->SplitterDistance = 216;
			this->splitContainer3->SplitterWidth = 3;
			this->splitContainer3->TabIndex = 0;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->classescontainer, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 216)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(317, 216);
			this->tableLayoutPanel1->TabIndex = 8;
			// 
			// classescontainer
			// 
			this->classescontainer->Controls->Add(this->TextBox_SearchClasses);
			this->classescontainer->Controls->Add(this->ComboBox_SortClasses);
			this->classescontainer->Controls->Add(this->label4);
			this->classescontainer->Controls->Add(this->label3);
			this->classescontainer->Controls->Add(this->TextBox_ClassName);
			this->classescontainer->Controls->Add(this->Button_RemoveClass);
			this->classescontainer->Controls->Add(this->Button_AddClass);
			this->classescontainer->Controls->Add(this->Button_LoadClasses);
			this->classescontainer->Controls->Add(this->GroupBox_Classes);
			this->classescontainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->classescontainer->Location = System::Drawing::Point(2, 2);
			this->classescontainer->Margin = System::Windows::Forms::Padding(2);
			this->classescontainer->Name = L"classescontainer";
			this->classescontainer->Padding = System::Windows::Forms::Padding(2);
			this->classescontainer->Size = System::Drawing::Size(313, 212);
			this->classescontainer->TabIndex = 6;
			this->classescontainer->TabStop = false;
			this->classescontainer->Text = L"Classes";
			// 
			// TextBox_SearchClasses
			// 
			this->TextBox_SearchClasses->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->TextBox_SearchClasses->Location = System::Drawing::Point(147, 183);
			this->TextBox_SearchClasses->Name = L"TextBox_SearchClasses";
			this->TextBox_SearchClasses->Size = System::Drawing::Size(161, 20);
			this->TextBox_SearchClasses->TabIndex = 7;
			this->TextBox_SearchClasses->TextChanged += gcnew System::EventHandler(this, &MainWindow::TextBox_SearchClasses_TextChanged);
			// 
			// ComboBox_SortClasses
			// 
			this->ComboBox_SortClasses->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->ComboBox_SortClasses->FormattingEnabled = true;
			this->ComboBox_SortClasses->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Name ⯅", L"Name ⯆" });
			this->ComboBox_SortClasses->Location = System::Drawing::Point(214, 157);
			this->ComboBox_SortClasses->Name = L"ComboBox_SortClasses";
			this->ComboBox_SortClasses->Size = System::Drawing::Size(94, 21);
			this->ComboBox_SortClasses->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 190);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Search:";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 163);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Sort:";
			// 
			// TextBox_ClassName
			// 
			this->TextBox_ClassName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->TextBox_ClassName->Location = System::Drawing::Point(7, 132);
			this->TextBox_ClassName->Name = L"TextBox_ClassName";
			this->TextBox_ClassName->Size = System::Drawing::Size(120, 20);
			this->TextBox_ClassName->TabIndex = 7;
			// 
			// Button_RemoveClass
			// 
			this->Button_RemoveClass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Button_RemoveClass->AutoSize = true;
			this->Button_RemoveClass->Location = System::Drawing::Point(220, 129);
			this->Button_RemoveClass->Margin = System::Windows::Forms::Padding(2);
			this->Button_RemoveClass->Name = L"Button_RemoveClass";
			this->Button_RemoveClass->Size = System::Drawing::Size(91, 23);
			this->Button_RemoveClass->TabIndex = 6;
			this->Button_RemoveClass->Text = L"Remove Class";
			this->Button_RemoveClass->UseVisualStyleBackColor = true;
			this->Button_RemoveClass->Click += gcnew System::EventHandler(this, &MainWindow::Button_RemoveClass_Click);
			// 
			// Button_AddClass
			// 
			this->Button_AddClass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Button_AddClass->AutoSize = true;
			this->Button_AddClass->Location = System::Drawing::Point(132, 130);
			this->Button_AddClass->Margin = System::Windows::Forms::Padding(2);
			this->Button_AddClass->Name = L"Button_AddClass";
			this->Button_AddClass->Size = System::Drawing::Size(84, 23);
			this->Button_AddClass->TabIndex = 5;
			this->Button_AddClass->Text = L"Add Class";
			this->Button_AddClass->UseVisualStyleBackColor = true;
			this->Button_AddClass->Click += gcnew System::EventHandler(this, &MainWindow::Button_AddClass_Click);
			// 
			// Button_LoadClasses
			// 
			this->Button_LoadClasses->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Button_LoadClasses->AutoSize = true;
			this->Button_LoadClasses->Location = System::Drawing::Point(193, 17);
			this->Button_LoadClasses->Margin = System::Windows::Forms::Padding(2);
			this->Button_LoadClasses->Name = L"Button_LoadClasses";
			this->Button_LoadClasses->Size = System::Drawing::Size(110, 23);
			this->Button_LoadClasses->TabIndex = 3;
			this->Button_LoadClasses->Text = L"Change .names File";
			this->Button_LoadClasses->UseVisualStyleBackColor = true;
			this->Button_LoadClasses->Click += gcnew System::EventHandler(this, &MainWindow::Button_LoadClasses_Click);
			// 
			// GroupBox_Classes
			// 
			this->GroupBox_Classes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GroupBox_Classes->FormattingEnabled = true;
			this->GroupBox_Classes->Location = System::Drawing::Point(4, 45);
			this->GroupBox_Classes->Margin = System::Windows::Forms::Padding(2);
			this->GroupBox_Classes->Name = L"GroupBox_Classes";
			this->GroupBox_Classes->Size = System::Drawing::Size(308, 82);
			this->GroupBox_Classes->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->groupBox3, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(317, 233);
			this->tableLayoutPanel3->TabIndex = 9;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->Button_ResizeConfirm);
			this->groupBox3->Controls->Add(this->NumericBox_YScale2);
			this->groupBox3->Controls->Add(this->NumericBox_XScale2);
			this->groupBox3->Controls->Add(this->NumericBox_YScale);
			this->groupBox3->Controls->Add(this->NumericBox_XScale);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->buttonRemoveAnnotation);
			this->groupBox3->Controls->Add(this->GroupBox_Annotations);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(2, 2);
			this->groupBox3->Margin = System::Windows::Forms::Padding(2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(2);
			this->groupBox3->Size = System::Drawing::Size(313, 229);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Annotations";
			// 
			// Button_ResizeConfirm
			// 
			this->Button_ResizeConfirm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Button_ResizeConfirm->Location = System::Drawing::Point(193, 173);
			this->Button_ResizeConfirm->Name = L"Button_ResizeConfirm";
			this->Button_ResizeConfirm->Size = System::Drawing::Size(119, 23);
			this->Button_ResizeConfirm->TabIndex = 12;
			this->Button_ResizeConfirm->Text = L"Resize Annotation";
			this->Button_ResizeConfirm->UseVisualStyleBackColor = true;
			this->Button_ResizeConfirm->Click += gcnew System::EventHandler(this, &MainWindow::Button_ResizeConfirm_Click);
			// 
			// NumericBox_YScale2
			// 
			this->NumericBox_YScale2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->NumericBox_YScale2->Location = System::Drawing::Point(109, 204);
			this->NumericBox_YScale2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 999999, 0, 0, 0 });
			this->NumericBox_YScale2->Name = L"NumericBox_YScale2";
			this->NumericBox_YScale2->Size = System::Drawing::Size(41, 20);
			this->NumericBox_YScale2->TabIndex = 11;
			// 
			// NumericBox_XScale2
			// 
			this->NumericBox_XScale2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->NumericBox_XScale2->Location = System::Drawing::Point(11, 204);
			this->NumericBox_XScale2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 999999, 0, 0, 0 });
			this->NumericBox_XScale2->Name = L"NumericBox_XScale2";
			this->NumericBox_XScale2->Size = System::Drawing::Size(41, 20);
			this->NumericBox_XScale2->TabIndex = 10;
			// 
			// NumericBox_YScale
			// 
			this->NumericBox_YScale->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->NumericBox_YScale->Location = System::Drawing::Point(109, 182);
			this->NumericBox_YScale->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 999999, 0, 0, 0 });
			this->NumericBox_YScale->Name = L"NumericBox_YScale";
			this->NumericBox_YScale->Size = System::Drawing::Size(41, 20);
			this->NumericBox_YScale->TabIndex = 9;
			// 
			// NumericBox_XScale
			// 
			this->NumericBox_XScale->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->NumericBox_XScale->Location = System::Drawing::Point(11, 182);
			this->NumericBox_XScale->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 999999, 0, 0, 0 });
			this->NumericBox_XScale->Name = L"NumericBox_XScale";
			this->NumericBox_XScale->Size = System::Drawing::Size(41, 20);
			this->NumericBox_XScale->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label6->Location = System::Drawing::Point(106, 167);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 20);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Y Scale";
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label5->Location = System::Drawing::Point(10, 166);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(59, 20);
			this->label5->TabIndex = 0;
			this->label5->Text = L"X Scale";
			// 
			// buttonRemoveAnnotation
			// 
			this->buttonRemoveAnnotation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonRemoveAnnotation->AutoSize = true;
			this->buttonRemoveAnnotation->Location = System::Drawing::Point(193, 201);
			this->buttonRemoveAnnotation->Margin = System::Windows::Forms::Padding(2);
			this->buttonRemoveAnnotation->Name = L"buttonRemoveAnnotation";
			this->buttonRemoveAnnotation->Size = System::Drawing::Size(120, 23);
			this->buttonRemoveAnnotation->TabIndex = 6;
			this->buttonRemoveAnnotation->Text = L"Remove Annotation";
			this->buttonRemoveAnnotation->UseVisualStyleBackColor = true;
			this->buttonRemoveAnnotation->Click += gcnew System::EventHandler(this, &MainWindow::buttonRemoveAnnotation_Click);
			// 
			// GroupBox_Annotations
			// 
			this->GroupBox_Annotations->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GroupBox_Annotations->FormattingEnabled = true;
			this->GroupBox_Annotations->Location = System::Drawing::Point(2, 17);
			this->GroupBox_Annotations->Margin = System::Windows::Forms::Padding(2);
			this->GroupBox_Annotations->Name = L"GroupBox_Annotations";
			this->GroupBox_Annotations->Size = System::Drawing::Size(311, 147);
			this->GroupBox_Annotations->TabIndex = 0;
			this->GroupBox_Annotations->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::GroupBox_Annotations_SelectedIndexChanged);
			// 
			// Label_Autosave
			// 
			this->Label_Autosave->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Label_Autosave->AutoSize = true;
			this->Label_Autosave->Location = System::Drawing::Point(13, 534);
			this->Label_Autosave->Name = L"Label_Autosave";
			this->Label_Autosave->Size = System::Drawing::Size(116, 13);
			this->Label_Autosave->TabIndex = 11;
			this->Label_Autosave->Text = L"Last Autosaved: Never";
			// 
			// Label_AnnotationPath
			// 
			this->Label_AnnotationPath->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Label_AnnotationPath->AutoSize = true;
			this->Label_AnnotationPath->Location = System::Drawing::Point(13, 521);
			this->Label_AnnotationPath->Name = L"Label_AnnotationPath";
			this->Label_AnnotationPath->Size = System::Drawing::Size(32, 13);
			this->Label_AnnotationPath->TabIndex = 10;
			this->Label_AnnotationPath->Text = L"Path:";
			// 
			// Button_SaveAnnotations
			// 
			this->Button_SaveAnnotations->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Button_SaveAnnotations->Location = System::Drawing::Point(13, 601);
			this->Button_SaveAnnotations->Name = L"Button_SaveAnnotations";
			this->Button_SaveAnnotations->Size = System::Drawing::Size(102, 23);
			this->Button_SaveAnnotations->TabIndex = 9;
			this->Button_SaveAnnotations->Text = L"Save Annotations";
			this->Button_SaveAnnotations->UseVisualStyleBackColor = true;
			this->Button_SaveAnnotations->Click += gcnew System::EventHandler(this, &MainWindow::Button_SaveAnnotations_Click);
			// 
			// Button_LoadAnnotations
			// 
			this->Button_LoadAnnotations->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Button_LoadAnnotations->Location = System::Drawing::Point(13, 572);
			this->Button_LoadAnnotations->Name = L"Button_LoadAnnotations";
			this->Button_LoadAnnotations->Size = System::Drawing::Size(102, 23);
			this->Button_LoadAnnotations->TabIndex = 8;
			this->Button_LoadAnnotations->Text = L"Load Annotations";
			this->Button_LoadAnnotations->UseVisualStyleBackColor = true;
			this->Button_LoadAnnotations->Click += gcnew System::EventHandler(this, &MainWindow::Button_LoadAnnotations_Click);
			// 
			// ComboBox_ToolSelection
			// 
			this->ComboBox_ToolSelection->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->ComboBox_ToolSelection->FormattingEnabled = true;
			this->ComboBox_ToolSelection->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Create Rectangle", L"Resize" });
			this->ComboBox_ToolSelection->Location = System::Drawing::Point(548, 521);
			this->ComboBox_ToolSelection->Name = L"ComboBox_ToolSelection";
			this->ComboBox_ToolSelection->Size = System::Drawing::Size(105, 21);
			this->ComboBox_ToolSelection->TabIndex = 7;
			// 
			// imageDisplay
			// 
			this->imageDisplay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->imageDisplay->BackColor = System::Drawing::SystemColors::WindowText;
			this->imageDisplay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->imageDisplay->Location = System::Drawing::Point(2, 2);
			this->imageDisplay->Margin = System::Windows::Forms::Padding(2);
			this->imageDisplay->Name = L"imageDisplay";
			this->imageDisplay->Size = System::Drawing::Size(678, 514);
			this->imageDisplay->TabIndex = 6;
			this->imageDisplay->TabStop = false;
			this->imageDisplay->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::imageDisplay_MouseDown);
			this->imageDisplay->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::imageDisplay_MouseUp);
			// 
			// Timer_AutosaveTimer
			// 
			this->Timer_AutosaveTimer->Interval = 60;
			this->Timer_AutosaveTimer->Tick += gcnew System::EventHandler(this, &MainWindow::Timer_AutosaveTimer_Tick);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(979, 642);
			this->Controls->Add(this->splitContainer1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(995, 575);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->classescontainer->ResumeLayout(false);
			this->classescontainer->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericBox_YScale2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericBox_XScale2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericBox_YScale))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NumericBox_XScale))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageDisplay))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	protected: System::String^ SaveFile(String^);
			 //Open a file dialogue to save a file

	protected: System::Void BrowseFolder();
			 //Browse for a folder of images

	protected: System::Void LoadFolder(String^);
			 //Loop through the contents of a folder and load supported image files

	protected: System::Void AddImage(String^);
			 //Create a new image object and add it to the list

	protected: System::String^ BrowseFile(String^);
			 //Browse for a single file (classes only)

	protected: System::Void ClearImages();
			 //Clear image list

	protected: System::Void ClearClasses();
			 //Clear class list

	protected: System::Void LoadClasses(String^);
			 //Load classes from a file

	protected: System::Void AddClass(String^);
			 //Add a class to the list

	protected: System::Void RemoveClass(int);
			 //Remove a class from the list

	protected: System::Void WriteClass(String^);
			 //Append a class to the file

	protected: System::Void RemovePolygonalAnnotation(int, int);
			 //Remove a square annotation

	protected: System::Void RenderAnnotations(int);
			 //Render currently loaded image and annotation

	protected: System::Void ListAnnotations();

	protected: System::Void SortImageByName(String^);
			 //Sort the files in the image pane by their name (ascending or descending)

	protected: System::Void SortImageByDate(String^);
			 //Sort the files in the image pane by their date modified (ascending or descending)

	protected: System::Void SortClassPane(String^);
			 //Sort the items in the class pane by their name (ascending or descending)

	// Functions below cannot currently be moved out of header - cannot add more arguments (ie the MainWindow) as they use eventhandlers



	private: System::Void imageDisplay_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (ComboBox_ToolSelection->SelectedIndex == 0)
		{
			if (GUI::loadedImages->Count > 0 && GUI::labelNames->Count > 0 && GroupBox_Classes->SelectedIndex >= 0) {
				GUI::mouseDownLocation = e->Location;

				if (GUI::loadedImages->Count == 0)
				{
					GUI::loadedImages->Add(gcnew ImageFile);
				}

				if (GUI::loadedImages[GUI::drawnImage]->annotationFiles->Count == 0)
				{
					GUI::loadedImages[GUI::drawnImage]->annotationFiles->Add(gcnew AnnotationFile);
				}
			}
		}
		else {
			FindSelectedAnnotation(e->Location);
		}
	}

	private: System::Void imageDisplay_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (GUI::loadedImages->Count > 0 && GUI::labelNames->Count > 0 && GroupBox_Classes->SelectedIndex >= 0) {
			List<int>^ tempVertices = gcnew List<int>;
			Point mouseUpLocation = e->Location;
			Point^ mouseDownLocation = GUI::mouseDownLocation;
			int mouseUpX = mouseDownLocation->X;
			int mouseUpY = mouseDownLocation->Y;
			if (ComboBox_ToolSelection->SelectedIndex == 0) 
			{
				PolygonalAnnotation^ tempAnnotation = gcnew PolygonalAnnotation;
				tempVertices->Add(0);
				tempVertices->Add(0);
				tempVertices->Add(0);
				tempVertices->Add(0);
				if (mouseUpX <= mouseUpLocation.X) {
					tempVertices[0] = (CalculatePosInverse(mouseUpX, GUI::xOffset, GUI::imageScale));
					tempVertices[2] = (CalculatePosInverse(mouseUpLocation.X, GUI::xOffset, GUI::imageScale));
				}
				else {
					tempVertices[2] = (CalculatePosInverse(mouseUpX, GUI::xOffset, GUI::imageScale));
					tempVertices[0] = (CalculatePosInverse(mouseUpLocation.X, GUI::xOffset, GUI::imageScale));
				}

				if (mouseUpY <= mouseUpLocation.Y) {
					tempVertices[1] = (CalculatePosInverse(mouseUpY, GUI::yOffset, GUI::imageScale));
					tempVertices[3] = (CalculatePosInverse(mouseUpLocation.Y, GUI::yOffset, GUI::imageScale));
				}
				else {
					tempVertices[3] = (CalculatePosInverse(mouseUpY, GUI::yOffset, GUI::imageScale));
					tempVertices[1] = (CalculatePosInverse(mouseUpLocation.Y, GUI::yOffset, GUI::imageScale));
				}
				tempAnnotation->vertices = tempVertices;
				tempAnnotation->label = GUI::labelNames[GUI::labelIndices[GroupBox_Classes->SelectedIndex]];
				GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal->Add(tempAnnotation);
				RenderAnnotations(GUI::drawnImage);
				ListAnnotations();
			}
			else 
			{
				ResizeAnnotation(e->Location);
				RenderAnnotations(GUI::drawnImage);
				ListAnnotations();
			}
		}
	}

	private: System::Void Button_ChangeDir_Click(System::Object^ sender, System::EventArgs^ e) {
		BrowseFolder();
		if (Combobox_SortImages->SelectedIndex == 0)
		{
			SortImageByName("ASCENDING");
		}
		else
		{
			SortImageByName("DESCENDING");
		}
		Label_FolderPath->Text = "Path: " + GUI::workingFolderPath;
	}

	private: System::Void Button_LoadClasses_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ namesPath = gcnew String(BrowseFile(".names file (*.names)|*.names"));
		GUI::labelFile = namesPath;
		ClearClasses();
		LoadClasses(namesPath);
		SortClassPane("B");
	}
	private: System::Void GroupBox_Images_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (GroupBox_Images->SelectedIndex > -1) {
			GUI::drawnImage = GUI::imageIndices[GroupBox_Images->SelectedIndex];
			RenderAnnotations(GUI::drawnImage);
			ListAnnotations();
		}
	}

	private: System::Void Button_AddClass_Click(System::Object^ sender, System::EventArgs^ e) {
		if (GUI::labelFile != "") {
			AddClass(TextBox_ClassName->Text);
			TextBox_ClassName->Text = "";
			SortClassPane("B");
		}
	}

	private: System::Void Button_RemoveClass_Click(System::Object^ sender, System::EventArgs^ e) {
		RemoveClass(GUI::labelIndices[GroupBox_Classes->SelectedIndex]);
		SortClassPane("B");
		RenderAnnotations(GUI::drawnImage);
		ListAnnotations();
	}

	private: System::Void buttonRemoveAnnotation_Click(System::Object^ sender, System::EventArgs^ e) {
		if (GroupBox_Annotations->SelectedIndex >= 0) {
			RemovePolygonalAnnotation(GUI::drawnImage, GroupBox_Annotations->SelectedIndex);
			RenderAnnotations(GUI::drawnImage);
			ListAnnotations();
		}
	}

	private: System::Void TextBox_SearchImages_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		GUI::imageSearchTerm = TextBox_SearchImages->Text;
		if (Combobox_SortImages->SelectedIndex == 0)
		{
			SortImageByName("ASCENDING");
		}
		else
		{
			SortImageByName("DESCENDING");
		}
	}

	private: System::Void TextBox_SearchClasses_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		GUI::labelSearchTerm = TextBox_SearchClasses->Text;
		SortClassPane("A");
	}
	private: System::Void Button_SaveAnnotations_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filePath = SaveFile(".ANNOTATIONS file (*.annotations)|*.annotations");
		if (filePath != "")
		{
			SaveJson(SystemToStdString(filePath));
			GUI::annotationFilePath = filePath;
			Label_AnnotationPath->Text = GUI::annotationFilePath;
		}
	}

	private: System::Void Button_LoadAnnotations_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filePath = BrowseFile(".ANNOTATIONS file (*.annotations)|*.annotations");
		if (filePath != "") 
		{
			LoadJson(SystemToStdString(filePath));
			GUI::annotationFilePath = filePath;
			Label_AnnotationPath->Text = "Path: " + GUI::annotationFilePath;
		}
		
	}
	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
		ComboBox_ToolSelection->SelectedIndex = 0;
		Timer_AutosaveTimer->Start();
	}

	private: System::Void GroupBox_Annotations_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		NumericBox_XScale->Value = GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[GroupBox_Annotations->SelectedIndex]->vertices[0];
		NumericBox_YScale->Value = GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[GroupBox_Annotations->SelectedIndex]->vertices[2];
		NumericBox_XScale2->Value = GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[GroupBox_Annotations->SelectedIndex]->vertices[1];
		NumericBox_YScale2->Value = GUI::loadedImages[GUI::drawnImage]->annotationFiles[0]->annotationsPolygonal[GroupBox_Annotations->SelectedIndex]->vertices[3];
		RenderAnnotations(GUI::drawnImage);
	}

	private: System::Void Button_ResizeConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
		if (GroupBox_Annotations->SelectedIndex >= 0)
		{
		QuickResizeAnnotation(GroupBox_Annotations->SelectedIndex, 0, Decimal::ToInt32(NumericBox_XScale->Value));
		QuickResizeAnnotation(GroupBox_Annotations->SelectedIndex, 2, Decimal::ToInt32(NumericBox_YScale->Value));
		QuickResizeAnnotation(GroupBox_Annotations->SelectedIndex, 1, Decimal::ToInt32(NumericBox_XScale2->Value));
		QuickResizeAnnotation(GroupBox_Annotations->SelectedIndex, 3, Decimal::ToInt32(NumericBox_YScale2->Value));
		RenderAnnotations(GUI::drawnImage);
		ListAnnotations();
		}
	}


	private: System::Void Combobox_SortImages_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Combobox_SortImages->SelectedIndex == 0)
		{
			SortImageByName("ASCENDING");
		}
		else
		{
			SortImageByName("DESCENDING");
		}
	}

	private: System::Void Timer_AutosaveTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (GUI::annotationFilePath != "") {
			SaveJson(SystemToStdString(GUI::annotationFilePath));
			Timer_AutosaveTimer->Interval = (60 * 1000); //60 seconds
			DateTime^ tempTime = DateTime::Now;
			Label_Autosave->Text = "Last Autosaved: " + tempTime->ToLongTimeString();
		}
	}
};

}
