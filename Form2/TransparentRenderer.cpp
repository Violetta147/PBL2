#include "TransparentRenderer.h"

void TransparentRenderer::OnRenderMenuItemBackground(System::Windows::Forms::ToolStripItemRenderEventArgs^ e)
{
	if (!e->Item->Selected)
	{	
		__super::OnRenderMenuItemBackground(e); // Draw normally if not selected
	}
}