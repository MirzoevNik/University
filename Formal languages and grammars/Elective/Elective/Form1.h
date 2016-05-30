#pragma once

#include "stdafx.h"

using namespace std;

namespace Elective {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  list_box_main;
	private: System::Windows::Forms::Button^  button_open_file;
	private: System::Windows::Forms::Label^  label_main;
	private: System::Windows::Forms::ListBox^  list_box_grammars;
	private: System::Windows::Forms::ListBox^  list_box_result;
	private: System::Windows::Forms::Label^  label_grammars;
	private: System::Windows::Forms::Label^  label_result;
	private: System::Windows::Forms::Button^  button_generate;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;

	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private: 
		wchar_t *file_substitution;
		char *file_result_grammar;

		Grammar *main_grammar;
		Grammar *result_grammar;
		set< pair < string, Grammar* > > *terminals_grammars;

		bool is_open_btn_click;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->list_box_main = (gcnew System::Windows::Forms::ListBox());
			this->button_open_file = (gcnew System::Windows::Forms::Button());
			this->label_main = (gcnew System::Windows::Forms::Label());
			this->list_box_grammars = (gcnew System::Windows::Forms::ListBox());
			this->list_box_result = (gcnew System::Windows::Forms::ListBox());
			this->label_grammars = (gcnew System::Windows::Forms::Label());
			this->label_result = (gcnew System::Windows::Forms::Label());
			this->button_generate = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// list_box_main
			// 
			this->list_box_main->FormattingEnabled = true;
			this->list_box_main->Location = System::Drawing::Point(39, 64);
			this->list_box_main->Name = L"list_box_main";
			this->list_box_main->Size = System::Drawing::Size(217, 303);
			this->list_box_main->TabIndex = 0;
			// 
			// button_open_file
			// 
			this->button_open_file->Location = System::Drawing::Point(192, 387);
			this->button_open_file->Name = L"button_open_file";
			this->button_open_file->Size = System::Drawing::Size(164, 34);
			this->button_open_file->TabIndex = 1;
			this->button_open_file->Text = L"Открыть файл";
			this->button_open_file->UseVisualStyleBackColor = true;
			this->button_open_file->Click += gcnew System::EventHandler(this, &Form1::button_open_file_Click);
			// 
			// label_main
			// 
			this->label_main->AutoSize = true;
			this->label_main->Location = System::Drawing::Point(78, 34);
			this->label_main->Name = L"label_main";
			this->label_main->Size = System::Drawing::Size(121, 13);
			this->label_main->TabIndex = 2;
			this->label_main->Text = L"Исходная грамматика";
			// 
			// list_box_grammars
			// 
			this->list_box_grammars->FormattingEnabled = true;
			this->list_box_grammars->Location = System::Drawing::Point(285, 64);
			this->list_box_grammars->Name = L"list_box_grammars";
			this->list_box_grammars->Size = System::Drawing::Size(255, 303);
			this->list_box_grammars->TabIndex = 3;
			// 
			// list_box_result
			// 
			this->list_box_result->FormattingEnabled = true;
			this->list_box_result->Location = System::Drawing::Point(571, 66);
			this->list_box_result->Name = L"list_box_result";
			this->list_box_result->Size = System::Drawing::Size(266, 303);
			this->list_box_result->TabIndex = 4;
			// 
			// label_grammars
			// 
			this->label_grammars->AutoSize = true;
			this->label_grammars->Location = System::Drawing::Point(331, 34);
			this->label_grammars->Name = L"label_grammars";
			this->label_grammars->Size = System::Drawing::Size(159, 13);
			this->label_grammars->TabIndex = 5;
			this->label_grammars->Text = L"Грамматики для подстановки";
			// 
			// label_result
			// 
			this->label_result->AutoSize = true;
			this->label_result->Location = System::Drawing::Point(643, 34);
			this->label_result->Name = L"label_result";
			this->label_result->Size = System::Drawing::Size(120, 13);
			this->label_result->TabIndex = 6;
			this->label_result->Text = L"Итоговая грамматика";
			// 
			// button_generate
			// 
			this->button_generate->Location = System::Drawing::Point(474, 386);
			this->button_generate->Name = L"button_generate";
			this->button_generate->Size = System::Drawing::Size(174, 35);
			this->button_generate->TabIndex = 7;
			this->button_generate->Text = L"Сгенерировать грамматику с подстановкой";
			this->button_generate->UseVisualStyleBackColor = true;
			this->button_generate->Click += gcnew System::EventHandler(this, &Form1::button_generate_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(877, 465);
			this->Controls->Add(this->button_generate);
			this->Controls->Add(this->label_result);
			this->Controls->Add(this->label_grammars);
			this->Controls->Add(this->list_box_result);
			this->Controls->Add(this->list_box_grammars);
			this->Controls->Add(this->label_main);
			this->Controls->Add(this->button_open_file);
			this->Controls->Add(this->list_box_main);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 file_substitution = new wchar_t[1024];
				 file_result_grammar = "result_grammar.txt";
				 main_grammar = new Grammar();
				 result_grammar = new Grammar();
				 terminals_grammars = new set< pair < string, Grammar* > >;
				 is_open_btn_click = false;
			 }

