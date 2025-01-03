#include "CustomControl.h"

Form2::RJButton::RJButton()
{
	this->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->FlatAppearance->BorderSize = 0;
	this->Size = System::Drawing::Size(150, 40);
	this->BackColor = Color::MediumSlateBlue;
	this->ForeColor = Color::White;
	this->Resize += gcnew System::EventHandler(this, &Form2::RJButton::OnResize);

}

GraphicsPath^ Form2::RJButton::GetFigurePath(Rectangle rect, float radius)
{
	GraphicsPath^ path = gcnew GraphicsPath();
	path->StartFigure();
	path->AddArc(static_cast<int>(rect.X), static_cast<int>(rect.Y), static_cast<int>(radius), static_cast<int>(radius), 180.0f, 90.0f);
	path->AddArc(static_cast<int>(rect.Width - radius), static_cast<int>(rect.Y), static_cast<int>(radius), static_cast<int>(radius), 270.0f, 90.0f);
	path->AddArc(static_cast<int>(rect.Width - radius), static_cast<int>(rect.Height - radius), static_cast<int>(radius), static_cast<int>(radius), 0.0f, 90.0f);
	path->AddArc(static_cast<int>(rect.X), static_cast<int>(rect.Height - radius), static_cast<int>(radius), static_cast<int>(radius), 90.0f, 90.0f);
	path->CloseFigure();
	return path;
}
void Form2::RJButton::OnPaint(PaintEventArgs^ pevent)
{
	__super::OnPaint(pevent);
	pevent->Graphics->SmoothingMode = SmoothingMode::AntiAlias;
	RectangleF rectSurface = RectangleF(0, 0, this->Width, this->Height);
	RectangleF rectBorder = RectangleF(1, 1, this->Width - 1, this->Height - 1);

	if (borderRadius > 2) // Rounded button
	{
		GraphicsPath^ pathSurface = GetFigurePath(Rectangle(static_cast<int>(rectSurface.X), static_cast<int>(rectSurface.Y), static_cast<int>(rectSurface.Width), static_cast<int>(rectSurface.Height)), borderRadius);
		GraphicsPath^ pathBorder = GetFigurePath(Rectangle(static_cast<int>(rectBorder.X), static_cast<int>(rectBorder.Y), static_cast<int>(rectBorder.Width), static_cast<int>(rectBorder.Height)), borderRadius - 1);
		Pen^ penSurface = gcnew Pen(this->Parent->BackColor, 2.0f);
		Pen^ penBorder = gcnew Pen(borderColor, borderSize);
		try
		{
			penBorder->Alignment = PenAlignment::Inset;
			this->Region = gcnew System::Drawing::Region(pathSurface);
			//Draw surface border for HD result
			pevent->Graphics->DrawPath(penSurface, pathSurface);
			//Draw control border
			if (borderSize >= 1)
			{
				pevent->Graphics->DrawPath(penBorder, pathBorder);
			}
		}
		finally
		{
			delete penSurface;
			delete penBorder;
			delete pathSurface;
			delete pathBorder;
		}
	}
	else // Normal button
	{
		//Button surface
		this->Region = gcnew System::Drawing::Region(rectSurface);
		//Button border
		if (borderSize >= 1)
		{
			Pen^ penBorder = gcnew Pen(borderColor, borderSize);
			try
			{
				penBorder->Alignment = PenAlignment::Inset;
				pevent->Graphics->DrawRectangle(penBorder, 0, 0, this->Width - 1, this->Height - 1);
			}
			finally
			{
				delete penBorder;
			}
		}
	}
}

void Form2::RJButton::OnHandleCreated(EventArgs^ e)
{
	__super::OnHandleCreated(e);
	this->Parent->BackColorChanged += gcnew EventHandler(this, &RJButton::OnParentBackColorChanged);
}

void Form2::RJButton::OnParentBackColorChanged(Object^ sender, EventArgs^ e)
{
	//can move this if need to change the color at run time
		this->Invalidate();
}

void Form2::RJButton::OnResize(System::Object^ sender, System::EventArgs^ e)
{
	if (borderRadius > this->Height)
		borderRadius = this->Height;
}
