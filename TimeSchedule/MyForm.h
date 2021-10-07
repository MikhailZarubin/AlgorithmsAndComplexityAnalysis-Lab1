#pragma once

#include "Graf.h"
#include "Timer.h"

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
		Pen^ pen, ^penScheduleMaxEdgeCount;
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->gr = CreateGraphics();
			this->pen = gcnew Pen(Color::Black);
			this->penScheduleMaxEdgeCount = gcnew Pen(Color::Purple);
			this->penScheduleMaxEdgeCount->Width = 3.0;
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Button^ button1;

	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // button1
			   // 
			   this->button1->BackColor = System::Drawing::SystemColors::ScrollBar;
			   this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			   this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->button1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			   this->button1->Location = System::Drawing::Point(210, 216);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(147, 23);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"Build a shedule";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::Window;
			   this->ClientSize = System::Drawing::Size(566, 481);
			   this->Controls->Add(this->button1);
			   this->Name = L"MyForm";
			   this->Text = L"TimeSchedule";
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		button1->Visible = false;
		gr->DrawLine(pen, 60, 400, 450, 400);
		gr->DrawLine(pen, 60, 400, 60, 50);
		gr->DrawLine(pen, 60, 50, 65, 55);
		gr->DrawLine(pen, 60, 50, 55, 55);
		gr->DrawLine(pen, 450, 400, 445, 395);
		gr->DrawLine(pen, 450, 400, 445, 405);
		this->pen->Width = 4.0;
		gr->DrawEllipse(pen, 58, 398, 4, 4);
		GrafTest::Timer timer;
		int lastPointX = 60, lastPointY = 400;
		for (int i = 3; i < 10002; i++)
		{
			GrafArray graf (i, i * (i - 1) / 2, 1, i * 100);
			timer.resetTimer();
			graf.KruskalAlgorithm();
			double time = timer.getTime();
			gr->DrawLine(this->penScheduleMaxEdgeCount, lastPointX, lastPointY, lastPointX + i / 80, lastPointY - time * 100);
			lastPointX = lastPointX + i / 8;
			lastPointY = lastPointY - time * 100;
		}
	}
	};
}
