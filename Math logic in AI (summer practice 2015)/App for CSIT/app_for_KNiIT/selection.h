#pragma once

#include "Form1.h"
#include "editor.h"
#include <fstream>
#include <string>

using namespace std;

namespace app_for_KNiIT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для selection
	/// </summary>
	public ref class selection : public System::Windows::Forms::Form
	{
	public:
		// связывание окна "Редактор заданий"(selection) с главным окном (Form1)
		selection(Form1^ parent)
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
		~selection()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::Label^  label1; // надпись "Задания"

	private: System::Windows::Forms::ListBox^  listBox1; // список заданий

	private: System::Windows::Forms::Button^  button1; // кнопка "В главное меню"
	private: System::Windows::Forms::Button^  button2; // кнопка "Редактировать"
	private: System::Windows::Forms::Button^  button3; // кнопка "Удалить задание"
	private: System::Windows::Forms::Button^  button4; // кнопка "Сохранить"

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(selection::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label()); // надпись "Задания"

			this->listBox1 = (gcnew System::Windows::Forms::ListBox()); // список заданий

			this->button1 = (gcnew System::Windows::Forms::Button()); // кнопка "В главное меню"
			this->button2 = (gcnew System::Windows::Forms::Button()); // кнопка "Редактировать"
			this->button3 = (gcnew System::Windows::Forms::Button()); // кнопка "Удалить задание"
			this->button4 = (gcnew System::Windows::Forms::Button()); // кнопка "Сохранить"

			this->SuspendLayout();
			//
			// надпись "Задания"
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(44, 18);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Задания";
			//
			// список заданий
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 17;
			this->listBox1->Location = System::Drawing::Point(26, 47);
			this->listBox1->Margin = System::Windows::Forms::Padding(4);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(406, 480);
			this->listBox1->TabIndex = 2;
			// 
			// кнопка "В главное меню"
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(483, 446);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(169, 81);
			this->button1->TabIndex = 0;
			this->button1->Text = L"В главное меню";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &selection::button1_Click);
			// 
			// кнопка "Редактировать"
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(483, 47);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(169, 74);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Редактировать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &selection::button2_Click);
			//  
			// кнопка "Удалить задание"
			// 
			this->button3->Location = System::Drawing::Point(483, 140);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(169, 74);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Удалить задание";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &selection::button3_Click);
			// 
			// кнопка "Сохранить"
			// 
			this->button4->Location = System::Drawing::Point(483, 348);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(169, 81);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Сохранить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &selection::button4_Click);
			// 
			// selection
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(692, 570);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"selection";
			this->Text = L"Редактор заданий";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &selection::selection_FormClosing_1);
			this->Load += gcnew System::EventHandler(this, &selection::selection_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: int n_k; // количество заданий до сохранения 
	private: bool is_changes_sel; // наличие/отсутствие изменений
	private: bool red; // переход/не переход в редактор
	private: bool is_main; // переход к главному окну
	private: static string* mas = new string[1000]; // массив заданий

#pragma endregion

	// загрузка окна "Редактор заданий"
	private: System::Void selection_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Location = Point(220, 100);
		is_changes_sel = false; // отсутствие изменений
		red = false; // нет перехода в редактор
		is_main = false; // нет перехода к главному окну
		Form1::kolvo_zad(); // подсчёт количества заданий
		list_zad(); // вывод списка заданий
	}

	// кнопка "В главное меню"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (is_changes_sel)
		{
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result;

			result = MessageBox::Show(this, "Сохранить изменения?", "Внимание!", buttons);
			
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				save(); // функция сохранения
			}
			else
			{
				if_not_save(); // функция, если не выбрано сохранение
			}
		}
		Form1::kolvo_zad(); // подсчёт количества заданий

		is_main = true; // переход к главному окну
		parentForm->Show();
		this->Close();
	}

	// кнопка "Редактировать"
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		int x = listBox1->SelectedIndex;
		Form1::var = x + 1;
		Form1::now_edit = true;

		if (Form1::var == 0)
		{
			MessageBox::Show(this,"Выберите задание.", "Внимание!");
			return;
		}

		if (is_changes_sel)
		{
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result;
			
			result = MessageBox::Show(this, "Сохранить изменения?", "Внимание!", buttons);

			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				save(); // функция сохранения
			}
			else
			{
				if_not_save(); // функция, если не выбрано сохранение
			}
		}

		// перейти к окну "Редактор"
		editor ^ed2 = gcnew editor(parentForm);
		red = true;	// перейти к редактору 
		ed2->Show();
		this->Close();	 
	}

	// кнопка "Удалить задание"
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (Form1::kol_zad <= 1)
		{
			MessageBox::Show(this,"Данный элемент удалить нельзя.", "Внимание!");
			return;
		}
		if (listBox1->SelectedIndex > -1)
		{
			mas[n_of_zad(listBox1->SelectedIndex)].insert(0, "!");
			listBox1->Items->RemoveAt(listBox1->SelectedIndex);
			is_changes_sel = true; // произошли изменения
			Form1::kol_zad--;
			listBox1->SelectedIndex = -1;
		}
		else
		{
			MessageBox::Show(this,"Выберите задание.", "Внимание!");
			return;
		}
	}

	// кнопка "Сохранить"
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		save(); // функция сохранения

		// заполнение массива заданий
		ifstream in(Form1::fileEditor);
		int i = 0;
		while (in.peek() != EOF)
		{
			getline(in, mas[i]);
			i++;
		}
		n_k = i;
		in.close();
	}

	// закрытие окна "Редактор заданий"
	private: System::Void selection_FormClosing_1(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
	{
		if (is_changes_sel)
		{
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result;

			result = MessageBox::Show(this, "Сохранить изменения?", "Внимание!", buttons);

			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				save(); // функция сохранения
			}
			else
			{
				if_not_save(); // функция, если не выбрано сохранение
			}	 
		}
		if (!red && !is_main)
			parentForm->Close(); // закрыть главное окно
	}

	// вывод списка заданий
	private: void list_zad()
	{
		Form1::kol_zad = 0;
		is_main = false;
		ifstream in(Form1::fileEditor);
		while (in.peek() != EOF)
		{
			string s, s1;
			getline(in, s);
			int x;
			x =  s.find('.');
			x += 2;
			s1 = s.substr(x, s.size() - x);
			String ^s2;
			s2 = gcnew String(s1.c_str());
			listBox1->Items->Add(s2);
			mas[Form1::kol_zad] = s; // заполнение массива заданий
			Form1::kol_zad++;
		}
		in.close();
		n_k = Form1::kol_zad;
	}

	// вычисление номера текущего задания в исходном списке заданий
	private: int short n_of_zad(int x)
	{
		int t = -1;
		for (int i = 0; i < n_k; i++)
		{
			if (mas[i].substr(0, 1) != "!")
				t++;
			if (t == x)
				return i;
		}
		return 0;
	}

	// функция сохранения
	private: void save()
	{
		ofstream out(Form1::fileEditor);
		for (int i = 0; i < Form1::kol_zad; i++)
		{
			string s;
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(listBox1->Items[i]->ToString())).ToPointer();
			s = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			out << i+1 << ". " << s << endl;
		}
		out.close();
		is_changes_sel = false; // отсутствие изменений
	}

	// функция, если не выбрано сохранение
	private: void if_not_save()
	{
		ofstream out(Form1::fileEditor);
		for (int i = 0; i < n_k; i++)
		{
			if (mas[i].substr(0, 1) == "!")
				mas[i].erase(0,1);
			out << mas[i] << endl;
		}
		out.close();
		is_changes_sel = false; // отсутствие изменений
	}
};
}
