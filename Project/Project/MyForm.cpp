#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Globalization;
using namespace System::Threading;
using namespace System::Data::SqlClient;

[STAThreadAttribute]
int main(array<String^>^args) {
	Thread::CurrentThread->CurrentUICulture = gcnew CultureInfo("ru-RU");
	Thread::CurrentThread->CurrentCulture = gcnew CultureInfo("ru-RU");
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Project::MyForm form;
	Application::Run(% form);
}