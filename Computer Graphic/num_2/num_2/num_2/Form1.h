#pragma once

namespace num_2 {

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
			this->ClientSize = System::Drawing::Size(557, 473);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				
				 Graphics^ g = e->Graphics;
				 g->Clear(Color::White);
				 Rectangle rect = Form::ClientRectangle;

				 Pen^ blue_pen = gcnew Pen(Color::Blue);
				 blue_pen->Width = 4;

				 Pen^ red_pen = gcnew Pen(Color::Red);
				 red_pen->Width = 4;

				 Pen^ yellow_pen = gcnew Pen(Color::Yellow);
				 yellow_pen->Width = 4;

				 Pen^ green_pen = gcnew Pen(Color::Green);
				 green_pen->Width = 4;

				 Pen^ black_pen = gcnew Pen(Color::Black);
				 black_pen->Width = 4;

				 // head
				 g->DrawLine( blue_pen, 40, 40, 60, 20 );
				 g->DrawLine( blue_pen, 60, 20, 80, 20 );
				 g->DrawLine( blue_pen, 80, 20, 100, 40 );
				 g->DrawLine( blue_pen, 100, 40, 80, 100 );
				 g->DrawLine( blue_pen, 80, 100, 80, 160 );
				 g->DrawLine( blue_pen, 80, 160, 140, 160 );
				 g->DrawLine( blue_pen, 140, 160, 140, 100 );
				 g->DrawLine( blue_pen, 140, 100, 120, 40 );
				 g->DrawLine( blue_pen, 120, 40, 140, 20 );
				 g->DrawLine( blue_pen, 140, 20, 160, 20 );
				 g->DrawLine( blue_pen, 160, 20, 180, 40 );
				 g->DrawLine( blue_pen, 180, 40, 180, 100 );
				 g->DrawLine( blue_pen, 180, 100, 160, 160 );
				 g->DrawLine( blue_pen, 160, 160, 180, 220 );
				 g->DrawLine( blue_pen, 180, 220, 160, 280 );
				 g->DrawLine( blue_pen, 160, 280, 120, 300 );
				 g->DrawLine( blue_pen, 120, 300, 100, 300 );
				 g->DrawLine( blue_pen, 100, 300, 60, 280 );
				 g->DrawLine( blue_pen, 60, 280, 40, 220 );
				 g->DrawLine( blue_pen, 40, 220, 60, 160 );
				 g->DrawLine( blue_pen, 60, 160, 40, 100 );
				 g->DrawLine( blue_pen, 40, 100, 40, 40 );

				 // body
				 g->DrawLine( red_pen, 180, 220, 240, 200 );
				 g->DrawLine( red_pen, 240, 200, 300, 200 );
				 g->DrawLine( red_pen, 300, 200, 320, 240 );
				 g->DrawLine( red_pen, 320, 240, 340, 240 );
				 g->DrawLine( red_pen, 340, 240, 340, 260 );
				 g->DrawLine( red_pen, 340, 260, 320, 260 );
				 g->DrawLine( red_pen, 320, 260, 320, 320 );
				 g->DrawLine( red_pen, 320, 320, 280, 320 );
				 g->DrawLine( red_pen, 280, 320, 280, 300 );
				 g->DrawLine( red_pen, 280, 300, 260, 300 );
				 g->DrawLine( red_pen, 260, 300, 260, 320 );
				 g->DrawLine( red_pen, 260, 320, 220, 320 );
				 g->DrawLine( red_pen, 220, 320, 220, 300 );
				 g->DrawLine( red_pen, 220, 300, 180, 300 );
				 g->DrawLine( red_pen, 180, 300, 180, 320 );
				 g->DrawLine( red_pen, 180, 320, 140, 320 );
				 g->DrawLine( red_pen, 140, 320, 140, 300 );
				 g->DrawLine( red_pen, 140, 300, 120, 300 );
				 g->DrawLine( red_pen, 120, 300, 120, 320 );
				 g->DrawLine( red_pen, 120, 320, 80, 320 );
				 g->DrawLine( red_pen, 80, 320, 80, 290 );

				 // ears
				 g->DrawLine( yellow_pen, 60, 60, 60, 120 );
				 g->DrawLine( yellow_pen, 160, 60, 160, 120 );
				 
				 // eyes
				 g->DrawLine( green_pen, 80, 200, 100, 200 );
				 g->DrawLine( green_pen, 100, 200, 100, 220 );
				 g->DrawLine( green_pen, 100, 220, 80, 220 );
				 g->DrawLine( green_pen, 80, 220, 80, 200 );

				 g->DrawLine( green_pen, 120, 200, 140, 200 );
				 g->DrawLine( green_pen, 140, 200, 140, 220 );
				 g->DrawLine( green_pen, 140, 220, 120, 220 );
				 g->DrawLine( green_pen, 120, 220, 120, 200 );

				 // mouth
				 g->DrawLine( black_pen, 100, 240, 120, 240 );
				 g->DrawLine( black_pen, 120, 240, 110, 260 );
				 g->DrawLine( black_pen, 110, 260, 100, 240 );

			 }
	};
}

