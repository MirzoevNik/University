#pragma once

#include <string>
#include <fstream>
#include "Form1.h"
#include <cstdio>

using namespace std;

namespace resolutionmethod {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� resolution
	/// </summary>
	public ref class resolution : public System::Windows::Forms::Form
	{
	public:
		// ���������� ���� "����� ���������"(resolution) � ������� ����� (Form1)
		resolution(Form1^ parent)
		{
			InitializeComponent();
			parentForm = parent;
			//
			//TODO: �������� ��� ������������
			//
		}
	private: Form1^ parentForm;

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~resolution()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1; // ������� "������ ���������"
	private: System::Windows::Forms::Label^  label2; // ������� "��������"
	private: System::Windows::Forms::Label^  label3; // ������� "���������"

	private: System::Windows::Forms::ListBox^  listBox1; // ������ ���������
	private: System::Windows::Forms::ListBox^  listBox2; // ������ ��������

	private: System::Windows::Forms::TextBox^  textBox1; // ���� ��� �������������� ���������
	
	private: System::Windows::Forms::Button^  button1; // ������ "�������"
	private: System::Windows::Forms::Button^  button2; // ������ "�������� ���������"
	private: System::Windows::Forms::Button^  button3; // ������ "������� ���������"
	private: System::Windows::Forms::Button^  button4; // ������ "������ ��������"
	private: System::Windows::Forms::Button^  button5; // ������ "������ �����������"

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(resolution::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label()); // ������� "������ ���������"
			this->label2 = (gcnew System::Windows::Forms::Label()); // ������� "��������"
			this->label3 = (gcnew System::Windows::Forms::Label()); // ������� "���������"

			this->listBox1 = (gcnew System::Windows::Forms::ListBox()); // ������ ���������
			this->listBox2 = (gcnew System::Windows::Forms::ListBox()); // ������ ��������

			this->textBox1 = (gcnew System::Windows::Forms::TextBox()); // ���� ��� �������������� ���������
			
			this->button1 = (gcnew System::Windows::Forms::Button()); // ������ "�������"
			this->button2 = (gcnew System::Windows::Forms::Button()); // ������ "�������� ���������"
			this->button3 = (gcnew System::Windows::Forms::Button()); // ������ "������� ���������"
			this->button4 = (gcnew System::Windows::Forms::Button()); // ������ "������ ��������"
			this->button5 = (gcnew System::Windows::Forms::Button()); // ������ "������ �����������"

			this->SuspendLayout();
			// 
			// // ������� "������ ���������"
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(31, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(196, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"������ ���������";
			// 
			// ������� "��������"
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(640, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"��������";
			// 
			// ������� "���������"
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(346, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(102, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"���������";
			// 
			// ������ ���������
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 17;
			this->listBox1->Location = System::Drawing::Point(12, 37);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(263, 463);
			this->listBox1->TabIndex = 1;
			// 
			// ������ ��������
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 17;
			this->listBox2->Location = System::Drawing::Point(625, 37);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(202, 89);
			this->listBox2->TabIndex = 4;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &resolution::listBox2_SelectedIndexChanged);
			// 
			// ���� ��� �������������� ���������
			// 
			this->textBox1->Location = System::Drawing::Point(296, 37);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(235, 24);
			this->textBox1->TabIndex = 2;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &resolution::textBox1_KeyPress);
			// 
			// ������ "�������"
			// 
			this->button1->Location = System::Drawing::Point(537, 36);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(79, 24);
			this->button1->TabIndex = 6;
			this->button1->Text = L"�������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &resolution::button1_Click);
			// 
			// ������ "�������� ���������"
			// 
			this->button2->Location = System::Drawing::Point(297, 75);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(151, 51);
			this->button2->TabIndex = 7;
			this->button2->Text = L"�������� ���������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &resolution::button2_Click);
			// 
			// ������ "������� ���������"
			// 
			this->button3->Location = System::Drawing::Point(467, 75);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(149, 51);
			this->button3->TabIndex = 8;
			this->button3->Text = L"������� ���������";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &resolution::button3_Click);
			// 
			// ������ "������ ��������"
			// 
			this->button4->Location = System::Drawing::Point(624, 319);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(202, 76);
			this->button4->TabIndex = 9;
			this->button4->Text = L"������ ��������";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &resolution::button4_Click);
			// 
			// ������ "������ �����������"
			// 
			this->button5->Location = System::Drawing::Point(625, 424);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(201, 76);
			this->button5->TabIndex = 10;
			this->button5->Text = L"������ �����������";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &resolution::button5_Click);
			// 
			// resolution
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(839, 533);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"resolution";
			this->Text = L"����� ���������";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &resolution::resolution_FormClosing);
			this->Load += gcnew System::EventHandler(this, &resolution::resolution_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: short oper, kate;

/*
	oper - ��������� ������
		-1 - ��� �������
		0 - �����
		1 - ����������
		2 - ����������
		3 - ���������
		4 - ����
	kate - ������� ��������
		0 - ��� ��������
		1 - ����������
		2 - ����������
		3 - ����
*/

#pragma endregion

	// �������� ���� "����� ���������"
	private: System::Void resolution_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Location = Point(220, 100);
		oper = -1; kate = 0; // �������� ��� ����������

		// ���������� ������ ��������
		listBox2->Items->Add("1. ����������");
		listBox2->Items->Add("2. ����������");
		listBox2->Items->Add("3. ���������");
		listBox2->Items->Add("4. ����");

		// ����� ������� ��������
		ifstream in(Form1::fileGroup);
		int x = 0;
		while (in.peek() != EOF)
		{
			if (x != Form1::var)
			{
				string s;
				getline(in, s);
				x++;
			}
			else
			{
				string s;
				getline(in, s);
				int i = s.find_first_of("::") + 3, p = i;
				while (s[i] != '>')
				{
					if (s[i] == ',' || s[i+1] == '=')
					{
						string s1 = s.substr(p, i - p);
						String ^s2;
						s2 = gcnew String(s1.c_str());
						listBox1->Items->Add(s2);
						i++;
						p = i + 1;
					}
					i++;
				}
				i = s.find_first_of("::") + 3;
				s = s.substr(i, s.find_first_of("::", i) - 1 - i);

				// ��������� ���������������� �������� ��������
				string fileStudent;
				create_fileStudent(fileStudent); // �������� ����� ��������
				ofstream out(fileStudent);
				out << "Task: " << s << endl;
				out << "!Open" << endl;
				out.close();
				break;
			}
		}
		in.close();

		listBox1->SelectionMode = SelectionMode::MultiSimple;
	}

