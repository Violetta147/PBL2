#pragma once

ref class TransparentRenderer : public System::Windows::Forms::ToolStripProfessionalRenderer
{
protected:
	virtual void OnRenderMenuItemBackground(System::Windows::Forms::ToolStripItemRenderEventArgs^ e) override;
};

