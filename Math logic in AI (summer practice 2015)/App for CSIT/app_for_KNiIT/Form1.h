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
	/// —водка дл€ Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	public: static short var; // номер варианта
	public:	static short kol_zad; // количество заданий
	public: static bool now_edit = false; // новое задание или редактирование задани€

	public: static wchar_t *fileEditor = new wchar_t[100]; // им€ файла с задани€ми
	public: static wchar_t *fileStudents = new wchar_t[100]; // им€ файла со списком студентов 
	public: static wchar_t *fileCheck = new wchar_t[100]; // им€ файла с решением студента
	public: static char *forGroup = new char[5]; // номер группы (дл€ создани€ файла группы)

	public: static bool editor_open; // открыт/закрыт файл с задани€ми
	public: static bool students_open; // открыт/закрыт файл со списком студентов
	public: static bool check_open; // открыт/закрыт файл с решением студента

	private: System::Windows::Forms::MenuStrip^  menuStrip1; // меню
	private: System::Windows::Forms::ToolStripMenuItem^  открытьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  открыть‘айл—«адани€миToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  открыть‘айл—о—писком—тудентовToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  открыть‘айл—–ешением—тудентаToolStripMenuItem;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1; // файл с задани€ми
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2; // файл со списком студентов
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog3; // файл с решением студента

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1; // кнопка "—оздать задание"
	private: System::Windows::Forms::Button^  button2; // кнопка "–едактировать задание"
	private: System::Windows::Forms::Button^  button3; // кнопка "Ќазначить задани€"
	private: System::Windows::Forms::Button^  button4; // кнопка "ѕроверить"

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			
			this->button1 = (gcnew System::Windows::Forms::Button()); // кнопка "—оздать задание"
			this->button2 = (gcnew System::Windows::Forms::Button()); // кнопка "–едактировать задание"
			this->button3 = (gcnew System::Windows::Forms::Button()); // кнопка "Ќазначить задани€"
			this->button4 = (gcnew System::Windows::Forms::Button()); // кнопка "ѕроверить"

			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip()); // меню
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открыть‘айл—«адани€миToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открыть‘айл—о—писком—тудентовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открыть‘айл—–ешением—тудентаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());

			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog()); // файл с задани€ми
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog()); // файл со списком студентов
			this->openFileDialog3 = (gcnew System::Windows::Forms::OpenFileDialog()); // файл с решением студента

			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// кнопка "—оздать задание"
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(75, 152);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(280, 59);
			this->button1->TabIndex = 0;
			this->button1->Text = L"—оздать задание";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// кнопка "–едактировать задание"
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(74, 227);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(279, 59);
			this->button2->TabIndex = 1;
			this->button2->Text = L"–едактировать задание";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// кнопка "Ќазначить задани€"
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(75, 307);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(280, 59);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Ќазначить задани€";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// кнопка "ѕроверить"
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(75, 386);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(280, 59);
			this->button4->TabIndex = 3;
			this->button4->Text = L"ѕроверить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->открытьToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(439, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// открытьToolStripMenuItem
			// 
			this->открытьToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->открыть‘айл—«адани€миToolStripMenuItem, 
			this->открыть‘айл—о—писком—тудентовToolStripMenuItem, this->открыть‘айл—–ешением—тудентаToolStripMenuItem});
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->открытьToolStripMenuItem->Text = L"ќткрыть";
			// 
			// открыть‘айл—«адани€миToolStripMenuItem
			// 
			this->открыть‘айл—«адани€миToolStripMenuItem->Name = L"открыть‘айл—«адани€миToolStripMenuItem";
			this->открыть‘айл—«адани€миToolStripMenuItem->Size = System::Drawing::Size(277, 22);
			this->открыть‘айл—«адани€миToolStripMenuItem->Text = L"ќткрыть файл с задани€ми";
			this->открыть‘айл—«адани€миToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::открыть‘айл—«адани€миToolStripMenuItem_Click);
			// 
			// открыть‘айл—о—писком—тудентовToolStripMenuItem
			// 
			this->открыть‘айл—о—писком—тудентовToolStripMenuItem->Name = L"открыть‘айл—о—писком—тудентовToolStripMenuItem";
			this->открыть‘айл—о—писком—тудентовToolStripMenuItem->Size = System::Drawing::Size(277, 22);
			this->открыть‘айл—о—писком—тудентовToolStripMenuItem->Text = L"ќткрыть файл со списком студентов";
			this->открыть‘айл—о—писком—тудентовToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::открыть‘айл—о—писком—тудентовToolStripMenuItem_Click);
			// 
			// открыть‘айл—–ешением—тудентаToolStripMenuItem
			// 
			this->открыть‘айл—–ешением—тудентаToolStripMenuItem->Name = L"открыть‘айл—–ешением—тудентаToolStripMenuItem";
			this->открыть‘айл—–ешением—тудентаToolStripMenuItem->Size = System::Drawing::Size(277, 22);
			this->открыть‘айл—–ешением—тудентаToolStripMenuItem->Text = L"ќткрыть файл с решением студента";
			this->открыть‘айл—–ешением—тудентаToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::открыть‘айл—–ешением—тудентаToolStripMenuItem_Click);
			// 
			// openFileDialog1 файл с задани€ми
			// 
			this->openFileDialog1->DefaultExt = L"txt";
			this->openFileDialog1->Filter = L"“екстовые файлы (*.txt)|*.txt";
			this->openFileDialog1->Title = L"ќткрыть файл с задани€ми";
			// 
			// openFileDialog2 файл со списком студентов
			// 
			this->openFileDialog2->DefaultExt = L"txt";
			this->openFileDialog2->Filter = L"“екстовые файлы (*.txt)|*.txt";
			this->openFileDialog2->Title = L"ќткрыть файл со списком студентов";
			// 
			// openFileDialog3 файл с решением студента
			// 
			this->openFileDialog3->DefaultExt = L"txt";
			this->openFileDialog3->Filter = L"“екстовые файлы (*.txt)|*.txt";
			this->openFileDialog3->Title = L"ќткрыть файл с решением студента";
			// 
			// настройки начального окна Form1
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
			this->Text = L"ѕриложение преподавател€";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	// загрузка главного окна
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Location = Point(400, 100); // положение главного окна
		editor_open = false; // закрыт файл с задани€ми
		students_open = false; //закрыт файл со списком студентов
		check_open = false; //закрыт файл с решением студента
	}

	// кнопка "—оздать задание"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e); 

	// кнопка "–едактировать задание"
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);

	// кнопка "Ќазначить задани€"
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);

	// кнопка "ѕроверить"
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void открыть‘айл—«адани€миToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if ( this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{ 
		}
		for (int i = 0; i < openFileDialog1->FileName->Length; i++)
		{
			fileEditor[i] = openFileDialog1->FileName[i]; // сохранение имени файла с задани€ми
		}
		fileEditor[openFileDialog1->FileName->Length] = '\0'; 
		editor_open = true; // открыт файл с задани€ми
	}

	private: System::Void открыть‘айл—о—писком—тудентовToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if ( this->openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{ 
		}
		for (int i = 0; i < openFileDialog2->FileName->Length; i++)
		{
			fileStudents[i] = openFileDialog2->FileName[i]; // сохранение имени файла со списком студентов
		}
		fileStudents[openFileDialog2->FileName->Length] = '\0';
		students_open = true; // открыт файл со списком студентов

		// сохранение номера группы (дл€ файла группы)
		ifstream in(fileStudents);
		string file;
		getline(in, file);
		forGroup[0] = file[0];
		forGroup[1] = file[1];
		forGroup[2] = file[2];
		in.close();
	}

	private: System::Void открыть‘айл—–ешением—тудентаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if ( this->openFileDialog3->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{ 
		}
		for (int i = 0; i < openFileDialog3->FileName->Length; i++)
		{
			fileCheck[i] = openFileDialog3->FileName[i]; // сохранение имени файла с решением студента
		}
		fileCheck[openFileDialog3->FileName->Length] = '\0';
		check_open = true; // открыт файл с решением студента
		
		decode(); // декодирование файла с решением студента 
	}

	// закрыть главное окно
	public: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);

	// подсчЄт количества заданий
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

	// декодирование файла с решением студента
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

