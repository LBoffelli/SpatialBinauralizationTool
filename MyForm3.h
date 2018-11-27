#pragma once
#include "stdio.h"
#include <sndfile.h>
#include "MovablePicBox.h"
#include "SorgenteAudio.h"
#include "offsetCalc.h"
#include "convolute.h"
#include "normalize.h"

#define BUFFER_LEN 1024
#define MAX_CHANNELS 2



namespace Progetto1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Riepilogo per MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}

	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:

	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Collections::Generic::List<MovablePicBox^>^ sorg = gcnew System::Collections::Generic::List<MovablePicBox^>();
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton5;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton6;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton7;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton8;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton9;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolTip toolTip1;
	private: System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer();
	private: bool bCancelEdit;
	private: ListViewItem::ListViewSubItem^ curSI;
	private: ListViewItem^ curItem;
	private: String^ folderName;
	private: bool scaleCm;

	private:
		/// <summary>
		/// Variabile di progettazione necessaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metodo necessario per il supporto della finestra di progettazione. Non modificare
		/// il contenuto del metodo con l'editor di codice.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton8 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton9 = (gcnew System::Windows::Forms::ToolStripButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel1->BackgroundImage = Image::FromFile(".\\ImageProg\\Immagine.png");
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			//this->panel1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->panel1->Location = System::Drawing::Point(37, 51);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(357, 355);
			this->panel1->TabIndex = 10;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseHover);
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->toolStripButton1,
				this->toolStripButton2,
				this->toolStripButton3,
				this->toolStripButton4,
				this->toolStripButton5,
				this->toolStripButton6,
				this->toolStripButton7,
				this->toolStripButton8,
				this->toolStripButton9
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1050, 50);
			this->toolStrip1->TabIndex = 11;
			this->toolStrip1->Text = L"toolStrip1";
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(30, 30);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->toolStripButton1->Image = Image::FromFile(
				".\\ImageProg\\AddFile.png");
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(230, 220);
			this->toolStripButton1->Text = L"Aggiungi File";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = Image::FromFile(
				".\\ImageProg\\RemoveFile.png");
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(230, 220);
			this->toolStripButton2->Text = L"Elimina File";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = Image::FromFile(
				".\\ImageProg\\Render.png");
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(230, 220);
			this->toolStripButton3->Text = L"Render";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = Image::FromFile(
				".\\ImageProg\\Play.png");
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(230, 220);
			this->toolStripButton4->Text = L"Play";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton5->Image = Image::FromFile(
				".\\ImageProg\\Settings.png");
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(230, 220);
			this->toolStripButton5->Text = L"Opzioni";
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton5_Click);
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton6->Image = Image::FromFile(
				".\\ImageProg\\Righello.png");
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(230, 220);
			this->toolStripButton6->Text = L"Regolazione Distanza";
			this->toolStripButton6->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton6_Click);
			// 
			// toolStripButton7
			// 
			this->toolStripButton7->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton7->Image = Image::FromFile(
				".\\ImageProg\\SaveFile.png");
			this->toolStripButton7->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton7->Name = L"toolStripButton7";
			this->toolStripButton7->Size = System::Drawing::Size(230, 220);
			this->toolStripButton7->Text = L"Salva Progetto";
			this->toolStripButton7->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton7_Click);
			// 
			// toolStripButton8
			// 
			this->toolStripButton8->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton8->Image = Image::FromFile(
				".\\ImageProg\\OpenFile.png");
			this->toolStripButton8->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton8->Name = L"toolStripButton8";
			this->toolStripButton8->Size = System::Drawing::Size(230, 220);
			this->toolStripButton8->Text = L"Apri Progetto";
			this->toolStripButton8->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton8_Click);
			// 
			// toolStripButton9
			// 
			this->toolStripButton9->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton9->Image = Image::FromFile(
				".\\ImageProg\\NewFile.png");
			this->toolStripButton9->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton9->Name = L"toolStripButton9";
			this->toolStripButton9->Size = System::Drawing::Size(230, 220);
			this->toolStripButton9->Text = L"Nuovo Progetto";
			this->toolStripButton9->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton9_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(632, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 29);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Render";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listView1
			// 
			this->listView1->Columns->Add(gcnew ColumnHeader);
			this->listView1->Columns[0]->Text = "Nome File";
			this->listView1->Columns->Add(gcnew ColumnHeader);
			this->listView1->Columns[1]->Text = "Offset";
			this->listView1->Columns->Add(gcnew ColumnHeader);
			this->listView1->Columns[2]->Text = "Asse X";
			this->listView1->Columns->Add(gcnew ColumnHeader);
			this->listView1->Columns[3]->Text = "Asse Y";
			this->listView1->Columns->Add(gcnew ColumnHeader);
			this->listView1->Columns[4]->Text = "Asse Z";
			this->listView1->Columns->Add(gcnew ColumnHeader);
			this->listView1->Columns[5]->Text = "Percorso";
			this->listView1->FullRowSelect = true;
			this->listView1->MultiSelect = false;
			this->listView1->GridLines = true;
			this->listView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listView1->LabelWrap = false;
			this->listView1->Location = System::Drawing::Point(432, 51);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(606, 355);
			this->listView1->TabIndex = 14;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::listView1_MouseDoubleClick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(601, 51);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Visible = false;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyDown);
			this->textBox1->LostFocus += gcnew System::EventHandler(this, &MyForm::textBox1_LostFocus);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(738, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(70, 29);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Play";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1050, 447);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseHover);
			//this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listView1);
			//this->Controls->Add(this->button1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"Binaural Convolution";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Closing += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::MyForm_FormClosing);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		if (!(System::IO::Directory::Exists("./files"))) {
			System::IO::Directory::CreateDirectory("./files");
		}
		folderName = "./files";
		scaleCm = true;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//Creazione e popolamento array per mix e convoluzione
		array<SorgenteAudio^>^ fileAudio = gcnew array<SorgenteAudio^>(listView1->Items->Count);
		for (int i = 0; i < listView1->Items->Count; i++) {
			fileAudio[i] = gcnew SorgenteAudio();
			const char* infilepath = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(listView1->Items[i]->SubItems[5]->Text)).ToPointer();
			fileAudio[i]->offset = Double::Parse(listView1->Items[i]->SubItems[1]->Text);
			fileAudio[i]->x = Double::Parse(listView1->Items[i]->SubItems[2]->Text);
			fileAudio[i]->y = Double::Parse(listView1->Items[i]->SubItems[3]->Text);
			fileAudio[i]->z = Double::Parse(listView1->Items[i]->SubItems[4]->Text);
			Diagnostics::Trace::WriteLine(gcnew String(infilepath));
			if (!(fileAudio[i]->audioFile = sf_open(infilepath, SFM_READ, fileAudio[i]->audioInfo))) {
				MessageBox::Show(String::Concat("Impossibile aprire il file ", listView1->Items[i]->SubItems[0]->Text), "Errore");
				return;
			}
			if (fileAudio[i]->audioInfo->channels != 2 || fileAudio[i]->audioInfo->samplerate != 44100) {
				MessageBox::Show("Utilizzare file WAV Stereo con Frequenza di Campionamento 44.1 kHz", "Errore");
				return;
			}
			//Stampo su console info del file aperto
			Diagnostics::Trace::WriteLine(System::String::Concat("Frames: ", fileAudio[i]->audioInfo->frames));
			Diagnostics::Trace::WriteLine(System::String::Concat("Channels: ", fileAudio[i]->audioInfo->channels));
			Diagnostics::Trace::WriteLine(System::String::Concat("SR: ", fileAudio[i]->audioInfo->samplerate));
			Diagnostics::Trace::WriteLine(System::String::Concat("X: ", fileAudio[i]->x));
			Diagnostics::Trace::WriteLine(System::String::Concat("Y: ", fileAudio[i]->y));
			Diagnostics::Trace::WriteLine(System::String::Concat("Z: ", fileAudio[i]->z));
			Diagnostics::Trace::WriteLine(System::String::Concat("Offset: ", fileAudio[i]->offset, " secondi"));

			//Conversione coordinate cartesiane a sferiche
			fileAudio[i]->azimuth = fileAudio[i]->calcAzimuth(fileAudio[i]->x, fileAudio[i]->y);
			fileAudio[i]->elevation = fileAudio[i]->calcElevation(fileAudio[i]->x, fileAudio[i]->y, fileAudio[i]->z);
			fileAudio[i]->radius = fileAudio[i]->calcRadius(fileAudio[i]->x, fileAudio[i]->y, fileAudio[i]->z);
			if (scaleCm)
				fileAudio[i]->radius = fileAudio[i]->radius / 4;
			else
				fileAudio[i]->radius = fileAudio[i]->radius * 8;
			if (fileAudio[i]->radius < 1)
				fileAudio[i]->radius = 1;
			Diagnostics::Trace::WriteLine(String::Concat("Azimuth: ", fileAudio[i]->azimuth, " Elevation: ", fileAudio[i]->elevation, " Radius: ", fileAudio[i]->radius));
			//Scelta IIR
			int j = 0;
			int elev40[57] = { 0, 6, 13, 19, 26, 32, 39, 45, 51, 58, 64, 71, 77, 84, 90, 96, 103, 109, 116, 122, 129, 135, 141, 148, 154, 161, 167, 174, 180, 186, 193, 199, 206, 212, 219, 225, 231, 238, 244, 251, 257, 264, 270, 276, 283, 289, 296, 302, 309, 315, 321, 328, 334, 341, 347, 354, 360 };
			int el = round((float)fileAudio[i]->elevation / 10) * 10;
			if (el < -40)
				el = -40;
			int az;
			switch (el) {
			case 30:
			case -30:
				az = round((float)fileAudio[i]->azimuth / 6) * 6;
				break;
			case 40:
			case -40:
				if (fileAudio[i]->azimuth == 360)
					fileAudio[i]->azimuth = 0;
				while (elev40[j] < fileAudio[i]->azimuth)
					j++;
				if (fileAudio[i]->azimuth - elev40[j] > elev40[j + 1] - fileAudio[i]->azimuth)
					az = elev40[j + 1];
				else
					az = elev40[j];
				break;
			case 50:
				az = round((float)fileAudio[i]->azimuth / 8) * 8;
				break;
			case 60:
				az = round((float)fileAudio[i]->azimuth / 10) * 10;
				break;
			case 70:
				az = round((float)fileAudio[i]->azimuth / 15) * 15;
				break;
			case 80:
				az = round((float)fileAudio[i]->azimuth / 30) * 30;
				break;
			case 90:
				az = 0;
				break;
			default:
				az = round((float)fileAudio[i]->azimuth / 5) * 5;
			}
			if (az == 360)
				az = 0;
			//MessageBox::Show(String::Concat(Convert::ToString(el)," da ",fileAudio[i]->elevation," - ", Convert::ToString(az), " da ", fileAudio[i]->azimuth), "Elevation and Azimuth");
			//Creazione iir filepath
			String^ iirName;
			iirName = el + "e" + "0" + "0" + az + "a";
			if (az > 9)
				iirName = el + "e" + "0" + az + "a";
			if (az > 99)
				iirName = el + "e" + az + "a";
			iirName = "./compact/H" + iirName + ".wav";
			//MessageBox::Show(iirName);
			const char* iirfilepath = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(iirName)).ToPointer();
			SNDFILE* iir;
			SF_INFO iirInfo;
			if (!(iir = sf_open(iirfilepath, SFM_READ, &iirInfo))) {
				MessageBox::Show(gcnew String(sf_strerror(iir)), "Errore");
				return;
			}
			//Convoluzione audio
			convolute(fileAudio[i]->audioFile, iir, fileAudio[i]->audioInfo, &iirInfo, i);
			String^ convpath = "./files/convFile" + i + ".wav";
			const char* convp = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(convpath)).ToPointer();
			sf_close(fileAudio[i]->audioFile);
			if (!(fileAudio[i]->audioFile = sf_open(convp, SFM_READ, fileAudio[i]->audioInfo))) {
				MessageBox::Show("Funzione convoluzione fallita", "Errore");
				return;
			}

			//Conversione offset da secondi (USER) a frames
			if (fileAudio[i]->offset) {
				fileAudio[i]->offset = fileAudio[i]->offset * 44100;
				Diagnostics::Trace::WriteLine(System::String::Concat("Offset: ", fileAudio[i]->offset, " frames"));
				//Creazione file offset
				offsetCalc(fileAudio[i]->audioFile, fileAudio[i]->audioInfo, fileAudio[i]->offset, i);
				sf_close(fileAudio[i]->audioFile);
				String^ offpath = "./files/offFile" + i + ".wav";
				const char* offp = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(offpath)).ToPointer();
				if (!(fileAudio[i]->audioFile = sf_open(offp, SFM_READ, fileAudio[i]->audioInfo))) {
					MessageBox::Show("Funzione offset fallita", "Errore");
					return;
				}
			}
		}
		if (fileAudio->Length > 0) {
			//Scansione file più lungo per creare vettore di output
			int maxLen = 0;
			for each (SorgenteAudio^ srg in fileAudio) {
				if (srg->audioInfo->frames > maxLen)
					maxLen = srg->audioInfo->frames;
			}
			Diagnostics::Trace::WriteLine(System::String::Concat("MaxLen: ", maxLen));
			int outCount = 0;
			String^ outfilenamestr = folderName + "/output.wav";
			const char* outfilename = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(outfilenamestr)).ToPointer();
			//MessageBox::Show(gcnew String(outfilename));
			SNDFILE *outFile = nullptr;
			if (!(outFile = sf_open(outfilename, SFM_WRITE, fileAudio[fileAudio->Length - 1]->audioInfo))) {
				MessageBox::Show(gcnew String(sf_strerror(outFile)), "Errore apertura file output.");
				return;
			}
			static double outData[BUFFER_LEN * 2];
			static double indata[100][BUFFER_LEN * 2]; //come mettere numero giusto e non 10?
			static double ampCoeff[100];
			double maxVal = 0;
			for (int i = 0; i < fileAudio->Length; i++)
				ampCoeff[i] = 1 / (log10(fileAudio[i]->radius) + 1);
			//Mix delle diverse sorgenti
			while (outCount < maxLen) {
				for (int i = 0; i < BUFFER_LEN * 2; i++)
					outData[i] = 0;
				for (int i = 0; i < fileAudio->Length; i++) {
					fileAudio[i]->readcount = sf_readf_double(fileAudio[i]->audioFile, indata[i], BUFFER_LEN);
				}
				for (int i = 0; i < fileAudio->Length; i++) {
					for (int j = 0; j < BUFFER_LEN * 2; j++) {
						outData[j] = (ampCoeff[i] * indata[i][j] + outData[j])/10;
					}
				}
				for (int j = 0; j < BUFFER_LEN * 2; j++)
					if (abs(outData[j]) > maxVal)
						maxVal = abs(outData[j]);
				sf_writef_double(outFile, outData, BUFFER_LEN);
				outCount += BUFFER_LEN;
			}
			sf_close(outFile);
			//MessageBox::Show(Convert::ToString(maxVal), "Campione massimo");
			for each (SorgenteAudio^ srg in fileAudio)
				sf_close(srg->audioFile);
			//Normalizzazione
			SNDFILE* outPre;
			SF_INFO preInfo;
			if (!(outPre = sf_open(outfilename, SFM_READ, &preInfo))) {
				MessageBox::Show(gcnew String(sf_strerror(outPre)), "Errore normalizzazione");
				return;
			}
			normalize(outPre, &preInfo, maxVal, folderName);
			sf_close(outPre);
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (System::IO::File::Exists(folderName + "/output.wav")) {
			/*if (MessageBox::Show("Vuoi effettuare il controllo anti-clipping?", "Normalizzazione", MessageBoxButtons::YesNo) == ::DialogResult::Yes){
				//Metto output file in sndfile
				const char* outfilepath = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(folderName + "/output.wav")).ToPointer();
				SNDFILE* out;
				SF_INFO outInfo;

				double *indata = new double[outInfo.frames * 2];
				if (!(out = sf_open(outfilepath, SFM_RDWR, &outInfo))) {
					MessageBox::Show(gcnew String(sf_strerror(out)), "Errore");
					return;
				}

				//Leggo il file di output come vettore e trovo il valore più alto
				sf_seek(out, 0, SEEK_SET);
				sf_read_double(out, indata, outInfo.frames * 2);
				double maxVal = 0;
				for (int i = 0; i < outInfo.frames * 2; i++) {
					if (abs(indata[i]) > maxVal)
						maxVal = abs(indata[i]);
				}
				//MessageBox::Show(Convert::ToString(maxVal), "Sample massimo");
				//Normalizzo il file (anti-clipping)
				if (maxVal > 1) {
					sf_seek(out, 0, SEEK_SET);
					for (int i = 0; i < outInfo.frames * 2; i++)
						indata[i] = indata[i] / maxVal;
				}
				sf_write_double(out, indata, outInfo.frames * 2);
				sf_close(out);
			}*/
				System::IO::Stream^ fs = System::IO::File::OpenRead(folderName + "/outputN.wav");
				player->Stream = fs;
				player->PlaySync();
				delete fs;
		}
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
	private: System::Void panel1_MouseHover(System::Object^  sender, System::Windows::Forms::MouseEventArgs^ e) {
		for (int i = 0; i < sorg->Count; i++) {
			if(Int32::Parse(listView1->Items[i]->SubItems[2]->Text) != sorg[i]->Left - 171)
				listView1->Items[i]->SubItems[2]->Text = Convert::ToString(sorg[i]->Left - 171);
			if (Int32::Parse(listView1->Items[i]->SubItems[3]->Text) != 172 - sorg[i]->Top)
				listView1->Items[i]->SubItems[3]->Text = Convert::ToString(172 - sorg[i]->Top);
		}
	}
	//Al doppio clic sul valore desiderato dà accesso alla modifica o al play del singolo file
	private: System::Void listView1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^ e) {
		curItem = listView1->GetItemAt(e->X, e->Y);
		curSI = curItem->GetSubItemAt(e->X, e->Y);
		int indexSI = curItem->SubItems->IndexOf(curSI);
		if (indexSI == 0) {
			System::IO::Stream^ fs = System::IO::File::OpenRead(curItem->SubItems[5]->Text);
			player->Stream = fs;
			player->PlaySync();
			delete fs;
			return;
		}
		if (indexSI != 1 && indexSI != 4)
			return;
		int lLeft = curSI->Bounds.Left + 2;
		int lWidth = curSI->Bounds.Width;
		textBox1->SetBounds(lLeft + listView1->Left, curSI->Bounds.Top + listView1->Top, lWidth, curSI->Bounds.Height);
		textBox1->Text = curSI->Text;
		textBox1->Show();
		textBox1->Focus();
		bCancelEdit = true;
	}
	//Controlla se l'utente vuole cambiare o no il valore
	private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			bCancelEdit = false;
			e->Handled = true;
			textBox1->Hide();
		}
		if (e->KeyCode == Keys::Escape) {
			bCancelEdit = true;
			e->Handled = true;
			textBox1->Hide();
		}
	}
	//Se l'utente ha premuto invio e la stringa non è vuota e contiene numeri la inserisco come valore
	private: System::Void textBox1_LostFocus(System::Object^  sender, System::EventArgs^  e) {
		textBox1->Hide();
		if (!bCancelEdit && textBox1->Text != "") {
			double parsed = 0;
			if (Double::TryParse(textBox1->Text, parsed)) {
				if (curItem->SubItems->IndexOf(curSI) == 1) {
					if (parsed >= 0) {
						sorg[curItem->Index]->offset = parsed;
						curSI->Text = Convert::ToString(parsed);
					}
				}
				else {
					sorg[curItem->Index]->z = parsed;
					curSI->Text = Convert::ToString(parsed);
				}
			}
			else
				MessageBox::Show("Inserimento non corretto.", "Errore Inserimento");
		}
		listView1->Focus();
	}
	private:
		void toolStripButton1_Click(System::Object ^ sender,
			System::EventArgs ^ e)
		{
			// Apre un OpenFileDialog
			openFileDialog1->Filter = "Audio File|*.wav";
			openFileDialog1->Title = "Seleziona un file audio";

			// Se il file selezionato è giusto, lo apre  
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				MovablePicBox^ nSorg = gcnew MovablePicBox();
				nSorg->Text = System::IO::Path::GetFileName(openFileDialog1->FileName);
				nSorg->path = openFileDialog1->FileName;
				panel1->Controls->Add(nSorg);
				sorg->Add(nSorg);
				nSorg->BringToFront();
				toolTip1.SetToolTip(nSorg, nSorg->Text);
				array<String^>^ row = {
					nSorg->Text,
					Convert::ToString(nSorg->offset),
					Convert::ToString(nSorg->coordinates.X - 171),
					Convert::ToString(nSorg->coordinates.Y - 172),
					Convert::ToString(nSorg->z),
					nSorg->path };
				listView1->Items->Add(gcnew ListViewItem(row));
			}
		}
