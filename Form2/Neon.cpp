//#include "Neon.h"
//
//void NeonMenuRenderer::OnRenderMenuItemBackground(System::Windows::Forms::ToolStripItemRenderEventArgs^ e)
//{
//	if (e->Item->Selected)
//	{
//		e->Graphics->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Transparent), e->Item->ContentRectangle);
//	}
//	else
//	{
//		System::Windows::Forms::ToolStripProfessionalRenderer::OnRenderMenuItemBackground(e);
//	}
//}
//
//
//void NeonMenuRenderer::OnRenderItemText(System::Windows::Forms::ToolStripItemTextRenderEventArgs^ e)
//{
//	if (e->Item->Selected)
//	{
//		e->TextColor = System::Drawing::Color::LimeGreen;
//	}
//	else
//	{	
//		e->TextColor = System::Drawing::Color::White;
//	}
//	System::Windows::Forms::ToolStripProfessionalRenderer::OnRenderItemText(e);
//	if (e->Item->Selected)
//	{
//		System::Drawing::Rectangle textRect = e->TextRectangle;
//		System::Drawing::Pen^ neonPen = gcnew System::Drawing::Pen(System::Drawing::Color::LimeGreen, 2);
//
//		e->Graphics->DrawLine(neonPen, textRect.Left, textRect.Bottom + 2, textRect.Right, textRect.Bottom + 2);
//		delete neonPen;
//	}
//
//}