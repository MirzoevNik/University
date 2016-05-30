#pragma once

#include "PClip.h"
#include <fstream>
#include <sstream>

namespace num_7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
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

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::Button^  btnOpen;



	private:
		System::Collections::Generic::List< TLine > lines;
		System::Collections::Generic::List< Polygon^ > polygons;

		float left, right, top, bottom;

		float v_cx, v_cy, v_x, v_y;
		float w_cx, w_cy, w_x, w_y;

		bool draw_names;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->FileName = L"openFileDialog1";
			this->openFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(12, 12);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(93, 32);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"Открыть";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &Form1::btnOpen_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(783, 553);
			this->Controls->Add(this->btnOpen);
			this->KeyPreview = true;
			this->MinimumSize = System::Drawing::Size(50, 110);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

				 lines.Clear();
				 polygons.Clear();

				 unit(T);

				 left = 12; 
				 right = 12;
				 top = 56;
				 bottom = 12;

				 w_cx = left;
				 w_cy = Form::ClientRectangle.Height - bottom;
				 w_x = Form::ClientRectangle.Width - left - right;
				 w_y = Form::ClientRectangle.Height - top - bottom;

				 draw_names = false;

			 }

	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

				 System::Drawing::Graphics^ g = e->Graphics;

				 System::Drawing::Pen^ black_pen = gcnew Pen( Color::Black );
				 black_pen->Width = 2;

				 System::Drawing::Pen^ rect_pen = gcnew Pen( Color::Green );
				 rect_pen->Width = 3;

				 g->DrawRectangle( rect_pen, w_cx, top, w_x, w_y );

				 TPoint p_min, p_max;
				 p_min.x = left;
				 p_min.y = top;
				 p_max.x = left + w_x;
				 p_max.y = w_cy;

				 for ( int i = 0; i < polygons.Count; i++ )
				 {
					 Polygon^ p = polygons[i];
					 Polygon^ p1 = gcnew Polygon();

					 TPoint a, b;
					 Vec A, B, A1, B1;

					 point2vec( p[ p->Count - 1 ], A );
					 timesMatVec( T, A, A1 );
					 vec2point( A1, a );					 p1->Add( a );
					 for ( int j = 0; j < p->Count; j++ )
					 {
						point2vec( p[j], B );
						timesMatVec( T, B, B1 );
						vec2point( B1, b );

						p1->Add( b );

						a = b;
					 }

					 Polygon^ p2 = pClip( p1, p_min, p_max );

					 if ( p2->Count > 0 )
					 {
						 a = p2[ p2->Count - 1 ];

						 for ( int j = 0; j < p2->Count; j++ )
						 {
							 b = p2[j];
							 g->DrawLine( black_pen, a.x, a.y, b.x, b.y );
							 a = b;
						 }
					 }
				 }

			 }

	private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e) {

				 if ( this->openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 wchar_t file_name[1024];
					 for ( int i = 0; i < openFileDialog->FileName->Length; i++ )
						 file_name[i] = openFileDialog->FileName[i];
					 file_name[openFileDialog->FileName->Length] = '\0';

					 std::ifstream in;
					 in.open( file_name );

					 if ( in.is_open() )
					 {
						 polygons.Clear();
						 unit( T );

						 std::string str;
						 getline( in, str );
						 while ( in )
						 {
							 if ( ( str.find_first_not_of(" \t\r\n") != std::string::npos ) && ( str[0] != '#' ) )
							 {
								 std::stringstream s( str );

								 std::string cmd;
								 s >> cmd;

								 if ( cmd == "frame" ) 
								 {
									 float x1, y1, x2, y2;
									 s >> x1 >> y1 >> x2 >> y2;
									 v_cx = x1;
									 v_cy = y1;
									 v_x = x2;
									 v_y = y2;

									 frame( v_x, v_y, v_cx, v_cy, w_x, w_y, w_cx, w_cy, T );
								 }
								 else if ( cmd == "polygon" )
								 {
									 int num_point;
									 s >> num_point;

									 Polygon^ pol = gcnew Polygon(0);
									 for ( int i = 0; i < num_point; i++ ) 
									 {
										TPoint p;
										s >> p.x >> p.y;
										pol->Add( p );
									 }									 polygons.Add( pol );
								 }
							 }

							 getline( in, str );
						 }
					 }

					 in.close();

					 //frame( v_x, v_y, v_cx, v_cy, w_x, w_y, w_cx, w_cy, T );

					 this->Refresh();
				 }

			 }

	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

				 System::Drawing::Rectangle rect = Form::ClientRectangle;

				 Mat R, T1;

				 float phi = 0.05; // угол поворота
				 float centre_x = rect.Width / 2;
				 float centre_y = rect.Height / 2;
				 float coef = 1.1; // коэффициент

				 switch ( e->KeyCode )
				 {
					 // движение
				 case Keys::W : // вверх
					 move( 0, -1, R );
					 break;
				 case Keys::S : // вниз
					 move( 0, 1, R );
					 break;
				 case Keys::A : // влево
					 move( -1, 0, R );
					 break;
			     case Keys::D : // вправо
					 move( 1, 0, R );
					 break;

					 // поворот относительно начала координат
				 case Keys::E : // по часовой
					 rotate( 0, 0, phi, R );
					 break;
				 case Keys::Q : // против часовой
					 rotate( 0, 0, -phi, R );
					 break;

					 // масштабирование относительно начала координат
				 case Keys::X : // увеличение
					 scale( coef, coef, R );
					 break;
				 case Keys::Z : // уменьшение
					 scale( 1 / coef, 1 / coef, R );
					 break;

					 // быстрое движение
				 case Keys::T : // вверх
					 move( 0, -10, R );
					 break;
				 case Keys::G : // вниз
					 move( 0, 10, R );
					 break;
				 case Keys::F : // влево
					 move( -10, 0, R );
					 break;
			     case Keys::H : // вправо
					 move( 10, 0, R );
					 break;

					 // поворот относительно центра
				 case Keys::Y : // по часовой
					 rotate( centre_x, centre_y, phi, R );
					 break;
				 case Keys::R : // против часовой
					 rotate( centre_x, centre_y, -phi, R );
					 break;

					 // отражение
				 case Keys::U : // по вертикали
					 reflectVertical( R );
					 times( R, T, T1 );
					 set( T1, T );
					 move( rect.Width, 0, R );
					 break;
				 case Keys::J : // по горизонтали
					 reflectHorizontal( R );
					 times( R, T, T1 );
					 set( T1, T );
					 move( 0, rect.Height, R );
					 break;

					 // масштабирование относительно центра окна
				 case Keys::V : // увеличение
					 move( -centre_x, -centre_y, R );
					 times( R, T, T1 );
					 scale( coef, coef, R );
					 times( R, T1, T);
					 move( centre_x, centre_y, R );
					 break;
				 case Keys::C : // уменьшение
					 move( -centre_x, -centre_y, R );
					 times( R, T, T1 );
					 scale( 1 / coef, 1 / coef, R );
					 times( R, T1, T);
					 move( centre_x, centre_y, R );
					 break;

					 // масштабирование относительно осей и центра окна
				 case Keys::O : // вертикаль + увеличение
					 move( 0, -centre_y, R );
					 times( R, T, T1 );
					 scale( 1, coef, R );
					 times( R, T1, T);
					 move( 0, centre_y, R );
					 break;
				 case Keys::I : // вертикаль + уменьшение
					 move( 0, -centre_y, R );
					 times( R, T, T1 );
					 scale( 1, 1 / coef, R );
					 times( R, T1, T);
					 move( 0, centre_y, R );
					 break;
				 case Keys::L : // горизонталь + увеличение
					 move( -centre_x, 0, R );
					 times( R, T, T1 );
					 scale( coef, 1, R );
					 times( R, T1, T);
					 move( centre_x, 0, R );
					 break;
				 case Keys::K : // горизонталь + уменьшение
					 move( -centre_x, 0, R );
					 times( R, T, T1 );
					 scale( 1 / coef, 1, R );
					 times( R, T1, T);
					 move( centre_x, 0, R );
					 break;

				 case Keys::P : // отобржать / не отображать название отрезков
					 draw_names = !draw_names;
					 unit( R );

					 break;

					 // приведение к первоначальному виду
				 case Keys::Escape :
					 unit( T );
					 /*reflectHorizontal( R );
					 set( R, T );
					 move( 0, Form::ClientRectangle.Height, R );*/
					 frame( v_x, v_y, v_cx, v_cy, w_x, w_y, w_cx, w_cy, R );
					 break;

				 default:
					 unit( R );
				 }

				 times( R, T, T1 );
				 set( T1, T );
				 this->Refresh();

			 }

private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {

			 float old_w_x = w_x;
			 float old_w_y = w_y;

			 w_cy = Form::ClientRectangle.Height - bottom;
		     w_x = Form::ClientRectangle.Width - left - right;
			 w_y = Form::ClientRectangle.Height - top - bottom;

			 Mat R, T1;

			 move( -w_cx, -top, R );
			 times( R, T, T1 );

			 scale( w_x / old_w_x, w_y / old_w_y, R );
			 times( R, T1, T);

			 move( w_cx, top, R );
			 times( R, T, T1 );
			 set( T1, T );

			 this->Refresh();

		 }
};
}