private:
	void toolStripButton2_Click(System::Object ^ sender,
		System::EventArgs ^ e) {
		if (listView1->SelectedItems->Count >= 1) {
			String^ name = System::IO::Path::GetFileName(listView1->SelectedItems[0]->SubItems[5]->Text);
			int x = System::Int32::Parse(listView1->SelectedItems[0]->SubItems[2]->Text);
			int y = System::Int32::Parse(listView1->SelectedItems[0]->SubItems[3]->Text);
			int selIndex = listView1->SelectedIndices[0];
			sorg->RemoveAt(selIndex);
			listView1->Items->Remove(listView1->SelectedItems[0]);
			for (int i = 0; i < this->panel1->Controls->Count; i++) {
				Control^ ctrl = this->panel1->Controls[i];
				if (dynamic_cast<PictureBox^>(ctrl) && (ctrl->Text == name && ctrl->Location == Point(171 + x, 172 - y))) {
					panel1->Controls->Remove(ctrl);
					return;
				}
			}
		}
		for each (MovablePicBox^ s in sorg){
			Diagnostics::Trace::WriteLine(s->Text);
		}
	}
private:
	void toolStripButton5_Click(System::Object ^ sender,
		System::EventArgs ^ e) {
		System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();
		folderBrowserDialog1->Description = "Seleziona il percorso di salvataggio del file di output.";
		//folderBrowserDialog1->SelectedPath = "./files/output.wav";
		if (result == ::DialogResult::OK)
			folderName = folderBrowserDialog1->SelectedPath;
		//MessageBox::Show(folderName);
		}
