#pragma once

namespace Project {

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
	private: System::Windows::Forms::Button^ button_New_post;
	protected:

	private: System::Windows::Forms::GroupBox^ Panel_New_post;
	private: System::Windows::Forms::Label^ Name_new_post;
	private: System::Windows::Forms::TextBox^ Textbox_Name_new_post;

	private: System::Windows::Forms::Label^ About_new_post;
	private: System::Windows::Forms::TextBox^ Textbox_About_new_post;
	private: System::Windows::Forms::Label^ Date_new_post;
	private: System::Windows::Forms::DateTimePicker^ Swith_date_new_post;
	private: System::Windows::Forms::Label^ view_media;


	private: System::Windows::Forms::ComboBox^ Swith_view_media;
	private: System::Windows::Forms::Label^ Text_New_post;
	private: System::Windows::Forms::Button^ Generation_Continuity_new_post;


	private: System::Windows::Forms::Button^ generation_text_post;

	private: System::Windows::Forms::TextBox^ textBox_Continuity_new_post;

	private: System::Windows::Forms::TextBox^ textBox_Text_New_post;

	private: System::Windows::Forms::Label^ Continuity_new_post;
	private: System::Windows::Forms::Button^ Save_button;
	private: System::Windows::Forms::TableLayoutPanel^ Table_post;

	private: System::Windows::Forms::Label^ Number_post;

	private: int postCounter = 0;
	private: System::Windows::Forms::Label^ Date_post;
	private: System::Windows::Forms::Label^ Text_post;

	private: System::Windows::Forms::Label^ About_post;
	private: System::Windows::Forms::Label^ Name_post;
	private: System::Windows::Forms::Label^ Continuity_post;
	private: System::Windows::Forms::Label^ view_post;
	private: System::Windows::Forms::Label^ Actioin_post;


