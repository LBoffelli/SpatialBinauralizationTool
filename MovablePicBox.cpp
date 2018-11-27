#include "MovablePicBox.h"



MovablePicBox::MovablePicBox()
{
	coordinates = Point(171, 172);
	z = 0;
	offset = 0;
	Size = Drawing::Size(10, 10);
	SizeMode = PictureBoxSizeMode::StretchImage;
	Image = System::Drawing::Image::FromFile(
		".\\ImageProg\\Sorgente.png");
	Location = coordinates;
	//Text = System::IO::Path::GetFileName(audioFilePath[listaFile->SelectedIndex]);
}


MovablePicBox::~MovablePicBox()
{
}

void MovablePicBox::OnMouseDown(MouseEventArgs^ e){
	coordinates = e->Location;
}

void MovablePicBox::OnMouseMove(MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		this->Left += e->X - coordinates.X;
		this->Top += e->Y - coordinates.Y;
	}
}
