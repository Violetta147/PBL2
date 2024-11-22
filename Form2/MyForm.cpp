#include "MyForm.h"

using json = nlohmann::ordered_json;

Form2::MyForm::MyForm(void)
{	
	InitializeComponent();
	ConfigureMainMenuStrip();
	ConfigureContainerPanel();
	this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
	this->MAINBUTTON->ResumeLayout(false);
	this->MAINBUTTON->PerformLayout();
	this->ResumeLayout(false);
	this->PerformLayout();
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
	this->MAINBUTTON->Padding = System::Windows::Forms::Padding(120, 2, 120, 2);
	this->MAINBUTTON->Size = System::Drawing::Size(1200, 65);
	this->MAINBUTTON->TabIndex = 0;

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
	item->Size = System::Drawing::Size(120, 24); //...?
	item->Text = text;
	item->TextAlign = ContentAlignment::MiddleCenter;
	item->Click += click;
}

void Form2::MyForm::ConfigureContainerPanel()
{	
	Console::WriteLine("ConfigureContainerpanel");
	this->ContainerPanel->AutoScroll = true; //...?
	this->ContainerPanel->AutoSize = true;
	this->ContainerPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
	this->ContainerPanel->BackColor = System::Drawing::Color::Transparent;
	this->ContainerPanel->Dock = System::Windows::Forms::DockStyle::Fill;
	this->ContainerPanel->Location = System::Drawing::Point(0, 65);
	this->ContainerPanel->Name = L"ContainerPanel";
	this->ContainerPanel->Size = System::Drawing::Size(1200, 635);
	this->ContainerPanel->TabIndex = 1;
}


Form2::MyForm::~MyForm()
{
	if (components)
	{	
		delete tour;
		delete components;
	}
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
	this->ContainerPanel = (gcnew System::Windows::Forms::Panel());
	this->MAINBUTTON->SuspendLayout();
	this->SuspendLayout();
	// 
	// MyForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(1200, 700);
	formSize = this->ClientSize;
	this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
	this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
	this->Controls->Add(this->ContainerPanel);
	this->Controls->Add(this->MAINBUTTON);
	this->ForeColor = System::Drawing::Color::Transparent;
	this->MainMenuStrip = this->MAINBUTTON;
	this->Name = L"MyForm";
	this->ShowIcon = false;
	this->Text = L"MyForm";
	this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseDown);
	this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseMove);
	this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseUp);
	this->Resize += gcnew System::EventHandler(this, &MyForm::OnResize); // need to check later the order of logic
}

void Form2::MyForm::OnResize(Object^ sender, EventArgs^ e)
{	
	Console::WriteLine("OnResize");
	//this->SuspendLayout();
	//this->MAINBUTTON->SuspendLayout();
	// Container width (MenuStrip)
	int containerWidth = this->ClientSize.Width; //is this correct
	int numButtons = 6;
	float padding = 10; // Padding between buttons (space between buttons)

	// Subtract left and right margins for centering the buttons
	float marginSpace = 40;  // Total margin space to be distributed on both sides of the buttons (can be adjusted)
	float availableWidth = containerWidth - marginSpace;
	float buttonWidth = (availableWidth - (numButtons - 1) * padding) / numButtons;

	// Optionally, ensure the buttons are not too wide (set a max width if necessary)
	buttonWidth = std::fmin(buttonWidth, 200);
	float totalButtonWidth = (buttonWidth * numButtons) + (padding * (numButtons - 1));
	float remainingWidth = containerWidth - totalButtonWidth;
	// Distribute the remaining width as margins on both sides (left and right)
	float leftMargin = remainingWidth / 2.0;
	float rightMargin = remainingWidth / 2.0;

	this->MAINBUTTON->Padding = System::Windows::Forms::Padding(leftMargin, 0, rightMargin, 0);
	for each (ToolStripMenuItem ^ item in this->MAINBUTTON->Items)
	{
		item->AutoSize = false;  
		item->Width = buttonWidth; 
		if (item != RANKING) // Center the text for the first and last buttons
		{
			item->Margin = System::Windows::Forms::Padding(0, 0, padding, 0);
		}
		item->TextAlign = ContentAlignment::MiddleCenter; 
	}
	//how tf redraw how?
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
	Graphics^ g = e->Graphics;
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
		int segmentStartX = itemBounds.Left + 10;
		int segmentEndX = itemBounds.Right - 10;
		g->DrawLine(pen, segmentStartX, lineY, segmentEndX, lineY);
	}
	Console::WriteLine("OnMenuStripPaint");
	//this->MAINBUTTON->ResumeLayout(false);
	//this->MAINBUTTON->PerformLayout();
	//this->ResumeLayout(false);
	//this->PerformLayout();
	delete pen;
}
//before changing the color of the button, the previous button color must be reset
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
System::Void Form2::MyForm::TEAMS_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (currentMenuItem != sender)
	{
		ResetButtonColors(); // if there is a previous button clicked, reset the color
		currentMenuItem = dynamic_cast<ToolStripMenuItem^>(sender);
		//draw the line under the current button
		this->MAINBUTTON->Invalidate(); //Trigger Paint event ~ repaint
		// Add the user control to the panel
		UC_TEAMS^ ucTeams = gcnew Form2::UC_TEAMS(tour);
		addUserControl(ucTeams);
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
		UC_RANKING^ ucRanking = gcnew Form2::UC_RANKING();
		addUserControl(ucRanking);
	}
}
System::Void Form2::MyForm::addUserControl(UserControl^ userControl)
{
	//why this doesn't check if that's the first time the userControl is added?
	userControl->Dock = DockStyle::Fill;
	this->ContainerPanel->Controls->Clear(); //can this be hidden?
	this->ContainerPanel->Controls->Add(userControl);
	userControl->BringToFront();
}
