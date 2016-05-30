#pragma once

#include "PClip.h"
#include <fstream>
#include <sstream>

#define ALPHA 5

namespace num_9 {

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
		System::Collections::Generic::List< Polygon3D^ > polygons;
		System::Collections::Generic::List< System::Drawing::Color > colors;
		System::Drawing::Color current_color;

		Point3D eye, up, center, eye_start, up_start, center_start;
		float fovy, near, aspect, far, alpha, fovy_start, near_start;
		bool pr_ortho;

		float left, right, top, bottom;

		float v_cx, v_cy, v_x, v_y;
		float w_cx, w_cy, w_x, w_y;

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
			this->openFileDialog->Filter = L"“екстовые файлы (*.txt)|*.txt|¬се файлы (*.*)|*.*";
			this->openFileDialog->Title = L"ќткрыть файл";
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(12, 12);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(93, 32);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"ќткрыть";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &Form1::btnOpen_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(783, 553);
			this->Controls->Add(this->btnOpen);
			this->DoubleBuffered = true;
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

				 unit(T);

				 left = 12; 
				 right = 12;
				 top = 56;
				 bottom = 12;

				 w_cx = left;
				 w_cy = Form::ClientRectangle.Height - bottom;
				 w_x = Form::ClientRectangle.Width - left - right;
				 w_y = Form::ClientRectangle.Height - top - bottom;

