#include "MyForm.h"

using json = nlohmann::ordered_json;

Form2::MyForm::MyForm(void)
{	
	InitializeComponent();
	formSize = this->ClientSize;
	ConfigureScrollBar();
	ConfigureMainMenuStrip();
	originalSize = MAINBUTTON->Items[0]->Size;
	originalMarginRight = MAINBUTTON->Items[0]->Margin.Right;
	this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
}

void Form2::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	try
	{	
		Console::WriteLine("MyForm_Load");
		tour = new Tournament(read_tournament("tournament.json")); // does this lead to wrong memory management?
		tour->get_all_data();
		MessageBox::Show("Tournament data loaded successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (const std::exception& )
	{
		MessageBox::Show("Failed to load tournament data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}

void Form2::MyForm::ConfigureMainMenuStrip()
{	
	Console::WriteLine("ConfigureMainMenuStrip");
	this->MAINBUTTON->AllowMerge = false;
	this->MAINBUTTON->AutoSize = false;
	this->MAINBUTTON->BackColor = System::Drawing::Color::Transparent;
	this->MAINBUTTON->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
	this->MAINBUTTON->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6)
	{
		this->HOME, this->TEAMS,
		this->PLAYERS, this->MATCHES, this->STATS, this->RANKING
	});
	this->MAINBUTTON->Location = System::Drawing::Point(0, 0);
	this->MAINBUTTON->Name = L"MAINBUTTON";
	this->MAINBUTTON->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
	this->MAINBUTTON->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
	this->MAINBUTTON->Size = System::Drawing::Size(formSize.Width - vScrollBar1->Width, formSize.Height / 8);
	this->MAINBUTTON->Padding = System::Windows::Forms::Padding((formSize.Width - vScrollBar1->Width)/8, this->MAINBUTTON->Height / 8, (formSize.Width - vScrollBar1->Width)/8, this->MAINBUTTON->Height / 8);
	this->MAINBUTTON->TabIndex = 1;

	//...
	ConfigureMenuItem(HOME, L"HOME", gcnew System::EventHandler(this, &MyForm::HOME_Click));
	ConfigureMenuItem(TEAMS, L"TEAMS", gcnew System::EventHandler(this, &MyForm::TEAMS_Click));
	ConfigureMenuItem(PLAYERS, L"PLAYERS", gcnew System::EventHandler(this, &MyForm::PLAYERS_Click));
	ConfigureMenuItem(MATCHES, L"MATCHES", gcnew System::EventHandler(this, &MyForm::MATCHES_Click));
	ConfigureMenuItem(STATS, L"STATS", gcnew System::EventHandler(this, &MyForm::STATS_Click));
	ConfigureMenuItem(RANKING, L"RANKING", gcnew System::EventHandler(this, &MyForm::RANKING_Click));

	this->MAINBUTTON->Renderer = gcnew TransparentRenderer();
	for each (ToolStripMenuItem ^ item in MAINBUTTON->Items)
	{
		item->MouseEnter += gcnew System::EventHandler(this, &Form2::MyForm::OnMenuItemHover);
		item->MouseLeave += gcnew System::EventHandler(this, &Form2::MyForm::OnMenuItemLeave);
	}
	this->MAINBUTTON->Paint += gcnew PaintEventHandler(this, &Form2::MyForm::OnMenuStripPaint); //draw whiteline
	this->MAINBUTTON->ResumeLayout(false);
	this->PerformLayout();
}

void Form2::MyForm::ConfigureMenuItem(ToolStripMenuItem^ item, String^ text, EventHandler^ click)
{	
	Console::WriteLine("ConfigureMenuItem");
	item->AutoSize = false;
	item->BackColor = System::Drawing::Color::Transparent;
	item->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	item->ForeColor = System::Drawing::Color::White;
	item->Name = text;
	item->Size = System::Drawing::Size((formSize.Width - vScrollBar1->Size.Width) / 8, 24);//...
	item->Text = text;
	item->TextAlign = ContentAlignment::MiddleCenter;
	item->Click += click;
}


Form2::MyForm::~MyForm()
{
	if (components)
	{	
		delete tour;
		delete components;
	}
}
void Form2::MyForm::ConfigureScrollBar()
{	
	// 
	// vScrollBar1
	// 
	this->vScrollBar1->Name = L"vScrollBar1";
	this->vScrollBar1->Size = System::Drawing::Size(20, formSize.Height);
	this->vScrollBar1->Location = System::Drawing::Point(formSize.Width - vScrollBar1->Width, 0);
	this->vScrollBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom));
	this->vScrollBar1->Visible = true;
	this->vScrollBar1->Enabled = true;
	this->vScrollBar1->TabIndex = 0;
	this->vScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::vScrollBar1_Scroll);
	this->vScrollBar1->ResumeLayout(false);
}
void Form2::MyForm::InitializeComponent(void)
{
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
	this->MAINBUTTON = (gcnew System::Windows::Forms::MenuStrip());
	this->HOME = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->TEAMS = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->PLAYERS = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->MATCHES = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->STATS = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->RANKING = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
	this->SuspendLayout();
	// 
	// MyForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
	this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
	this->ClientSize = System::Drawing::Size(1280, 720);
	this->Controls->Add(this->vScrollBar1);
	this->Controls->Add(this->MAINBUTTON);
	this->MainMenuStrip = this->MAINBUTTON;
	this->Name = L"MyForm";
	this->ShowIcon = false;
	this->Text = L"MyForm";
	this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseDown);
	this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseMove);
	this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseUp);
	this->Resize += gcnew System::EventHandler(this, &MyForm::OnResize);
	this->ResumeLayout(false);
	this->PerformLayout();

}

