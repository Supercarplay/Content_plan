#pragma endregion
#include "MyForm.h"
using namespace Project;
using namespace System;


System::Void Project::MyForm::SyncDirectories(String^ localDir, String^ serverDir) {
    
    try {
        // Убедимся, что папки существуют
        if (!System::IO::Directory::Exists(localDir)) {
            System::IO::Directory::CreateDirectory(localDir);
        }

        // Получаем списки файлов
        array<String^>^ localFiles = System::IO::Directory::GetFiles(localDir);
        array<String^>^ serverFiles = System::IO::Directory::GetFiles(serverDir);

        // Приведём к Dictionary для быстрого поиска по имени
        System::Collections::Generic::Dictionary<String^, System::IO::FileInfo^>^ localMap =
            gcnew System::Collections::Generic::Dictionary<String^, System::IO::FileInfo^>();
        System::Collections::Generic::Dictionary<String^, System::IO::FileInfo^>^ serverMap =
            gcnew System::Collections::Generic::Dictionary<String^, System::IO::FileInfo^>();

        for each (String ^ path in localFiles) {
            System::IO::FileInfo^ fi = gcnew System::IO::FileInfo(path);
            localMap->Add(fi->Name, fi);
        }
        for each (String ^ path in serverFiles) {
            System::IO::FileInfo^ fi = gcnew System::IO::FileInfo(path);
            serverMap->Add(fi->Name, fi);
        }

        // Сравниваем все файлы по имени
        System::Collections::Generic::List<String^>^ allNames =
            gcnew System::Collections::Generic::List<String^>();

        for each (String ^ name in localMap->Keys) {
            if (!allNames->Contains(name)) allNames->Add(name);
        }
        for each (String ^ name in serverMap->Keys) {
            if (!allNames->Contains(name)) allNames->Add(name);
        }

        for each (String ^ name in allNames) {
            bool inLocal = localMap->ContainsKey(name);
            bool inServer = serverMap->ContainsKey(name);

            if (inLocal && inServer) {
                // Оба файла существуют — сравниваем даты
                System::DateTime localTime = localMap[name]->LastWriteTime;
                System::DateTime serverTime = serverMap[name]->LastWriteTime;

                if (localTime < serverTime) {
                    // Сервер новее → копируем на локальный
                    System::IO::File::Copy(serverMap[name]->FullName, localMap[name]->FullName, true);
                }
            }
            else if (!inLocal && inServer) {
                // Только на сервере → копируем локально
                String^ dest = System::IO::Path::Combine(localDir, name);
                System::IO::File::Copy(serverMap[name]->FullName, dest, true);
            }
            else if (inLocal && !inServer) {
                // Только локально → удаляем, так как его нет на сервере
                System::IO::File::Delete(localMap[name]->FullName);
            }
        }
    }
    catch (Exception^ ex) {
        System::Windows::Forms::MessageBox::Show("Ошибка: " + ex->Message, "Ошибка синхронизации");
    }
}