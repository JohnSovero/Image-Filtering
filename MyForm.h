#pragma once
#include "Controladora.h"
namespace FiltradoImagenes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			g = CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			bf = espacio->Allocate(g, ClientRectangle);
			objC = new Controladora();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete bf, espacio, g, objC;
		}

	protected:



	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		Graphics^ g;
		BufferedGraphicsContext^ espacio;
		BufferedGraphics^ bf;
		Controladora* objC;
		Bitmap^ imagen;
		Bitmap^ imagenFiltrada;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ BtnMediana;





	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ BtnSobel;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ BtmSeleccionarImagen;


	private: System::Windows::Forms::PictureBox^ PicmostrarImagen;
	private: System::Windows::Forms::OpenFileDialog^ OfdSeleccionarImagen;
	private: System::Windows::Forms::PictureBox^ PicImagenFiltrada;
	private: System::Windows::Forms::Timer^ TimerImagen;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Button^ BtmGuardarImagen;


	private: System::Windows::Forms::Button^ BtnMedia;









#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->BtnMediana = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->BtnSobel = (gcnew System::Windows::Forms::Button());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->BtmSeleccionarImagen = (gcnew System::Windows::Forms::Button());
			   this->PicmostrarImagen = (gcnew System::Windows::Forms::PictureBox());
			   this->OfdSeleccionarImagen = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->BtnMedia = (gcnew System::Windows::Forms::Button());
			   this->PicImagenFiltrada = (gcnew System::Windows::Forms::PictureBox());
			   this->TimerImagen = (gcnew System::Windows::Forms::Timer(this->components));
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			   this->BtmGuardarImagen = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicmostrarImagen))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicImagenFiltrada))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(370, 23);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(141, 27);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Aplicar Filtro";
			   this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			   // 
			   // BtnMediana
			   // 
			   this->BtnMediana->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnMediana->Location = System::Drawing::Point(387, 179);
			   this->BtnMediana->Name = L"BtnMediana";
			   this->BtnMediana->Size = System::Drawing::Size(105, 53);
			   this->BtnMediana->TabIndex = 2;
			   this->BtnMediana->Text = L"Mediana";
			   this->BtnMediana->UseVisualStyleBackColor = true;
			   this->BtnMediana->Click += gcnew System::EventHandler(this, &MyForm::BtnMediana_Click);
			   // 
			   // button3
			   // 
			   this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button3->Location = System::Drawing::Point(387, 288);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(105, 58);
			   this->button3->TabIndex = 7;
			   this->button3->Text = L"Laplace";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			   // 
			   // BtnSobel
			   // 
			   this->BtnSobel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnSobel->Location = System::Drawing::Point(387, 418);
			   this->BtnSobel->Name = L"BtnSobel";
			   this->BtnSobel->Size = System::Drawing::Size(105, 54);
			   this->BtnSobel->TabIndex = 8;
			   this->BtnSobel->Text = L"Sobel";
			   this->BtnSobel->UseVisualStyleBackColor = true;
			   this->BtnSobel->Click += gcnew System::EventHandler(this, &MyForm::BtnSobel_Click);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(711, 23);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(163, 27);
			   this->label4->TabIndex = 9;
			   this->label4->Text = L"Imagen Filtrada";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(134, 23);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(83, 27);
			   this->label5->TabIndex = 10;
			   this->label5->Text = L"Imagen";
			   this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			   // 
			   // BtmSeleccionarImagen
			   // 
			   this->BtmSeleccionarImagen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->BtmSeleccionarImagen->Location = System::Drawing::Point(87, 82);
			   this->BtmSeleccionarImagen->Name = L"BtmSeleccionarImagen";
			   this->BtmSeleccionarImagen->Size = System::Drawing::Size(184, 36);
			   this->BtmSeleccionarImagen->TabIndex = 11;
			   this->BtmSeleccionarImagen->Text = L"Seleccionar Imagen";
			   this->BtmSeleccionarImagen->UseVisualStyleBackColor = true;
			   this->BtmSeleccionarImagen->Click += gcnew System::EventHandler(this, &MyForm::BtmSeleccionarImagen_Click);
			   // 
			   // PicmostrarImagen
			   // 
			   this->PicmostrarImagen->BackColor = System::Drawing::SystemColors::Control;
			   this->PicmostrarImagen->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->PicmostrarImagen->Cursor = System::Windows::Forms::Cursors::SizeAll;
			   this->PicmostrarImagen->Location = System::Drawing::Point(37, 152);
			   this->PicmostrarImagen->Name = L"PicmostrarImagen";
			   this->PicmostrarImagen->Size = System::Drawing::Size(288, 277);
			   this->PicmostrarImagen->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->PicmostrarImagen->TabIndex = 12;
			   this->PicmostrarImagen->TabStop = false;
			   this->PicmostrarImagen->Click += gcnew System::EventHandler(this, &MyForm::PicmostrarImagen_Click);
			   // 
			   // OfdSeleccionarImagen
			   // 
			   this->OfdSeleccionarImagen->Filter = L"Archivos de mapas de bits|*.PNG|JPEG|*.JPG";
			   this->OfdSeleccionarImagen->Title = L"Seleccionar Imagen";
			   this->OfdSeleccionarImagen->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			   // 
			   // BtnMedia
			   // 
			   this->BtnMedia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtnMedia->Location = System::Drawing::Point(387, 74);
			   this->BtnMedia->Name = L"BtnMedia";
			   this->BtnMedia->Size = System::Drawing::Size(105, 51);
			   this->BtnMedia->TabIndex = 13;
			   this->BtnMedia->Text = L"Media";
			   this->BtnMedia->UseVisualStyleBackColor = true;
			   this->BtnMedia->Click += gcnew System::EventHandler(this, &MyForm::BtnMedia_Click);
			   // 
			   // PicImagenFiltrada
			   // 
			   this->PicImagenFiltrada->Location = System::Drawing::Point(565, 74);
			   this->PicImagenFiltrada->Name = L"PicImagenFiltrada";
			   this->PicImagenFiltrada->Size = System::Drawing::Size(457, 398);
			   this->PicImagenFiltrada->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->PicImagenFiltrada->TabIndex = 14;
			   this->PicImagenFiltrada->TabStop = false;
			   // 
			   // TimerImagen
			   // 
			   this->TimerImagen->Enabled = true;
			   this->TimerImagen->Tick += gcnew System::EventHandler(this, &MyForm::TimerImagen_Tick);
			   // 
			   // saveFileDialog1
			   // 
			   this->saveFileDialog1->Filter = L"Archivos de mapas de bits|*.PNG|JPEG|*.JPG";
			   // 
			   // BtmGuardarImagen
			   // 
			   this->BtmGuardarImagen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BtmGuardarImagen->Location = System::Drawing::Point(682, 499);
			   this->BtmGuardarImagen->Name = L"BtmGuardarImagen";
			   this->BtmGuardarImagen->Size = System::Drawing::Size(227, 31);
			   this->BtmGuardarImagen->TabIndex = 15;
			   this->BtmGuardarImagen->Text = L"Guardar Imagen Filtrada";
			   this->BtmGuardarImagen->UseVisualStyleBackColor = true;
			   this->BtmGuardarImagen->Click += gcnew System::EventHandler(this, &MyForm::BtmGuardarImagen_Click);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1052, 561);
			   this->Controls->Add(this->BtmGuardarImagen);
			   this->Controls->Add(this->PicImagenFiltrada);
			   this->Controls->Add(this->BtnMedia);
			   this->Controls->Add(this->PicmostrarImagen);
			   this->Controls->Add(this->BtmSeleccionarImagen);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->BtnSobel);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->BtnMediana);
			   this->Controls->Add(this->label1);
			   this->Name = L"MyForm";
			   this->Text = L"Filtrado de imágenes";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicmostrarImagen))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicImagenFiltrada))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	private: System::Void BtmSeleccionarImagen_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (OfdSeleccionarImagen->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			imagen = gcnew Bitmap(OfdSeleccionarImagen->FileName);			
			imagenFiltrada = objC->FiltrarImagen(bf->Graphics, imagen);
			objC->convertToMatrix(imagenFiltrada);
			PicmostrarImagen->Image = imagenFiltrada;
		}
	}
	private: System::Void PicmostrarImagen_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

}
	private: System::Void BtnMediana_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		PicImagenFiltrada->Image = objC->convertToPixels(objC->filtroMediana(imagenFiltrada, 3), imagenFiltrada);
	}
	private: System::Void BtnMedia_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		int mascara9[] = {
		1, 1, 1,
		1, 1, 1,
		1, 1, 1
		};
		PicImagenFiltrada->Image = objC->convertToPixels(objC->filtroMedia(imagenFiltrada, mascara9, 9), imagenFiltrada);;
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		int laplaciano1[] = {
		0,  1,  0,
		1, -4,  1,
		0,  1,  0
		};
		int laplaciano2[] = {
		1,  1,  1,
		1, -8,  1,
		1,  1,  1
		};
		int laplaciano3[] = {
		-1, -1, -1,
		-1,  8, -1,
		-1, -1, -1
		};
		PicImagenFiltrada->Image = objC->convertToPixels(objC->filtroLaplaciano(imagenFiltrada, laplaciano1), imagenFiltrada);;
	}
	private: System::Void BtnSobel_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		int sobel1[] = {
		-1, -2, -1,
		 0,  0,  0,
		 1,  2,  1
		};
		PicImagenFiltrada->Image = objC->convertToPixels(objC->filtroSobel(imagenFiltrada, sobel1), imagenFiltrada);;
	}
private: System::Void timer1_Tick_1(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void TimerImagen_Tick(System::Object^ sender, System::EventArgs^ e) {
	bf->Graphics->Clear(Color::Black);
	bf->Render(g);
}
private: System::Void BtmGuardarImagen_Click(System::Object^ sender, System::EventArgs^ e) {
	//-------Boton Guardar---------
	//Abre el buscador de archivos de windows
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//Guardar el archivo en el formato PNG
		imagenFiltrada->Save(saveFileDialog1->FileName, System::Drawing::Imaging::ImageFormat::Jpeg);
	}
}
};
}