private:
	void toolStripButton6_Click(System::Object ^ sender,
		System::EventArgs ^ e) {
		if (scaleCm) {
			scaleCm = false;
			this->panel1->BackgroundImage = Image::FromFile(".\\ImageProg\\Immagine2.png");
		}
		else {
			scaleCm = true;
			this->panel1->BackgroundImage = Image::FromFile(".\\ImageProg\\Immagine.png");
		}
	}
private:
	void toolStripButton7_Click(System::Object ^ sender, System::EventArgs ^ e) {
		String^ filename = "";
		SaveFileDialog^ sfd = gcnew SaveFileDialog();

		sfd->Title = "Salva Progetto";
		sfd->Filter = "Text File (.txt) | *.txt";

		if (sfd->ShowDialog() == ::DialogResult::OK){
			filename = sfd->FileName->ToString();
			if (filename != ""){
				System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(filename);
				String^ itemInfo;
				for (int i = 0; i < listView1->Items->Count; i++) {
					itemInfo = "";
					Diagnostics::Trace::WriteLine(listView1->Items[i]->SubItems[0]->Text);
					for (int j = 0; j <= 5; j++)
						itemInfo = itemInfo + listView1->Items[i]->SubItems[j]->Text + "|";
					sw->WriteLine(itemInfo);
				}
				sw->Close();
			}
		}
	}
