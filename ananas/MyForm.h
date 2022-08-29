#include "RSAForm.h"
#pragma once


namespace ananas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ RSAButton;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->RSAButton = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// RSAButton
			// 
			this->RSAButton->Location = System::Drawing::Point(23, 22);
			this->RSAButton->Name = L"RSAButton";
			this->RSAButton->Size = System::Drawing::Size(147, 59);
			this->RSAButton->TabIndex = 0;
			this->RSAButton->Text = L"RSA";
			this->RSAButton->UseVisualStyleBackColor = true;
			this->RSAButton->Click += gcnew System::EventHandler(this, &MyForm::RSAButton_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(212, 22);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(147, 59);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Акростих";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(391, 22);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(147, 59);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Транспозиция";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(23, 113);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(147, 59);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Шифр Виженера";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(212, 113);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(147, 59);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Шифр Цезаря";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(391, 113);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(147, 59);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Многоалфавитная замена";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(23, 198);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(147, 59);
			this->button7->TabIndex = 6;
			this->button7->Text = L"ROT1";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(212, 198);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(147, 59);
			this->button8->TabIndex = 7;
			this->button8->Text = L"Шифр Бейла";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(391, 198);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(147, 59);
			this->button9->TabIndex = 8;
			this->button9->Text = L"Азбука морзе";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(556, 275);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->RSAButton);
			this->Name = L"MyForm";
			this->Text = L"Ananas";
			this->ResumeLayout(false);

		}
#pragma endregion

		//КНОПКА RSA
		System::Void MyForm::RSAButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			RSAForm^ f2 = gcnew RSAForm();
			f2->Show();
		}
};
}
