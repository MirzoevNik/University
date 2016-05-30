#pragma once

#include "Form1.h"
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
	/// Сводка для assign
	/// </summary>
	public ref class assign : public System::Windows::Forms::Form
	{
	public:
		// связывание окна "Распределение заданий"(assign) с главным окном (Form1)
		assign(Form1^ parent)
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
		~assign()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1; // надпись "Список студентов"
	private: System::Windows::Forms::Label^  label2; // надпись "Список заданий"
	private: System::Windows::Forms::Label^  label3; // надпись "Выбрать задание"
	private: System::Windows::Forms::Label^  label4; // надпись "Пароли"

	private: System::Windows::Forms::ListBox^  listBox1; // список студентов
	private: System::Windows::Forms::ListBox^  listBox2; // список заданий
	private: System::Windows::Forms::ListBox^  listBox3; // список паролей

	private: System::Windows::Forms::ComboBox^  comboBox1; // выбор задания

	private: System::Windows::Forms::TextBox^  textBox1; // поле редактирования паролей
	
	private: System::Windows::Forms::Button^  button1; // кнопка "Сохранить"
	private: System::Windows::Forms::Button^  button2; // кнопка "В главное меню"
	private: System::Windows::Forms::Button^  button3; // кнопка "Добавить задание"
	private: System::Windows::Forms::Button^  button4; // кнопка "Добавить пароль"

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(assign::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label()); // надпись "Список студентов"
			this->label2 = (gcnew System::Windows::Forms::Label()); // надпись "Список заданий"
			this->label3 = (gcnew System::Windows::Forms::Label()); // надпись "Выбрать задание"
			this->label4 = (gcnew System::Windows::Forms::Label()); // надпись "Пароли"

			this->listBox1 = (gcnew System::Windows::Forms::ListBox()); // список студентов
			this->listBox2 = (gcnew System::Windows::Forms::ListBox()); // список заданий
			this->listBox3 = (gcnew System::Windows::Forms::ListBox()); // список паролей

			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox()); // выбор задания

			this->textBox1 = (gcnew System::Windows::Forms::TextBox()); // поле редактирования паролей
			
			this->button1 = (gcnew System::Windows::Forms::Button()); // кнопка "Сохранить"
			this->button2 = (gcnew System::Windows::Forms::Button()); // кнопка "В главное меню"
			this->button3 = (gcnew System::Windows::Forms::Button()); // кнопка "Добавить задание"
			this->button4 = (gcnew System::Windows::Forms::Button()); // кнопка "Добавить пароль"

			this->SuspendLayout();
			// 
			// надпись "Список студентов"
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(28, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(183, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Список студентов";
			// 
			// надпись "Список заданий"
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(307, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(165, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Список заданий";
			// 
			// надпись "Выбрать задание"
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(804, 18);
			this->label3->Name = L"label3";
			this->label3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label3->Size = System::Drawing::Size(172, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Выбрать задание";
			// 
			// надпись "Пароли"
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(641, 18);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 25);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Пароли";
			// 
			// список студентов
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 17;
			this->listBox1->Location = System::Drawing::Point(13, 54);
			this->listBox1->Margin = System::Windows::Forms::Padding(4);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(245, 429);
			this->listBox1->TabIndex = 0;
			// 
			// список заданий
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 17;
			this->listBox2->Location = System::Drawing::Point(281, 54);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(322, 429);
			this->listBox2->TabIndex = 2;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &assign::listBox2_SelectedIndexChanged);
			// 
			// список паролей
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 17;
			this->listBox3->Location = System::Drawing::Point(624, 53);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(162, 429);
			this->listBox3->TabIndex = 10;
			this->listBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &assign::listBox3_SelectedIndexChanged);
			// 
			// выбор задания
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(808, 53);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(160, 25);
			this->comboBox1->TabIndex = 1;
			// 
			// поле редактирования паролей
			// 
			this->textBox1->Location = System::Drawing::Point(811, 157);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(157, 24);
			this->textBox1->TabIndex = 11;
			// 
			// кнопка "Сохранить" 
			// 
			this->button1->Location = System::Drawing::Point(803, 347);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(173, 65);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Сохранить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &assign::button1_Click);
			// 
		    // кнопка "В главное меню"
			// 
			this->button2->Location = System::Drawing::Point(803, 417);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(173, 65);
			this->button2->TabIndex = 7;
			this->button2->Text = L"В главное меню";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &assign::button2_Click);
			// 
			// кнопка "Добавить задание"
			// 
			this->button3->Location = System::Drawing::Point(809, 86);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(159, 34);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Добавить задание";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &assign::button3_Click);
			// 
			// кнопка "Добавить пароль"
			// 
			this->button4->Location = System::Drawing::Point(811, 187);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(157, 34);
			this->button4->TabIndex = 12;
			this->button4->Text = L"Добавить пароль";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &assign::button4_Click);
			// 
			// assign
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(980, 519);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);		
			this->Controls->Add(this->label4);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox1);	
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"assign";
			this->Text = L"Распределение заданий";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &assign::assign_FormClosing_1);
			this->Load += gcnew System::EventHandler(this, &assign::assign_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: bool is_changes_ass; // наличие/отсутствие изменений
	private: bool is_main; // переход к главному окну

#pragma endregion

	// загрузка окна "Распределение заданий"
	private: System::Void assign_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Location = Point(220, 100);
		is_changes_ass = false; // отсутствие изменений
		is_main = false; // нет перехода к главному окну

		// создание файла группы
		string fileGroup;
		create_fileGroup(fileGroup); 

		ifstream in(fileGroup);
		while (in.peek() != EOF)
		{
			string s, s1;
			getline(in, s);
			int x, x2;
			x =  s.find('.');
			x += 2;
			x2 = s.find_first_of(':');
			x2--;
			s1 = s.substr(x, x2 - x);
			String ^s2, ^s3, ^s4;
			s2 = gcnew String(s1.c_str());
			listBox1->Items->Add(s2);
			if (x2 + 3 < s.size())
			{
				x2 += 4;
				int x3 = s.find_first_of(':', x2);
				s1 = s.substr(x2, x3 - 1 - x2);
				s3 = gcnew String(s1.c_str());
				listBox2->Items->Add(s3);
				s1 = s.substr(x3 + 3, s.size() - (x3 + 3));
				s4 = gcnew String(s1.c_str());
				listBox3->Items->Add(s4);
			}
			else
			{
				listBox2->Items->Add(" ");
				listBox3->Items->Add(" ");
			}
		}
		in.close();
	
		// заполнение comboBox1 заданиями
		ifstream in2(Form1::fileEditor);
		while (in2.peek() != EOF)
		{
			string s, s1;
			getline(in2, s);
			int x;
			x =  s.find('.');
			x += 2;
			s1 = s.substr(x, s.size() - x);
			String ^s2;
			s2 = gcnew String(s1.c_str());
			comboBox1->Items->Add(s2);
		}
		in2.close();
	}

	// кнопка "Сохранить"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (is_changes_ass)
		{
			save(); // функция сохранения
			is_changes_ass = false; // отсутствие изменений
		}
	}

	// кнопка "В главное меню"
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (is_changes_ass)
		{
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result;
			
			result = MessageBox::Show(this, "Сохранить изменения?", "Внимание!", buttons);

			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				save(); // функция сохранения
			}
		}
		is_changes_ass = false; // отсутствие изменений

		is_main = true; // переход к главному окну
		parentForm->Show();
		this->Close();
	}

	// кнопка "Добавить задание"
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listBox1->SelectedIndex == -1)
			MessageBox::Show(this,"Выберите студента.", "Внимание!");
		else
		{
			if (comboBox1->SelectedIndex == -1)
				MessageBox::Show(this,"Выберите задание.", "Внимание!");
			else
			{
				listBox2->Items[listBox1->SelectedIndex] = comboBox1->Text;
				listBox1->SelectedIndex = -1;
				listBox2->SelectedIndex = -1;
				listBox3->SelectedIndex = -1;
				comboBox1->Text = "";
				is_changes_ass = true; // произошли изменения
			}
		}
	}

	// кнопка "Добавить пароль"
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listBox1->SelectedIndex == -1)
			MessageBox::Show(this,"Выберите студента.", "Внимание!");
		else
		{
			if (textBox1->Text == "")
				MessageBox::Show(this,"Введите пароль.", "Внимание!");
			else
			{
				listBox3->Items[listBox1->SelectedIndex] = textBox1->Text;
				listBox1->SelectedIndex = -1;
				listBox2->SelectedIndex = -1;
				listBox3->SelectedIndex = -1;
				textBox1->Text = "";
				is_changes_ass = true; // произошли изменения
			}
		}
	}

	// отмена выбора элемента списка заданий
	private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listBox2->SelectedIndex >= 0)
			listBox2->SelectedIndex = -1;
	}

	// отмена выбора элемента списка паролей
	private: System::Void listBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listBox3->SelectedIndex >= 0)
			listBox3->SelectedIndex = -1;
	}

	// закрытие окна "Распределение заданий"
	private: System::Void assign_FormClosing_1(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		if (is_changes_ass)
		{
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result;

			result = MessageBox::Show(this, "Сохранить изменения?", "Внимание!", buttons);

			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				save(); // функция сохранения
			}
			is_changes_ass = false; // отсутствие изменений
		}

		encode(); // закодировать файл группы

		if (!is_main)
			parentForm->Close(); // закрыть главное окно
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

	// функция сохранения
	private: void save()
	{
		// создание файла группы
		string fileGroup;
		create_fileGroup(fileGroup);
		
		ofstream out(fileGroup);
		for (int i = 0; i < listBox1->Items->Count; i++)
		{
			string s = convert_to_string(listBox1->Items[i]->ToString());
			out << i+1 << ". " << s << " :: ";

			string s2 = convert_to_string(listBox2->Items[i]->ToString());
			out << s2 << " :: ";

			string s3 = convert_to_string(listBox3->Items[i]->ToString());
			out << s3 << endl;
		}
		out.close();
	}

	// создание файла группы
	public: static void create_fileGroup(string &s)
	{
		s = "students_task_000.txt";
		s[14] = Form1::forGroup[0];
		s[15] = Form1::forGroup[1];
		s[16] = Form1::forGroup[2];
	}

	// закодировать файл группы
	private: void encode()
	{
		// создание файла группы
		string fileGroup;
		create_fileGroup(fileGroup);

		ifstream in(fileGroup);
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
		ofstream out2(fileGroup);
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