private:
	void toolStripButton8_Click(System::Object ^ sender, System::EventArgs ^ e) {
		if(listView1->Items->Count > 0)
			toolStripButton9_Click(sender, e);
		String^ filename = "";
		OpenFileDialog^ ofd = gcnew OpenFileDialog();

		ofd->Title = "Apri Progetto";
		ofd->Filter = "Text File (.txt) | *.txt";

		if (ofd->ShowDialog() == ::DialogResult::OK && ofd->FileName->ToString() != "") {
			String^ filename = ofd->FileName->ToString();
			int i = 0;
			for each (String^ line in System::IO::File::ReadAllLines(filename)) {
				ListViewItem^ item = gcnew ListViewItem(line->Split('|'));
				listView1->Items->Add(item);
				MovablePicBox^ nSorg = gcnew MovablePicBox();
				nSorg->Text = listView1->Items[i]->SubItems[0]->Text;
				nSorg->path = listView1->Items[i]->SubItems[5]->Text;
				Point coord = Point(Convert::ToInt32(listView1->Items[i]->SubItems[2]->Text)+171, 172-(Convert::ToInt32(listView1->Items[i]->SubItems[3]->Text)));
				nSorg->coordinates = coord;
				nSorg->Location = coord;
				panel1->Controls->Add(nSorg);
				sorg->Add(nSorg);
				nSorg->BringToFront();
				toolTip1.SetToolTip(nSorg, nSorg->Text);
				i++;
			}
		}
	}
