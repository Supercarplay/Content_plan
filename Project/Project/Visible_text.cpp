#pragma endregion
#include "MyForm.h"
using namespace Project;
using namespace System;

System::Void Project::MyForm::Authorization_Login_Enter(System::Object^ sender, System::EventArgs^ e) {
	String^ login = Authorization_Login->Text->Trim();

	if (login == "Логин") {
		Authorization_Login->Text = "";
		Authorization_Login->ForeColor = System::Drawing::Color::Black;
	}
}
System::Void Project::MyForm::Authorization_Login_Leave(System::Object^ sender, System::EventArgs^ e) {
	String^ login = Authorization_Login->Text->Trim();

	if (String::IsNullOrWhiteSpace(login)) {
		Authorization_Login->Text = "Логин";
		Authorization_Login->ForeColor = System::Drawing::Color::Gray;
	}
}
System::Void Project::MyForm::Authorization_Password_Enter(System::Object^ sender, System::EventArgs^ e) {
	String^ Password = Authorization_Password->Text->Trim();
	Authorization_Password->UseSystemPasswordChar = true;
	if (Password == "Пароль") {
		Authorization_Password->Text = "";
		Authorization_Password->ForeColor = System::Drawing::Color::Black;
	}
}
System::Void Project::MyForm::Authorization_Password_Leave(System::Object^ sender, System::EventArgs^ e) {
	String^ Password = Authorization_Password->Text->Trim();
	if (String::IsNullOrWhiteSpace(Password)) {
		Authorization_Password->UseSystemPasswordChar = false;
		Authorization_Password->Text = "Пароль";
		Authorization_Password->ForeColor = System::Drawing::Color::Gray;
	}
}
System::Void Project::MyForm::btn_Show_Password_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Authorization_Password->UseSystemPasswordChar = false;
}
System::Void Project::MyForm::btn_Show_Password_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	Authorization_Password->UseSystemPasswordChar = false;
}
System::Void Project::MyForm::btn_Show_Password_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	String^ password = Authorization_Password->Text->Trim();
	if (String::IsNullOrWhiteSpace(password) || password == "Пароль") {
		Authorization_Password->UseSystemPasswordChar = false;
	}
	else {
		Authorization_Password->UseSystemPasswordChar = true;
	}
}

//Окно регистрация

System::Void Project::MyForm::registr_Login_Enter(System::Object^ sender, System::EventArgs^ e) {
	String^ login = registr_Login->Text->Trim();

	if (login=="Логин") {
		registr_Login->Text = "";
		registr_Login->ForeColor = System::Drawing::Color::Black;
	}
	
}
System::Void Project::MyForm::registr_Login_Leave(System::Object^ sender, System::EventArgs^ e) {
	String^ login = registr_Login->Text->Trim();

	if (String::IsNullOrWhiteSpace(login)) {
		registr_Login->Text = "Логин";
		registr_Login->ForeColor = System::Drawing::Color::Gray;
	}
}

System::Void Project::MyForm::registr_password_Enter(System::Object^ sender, System::EventArgs^ e){
	String^ password = registr_password->Text->Trim();
	if (password == "Пароль") {
		registr_password->Text = "";
		registr_password->ForeColor = System::Drawing::Color::Black;
	}
}
System::Void Project::MyForm::registr_password_Leave(System::Object^ sender, System::EventArgs^ e){
	String^ password = registr_password->Text->Trim();
	if (String::IsNullOrWhiteSpace(password)) {
		registr_password->Text = "Пароль";
		registr_password->ForeColor = System::Drawing::Color::Gray;
	}
}
System::Void Project::MyForm::registr_password_repeat_Enter(System::Object^ sender, System::EventArgs^ e){
	String^ password = registr_password_repeat->Text->Trim();
	registr_password_repeat->UseSystemPasswordChar = true;
	if (password == "Повторите пароль") {
		registr_password_repeat->Text = "";
		registr_password_repeat->ForeColor = System::Drawing::Color::Black;
	}
}
System::Void Project::MyForm::registr_password_repeat_Leave(System::Object^ sender, System::EventArgs^ e){
	String^ password = registr_password_repeat->Text->Trim();
	if (String::IsNullOrWhiteSpace(password)) {
		registr_password_repeat->ForeColor = System::Drawing::Color::Gray;
		registr_password_repeat->UseSystemPasswordChar = false;
		registr_password_repeat->Text = "Повторите пароль";
	}
}
System::Void Project::MyForm::btn_Show_repeat_Password_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	registr_password_repeat->UseSystemPasswordChar = false;
}
System::Void Project::MyForm::btn_Show_repeat_Password_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	registr_password_repeat->UseSystemPasswordChar = false;
}
System::Void Project::MyForm::btn_Show_repeat_Password_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	String^ password = registr_password_repeat->Text->Trim();
	if (String::IsNullOrWhiteSpace(password) || password == "Повторите пароль") {
		registr_password_repeat->UseSystemPasswordChar = false;
	}
	else {
		registr_password_repeat->UseSystemPasswordChar = true;
	}
}