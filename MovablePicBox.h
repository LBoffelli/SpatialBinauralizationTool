#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

public ref class MovablePicBox : System::Windows::Forms::PictureBox
{
public:
	Point coordinates;
	double z;
	double offset;
	String^ path;

	MovablePicBox();
	~MovablePicBox();
protected:
	virtual void OnMouseDown(MouseEventArgs^ e) override;
	virtual void OnMouseMove(MouseEventArgs^ e) override;
};

