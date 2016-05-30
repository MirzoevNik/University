#pragma once

#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

namespace app_for_KNiIT {

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

	public: static short var; // ����� ��������
	public:	static short kol_zad; // ���������� �������
	public: static bool now_edit = false; // ����� ������� ��� �������������� �������

	public: static wchar_t *fileEditor = new wchar_t[100]; // ��� ����� � ���������
	public: static wchar_t *fileStudents = new wchar_t[100]; // ��� ����� �� ������� ��������� 
	public: static wchar_t *fileCheck = new wchar_t[100]; // ��� ����� � �������� ��������
	public: static char *forGroup = new char[5]; // ����� ������ (��� �������� ����� ������)

	public: static bool editor_open; // ������/������ ���� � ���������
	public: static bool students_open; // ������/������ ���� �� ������� ���������
	public: static bool check_open; // ������/������ ���� � �������� ��������

	private: System::Windows::Forms::MenuStrip^  menuStrip1; // ����
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������������������������ToolStripMenuItem;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1; // ���� � ���������
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2; // ���� �� ������� ���������
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog3; // ���� � �������� ��������

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

	private: System::Windows::Forms::Button^  button1; // ������ "������� �������"
	private: System::Windows::Forms::Button^  button2; // ������ "������������� �������"
	private: System::Windows::Forms::Button^  button3; // ������ "��������� �������"
	private: System::Windows::Forms::Button^  button4; // ������ "���������"

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
			