void Form2::MyForm::OnResize(Object^ sender, EventArgs^ e)
{	
	this->SuspendLayout();
	Console::WriteLine("OnResize");
	float xRatio = static_cast<float>(this->ClientSize.Width) / formSize.Width;

	this->MAINBUTTON->Padding = System::Windows::Forms::Padding((this->ClientSize.Width - this->vScrollBar1->Width) / 8, 11.25, (this->ClientSize.Width - this->vScrollBar1->Width) / 8, 11.25);
	for each (ToolStripMenuItem ^ item in this->MAINBUTTON->Items)
	{
		item->Size = System::Drawing::Size(static_cast<int>(originalSize.Width * xRatio), item->Size.Height);
		if (item != RANKING)
		{
			item->Margin = System::Windows::Forms::Padding(0, 0, originalMarginRight * xRatio, 0);
		}
		item->TextAlign = ContentAlignment::MiddleCenter; 
	}
	if (currentUC != nullptr)
	{
		vScrollBar1->Minimum = 0;
		FlowLayoutPanel^ flowPanel = dynamic_cast<FlowLayoutPanel^>(currentUC->Controls["flowLayoutPanel1"]);
		if (flowPanel != nullptr)
		{
			vScrollBar1->Maximum = flowPanel->VerticalScroll->Maximum;
			vScrollBar1->Value = flowPanel->VerticalScroll->Value;
			SCROLLINFO si = { 0 };
			si.cbSize = sizeof(SCROLLINFO);
			si.fMask = SIF_ALL;
			if (::GetScrollInfo(static_cast<HWND>(flowPanel->Handle.ToPointer()), SB_VERT, &si))
			{
				vScrollBar1->LargeChange = si.nPage;
				vScrollBar1->SmallChange = max(1, si.nPage / 20);
			}
		}
	}
	this->ResumeLayout(false);
}

void Form2::MyForm::OnMouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		dragging = true;
		offset = Point(e->X, e->Y);
	}
}

void Form2::MyForm::OnMouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (dragging)
	{
		Point currentScreenPos = PointToScreen(e->Location);
		Location = Point(currentScreenPos.X - offset.X, currentScreenPos.Y - offset.Y);
	}
}

void Form2::MyForm::OnMouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		dragging = false;
	}
}
void Form2::MyForm::OnMenuItemHover(Object^ sender, EventArgs^ e)
{	
		Console::WriteLine("OnMenuItemHover");
	hoveredItem = dynamic_cast<ToolStripMenuItem^>(sender);
	hoveredIndex = this->MAINBUTTON->Items->IndexOf(hoveredItem);
	//currentMenuItem only changes state when there is event of click a button and if 
	//next button click is not the same as the previous one
	if (hoveredItem != nullptr && hoveredItem != currentMenuItem) {
		hoveredItem->ForeColor = Color::LimeGreen;
	}
	this->MAINBUTTON->Invalidate(); //Trigger Paint event ~ repaint
}

