#pragma once
#include<vector>
#include "Source.cpp"
#include <msclr/marshal_cppstd.h>
#include<stack>

namespace ProjectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for Display
	/// </summary>
	public ref class Display : public System::Windows::Forms::Form
	{
	public:
		Display(myutility* t, Trie* s, System::String^ q)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			resLabels = gcnew List<Label^>();
			store = new Trie(*s);
			*searcher = *t;
			query = q;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Display()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ urlTb;
	protected:
	private: System::Windows::Forms::Button^ urlBtn;
	private: System::Windows::Forms::Button^ fwdBtn;
	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::Label^ logoLbl;
	private: System::Windows::Forms::TextBox^ searchTB;
	private: System::Windows::Forms::Button^ searchBtn;
	private: System::Windows::Forms::Panel^ resultsPnl;
		   List<Label^>^ resLabels;
		   Trie* store;
		   myutility* searcher;
		   System::String^ query;
		   

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Display::typeid));
			this->urlTb = (gcnew System::Windows::Forms::TextBox());
			this->urlBtn = (gcnew System::Windows::Forms::Button());
			this->fwdBtn = (gcnew System::Windows::Forms::Button());
			this->backBtn = (gcnew System::Windows::Forms::Button());
			this->logoLbl = (gcnew System::Windows::Forms::Label());
			this->searchTB = (gcnew System::Windows::Forms::TextBox());
			this->searchBtn = (gcnew System::Windows::Forms::Button());
			this->resultsPnl = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// urlTb
			// 
			this->urlTb->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->urlTb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->urlTb->ForeColor = System::Drawing::SystemColors::Info;
			this->urlTb->Location = System::Drawing::Point(138, 12);
			this->urlTb->Name = L"urlTb";
			this->urlTb->Size = System::Drawing::Size(790, 29);
			this->urlTb->TabIndex = 9;
			// 
			// urlBtn
			// 
			this->urlBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"urlBtn.Image")));
			this->urlBtn->Location = System::Drawing::Point(97, 9);
			this->urlBtn->Name = L"urlBtn";
			this->urlBtn->Size = System::Drawing::Size(35, 36);
			this->urlBtn->TabIndex = 8;
			this->urlBtn->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->urlBtn->UseVisualStyleBackColor = true;
			this->urlBtn->Click += gcnew System::EventHandler(this, &Display::urlBtn_Click);
			// 
			// fwdBtn
			// 
			this->fwdBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fwdBtn.Image")));
			this->fwdBtn->Location = System::Drawing::Point(55, 9);
			this->fwdBtn->Name = L"fwdBtn";
			this->fwdBtn->Size = System::Drawing::Size(36, 36);
			this->fwdBtn->TabIndex = 7;
			this->fwdBtn->UseVisualStyleBackColor = true;
			// 
			// backBtn
			// 
			this->backBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"backBtn.Image")));
			this->backBtn->Location = System::Drawing::Point(13, 9);
			this->backBtn->Name = L"backBtn";
			this->backBtn->Size = System::Drawing::Size(37, 36);
			this->backBtn->TabIndex = 6;
			this->backBtn->UseVisualStyleBackColor = true;
			// 
			// logoLbl
			// 
			this->logoLbl->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logoLbl.Image")));
			this->logoLbl->Location = System::Drawing::Point(13, 58);
			this->logoLbl->Name = L"logoLbl";
			this->logoLbl->Size = System::Drawing::Size(119, 38);
			this->logoLbl->TabIndex = 10;
			// 
			// searchTB
			// 
			this->searchTB->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->searchTB->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->searchTB->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->searchTB->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTB->Location = System::Drawing::Point(138, 58);
			this->searchTB->Name = L"searchTB";
			this->searchTB->Size = System::Drawing::Size(370, 26);
			this->searchTB->TabIndex = 11;
			// 
			// searchBtn
			// 
			this->searchBtn->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->searchBtn->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchBtn->Location = System::Drawing::Point(514, 58);
			this->searchBtn->Name = L"searchBtn";
			this->searchBtn->Size = System::Drawing::Size(84, 26);
			this->searchBtn->TabIndex = 12;
			this->searchBtn->Text = L"Search";
			this->searchBtn->UseVisualStyleBackColor = false;
			this->searchBtn->Click += gcnew System::EventHandler(this, &Display::searchBtn_Click);
			// 
			// resultsPnl
			// 
			this->resultsPnl->AllowDrop = true;
			this->resultsPnl->AutoScroll = true;
			this->resultsPnl->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->resultsPnl->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultsPnl->Location = System::Drawing::Point(13, 110);
			this->resultsPnl->Name = L"resultsPnl";
			this->resultsPnl->Size = System::Drawing::Size(920, 350);
			this->resultsPnl->TabIndex = 13;
			// 
			// Display
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(949, 468);
			this->Controls->Add(this->resultsPnl);
			this->Controls->Add(this->searchBtn);
			this->Controls->Add(this->searchTB);
			this->Controls->Add(this->logoLbl);
			this->Controls->Add(this->urlTb);
			this->Controls->Add(this->urlBtn);
			this->Controls->Add(this->fwdBtn);
			this->Controls->Add(this->backBtn);
			this->Name = L"Display";
			this->Text = L"Display";
			this->Load += gcnew System::EventHandler(this, &Display::Display_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Display_Load(System::Object^ sender, System::EventArgs^ e) {
		System::String^ inp = query;
		std::string toParse = msclr::interop::marshal_as<std::string>(inp);
		std::vector<mypairs> ret = searcher->ParseQuery(toParse, *store);

		int results = ret.size();
		int yOffset = 20;
		for (int i = 0; i < results; i++) {
			Label^ lbl = gcnew Label;
			lbl->Text = msclr::interop::marshal_as<System::String^>(ret[i].getName());
			lbl->ForeColor = System::Drawing::Color::White;
			lbl->Location = Point(10, yOffset);
			lbl->Size = System::Drawing::Size(100, 30);
			lbl->Tag = "D:\\NUST\\4th Semester\\DSA\\Root\\" + lbl->Text;
			lbl->Click += gcnew EventHandler(this, &Display::Label_Click);
			yOffset += 35; // Adjust the y offset for next label
			resultsPnl->Controls->Add(lbl);
			resLabels->Add(lbl);
		}
	}
	private: System::Void urlBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Convert System::String to std::wstring directly
		std::wstring filePath = msclr::interop::marshal_as<std::wstring>(urlTb->Text);

		// Use ShellExecute to open the file or URL with the default viewer
		HINSTANCE result = ShellExecute(NULL, L"open", filePath.c_str(), NULL, NULL, SW_SHOW);

		if ((int)result <= 32) {
			MessageBox::Show("Incorrect Path or File does not Exist!", "File Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void searchBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	resultsPnl->Controls->Clear();
	System::String^ inp = searchTB->Text;
	std::string toParse = msclr::interop::marshal_as<std::string>(inp);
	std::vector<mypairs> ret = searcher->ParseQuery(toParse, *store);

	int results = ret.size();
	int yOffset = 20;
	for (int i = 0; i < results; i++) {
		Label^ lbl = gcnew Label;
		lbl->Text = msclr::interop::marshal_as<System::String^>(ret[i].getName());
		lbl->ForeColor = System::Drawing::Color::White;
		lbl->Location = Point(10, yOffset);
		lbl->Size = System::Drawing::Size(100, 30); 
		lbl->Tag = "D:\\NUST\\4th Semester\\DSA\\Root\\" + lbl->Text; 
		lbl->Click += gcnew EventHandler(this, &Display::Label_Click);
		yOffset += 35; // Adjust the y offset for next label
		resultsPnl->Controls->Add(lbl);
		resLabels->Add(lbl);

	}
}

    void Display::Label_Click(Object^ sender, EventArgs^ e) {
	  Label^ lbl = dynamic_cast<Label^>(sender);
	  String^ filePath = dynamic_cast<String^>(lbl->Tag);

	  String^ wstrInp = dynamic_cast<String^>(lbl->Tag);
	  std::wstring filePath_ = msclr::interop::marshal_as<std::wstring>(wstrInp);
	  HINSTANCE result = ShellExecute(NULL, L"open", filePath_.c_str(), NULL, NULL, SW_SHOW);
		 if ((int)result <= 32) {
			 MessageBox::Show("Incorrect Path or File does not Exist!", "File Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		 }
	}
};
}
