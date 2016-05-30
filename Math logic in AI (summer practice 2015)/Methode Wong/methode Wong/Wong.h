#pragma once

#include <string>
#include <fstream>
#include "Form1.h"
#include <cstdio>

using namespace std;

namespace methodeWong {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Wong
	/// </summary>
	public ref class Wong : public System::Windows::Forms::Form
	{
	public:
		// связывание окна "Метод Вонга"(Wong) с главным окном (Form1)
		Wong(Form1^ parent)
		{
			InitializeComponent();
			parentForm = parent;
			//
			//TODO: добавьте код конструктора
			//
		}
	private: Form1^ parentForm;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Wong()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  textBox1; // поле редактирования клаузы

	private: System::Windows::Forms::CheckedListBox^  checkedListBox1; // список клауз

	private: System::Windows::Forms::Button^  button1; // кнопка "Разбить клаузу"
	private: System::Windows::Forms::Button^  button2; // кнопка "Пометить как клаузу Вонга"
	private: System::Windows::Forms::Button^  button3; // кнопка "Клауза доказана"
	private: System::Windows::Forms::Button^  button4; // кнопка "Изменить клаузу"
	private: System::Windows::Forms::Button^  button5; // кнопка "Клауза недоказуема"

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Wong::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());

			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());

			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());

			this->SuspendLayout();
			// 
			// поле редактирования клаузы
			// 
			this->textBox1->Location = System::Drawing::Point(12, 454);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(624, 24);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Wong::textBox1_KeyPress);
			// 
			// список клауз
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(12, 12);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(624, 422);
			this->checkedListBox1->TabIndex = 3;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Wong::checkedListBox1_SelectedIndexChanged);
			// 
			// кнопка "Разбить клаузу"
			// 
			this->button1->Location = System::Drawing::Point(663, 34);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 48);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Разбить клаузу";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Wong::button1_Click);
			// 
			// "Пометить как клаузу Вонга"
			// 
			this->button2->Location = System::Drawing::Point(663, 97);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(164, 48);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Пометить как клаузу Вонга";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Wong::button2_Click);
			// 
			// кнопка "Клауза доказана"
			// 
			this->button3->Location = System::Drawing::Point(663, 334);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(164, 73);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Клауза доказана";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Wong::button3_Click);
			// 
			// кнопка "Изменить клаузу"
			// 
			this->button4->Location = System::Drawing::Point(218, 484);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(234, 44);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Изменить клаузу";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Wong::button4_Click);
			// 
			// кнопка "Клауза недоказуема"
			// 
			this->button5->Location = System::Drawing::Point(663, 429);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(164, 73);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Клауза недоказуема";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Wong::button5_Click);
			// 
			// Wong
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(839, 533);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Wong";
			this->Text = L"Метод Вонга";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Wong::Wong_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Wong::Wong_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: bool true_check; // текущее состояние проверки
	private: static bool *changes = new bool[50]; // массив с информацией об изменениях строк списка клауз 

