#pragma once

#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

namespace resolutionmethod {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	public: static wchar_t *fileGroup = new wchar_t[100]; // ��� ����� ������
	public: static int var; // ������� ��������

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1; // ������� "���:"
	private: System::Windows::Forms::Label^  label2; // ������� "������:"

	private: System::Windows::Forms::ComboBox^  comboBox1; // ������ ���������
	
	private: System::Windows::Forms::TextBox^  textBox1; // ���� ����� ������
			 
	private: System::Windows::Forms::Button^  button1; // ������ "�����"

	private: System::Windows::Forms::MenuStrip^  menuStrip1; // ����
	private: System::Windows::Forms::ToolStripMenuItem^  �������������������ToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1; // ������� ���� ������
	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label()); // ������� "���:"
			this->label2 = (gcnew System::Windows::Forms::Label()); // ������� "������:"

			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox()); // ������ ���������
			
			this->textBox1 = (gcnew System::Windows::Forms::TextBox()); // ���� ����� ������

			this->button1 = (gcnew System::Windows::Forms::Button()); // ������ "�����"

			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip()); // ����
			this->�������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog()); // ������� ���� ������

			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ������� "���:"
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(84, 72);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"���:";
			// 
			// ������� "������:"
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(84, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"������:";
			// 
			// ������ ���������
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(173, 72);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(257, 29);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->Text = L"�������� �� ������";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// ���� ����� ������
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(173, 119);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(257, 29);
			this->textBox1->TabIndex = 3;
			// 
			// ������ "�����"
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(218, 167);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 45);
			this->button1->TabIndex = 4;
			this->button1->Text = L"�����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// ����
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->�������������������ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(560, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �������������������ToolStripMenuItem
			// 
			this->�������������������ToolStripMenuItem->Name = L"�������������������ToolStripMenuItem";
			this->�������������������ToolStripMenuItem->Size = System::Drawing::Size(142, 20);
			this->�������������������ToolStripMenuItem->Text = L"������� ���� ������";
			this->�������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������������������ToolStripMenuItem_Click);
			// 
			// ������� ���� ������
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(560, 308);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"����� ���������";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// �������� �������� ����
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Location = Point(400, 100);
		this->Show();

		MessageBox::Show(this,"�������� ���� ������.", "��������!");
		�������������������ToolStripMenuItem_Click(sender,e);
		
		textBox1->PasswordChar = '*'; // �������� �������� ������ ����������
	}

	// ������ "�����"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void �������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if ( this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{ // �������� ������������ openFileDialog
		}
		for (int i = 0; i < openFileDialog1->FileName->Length; i++)
			fileGroup[i] = openFileDialog1->FileName[i]; // ���������� ����� ����� � ���������
		fileGroup[openFileDialog1->FileName->Length] = '\0';

		decode(); // ������������� ����� ������
		
		ifstream in(fileGroup);
		while (in.peek() != EOF) // ���������� comboBox ����������
		{
			string s, s1;
			getline(in, s);
			int x, x2;
			x =  s.find('.');
			x += 2;
			x2 = s.find_first_of(':');
			x2--;
			s1 = s.substr(x, x2 - x);
			String ^s2;
			s2 = gcnew String(s1.c_str());
			comboBox1->Items->Add(s2);
		}
		in.close();
	}

	// ����� �������� �� ������
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		var = comboBox1->SelectedIndex;
	}

	// ������������� �����
	private: void decode()
	{
		ifstream in(fileGroup);
		ofstream out("decode.txt");
		int i = 0;
		while (in.peek() != EOF)
		{
			string s;
			getline(in, s);
			if (i >= 30)
			{
				if (s.find(".") != string::npos)
				{
					int x = s.find("@", 150);
					string s1 = s.substr(150, x - 150);
					for (int j = 0; j != s1.size(); j++)
						if (s1[j] == '%')
							s1[j] = ' ';
					out << s1 << endl;
				}
				else
					break;
			}
			i++;
		}
		out.close();
		in.close();

		ifstream in2("decode.txt");
		ofstream out2(fileGroup);
		while (in2.peek() != EOF)
		{
			string s;
			getline(in2, s);
			out2 << s << endl;
		}
		out2.close();
		in2.close();

		remove("decode.txt");
	}

};
}

