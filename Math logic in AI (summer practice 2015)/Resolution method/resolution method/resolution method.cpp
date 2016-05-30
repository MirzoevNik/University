// resolution method.cpp: ������� ���� �������.

#include "stdafx.h"
#include <fstream>
#include <string>
#include "Form1.h"
#include "resolution.h"

using namespace resolutionmethod;

// �������� ������
bool is_init(String ^s)
{
	if (s)
	{
		ifstream file(Form1::fileGroup);
		int v = 0;
		while (file.peek() != EOF)
		{
			string s1;
			getline(file, s1);
			if (v == Form1::var)
			{
				int x = s1.find(':') + 3;
				x = s1.find(':', x) + 3;
				String ^s2;
				string s3 = s1.substr(x, s1.size() - x);
				s2 = gcnew String(s3.c_str());
				if (s2 == s)
					return true;
				else
					return false;
			}
			v++;
		}
		file.close();
	}
	return true;
}

// ������ "�����"
System::Void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (!is_init(textBox1->Text)) // �������� ������������ ������
	{
		if (textBox1->Text->Length == 0)
			MessageBox::Show(this,"������� ������.", "��������!");
		else
			MessageBox::Show(this,"����������� ����� ������.", "��������!");
		return;
	}

	// ������� � ���� "����� ���������"
	resolution ^res = gcnew resolution(this);
	res->Show();
	this->Hide();
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