void Form2::MyForm::OnMenuItemLeave(Object^ sender, EventArgs^ e)
{	
	Console::WriteLine("OnMenuItemLeave");
	if (hoveredItem != nullptr && hoveredItem != currentMenuItem) {
		// Revert the text color back to the default 
		hoveredItem->ForeColor = Color::FromArgb(120, Color::White);
	}
	hoveredItem = nullptr;
	hoveredIndex = -1;
	this->MAINBUTTON->Invalidate(); //Trigger Paint event ~ repaint
}

void Form2::MyForm::OnMenuStripPaint(Object^ sender, PaintEventArgs^ e)
{	
	//need more well calculated size of the greenlime line
	Graphics^ g = e->Graphics;//...
	Pen^ pen = gcnew Pen(Color::FromArgb(120, Color::White));
	pen->Width = 2.0f;

	int startX = this->HOME->Bounds.Left - this->HOME->Padding.Right;
	int endX = this->RANKING->Bounds.Right + this->RANKING->Padding.Left;

	int lineY = this->HOME->Bounds.Bottom + 2;

	g->DrawLine(pen, startX, lineY, endX, lineY);	
	pen->Color = Color::LimeGreen;
	pen->Width = 2.0f;
	
	if (hoveredItem != nullptr && hoveredIndex != -1 )
	{	
		Console::WriteLine("hoveredItem");
        System::Drawing::Rectangle itemBounds = hoveredItem->Bounds;
		int segmentStartX = itemBounds.Left - hoveredItem->Padding.Right;
		int segmentEndX = itemBounds.Right + hoveredItem->Padding.Right;
		g->DrawLine(pen, segmentStartX, lineY, segmentEndX, lineY);
	}
	if (currentMenuItem != nullptr) //no else?
	{	
		Console::WriteLine("currentMenuItem");
		currentMenuItem->ForeColor = Color::LimeGreen;
		System::Drawing::Rectangle itemBounds = currentMenuItem->Bounds;
		int segmentStartX = itemBounds.Left - currentMenuItem->Padding.Right;
		int segmentEndX = itemBounds.Right + currentMenuItem->Padding.Right;
		g->DrawLine(pen, segmentStartX, lineY, segmentEndX, lineY);
	}
	Console::WriteLine("OnMenuStripPaint");
	delete pen;
	this->PerformLayout();
}
void Form2::MyForm::ResetButtonColors()
{
	for each (ToolStripMenuItem ^ item in MAINBUTTON->Items)
	{
		item->ForeColor = Color::FromArgb(120, Color::White);
	}
}
System::Void Form2::MyForm::HOME_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (currentMenuItem != sender)
	{
		ResetButtonColors(); // if there is a previous button clicked, reset the color
		currentMenuItem = dynamic_cast<ToolStripMenuItem^>(sender);
		this->MAINBUTTON->Invalidate();
		//draw the line under the current button
		// Add the user control to the panel
		UC_HOME^ ucHome = gcnew Form2::UC_HOME();
		addUserControl(ucHome);
	}
}
System::Void Form2::MyForm::PLAYERS_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (currentMenuItem != sender)
	{
		ResetButtonColors(); // if there is a previous button clicked, reset the color
		currentMenuItem = dynamic_cast<ToolStripMenuItem^>(sender);
		//draw the line under the current button
		this->MAINBUTTON->Invalidate(); //Trigger Paint event ~ repaint
		// Add the user control to the panel
		UC_PLAYERS^ ucPlayers = gcnew Form2::UC_PLAYERS();
		addUserControl(ucPlayers);
	}
}
System::Void Form2::MyForm::MATCHES_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (currentMenuItem != sender)
	{
		ResetButtonColors(); // if there is a previous button clicked, reset the color
		currentMenuItem = dynamic_cast<ToolStripMenuItem^>(sender);
		//draw the line under the current button
		this->MAINBUTTON->Invalidate(); //Trigger Paint event ~ repaint
		// Add the user control to the panel
		UC_MATCHES^ ucMatches = gcnew Form2::UC_MATCHES();
		addUserControl(ucMatches);
	}
}
System::Void Form2::MyForm::STATS_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (currentMenuItem != sender)
	{
		ResetButtonColors(); // if there is a previous button clicked, reset the color
		currentMenuItem = dynamic_cast<ToolStripMenuItem^>(sender);
		//draw the line under the current button
		this->MAINBUTTON->Invalidate(); //Trigger Paint event ~ repaint
		// Add the user control to the panel
		UC_STATS^ ucStats = gcnew Form2::UC_STATS();
		addUserControl(ucStats);
	}
}
System::Void Form2::MyForm::RANKING_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (currentMenuItem != sender)
	{
		ResetButtonColors(); // if there is a previous button clicked, reset the color
		currentMenuItem = dynamic_cast<ToolStripMenuItem^>(sender);
		//draw the line under the current button
		this->MAINBUTTON->Invalidate(); //Trigger Paint event ~ repaint
		// Add the user control to the panel
		this->vScrollBar1->Visible = false;
		UC_RANKING^ ucRanking = gcnew Form2::UC_RANKING(tour);
		addUserControl(ucRanking);
	}
}
System::Void Form2::MyForm::addUserControl(UserControl^ userControlNew)
{
	//why this doesn't check if that's the first time the userControl is added?
	//clear the previous user control
	if (currentUC != nullptr)
	{
		this->Controls->Remove(currentUC);
		//optionally dispose the user control if no longer return back to the old state
		//currentUC->Dispose(); 
	}
	currentUC = userControlNew;
	this->Controls->Add(currentUC);
	this->Controls->SetChildIndex(currentUC, 2);
	currentUC->BringToFront();
}
System::Void Form2::MyForm::TEAMS_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (currentMenuItem != sender)
	{	
		ResetButtonColors(); // if there is a previous button clicked, reset the color
		currentMenuItem = dynamic_cast<ToolStripMenuItem^>(sender);
		//draw the line under the current button
		this->MAINBUTTON->Invalidate(); //Trigger Paint event ~ repaint
		// Add the user control to the panel
		if (vScrollBar1->Visible == false)
		{
			vScrollBar1->Visible = true;
		}
		UC_TEAMS^ ucTeams = gcnew Form2::UC_TEAMS(tour);
		FlowLayoutPanel^ flowPanel = dynamic_cast<FlowLayoutPanel^>(ucTeams->Controls["flowLayoutPanel1"]);
		if (flowPanel != nullptr)
		{
			flowPanel->Layout += gcnew System::Windows::Forms::LayoutEventHandler(this, &MyForm::OnFlowPanelLayout);
		}
		ucTeams->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
		addUserControl(ucTeams);
	}
}

