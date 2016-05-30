#pragma once

#include <stdlib.h>
#include <string>
#include <fstream>
#include "Form1.h"
#include <vector>

using namespace std;

namespace app_for_KNiIT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для editor
	/// </summary>
	public ref class editor : public System::Windows::Forms::Form
	{

	// связывание окна "Редактор"(editor) с главным окном (Form1)
	public:
		editor(Form1^ parent)
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
		~editor()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1; // надпись "Дизъюнкторы"
	private: System::Windows::Forms::Label^  label2; // надпись "Конъюнкторы"
	private: System::Windows::Forms::Label^  label3; // надпись "Вариант .."
	private: System::Windows::Forms::Label^  label4; // надпись "Операции"

	private: System::Windows::Forms::ListBox^  listBox1; // список дизъюнкторов
	private: System::Windows::Forms::ListBox^  listBox2; // список конъюнкторов
	private: System::Windows::Forms::ListBox^  inform; // список с операциями

	private: System::Windows::Forms::Button^  button1; // кнопка "Добавить дизъюнктор"
	private: System::Windows::Forms::Button^  button2; // кнопка "Добавить конъюнктор"
	private: System::Windows::Forms::Button^  button3; // кнопка "Удалить элемент"
	private: System::Windows::Forms::Button^  button4; // кнопка "Сохранить"
	private: System::Windows::Forms::Button^  button5; // кнопка "В главное меню"
	private: System::Windows::Forms::Button^  button6; // кнопка "Удалить"

	private: System::Windows::Forms::TextBox^  textBox1; // поле редактирования

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(editor::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label()); // надпись "Дизъюнкторы"
			this->label2 = (gcnew System::Windows::Forms::Label()); // надпись "Конъюнкторы"
			this->label3 = (gcnew System::Windows::Forms::Label()); // надпись "Вариант .."
			this->label4 = (gcnew System::Windows::Forms::Label()); // надпись "Операции"

			this->listBox1 = (gcnew System::Windows::Forms::ListBox()); // список дизъюнкторов
			this->listBox2 = (gcnew System::Windows::Forms::ListBox()); // список конъюнкторов
			this->inform = (gcnew System::Windows::Forms::ListBox()); // список с операциями
			
			this->button1 = (gcnew System::Windows::Forms::Button()); // кнопка "Добавить дизъюнктор"
			this->button2 = (gcnew System::Windows::Forms::Button()); // кнопка "Добавить конъюнктор"
			this->button3 = (gcnew System::Windows::Forms::Button()); // кнопка "Удалить элемент"
			this->button4 = (gcnew System::Windows::Forms::Button()); // кнопка "Сохранить"
			this->button5 = (gcnew System::Windows::Forms::Button()); // кнопка "В главное меню"
			this->button6 = (gcnew System::Windows::Forms::Button()); // кнопка "Удалить"

			this->textBox1 = (gcnew System::Windows::Forms::TextBox()); // поле редактирования

			this->SuspendLayout();
			// 
			// надпись "Дизъюнкторы"
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(43, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Дизъюнкторы";
			// 
			// надпись "Конъюнкторы"
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(43, 267);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Конъюнкторы";
			// 
			// надпись "Вариант .."
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(377, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"label3";
			// 
			// надпись "Операции"
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(640, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(107, 25);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Операции";
			// 
			// список дизъюнкторов
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 17;
			this->listBox1->Location = System::Drawing::Point(38, 56);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(242, 174);
			this->listBox1->TabIndex = 1;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &editor::listBox1_SelectedIndexChanged);
			// 
			// список конъюнкторов
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 17;
			this->listBox2->Location = System::Drawing::Point(38, 321);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(242, 191);
			this->listBox2->TabIndex = 3;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &editor::listBox2_SelectedIndexChanged);
			// 
			// список с операциями
			// 
			this->inform->FormattingEnabled = true;
			this->inform->ItemHeight = 17;
			this->inform->Location = System::Drawing::Point(634, 56);
			this->inform->Name = L"inform";
			this->inform->Size = System::Drawing::Size(185, 72);
			this->inform->TabIndex = 10;
			this->inform->SelectedIndexChanged += gcnew System::EventHandler(this, &editor::inform_SelectedIndexChanged);
			// 
			// кнопка "Добавить дизъюнктор"
			// 
			this->button1->Location = System::Drawing::Point(328, 100);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(219, 56);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Добавить дизъюнктор";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &editor::button1_Click);
			// 
			// кнопка "Добавить конъюнктор"
			// 
			this->button2->Location = System::Drawing::Point(328, 178);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(219, 56);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Добавить конъюнктор";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &editor::button2_Click);
			// 
			// кнопка "Удалить элемент"
			// 
			this->button3->Location = System::Drawing::Point(328, 252);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(219, 56);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Удалить элемент";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &editor::button3_Click);
			// 
			// кнопка "Сохранить"
			// 
			this->button4->Location = System::Drawing::Point(634, 366);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(185, 48);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Сохранить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &editor::button4_Click);
			// 
			// кнопка "В главное меню"
			// 
			this->button5->Location = System::Drawing::Point(634, 436);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(185, 82);
			this->button5->TabIndex = 12;
			this->button5->Text = L"В главное меню";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &editor::button5_Click);
			// 
			// кнопка "Удалить"
			// 
			this->button6->Location = System::Drawing::Point(553, 56);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 24);
			this->button6->TabIndex = 14;
			this->button6->Text = L"Удалить";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &editor::button6_Click);
			//
			// поле редактирования
			// 
			this->textBox1->Location = System::Drawing::Point(328, 56);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(219, 24);
			this->textBox1->TabIndex = 13;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &editor::textBox1_KeyPress);
			// 
			// editor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(853, 533);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->inform);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"editor";
			this->Text = L"Редактор";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &editor::editor_FormClosing_1);
			this->Load += gcnew System::EventHandler(this, &editor::editor_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: int n1, n2; //n1 - кол-во диз; n2 - кол-во кон
	private: bool is_changes_ed; // наличие/отсутствие изменений
	private: bool is_main; // переход к главному окну
	private: short d, oper, kate;

/*
	oper - последний символ
		-1 - нет символа
		0 - буква
		1 - дизъюнкция
		2 - конъюнкция
		3 - отрицание
	kate - текущая операция
		0 - нет операции
		1 - дизъюнкция
		2 - конъюнкция
	d - переменная, в которой хранится выбранный list (диз или кон)
		1 - диз
		2 - кон
*/

#pragma endregion

	// загрузка окна "Редактор"
    private: System::Void editor_Load(System::Object^  sender, System::EventArgs^  e)
	{
		n1 = 0; n2 = 0; oper = -1; d = 0; kate = 0; // обнуляем все переменные
		this->Location = Point(220, 100);
		is_changes_ed = false; // отсутствие изменений
		is_main = false; // нет перехода к главному окну

		// заполнение списка операций
		inform->Items->Add("1. Конъюнкция");
		inform->Items->Add("2. Дизъюнкция");
		inform->Items->Add("3. Отрицание");

		label3->Text = "Вариант " + Form1::var; // редактирование надписи с номером варианта

		// заполнение списков дизъюнкторами и конъюнкторами, если задание редактируется
		if (Form1::now_edit)
		{
			ifstream in(Form1::fileEditor);
			int x = 1;
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
					int i = s.find(".") + 2, p = i;
					while (s[i] != '>')
					{
						if (s[i] == ',' || s[i+1] == '=')
						{
							string s1 = s.substr(p, i - p);
							String ^s2;
							s2 = gcnew String(s1.c_str());
							listBox1->Items->Add(s2);
							n1++;
							i++;
							p = i + 1;
						}
						i++;
					}
					i = s.find(">") + 2; p = i;
					if (s[i] != '0')
					{
						while (i != s.length() )
						{
							if (s[i] == ';' || i+1 == s.length())
							{
								if (i + 1 == s.length())
									i++;
								string s4 = s.substr(p, i - p);
								String ^s3;
								s3 = gcnew String(s4.c_str());
								listBox2->Items->Add(s3);
								n2++;
								if (i == s.length())
									break;
								i++;
								p = i + 1;
							}
							i++;
						}
					}
					break;
				}
			}
			in.close();
			Form1::now_edit = false;
		}
	}

	// выбор операций
	private: System::Void inform_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		kate = what_kate(); // определение текущей операции
		oper = what_oper(); // определение последнего символа
		switch (inform->SelectedIndex)
		{
			case 0: // конъюнкция
			{
				if (kate == 1)
				{
					MessageBox::Show(this, "Конъюнкция и дизъюнкция не могут быть вместе в одном выражении.", "Внимание!");
					break;
				}
				if (oper == 2 || oper == 3)
				{
					MessageBox::Show(this,"Две операции не могут идти подряд.", "Внимание!");
					break;
				}
				if (oper < 0)
				{
					MessageBox::Show(this,"Выражение не может начинаться со знака конъюнкции.", "Внимание!");
					break;
				}
				oper = 2;
				kate = 2;
				textBox1->Text = textBox1->Text + " & "; 
				break;
			}
			case 1: //дизъюнкция
			{
				if (kate == 2)
				{
					MessageBox::Show(this, "Конъюнкция и дизъюнкция не могут быть вместе в одном выражении.", "Внимание!");
					break;
				}
				if (oper == 1 || oper == 3)
				{
					MessageBox::Show(this,"Две операции не могут идти подряд.", "Внимание!");
					break;
				}
				if (oper < 0)
				{
					MessageBox::Show(this,"Выражение не может начинаться со знака дизъюнкции.", "Внимание!");
					break;
				}
				oper = 1;
				kate = 1;
				textBox1->Text = textBox1->Text + " v "; 
				break;
			}
			case 2: //отрицание
			{
				if (oper == 3)
				{
					MessageBox::Show(this,"Две операции не могут идти подряд.", "Внимание!");
					break;
				}
				else
				{
					if (oper == 0)
					{
						MessageBox::Show(this,"Недопустимое действие!", "Внимание!");
						break;
					}
				}
				textBox1->Text = textBox1->Text + "¬ "; 
				oper = 3; 
				break;
			}
		}

		inform->SelectedIndex = -1;
		textBox1->Focus();
		textBox1->Select(textBox1->Text->Length, 0);

		is_changes_ed = true; // произошли изменения
		return;
	}

	// кнопка "Добавить дизъюнктор"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		String ^s; 
		s =	textBox1->Text->ToString(); // сохранение строки из поля редактирования текста

		kate = what_kate(); // определение текущей операции
		oper = what_oper(); // определение последнего символа

		if (oper > 0)
		{
			MessageBox::Show(this,"Выражение не может оканчиваться знаком логической операции.", "Внимание!");
			textBox1->Focus();
			textBox1->Select(textBox1->Text->Length, 0);
			return;
		}
		if (kate == 2)
		{
			MessageBox::Show(this,"Выражение содержит конъюнкцию.", "Внимание!");
			textBox1->Focus();
			textBox1->Select(textBox1->Text->Length, 0);
			return;
		}
		if ( (textBox1->Text != "") && (s[0] != ' ') )
		{
			if (listBox1->SelectedIndex > -1)
			{
				listBox1->Items[listBox1->SelectedIndex] = textBox1->Text;
				listBox1->SelectedIndex = -1;
				textBox1->Text = ""; 
			}
			else
			{
				listBox1->Items->Add(textBox1->Text);
				textBox1->Text = "";
				n1++;
			} 
		}
		oper = -1;
		kate = 0;
		listBox1->SelectedIndex = -1;
		listBox2->SelectedIndex = -1;
		is_changes_ed = true; // произошли изменения
	}

	// выбор дизъюнктора из списка
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listBox1->SelectedIndex > -1)
		{
			d = 1; // выбран список дизъюнкторов
			textBox1->Text = listBox1->Items[listBox1->SelectedIndex]->ToString(); // добавление дизъюнктора в полне редактирования
			kate = what_kate(); // определение текущей операции
			oper = what_oper(); // определение последнего символа
		}
	}

	// кнопка "Добавить конъюнктор"
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		String ^ s;
		s = textBox1->Text->ToString();// сохранение строки из поля редактирования текста

		kate = what_kate(); // определение текущей операции
		oper = what_oper(); // определение последнего символа

		if (oper > 0)
		{
			MessageBox::Show(this,"Выражение не может оканчиваться знаком логической операции.", "Внимание!");
			textBox1->Focus();
			textBox1->Select(textBox1->Text->Length, 0);
			return;
		}
		if (kate == 1)
		{
			MessageBox::Show(this,"Выражение содержит дизъюнкцию.", "Внимание!");
			textBox1->Focus();
			textBox1->Select(textBox1->Text->Length, 0);
			return;
		}
		if ( (textBox1->Text != "") && (s[0] != ' ') )
		{
			if (listBox2->SelectedIndex > -1)
			{
				listBox2->Items[listBox2->SelectedIndex] = textBox1->Text;
				listBox2->SelectedIndex = -1;
				textBox1->Text = ""; 
			}
			else
			{
				listBox2->Items->Add(textBox1->Text);
				textBox1->Text = "";
				n2++;
			} 
		}
		oper = -1;
		kate = 0; 
		listBox1->SelectedIndex = -1;
		listBox2->SelectedIndex = -1;
		is_changes_ed = true; // произошли изменения
	}

	// выбор конъюнктора из списка
	private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listBox2->SelectedIndex > -1)
		{
			d = 2; // выбран список конъюнкторов
			textBox1->Text = listBox2->Items[listBox2->SelectedIndex]->ToString(); // добавление конъюнктора в полне редактирования
			kate = what_kate(); // определение текущей операции
			oper = what_oper(); // определение последнего символа
		}
	}

	// кнопка "Удалить элемент"
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (d == 1)
		{
			listBox1->Items->RemoveAt(listBox1->SelectedIndex);
			n1--;
		}
		else if (d == 2)
		{
			listBox2->Items->RemoveAt(listBox2->SelectedIndex);
			n2--;
		}

		textBox1->Text = "";
		kate = what_kate(); // определение текущей операции
		oper = what_oper(); // определение последнего символа
		listBox1->SelectedIndex = -1;
		listBox2->SelectedIndex = -1;
		d = 0;
		is_changes_ed = true; // произошли изменения
	}

	// кнопка "Сохранить"
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (is_changes_ed)
		{
			save(); // сохранение

			textBox1->Text = "";
			is_changes_ed = false; // отсутствие изменений
			edit_editor_txt(); // редактирование файла с заданиями
		}
	}

	// кнопка "В главное меню"
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (is_changes_ed)
		{
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result;

			result = MessageBox::Show(this, "Сохранить?", "Внимание!", buttons);

			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				save();
				Form1::kol_zad++;
			}
			else
			{
				if (n1 + n2 == 0)
					Form1::var--;
			}
			is_changes_ed = false;
			edit_editor_txt();
		}
		Form1::kolvo_zad(); // подсчёт количества заданий

		is_main = true; // переход к главному окну
		parentForm->Show();
		this->Close();
	}

	// кнопка "Удалить"
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		kate = what_kate(); // определение текущей операции
		oper = what_oper(); // определение последнего символа
		switch (oper)
		{
			case -1: 
			{ 
				textBox1->Focus();
				textBox1->Select(textBox1->Text->Length, 0);
				break;
			}  
			case 0: 
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
		oper = what_oper(); // определение последнего символа
		if (oper >= 0)
			kate = what_kate(); // определение текущей операции
		textBox1->Focus();
		textBox1->Select(textBox1->Text->Length, 0);
	}

	// ввод символа
	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
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
		kate = what_kate(); // определение текущей операции
		oper = what_oper(); // определение последнего символа
	}

	// закрытие окна "Редактор"
	private: System::Void editor_FormClosing_1(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		if (is_changes_ed)
		{
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result;

			result = MessageBox::Show(this, "Сохранить?", "Внимание!", buttons);

			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				save();
				Form1::kol_zad++;
			}
			else
			{
				if (n1 + n2 == 0)
					Form1::var--;
			}
			is_changes_ed = false;
			edit_editor_txt();
		}
		Form1::kolvo_zad(); // подсчёт количества заданий

		if (!is_main)
			parentForm->Close(); // закрыть главное окно
	}

	// редактирование файла с заданиями (editor.txt)
	private: void edit_editor_txt()
	{
		vector <string> a;
		ifstream in(Form1::fileEditor);
		while (in.peek() != EOF)
		{
			string s;
			getline(in, s);
			if (a.size() == 0)
				a.push_back(s);
			else
			{
				for (int i = 0; i != a.size(); i++)
				{
					if ( a[i].substr(0, a[i].find(".")) == s.substr(0, s.find(".")) )
					{
						a[i] = s;
						break;
					}
					if (i + 1 == a.size() )
						a.push_back(s);
				}
			}
		}
		in.close();

		ofstream out(Form1::fileEditor);
		for (int i = 0; i != a.size(); i++)
			out << a[i] << endl;
		out.close();
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
		if (n1 + n2 == 0)
		{
			MessageBox::Show( "Пустые поля.", "Внимание!");
			return;
		}
		if (n1 == 0)
		{
			MessageBox::Show( "Введите дизъюнкторы.", "Внимание!");
			return;
		}

		ofstream out(Form1::fileEditor, ios::app);
		out << Form1::var << ". "; 
		int x = 0;
		string s;
		while (x < n1 - 1)
		{
			s = convert_to_string(listBox1->Items[x]->ToString());
			out << s << ", ";
			x++;
		}
		s = convert_to_string(listBox1->Items[x]->ToString());
		out << s << " => ";
		
		listBox1->SelectedIndex = -1;
				
		if (n2 == 0)
			out << "0" << endl;
		else
		{
			x = 0;
			while (x < n2 - 1)
			{
				s = convert_to_string(listBox2->Items[x]->ToString());
				out << s << "; ";
				x++;
			}
			s = convert_to_string(listBox2->Items[x]->ToString());
			out << s << endl;

			listBox2->SelectedIndex = -1;
		}
		out.close();
	}

	// определение последнего символа
	short what_oper()
	{
		short x = textBox1->Text->Length;
		if (x == 0)
			return -1;
		else
		{
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

	// определение текущей операции
	short what_kate()
	{
		if (textBox1->Text->Length == 0)
			return 0;
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

};
}