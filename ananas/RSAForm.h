#pragma once
#include "RSA.h"
#include "RSAForm.h"
#include <msclr\marshal_cppstd.h>

namespace ananas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class RSAForm : public System::Windows::Forms::Form
	{
	public:
		RSAForm(void)
		{
			InitializeComponent();
		}

	protected:
		~RSAForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(157, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(564, 74);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(32, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Input";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(157, 128);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(564, 74);
			this->textBox2->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(32, 153);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Output";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(282, 469);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(202, 52);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Decrypt";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &RSAForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(533, 469);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(188, 52);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Encrypt";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &RSAForm::button3_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 469);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(215, 52);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Generate keys";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RSAForm::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(157, 238);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(564, 74);
			this->textBox3->TabIndex = 8;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(157, 347);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(564, 74);
			this->textBox4->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(32, 248);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 25);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Private";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(32, 358);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 25);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Public";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(45, 273);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 25);
			this->label5->TabIndex = 12;
			this->label5->Text = L"key";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(45, 383);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 25);
			this->label6->TabIndex = 13;
			this->label6->Text = L"key";
			// 
			// RSAForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 531);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"RSAForm";
			this->Text = L"RSAForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Gen keys button
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{	
		this->Enabled = false;

		boost::multiprecision::uint1024_t max = 100000000000000;
		max = max *max;max = max * max; max = max * max; max = max * max; max = max * max; max = max * max;

		textBox3->Text = "";
		textBox4->Text = "";

		std::vector<boost::multiprecision::uint1024_t> keys = createKeys();

		while(keys[2] > max)
		{
			keys = createKeys();
		}

		std::stringstream sprivate;
		std::stringstream spublic;
		
		std::string privateKey;
		std::string publicKey;

		sprivate << keys[2] << "_" << keys[1];
		spublic << keys[0] << "_" << keys[1];

		privateKey = sprivate.str();
		publicKey = spublic.str();

		String^ privateStr = gcnew String(privateKey.c_str());
		String^ publicStr = gcnew String(publicKey.c_str());

		textBox3->Text = privateStr;
		textBox4->Text = publicStr;
		this->Enabled = true;
	}

	// Decode button
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		textBox2->Text = "";
		std::string result;
		boost::multiprecision::uint1024_t d;
		boost::multiprecision::uint1024_t n;
		
		// Getting input Text
		std::string message;
		message = msclr::interop::marshal_as<std::string>(textBox1->Text->ToString());
		// Getting private key
		std::string key;
		key = msclr::interop::marshal_as<std::string>(textBox3->Text->ToString());
		d = boost::lexical_cast<boost::multiprecision::uint1024_t>(key.substr(0, key.find("_")));
		n = boost::lexical_cast<boost::multiprecision::uint1024_t>(key.substr(key.find("_")+1));

		result = decrypt(message, d, n);

		String^ resultStr = gcnew String(result.c_str());
		textBox2->Text = resultStr;
	}

	// Encrypt button
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{

		textBox2->Text = "";
		std::string result;
		boost::multiprecision::uint1024_t e1;
		boost::multiprecision::uint1024_t n;

		// Getting input Text
		std::string message;
		message = msclr::interop::marshal_as<std::string>(textBox1->Text->ToString());
		// Getting public key
		std::string key;
		key = msclr::interop::marshal_as<std::string>(textBox4->Text->ToString());

		e1 = boost::lexical_cast<boost::multiprecision::uint1024_t>(key.substr(0, key.find("_")));
		n = boost::lexical_cast<boost::multiprecision::uint1024_t>(key.substr(key.find("_")+1));

		result = encrypt(message, e1, n);

		String^ resultStr = gcnew String(result.c_str());
		textBox2->Text = resultStr;
	}


	};
	}