private:
	void toolStripButton9_Click(System::Object ^ sender, System::EventArgs ^ e) {
		if (MessageBox::Show("Vuoi salvare il progetto attuale?", "Nuovo Progetto", MessageBoxButtons::YesNo) == ::DialogResult::Yes)
			toolStripButton7_Click(sender, e);
		listView1->Items->Clear();
		sorg->Clear();
		sorg->TrimExcess();
		panel1->Controls->Clear();
	}
private: void MyForm_FormClosing(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		if (MessageBox::Show("Vuoi cancellare i files temporanei?", "Cancellazione File", MessageBoxButtons::YesNo) == ::DialogResult::Yes)
		{
			System::IO::Directory::Delete("./files", true);
			MessageBox::Show("I files temporanei sono stati cancellati.", "Applicazione terminata!", MessageBoxButtons::OK);
		}
		else
		{
			MessageBox::Show("I files temporanei non sono stati cancellati.", "Applicazione terminata!", MessageBoxButtons::OK);
		}
	}
};
}


/*this->toolStripButton1->Image = Image::FromFile(String::Concat(
				System::Environment::GetFolderPath
				(System::Environment::SpecialFolder::Personal),
				"\\ImageProg\\OpenFile.png"));*/
/*this->toolStripButton2->Image = Image::FromFile(String::Concat(
	System::Environment::GetFolderPath
	(System::Environment::SpecialFolder::Personal),
	"\\ImageProg\\RemoveFile.png"));*/
/*this->listView1->Columns->Add(gcnew ColumnHeader);
			this->listView1->Columns[0]->Text = "Nome File";
			this->listView1->Columns->Add(gcnew ColumnHeader);
			this->listView1->Columns[1]->Text = "Inizio";
			this->listView1->Columns->Add(gcnew ColumnHeader);
			this->listView1->Columns[2]->Text = "Asse X";
			this->listView1->Columns->Add(gcnew ColumnHeader);
			this->listView1->Columns[3]->Text = "Asse Y";
			this->listView1->Columns->Add(gcnew ColumnHeader);
			this->listView1->Columns[4]->Text = "Asse z";*/
