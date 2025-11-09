#pragma once

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		static String^ connectString_post = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database_post.accdb;";
		static String^ connectString_Login = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database_Login.accdb;";
	private: System::Windows::Forms::Label^ Name_new_post;
	public:
	private: System::Windows::Forms::TextBox^ Textbox_Name_new_post;
	private: System::Windows::Forms::Label^ About_new_post;
	private: System::Windows::Forms::TextBox^ Textbox_About_new_post;
	private: System::Windows::Forms::Label^ Date_new_post;
	private: System::Windows::Forms::DateTimePicker^ Swith_date_new_post;
	private: System::Windows::Forms::Label^ view_media;
	private: System::Windows::Forms::ComboBox^ Swith_view_media;
	private: System::Windows::Forms::Label^ Text_New_post;
	private: System::Windows::Forms::Label^ Continuity_new_post;
	private: System::Windows::Forms::TextBox^ textBox_Text_New_post;
	private: System::Windows::Forms::TextBox^ textBox_Continuity_new_post;
	private: System::Windows::Forms::Button^ generation_text_post;
	private: System::Windows::Forms::Button^ Generation_Continuity_new_post;
	private: System::Windows::Forms::Button^ Save_button;
	private: System::Windows::Forms::GroupBox^ Panel_New_post;
	private: System::Windows::Forms::DataGridView^ Table_post;
	private: System::Windows::Forms::GroupBox^ Edit_post;
	private: System::Windows::Forms::Button^ Save_editbutton;
	private: System::Windows::Forms::TextBox^ Continuity_Edit_post;
	private: System::Windows::Forms::TextBox^ text_Edit_post;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ View_media_Edit;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_Editpost;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ About_Edit_post;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ Name_Edit_post;
	private: System::Windows::Forms::Label^ label6;
	










		   
	

	private: System::Windows::Forms::Button^ Btnsettings;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ BtnArchive;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Button^ BtnAddFiles;
	private: System::Windows::Forms::LinkLabel^ linkFile;
	private: System::Windows::Forms::LinkLabel^ linkEditFile;
	private: System::Windows::Forms::Button^ BtnEditFile;
	private: System::Windows::Forms::GroupBox^ SettingsGroup;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ ID_Group_text;

	private: System::Windows::Forms::Button^ BtnSaveSettings;











	private:
		int currentEditPostID;
	private:
		OleDbConnection^ DBconnection_post;
		OleDbConnection^ DBconnection_login;

		String^ selectedFileForNewPost;










	private: System::Windows::Forms::DataGridView^ Archive_Table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Archive_ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Archive_Data;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Archive_Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Archive_About;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Archive_Text;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Archive_Scencens;
	private: System::Windows::Forms::DataGridViewLinkColumn^ Archive_ViewMedia;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Archive_post;
	private: System::Windows::Forms::DataGridViewButtonColumn^ BtnReturn;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date_post;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ name_post;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ About_post;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Text_post;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Scencens_post;
