#pragma once
public ref class NeonMenuRenderer : public System::Windows::Forms::ToolStripProfessionalRenderer
{
protected:
	virtual void OnRenderMenuItemBackground(System::Windows::Forms::ToolStripItemRenderEventArgs^ e) override;
	virtual void OnRenderItemText(System::Windows::Forms::ToolStripItemTextRenderEventArgs^ e) override;
};