				 aspect = w_x / w_y;

			 }

	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

				 System::Drawing::Graphics^ g = e->Graphics;

				 System::Drawing::Pen^ draw_pen = gcnew Pen( Color::Black );
				 draw_pen->Width = 2;

				 System::Drawing::Pen^ rect_pen = gcnew Pen( Color::Green );
				 rect_pen->Width = 2;

				 g->DrawRectangle( rect_pen, w_cx, top, w_x, w_y );

				 TPoint p_min, p_max;
				 p_min.x = left;
				 p_min.y = top;
				 p_max.x = left + w_x;
				 p_max.y = w_cy;

				 Mat3D V, U, R, T1;

				 lookAt(eye, center, up, V);

				 if ( pr_ortho ) 
				 {
					 float v_y = 2 * near * tan( fovy / 2 );
					 float v_x = v_y * aspect;
					 ortho( v_x, v_y, near, far, U );
				 } 
				 else
					 perspective( fovy, aspect, near, far, U );

				 times( U, V, T1 );
				 times( T1, T3D, R );

				 Mat F;
				 frame( 2, 2, -1, -1, w_x, w_y, w_cx, w_cy, F );

				 for ( int i = 0; i < polygons.Count; i++ )
				 {
					 Polygon3D ^p = polygons[i];
					 Polygon ^p1 = gcnew Polygon(0);

					 TPoint a, b;
					 Vec A1, A2;
					 Point3D a3D;
					 Vec3D A1_3D, A2_3D;

					 for ( int j = 0; j < p->Count; j++ )
					 {
						point2vec( p[j], A1_3D );
						timesMatVec( R, A1_3D, A2_3D );
						vec2point( A2_3D, a3D );
						set( a3D, a );

						point2vec( a, A1 );
						timesMatVec( F, A1, A2 );
						vec2point( A2, a );

						p1->Add( a );
					 }

					 Polygon^ p2 = pClip( p1, p_min, p_max );

					 if ( p2->Count > 0 )
					 {
						 draw_pen->Color = colors[i];
						 a = p2[ p2->Count - 1 ];

						 for ( int j = 0; j < p2->Count; j++ )
						 {
							 b = p2[j];
							 g->DrawLine( draw_pen, a.x, a.y, b.x, b.y );
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

					 polygons.Clear();
					 colors.Clear();

					 current_color = Color::Black;

					 std::ifstream in;
					 in.open( file_name );

					 if ( in.is_open() )
					 {
						 std::string str;
						 getline( in, str );

						 while ( in )
						 {
							 if ( ( str.find_first_not_of(" \t\r\n") != std::string::npos ) && ( str[0] != '#' ) )
							 {
								 std::stringstream s( str );

								 std::string cmd;
								 s >> cmd;

								 if ( cmd == "lookat" )
								 {
									 float e_x, e_y, e_z, c_x, c_y, c_z, u_x, u_y, u_z;
									 s >> e_x >> e_y >> e_z >> c_x >> c_y >> c_z >> u_x >> u_y >> u_z;

									 eye_start.x = e_x;
									 eye_start.y = e_y;
									 eye_start.z = e_z;

									 center_start.x = c_x;
									 center_start.y = c_y;
									 center_start.z = c_z;

									 up_start.x = u_x;
									 up_start.y = u_y;
									 up_start.z = u_z;
								 } 
								 else if ( cmd == "screen" )
								 {
									 float a, b, c;
									 s >> a >> b >> c;
									 fovy_start = a;
									 near_start = b;
									 far = c;
								 } 
								 else if ( cmd == "triangle" )
								 {				
									 Polygon3D ^P = gcnew Polygon3D(0);
									
									 for ( int i = 0; i < 3; i++ )
									 {
									 	 Point3D p;
										 s >> p.x >> p.y >> p.z;
										 P->Add(p);
									 }

									 polygons.Add(P);
									 colors.Add( current_color );
								} 
								else if ( cmd == "color" )
								{
									 int r, g, b;
									 s >> r >> g >> b;

									 current_color = Color::FromArgb( r, g, b );
								}
							 }

							 getline( in, str );
						 }
					 }

					 in.close();

					 center = center_start;
					 near = near_start;
					 fovy = fovy_start;

					 lookAt( center_start, eye_start, up_start, T3D );

					 Vec3D V1, V2;
					 Point3D P1;

					 point2vec( eye_start, V1 );
                     timesMatVec( T3D, V1, V2 );
                     vec2point( V2, P1 );

					 eye = P1;

					 up.x = 0;
					 up.y = 1;
					 up.z = 0;

					 center.x = 0;
					 center.y = 0;
					 center.z = 0;

					 alpha = ALPHA;
					 pr_ortho = true;

					 this->Refresh();
				 }

			 }

	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

				 System::Drawing::Rectangle rect = Form::ClientRectangle;
				 float centre_x = rect.Width / 2;
				 float centre_y = rect.Height / 2;

				 Mat3D R1, R2, R3, T1;

				 float pi = 3.1415926535;
				 float alpha_r = alpha * ( pi / 180 ); // угол alpha в радианах

				 float koef = 0.1;
				 float koef2 = 1.1;

				 Point3D o_x, o_z;
				 o_x.x = 1;
				 o_x.y = 0;
				 o_x.z = 0;
				 o_z.x = 0;
				 o_z.y = 0;
				 o_z.z = 1;

				 switch ( e->KeyCode )
				 {

				 case Keys::P : // ортогональна€ / перспективна€ проекци€
					 pr_ortho = !pr_ortho;
					 break;

					 // поворот относительно центра сцены
				 case Keys::A : // влево
					 rotate( up, alpha_r, R1 );
					 times( R1, T3D, T1 );
					 set( T1, T3D );
					 break;
			     case Keys::D : // вправо
					 rotate( up, -alpha_r, R1 );
					 times( R1, T3D, T1 );
					 set( T1, T3D );
					 break;

				 case Keys::W : // вверх
					 rotate( o_x, alpha_r, R2 );
					 times( R2, T3D, T1 );
					 set( T1, T3D );
					 break;
				 case Keys::S : // вниз
					 rotate( o_x, -alpha_r, R2 );
					 times( R2, T3D, T1 );
					 set( T1, T3D );
					 break;

				 case Keys::Q : // против часовой
					 rotate( o_z, alpha_r, R3 );
					 times( R3, T3D, T1 );
					 set( T1, T3D );
					 break;
				 case Keys::E : // по часовой
					 rotate( o_z, -alpha_r, R3 );
					 times( R3, T3D, T1 );
					 set( T1, T3D );
					 break;
				 
					 // изменение рассто€ни€ от наблюдател€ до окна наблюдени€
				 case Keys::Z : // увеличение
					 near += koef;
					 break;
				 case Keys::X : // уменьшение
					 if ( near >= koef )
						 near -= koef;
					 break;

					 // изменение угла вертикального обзора через окно наблюдени€
				 case Keys::C : // увеличение
					 fovy += koef;
					 break;
				 case Keys::V : // уменьшение
					 fovy -= koef;
					 break;

					 // изменение угла alpha
				 case Keys::O : // увеличение
					 alpha *= koef2;
					 break;
				 case Keys::L : // уменьшение
					 alpha *= 1.0 / koef2;
					 break;

					 // приведение к первоначальному виду
				 case Keys::Escape :
					 lookAt( center_start, eye_start, up_start, T3D );
					 near = near_start;
					 fovy = fovy_start;
					 alpha = ALPHA;
					 pr_ortho = true;

				 }

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

			 aspect = w_x / w_y;

			 this->Refresh();

		 }
};
}