	private: System::Void button_open_file_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 is_open_btn_click = true;
				 this->list_box_main->Items->Clear();
				 this->list_box_grammars->Items->Clear();
				 main_grammar = new Grammar();
				 result_grammar = new Grammar();
				 terminals_grammars = new set< pair < string, Grammar* > >;

				 if ( this->openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 for ( int i = 0; i < openFileDialog->FileName->Length; i++ )
						 file_substitution[i] = openFileDialog->FileName[i];
					 file_substitution[ openFileDialog->FileName->Length ] = '\0';				 }
				 readFile();

				 set< string > non_terms = main_grammar->getNonTerminals();
				 this->list_box_main->Items->Add( gcnew System::String( ( "Множество нетерминалов (" + non_terms.size() + "):" ) ) );
				 if ( non_terms.size() )
				 {
					for ( set< string > :: iterator it = non_terms.begin(); it != non_terms.end(); it++ )
					{
						this->list_box_main->Items->Add( gcnew System::String( (*it).c_str() ) );
					}
				 }

				 set< string > terms = main_grammar->getTerminals();
				 this->list_box_main->Items->Add( gcnew System::String( ( "Множество терминалов (" + terms.size() + "):" ) ) );
				 if ( terms.size() )
				 {
					for ( set< string > :: iterator it = terms.begin(); it != terms.end(); it++ )
					{
						this->list_box_main->Items->Add( gcnew System::String( (*it).c_str() ) );
					}
				 }

				 set< Production* > prods = main_grammar->getProductions();
				 this->list_box_main->Items->Add( gcnew System::String( ( "Множество продукций (" + prods.size() + "):" ) ) );
				 if ( prods.size() )
				 {
					for ( set< Production* > :: iterator it = prods.begin(); it != prods.end(); it++ )
					{
						this->list_box_main->Items->Add( gcnew System::String( ( (*it)->getLeftPart() + " -> " + (*it)->getRightPart() ).c_str() ) );
					}
				 }

				 this->list_box_main->Items->Add( gcnew System::String( ( "Начальный символ: " + main_grammar->getStartSymbol() ).c_str() ) );

