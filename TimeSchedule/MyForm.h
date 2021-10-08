#pragma once

#include "Graf.h"
#include "Timer.h"

constexpr int countRows = 101;
constexpr int vertexCount = 10001;
constexpr int minWeightEdge = 1;
constexpr int maxWeightEdge = 1000000;
constexpr int maxEdgeCount = 10000000;
constexpr int edgeStep = 100000;

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
		Pen^ pen, ^penScheduleKruskal;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;




	private: System::Windows::Forms::DataGridView^ dataGridView1;
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->gr = CreateGraphics();
			this->pen = gcnew Pen(Color::Black);
			this->penScheduleKruskal = gcnew Pen(Color::Purple);
			this->penScheduleKruskal->Width = 3.0;

			for (int i = 0; i < countRows ; i++)
			{
				dataGridView1->Rows->Add();
			}
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
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				   this->Column1,
					   this->Column2
			   });
			   this->dataGridView1->Location = System::Drawing::Point(339, 499);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->Size = System::Drawing::Size(240, 150);
			   this->dataGridView1->TabIndex = 1;
			   // 
			   // Column1
			   // 
			   this->Column1->Frozen = true;
			   this->Column1->HeaderText = L"EdgeCount";
			   this->Column1->Name = L"Column1";
			   // 
			   // Column2
			   // 
			   this->Column2->Frozen = true;
			   this->Column2->HeaderText = L"ExecutionTime";
			   this->Column2->Name = L"Column2";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(750, 405);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(90, 13);
			   this->label1->TabIndex = 2;
			   this->label1->Text = L"EdgeCount, 10^5";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(60, 50);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(54, 13);
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
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(884, 661);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"Click To Continue";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(402, 447);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(80, 25);
			   this->button2->TabIndex = 4;
			   this->button2->Text = L"Start Testing";
			   this->button2->UseMnemonic = false;
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Visible = false;
			   this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::Window;
			   this->ClientSize = System::Drawing::Size(884, 661);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->dataGridView1);
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

		gr->DrawLine(pen, 50, 400, 750, 400);
		gr->DrawLine(pen, 50, 400, 50, 50);
		gr->DrawLine(pen, 50, 50, 55, 55);
		gr->DrawLine(pen, 50, 50, 45, 55);
		gr->DrawLine(pen, 750, 400, 745, 395);
		gr->DrawLine(pen, 750, 400, 745, 405);

		GrafTest::Timer timer;
		int stepX = 700 / (maxEdgeCount / edgeStep), stepY = 10;

		for (int i = 57; i <= 750 - stepX; i += stepX)
			gr->DrawLine(pen, i, 398, i, 402);

		for (int i = 390; i >= 50 + stepY; i -= stepY)
			gr->DrawLine(pen, 48, i, 52, i);

		this->pen->Width = 4.0;
		gr->DrawEllipse(pen, 48, 398, 4, 4);
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->button2->Visible = false;

	int lastPointX = 50, lastPointY = 400, startPointY = 400, stepX = 700 / (maxEdgeCount / edgeStep), numberRow = 0;
	GrafTest::Timer timer;

	for (int i = 0; i <= maxEdgeCount; i += edgeStep)
		{
			GrafArray graf(vertexCount, i, minWeightEdge, maxWeightEdge);

			timer.resetTimer();
			graf.KruskalAlgorithm();
			double time = timer.getTime();

			this->dataGridView1->Rows[numberRow]->Cells[0]->Value = i;
			this->dataGridView1->Rows[numberRow++]->Cells[1]->Value = time;

			gr->DrawLine(penScheduleKruskal, lastPointX, lastPointY, lastPointX + stepX, startPointY - time * 5.);
			lastPointX += stepX;
			lastPointY = startPointY - time * 5.;
		}
}
};
}