	protected:


	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button_New_post = (gcnew System::Windows::Forms::Button());
			this->Panel_New_post = (gcnew System::Windows::Forms::GroupBox());
			this->Save_button = (gcnew System::Windows::Forms::Button());
			this->Generation_Continuity_new_post = (gcnew System::Windows::Forms::Button());
			this->generation_text_post = (gcnew System::Windows::Forms::Button());
			this->textBox_Continuity_new_post = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Text_New_post = (gcnew System::Windows::Forms::TextBox());
			this->Continuity_new_post = (gcnew System::Windows::Forms::Label());
			this->Text_New_post = (gcnew System::Windows::Forms::Label());
			this->Swith_view_media = (gcnew System::Windows::Forms::ComboBox());
			this->view_media = (gcnew System::Windows::Forms::Label());
			this->Swith_date_new_post = (gcnew System::Windows::Forms::DateTimePicker());
			this->Date_new_post = (gcnew System::Windows::Forms::Label());
			this->Textbox_About_new_post = (gcnew System::Windows::Forms::TextBox());
			this->About_new_post = (gcnew System::Windows::Forms::Label());
			this->Textbox_Name_new_post = (gcnew System::Windows::Forms::TextBox());
			this->Name_new_post = (gcnew System::Windows::Forms::Label());
			this->Table_post = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Actioin_post = (gcnew System::Windows::Forms::Label());
			this->view_post = (gcnew System::Windows::Forms::Label());
			this->Continuity_post = (gcnew System::Windows::Forms::Label());
			this->Text_post = (gcnew System::Windows::Forms::Label());
			this->About_post = (gcnew System::Windows::Forms::Label());
			this->Name_post = (gcnew System::Windows::Forms::Label());
			this->Number_post = (gcnew System::Windows::Forms::Label());
			this->Date_post = (gcnew System::Windows::Forms::Label());
			this->Panel_New_post->SuspendLayout();
			this->Table_post->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_New_post
			// 
			resources->ApplyResources(this->button_New_post, L"button_New_post");
			this->button_New_post->Name = L"button_New_post";
			this->button_New_post->UseVisualStyleBackColor = true;
			this->button_New_post->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// Panel_New_post
			// 
			resources->ApplyResources(this->Panel_New_post, L"Panel_New_post");
			this->Panel_New_post->Controls->Add(this->Save_button);
			this->Panel_New_post->Controls->Add(this->Generation_Continuity_new_post);
			this->Panel_New_post->Controls->Add(this->generation_text_post);
			this->Panel_New_post->Controls->Add(this->textBox_Continuity_new_post);
			this->Panel_New_post->Controls->Add(this->textBox_Text_New_post);
			this->Panel_New_post->Controls->Add(this->Continuity_new_post);
			this->Panel_New_post->Controls->Add(this->Text_New_post);
			this->Panel_New_post->Controls->Add(this->Swith_view_media);
			this->Panel_New_post->Controls->Add(this->view_media);
			this->Panel_New_post->Controls->Add(this->Swith_date_new_post);
			this->Panel_New_post->Controls->Add(this->Date_new_post);
			this->Panel_New_post->Controls->Add(this->Textbox_About_new_post);
			this->Panel_New_post->Controls->Add(this->About_new_post);
			this->Panel_New_post->Controls->Add(this->Textbox_Name_new_post);
			this->Panel_New_post->Controls->Add(this->Name_new_post);
			this->Panel_New_post->ForeColor = System::Drawing::Color::White;
			this->Panel_New_post->Name = L"Panel_New_post";
			this->Panel_New_post->TabStop = false;
			this->Panel_New_post->Tag = L"New_post";
			this->Panel_New_post->Enter += gcnew System::EventHandler(this, &MyForm::Panel_New_post_Enter);
			// 
			// Save_button
			// 
			resources->ApplyResources(this->Save_button, L"Save_button");
			this->Save_button->ForeColor = System::Drawing::Color::Black;
			this->Save_button->Name = L"Save_button";
			this->Save_button->UseVisualStyleBackColor = true;
			this->Save_button->Click += gcnew System::EventHandler(this, &MyForm::Save_button_Click);
			// 
			// Generation_Continuity_new_post
			// 
			resources->ApplyResources(this->Generation_Continuity_new_post, L"Generation_Continuity_new_post");
			this->Generation_Continuity_new_post->ForeColor = System::Drawing::Color::Black;
			this->Generation_Continuity_new_post->Name = L"Generation_Continuity_new_post";
			this->Generation_Continuity_new_post->UseVisualStyleBackColor = true;
			// 
			// generation_text_post
			// 
			resources->ApplyResources(this->generation_text_post, L"generation_text_post");
			this->generation_text_post->ForeColor = System::Drawing::Color::Black;
			this->generation_text_post->Name = L"generation_text_post";
			this->generation_text_post->UseVisualStyleBackColor = true;
			// 
			// textBox_Continuity_new_post
			// 
			this->textBox_Continuity_new_post->AcceptsReturn = true;
			this->textBox_Continuity_new_post->AcceptsTab = true;
			resources->ApplyResources(this->textBox_Continuity_new_post, L"textBox_Continuity_new_post");
			this->textBox_Continuity_new_post->BackColor = System::Drawing::Color::Gray;
			this->textBox_Continuity_new_post->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_Continuity_new_post->ForeColor = System::Drawing::Color::White;
			this->textBox_Continuity_new_post->Name = L"textBox_Continuity_new_post";
			this->textBox_Continuity_new_post->Tag = L"Name_Project";
			// 
			// textBox_Text_New_post
			// 
			this->textBox_Text_New_post->AcceptsReturn = true;
			this->textBox_Text_New_post->AcceptsTab = true;
			resources->ApplyResources(this->textBox_Text_New_post, L"textBox_Text_New_post");
			this->textBox_Text_New_post->BackColor = System::Drawing::Color::Gray;
			this->textBox_Text_New_post->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_Text_New_post->ForeColor = System::Drawing::Color::White;
			this->textBox_Text_New_post->Name = L"textBox_Text_New_post";
			this->textBox_Text_New_post->Tag = L"Name_Project";
			// 
			// Continuity_new_post
			// 
			resources->ApplyResources(this->Continuity_new_post, L"Continuity_new_post");
			this->Continuity_new_post->Name = L"Continuity_new_post";
			// 
			// Text_New_post
			// 
			resources->ApplyResources(this->Text_New_post, L"Text_New_post");
			this->Text_New_post->Name = L"Text_New_post";
			// 
			// Swith_view_media
			// 
			resources->ApplyResources(this->Swith_view_media, L"Swith_view_media");
			this->Swith_view_media->FormattingEnabled = true;
			this->Swith_view_media->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				resources->GetString(L"Swith_view_media.Items"),
					resources->GetString(L"Swith_view_media.Items1"), resources->GetString(L"Swith_view_media.Items2")
			});
			this->Swith_view_media->Name = L"Swith_view_media";
			// 
			// view_media
			// 
			resources->ApplyResources(this->view_media, L"view_media");
			this->view_media->Name = L"view_media";
			// 
			// Swith_date_new_post
			// 
			resources->ApplyResources(this->Swith_date_new_post, L"Swith_date_new_post");
			this->Swith_date_new_post->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->Swith_date_new_post->Name = L"Swith_date_new_post";
			// 
			// Date_new_post
			// 
			resources->ApplyResources(this->Date_new_post, L"Date_new_post");
			this->Date_new_post->Name = L"Date_new_post";
			// 
			// Textbox_About_new_post
			// 
			this->Textbox_About_new_post->AcceptsReturn = true;
			this->Textbox_About_new_post->AcceptsTab = true;
			resources->ApplyResources(this->Textbox_About_new_post, L"Textbox_About_new_post");
			this->Textbox_About_new_post->BackColor = System::Drawing::Color::Gray;
			this->Textbox_About_new_post->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Textbox_About_new_post->ForeColor = System::Drawing::Color::White;
			this->Textbox_About_new_post->Name = L"Textbox_About_new_post";
			this->Textbox_About_new_post->Tag = L"Name_Project";
			// 
			// About_new_post
			// 
			resources->ApplyResources(this->About_new_post, L"About_new_post");
			this->About_new_post->Name = L"About_new_post";
			// 
			// Textbox_Name_new_post
			// 
			this->Textbox_Name_new_post->AcceptsReturn = true;
			this->Textbox_Name_new_post->AcceptsTab = true;
			resources->ApplyResources(this->Textbox_Name_new_post, L"Textbox_Name_new_post");
			this->Textbox_Name_new_post->BackColor = System::Drawing::Color::Gray;
			this->Textbox_Name_new_post->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Textbox_Name_new_post->ForeColor = System::Drawing::Color::White;
			this->Textbox_Name_new_post->Name = L"Textbox_Name_new_post";
			this->Textbox_Name_new_post->Tag = L"Name_Project";
			// 
			// Name_new_post
			// 
			resources->ApplyResources(this->Name_new_post, L"Name_new_post");
			this->Name_new_post->ForeColor = System::Drawing::Color::White;
			this->Name_new_post->Name = L"Name_new_post";
			// 
			// Table_post
			// 
			resources->ApplyResources(this->Table_post, L"Table_post");
			this->Table_post->Controls->Add(this->Actioin_post, 7, 0);
			this->Table_post->Controls->Add(this->view_post, 6, 0);
			this->Table_post->Controls->Add(this->Continuity_post, 5, 0);
			this->Table_post->Controls->Add(this->Text_post, 4, 0);
			this->Table_post->Controls->Add(this->About_post, 3, 0);
			this->Table_post->Controls->Add(this->Name_post, 2, 0);
			this->Table_post->Controls->Add(this->Number_post, 0, 0);
			this->Table_post->Controls->Add(this->Date_post, 1, 0);
			this->Table_post->ForeColor = System::Drawing::Color::White;
			this->Table_post->Name = L"Table_post";
			// 
			// Actioin_post
			// 
			resources->ApplyResources(this->Actioin_post, L"Actioin_post");
			this->Actioin_post->ForeColor = System::Drawing::Color::White;
			this->Actioin_post->Name = L"Actioin_post";
			// 
			// view_post
			// 
			resources->ApplyResources(this->view_post, L"view_post");
			this->view_post->ForeColor = System::Drawing::Color::White;
			this->view_post->Name = L"view_post";
			// 
			// Continuity_post
			// 
			resources->ApplyResources(this->Continuity_post, L"Continuity_post");
			this->Continuity_post->ForeColor = System::Drawing::Color::White;
			this->Continuity_post->Name = L"Continuity_post";
			// 
			// Text_post
			// 
			resources->ApplyResources(this->Text_post, L"Text_post");
			this->Text_post->ForeColor = System::Drawing::Color::White;
			this->Text_post->Name = L"Text_post";
			// 
			// About_post
			// 
			resources->ApplyResources(this->About_post, L"About_post");
			this->About_post->ForeColor = System::Drawing::Color::White;
			this->About_post->Name = L"About_post";
			// 
			// Name_post
			// 
			resources->ApplyResources(this->Name_post, L"Name_post");
			this->Name_post->ForeColor = System::Drawing::Color::White;
			this->Name_post->Name = L"Name_post";
			// 
			// Number_post
			// 
			resources->ApplyResources(this->Number_post, L"Number_post");
			this->Number_post->ForeColor = System::Drawing::Color::White;
			this->Number_post->Name = L"Number_post";
			// 
			// Date_post
			// 
			resources->ApplyResources(this->Date_post, L"Date_post");
			this->Date_post->ForeColor = System::Drawing::Color::White;
			this->Date_post->Name = L"Date_post";
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			this->Controls->Add(this->Panel_New_post);
			this->Controls->Add(this->button_New_post);
			this->Controls->Add(this->Table_post);
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Panel_New_post->ResumeLayout(false);
			this->Panel_New_post->PerformLayout();
			this->Table_post->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Panel_New_post->Visible = true;
	}


	private: System::Void Save_button_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ date = Swith_date_new_post->Value.ToShortDateString();
		String^ name = Textbox_Name_new_post->Text;
		String^ about = Textbox_About_new_post->Text;
		String^ text = textBox_Text_New_post->Text;
		String^ continuity = textBox_Continuity_new_post->Text;
		String^ media = Swith_view_media->Text;

		int newRow = this->Table_post->RowCount;
		this->Table_post->RowCount = newRow + 1;
		this->Table_post->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 80));

		Label^ lblIndex = gcnew Label();
		lblIndex->Text = (postCounter + 1).ToString();
		lblIndex->ForeColor = Color::White;
		lblIndex->BackColor = Color::Transparent;
		lblIndex->TextAlign = ContentAlignment::MiddleCenter;
		lblIndex->Dock = DockStyle::Fill;
		lblIndex->Margin = System::Windows::Forms::Padding(8);

		Label^ lblDate = gcnew Label();
		lblDate->Text = date;
		lblDate->ForeColor = Color::White;
		lblDate->BackColor = Color::Transparent;
		lblDate->TextAlign = ContentAlignment::MiddleCenter;
		lblDate->Dock = DockStyle::Fill;
		lblDate->AutoEllipsis = true;

		Label^ lblName = gcnew Label();
		lblName->Text = name;
		lblName->ForeColor = Color::White;
		lblName->BackColor = Color::Transparent;
		lblName->TextAlign = ContentAlignment::MiddleCenter;
		lblName->Dock = DockStyle::Fill;
		lblName->AutoEllipsis = true;

		Label^ lblAbout = gcnew Label();
		lblAbout->Text = about;
		lblAbout->ForeColor = Color::White;
		lblAbout->BackColor = Color::Transparent;
		lblAbout->TextAlign = ContentAlignment::MiddleCenter;
		lblAbout->Dock = DockStyle::Fill;
		lblAbout->AutoEllipsis = true;

		Label^ lblText = gcnew Label();
		lblText->Text = text;
		lblText->ForeColor = Color::White;
		lblText->BackColor = Color::Transparent;
		lblText->TextAlign = ContentAlignment::MiddleCenter;
		lblText->Dock = DockStyle::Fill;
		lblText->AutoEllipsis = true;

		Label^ lblContinuity = gcnew Label();
		lblContinuity->Text = continuity;
		lblContinuity->ForeColor = Color::White;
		lblContinuity->BackColor = Color::Transparent;
		lblContinuity->TextAlign = ContentAlignment::MiddleCenter;
		lblContinuity->Dock = DockStyle::Fill;
		lblContinuity->AutoEllipsis = true;

		Label^ lblMedia = gcnew Label();
		lblMedia->Text = media;
		lblMedia->ForeColor = Color::White;
		lblMedia->BackColor = Color::Transparent;
		lblMedia->TextAlign = ContentAlignment::MiddleCenter;
		lblMedia->Dock = DockStyle::Fill;
		lblMedia->AutoEllipsis = true;

		Label^ lblAction = gcnew Label();
		lblAction->Controls->Add(gcnew Button());
		lblMedia->TextAlign = ContentAlignment::MiddleCenter;
		lblMedia->Dock = DockStyle::Fill;

		this->Table_post->Controls->Add(lblIndex, 0, newRow);
		this->Table_post->Controls->Add(lblDate, 1, newRow);
		this->Table_post->Controls->Add(lblName, 2, newRow);
		this->Table_post->Controls->Add(lblAbout, 3, newRow);
		this->Table_post->Controls->Add(lblText, 4, newRow);
		this->Table_post->Controls->Add(lblContinuity, 5, newRow);
		this->Table_post->Controls->Add(lblMedia, 6, newRow);
		this->Table_post->Controls->Add(lblAction, 7, newRow);
		postCounter++;
		Panel_New_post->Visible = false;
		Textbox_Name_new_post->Clear();
		Textbox_About_new_post->Clear();
		textBox_Text_New_post->Clear();
		textBox_Continuity_new_post->Clear();
		Swith_view_media->Text = L"Ничего";
	};
	private: System::Void Panel_New_post_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
}
	; }
