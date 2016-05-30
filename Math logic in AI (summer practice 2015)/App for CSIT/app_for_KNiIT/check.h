#pragma once

#include "Form1.h"
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

// 
struct expr
{
	string inf;
	bool label;
};

namespace app_for_KNiIT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for check
	/// </summary>
	public ref class check : public System::Windows::Forms::Form
	{
	public:
		// связывание окна "Проверка заданий"(check) с главным окном (Form1)
		check(Form1^ parent)
		{
			InitializeComponent();
			parentForm = parent;
			//
			//TODO: Add the constructor code here
			//
		}
	private: Form1^ parentForm;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~check()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::Label^  label1; // надпись "Действия"
	private: System::Windows::Forms::Label^  label2; // надпись "Результат"
	private: System::Windows::Forms::Label^  label3; // надпись "Проверка"
	private: System::Windows::Forms::Label^  label4; // надпись "Задание:"

	private: System::Windows::Forms::ListBox^  listBox1; // список действий
	private: System::Windows::Forms::ListBox^  listBox2; // список результатов
	private: System::Windows::Forms::ListBox^  listBox3; // список проверки
	
	private: System::Windows::Forms::TextBox^  textBox1; // поле с заданием

	private: System::Windows::Forms::Button^  button1; // кнопка "В главное меню"

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(check::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(33, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Действия";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(382, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Результат";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(691, 37);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(101, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Проверка";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(132, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 25);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Задание: ";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->HorizontalScrollbar = true;
			this->listBox1->ItemHeight = 17;
			this->listBox1->Location = System::Drawing::Point(12, 71);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(325, 429);
			this->listBox1->TabIndex = 3;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &check::listBox1_SelectedIndexChanged);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->HorizontalScrollbar = true;
			this->listBox2->ItemHeight = 17;
			this->listBox2->Location = System::Drawing::Point(356, 71);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(308, 429);
			this->listBox2->TabIndex = 4;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &check::listBox2_SelectedIndexChanged);
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 17;
			this->listBox3->Location = System::Drawing::Point(685, 71);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(123, 429);
			this->listBox3->TabIndex = 5;
			this->listBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &check::listBox3_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(230, 11);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(480, 24);
			this->textBox1->TabIndex = 8;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &check::textBox1_KeyPress);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(828, 436);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(83, 64);
			this->button1->TabIndex = 6;
			this->button1->Text = L"В главное меню";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &check::button1_Click);
			// 
			// check
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(923, 522);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"check";
			this->Text = L"Проверка задания";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &check::check_FormClosing);
			this->Load += gcnew System::EventHandler(this, &check::check_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: bool is_main; // переход к главному окну
	private: bool true_check; // проверка на правильность

#pragma endregion

	// загрузка окна "Проверка заданий"
	private: System::Void check_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Location = Point(220, 100);
		is_main = false;
		true_check = true;

		ifstream in(Form1::fileCheck);
		int n = 0;
		while (in.peek() != EOF)
		{
			string s;
			getline(in, s);
			
			if (s.size() > 6 && s.substr(0, 6) == "Task: ")
			{
				string s1 = s.substr(6, s.size() - 6);
				String ^s2;
				s2 = gcnew String(s1.c_str());
				textBox1->Text = s2;	
				n--;
			}
	        else
			{
				listBox1->Items->Add("");
				listBox2->Items->Add("");
				listBox3->Items->Add("");

				if (s[0] == '!')
				{
					func_word(s, n); // определение действия студента
				}
				else
				{
					string s1;
					bool is_crash = false;
					int x = s.find("!=>");
					if (x == string::npos)
					{
						x = s.find("!=Crash>");
						is_crash = true;
					}
					s1 = s.substr(0, x - 1);
					String ^s2;
					s2 = gcnew String(s1.c_str());
					listBox1->Items[n] = s2;
					x += 4;
					if (is_crash)
						x += 5;
					s1 = s.substr(x, s.size() - x);
					if (s1[0] == '!')
						func_word(s1, n); // определение действия студента
					else
					{
						String ^s3;
						s3 = gcnew String(s1.c_str());
						listBox2->Items[n] = s3;
					}
				}

				if (s!= "!Open" && s != "!Close" && listBox2->Items[n] != "Выражение удалено" && listBox2->Items[n] != "Клауза разбита")
				{
					if (for_check(s, n)) // проверка
					{
						listBox3->Items[n] = "Верно";
					}
					else
					{
						listBox3->Items[n] = "Ошибка";
					}
				}
			}
			n++;
		}
		in.close(); 
	}

	// кнопка "В главное меню"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		is_main = true; // переход к главному окну
		parentForm->Show();
		this->Close();
	}

	// блокировка изменений в поле с заданием
	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		e->Handled = true; // блокировка ввода символа
	}

	// отмена выбора элемента списка действий
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listBox1->SelectedIndex > -1)
			listBox1->SelectedIndex = -1;
	}

	// отмена выбора элемента списка результатов
	private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listBox2->SelectedIndex > -1)
			listBox2->SelectedIndex = -1;
	}

	// отмена выбора элемента списка проверки
	private: System::Void listBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listBox3->SelectedIndex > -1)
			listBox3->SelectedIndex = -1;
	}

	// закрытие окна "Проверка заданий"
	private: System::Void check_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		if (!is_main)
			parentForm->Close(); // закрыть главное окно
	}

	// проверка
	private: bool for_check(string s, int n)
	{
		if (listBox2->Items[n] == "Клауза доказана" || listBox2->Items[n] == "Клауза недоказуема")
		{
			if (listBox2->Items[n] == "Клауза доказана")
			{
				if (s == "!Proved+" && true_check)
					return true;
				else
					return false;
			}
			else
			{
				if (s == "!Unproven+" && true_check)
					return true;
				else
					return false;
			}
		}
		else
		{
			string s1 = "", s2 = "";
			int x = s.find("!=Crash>");
			if (x != string::npos)
			{
				bool crash = check_crash( s.substr(0, x - 1), s.substr(x + 9, s.size() - (x + 9)), s1 );
				if (crash)
				{
					true_check = true;
					return true;
				}
				else
				{
					s = s1 + " !=> " + s.substr(x + 9, s.size() - (x + 9));
				}
			}

			x = s.find("!=>");
			s1 = s.substr(0, x - 1);
			x += 4;
			s2 = s.substr(x, s.size() - x);

			// разибваем левую часть на массивы a и b
			int i = 0;
			if (s1[0] >= '0' && s1[0] <= '9')
			{
				while (s1[i] != ' ')
					i++;
				i++;
			}
			s1 = s1.substr(i); 
			expr *a, *b = new expr[30];
			int ka = 0, kb = 0;
			if (s1.find("=>") != string::npos)
			{				 
				a = divide(s1.substr(0, s1.find("=>") - 1), ka); // разбиваем левую часть (от "=>") на выражения
				b = divide(s1.substr(s1.find("=>") + 3, s1.size() - (s1.find("=>") + 3)), kb); // разбиваем правую часть (от "=>") на выражения
			}
			else
			{
				a = divide(s1, ka); // разбиваем левую часть (от "!=>") на выражения
			}

			// проверка на клаузу Вонга
			if (listBox2->Items[n] == "Клауза помечена как клауза Вонга")
			{
				for (int i = 0; i < ka; i++)
					for (int j = 0; j < kb; j++)
					{
						if (a[i].inf == b[j].inf)
							return true;
					}
				
				for (int i = 0; i < ka - 1; i++)
				{
					for (int j = i + 1; j < ka; j++)
					{
						int size = a[i].inf.size();
						if (size > 2 && a[i].inf.substr(2, size - 2) == a[j].inf)
							return true;
						size = a[j].inf.size();
						if (size > 2 && a[j].inf.substr(2, size - 2) == a[i].inf)
							return true;
					}
				}

				for (int i = 0; i < kb - 1; i++)
				{
					for (int j = i + 1; j < kb; j++)
					{
						int size = b[i].inf.size();
						if (size > 2 && b[i].inf.substr(2, size - 2) == b[j].inf)
							return true;
						size = b[j].inf.size();
						if (size > 2 && b[j].inf.substr(2, size - 2) == b[i].inf)
							return true;
					}
				}

				true_check = false;
				return false;
			}
					 
			// разибваем правую часть на массивы c и d
			i = 0;
			if (s2.size() > 1 && s2[0] >= '0' && s2[0] <= '9')
			{
				while (s2[i] != ' ')
					i++;
				i++;
			}
			s2 = s2.substr(i); 
			expr *c, *d = new expr[30];
			int kc = 0, kd = 0;
			
			if (s2.find("=>") != string::npos)
			{				 
				c = divide(s2.substr(0, s2.find("=>") - 1), kc); // разбиваем левую часть (от "=>") на выражения
				d = divide(s2.substr(s2.find("=>") + 3, s2.size() - (s2.find("=>") + 3)), kd); // разбиваем правую часть (от "=>") на выражения
			}
			else
			{
				c = divide(s2, kc); // разбиваем правую часть (от "!=>") на выражения
			}
			
			// метод резолюций
			if (kb == 0 && kd == 0)
			{
				expr *a_full = new expr[40];
				int ka_full = 0;
				a_full = divide_vars(a[0].inf, a[1].inf, ka_full);
					 
				// помечаем все одинаковые переменные
				for (int i = 0; i < ka_full - 1; i++)
				{
					if (!a_full[i].label)
					{
						for (int j = i + 1; j < ka_full; j++)
							if (a_full[i].inf == a_full[j].inf)
								a_full[j].label = true;
					}
				}
				
				bool paste_together = false; // склеивание
				// помечаем все переменные, имеющие отрицание
				for (int i = 0; i < ka_full - 1; i++)
				{
					if (!a_full[i].label)
					{
						for (int j = i + 1; j < ka_full; j++)
						{
							int size = a_full[i].inf.size();
							if (size > 2 && a_full[i].inf.substr(2, size - 2) == a_full[j].inf)
							{
								if (paste_together)
								{
									break;
								}
								a_full[i].label = true;
								a_full[j].label = true;
								paste_together = true;
								break;
							}
							size = a_full[j].inf.size();
							if (size > 2 && a_full[j].inf.substr(2, size - 2) == a_full[i].inf)
							{
								if (paste_together)
								{
									break;
								}
								a_full[i].label = true;
								a_full[j].label = true;
								paste_together = true;
								break;
							}
						}
					}
				}

				// подсчитываем количество непомеченных переменных
				int nep = 0;
				for (int i = 0; i < ka_full; i++)
					if (!a_full[i].label)
						nep++;
						 
				if (nep == 0)
				{
					if (c[0].inf == "0")
						return true;
					else
						{
							true_check = false;
							return false;
						}
				}
				else
				{
					int i = 0;
					int pos = 0;
					while (i != c[0].inf.size())
					{
						i++;
						if (i == c[0].inf.size() || (i + 1 < c[0].inf.size() && c[0].inf[i + 1] == 'v'))
						{
							for (int j = 0; j < ka_full; j++)
							{
								if (!a_full[j].label && c[0].inf.substr(pos, i - pos) == a_full[j].inf)
								{
									a_full[j].label = true;
									break;
								}
								if (j + 1 == ka_full)
								{
									true_check = false;
									return false;
								}
							}
							if (i == c[0].inf.size())
								break;
							i += 2;
							pos = i + 1;
						}
					}
					nep = 0;
					for (int i = 0; i < ka_full; i++)
						if (!a_full[i].label)
							nep++;
							 
					if (nep == 0)
						return true;
					else
					{
						true_check = false;
						return false;
					}
				}
			}
			else // метод Вонга
			{
				// помечаем одинаковые a и c
				for (int i = 0; i < ka; i++)
				{
					for (int j = 0; j < kc; j++)
						if (a[i].inf == c[j].inf)
						{
							a[i].label = true;
							c[j].label = true;
						}
				}
						 
				// помечаем одинаковые b и d
				for (int i = 0; i < kb; i++)
				{
					for (int j = 0; j < kd; j++)
						if (b[i].inf == d[j].inf)
						{
							b[i].label = true;
							d[j].label = true;
						}
				}					 
						 
				// ищем обратные к c из b
				for (int i = 0; i < kc; i++)
				{
					for (int j = 0; j < kb; j++)
					{
						if (!b[j].label)
						{
							int size = c[i].inf.size();
							if (size > 2 && c[i].inf.substr(2, size - 2) == b[j].inf)
							{
								b[j].label = true;
								c[i].label = true;
							}
							else
							{
								size = b[j].inf.size();
								if (size > 2 && b[j].inf.substr(2, size - 2) == c[i].inf)
								{
									b[j].label = true;
									c[i].label = true;
								}
							}
						}
						if (j + 1 == kb && !c[i].label)
						{
							true_check = false;
								return false;
						}
					}
				}

				// ищем обратные к d из a
				for (int i = 0; i < kd; i++)
				{
					for (int j = 0; j < ka; j++)
					{
						if (!a[j].label)
						{
							int size = d[i].inf.size();
							if (size > 2 && d[i].inf.substr(2, size - 2) == a[j].inf)
							{
								a[j].label = true;
								d[i].label = true;
							}
							else
							{
								size = a[j].inf.size();
								if (size > 2 && a[j].inf.substr(2, size - 2) == d[i].inf)
								{
									a[j].label = true;
									d[i].label = true;
								}
							}
						}
						if (j + 1 == ka && !d[i].label)
						{
							true_check = false;
							return false;
						}
					}
				}

				// проверяем непомеченные a
				for (int i = 0; i < ka; i++)
					if (!a[i].label)
						for (int j = 0; j < kc; j++)
						{
							if (a[i].inf == c[j].inf)
							{
								a[i].label = true;
								break;
							}
							if (j + 1 == kc && !a[i].label)
							{
								true_check = false;
								return false;
							}
						}
						
				// проверяем непомеченные b
				for (int i = 0; i < kb; i++)
					if (!b[i].label)
						for (int j = 0; j < kd; j++)
						{
							if (b[i].inf == d[j].inf)
							{
								b[i].label = true;
								break;
							}
							if (j + 1 == kd && !b[i].label)
							{
								true_check = false;
								return false;
							}
						}
				return true;
			}
		}
	}

	// проверка разбиения клаузы
	private: bool check_crash(string s1, string s2, string &new_str)
	{ 
		int num = (int)s1[s1.find(" ") - 2] - 48;
		int x = s1.find("v");
		if (x == string::npos)
			x = s1.find("&");
		int i = 0, j = 0;
		for (i = x; i >= 0; i--)
		{
			if (i == 0 || s1[i] == '.' || s1[i] == ',' || s1[i] == ';' || s1[i] == '>')
				break;
		}
		if (i > 0)
			i += 2;
		for (j = x + 1; j != s1.size(); j++)
		{
			if (j + 1 == s1.size() || s1[j] == ',' || s1[j] == ';' || s1[j + 1] == '=')
				break;
		}

		int k = 0;
		string st = "";
		x = i + 1; 
		int t = i;
		while (x < j)
		{
			if (x + 1 == j || s1[x + 1] == 'v' || s1[x + 1] == '&')
			{
				k++;
				if (k == num)
				{
					if (x + 1 == j)
						x++;
					st = s1.substr(t, x - t);
					break;
				}
				t = x + 3;
				x = t - 1;
			}
			x++;
		}

		new_str = "";
		new_str = s1.substr(0, i) + st + s1.substr(j, s1.size() - j);

		if (new_str == s2)
			return true;
		else
			return false;
	}

	// разбивание строки на выражения
	private: expr *divide(string s, int &k)
	{
		int i = 0, pos = 0;
		expr *mas = new expr[30];
		while (i != s.size())
		{
			i++;
			if (i == s.size() || s[i] == ',' || s[i] == ';')
			{
				mas[k].inf = s.substr(pos, i - pos);
				mas[k].label = false;
				k++;
				if (i == s.size())
					break;
				i++;
				pos = i + 1;
			}
		}
		return mas;
	}

	// разбивание двух выражений на переменные
	private: expr *divide_vars(string s1, string s2, int &k)
	{		 
		int i = 0, pos = 0;
		expr *mas = new expr[40];
		while (i != s1.size())
		{
			i++;
			if (i == s1.size() || (i + 1 < s1.size() && s1[i + 1] == 'v'))
			{
				mas[k].inf = s1.substr(pos, i - pos);
				mas[k].label = false;
				k++;
				if (i == s1.size())
					break;
				i += 2;
				pos = i + 1;
			}
		} 
		i = 0; pos = 0;
		while (i != s2.size())
		{
			i++;
			if (i == s2.size() || (i + 1 < s2.size() && s2[i + 1] == 'v'))
			{
				mas[k].inf = s2.substr(pos, i - pos);
				mas[k].label = false;
				k++;
				if (i == s2.size())
					break;
				i += 2;
				pos = i + 1;
			}
		}
		return mas;
	}

	// определение действия студента
	private: void func_word(string s, int x)
	{
		if (s == "!Open")
			listBox2->Items[x] = "Приложение открыто";
		if (s == "!Close")
			listBox2->Items[x] = "Приложение закрыто";
		if (s == "!Proved+" || s == "!Proved-")
			listBox2->Items[x] = "Клауза доказана";
		if (s == "!Unproven+" || s == "!Unproven-")
			listBox2->Items[x] = "Клауза недоказуема";
		if (s == "!Delete")
			listBox2->Items[x] = "Выражение удалено";
		if (s == "!Crash")
			listBox2->Items[x] = "Клауза разбита";
		if (s == "!Wong")
			listBox2->Items[x] = "Клауза помечена как клауза Вонга";
	}

};
}
