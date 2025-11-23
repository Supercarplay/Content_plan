#pragma endregion
#include "MyForm.h"
using namespace Project;
using namespace System;
//Акаунт с правами Администатора
System::Boolean Project::MyForm::IsAdminUser() {
	if (!currentUserId.HasValue) return false;
	try {
		String^ query = "SELECT [Name_Users] FROM Login WHERE [ID] = @ID";
		SqlCommand^ cmd = gcnew SqlCommand(query, DBconnection);
		cmd->Parameters->AddWithValue("@ID", currentUserId.Value);
		Object^ result = cmd->ExecuteScalar();
		if (result != nullptr && result != DBNull::Value) {
			String^ username = safe_cast<String^>(result);
			return (username->Equals("Admin", StringComparison::OrdinalIgnoreCase));
		}
	}
	catch (Exception^) {
	}
	return false;
}
//Функционал приложения при загрузке и закрытие
System::Void Project::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
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

	String^ query;
	SqlCommand^ command;
	if (IsAdminUser()) {
		query = "SELECT [ID], [Date_post], [name_post], [About_post], [Text_post], [Scencens_post], [ViewMedia_post], [Files] "
			"FROM TablePost WHERE [Published] = 0 ORDER BY [Date_post]";
		command = gcnew SqlCommand(query, DBconnection);
	}
	else {
		query = "SELECT [ID], [Date_post], [name_post], [About_post], [Text_post], [Scencens_post], [ViewMedia_post], [Files] "
			"FROM TablePost WHERE [Published] = 0 AND [Users_ID] = @UserID ORDER BY [Date_post]";
		command = gcnew SqlCommand(query, DBconnection);
		if (currentUserId.HasValue) {
			command->Parameters->AddWithValue("@UserID", currentUserId.Value);
		}
		else {
			command->Parameters->AddWithValue("@UserID", DBNull::Value);
		}
	}
	SqlDataAdapter^ adapter = gcnew SqlDataAdapter(command);
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
System::Void Project::MyForm::LoadArchiveData() {
	Archive_Table->AutoGenerateColumns = false;
	Archive_Data->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
	Archive_Data->Width = 100;
	Archive_ViewMedia->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
	Archive_ViewMedia->Width = 100;
	BtnReturn->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
	BtnReturn->Width = 50;
	BtnReturn->UseColumnTextForButtonValue = true;
	BtnReturn->Text = L"↩";

	String^ query;
	SqlCommand^ command;
	if (IsAdminUser()) {
		query = "SELECT [ID], [Date_post], [name_post], [About_post], [Text_post], [Scencens_post], [ViewMedia_post], [Files] "
			"FROM TablePost WHERE [Published] = 1 ORDER BY [Date_post]";
		command = gcnew SqlCommand(query, DBconnection);
	}
	else {
		query = "SELECT [ID], [Date_post], [name_post], [About_post], [Text_post], [Scencens_post], [ViewMedia_post], [Files] "
			"FROM TablePost WHERE [Published] = 1 AND [Users_ID] = @UserID ORDER BY [Date_post]";
		command = gcnew SqlCommand(query, DBconnection);
		if (currentUserId.HasValue) {
			command->Parameters->AddWithValue("@UserID", currentUserId.Value);
		}
		else {
			command->Parameters->AddWithValue("@UserID", DBNull::Value);
		}
	}
	SqlDataAdapter^ adapter = gcnew SqlDataAdapter(command);
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
System::Void Project::MyForm::CopyStyleToArchiveTable() {
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

System::Void Project::MyForm::LoadGroupID() {
	if (!currentUserId.HasValue) {
		ID_Group_text->Text = "";
		return;
	}
	try {
		String^ query = "SELECT [ID_Group] FROM Login WHERE [ID] = @ID";
		SqlCommand^ cmd = gcnew SqlCommand(query, DBconnection);
		cmd->Parameters->AddWithValue("@ID", currentUserId.Value);
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
System::Void Project::MyForm::MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	try {
		if (DBconnection != nullptr && DBconnection->State == ConnectionState::Open) {
			DBconnection->Close();
		}
	}
	catch (Exception^) {}
}
System::Void Project::MyForm::BtnArchive_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Archive_Table->Visible == false) {
		Archive_Table->Visible = true;
		BtnArchive->Text = "Закрыть";
	}
	else {
		Archive_Table->Visible = false;
		BtnArchive->Text = "Архив";
	}
}
//	Адаптация приложения при изменениях размеров
System::Void Project::MyForm::MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
	if (this->Width > 1400) {
		name_post->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		name_post->Width = 250;
		About_post->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		About_post->Width = 250;
		Archive_Name->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		Archive_Name->Width = 250;
		Archive_About->AutoSizeMode = DataGridViewAutoSizeColumnMode::None;
		Archive_About->Width = 250;
	}
	else {
		name_post->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		About_post->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		Archive_Name->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		Archive_About->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
	}
}
//
// Структура сохрананения новых постов
//
System::Void Project::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Panel_New_post->Visible == false) {
		Panel_New_post->Visible = true;
		button_New_post->Text = L"Закрыть окно";
	}
	else {
		Panel_New_post->Visible = false;
		button_New_post->Text = L"Добавить пост";
		try {
			DateTime selectedDate = Swith_date_new_post->Value;
			String^ DopName = selectedDate.ToString("yyyyMMdd");
			String^ filePostDir = System::IO::Path::Combine(Application::StartupPath, "FilePost");
			String^ DeleteFile = System::IO::Path::Combine(filePostDir, DopName + "_" + HistoryFileNewPost);
			String^ DeleteFileServer = System::IO::Path::Combine(serverDir, DopName + "_" + HistoryFileNewPost);
			if (System::IO::File::Exists(DeleteFile) && System::IO::File::Exists(DeleteFileServer)) {
				System::IO::File::Delete(DeleteFile);
				System::IO::File::Delete(DeleteFileServer);
			}
			linkFile->Text = L"Ссылка на файл";
			selectedFileForNewPost=nullptr;
			BtnAddFiles->Text = L"Добавить файл";
		}
		catch (Exception^ ex) {}
	}
}