void Form2::MyForm::vScrollBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{	
	Console::WriteLine("vScrollBar1_Scroll");
	if (currentUC != nullptr)
	{
		FlowLayoutPanel^ flowPanel = dynamic_cast<FlowLayoutPanel^>(currentUC->Controls["flowLayoutPanel1"]);
		if (flowPanel != nullptr)
		{	
			flowPanel->VerticalScroll->Value = vScrollBar1->Value;

			Console::WriteLine(vScrollBar1->Value);
			flowPanel->Invalidate();
		}
	}
}

void Form2::MyForm::OnFlowPanelLayout(Object^ sender, LayoutEventArgs^ e)
{	
	static int count = 0;
	count++;
	Console::WriteLine("OnFlowPanelLayout");
	FlowLayoutPanel^ flowPanel = dynamic_cast<FlowLayoutPanel^>(sender);
	//too many calls to if need update later but still fine
	if (flowPanel != nullptr)
	{
		// Update scrollbar range after layout changes
		vScrollBar1->Minimum = 0;
		vScrollBar1->Maximum = flowPanel->VerticalScroll->Maximum;
		vScrollBar1->Value = flowPanel->VerticalScroll->Value; //...
	}
	if (count == 4)
	{	
		SCROLLINFO si = { 0 };
		si.cbSize = sizeof(SCROLLINFO);
		si.fMask = SIF_ALL;

		if (::GetScrollInfo(static_cast<HWND>(flowPanel->Handle.ToPointer()), SB_VERT, &si))
		{
			vScrollBar1->LargeChange = si.nPage;
			Console::WriteLine(vScrollBar1->LargeChange);
			vScrollBar1->SmallChange = max(1, si.nPage / 20); //another max:(
		}
	}
}