#pragma endregion

	// загрузка окна "Метод Вонга"
	private: System::Void Wong_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Location = Point(220, 100);
		true_check = true; // проверка выполнена правильно

		// вывод задания студента
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
				int i = s.find_first_of("::", 0) + 3;
				int f = s.find_first_of("::", i) - 1;
				string s1 = s.substr(i, f - i);
				String ^s2;
				s2 = gcnew String(s1.c_str());
				checkedListBox1->Items->Add(s2);
				changes[0] = false;

				// стартовое протоколирование действий студента
				string fileStudent;
				create_fileStudent(fileStudent); // создание файла студента
				ofstream out(fileStudent);
				out << "Task: " << s1 << endl;
				out << "!Open" << endl;
				out.close();
				break;
			}
		}
		in.close();
	}

	// кнопка "Разбить клаузу"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (checkedListBox1->SelectedIndex == -1)
			MessageBox::Show(this,"Выберите клаузу.", "Внимание!");
		else
		{
			String ^s;
			s = checkedListBox1->SelectedItem->ToString(); // создание файла студента
			if (s->IndexOf('v') == -1 && s->IndexOf('&') == -1)
			{
				MessageBox::Show(this,"Клаузу нельзя разбить.", "Внимание!");
			}
			else
			{
				string s1 = convert_to_string(s);
				
				string fileStudent;
				create_fileStudent(fileStudent); // создание файла студента
				
				// протоколирование действия студента
				ofstream out(fileStudent, ios::app);
				out << s1 << " !=> !Crash" << endl;
				out.close();
				changes[checkedListBox1->SelectedIndex] = true;
				
				int x = s1.find("v");
				if (x == string::npos)
					x = s1.find("&");
				
				int kol = 1; // количество разбиений
				x++;
				while (x + 1 != s1.size() && s1[x] != ',' && s1[x] != ';' && s1[x + 1] != '=')
				{
					if (s[x] == 'v' || s[x] == '&')
						kol++;
					x++;
				}
				kol++;
				
				int kol_points = 0; // количество точек
				int i = 0;
				while (s[i] != ' ')
				{
					if (s[i] == '.')
						kol_points++;
					i++;
				}

				int tek_n = 1;
				String ^s2 = "", ^s3 = "";
				if (kol_points > 0)
				{
					s2 = s->Substring(0, 2 * kol_points);
					s3 = s->Substring(2 * kol_points + 1, s->Length - (2 * kol_points + 1));
				}
				else
				{
					s3 = s;
				}

				while (tek_n <= kol)
				{
					checkedListBox1->Items->Add(s2 + tek_n + ". " + s3);
					changes[checkedListBox1->Items->Count - 1] = false;
					tek_n++;
				}
			}		 
		}

		checkedListBox1->SelectedIndex = -1;
		textBox1->Text = "";
	}

	// кнопка "Пометить как клаузу Вонга"
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (checkedListBox1->SelectedIndex == -1)
			MessageBox::Show(this,"Выберите клаузу.", "Внимание!");
		else
		{
			// пометить строку checkedListBox галочкой
			checkedListBox1->SetItemChecked(checkedListBox1->SelectedIndex, true);

			changes[checkedListBox1->SelectedIndex] = true;

			string s = convert_to_string(checkedListBox1->SelectedItem->ToString());

			string fileStudent;
			create_fileStudent(fileStudent); // создание файла студента
			
			// протоколируем действия студента
			ofstream out(fileStudent, ios::app);
			out << s << " !=> !Wong" << endl;
			out.close();

			checkedListBox1->SelectedIndex = -1;
			textBox1->Text = "";
		}
	}

	// кнопка "Клауза доказана"
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		string fileStudent;
		create_fileStudent(fileStudent); // создание файла студента

		ofstream out(fileStudent, ios::app);
		start_check(); // начало проверки
		if (true_check)
			out << "!Proved+" << endl;
		else
			out << "!Proved-" << endl;
		out.close();

		this->Close();
	}

	// кнопка "Изменить клаузу"
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (checkedListBox1->SelectedIndex == -1)
			MessageBox::Show(this,"Выберите клаузу.", "Внимание!");
		else
		{
			string s = convert_to_string(checkedListBox1->SelectedItem->ToString());
			string s2 = convert_to_string(textBox1->Text->ToString());

			string fileStudent;
			create_fileStudent(fileStudent); // создание файла студента

			ofstream out(fileStudent, ios::app);
			if (!changes[checkedListBox1->SelectedIndex])
			{
				out << s << " !=Crash> " << s2 << endl;
				changes[checkedListBox1->SelectedIndex] = true;
			}
			else
			{
				out << s << " !=> " << s2 << endl;
			}
			out.close();

			checkedListBox1->Items[checkedListBox1->SelectedIndex] = textBox1->Text->ToString();
			checkedListBox1->SelectedIndex = -1;
			textBox1->Text = "";
		}
	}

	// кнопка "Клауза недоказуема"
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		string fileStudent;
		create_fileStudent(fileStudent); // создание файла студента

		ofstream out(fileStudent, ios::app);
		start_check(); // начало проверки
		if (!true_check)
			out << "!Unproven+" << endl;
		else
			out << "!Unproven-" << endl;
		out.close();

		this->Close();
	}

	// ввод символа в поле редактирования клаузы
	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		if ((e->KeyChar >= 'a' && e->KeyChar <= 'z') || (e->KeyChar >= 1072 && e->KeyChar <= 1103))
		{
			e->KeyChar = e->KeyChar - 32;
		}
	}

	// добавить клаузу в textBox
	private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (checkedListBox1->SelectedIndex != -1)
			textBox1->Text = checkedListBox1->SelectedItem->ToString();
	}

	// закрытие окна "Метод Вонга"
	private: System::Void Wong_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		string fileStudent;
		create_fileStudent(fileStudent); // создание файла студента

		ofstream out(fileStudent, ios::app);
		out << "!Close" << endl;
		out.close();
		encode_student(); // закодирование файла студента
		encode_group(); // закодирование файла группы

		parentForm->Close();
	}

	// преобразование из String^ в string
	private: string convert_to_string(System::String ^ str)
	{
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(str)).ToPointer();
		string s = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
		return s;
	}

	// создание файла студента
	private: void create_fileStudent(string &s)
	{
		s = "student_00_wong.txt";
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

	// закодирование файла студента
	private: void encode_student()
	{
		string fileStudent; 
		create_fileStudent(fileStudent); // создание файла студента

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

	// закодирование файла группы
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

	// начало проверки
	private: void start_check()
	{
		int i = 1;
		while (i + 1 < checkedListBox1->Items->Count)
		{
			string s = convert_to_string(checkedListBox1->Items[i]->ToString());
			string s2 = convert_to_string(checkedListBox1->Items[i + 1]->ToString());

			if (s[0] < s2[0])
				check_wong(s.substr(0, 2), i); // проверка метода Вонга
			i++;
		}
		if (checkedListBox1->GetItemChecked(checkedListBox1->Items->Count - 1) && true_check)
			true_check = true;
		else
			true_check = false;
	}

	// проверка метода Вонга
	private: void check_wong(string s, int x)
	{
		if (true_check)
		{
			if (x + 1 >= checkedListBox1->Items->Count)
			{
				if (checkedListBox1->GetItemChecked(x) && true_check)
					true_check = true;
				else
					true_check = false;
			}
			else
			{
				int i = x + 1;
				while (i < checkedListBox1->Items->Count)
				{
					string s2 = convert_to_string(checkedListBox1->Items[i]->ToString());
					string s3 = s2.substr(0, s.size());

					if (s3 == s)
					{
						check_wong(s2.substr(0, s.size() + 2), i);
					}
					if (i + 1 == checkedListBox1->Items->Count)
					{
						if (checkedListBox1->GetItemChecked(x) && true_check)
							true_check = true;
						else
							true_check = false;
					}
					i++;
				}
			}
		}
	}

};
}