System::Void Project::MyForm::Save_button_Click(System::Object^ sender, System::EventArgs^ e) {
	try {

		String^ insertQuery = "INSERT INTO TablePost ([Users_ID], [Date_post], [name_post], [About_post], [Text_post], [Scencens_post], [ViewMedia_post], [Files]) "
			"VALUES (@Users_ID, @Date_post, @name_post, @About_post, @Text_post, @Scencens_post, @ViewMedia_post, @Files)";

		SqlCommand^ cmd = gcnew SqlCommand(insertQuery, DBconnection);
		if (currentUserId.HasValue) {
			cmd->Parameters->AddWithValue("@Users_ID", currentUserId.Value);
		}
		else {
			cmd->Parameters->AddWithValue("@Users_ID", DBNull::Value);
		}
		DateTime selectedDate = Swith_date_new_post->Value;
		DateTime selectedTime = TimePicker_new_post->Value;
		DateTime combinedDateTime = selectedDate.Date + selectedTime.TimeOfDay;
		cmd->Parameters->AddWithValue("@Date_post", combinedDateTime);
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

		Object^ mediaValue = String::IsNullOrWhiteSpace(Swith_view_media->Text) || Swith_view_media->SelectedIndex == 0
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

	}
	catch (Exception^ ex) {
		MessageBox::Show("Ошибка сохранения:\n" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	selectedFileForNewPost = nullptr;
	linkFile->Visible = false;
	BtnAddFiles->Text = L"Добавить файл";
}
//
// Структура взаимодействия с кнопками удаление и редактирования и просмотр файла
//
System::Void Project::MyForm::Table_post_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex < 0) return;

	int editColIndex = Table_post->Columns["EditButton"]->Index;
	int deleteColIndex = Table_post->Columns["DeleteButton"]->Index;

	if (e->ColumnIndex == Table_post->Columns["ViewMedia_post"]->Index) {
		DataGridViewRow^ row = Table_post->Rows[e->RowIndex];
		Object^ fileObj = row->Cells["Files_post"]->Value;
		Object^ dateObj = row->Cells["Date_post"]->Value;
		String^ DopName;
		if (dateObj != nullptr && dateObj != DBNull::Value) {
			DateTime postDate = safe_cast<DateTime>(dateObj);
			DopName = postDate.ToString("yyyyMMdd");
		}
		if (fileObj != nullptr && fileObj != DBNull::Value) {
			String^ relativePath = safe_cast<String^>(fileObj);
			String^ filePostDir = System::IO::Path::Combine(Application::StartupPath, "FilePost");
			String^ fullPath = System::IO::Path::Combine(filePostDir, DopName + "_" + relativePath);

			if (System::IO::File::Exists(fullPath)) {
				try {
					System::Diagnostics::Process::Start(fullPath);
				}
				catch (Exception^ ex) {
					MessageBox::Show("Выполняется синхронизация, ожидайте", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
					SyncDirectories(localDir, serverDir);
				}
			}
			else {
				MessageBox::Show("Выполняется синхронизация, ожидайте", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
				SyncDirectories(localDir, serverDir);
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
			DateTime postDateTime = safe_cast<DateTime>(dateObj);
			dateTimePicker_Editpost->Value = postDateTime.Date;
			TimePicker_Editpost->Value = DateTime::Today + postDateTime.TimeOfDay;
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
		}
		else { Edit_post->Visible = true; }

	}
	else if (e->ColumnIndex == deleteColIndex) {
		String^ postName = safe_cast<String^>(Table_post->Rows[e->RowIndex]->Cells["name_post"]->Value);
		System::Windows::Forms::DialogResult res = MessageBox::Show(
			"Удалить пост \"" + postName + "\"?",
			"Подтверждение",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);
		if (res == System::Windows::Forms::DialogResult::Yes) {
			try {
				String^ fileName = Convert::ToString(Table_post->Rows[e->RowIndex]->Cells["Files_post"]->Value);
				String^ filePostDir = System::IO::Path::Combine(Application::StartupPath, "FilePost");
				String^ dest = System::IO::Path::Combine(filePostDir, fileName);

				String^ deleteQuery = "DELETE FROM TablePost WHERE [ID] = @ID";
				SqlCommand^ cmd = gcnew SqlCommand(deleteQuery, DBconnection);
				int idToDelete = Convert::ToInt32(Table_post->Rows[e->RowIndex]->Cells["ID"]->Value);
				cmd->Parameters->AddWithValue("@ID", idToDelete);
				if (System::IO::File::Exists(dest)) {
					System::IO::File::Delete(dest);
				}
				cmd->ExecuteNonQuery();
				MyForm_Load(this, gcnew System::EventArgs());
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка удаления:\n" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
}
//
// Структура взаимодействия с кнопками восстановления и просмотр файла в архиве
//
System::Void Project::MyForm::Archive_Table_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex < 0) return;
	int returnColIndex = Archive_Table->Columns["BtnReturn"]->Index;

	if (e->ColumnIndex == Archive_Table->Columns["Archive_ViewMedia"]->Index) {
		DataGridViewRow^ row = Archive_Table->Rows[e->RowIndex];
		Object^ fileObj = row->Cells["Archive_post"]->Value;
		Object^ dateObj = row->Cells["Date_post"]->Value;
		String^ DopName;
		if (dateObj != nullptr && dateObj != DBNull::Value) {
			DateTime postDate = safe_cast<DateTime>(dateObj);
			DopName = postDate.ToString("yyyyMMdd");
		}
		if (fileObj != nullptr && fileObj != DBNull::Value) {
			String^ relativePath = safe_cast<String^>(fileObj);
			String^ filePostDir = System::IO::Path::Combine(Application::StartupPath, "FilePost");
			String^ fullPath = System::IO::Path::Combine(filePostDir, DopName + "_" + relativePath);
			if (System::IO::File::Exists(fullPath)) {
				try {
					System::Diagnostics::Process::Start(fullPath);
				}
				catch (Exception^ ex) {
					MessageBox::Show("Выполняется синхронизация, ожидайте", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
					SyncDirectories(localDir, serverDir);
				}
			}
			else {
				MessageBox::Show("Выполняется синхронизация, ожидайте", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Information);
				SyncDirectories(localDir, serverDir);
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
			DateTime postDateTime = safe_cast<DateTime>(dateObj);
			dateTimePicker_Editpost->Value = postDateTime.Date;
			TimePicker_Editpost->Value = DateTime::Today + postDateTime.TimeOfDay;
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
//
//	Редактирование постов
//
System::Void Project::MyForm::Save_editbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ updateQuery;
		if (isEditingFromArchive) {
			updateQuery = "UPDATE TablePost SET " +
				"[Date_post] = @Date_post, " +
				"[name_post] = @name_post, " +
				"[About_post] = @About_post, " +
				"[Text_post] = @Text_post, " +
				"[Scencens_post] = @Scencens_post, " +
				"[ViewMedia_post] = @ViewMedia_post, " +
				"[Files] = @Files, " +
				"[Published] = 0 " +
				"WHERE [ID] = @ID";
		}
		else {
			updateQuery = "UPDATE TablePost SET " +
				"[Date_post] = @Date_post, " +
				"[name_post] = @name_post, " +
				"[About_post] = @About_post, " +
				"[Text_post] = @Text_post, " +
				"[Scencens_post] = @Scencens_post, " +
				"[ViewMedia_post] = @ViewMedia_post, " +
				"[Files] = @Files " +
				"WHERE [ID] = @ID";
		}

		SqlCommand^ cmd = gcnew SqlCommand(updateQuery, DBconnection);
		DateTime selectedDate = dateTimePicker_Editpost->Value;
		DateTime selectedTime = TimePicker_Editpost->Value;
		DateTime combinedDateTime = selectedDate.Date + selectedTime.TimeOfDay;
		cmd->Parameters->AddWithValue("@Date_post", combinedDateTime);
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
//
//	Добавление файлов
//
System::Void Project::MyForm::BtnAddFiles_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		try {
			DateTime selectedDate = Swith_date_new_post->Value;
			String^ DopName = selectedDate.ToString("yyyyMMdd");
			String^ src = openFileDialog->FileName;
			String^ fileName = System::IO::Path::GetFileName(src);
			String^ filePostDir = System::IO::Path::Combine(Application::StartupPath, "FilePost");
			String^ dest = System::IO::Path::Combine(filePostDir, DopName+"_"+fileName);
			String^ destServer = System::IO::Path::Combine(serverDir, DopName + "_" + fileName);
			System::IO::File::Copy(src, dest, true);
			System::IO::File::Copy(src, destServer, true);
			selectedFileForNewPost = fileName;
			//	Попытка удалить уже имеющися файл
			try{
				String^ DeleteFile = System::IO::Path::Combine(filePostDir, DopName+"_"+HistoryFileNewPost);
				String^ DeleteFileServer = System::IO::Path::Combine(destServer, DopName + "_" + HistoryFileNewPost);
				if (System::IO::File::Exists(DeleteFile) && System::IO::File::Exists(DeleteFileServer)) {
					System::IO::File::Delete(DeleteFile);
					System::IO::File::Delete(DeleteFileServer);
				}
			}catch (Exception^ ex){
				MessageBox::Show("Ошибка: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			linkFile->Text = fileName;
			linkFile->Visible = true;
			BtnAddFiles->Text = L"Изменить файл";
			HistoryFileNewPost = selectedFileForNewPost;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
System::Void Project::MyForm::BtnEditFile_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		try {
			DateTime selectedDate = Swith_date_new_post->Value;
			String^ DopName = selectedDate.ToString("yyyyMMdd");
			String^ src = openFileDialog->FileName;
			String^ fileName = System::IO::Path::GetFileName(src);
			String^ filePostDir = System::IO::Path::Combine(Application::StartupPath, "FilePost");
			String^ dest = System::IO::Path::Combine(filePostDir, DopName + "_" + fileName);
			String^ destServer = System::IO::Path::Combine(serverDir, DopName + "_" + fileName);
			HistoryFileEditPost = selectedFileForEditPost;
			try {
				String^ DeleteFile = System::IO::Path::Combine(filePostDir, DopName + "_" + HistoryFileEditPost);
				String^ DeleteFileServer = System::IO::Path::Combine(destServer, DopName + "_" + HistoryFileEditPost);
				if (System::IO::File::Exists(DeleteFile) && System::IO::File::Exists(DeleteFileServer)) {
					System::IO::File::Delete(DeleteFile);
					System::IO::File::Delete(DeleteFileServer);
				}
			}
			catch (Exception^ ex) {}
			System::IO::File::Copy(src, dest, true);
			selectedFileForEditPost = fileName;
			linkEditFile->Text = fileName;
			linkEditFile->Visible = true;
			BtnAddFiles->Text = L"Изменить файл";
			
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
//
//	Настройка бота для публикаций
//
System::Void Project::MyForm::Btnsettings_Click(System::Object^ sender, System::EventArgs^ e) {
	if (SettingsGroup->Visible == false) {
		SettingsGroup->Visible = true;
		LoadGroupID();
	}
	else {
		SettingsGroup->Visible = false;
	}
}
System::Void Project::MyForm::BtnSaveSettings_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!currentUserId.HasValue) {
		MessageBox::Show("Вы не авторизованы.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	try {
		String^ newGroupID = ID_Group_text->Text->Trim();
		String^ updateQuery = "UPDATE Login SET [ID_Group] = @ID_Group WHERE [ID] = @ID";
		SqlCommand^ cmd = gcnew SqlCommand(updateQuery, DBconnection);
		cmd->Parameters->AddWithValue("@ID_Group", newGroupID == "" ? DBNull::Value : safe_cast<Object^>(newGroupID));
		cmd->Parameters->AddWithValue("@ID", currentUserId.Value);
		int rowsAffected = cmd->ExecuteNonQuery();
		if (rowsAffected <= 0) {
			MessageBox::Show("Не удалось обновить настройки.", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		SettingsGroup->Visible = false;
	}
	catch (Exception^ ex) {
		MessageBox::Show("Ошибка сохранения настроек:\n" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
System::Void Project::MyForm::Add_bot_settings_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Diagnostics::Process::Start("https://t.me/");
}
//
//	Авторизация и регистрация(Перенести в отдельный файл при выпуске)
//
System::Void Project::MyForm::BTNAuthorization_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ login = Authorization_Login->Text->Trim();
	String^ password = Authorization_Password->Text->Trim();

	if (String::IsNullOrWhiteSpace(login) || String::IsNullOrWhiteSpace(password) || (login=="Логин" && password=="Пароль")) {
		MessageBox::Show("Введите логин и пароль.", "Ошибка авторизации", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	try {
		String^ query = "SELECT [ID] FROM Login WHERE [Name_Users] = @Login AND [Password_Users] = @Password";
		SqlCommand^ cmd = gcnew SqlCommand(query, DBconnection);
		cmd->Parameters->AddWithValue("@Login", login);
		cmd->Parameters->AddWithValue("@Password", password);
		Object^ result = cmd->ExecuteScalar();
		if (result != nullptr && result != DBNull::Value) {
			currentUserId = safe_cast<int>(result);
			Authorization->Visible = false;
			pictureBox2->Visible = false;
			MyForm_Load(this, gcnew System::EventArgs());
		}
		else {
			MessageBox::Show("Неверный логин или пароль.", "Ошибка авторизации", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Ошибка при подключении к базе данных:\n" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
System::Void Project::MyForm::Btn_new_user_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	Registr_group->Visible = true;
}

System::Void Project::MyForm::SignUp_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	Registr_group->Visible = false;
	registr_Login->Clear();
	registr_password->Clear();
	registr_password_repeat->Clear();
}
System::Void Project::MyForm::Btn_registr_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ login = registr_Login->Text->Trim();
	String^ password = registr_password->Text->Trim();
	String^ passwordRepeat = registr_password_repeat->Text->Trim();

	if (String::IsNullOrWhiteSpace(login) || String::IsNullOrWhiteSpace(password) || (login == "Логин" && password == "Пароль")) {
		MessageBox::Show("Логин и пароль не могут быть пустыми.", "Ошибка регистрации", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (password != passwordRepeat) {
		MessageBox::Show("Пароли не совпадают.", "Ошибка регистрации", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	try {
		String^ checkQuery = "SELECT COUNT(*) FROM Login WHERE [Name_Users] = @Login";
		SqlCommand^ checkCmd = gcnew SqlCommand(checkQuery, DBconnection);
		checkCmd->Parameters->AddWithValue("@Login", login);
		Object^ countResult = checkCmd->ExecuteScalar();
		int existingCount = safe_cast<int>(countResult);

		if (existingCount > 0) {
			MessageBox::Show("Пользователь с таким логином уже существует.", "Ошибка регистрации", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		String^ insertQuery = "INSERT INTO Login ([Name_Users], [Password_Users]) VALUES (@Name_Users, @Password_Users)";
		SqlCommand^ insertCmd = gcnew SqlCommand(insertQuery, DBconnection);
		insertCmd->Parameters->AddWithValue("@Name_Users", login);
		insertCmd->Parameters->AddWithValue("@Password_Users", password);

		int rowsAffected = insertCmd->ExecuteNonQuery();
		if (rowsAffected > 0) {
			MessageBox::Show("Регистрация прошла успешно! Теперь вы можете войти.", "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
			registr_Login->Clear();
			registr_password->Clear();
			registr_password_repeat->Clear();
			Registr_group->Visible = false;
		}
		else {
			MessageBox::Show("Не удалось создать пользователя.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Ошибка при регистрации:\n" + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}

System::Void Project::MyForm::OnRefreshTimerTick(System::Object ^ sender, System::EventArgs ^ e) {
	try {
		bool exists = System::IO::Directory::Exists(serverDir);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Ошибка доступа: " + ex->Message);
	}
	SyncDirectories(localDir, serverDir);
	MyForm_Load(sender, e);
}
