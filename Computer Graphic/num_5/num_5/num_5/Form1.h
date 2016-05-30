#pragma once

#include "function.h"
#include "Clip.h"

namespace num_5 {

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

	private:

		float v_cx, v_cy, v_x, v_y;
		float w_cx, w_cy, w_x, w_y;
		float start_v_cx, start_v_cy, start_v_x, start_v_y;

		float left, right, top, bottom;

		int L;
		int K;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(858, 485);
			this->DoubleBuffered = true;
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

				 left = 20; 
				 right = 12;
				 top = 20;
				 bottom = 12;

				 v_cx = 0;
				 v_cy = 0;
				 v_x = 10;
				 v_y = 10;

				 start_v_cx = v_cx;
				 start_v_x = v_x;
				 start_v_cy = v_cy;
				 start_v_y = v_y;

				 w_cx = left;
				 w_cy = Form::ClientRectangle.Height - bottom;
				 w_x = Form::ClientRectangle.Width - left - right;
				 w_y = Form::ClientRectangle.Height - top - bottom;

				 L = 35;
				 K = 25;

			 }

	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

				 System::Drawing::Graphics^ g = e->Graphics;

				 System::Drawing::Pen^ black_pen = gcnew Pen( Color::Black );
				 black_pen->Width = 2;

				 System::Drawing::Pen^ rect_pen = gcnew Pen( Color::Green );
				 black_pen->Width = 3;

				 System::Drawing::Font^ draw_font = gcnew System::Drawing::Font( "Arial", 5 );
				 SolidBrush^ draw_brush = gcnew SolidBrush( Color::Red );

				 for ( int i = 0; i <= K + 1; i++ )
				 {
					 float y_s = top + i * w_y / (K + 1);
					 g->DrawLine( rect_pen, w_cx, y_s, w_cx + w_x, y_s );

					 float y = v_cy - ( y_s - w_cy ) * v_y / w_y;

					 g->DrawString( Convert::ToString( ( (float) ( (int) (y * 10) ) / 10) ), draw_font, draw_brush, w_cx - 17, y_s - 3 );
				 }

				 for ( int i = 0; i <= L + 1; i++ )
				 {
					 float x_s = left + i * w_x / (L + 1);
					 g->DrawLine( rect_pen, x_s, w_cy, x_s, w_cy - w_y );

					 float x = ( x_s - w_cx ) * v_x / w_x + v_cx;

					 g->DrawString( Convert::ToString( ( (float) ( (int) (x * 10) ) / 10) ), draw_font, draw_brush, x_s - 5, w_cy - w_y - 10 );
				 }

				 TPoint p_min, p_max;
				 p_min.x = left;
				 p_min.y = top;
				 p_max.x = left + w_x;
				 p_max.y = w_cy;

				 float x_s = w_cx;
				 float x = v_cx;
				 float y_ss;
				 float y_s;
				 float y;

				 bool visible1;
				 bool visible2;
				 
				 if ( fexists( x ) )
				 {
					 visible1 = true;
					 y = f( x );
					 y_s = w_cy - ( y - v_cy) * w_y / v_y;
				 }
				 else
					 visible1 = false;

				 while ( x_s < w_cx + w_x )
				 {
					 x = ( x_s + 1 - w_cx ) * v_x / w_x + v_cx;

					 if ( fexists( x ) )
					 {
						 visible2 = true;
						 y = f( x );
						 y_ss = w_cy - ( y - v_cy) * w_y / v_y;
					 }
					 else
						 visible2 = false;

					 if ( visible1 && visible2 )
					 {
						 TLine l;
						 l.start.x = x_s; 
						 l.start.y = y_s; 
						 l.end.x = x_s + 1; 
						 l.end.y = y_ss;
						 
						 if ( clip( l.start, l.end, p_min, p_max ) )
						 {
							 g->DrawLine( black_pen, l.start.x, l.start.y, l.end.x, l.end.y );
						 }
					 }

					 x_s = x_s + 1;
					 y_s = y_ss;
					 visible1 = visible2;
				 }

			 }

	private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {

				 float old_w_x = w_x;
				 float old_w_y = w_y;

				 w_cy = Form::ClientRectangle.Height - bottom;
				 w_x = Form::ClientRectangle.Width - left - right;
				 w_y = Form::ClientRectangle.Height - top - bottom;

				 this->Refresh();

			 }

private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			 System::Drawing::Rectangle rect = Form::ClientRectangle;

			 float coef = 1.1; // коэффициент

			 switch ( e->KeyCode )
			 {
				 // движение
				 case Keys::W : // вверх
					 v_cy -= v_y / w_y;
					 break;
				 case Keys::S : // вниз
					 v_cy += v_y / w_y;
					 break;
				 case Keys::A : // влево
					 v_cx += v_x / w_x;
					 break;
			     case Keys::D : // вправо
					 v_cx -= v_x / w_x;
					 break;

				 // масштабирование относительно осей и центра окна
				 case Keys::O : // вертикаль + увеличение
					 v_cy += ( v_y - v_y / coef ) / 2;
					 v_y /= coef;
					 break;
				 case Keys::I : // вертикаль + уменьшение
					 v_cy += ( v_y - v_y * coef ) / 2;
					 v_y *= coef;
					 break;
				 case Keys::L : // горизонталь + увеличение
					 v_cx += ( v_x - v_x / coef ) / 2;
					 v_x /= coef;
					 break;
				 case Keys::K : // горизонталь + уменьшение
					 v_cx += ( v_x - v_x * coef ) / 2;
					 v_x *= coef;
					 break;

					 // быстрое движение
				 case Keys::T : // вверх
					 v_cy -= v_y * 20 / w_y;
					 break;
				 case Keys::G : // вниз
					 v_cy += v_y * 20 / w_y;
					 break;
				 case Keys::F : // влево
					 v_cx += v_x * 20 / w_x;
					 break;
			     case Keys::H : // вправо
					 v_cx -= v_x * 20 / w_x;
					 break;

					 // изменение кол-ва линий
				 case Keys::Q : // вертикальные + уменьшение
					 L--;
					 break;
				 case Keys::E : // вертикальные + увеличение
					 L++;
					 break;
				 case Keys::Z : // горизонтальные + уменьшение
					 K--;
					 break;
				 case Keys::C : // горизонтальные + увеличение
					 K++;
					 break;

					 // приведение к первоначальному виду
				 case Keys::Escape :
					 v_cx = start_v_cx;
					 v_x = start_v_x;
					 v_cy = start_v_cy;
					 v_y = start_v_y;
					 break;

			 }

			 this->Refresh();

		 }
};

}