private: System::Windows::Forms::DataGridViewLinkColumn^ ViewMedia_post;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Files_post;
private: System::Windows::Forms::DataGridViewButtonColumn^ EditButton;
private: System::Windows::Forms::DataGridViewButtonColumn^ DeleteButton;








































		   String^ selectedFileForEditPost;
	private:
		static String^ GetRelativePath(String^ fromPath, String^ toPath) {
			Uri^ fromUri = gcnew Uri(fromPath + "\\");
			Uri^ toUri = gcnew Uri(toPath);
			Uri^ relativeUri = fromUri->MakeRelativeUri(toUri);
			return relativeUri->ToString()->Replace('/', '\\');
		}
	private:
		bool isEditingFromArchive = false;
	public:
		MyForm(void)
		{
			InitializeComponent();

			String^ dbPathPost = System::IO::Path::Combine(Application::StartupPath, "Database_post.accdb");
			String^ connectString_post = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dbPathPost + ";Persist Security Info=False;";
			DBconnection_post = gcnew OleDbConnection(connectString_post);

			String^ dbPathLogin = System::IO::Path::Combine(Application::StartupPath, "Database_Login.accdb");
			String^ connectString_login = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dbPathLogin + ";Persist Security Info=False;";
			DBconnection_login = gcnew OleDbConnection(connectString_login);

			String^ filePostFolder = System::IO::Path::Combine(Application::StartupPath, "FilePost");
			if (!System::IO::Directory::Exists(filePostFolder)) {
				System::IO::Directory::CreateDirectory(filePostFolder);
			}

			this->AutoScroll = true;
			Table_post->RowHeadersVisible = false;
			Table_post->GridColor = System::Drawing::Color::White;
			Table_post->CellBorderStyle = DataGridViewCellBorderStyle::Single;
			Archive_Table->RowHeadersVisible = false;
			Archive_Table->GridColor = System::Drawing::Color::White;
			Archive_Table->CellBorderStyle = DataGridViewCellBorderStyle::Single;
			
			DBconnection_post->Open();
			DBconnection_login->Open();
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button_New_post = (gcnew System::Windows::Forms::Button());
			this->Name_new_post = (gcnew System::Windows::Forms::Label());
			this->Textbox_Name_new_post = (gcnew System::Windows::Forms::TextBox());
			this->About_new_post = (gcnew System::Windows::Forms::Label());
			this->Textbox_About_new_post = (gcnew System::Windows::Forms::TextBox());
			this->Date_new_post = (gcnew System::Windows::Forms::Label());
			this->Swith_date_new_post = (gcnew System::Windows::Forms::DateTimePicker());
			this->view_media = (gcnew System::Windows::Forms::Label());
			this->Swith_view_media = (gcnew System::Windows::Forms::ComboBox());
			this->Text_New_post = (gcnew System::Windows::Forms::Label());
			this->Continuity_new_post = (gcnew System::Windows::Forms::Label());
			this->textBox_Text_New_post = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Continuity_new_post = (gcnew System::Windows::Forms::TextBox());
			this->generation_text_post = (gcnew System::Windows::Forms::Button());
			this->Generation_Continuity_new_post = (gcnew System::Windows::Forms::Button());
			this->Save_button = (gcnew System::Windows::Forms::Button());
			this->Panel_New_post = (gcnew System::Windows::Forms::GroupBox());
			this->linkFile = (gcnew System::Windows::Forms::LinkLabel());
			this->BtnAddFiles = (gcnew System::Windows::Forms::Button());
			this->Edit_post = (gcnew System::Windows::Forms::GroupBox());
			this->linkEditFile = (gcnew System::Windows::Forms::LinkLabel());
			this->BtnEditFile = (gcnew System::Windows::Forms::Button());
			this->Save_editbutton = (gcnew System::Windows::Forms::Button());
			this->Continuity_Edit_post = (gcnew System::Windows::Forms::TextBox());
			this->text_Edit_post = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->View_media_Edit = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker_Editpost = (gcnew System::Windows::Forms::DateTimePicker());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->About_Edit_post = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Name_Edit_post = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Archive_Table = (gcnew System::Windows::Forms::DataGridView());
			this->Archive_ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Archive_Data = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Archive_Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Archive_About = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Archive_Text = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Archive_Scencens = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Archive_ViewMedia = (gcnew System::Windows::Forms::DataGridViewLinkColumn());
			this->Archive_post = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BtnReturn = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Table_post = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date_post = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name_post = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->About_post = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Text_post = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Scencens_post = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ViewMedia_post = (gcnew System::Windows::Forms::DataGridViewLinkColumn());
			this->Files_post = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EditButton = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->DeleteButton = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Btnsettings = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->BtnArchive = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SettingsGroup = (gcnew System::Windows::Forms::GroupBox());
			this->BtnSaveSettings = (gcnew System::Windows::Forms::Button());
			this->ID_Group_text = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Panel_New_post->SuspendLayout();
			this->Edit_post->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Archive_Table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table_post))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SettingsGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_New_post
			// 
			resources->ApplyResources(this->button_New_post, L"button_New_post");
			this->button_New_post->Name = L"button_New_post";
			this->button_New_post->UseVisualStyleBackColor = true;
			this->button_New_post->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// Name_new_post
			// 
			resources->ApplyResources(this->Name_new_post, L"Name_new_post");
			this->Name_new_post->ForeColor = System::Drawing::Color::White;
			this->Name_new_post->Name = L"Name_new_post";
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
			// About_new_post
			// 
			resources->ApplyResources(this->About_new_post, L"About_new_post");
			this->About_new_post->Name = L"About_new_post";
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
			// Date_new_post
			// 
			resources->ApplyResources(this->Date_new_post, L"Date_new_post");
			this->Date_new_post->Name = L"Date_new_post";
			// 
			// Swith_date_new_post
			// 
			resources->ApplyResources(this->Swith_date_new_post, L"Swith_date_new_post");
			this->Swith_date_new_post->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->Swith_date_new_post->Name = L"Swith_date_new_post";
			// 
			// view_media
			// 
			resources->ApplyResources(this->view_media, L"view_media");
			this->view_media->Name = L"view_media";
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
			// Text_New_post
			// 
			resources->ApplyResources(this->Text_New_post, L"Text_New_post");
			this->Text_New_post->Name = L"Text_New_post";
			// 
			// Continuity_new_post
			// 
			resources->ApplyResources(this->Continuity_new_post, L"Continuity_new_post");
			this->Continuity_new_post->Name = L"Continuity_new_post";
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
			// generation_text_post
			// 
			resources->ApplyResources(this->generation_text_post, L"generation_text_post");
			this->generation_text_post->ForeColor = System::Drawing::Color::Black;
			this->generation_text_post->Name = L"generation_text_post";
			this->generation_text_post->UseVisualStyleBackColor = true;
			// 
			// Generation_Continuity_new_post
			// 
			resources->ApplyResources(this->Generation_Continuity_new_post, L"Generation_Continuity_new_post");
			this->Generation_Continuity_new_post->ForeColor = System::Drawing::Color::Black;
			this->Generation_Continuity_new_post->Name = L"Generation_Continuity_new_post";
			this->Generation_Continuity_new_post->UseVisualStyleBackColor = true;
			// 
			// Save_button
			// 
			resources->ApplyResources(this->Save_button, L"Save_button");
			this->Save_button->ForeColor = System::Drawing::Color::Black;
			this->Save_button->Name = L"Save_button";
			this->Save_button->UseVisualStyleBackColor = true;
			this->Save_button->Click += gcnew System::EventHandler(this, &MyForm::Save_button_Click);
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
			this->Panel_New_post->Controls->Add(this->linkFile);
			this->Panel_New_post->Controls->Add(this->BtnAddFiles);
			this->Panel_New_post->ForeColor = System::Drawing::Color::White;
			this->Panel_New_post->Name = L"Panel_New_post";
			this->Panel_New_post->TabStop = false;
			this->Panel_New_post->Tag = L"New_post";
			// 
			// linkFile
			// 
			resources->ApplyResources(this->linkFile, L"linkFile");
			this->linkFile->LinkColor = System::Drawing::Color::White;
			this->linkFile->Name = L"linkFile";
			this->linkFile->TabStop = true;
			// 
			// BtnAddFiles
			// 
			resources->ApplyResources(this->BtnAddFiles, L"BtnAddFiles");
			this->BtnAddFiles->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->BtnAddFiles->Name = L"BtnAddFiles";
			this->BtnAddFiles->UseVisualStyleBackColor = true;
			this->BtnAddFiles->Click += gcnew System::EventHandler(this, &MyForm::BtnAddFiles_Click);
			// 
			// Edit_post
			// 
			resources->ApplyResources(this->Edit_post, L"Edit_post");
			this->Edit_post->Controls->Add(this->linkEditFile);
			this->Edit_post->Controls->Add(this->BtnEditFile);
			this->Edit_post->Controls->Add(this->Save_editbutton);
			this->Edit_post->Controls->Add(this->Continuity_Edit_post);
			this->Edit_post->Controls->Add(this->text_Edit_post);
			this->Edit_post->Controls->Add(this->label1);
			this->Edit_post->Controls->Add(this->label2);
			this->Edit_post->Controls->Add(this->View_media_Edit);
			this->Edit_post->Controls->Add(this->label3);
			this->Edit_post->Controls->Add(this->dateTimePicker_Editpost);
			this->Edit_post->Controls->Add(this->label4);
			this->Edit_post->Controls->Add(this->About_Edit_post);
			this->Edit_post->Controls->Add(this->label5);
			this->Edit_post->Controls->Add(this->Name_Edit_post);
			this->Edit_post->Controls->Add(this->label6);
			this->Edit_post->ForeColor = System::Drawing::Color::White;
			this->Edit_post->Name = L"Edit_post";
			this->Edit_post->TabStop = false;
			this->Edit_post->Tag = L"Edit_post";
			// 
			// linkEditFile
			// 
			resources->ApplyResources(this->linkEditFile, L"linkEditFile");
			this->linkEditFile->LinkColor = System::Drawing::Color::White;
			this->linkEditFile->Name = L"linkEditFile";
			this->linkEditFile->TabStop = true;
			// 
			// BtnEditFile
			// 
			resources->ApplyResources(this->BtnEditFile, L"BtnEditFile");
			this->BtnEditFile->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->BtnEditFile->Name = L"BtnEditFile";
			this->BtnEditFile->UseVisualStyleBackColor = true;
			this->BtnEditFile->Click += gcnew System::EventHandler(this, &MyForm::BtnEditFile_Click);
			// 
			// Save_editbutton
			// 
			resources->ApplyResources(this->Save_editbutton, L"Save_editbutton");
			this->Save_editbutton->ForeColor = System::Drawing::Color::Black;
			this->Save_editbutton->Name = L"Save_editbutton";
			this->Save_editbutton->UseVisualStyleBackColor = true;
			this->Save_editbutton->Click += gcnew System::EventHandler(this, &MyForm::Save_editbutton_Click);
			// 
			// Continuity_Edit_post
			// 
			this->Continuity_Edit_post->AcceptsReturn = true;
			this->Continuity_Edit_post->AcceptsTab = true;
			resources->ApplyResources(this->Continuity_Edit_post, L"Continuity_Edit_post");
			this->Continuity_Edit_post->BackColor = System::Drawing::Color::Gray;
			this->Continuity_Edit_post->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Continuity_Edit_post->ForeColor = System::Drawing::Color::White;
			this->Continuity_Edit_post->Name = L"Continuity_Edit_post";
			this->Continuity_Edit_post->Tag = L"Name_Project";
			// 
			// text_Edit_post
			// 
			this->text_Edit_post->AcceptsReturn = true;
			this->text_Edit_post->AcceptsTab = true;
			resources->ApplyResources(this->text_Edit_post, L"text_Edit_post");
			this->text_Edit_post->BackColor = System::Drawing::Color::Gray;
			this->text_Edit_post->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->text_Edit_post->ForeColor = System::Drawing::Color::White;
			this->text_Edit_post->Name = L"text_Edit_post";
			this->text_Edit_post->Tag = L"Name_Project";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// View_media_Edit
			// 
			resources->ApplyResources(this->View_media_Edit, L"View_media_Edit");
			this->View_media_Edit->FormattingEnabled = true;
			this->View_media_Edit->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				resources->GetString(L"View_media_Edit.Items"),
					resources->GetString(L"View_media_Edit.Items1"), resources->GetString(L"View_media_Edit.Items2")
			});
			this->View_media_Edit->Name = L"View_media_Edit";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// dateTimePicker_Editpost
			// 
			resources->ApplyResources(this->dateTimePicker_Editpost, L"dateTimePicker_Editpost");
			this->dateTimePicker_Editpost->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->dateTimePicker_Editpost->Name = L"dateTimePicker_Editpost";
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			// 
			// About_Edit_post
			// 
			this->About_Edit_post->AcceptsReturn = true;
			this->About_Edit_post->AcceptsTab = true;
			resources->ApplyResources(this->About_Edit_post, L"About_Edit_post");
			this->About_Edit_post->BackColor = System::Drawing::Color::Gray;
			this->About_Edit_post->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->About_Edit_post->ForeColor = System::Drawing::Color::White;
			this->About_Edit_post->Name = L"About_Edit_post";
			this->About_Edit_post->Tag = L"Name_Project";
			// 
			// label5
			// 
			resources->ApplyResources(this->label5, L"label5");
			this->label5->Name = L"label5";
			// 
			// Name_Edit_post
			// 
			this->Name_Edit_post->AcceptsReturn = true;
			this->Name_Edit_post->AcceptsTab = true;
			resources->ApplyResources(this->Name_Edit_post, L"Name_Edit_post");
			this->Name_Edit_post->BackColor = System::Drawing::Color::Gray;
			this->Name_Edit_post->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Name_Edit_post->ForeColor = System::Drawing::Color::White;
			this->Name_Edit_post->Name = L"Name_Edit_post";
			this->Name_Edit_post->Tag = L"Name_Project";
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Name = L"label6";
			// 
			// Archive_Table
			// 
			this->Archive_Table->AllowUserToAddRows = false;
			this->Archive_Table->AllowUserToDeleteRows = false;
			resources->ApplyResources(this->Archive_Table, L"Archive_Table");
			this->Archive_Table->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->Archive_Table->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)), static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->Archive_Table->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->Padding = System::Windows::Forms::Padding(5);
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->Archive_Table->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->Archive_Table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->Archive_Table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->Archive_ID,
					this->Archive_Data, this->Archive_Name, this->Archive_About, this->Archive_Text, this->Archive_Scencens, this->Archive_ViewMedia,
					this->Archive_post, this->BtnReturn
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Archive_Table->DefaultCellStyle = dataGridViewCellStyle2;
			this->Archive_Table->GridColor = System::Drawing::Color::Black;
			this->Archive_Table->Name = L"Archive_Table";
			this->Archive_Table->ReadOnly = true;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Archive_Table->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->Archive_Table->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::Archive_Table_CellContentClick);
			// 
			// Archive_ID
			// 
			resources->ApplyResources(this->Archive_ID, L"Archive_ID");
			this->Archive_ID->Name = L"Archive_ID";
			this->Archive_ID->ReadOnly = true;
			this->Archive_ID->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Archive_Data
			// 
			resources->ApplyResources(this->Archive_Data, L"Archive_Data");
			this->Archive_Data->Name = L"Archive_Data";
			this->Archive_Data->ReadOnly = true;
			this->Archive_Data->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Archive_Name
			// 
			resources->ApplyResources(this->Archive_Name, L"Archive_Name");
			this->Archive_Name->Name = L"Archive_Name";
			this->Archive_Name->ReadOnly = true;
			this->Archive_Name->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Archive_About
			// 
			resources->ApplyResources(this->Archive_About, L"Archive_About");
			this->Archive_About->Name = L"Archive_About";
			this->Archive_About->ReadOnly = true;
			this->Archive_About->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Archive_Text
			// 
			resources->ApplyResources(this->Archive_Text, L"Archive_Text");
			this->Archive_Text->Name = L"Archive_Text";
			this->Archive_Text->ReadOnly = true;
			this->Archive_Text->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Archive_Scencens
			// 
			resources->ApplyResources(this->Archive_Scencens, L"Archive_Scencens");
			this->Archive_Scencens->Name = L"Archive_Scencens";
			this->Archive_Scencens->ReadOnly = true;
			this->Archive_Scencens->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Archive_ViewMedia
			// 
			this->Archive_ViewMedia->ActiveLinkColor = System::Drawing::Color::RosyBrown;
			resources->ApplyResources(this->Archive_ViewMedia, L"Archive_ViewMedia");
			this->Archive_ViewMedia->LinkColor = System::Drawing::Color::White;
			this->Archive_ViewMedia->Name = L"Archive_ViewMedia";
			this->Archive_ViewMedia->ReadOnly = true;
			this->Archive_ViewMedia->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Archive_ViewMedia->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->Archive_ViewMedia->VisitedLinkColor = System::Drawing::Color::White;
			// 
			// Archive_post
			// 
			resources->ApplyResources(this->Archive_post, L"Archive_post");
			this->Archive_post->Name = L"Archive_post";
			this->Archive_post->ReadOnly = true;
			// 
			// BtnReturn
			// 
			resources->ApplyResources(this->BtnReturn, L"BtnReturn");
			this->BtnReturn->Name = L"BtnReturn";
			this->BtnReturn->ReadOnly = true;
			this->BtnReturn->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Table_post
			// 
			this->Table_post->AllowUserToAddRows = false;
			this->Table_post->AllowUserToDeleteRows = false;
			resources->ApplyResources(this->Table_post, L"Table_post");
			this->Table_post->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->Table_post->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->Table_post->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->Padding = System::Windows::Forms::Padding(5);
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->Table_post->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->Table_post->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->Table_post->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->ID, this->Date_post,
					this->name_post, this->About_post, this->Text_post, this->Scencens_post, this->ViewMedia_post, this->Files_post, this->EditButton,
					this->DeleteButton
			});
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F));
			dataGridViewCellStyle5->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Table_post->DefaultCellStyle = dataGridViewCellStyle5;
			this->Table_post->GridColor = System::Drawing::Color::Black;
			this->Table_post->Name = L"Table_post";
			this->Table_post->ReadOnly = true;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Table_post->RowsDefaultCellStyle = dataGridViewCellStyle6;
			this->Table_post->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::Table_post_CellContentClick);
			// 
			// ID
			// 
			resources->ApplyResources(this->ID, L"ID");
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			// 
			// Date_post
			// 
			resources->ApplyResources(this->Date_post, L"Date_post");
			this->Date_post->Name = L"Date_post";
			this->Date_post->ReadOnly = true;
			this->Date_post->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// name_post
			// 
			resources->ApplyResources(this->name_post, L"name_post");
			this->name_post->Name = L"name_post";
			this->name_post->ReadOnly = true;
			this->name_post->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// About_post
			// 
			resources->ApplyResources(this->About_post, L"About_post");
			this->About_post->Name = L"About_post";
			this->About_post->ReadOnly = true;
			this->About_post->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Text_post
			// 
			resources->ApplyResources(this->Text_post, L"Text_post");
			this->Text_post->Name = L"Text_post";
			this->Text_post->ReadOnly = true;
			this->Text_post->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Scencens_post
			// 
			resources->ApplyResources(this->Scencens_post, L"Scencens_post");
			this->Scencens_post->Name = L"Scencens_post";
			this->Scencens_post->ReadOnly = true;
			this->Scencens_post->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// ViewMedia_post
			// 
			this->ViewMedia_post->ActiveLinkColor = System::Drawing::Color::RosyBrown;
			resources->ApplyResources(this->ViewMedia_post, L"ViewMedia_post");
			this->ViewMedia_post->LinkColor = System::Drawing::Color::White;
			this->ViewMedia_post->Name = L"ViewMedia_post";
			this->ViewMedia_post->ReadOnly = true;
			this->ViewMedia_post->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->ViewMedia_post->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->ViewMedia_post->VisitedLinkColor = System::Drawing::Color::White;
			// 
			// Files_post
			// 
			resources->ApplyResources(this->Files_post, L"Files_post");
			this->Files_post->Name = L"Files_post";
			this->Files_post->ReadOnly = true;
			// 
			// EditButton
			// 
			resources->ApplyResources(this->EditButton, L"EditButton");
			this->EditButton->Name = L"EditButton";
			this->EditButton->ReadOnly = true;
			this->EditButton->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// DeleteButton
			// 
			resources->ApplyResources(this->DeleteButton, L"DeleteButton");
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->ReadOnly = true;
			this->DeleteButton->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Btnsettings
			// 
			resources->ApplyResources(this->Btnsettings, L"Btnsettings");
			this->Btnsettings->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Btnsettings->FlatAppearance->BorderSize = 5;
			this->Btnsettings->Name = L"Btnsettings";
			this->Btnsettings->UseVisualStyleBackColor = true;
			this->Btnsettings->Click += gcnew System::EventHandler(this, &MyForm::Btnsettings_Click);
			// 
			// pictureBox1
			// 
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
			// 
			// BtnArchive
			// 
			resources->ApplyResources(this->BtnArchive, L"BtnArchive");
			this->BtnArchive->Name = L"BtnArchive";
			this->BtnArchive->UseVisualStyleBackColor = true;
			this->BtnArchive->Click += gcnew System::EventHandler(this, &MyForm::BtnArchive_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			// 
			// SettingsGroup
			// 
			this->SettingsGroup->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->SettingsGroup->Controls->Add(this->BtnSaveSettings);
			this->SettingsGroup->Controls->Add(this->ID_Group_text);
			this->SettingsGroup->Controls->Add(this->label7);
			resources->ApplyResources(this->SettingsGroup, L"SettingsGroup");
			this->SettingsGroup->ForeColor = System::Drawing::Color::White;
			this->SettingsGroup->Name = L"SettingsGroup";
			this->SettingsGroup->TabStop = false;
			// 
			// BtnSaveSettings
			// 
			this->BtnSaveSettings->ForeColor = System::Drawing::Color::Black;
			resources->ApplyResources(this->BtnSaveSettings, L"BtnSaveSettings");
			this->BtnSaveSettings->Name = L"BtnSaveSettings";
			this->BtnSaveSettings->UseVisualStyleBackColor = true;
			this->BtnSaveSettings->Click += gcnew System::EventHandler(this, &MyForm::BtnSaveSettings_Click);
			// 
			// ID_Group_text
			// 
			resources->ApplyResources(this->ID_Group_text, L"ID_Group_text");
			this->ID_Group_text->Name = L"ID_Group_text";
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->Name = L"label7";
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			this->Controls->Add(this->SettingsGroup);
			this->Controls->Add(this->Edit_post);
			this->Controls->Add(this->Panel_New_post);
			this->Controls->Add(this->BtnArchive);
			this->Controls->Add(this->Btnsettings);
			this->Controls->Add(this->button_New_post);
			this->Controls->Add(this->Archive_Table);
			this->Controls->Add(this->Table_post);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Panel_New_post->ResumeLayout(false);
			this->Panel_New_post->PerformLayout();
			this->Edit_post->ResumeLayout(false);
			this->Edit_post->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Archive_Table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table_post))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->SettingsGroup->ResumeLayout(false);
			this->SettingsGroup->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Table_post->AutoGenerateColumns = false;
		Date_post->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		Date_post->Width = 100;
		ViewMedia_post->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		ViewMedia_post->Width = 100;

		EditButton->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		EditButton->Width = 50;
		EditButton->UseColumnTextForButtonValue = true;
		EditButton->Text = L"✎";

		DeleteButton->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		DeleteButton->Width = 50;
				DeleteButton->UseColumnTextForButtonValue = true;
		DeleteButton->Text = L"✕";
		
		String^ query = "SELECT [ID], [Date_post], [name_post], [About_post], [Text_post], [Scencens_post], [ViewMedia_post], [Files] FROM TablePost WHERE [Published] = False ORDER BY [Date_post]";
		OleDbCommand^ command = gcnew OleDbCommand(query, DBconnection_post);
		OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter(command);
		DataTable^ dataTable = gcnew DataTable();

		adapter->Fill(dataTable);

		Table_post->DataSource = dataTable;
		ID->DataPropertyName = "ID";
		Date_post->DataPropertyName = "Date_post";
		name_post->DataPropertyName = "name_post";
		About_post->DataPropertyName = "About_post";
		Text_post->DataPropertyName = "Text_post";
		Scencens_post->DataPropertyName = "Scencens_post";
		ViewMedia_post->DataPropertyName = "ViewMedia_post";
		Files_post->DataPropertyName = "Files";
		Table_post->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
		Table_post->DefaultCellStyle->WrapMode = DataGridViewTriState::True;
		Table_post->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;
		for each (DataGridViewColumn ^ col in Table_post->Columns) {
			col->SortMode = DataGridViewColumnSortMode::NotSortable;
		}
		LoadArchiveData();
	}

	private: System::Void LoadArchiveData() {
		Archive_Table->AutoGenerateColumns = false;
		Archive_Data->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		Archive_Data->Width = 100;
		Archive_ViewMedia->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		Archive_ViewMedia->Width = 100;
		BtnReturn->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		BtnReturn->Width = 50;
		BtnReturn->UseColumnTextForButtonValue = true;
		BtnReturn->Text = L"↩";

		String^ query = "SELECT [ID], [Date_post], [name_post], [About_post], [Text_post], [Scencens_post], [ViewMedia_post], [Files] "
			"FROM TablePost WHERE [Published] = True "
			"ORDER BY [Date_post]";
		OleDbCommand^ command = gcnew OleDbCommand(query, DBconnection_post);
		OleDbDataAdapter^ adapter = gcnew OleDbDataAdapter(command);
		DataTable^ dataTable = gcnew DataTable();
		adapter->Fill(dataTable);
		Archive_Table->DataSource = dataTable;

		Archive_ID->DataPropertyName = "ID";
		Archive_Data->DataPropertyName = "Date_post";
		Archive_Name->DataPropertyName = "name_post";
		Archive_About->DataPropertyName = "About_post";
		Archive_Text->DataPropertyName = "Text_post";
		Archive_Scencens->DataPropertyName = "Scencens_post";
		Archive_ViewMedia->DataPropertyName = "ViewMedia_post";
		Archive_post->DataPropertyName = "Files";

		Archive_Table->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
		Archive_Table->DefaultCellStyle->WrapMode = DataGridViewTriState::True;
		Archive_Table->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;
		for each (DataGridViewColumn ^ col in Archive_Table->Columns) {
			col->SortMode = DataGridViewColumnSortMode::NotSortable;
		}
	}
	private: System::Void CopyStyleToArchiveTable() {
		Archive_Table->BackgroundColor = Table_post->BackgroundColor;
		Archive_Table->BorderStyle = Table_post->BorderStyle;
		Archive_Table->GridColor = Table_post->GridColor;
		Archive_Table->CellBorderStyle = Table_post->CellBorderStyle;
		Archive_Table->RowHeadersVisible = Table_post->RowHeadersVisible;
		Archive_Table->ReadOnly = Table_post->ReadOnly;
		Archive_Table->AllowUserToAddRows = Table_post->AllowUserToAddRows;
		Archive_Table->AllowUserToDeleteRows = Table_post->AllowUserToDeleteRows;

		Archive_Table->ColumnHeadersDefaultCellStyle = Table_post->ColumnHeadersDefaultCellStyle;
		Archive_Table->DefaultCellStyle = Table_post->DefaultCellStyle;
		Archive_Table->RowsDefaultCellStyle = Table_post->RowsDefaultCellStyle;

		Archive_Table->BackColor = Table_post->BackColor;
		Archive_Table->ForeColor = Table_post->ForeColor;
	}
	
	private: System::Void LoadGroupID() {
		try {
			String^ query_Auth = "SELECT TOP 1 [ID_Group] FROM Login ORDER BY [ID]";
			OleDbCommand^ cmd = gcnew OleDbCommand(query_Auth, DBconnection_login);
			Object^ result = cmd->ExecuteScalar();
			if (result != nullptr && result != DBNull::Value) {
				ID_Group_text->Text = safe_cast<String^>(result);
			}
			else {
				ID_Group_text->Text = "";
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка загрузки настроек:\n" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			ID_Group_text->Text = "";
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Panel_New_post->Visible == false) {
			Panel_New_post->Visible = true;
			button_New_post->Text = L"Закрыть окно";
		}
		else {
			Panel_New_post->Visible = false;
			button_New_post->Text = L"Добавить пост";
		}
	}
	private: System::Void Save_button_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			
			String^ insertQuery = "INSERT INTO TablePost ([Date_post], [name_post], [About_post], [Text_post], [Scencens_post], [ViewMedia_post], [Files]) "
				"VALUES (?, ?, ?, ?, ?, ?, ?)";

			OleDbCommand^ cmd = gcnew OleDbCommand(insertQuery, DBconnection_post);
			DateTime selectedDate = Swith_date_new_post->Value;
			DateTime dateAt9AM = selectedDate.Date + TimeSpan(9, 0, 0);
			cmd->Parameters->AddWithValue("@Date_post", dateAt9AM);
			cmd->Parameters->AddWithValue("@name_post", Textbox_Name_new_post->Text);
			Object^ aboutValue = String::IsNullOrWhiteSpace(Textbox_About_new_post->Text)
				? static_cast<Object^>(DBNull::Value)
				: safe_cast<Object^>(Textbox_About_new_post->Text);
			cmd->Parameters->AddWithValue("@About_post", aboutValue);

			Object^ textValue = String::IsNullOrWhiteSpace(textBox_Text_New_post->Text)
				? static_cast<Object^>(DBNull::Value)
				: safe_cast<Object^>(textBox_Text_New_post->Text);
			cmd->Parameters->AddWithValue("@Text_post", textValue);

			Object^ scencensValue = String::IsNullOrWhiteSpace(textBox_Continuity_new_post->Text)
				? static_cast<Object^>(DBNull::Value)
				: safe_cast<Object^>(textBox_Continuity_new_post->Text);
			cmd->Parameters->AddWithValue("@Scencens_post", scencensValue);

			Object^ mediaValue = String::IsNullOrWhiteSpace(Swith_view_media->Text) || Swith_view_media->SelectedIndex == -1
				? static_cast<Object^>(DBNull::Value)
				: safe_cast<Object^>(Swith_view_media->Text);
			cmd->Parameters->AddWithValue("@ViewMedia_post", mediaValue);

			Object^ filesValue = selectedFileForNewPost
				? safe_cast<Object^>(selectedFileForNewPost)
				: static_cast<Object^>(DBNull::Value);
			cmd->Parameters->AddWithValue("@Files", filesValue);

			int rowsAffected = cmd->ExecuteNonQuery();

			MyForm_Load(sender, e);

			Panel_New_post->Visible = false;
			button_New_post->Text = L"Добавить пост";

			Textbox_Name_new_post->Clear();
			Textbox_About_new_post->Clear();
			textBox_Text_New_post->Clear();
			textBox_Continuity_new_post->Clear();
			Swith_view_media->SelectedIndex = 0;

		}catch(Exception^ ex){
			MessageBox::Show("Ошибка сохранения:\n" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		selectedFileForNewPost = nullptr;
		linkFile->Visible = false;
		BtnAddFiles->Text = L"Добавить файл";
	}

	
	private: System::Void Table_post_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;

		int editColIndex = Table_post->Columns["EditButton"]->Index;
		int deleteColIndex = Table_post->Columns["DeleteButton"]->Index;

		if (e->ColumnIndex == Table_post->Columns["ViewMedia_post"]->Index) {
			DataGridViewRow^ row = Table_post->Rows[e->RowIndex];
			Object^ fileObj = row->Cells["Files_post"]->Value;

			if (fileObj != nullptr && fileObj != DBNull::Value) {
				String^ relativePath = safe_cast<String^>(fileObj);
				String^ fullPath = System::IO::Path::Combine(Application::StartupPath, relativePath);

				if (System::IO::File::Exists(fullPath)) {
					try {
						System::Diagnostics::Process::Start(fullPath);
					}
					catch (Exception^ ex) {
						MessageBox::Show("Не удалось открыть файл:\n" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
				else {
					MessageBox::Show("Файл не найден:\n" + fullPath, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			else {
				MessageBox::Show("К этому посту не прикреплён файл.", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			return;
		}
		if (e->ColumnIndex == editColIndex) {
			
			DataGridViewRow^ row = Table_post->Rows[e->RowIndex];
			Object^ idObj = row->Cells["ID"]->Value;
			if (idObj == nullptr || idObj == DBNull::Value) {
				MessageBox::Show("Не удалось загрузить ID записи.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			currentEditPostID = Convert::ToInt32(idObj);

			Object^ dateObj = row->Cells["Date_post"]->Value;
			Object^ nameObj = row->Cells["name_post"]->Value;
			Object^ aboutObj = row->Cells["About_post"]->Value;
			Object^ textObj = row->Cells["Text_post"]->Value;
			Object^ scencensObj = row->Cells["Scencens_post"]->Value;
			Object^ mediaObj = row->Cells["ViewMedia_post"]->Value;
			Object^ FileObj = row->Cells["Files_post"]->Value;

			if (dateObj != nullptr && dateObj != DBNull::Value) {
				dateTimePicker_Editpost->Value = safe_cast<DateTime>(dateObj);
			}

			Name_Edit_post->Text = (nameObj != nullptr && nameObj != DBNull::Value) ? safe_cast<String^>(nameObj) : "";
			About_Edit_post->Text = (aboutObj != nullptr && aboutObj != DBNull::Value) ? safe_cast<String^>(aboutObj) : "";
			text_Edit_post->Text = (textObj != nullptr && textObj != DBNull::Value) ? safe_cast<String^>(textObj) : "";
			Continuity_Edit_post->Text = (scencensObj != nullptr && scencensObj != DBNull::Value) ? safe_cast<String^>(scencensObj) : "";
			linkEditFile->Text = (FileObj != nullptr && FileObj != DBNull::Value) ? safe_cast<String^>(FileObj) : "";

			View_media_Edit->SelectedIndex = -1;
			if (mediaObj != nullptr && mediaObj != DBNull::Value) {
				String^ mediaStr = safe_cast<String^>(mediaObj);
				for (int i = 0; i < View_media_Edit->Items->Count; i++) {
					if (View_media_Edit->Items[i]->ToString() == mediaStr) {
						View_media_Edit->SelectedIndex = i;
						break;
					}
				}
			}
			if (FileObj != nullptr && FileObj != DBNull::Value) {
				String^ fileName = safe_cast<String^>(FileObj);
				linkEditFile->Text = fileName;
				linkEditFile->Visible = true;
				selectedFileForEditPost = fileName;
			}
			else {
				linkEditFile->Text = "";
				linkEditFile->Visible = false;
				selectedFileForEditPost = nullptr;
			}
			if (Edit_post->Visible == true) {
				Edit_post->Visible = false;
			}else { Edit_post->Visible = true; }
			
		}else if (e->ColumnIndex == deleteColIndex) {
			String^ postName = safe_cast<String^>(Table_post->Rows[e->RowIndex]->Cells["name_post"]->Value);
			System::Windows::Forms::DialogResult res = MessageBox::Show(
				"Удалить пост \"" + postName + "\"?",
				"Подтверждение",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question
			);
			if (res == System::Windows::Forms::DialogResult::Yes) {
				try {
					String^ deleteQuery = "DELETE FROM TablePost WHERE [ID] = ?";
					OleDbCommand^ cmd = gcnew OleDbCommand(deleteQuery, DBconnection_post);
					int idToDelete = Convert::ToInt32(Table_post->Rows[e->RowIndex]->Cells["ID"]->Value);
					cmd->Parameters->AddWithValue("@ID", idToDelete);
					cmd->ExecuteNonQuery();
					MyForm_Load(this, gcnew System::EventArgs());
				}
				catch (Exception^ ex) {
					MessageBox::Show("Ошибка удаления:\n" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
	}

	private: System::Void Archive_Table_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex < 0) return;
		int returnColIndex = Archive_Table->Columns["BtnReturn"]->Index;

		if (e->ColumnIndex == Archive_Table->Columns["Archive_ViewMedia"]->Index) {
			DataGridViewRow^ row = Archive_Table->Rows[e->RowIndex];
			Object^ fileObj = row->Cells["Archive_post"]->Value;
			if (fileObj != nullptr && fileObj != DBNull::Value) {
				String^ relativePath = safe_cast<String^>(fileObj);
				String^ fullPath = System::IO::Path::Combine(Application::StartupPath, relativePath);
				if (System::IO::File::Exists(fullPath)) {
					try {
						System::Diagnostics::Process::Start(fullPath);
					}
					catch (Exception^ ex) {
						MessageBox::Show("Не удалось открыть файл:" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
				else {
					MessageBox::Show("Файл не найден:" + fullPath, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			else {
				MessageBox::Show("К этому посту не прикреплён файл.", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			return;
		}

		if (e->ColumnIndex == returnColIndex) {
			DataGridViewRow^ row = Archive_Table->Rows[e->RowIndex];
			Object^ idObj = row->Cells["Archive_ID"]->Value;
			if (idObj == nullptr || idObj == DBNull::Value) {
				MessageBox::Show("Не удалось загрузить ID записи.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			currentEditPostID = Convert::ToInt32(idObj);
			isEditingFromArchive = true;

			Object^ dateObj = row->Cells["Archive_Data"]->Value;
			Object^ nameObj = row->Cells["Archive_Name"]->Value;
			Object^ aboutObj = row->Cells["Archive_About"]->Value;
			Object^ textObj = row->Cells["Archive_Text"]->Value;
			Object^ scencensObj = row->Cells["Archive_Scencens"]->Value;
			Object^ mediaObj = row->Cells["Archive_ViewMedia"]->Value;
			Object^ fileObj = row->Cells["Archive_post"]->Value;

			if (dateObj != nullptr && dateObj != DBNull::Value) {
				dateTimePicker_Editpost->Value = safe_cast<DateTime>(dateObj);
			}
			Name_Edit_post->Text = (nameObj != nullptr && nameObj != DBNull::Value) ? safe_cast<String^>(nameObj) : "";
			About_Edit_post->Text = (aboutObj != nullptr && aboutObj != DBNull::Value) ? safe_cast<String^>(aboutObj) : "";
			text_Edit_post->Text = (textObj != nullptr && textObj != DBNull::Value) ? safe_cast<String^>(textObj) : "";
			Continuity_Edit_post->Text = (scencensObj != nullptr && scencensObj != DBNull::Value) ? safe_cast<String^>(scencensObj) : "";
			linkEditFile->Text = (fileObj != nullptr && fileObj != DBNull::Value) ? safe_cast<String^>(fileObj) : "";

			View_media_Edit->SelectedIndex = -1;
			if (mediaObj != nullptr && mediaObj != DBNull::Value) {
				String^ mediaStr = safe_cast<String^>(mediaObj);
				for (int i = 0; i < View_media_Edit->Items->Count; i++) {
					if (View_media_Edit->Items[i]->ToString() == mediaStr) {
						View_media_Edit->SelectedIndex = i;
						break;
					}
				}
			}

			if (fileObj != nullptr && fileObj != DBNull::Value) {
				String^ fileName = safe_cast<String^>(fileObj);
				linkEditFile->Text = fileName;
				linkEditFile->Visible = true;
				selectedFileForEditPost = fileName;
			}
			else {
				linkEditFile->Visible = false;
				selectedFileForEditPost = nullptr;
			}

			Edit_post->Visible = true;
		}
	}
	private: System::Void Save_editbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ updateQuery;
			if (isEditingFromArchive) {
				updateQuery = "UPDATE TablePost SET " +
					"[Date_post] = ?, " +
					"[name_post] = ?, " +
					"[About_post] = ?, " +
					"[Text_post] = ?, " +
					"[Scencens_post] = ?, " +
					"[ViewMedia_post] = ?, " +
					"[Files] = ?, " +
					"[Published] = False " + 
					"WHERE [ID] = ?";
			}
			else {
				updateQuery = "UPDATE TablePost SET " +
					"[Date_post] = ?, " +
					"[name_post] = ?, " +
					"[About_post] = ?, " +
					"[Text_post] = ?, " +
					"[Scencens_post] = ?, " +
					"[ViewMedia_post] = ?, " +
					"[Files] = ? " +
					"WHERE [ID] = ?";
			}

			OleDbCommand^ cmd = gcnew OleDbCommand(updateQuery, DBconnection_post);
			DateTime selectedDate = dateTimePicker_Editpost->Value;
			DateTime dateAt9AM = selectedDate.Date + TimeSpan(9, 0, 0);
			cmd->Parameters->AddWithValue("@Date_post", dateAt9AM);
			cmd->Parameters->AddWithValue("@name_post", Name_Edit_post->Text);
			Object^ aboutValue = String::IsNullOrWhiteSpace(About_Edit_post->Text)
				? static_cast<Object^>(DBNull::Value)
				: safe_cast<Object^>(About_Edit_post->Text);
			cmd->Parameters->AddWithValue("@About_post", aboutValue);
			Object^ textValue = String::IsNullOrWhiteSpace(text_Edit_post->Text)
				? static_cast<Object^>(DBNull::Value)
				: safe_cast<Object^>(text_Edit_post->Text);
			cmd->Parameters->AddWithValue("@Text_post", textValue);
			Object^ scencensValue = String::IsNullOrWhiteSpace(Continuity_Edit_post->Text)
				? static_cast<Object^>(DBNull::Value)
				: safe_cast<Object^>(Continuity_Edit_post->Text);
			cmd->Parameters->AddWithValue("@Scencens_post", scencensValue);
			Object^ mediaValue = String::IsNullOrWhiteSpace(View_media_Edit->Text) || View_media_Edit->SelectedIndex == 0
				? static_cast<Object^>(DBNull::Value)
				: safe_cast<Object^>(View_media_Edit->Text);
			cmd->Parameters->AddWithValue("@ViewMedia_post", mediaValue);
			Object^ filesValue = selectedFileForEditPost
				? safe_cast<Object^>(selectedFileForEditPost)
				: static_cast<Object^>(DBNull::Value);
			cmd->Parameters->AddWithValue("@Files", filesValue);
			cmd->Parameters->AddWithValue("@ID", currentEditPostID);

			int rowsAffected = cmd->ExecuteNonQuery();
			if (rowsAffected <= 0) {
				MessageBox::Show("Не найден пост для обновления.", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

			isEditingFromArchive = false;
			MyForm_Load(this, gcnew System::EventArgs());
			Edit_post->Visible = false;
			currentEditPostID = 0;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка обновления:\n" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		selectedFileForEditPost = nullptr;
		linkEditFile->Visible = false;
		BtnEditFile->Text = L"Добавить файл";
	}
	private: System::Void BtnAddFiles_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				String^ src = openFileDialog->FileName;
				String^ fileName = System::IO::Path::GetFileName(src);
				String^ filePostDir = System::IO::Path::Combine(Application::StartupPath, "FilePost");
				String^ dest = System::IO::Path::Combine(filePostDir, fileName);
				System::IO::File::Copy(src, dest, true);
				selectedFileForNewPost = MyForm::GetRelativePath(Application::StartupPath, dest);
				linkFile->Text = fileName;
				linkFile->Visible = true;
				BtnAddFiles->Text = L"Изменить файл";
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	private: System::Void BtnEditFile_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				String^ src = openFileDialog->FileName;
				String^ fileName = System::IO::Path::GetFileName(src);
				String^ filePostDir = System::IO::Path::Combine(Application::StartupPath, "FilePost");
				String^ dest = System::IO::Path::Combine(filePostDir, fileName);
				System::IO::File::Copy(src, dest, true);
				selectedFileForEditPost = MyForm::GetRelativePath(Application::StartupPath, dest);
				linkEditFile->Text = fileName;
				linkEditFile->Visible = true;
				BtnEditFile->Text = L"Изменить файл";
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	private: System::Void Btnsettings_Click(System::Object^ sender, System::EventArgs^ e) {
		if (SettingsGroup->Visible == false) {
			SettingsGroup->Visible = true;
			LoadGroupID();
		}else{
			SettingsGroup->Visible = false;
		}
	}
	private: System::Void BtnSaveSettings_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ newGroupID = ID_Group_text->Text->Trim();
			String^ updateQuery = "UPDATE Login SET [ID_Group] = ? WHERE [ID] = 1";
			OleDbCommand^ cmd = gcnew OleDbCommand(updateQuery, DBconnection_login);
			cmd->Parameters->AddWithValue("@ID_Group", newGroupID == "" ? DBNull::Value : safe_cast<Object^>(newGroupID));
			int rowsAffected = cmd->ExecuteNonQuery();
			if (rowsAffected <= 0) {
				MessageBox::Show("Не удалось обновить настройки. Проверьте, существует ли запись с ID=1 в таблице Login.", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			SettingsGroup->Visible = false;
		}catch (Exception^ ex) {
			MessageBox::Show("Ошибка сохранения настроек:\n" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		try {
			if (DBconnection_post != nullptr && DBconnection_post->State == ConnectionState::Open) {
				DBconnection_post->Close();
			}
			if (DBconnection_login != nullptr && DBconnection_login->State == ConnectionState::Open) {
				DBconnection_login->Close();
			}
		}
		catch (Exception^) {}
	}
	private: System::Void BtnArchive_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Archive_Table->Visible == false) {
			Archive_Table->Visible = true;
			BtnArchive->Text = "Закрыть";
		}
		else {
			Archive_Table->Visible = false;
			BtnArchive->Text = "Архив";
		}
	}
}; }