#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::ComponentModel;


namespace Form2
{ 
public ref class RJButton: public Button
{
	//Fields
private:
	int	borderSize = 0;
	int borderRadius = 40;
	Color borderColor = Color::PaleVioletRed;
public: Color textColor;
public: Color backgroundColor;

	  //Properties
	  [Category("VIOLETTA ADVANCED")]
		  property int BorderSize
	  {
		  int get()
		  {
			  return borderSize;
		  }
		  void set(int value)
		  {
			  borderSize = value;
			  this->Invalidate();
		  }
	  }
	  [Category("VIOLETTA ADVANCED")]
		  property int BorderRadius
	  {
		  int get()
		  {
			  return borderRadius;
		  }
		  void set(int value)
		  {
			  if (value <= this->Height)
				  borderRadius = value;
			  else
				  borderRadius = this->Height;
			  this->Invalidate();
		  }
	  }
	  [Category("VIOLETTA ADVANCED")]
		  property Color BorderColor
	  {
		  Color get()
		  {
			  return borderColor;
		  }
		  void set(Color value)
		  {
			  borderColor = value;
			  this->Invalidate();
		  }
	  }
	  [Category("VIOLETTA ADVANCED")]
		  property Color BackgroundColor
	  {
		  Color get()
		  {
			  return this->BackColor;
		  }
		  void set(Color value)
		  {
			  this->BackColor = value;
		  }
	  }
	  [Category("VIOLETTA ADVANCED")]
		  property Color TextColor
	  {
		  Color get()
		  {
			  return this->ForeColor;
		  }
		  void set(Color value)
		  {
			  this->ForeColor = value;
		  }
	  }


	  //Constructor
public:
	RJButton();
	//Methods
private: GraphicsPath^ GetFigurePath(System::Drawing::Rectangle rect, float radius);
protected: virtual void OnPaint(PaintEventArgs^ pevent) override;
protected: virtual void OnHandleCreated(EventArgs^ e) override;
private: void OnParentBackColorChanged(Object^ sender, EventArgs^ e);
private: void OnResize(Object^ sender, EventArgs^ e);

};
}

