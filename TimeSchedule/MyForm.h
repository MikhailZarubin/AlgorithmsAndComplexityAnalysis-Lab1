#pragma once

#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <string>

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Graphics^ gr;
		Pen^ pen, ^penScheduleKruskal, ^penSchedulePrim;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::DataGridView^ dataGridView1;
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->gr = CreateGraphics();
			this->pen = gcnew Pen(Color::Black);
			this->penScheduleKruskal = gcnew Pen(Color::Purple);
			this->penSchedulePrim = gcnew Pen(Color::Red);
			this->penScheduleKruskal->Width = 3.0;
			this->penSchedulePrim->Width = 3.0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
			}
		}


	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				   this->Column1,
					   this->Column2, this->Column3
			   });
			   this->dataGridView1->Location = System::Drawing::Point(296, 614);
			   this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->Size = System::Drawing::Size(587, 185);
			   this->dataGridView1->TabIndex = 1;
			   // 
			   // Column1
			   // 
			   this->Column1->Frozen = true;
			   this->Column1->HeaderText = L"EdgeCount";
			   this->Column1->MinimumWidth = 6;
			   this->Column1->Name = L"Column1";
			   this->Column1->Width = 125;
			   // 
			   // Column2
			   // 
			   this->Column2->Frozen = true;
			   this->Column2->HeaderText = L"ExecutionTimeKruskal";
			   this->Column2->MinimumWidth = 6;
			   this->Column2->Name = L"Column2";
			   this->Column2->Width = 150;
			   // 
			   // Column3
			   // 
			   this->Column3->HeaderText = L"Execution Time Prim";
			   this->Column3->MinimumWidth = 6;
			   this->Column3->Name = L"Column3";
			   this->Column3->Width = 150;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(1000, 498);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(117, 17);
			   this->label1->TabIndex = 2;
			   this->label1->Text = L"EdgeCount";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(80, 62);
			   this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(62, 17);
			   this->label2->TabIndex = 3;
			   this->label2->Text = L"Time, 2c";
			   // 
			   // button1
			   // 
			   this->button1->BackColor = System::Drawing::SystemColors::Window;
			   this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			   this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->button1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			   this->button1->Location = System::Drawing::Point(0, 0);
			   this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(1179, 814);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"Click To Continue";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(536, 550);
			   this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(107, 31);
			   this->button2->TabIndex = 4;
			   this->button2->Text = L"Start Testing";
			   this->button2->UseMnemonic = false;
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Visible = false;
			   this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(1096, 614);
			   this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(55, 17);
			   this->label3->TabIndex = 5;
			   this->label3->Text = L"Kruskal";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(1096, 651);
			   this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(36, 17);
			   this->label4->TabIndex = 7;
			   this->label4->Text = L"Prim";
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::Window;
			   this->ClientSize = System::Drawing::Size(1179, 814);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->dataGridView1);
			   this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Name = L"MyForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"TimeSchedule";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		button1->Visible = false;
		button2->Visible = true;
	}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->button2->Visible = false;

	//get size graf
	std::ifstream fileKruskal("../KruskalData.txt");
	std::ifstream filePrim("../PrimData.txt");
	const int bufferLenght = 250;
	char bufferKruskal[bufferLenght], bufferPrim[bufferLenght];

	fileKruskal.getline(bufferKruskal, bufferLenght, '\n');
	filePrim.getline(bufferPrim, bufferLenght, '\n');

	std::string temporaryString;
	int number = 0, maxEdgeCount = 0, startEdgeCount = 0, stepEdgeCount = 1;
	for (int i = 0; bufferKruskal[i] != '\0'; i++)
	{
		if (bufferKruskal[i] == ' ')
		{
			int value = atoi(temporaryString.c_str());

			if (number == 1)
				maxEdgeCount = value;
			else if (number == 2)
				startEdgeCount = value;

			temporaryString.clear();
			number++;
		}
		else
		{
			temporaryString += bufferKruskal[i];
		}
	}
	stepEdgeCount = atoi(temporaryString.c_str());

	int countEdge = (maxEdgeCount - startEdgeCount) / stepEdgeCount;

	//drawing system coordinates
	gr->DrawLine(pen, 50, 400, 750, 400);
	gr->DrawLine(pen, 50, 400, 50, 50);
	gr->DrawLine(pen, 50, 50, 55, 55);
	gr->DrawLine(pen, 50, 50, 45, 55);
	gr->DrawLine(pen, 750, 400, 745, 395);
	gr->DrawLine(pen, 750, 400, 745, 405);

	int stepX = 700 / countEdge, stepY = 10;

	for (int i = 57; i < 745; i += stepX)
		gr->DrawLine(pen, i, 398, i, 402);

	for (int i = 390; i > 55; i -= stepY)
		gr->DrawLine(pen, 48, i, 52, i);

	this->pen->Width = 4.0;
	gr->DrawEllipse(pen, 48, 398, 4, 4);

	gr->DrawLine(penScheduleKruskal, 785, 506, 815, 506);
	gr->DrawLine(penSchedulePrim, 785, 536, 815, 536);

	for (int i = 0; i < countEdge; i++)
	{
		dataGridView1->Rows->Add();
	}

	//drawing schedule
	int lastPointX = 50, lastPointKruskalY = 400, lastPointPrimY = 400, startPointY = 400, numberRow = 0;
	double timeKruskal, timePrim;
	int numberIter = startEdgeCount;
	while (!fileKruskal.eof() && !filePrim.eof())
	{
		fileKruskal.getline(bufferKruskal, bufferLenght, '\n');
		filePrim.getline(bufferPrim, bufferLenght, '\n');

		timeKruskal = atof(bufferKruskal);
		timePrim = atof(bufferPrim);

		this->dataGridView1->Rows[numberRow]->Cells[0]->Value = numberIter;
		this->dataGridView1->Rows[numberRow]->Cells[1]->Value = timeKruskal;
		this->dataGridView1->Rows[numberRow++]->Cells[2]->Value = timePrim;

		gr->DrawLine(penScheduleKruskal, lastPointX, lastPointKruskalY, lastPointX + stepX, startPointY - timeKruskal * 5.);
		gr->DrawLine(penSchedulePrim, lastPointX, lastPointPrimY, lastPointX + stepX, startPointY - timePrim * 5.);
		lastPointX += stepX;
		lastPointKruskalY = startPointY - timeKruskal * 5.;
		lastPointPrimY = startPointY - timePrim * 5.;

		numberIter += stepEdgeCount;
	}
}
};
}