	// ������ "�������"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		kate = what_kate(); // ����������� ������� ��������
		oper = what_oper(); // ����������� ���������� �������
		switch (oper)
		{
			case -1:
			{ 
				textBox1->Focus();
				textBox1->Select(textBox1->Text->Length, 0);
				break;
			}  
			case 0: case 4:
			{ 
				textBox1->Text = textBox1->Text->Substring(0, textBox1->Text->Length - 1);
					break;
			}
			case 1: 
			{ 
				textBox1->Text = textBox1->Text->Substring(0, textBox1->Text->Length - 3);
				break;
			}
			case 2:  
			{ 
				textBox1->Text = textBox1->Text->Substring(0, textBox1->Text->Length - 3);
				break;
			}
			case 3: 
			{ 
				textBox1->Text = textBox1->Text->Substring(0, textBox1->Text->Length - 2);
				break;
			}
		}
		oper = what_oper(); // ����������� ���������� �������
		if (oper >= 0)
			kate = what_kate(); // ����������� ������� ��������
		textBox1->Focus();
		textBox1->Select(textBox1->Text->Length, 0);
	}

	// ������ "�������� ���������"
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		kate = what_kate(); // ����������� ������� ��������
		oper = what_oper();  // ����������� ���������� �������
		if (listBox1->SelectedIndices->Count != 2)
		{
			MessageBox::Show(this,"�������� ����� ��� ���������.", "��������!");
			textBox1->Focus();
			textBox1->Select(textBox1->Text->Length, 0);
			return;
		}
		if (oper > 0 && oper < 4)
		{
			MessageBox::Show(this,"��������� �� ����� ������������ ������ ���������� ��������.", "��������!");
			textBox1->Focus();
			textBox1->Select(textBox1->Text->Length, 0);
			return;
		}
		String ^ s;
		s = textBox1->Text->ToString();
		if ( (textBox1->Text != "") && (s[0] != ' ') )
		{
			listBox1->Items->Add(textBox1->Text);
			textBox1->Text = ""; 

			string fileStudent;
			create_fileStudent(fileStudent); // �������� ����� ��������

			ofstream out(fileStudent, ios::app);
			string s0 = convert_to_string(listBox1->SelectedItems[0]->ToString());
			string s1 = convert_to_string(listBox1->SelectedItems[1]->ToString());
			string s2 = convert_to_string(s);

			out << s0 << ", " << s1 << " !=> " << s2 << endl;
			out.close();
		}
		oper = -1;
		kate = 0; 
		listBox1->ClearSelected();
	}


	// ����� �������� �� ������
	private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, EventArgs^  e) 
	{
		kate = what_kate(); // ����������� ������� ��������
		oper = what_oper(); // ����������� ���������� �������
		switch (listBox2->SelectedIndex)
		{
			case 0: // ����������
			{
				if (oper == 4)
					break;
				if (kate == 1)
				{
					MessageBox::Show(this, "���������� � ���������� �� ����� ���� ������ � ����� ���������.", "��������!");
					break;
				}
				if (oper == 2 || oper == 3)
				{
					MessageBox::Show(this,"��� �������� �� ����� ���� ������.", "��������!");
					break;
				}
				if (oper < 0)
				{
					MessageBox::Show(this,"��������� �� ����� ���������� �� ����� ����������.", "��������!");
					break;
				}
				oper = 2;
				kate = 2;
				textBox1->Text = textBox1->Text + " & "; 
				break;
			}
			case 1: //����������
			{
				if (oper == 4)
					break;
				if (kate == 2)
				{
					MessageBox::Show(this, "���������� � ���������� �� ����� ���� ������ � ����� ���������.", "��������!");
					break;
				}
				if (oper == 1 || oper == 3)
				{
					MessageBox::Show(this,"��� �������� �� ����� ���� ������.", "��������!");
					break;
				}
				if (oper < 0)
				{
					MessageBox::Show(this,"��������� �� ����� ���������� �� ����� ����������.", "��������!");
					break;
				}
				oper = 1;
				kate = 1;
				textBox1->Text = textBox1->Text + " v "; 
				break;
			}
			case 2: //���������
			{
				if (oper == 4)
					break;
				if (oper == 3)
				{
					MessageBox::Show(this,"��� �������� �� ����� ���� ������.", "��������!");
					break;
				}
				else
				{
					if (oper == 0)
					{
						MessageBox::Show(this,"������������ ��������!", "��������!");
						break;
					}
				}
				textBox1->Text = textBox1->Text + "� "; 
				oper = 3; 
				break;
			}
			case 3: // ����
			{
				if (oper > -1)
				{
					MessageBox::Show(this,"���� ������ ���� ������������ �������� � ���������!", "��������!");
					break;
				}
				textBox1->Text = "0";
				oper = 4;
				break;
			}
		}
		listBox2->SelectedIndex = -1;
		textBox1->Focus();
		textBox1->Select(textBox1->Text->Length, 0);
		return;
	}

	// ������ "������� ���������"
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		string fileStudent;
		create_fileStudent(fileStudent); // �������� ����� ��������

		ofstream out(fileStudent, ios::app);
		while (listBox1->SelectedIndices->Count > 1)
		{				 
			string s = convert_to_string(listBox1->SelectedItems[0]->ToString());
			out << s << ", ";
			listBox1->Items->RemoveAt(listBox1->SelectedIndices[0]);
		}
		string s = convert_to_string(listBox1->SelectedItems[0]->ToString());
		
		out << s << " ";
		listBox1->Items->RemoveAt(listBox1->SelectedIndices[0]);
		out << "!=> !Delete" << endl;
		out.close();

		textBox1->Text = "";
		kate = what_kate(); // ����������� ������� ��������
		oper = what_oper(); // ����������� ���������� �������
		listBox1->SelectedIndex = -1;
	}

	// ���� �������
	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		if (oper == 4)
		{
			e->Handled = true;
			return;
		}
		if ((e->KeyChar >= 'a' && e->KeyChar <= 'z') || (e->KeyChar >= 1072 && e->KeyChar <= 1103))
		{
			e->KeyChar = e->KeyChar - 32;
			oper = 0;
		}
		else
		{
			if ((e->KeyChar >= 'A' && e->KeyChar <= 'Z') || (e->KeyChar >= 1040 && e->KeyChar <= 1071))
				oper = 0;
			else
				e->Handled = true;
		}
		kate = what_kate(); // ����������� ������� ��������
		oper = what_oper(); // ����������� ���������� �������
	}

	// ������ "������ ��������"
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		string fileStudent;
		create_fileStudent(fileStudent); // �������� ����� ��������
		
		ofstream out(fileStudent, ios::app);
		if (listBox1->Items[listBox1->Items->Count - 1]->ToString() == "0")
			out << "!Proved+" << endl;
		else
			out << "!Proved-" << endl;
		out.close();

		this->Close();
	}

	// ������ "������ �����������"
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		string fileStudent;
		create_fileStudent(fileStudent); // �������� ����� ��������

		ofstream out(fileStudent, ios::app);
		if (listBox1->Items[listBox1->Items->Count - 1]->ToString() != "0")
			out << "!Unproven+" << endl;
		else
			out << "!Unproven-" << endl;
		out.close();

		this->Close();
	}

	// �������� ���� "����� ���������"
	private: System::Void resolution_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		string fileStudent;
		create_fileStudent(fileStudent); // �������� ����� ��������

		ofstream out(fileStudent, ios::app);
		out << "!Close" << endl;
		out.close();
		encode_student(); // ������������� ����� ��������
		encode_group(); // ������������� ����� ������
		 
		parentForm->Close();
	}

	// �������������� �� String^ � string
	private: string convert_to_string(System::String ^ str)
	{
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(str)).ToPointer();
		string s = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
		return s;
	}

	// ����������� ��������� �������� oper
	private: short what_oper()
	{
		short x = textBox1->Text->Length;
		if (x == 0)
			return -1;
		else
		{
			if (textBox1->Text[0] == '0')
				return 4;
			switch( textBox1->Text[x - 1] )
			{
				case ' ':
				{
					switch (textBox1->Text[x - 2])
					{
						case 'v':
						{
							return 1;
							break;
						}
						case '&':
						{
							return 2;
							break;
						}
						default:
						{
							return 3;
							break;
						}
					}
					break;
				}
				default:
					return 0;
			}
		}
	}

	// ������������ �������� � ���������
	private: short what_kate()
	{
		if (textBox1->Text->Length == 0)
			return 0;
		if (textBox1->Text[0] == '0')
			return 3;
		for (int i = 0; i < textBox1->Text->Length; i++)
		{
			if (textBox1->Text[i] == 'v')
			{
				return 1;
			}
			else
			{
				if (textBox1->Text[i] == '&')
					return 2;
			}
			if (i == textBox1->Text->Length - 1)
				return 0;
		}
		return 0;
	}	

	// �������� ����� ��������
	private: void create_fileStudent(string &s)
	{
		s = "student_00_res.txt";
		int n = Form1::var;
		char *s2 = new char[14];
		itoa(n, s2, 10);
		if (strlen(s2) == 2)
		{
			s[8] = s2[0];
			s[9] = s2[1];
		}
		else
			s[9] = s2[0];
	}

	// ������������� ����� ��������
	private: void encode_student()
	{
		string fileStudent;
		create_fileStudent(fileStudent); // �������� ����� ��������

		ifstream in(fileStudent);
		ofstream out("code.txt");
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 80; j++)
				out << "@#$%&";
			out << endl;
		}
		while (in.peek() != EOF)
		{
			string s;
			getline(in, s);

			for (int i = 0; i != s.size(); i++)
				if (s[i] == ' ')
					s[i] = '%';

			for (int i = 0; i < 30; i++)
				out << "@#$%&";
			out << s;
			for (int i = 0; i < 30; i++)
				out << "@#$%&";
			out << endl;
		}
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 80; j++)
				out << "@#$%&";
			out << endl;
		}
		out.close();
		in.close();

		ifstream in2("code.txt");
		ofstream out2(fileStudent);
		while (in2.peek() != EOF)
		{
			string s;
			getline(in2, s);
			out2 << s << endl;
		}
		out2.close();
		in2.close();

		remove("code.txt");
	}

	// ������������� ����� ������
	private: void encode_group()
	{
		ifstream in(Form1::fileGroup);
		ofstream out("code.txt");
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 80; j++)
				out << "@#$%&";
			out << endl;
		}
		while (in.peek() != EOF)
		{
			string s;
			getline(in, s);

			for (int i = 0; i != s.size(); i++)
				if (s[i] == ' ')
					s[i] = '%';

			for (int i = 0; i < 30; i++)
				out << "@#$%&";
			out << s;
			for (int i = 0; i < 30; i++)
				out << "@#$%&";
			out << endl;
		}
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 80; j++)
				out << "@#$%&";
			out << endl;
		}
		out.close();
		in.close();

		ifstream in2("code.txt");
		ofstream out2(Form1::fileGroup);
		while (in2.peek() != EOF)
		{
			string s;
			getline(in2, s);
			out2 << s << endl;
		}
		out2.close();
		in2.close();

		remove("code.txt");
	}

};
}