			this->button1 = (gcnew System::Windows::Forms::Button()); // ������ "������� �������"
			this->button2 = (gcnew System::Windows::Forms::Button()); // ������ "������������� �������"
			this->button3 = (gcnew System::Windows::Forms::Button()); // ������ "��������� �������"
			this->button4 = (gcnew System::Windows::Forms::Button()); // ������ "���������"

			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip()); // ����
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());

			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog()); // ���� � ���������
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog()); // ���� �� ������� ���������
			this->openFileDialog3 = (gcnew System::Windows::Forms::OpenFileDialog()); // ���� � �������� ��������

			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ������ "������� �������"
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(75, 152);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(280, 59);
			this->button1->TabIndex = 0;
			this->button1->Text = L"������� �������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// ������ "������������� �������"
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(74, 227);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(279, 59);
			this->button2->TabIndex = 1;
			this->button2->Text = L"������������� �������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// ������ "��������� �������"
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(75, 307);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(280, 59);
			this->button3->TabIndex = 2;
			this->button3->Text = L"��������� �������";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// ������ "���������"
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(75, 386);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(280, 59);
			this->button4->TabIndex = 3;
			this->button4->Text = L"���������";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->�������ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(439, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->���������������������ToolStripMenuItem, 
			this->�����������������������������ToolStripMenuItem, this->����������������������������ToolStripMenuItem});
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// ���������������������ToolStripMenuItem
			// 
			this->���������������������ToolStripMenuItem->Name = L"���������������������ToolStripMenuItem";
			this->���������������������ToolStripMenuItem->Size = System::Drawing::Size(277, 22);
			this->���������������������ToolStripMenuItem->Text = L"������� ���� � ���������";
			this->���������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���������������������ToolStripMenuItem_Click);
			// 
			// �����������������������������ToolStripMenuItem
			// 
			this->�����������������������������ToolStripMenuItem->Name = L"�����������������������������ToolStripMenuItem";
			this->�����������������������������ToolStripMenuItem->Size = System::Drawing::Size(277, 22);
			this->�����������������������������ToolStripMenuItem->Text = L"������� ���� �� ������� ���������";
			this->�����������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����������������������������ToolStripMenuItem_Click);
			// 
			// ����������������������������ToolStripMenuItem
			// 
			this->����������������������������ToolStripMenuItem->Name = L"����������������������������ToolStripMenuItem";
			this->����������������������������ToolStripMenuItem->Size = System::Drawing::Size(277, 22);
			this->����������������������������ToolStripMenuItem->Text = L"������� ���� � �������� ��������";
			this->����������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����������������������������ToolStripMenuItem_Click);
			// 
			// openFileDialog1 ���� � ���������
			// 
			this->openFileDialog1->DefaultExt = L"txt";
			this->openFileDialog1->Filter = L"��������� ����� (*.txt)|*.txt";
			this->openFileDialog1->Title = L"������� ���� � ���������";
			// 
			// openFileDialog2 ���� �� ������� ���������
			// 
			this->openFileDialog2->DefaultExt = L"txt";
			this->openFileDialog2->Filter = L"��������� ����� (*.txt)|*.txt";
			this->openFileDialog2->Title = L"������� ���� �� ������� ���������";
			// 
			// openFileDialog3 ���� � �������� ��������
			// 
			this->openFileDialog3->DefaultExt = L"txt";
			this->openFileDialog3->Filter = L"��������� ����� (*.txt)|*.txt";
			this->openFileDialog3->Title = L"������� ���� � �������� ��������";
			// 
			// ��������� ���������� ���� Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(439, 552);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"���������� �������������";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
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
		this->Location = Point(400, 100); // ��������� �������� ����
		editor_open = false; // ������ ���� � ���������
		students_open = false; //������ ���� �� ������� ���������
		check_open = false; //������ ���� � �������� ��������
	}

	// ������ "������� �������"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e); 

	// ������ "������������� �������"
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);

	// ������ "��������� �������"
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);

	// ������ "���������"
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void ���������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if ( this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{ 
		}
		for (int i = 0; i < openFileDialog1->FileName->Length; i++)
		{
			fileEditor[i] = openFileDialog1->FileName[i]; // ���������� ����� ����� � ���������
		}
		fileEditor[openFileDialog1->FileName->Length] = '\0'; 
		editor_open = true; // ������ ���� � ���������
	}

	private: System::Void �����������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if ( this->openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{ 
		}
		for (int i = 0; i < openFileDialog2->FileName->Length; i++)
		{
			fileStudents[i] = openFileDialog2->FileName[i]; // ���������� ����� ����� �� ������� ���������
		}
		fileStudents[openFileDialog2->FileName->Length] = '\0';
		students_open = true; // ������ ���� �� ������� ���������

		// ���������� ������ ������ (��� ����� ������)
		ifstream in(fileStudents);
		string file;
		getline(in, file);
		forGroup[0] = file[0];
		forGroup[1] = file[1];
		forGroup[2] = file[2];
		in.close();
	}

	private: System::Void ����������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if ( this->openFileDialog3->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{ 
		}
		for (int i = 0; i < openFileDialog3->FileName->Length; i++)
		{
			fileCheck[i] = openFileDialog3->FileName[i]; // ���������� ����� ����� � �������� ��������
		}
		fileCheck[openFileDialog3->FileName->Length] = '\0';
		check_open = true; // ������ ���� � �������� ��������
		
		decode(); // ������������� ����� � �������� �������� 
	}

	// ������� ������� ����
	public: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);

	// ������� ���������� �������
	public: static void kolvo_zad()
	{
		kol_zad = 0;
		ifstream in(Form1::fileEditor);
		while (in.peek() != EOF)
		{
			string s;
			getline(in, s);
			kol_zad++;
		}
		in.close();
	}

	// ������������� ����� � �������� ��������
	private: void decode()
	{
		ifstream in(fileCheck);
		ofstream out("decode.txt");
		int i = 0;
		while (in.peek() != EOF)
		{
			string s;
			getline(in, s);
			if (i == 30)
			{
				int x = s.find("@", 150);
				string s1 = s.substr(150, x - 150);
				for (int j = 0; j != s1.size(); j++)
					if (s1[j] == '%')
						s1[j] = ' ';
				out << s1 << endl;
			}
			if (i > 30)
			{
				if (s.find("!") != string::npos)
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
		ofstream out2(fileCheck);
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

