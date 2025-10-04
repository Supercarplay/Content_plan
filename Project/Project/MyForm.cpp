#include "MyForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^) {
	setlocale(LC_ALL "Russian");
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Project::MyForm form;
	Application::Run(% form);
} // Проверка
