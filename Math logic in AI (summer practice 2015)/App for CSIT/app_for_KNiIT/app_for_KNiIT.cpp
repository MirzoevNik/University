// app_for_KNiIT.cpp: ������� ���� �������.

#include "stdafx.h"
#include "Form1.h"
#include "editor.h"
#include "selection.h"
#include "assign.h"
#include "check.h"
#include <string>
#include <fstream>

using namespace app_for_KNiIT;

// ������� ���� "��������_�������"
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

// ������ "������� �������"
System::Void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (!editor_open)
	{
		MessageBox::Show( "�������� ���� ��� ���������� �������.", "��������!");
		return;
	}
	Form1::kolvo_zad(); // ������� ���������� �������
	var = kol_zad + 1;

	// ������� � ���� "��������"
	editor ^ed = gcnew editor(this);
	ed->Show();
	this->Hide();
}

// ������ "������������� �������"
System::Void Form1::button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (!editor_open)
	{
		MessageBox::Show( "�������� ���� � ���������.", "��������!");
		return;
	}
	Form1::kolvo_zad(); // ������� ���������� �������

	// ������� � ���� "�������� �������"
	selection ^sel = gcnew selection(this);
	sel->Show();
	this->Hide();
}

// ������ "��������� �������"
System::Void Form1::button3_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (!editor_open)
	{
		MessageBox::Show( "�������� ���� � ���������.", "��������!");
		return;
	}
	if (!students_open)
	{
		MessageBox::Show( "�������� ���� �� ������� ���������.", "��������!");
		return;
	}
	Form1::kolvo_zad(); // ������� ���������� �������
	file_stud_task(); // ������� ���� "��������_�������"

	// ������� � ���� "������������� �������"
	assign ^ass = gcnew assign(this);
	ass->Show();
	this->Hide();
}

// ������ "���������"
System::Void Form1::button4_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (!check_open)
	{
		MessageBox::Show( "�������� ���� � �������� ��������.", "��������!");
		return;
	}

	// ������� � ���� "�������� �������"
	check ^che = gcnew check(this);
	che->Show();
	this->Hide();
}

// ������� ������� ����
System::Void Form1::Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	check ^che = gcnew check(this);
	che->Show();
}

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew Form1());
	return 0;
}
