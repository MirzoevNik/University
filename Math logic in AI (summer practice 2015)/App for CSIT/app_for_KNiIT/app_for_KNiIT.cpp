// app_for_KNiIT.cpp: главный файл проекта.

#include "stdafx.h"
#include "Form1.h"
#include "editor.h"
#include "selection.h"
#include "assign.h"
#include "check.h"
#include <string>
#include <fstream>

using namespace app_for_KNiIT;

// создать файл "студенты_задания"
void file_stud_task()
{
	string fileGroup;
	assign::create_fileGroup(fileGroup);

	ifstream in(fileGroup);
	string s;
	in >> s;
	in.close();
	if (s == "")
	{
		ifstream in_stud(Form1::fileStudents);
		ofstream out(fileGroup);
		int i = 0;
		while (in_stud.peek() != EOF)
		{
			getline(in_stud, s);
			if (i > 0)
				out << i << ". " << s << " :" << endl;
			i++;
		}
		in_stud.close();
		out.close();
	}
}

// кнопка "Создать задание"
System::Void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (!editor_open)
	{
		MessageBox::Show( "Откройте файл для добавления заданий.", "Внимание!");
		return;
	}
	Form1::kolvo_zad(); // подсчёт количества заданий
	var = kol_zad + 1;

	// перейти к окну "Редактор"
	editor ^ed = gcnew editor(this);
	ed->Show();
	this->Hide();
}

// кнопка "Редактировать задание"
System::Void Form1::button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (!editor_open)
	{
		MessageBox::Show( "Откройте файл с заданиями.", "Внимание!");
		return;
	}
	Form1::kolvo_zad(); // подсчёт количества заданий

	// перейти к окну "Редактор заданий"
	selection ^sel = gcnew selection(this);
	sel->Show();
	this->Hide();
}

// кнопка "Назначить задания"
System::Void Form1::button3_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (!editor_open)
	{
		MessageBox::Show( "Откройте файл с заданиями.", "Внимание!");
		return;
	}
	if (!students_open)
	{
		MessageBox::Show( "Откройте файл со списком студентов.", "Внимание!");
		return;
	}
	Form1::kolvo_zad(); // подсчёт количества заданий
	file_stud_task(); // создать файл "студенты_задания"

	// перейти к окну "Распределение заданий"
	assign ^ass = gcnew assign(this);
	ass->Show();
	this->Hide();
}

// кнопка "Проверить"
System::Void Form1::button4_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (!check_open)
	{
		MessageBox::Show( "Откройте файл с решением студента.", "Внимание!");
		return;
	}

	// перейти к окну "Проверка задания"
	check ^che = gcnew check(this);
	che->Show();
	this->Hide();
}

// закрыть главное окно
System::Void Form1::Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	check ^che = gcnew check(this);
	che->Show();
}

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Создание главного окна и его запуск
	Application::Run(gcnew Form1());
	return 0;
}
