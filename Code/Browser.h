#pragma once
#include "Display.h"
#include <windows.h>

namespace ProjectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Browser
	/// </summary>
	public ref class Browser : public System::Windows::Forms::Form
	{
	public:
		Browser(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			searcher = new myutility();
			store = new Trie();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Browser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ searchBtn;
	private: System::Windows::Forms::TextBox^ searchTB;


	private: System::Windows::Forms::Button^ urlBtn;
	private: System::Windows::Forms::TextBox^ urlTb;
	private: System::Windows::Forms::Label^ logoLbl;
	private: System::Windows::Forms::Label^ label1;
	protected:
		myutility* searcher;
		Trie* store;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Browser::typeid));
			this->searchBtn = (gcnew System::Windows::Forms::Button());
			this->searchTB = (gcnew System::Windows::Forms::TextBox());
			this->urlBtn = (gcnew System::Windows::Forms::Button());
			this->urlTb = (gcnew System::Windows::Forms::TextBox());
			this->logoLbl = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// searchBtn
			// 
			this->searchBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchBtn->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchBtn->Location = System::Drawing::Point(434, 310);
			this->searchBtn->Name = L"searchBtn";
			this->searchBtn->Size = System::Drawing::Size(108, 32);
			this->searchBtn->TabIndex = 0;
			this->searchBtn->Text = L"Search";
			this->searchBtn->UseVisualStyleBackColor = true;
			this->searchBtn->Click += gcnew System::EventHandler(this, &Browser::searchBtn_Click);
			// 
			// searchTB
			// 
			this->searchTB->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchTB->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->searchTB->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->searchTB->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->searchTB->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTB->Location = System::Drawing::Point(256, 278);
			this->searchTB->Name = L"searchTB";
			this->searchTB->Size = System::Drawing::Size(457, 26);
			this->searchTB->TabIndex = 1;
			// 
			// urlBtn
			// 
			this->urlBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"urlBtn.Image")));
			this->urlBtn->Location = System::Drawing::Point(96, 12);
			this->urlBtn->Name = L"urlBtn";
			this->urlBtn->Size = System::Drawing::Size(35, 36);
			this->urlBtn->TabIndex = 4;
			this->urlBtn->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->urlBtn->UseVisualStyleBackColor = true;
			this->urlBtn->Click += gcnew System::EventHandler(this, &Browser::urlBtn_Click);
			// 
			// urlTb
			// 
			this->urlTb->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->urlTb->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->urlTb->ForeColor = System::Drawing::SystemColors::Info;
			this->urlTb->Location = System::Drawing::Point(137, 15);
			this->urlTb->Name = L"urlTb";
			this->urlTb->Size = System::Drawing::Size(790, 29);
			this->urlTb->TabIndex = 5;
			// 
			// logoLbl
			// 
			this->logoLbl->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logoLbl.Image")));
			this->logoLbl->Location = System::Drawing::Point(256, 108);
			this->logoLbl->Name = L"logoLbl";
			this->logoLbl->Size = System::Drawing::Size(457, 153);
			this->logoLbl->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 36);
			this->label1->TabIndex = 11;
			// 
			// Browser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(949, 468);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->logoLbl);
			this->Controls->Add(this->urlTb);
			this->Controls->Add(this->urlBtn);
			this->Controls->Add(this->searchTB);
			this->Controls->Add(this->searchBtn);
			this->Name = L"Browser";
			this->Text = L"Browser";
			this->Load += gcnew System::EventHandler(this, &Browser::Browser_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void searchBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Display^ form = gcnew Display(searcher, store, searchTB->Text);
		form->Show();
	}
	private: System::Void Browser_Load(System::Object^ sender, System::EventArgs^ e) {
		searcher->read_directory("D:\\NUST\\4th Semester\\DSA\\Root", *store);
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
};
}
