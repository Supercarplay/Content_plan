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
	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;








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
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Panel_New_post->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// button_New_post
			// 
			this->button_New_post->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_New_post->Location = System::Drawing::Point(374, 14);
			this->button_New_post->Margin = System::Windows::Forms::Padding(5);
			this->button_New_post->Name = L"button_New_post";
			this->button_New_post->Size = System::Drawing::Size(131, 36);
			this->button_New_post->TabIndex = 0;
			this->button_New_post->Text = L"Добавить пост";
			this->button_New_post->UseVisualStyleBackColor = true;
			this->button_New_post->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// Panel_New_post
			// 
			this->Panel_New_post->AutoSize = true;
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
			this->Panel_New_post->Location = System::Drawing::Point(12, 58);
			this->Panel_New_post->Name = L"Panel_New_post";
			this->Panel_New_post->Size = System::Drawing::Size(847, 350);
			this->Panel_New_post->TabIndex = 1;
			this->Panel_New_post->TabStop = false;
			this->Panel_New_post->Tag = L"New_post";
			this->Panel_New_post->Visible = false;
			// 
			// Save_button
			// 
			this->Save_button->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->Save_button->ForeColor = System::Drawing::Color::Black;
			this->Save_button->Location = System::Drawing::Point(362, 283);
			this->Save_button->Name = L"Save_button";
			this->Save_button->Size = System::Drawing::Size(131, 32);
			this->Save_button->TabIndex = 14;
			this->Save_button->Text = L"Сохранить";
			this->Save_button->UseVisualStyleBackColor = true;
			this->Save_button->Click += gcnew System::EventHandler(this, &MyForm::Save_button_Click);
			// 
			// Generation_Continuity_new_post
			// 
			this->Generation_Continuity_new_post->ForeColor = System::Drawing::Color::Black;
			this->Generation_Continuity_new_post->Location = System::Drawing::Point(670, 186);
			this->Generation_Continuity_new_post->Name = L"Generation_Continuity_new_post";
			this->Generation_Continuity_new_post->Size = System::Drawing::Size(116, 32);
			this->Generation_Continuity_new_post->TabIndex = 13;
			this->Generation_Continuity_new_post->Text = L"Сгенерировать";
			this->Generation_Continuity_new_post->UseVisualStyleBackColor = true;
			// 
			// generation_text_post
			// 
			this->generation_text_post->ForeColor = System::Drawing::Color::Black;
			this->generation_text_post->Location = System::Drawing::Point(438, 186);
			this->generation_text_post->Name = L"generation_text_post";
			this->generation_text_post->Size = System::Drawing::Size(116, 32);
			this->generation_text_post->TabIndex = 12;
			this->generation_text_post->Text = L"Сгенерировать";
			this->generation_text_post->UseVisualStyleBackColor = true;
			// 
			// textBox_Continuity_new_post
			// 
			this->textBox_Continuity_new_post->AcceptsReturn = true;
			this->textBox_Continuity_new_post->AcceptsTab = true;
			this->textBox_Continuity_new_post->BackColor = System::Drawing::Color::Gray;
			this->textBox_Continuity_new_post->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_Continuity_new_post->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->textBox_Continuity_new_post->ForeColor = System::Drawing::Color::White;
			this->textBox_Continuity_new_post->Location = System::Drawing::Point(644, 68);
			this->textBox_Continuity_new_post->Multiline = true;
			this->textBox_Continuity_new_post->Name = L"textBox_Continuity_new_post";
			this->textBox_Continuity_new_post->Size = System::Drawing::Size(169, 112);
			this->textBox_Continuity_new_post->TabIndex = 11;
			this->textBox_Continuity_new_post->Tag = L"Name_Project";
			// 
			// textBox_Text_New_post
			// 
			this->textBox_Text_New_post->AcceptsReturn = true;
			this->textBox_Text_New_post->AcceptsTab = true;
			this->textBox_Text_New_post->BackColor = System::Drawing::Color::Gray;
			this->textBox_Text_New_post->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_Text_New_post->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->textBox_Text_New_post->ForeColor = System::Drawing::Color::White;
			this->textBox_Text_New_post->Location = System::Drawing::Point(414, 68);
			this->textBox_Text_New_post->Multiline = true;
			this->textBox_Text_New_post->Name = L"textBox_Text_New_post";
			this->textBox_Text_New_post->Size = System::Drawing::Size(169, 112);
			this->textBox_Text_New_post->TabIndex = 10;
			this->textBox_Text_New_post->Tag = L"Name_Project";
			// 
			// Continuity_new_post
			// 
			this->Continuity_new_post->AutoSize = true;
			this->Continuity_new_post->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->Continuity_new_post->Location = System::Drawing::Point(690, 36);
			this->Continuity_new_post->Name = L"Continuity_new_post";
			this->Continuity_new_post->Size = System::Drawing::Size(78, 19);
			this->Continuity_new_post->TabIndex = 9;
			this->Continuity_new_post->Text = L"Сценарий";
			// 
			// Text_New_post
			// 
			this->Text_New_post->AutoSize = true;
			this->Text_New_post->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->Text_New_post->Location = System::Drawing::Point(473, 36);
			this->Text_New_post->Name = L"Text_New_post";
			this->Text_New_post->Size = System::Drawing::Size(45, 19);
			this->Text_New_post->TabIndex = 8;
			this->Text_New_post->Text = L"Текст";
			// 
			// Swith_view_media
			// 
			this->Swith_view_media->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->Swith_view_media->FormattingEnabled = true;
			this->Swith_view_media->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Ничего", L"Видео", L"Фото" });
			this->Swith_view_media->Location = System::Drawing::Point(252, 180);
			this->Swith_view_media->Name = L"Swith_view_media";
			this->Swith_view_media->Size = System::Drawing::Size(104, 23);
			this->Swith_view_media->TabIndex = 7;
			this->Swith_view_media->Text = L"Ничего";
			// 
			// view_media
			// 
			this->view_media->AutoSize = true;
			this->view_media->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->view_media->Location = System::Drawing::Point(264, 150);
			this->view_media->Name = L"view_media";
			this->view_media->Size = System::Drawing::Size(81, 19);
			this->view_media->TabIndex = 6;
			this->view_media->Text = L"Вид медиа";
			// 
			// Swith_date_new_post
			// 
			this->Swith_date_new_post->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->Swith_date_new_post->Location = System::Drawing::Point(41, 182);
			this->Swith_date_new_post->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->Swith_date_new_post->Name = L"Swith_date_new_post";
			this->Swith_date_new_post->Size = System::Drawing::Size(157, 21);
			this->Swith_date_new_post->TabIndex = 5;
			// 
			// Date_new_post
			// 
			this->Date_new_post->AutoSize = true;
			this->Date_new_post->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Date_new_post->Location = System::Drawing::Point(56, 150);
			this->Date_new_post->Name = L"Date_new_post";
			this->Date_new_post->Size = System::Drawing::Size(109, 19);
			this->Date_new_post->TabIndex = 4;
			this->Date_new_post->Text = L"Выберите дату";
			// 
			// Textbox_About_new_post
			// 
			this->Textbox_About_new_post->AcceptsReturn = true;
			this->Textbox_About_new_post->AcceptsTab = true;
			this->Textbox_About_new_post->BackColor = System::Drawing::Color::Gray;
			this->Textbox_About_new_post->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Textbox_About_new_post->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->Textbox_About_new_post->ForeColor = System::Drawing::Color::White;
			this->Textbox_About_new_post->Location = System::Drawing::Point(217, 68);
			this->Textbox_About_new_post->Multiline = true;
			this->Textbox_About_new_post->Name = L"Textbox_About_new_post";
			this->Textbox_About_new_post->Size = System::Drawing::Size(169, 64);
			this->Textbox_About_new_post->TabIndex = 3;
			this->Textbox_About_new_post->Tag = L"Name_Project";
			// 
			// About_new_post
			// 
			this->About_new_post->AutoSize = true;
			this->About_new_post->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->About_new_post->Location = System::Drawing::Point(267, 36);
			this->About_new_post->Name = L"About_new_post";
			this->About_new_post->Size = System::Drawing::Size(78, 19);
			this->About_new_post->TabIndex = 2;
			this->About_new_post->Text = L"Описание";
			// 
			// Textbox_Name_new_post
			// 
			this->Textbox_Name_new_post->AcceptsReturn = true;
			this->Textbox_Name_new_post->AcceptsTab = true;
			this->Textbox_Name_new_post->BackColor = System::Drawing::Color::Gray;
			this->Textbox_Name_new_post->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Textbox_Name_new_post->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9));
			this->Textbox_Name_new_post->ForeColor = System::Drawing::Color::White;
			this->Textbox_Name_new_post->Location = System::Drawing::Point(29, 68);
			this->Textbox_Name_new_post->Multiline = true;
			this->Textbox_Name_new_post->Name = L"Textbox_Name_new_post";
			this->Textbox_Name_new_post->Size = System::Drawing::Size(169, 64);
			this->Textbox_Name_new_post->TabIndex = 1;
			this->Textbox_Name_new_post->Tag = L"Name_Project";
			// 
			// Name_new_post
			// 
			this->Name_new_post->AutoSize = true;
			this->Name_new_post->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->Name_new_post->ForeColor = System::Drawing::Color::White;
			this->Name_new_post->Location = System::Drawing::Point(73, 36);
			this->Name_new_post->Name = L"Name_new_post";
			this->Name_new_post->Size = System::Drawing::Size(73, 19);
			this->Name_new_post->TabIndex = 0;
			this->Name_new_post->Text = L"Название";
			// 
			// dataGridView
			// 
			this->dataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(71)));
			this->dataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView->ColumnHeadersHeight = 20;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6
			});
			this->dataGridView->Location = System::Drawing::Point(171, 176);
			this->dataGridView->Margin = System::Windows::Forms::Padding(5);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersWidth = 70;
			this->dataGridView->Size = System::Drawing::Size(528, 86);
			this->dataGridView->TabIndex = 4;
			this->dataGridView->Tag = L"Table_post";
			// 
			// Column1
			// 
			this->Column1->Frozen = true;
			this->Column1->HeaderText = L"Дата";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 58;
			// 
			// Column2
			// 
			this->Column2->Frozen = true;
			this->Column2->HeaderText = L"Название";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 82;
			// 
			// Column3
			// 
			this->Column3->Frozen = true;
			this->Column3->HeaderText = L"Описание";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 82;
			// 
			// Column4
			// 
			this->Column4->Frozen = true;
			this->Column4->HeaderText = L"Текст";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 62;
			// 
			// Column5
			// 
			this->Column5->Frozen = true;
			this->Column5->HeaderText = L"Сценарий";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 81;
			// 
			// Column6
			// 
			this->Column6->Frozen = true;
			this->Column6->HeaderText = L"Вид медиа";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 86;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			this->ClientSize = System::Drawing::Size(871, 439);
			this->Controls->Add(this->Panel_New_post);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->button_New_post);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Panel_New_post->ResumeLayout(false);
			this->Panel_New_post->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
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
		this->dataGridView->Rows->Add(date, name, about, text, continuity, media);
		Panel_New_post->Visible = false;
		Textbox_Name_new_post->Clear();
		Textbox_About_new_post->Clear();
		textBox_Text_New_post->Clear();
		textBox_Continuity_new_post->Clear();
	};
	}
	; }