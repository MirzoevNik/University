#pragma once

namespace num_1 {

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
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

				 Graphics^ g = e->Graphics;
				 g->Clear(Color::Aquamarine);
				 Rectangle rect = Form::ClientRectangle;

				 Pen^ redPen = gcnew Pen(Color::Red);
				 redPen->Width = 4;
				 g->DrawLine( redPen, 0, 0, rect.Width, rect.Height );

				 Pen^ bluePen = gcnew Pen(Color::Blue);
				 bluePen->Width = 10;
				 g->DrawLine( bluePen, 50, 70, rect.Width, 80);
				 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial",10 );
				 SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);				 g->DrawString("Надпись на форме", drawFont,drawBrush, 40, 100);
			 }
	private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {

				 this->Refresh();

			 }
	};
}

