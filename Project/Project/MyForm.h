#pragma once
namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		static String^ connectString =
			"Server=192.168.0.58,58907;"  // IP сервера
			"Database=Database_program;"
			"User Id=CVuser;"
			"Password=wpM2JV@Kk-;"
			"Encrypt=False;";
	private: System::Windows::Forms::Label^ Name_new_post;
	private: System::Windows::Forms::TextBox^ Textbox_Name_new_post;
	private: System::Windows::Forms::Label^ About_new_post;
	private: System::Windows::Forms::TextBox^ Textbox_About_new_post;
	private: System::Windows::Forms::Label^ Date_new_post;
	private: System::Windows::Forms::DateTimePicker^ Swith_date_new_post;
	private: System::Windows::Forms::DateTimePicker^ TimePicker_new_post;
	private: System::Windows::Forms::DateTimePicker^ TimePicker_Editpost;
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
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::GroupBox^ Authorization;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ Authorization_Login;


	private: System::Windows::Forms::Button^ BTNAuthorization;
	private: System::Windows::Forms::TextBox^ Authorization_Password;







	private: System::Windows::Forms::LinkLabel^ Btn_new_user;
	private: System::Windows::Forms::GroupBox^ Registr_group;

	private: System::Windows::Forms::TextBox^ registr_password_repeat;
	private: System::Windows::Forms::Button^ Btn_registr;


	private: System::Windows::Forms::TextBox^ registr_password;
	private: System::Windows::Forms::TextBox^ registr_Login;




	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ btn_Show_repeat_Password;
	private: System::Windows::Forms::Button^ btn_Show_Password;
	private: System::Windows::Forms::Button^ Add_bot_settings;


	private: System::Windows::Forms::LinkLabel^ SignUp;








	private:
		SqlConnection^ DBconnection;
		int currentEditPostID;
		Nullable<int> currentUserId;
		String^ selectedFileForNewPost;
		String^ selectedFileForEditPost;
		String^ HistoryFileNewPost;
		String^ HistoryFileEditPost;
	private:
		bool isEditingFromArchive = false;
	private:
		System::Boolean IsAdminUser();
		System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void LoadArchiveData();
		System::Void CopyStyleToArchiveTable();
		System::Void LoadGroupID();
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Save_button_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Table_post_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		System::Void Archive_Table_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		System::Void Save_editbutton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void BtnAddFiles_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void BtnEditFile_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Btnsettings_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void BtnSaveSettings_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
		System::Void BtnArchive_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void BTNAuthorization_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Btn_new_user_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
		System::Void SignUp_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
		System::Void Btn_registr_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Authorization_Login_Enter(System::Object^ sender, System::EventArgs^ e);
		System::Void Authorization_Login_Leave(System::Object^ sender, System::EventArgs^ e);
		System::Void Authorization_Password_Enter(System::Object^ sender, System::EventArgs^ e);
		System::Void Authorization_Password_Leave(System::Object^ sender, System::EventArgs^ e);
		System::Void registr_Login_Enter(System::Object^ sender, System::EventArgs^ e);
		System::Void registr_Login_Leave(System::Object^ sender, System::EventArgs^ e);
		System::Void registr_password_Enter(System::Object^ sender, System::EventArgs^ e);
		System::Void registr_password_Leave(System::Object^ sender, System::EventArgs^ e);
		System::Void registr_password_repeat_Enter(System::Object^ sender, System::EventArgs^ e);
		System::Void registr_password_repeat_Leave(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Show_repeat_Password_MouseLeave(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Show_repeat_Password_MouseEnter(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Show_repeat_Password_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void btn_Show_Password_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void btn_Show_Password_MouseEnter(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Show_Password_MouseLeave(System::Object^ sender, System::EventArgs^ e);
		System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e);
		System::Void Add_bot_settings_Click(System::Object^ sender, System::EventArgs^ e);

		//Таймер обновления БД
		System::Windows::Forms::Timer^ refreshTimer;
		System::Void OnRefreshTimerTick(System::Object^ sender, System::EventArgs^ e);
	public:
		MyForm(void)
		{
			InitializeComponent();

			DBconnection = gcnew SqlConnection(connectString);

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

			try {
				DBconnection->Open();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка подключения к базе данных:\n" + ex->Message,
					"Критическая ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				Application::Exit();
				return;
			}

			refreshTimer = gcnew System::Windows::Forms::Timer();
			refreshTimer->Interval = 10000; // 10 секунд
			refreshTimer->Tick += gcnew System::EventHandler(this, &MyForm::OnRefreshTimerTick);
			refreshTimer->Start();
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button_New_post = (gcnew System::Windows::Forms::Button());
			this->Name_new_post = (gcnew System::Windows::Forms::Label());
			this->Textbox_Name_new_post = (gcnew System::Windows::Forms::TextBox());
			this->About_new_post = (gcnew System::Windows::Forms::Label());
			this->Textbox_About_new_post = (gcnew System::Windows::Forms::TextBox());
			this->Date_new_post = (gcnew System::Windows::Forms::Label());
			this->Swith_date_new_post = (gcnew System::Windows::Forms::DateTimePicker());
			this->view_media = (gcnew System::Windows::Forms::Label());
			this->TimePicker_new_post = (gcnew System::Windows::Forms::DateTimePicker());
			this->TimePicker_Editpost = (gcnew System::Windows::Forms::DateTimePicker());
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
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Authorization = (gcnew System::Windows::Forms::GroupBox());
			this->btn_Show_Password = (gcnew System::Windows::Forms::Button());
			this->Btn_new_user = (gcnew System::Windows::Forms::LinkLabel());
			this->BTNAuthorization = (gcnew System::Windows::Forms::Button());
			this->Authorization_Password = (gcnew System::Windows::Forms::TextBox());
			this->Authorization_Login = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Registr_group = (gcnew System::Windows::Forms::GroupBox());
			this->btn_Show_repeat_Password = (gcnew System::Windows::Forms::Button());
			this->SignUp = (gcnew System::Windows::Forms::LinkLabel());
			this->registr_password_repeat = (gcnew System::Windows::Forms::TextBox());
			this->Btn_registr = (gcnew System::Windows::Forms::Button());
			this->registr_password = (gcnew System::Windows::Forms::TextBox());
			this->registr_Login = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->Add_bot_settings = (gcnew System::Windows::Forms::Button());
			this->Panel_New_post->SuspendLayout();
			this->Edit_post->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Archive_Table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table_post))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SettingsGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->Authorization->SuspendLayout();
			this->Registr_group->SuspendLayout();
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
			// TimePicker_new_post
			// 
			this->TimePicker_new_post->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			resources->ApplyResources(this->TimePicker_new_post, L"TimePicker_new_post");
			this->TimePicker_new_post->Name = L"TimePicker_new_post";
			this->TimePicker_new_post->ShowUpDown = true;
			this->TimePicker_new_post->Value = System::DateTime(2025, 11, 16, 9, 0, 0, 0);
			// 
			// TimePicker_Editpost
			// 
			this->TimePicker_Editpost->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			resources->ApplyResources(this->TimePicker_Editpost, L"TimePicker_Editpost");
			this->TimePicker_Editpost->Name = L"TimePicker_Editpost";
			this->TimePicker_Editpost->ShowUpDown = true;
			this->TimePicker_Editpost->Value = System::DateTime(2025, 11, 16, 16, 9, 31, 0);
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
			this->Panel_New_post->Controls->Add(this->Swith_date_new_post);
			this->Panel_New_post->Controls->Add(this->Date_new_post);
			this->Panel_New_post->Controls->Add(this->TimePicker_new_post);
			this->Panel_New_post->Controls->Add(this->view_media);
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
			this->Edit_post->Controls->Add(this->TimePicker_Editpost);
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
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F));
			dataGridViewCellStyle7->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle7->Padding = System::Windows::Forms::Padding(5);
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->Archive_Table->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle7;
			this->Archive_Table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->Archive_Table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->Archive_ID,
					this->Archive_Data, this->Archive_Name, this->Archive_About, this->Archive_Text, this->Archive_Scencens, this->Archive_ViewMedia,
					this->Archive_post, this->BtnReturn
			});
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F));
			dataGridViewCellStyle8->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Archive_Table->DefaultCellStyle = dataGridViewCellStyle8;
			this->Archive_Table->GridColor = System::Drawing::Color::Black;
			this->Archive_Table->Name = L"Archive_Table";
			this->Archive_Table->ReadOnly = true;
			dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Archive_Table->RowsDefaultCellStyle = dataGridViewCellStyle9;
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
			dataGridViewCellStyle10->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle10->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F));
			dataGridViewCellStyle10->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle10->Padding = System::Windows::Forms::Padding(5);
			dataGridViewCellStyle10->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle10->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle10->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->Table_post->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle10;
			this->Table_post->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->Table_post->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->ID, this->Date_post,
					this->name_post, this->About_post, this->Text_post, this->Scencens_post, this->ViewMedia_post, this->Files_post, this->EditButton,
					this->DeleteButton
			});
			dataGridViewCellStyle11->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle11->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F));
			dataGridViewCellStyle11->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle11->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(71)));
			dataGridViewCellStyle11->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle11->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->Table_post->DefaultCellStyle = dataGridViewCellStyle11;
			this->Table_post->GridColor = System::Drawing::Color::Black;
			this->Table_post->Name = L"Table_post";
			this->Table_post->ReadOnly = true;
			dataGridViewCellStyle12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Table_post->RowsDefaultCellStyle = dataGridViewCellStyle12;
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
			resources->ApplyResources(this->SettingsGroup, L"SettingsGroup");
			this->SettingsGroup->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->SettingsGroup->Controls->Add(this->Add_bot_settings);
			this->SettingsGroup->Controls->Add(this->BtnSaveSettings);
			this->SettingsGroup->Controls->Add(this->ID_Group_text);
			this->SettingsGroup->Controls->Add(this->label7);
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
			// pictureBox2
			// 
			resources->ApplyResources(this->pictureBox2, L"pictureBox2");
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->TabStop = false;
			// 
			// Authorization
			// 
			resources->ApplyResources(this->Authorization, L"Authorization");
			this->Authorization->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(150)));
			this->Authorization->Controls->Add(this->btn_Show_Password);
			this->Authorization->Controls->Add(this->Btn_new_user);
			this->Authorization->Controls->Add(this->BTNAuthorization);
			this->Authorization->Controls->Add(this->Authorization_Password);
			this->Authorization->Controls->Add(this->Authorization_Login);
			this->Authorization->Controls->Add(this->label8);
			this->Authorization->ForeColor = System::Drawing::Color::White;
			this->Authorization->Name = L"Authorization";
			this->Authorization->TabStop = false;
			// 
			// btn_Show_Password
			// 
			this->btn_Show_Password->BackColor = System::Drawing::Color::White;
			resources->ApplyResources(this->btn_Show_Password, L"btn_Show_Password");
			this->btn_Show_Password->Name = L"btn_Show_Password";
			this->btn_Show_Password->UseVisualStyleBackColor = false;
			this->btn_Show_Password->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::btn_Show_Password_MouseClick);
			this->btn_Show_Password->MouseEnter += gcnew System::EventHandler(this, &MyForm::btn_Show_Password_MouseEnter);
			this->btn_Show_Password->MouseLeave += gcnew System::EventHandler(this, &MyForm::btn_Show_Password_MouseLeave);
			// 
			// Btn_new_user
			// 
			resources->ApplyResources(this->Btn_new_user, L"Btn_new_user");
			this->Btn_new_user->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->Btn_new_user->Name = L"Btn_new_user";
			this->Btn_new_user->TabStop = true;
			this->Btn_new_user->VisitedLinkColor = System::Drawing::Color::Blue;
			this->Btn_new_user->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::Btn_new_user_LinkClicked);
			// 
			// BTNAuthorization
			// 
			resources->ApplyResources(this->BTNAuthorization, L"BTNAuthorization");
			this->BTNAuthorization->ForeColor = System::Drawing::Color::Black;
			this->BTNAuthorization->Name = L"BTNAuthorization";
			this->BTNAuthorization->UseVisualStyleBackColor = true;
			this->BTNAuthorization->Click += gcnew System::EventHandler(this, &MyForm::BTNAuthorization_Click);
			// 
			// Authorization_Password
			// 
			this->Authorization_Password->ForeColor = System::Drawing::Color::Gray;
			resources->ApplyResources(this->Authorization_Password, L"Authorization_Password");
			this->Authorization_Password->Name = L"Authorization_Password";
			this->Authorization_Password->Enter += gcnew System::EventHandler(this, &MyForm::Authorization_Password_Enter);
			this->Authorization_Password->Leave += gcnew System::EventHandler(this, &MyForm::Authorization_Password_Leave);
			// 
			// Authorization_Login
			// 
			this->Authorization_Login->ForeColor = System::Drawing::Color::Gray;
			resources->ApplyResources(this->Authorization_Login, L"Authorization_Login");
			this->Authorization_Login->Name = L"Authorization_Login";
			this->Authorization_Login->Enter += gcnew System::EventHandler(this, &MyForm::Authorization_Login_Enter);
			this->Authorization_Login->Leave += gcnew System::EventHandler(this, &MyForm::Authorization_Login_Leave);
			// 
			// label8
			// 
			resources->ApplyResources(this->label8, L"label8");
			this->label8->Name = L"label8";
			// 
			// Registr_group
			// 
			resources->ApplyResources(this->Registr_group, L"Registr_group");
			this->Registr_group->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(150)));
			this->Registr_group->Controls->Add(this->btn_Show_repeat_Password);
			this->Registr_group->Controls->Add(this->SignUp);
			this->Registr_group->Controls->Add(this->registr_password_repeat);
			this->Registr_group->Controls->Add(this->Btn_registr);
			this->Registr_group->Controls->Add(this->registr_password);
			this->Registr_group->Controls->Add(this->registr_Login);
			this->Registr_group->Controls->Add(this->label10);
			this->Registr_group->ForeColor = System::Drawing::Color::White;
			this->Registr_group->Name = L"Registr_group";
			this->Registr_group->TabStop = false;
			// 
			// btn_Show_repeat_Password
			// 
			this->btn_Show_repeat_Password->BackColor = System::Drawing::Color::White;
			resources->ApplyResources(this->btn_Show_repeat_Password, L"btn_Show_repeat_Password");
			this->btn_Show_repeat_Password->Name = L"btn_Show_repeat_Password";
			this->btn_Show_repeat_Password->UseVisualStyleBackColor = false;
			this->btn_Show_repeat_Password->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::btn_Show_repeat_Password_MouseClick);
			this->btn_Show_repeat_Password->MouseEnter += gcnew System::EventHandler(this, &MyForm::btn_Show_repeat_Password_MouseEnter);
			this->btn_Show_repeat_Password->MouseLeave += gcnew System::EventHandler(this, &MyForm::btn_Show_repeat_Password_MouseLeave);
			// 
			// SignUp
			// 
			resources->ApplyResources(this->SignUp, L"SignUp");
			this->SignUp->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->SignUp->Name = L"SignUp";
			this->SignUp->TabStop = true;
			this->SignUp->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::SignUp_LinkClicked);
			// 
			// registr_password_repeat
			// 
			this->registr_password_repeat->ForeColor = System::Drawing::Color::Gray;
			resources->ApplyResources(this->registr_password_repeat, L"registr_password_repeat");
			this->registr_password_repeat->Name = L"registr_password_repeat";
			this->registr_password_repeat->Enter += gcnew System::EventHandler(this, &MyForm::registr_password_repeat_Enter);
			this->registr_password_repeat->Leave += gcnew System::EventHandler(this, &MyForm::registr_password_repeat_Leave);
			// 
			// Btn_registr
			// 
			resources->ApplyResources(this->Btn_registr, L"Btn_registr");
			this->Btn_registr->ForeColor = System::Drawing::Color::Black;
			this->Btn_registr->Name = L"Btn_registr";
			this->Btn_registr->UseVisualStyleBackColor = true;
			this->Btn_registr->Click += gcnew System::EventHandler(this, &MyForm::Btn_registr_Click);
			// 
			// registr_password
			// 
			this->registr_password->ForeColor = System::Drawing::Color::Gray;
			resources->ApplyResources(this->registr_password, L"registr_password");
			this->registr_password->Name = L"registr_password";
			this->registr_password->Enter += gcnew System::EventHandler(this, &MyForm::registr_password_Enter);
			this->registr_password->Leave += gcnew System::EventHandler(this, &MyForm::registr_password_Leave);
			// 
			// registr_Login
			// 
			this->registr_Login->ForeColor = System::Drawing::Color::Gray;
			resources->ApplyResources(this->registr_Login, L"registr_Login");
			this->registr_Login->Name = L"registr_Login";
			this->registr_Login->Enter += gcnew System::EventHandler(this, &MyForm::registr_Login_Enter);
			this->registr_Login->Leave += gcnew System::EventHandler(this, &MyForm::registr_Login_Leave);
			// 
			// label10
			// 
			resources->ApplyResources(this->label10, L"label10");
			this->label10->Name = L"label10";
			// 
			// Add_bot_settings
			// 
			resources->ApplyResources(this->Add_bot_settings, L"Add_bot_settings");
			this->Add_bot_settings->ForeColor = System::Drawing::Color::Black;
			this->Add_bot_settings->Name = L"Add_bot_settings";
			this->Add_bot_settings->UseVisualStyleBackColor = true;
			this->Add_bot_settings->Click += gcnew System::EventHandler(this, &MyForm::Add_bot_settings_Click);
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			
			this->Controls->Add(this->Registr_group);
			this->Controls->Add(this->Authorization);
			this->Controls->Add(this->pictureBox2);
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
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->Panel_New_post->ResumeLayout(false);
			this->Panel_New_post->PerformLayout();
			this->Edit_post->ResumeLayout(false);
			this->Edit_post->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Archive_Table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table_post))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->SettingsGroup->ResumeLayout(false);
			this->SettingsGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->Authorization->ResumeLayout(false);
			this->Authorization->PerformLayout();
			this->Registr_group->ResumeLayout(false);
			this->Registr_group->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	};
}