				 for ( set< pair < string, Grammar* > > :: iterator it = terminals_grammars->begin(); it != terminals_grammars->end(); it++ )
				 {
					 string term = (*it).first;

					 this->list_box_grammars->Items->Add( gcnew System::String( ( "Терминал из исходной грамматики: " + term ).c_str() ) );

					 Grammar *grammar = (*it).second;

					 non_terms = grammar->getNonTerminals();
					 this->list_box_grammars->Items->Add( gcnew System::String( ( "Множество нетерминалов (" + non_terms.size() + "):" ) ) );
					 if ( non_terms.size() )
					 {
						for ( set< string > :: iterator it = non_terms.begin(); it != non_terms.end(); it++ )
						{
							this->list_box_grammars->Items->Add( gcnew System::String( (*it).c_str() ) );
						}
					 }

					 terms = grammar->getTerminals();
					 this->list_box_grammars->Items->Add( gcnew System::String( ( "Множество терминалов (" + terms.size() + "):" ) ) );
					 if ( terms.size() )
					 {
						for ( set< string > :: iterator it = terms.begin(); it != terms.end(); it++ )
						{
							this->list_box_grammars->Items->Add( gcnew System::String( (*it).c_str() ) );
						}
					 }

					 prods = grammar->getProductions();
					 this->list_box_grammars->Items->Add( gcnew System::String( ( "Множество продукций (" + prods.size() + "):" ) ) );
					 if ( prods.size() )
					 {
						for ( set< Production* > :: iterator it = prods.begin(); it != prods.end(); it++ )
						{
							this->list_box_grammars->Items->Add( gcnew System::String( ( (*it)->getLeftPart() + " -> " + (*it)->getRightPart() ).c_str() ) );
						}
					 }

					 this->list_box_grammars->Items->Add( gcnew System::String( ( "Начальный символ: " + grammar->getStartSymbol() ).c_str() ) );
					 this->list_box_grammars->Items->Add( gcnew System::String( " " ) );
				 }
			 }

	private: System::Void button_generate_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if ( is_open_btn_click )
				 {
					 this->list_box_result->Items->Clear();

					 makeSubstitution();

					 set< string > non_terms = result_grammar->getNonTerminals();
					 this->list_box_result->Items->Add( gcnew System::String( ( "Множество нетерминалов (" + non_terms.size() + "):" ) ) );
					 if ( non_terms.size() )
					 {
						for ( set< string > :: iterator it = non_terms.begin(); it != non_terms.end(); it++ )
						{
							this->list_box_result->Items->Add( gcnew System::String( (*it).c_str() ) );
						}
					 }

					 set< string > terms = result_grammar->getTerminals();
					 this->list_box_result->Items->Add( gcnew System::String( ( "Множество терминалов (" + terms.size() + "):" ) ) );
					 if ( terms.size() )
					 {
						for ( set< string > :: iterator it = terms.begin(); it != terms.end(); it++ )
						{
							this->list_box_result->Items->Add( gcnew System::String( (*it).c_str() ) );
						}
					 }

					 set< Production* > prods = result_grammar->getProductions();
					 this->list_box_result->Items->Add( gcnew System::String( ( "Множество продукций (" + prods.size() + "):" ) ) );
					 if ( prods.size() )
					 {
						for ( set< Production* > :: iterator it = prods.begin(); it != prods.end(); it++ )
						{
							this->list_box_result->Items->Add( gcnew System::String( ( (*it)->getLeftPart() + " -> " + (*it)->getRightPart() ).c_str() ) );
						}
					 }

					 this->list_box_result->Items->Add( gcnew System::String( ( "Начальный символ: " + result_grammar->getStartSymbol() ).c_str() ) );

					 is_open_btn_click = false;
				 }
			 }

	private: void readFile()
			{
				ifstream in( file_substitution );

				string file_main_grammar;
				getline( in, file_main_grammar );

				main_grammar = new Grammar();
				main_grammar->readGrammar( file_main_grammar.c_str() );
				
				int count_terminals = main_grammar->getCountTerminals();

				for ( int i = 0; i < count_terminals; i++ )
				{
					string file_grammar;
					getline( in, file_grammar );

					int j = file_grammar.find( " " );
					string terminal = file_grammar.substr( 0, j );
					file_grammar = file_grammar.substr( j + 1, file_grammar.size() - j + 1 );

					Grammar *grammar = new Grammar();
					grammar->readGrammar( file_grammar.c_str() );

					pair < string, Grammar* > term_gram;
					term_gram.first = terminal;
					term_gram.second = grammar;

					terminals_grammars->insert( term_gram );
				}

				in.close();
			}

	private: void makeSubstitution()
			{
				result_grammar = main_grammar;

				string old_start_symbol = result_grammar->getStartSymbol();

				string start_non_term = result_grammar->checkAndGenerateNewSymbol( old_start_symbol, '!', '!' );
				result_grammar->addNonTerminal( start_non_term );
				result_grammar->setStartSymbol( start_non_term );

				string extra_non_term = result_grammar->checkAndGenerateNewSymbol( old_start_symbol, '*', '*' );
				result_grammar->addNonTerminal( extra_non_term );

				result_grammar->addProduction( start_non_term, extra_non_term + old_start_symbol );
				result_grammar->addProduction( extra_non_term, "\"\"" );

				for ( set< pair < string, Grammar* > > :: iterator it = terminals_grammars->begin(); it != terminals_grammars->end(); it++ )
				{
					string term = (*it).first;
					string non_term = result_grammar->checkAndGenerateNewSymbol( term, '[', ']' );
					result_grammar->replaceTerminalAtNonTerminal( term, non_term );

					result_grammar->addProduction( extra_non_term + non_term, extra_non_term + (*it).second->getStartSymbol() );
				}

				for ( set< pair < string, Grammar* > > :: iterator it = terminals_grammars->begin(); it != terminals_grammars->end(); it++ )
				{
					set< string > result_non_terminals = result_grammar->getNonTerminals();

					Grammar *grammar = (*it).second;

					set< string > non_terminals = grammar->getNonTerminals();
					for ( set< string > :: iterator j = non_terminals.begin(); j != non_terminals.end(); j++ )
					{
						string new_non_term = result_grammar->checkAndGenerateNewSymbol( (*j), '{', '}' );

						bool is_find = false;

						for ( set< string > :: iterator k = result_non_terminals.begin(); k != result_non_terminals.end(); k++ )
						{
							if ( *k == *j )
							{
								grammar->replaceNonTerminalAtNonTerminal( *j, new_non_term );
								is_find = true;
								break;
							}
						}

						if ( !is_find )
						{
							set< string > result_terminals = result_grammar->getTerminals();
							for ( set< string > :: iterator k = result_terminals.begin(); k != result_terminals.end(); k++ )
							{
								if ( *k == *j )
								{
									grammar->replaceNonTerminalAtNonTerminal( *j, new_non_term );
									is_find = true;
									break;
								}
							}
						}

						if ( !is_find )
							result_grammar->addNonTerminal( *j );
						else
							result_grammar->addNonTerminal( new_non_term );
					}
					
					set< string > terminals = grammar->getTerminals();
					for ( set< string > :: iterator j = terminals.begin(); j != terminals.end(); j++ )
					{
						for ( set< string > :: iterator k = result_non_terminals.begin(); k != result_non_terminals.end(); k++ )
						{
							if ( *k == *j )
							{
								string new_non_term = result_grammar->checkAndGenerateNewSymbol( (*j), '(', ')' );
								result_grammar->replaceNonTerminalAtNonTerminal( *k, new_non_term );
								break;
							}
						}

						result_grammar->addTerminal( *j );
						result_grammar->addProduction( extra_non_term + (*j), (*j) + extra_non_term );
					}
					
					set< Production* > productions = grammar->getProductions();
					for ( set< Production* > :: iterator j = productions.begin(); j != productions.end(); j++ )
					{
						result_grammar->addProduction( (*j)->getLeftPart(), (*j)->getRightPart() );
					}
				}

				result_grammar->printGrammar( file_result_grammar );
			}

};
}

