#pragma once
#include "include/Tournament.h"
#include "include/Team.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Resources;
using namespace System::Reflection;

namespace Form2 {

	public ref class UC_TEAMS : public System::Windows::Forms::UserControl
	{
	public:
		UC_TEAMS(Tournament* tour)
		{	
			InitializeComponent();
			this->Load += gcnew EventHandler(this, &UC_TEAMS::UC_TEAMS_Load);
			this->Resize += gcnew System::EventHandler(this, &Form2::UC_TEAMS::OnResize);
			this->tour = tour;
		}

	protected:
		~UC_TEAMS()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		   System::ComponentModel::Container ^components;
	       System::Windows::Forms::Panel^ SearchPanel;
		   bool isDeleteMode = false;
		   const int buttonWidth = 320;
		   const int buttonHeight = 240;
		   const int buttonMargin = 20;


	private: System::Windows::Forms::Label^ buttonMinus;

	private: System::Windows::Forms::Label^ buttonPlus;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
		   Tournament* tour;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UC_TEAMS::typeid));
			this->SearchPanel = (gcnew System::Windows::Forms::Panel());
			this->buttonMinus = (gcnew System::Windows::Forms::Label());
			this->buttonPlus = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SearchPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// SearchPanel
			// 
			this->SearchPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->SearchPanel->BackColor = System::Drawing::Color::Transparent;
			this->SearchPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SearchPanel.BackgroundImage")));
			this->SearchPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->SearchPanel->Controls->Add(this->buttonMinus);
			this->SearchPanel->Controls->Add(this->buttonPlus);
			this->SearchPanel->Location = System::Drawing::Point(0, 0);
			this->SearchPanel->Margin = System::Windows::Forms::Padding(0);
			this->SearchPanel->Name = L"SearchPanel";
			this->SearchPanel->Size = System::Drawing::Size(1260, 90);
			this->SearchPanel->TabIndex = 0;
			// 
			// buttonMinus
			// 
			this->buttonMinus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMinus->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonMinus.Image")));
			this->buttonMinus->Location = System::Drawing::Point(141, 6);
			this->buttonMinus->Margin = System::Windows::Forms::Padding(0);
			this->buttonMinus->Name = L"buttonMinus";
			this->buttonMinus->Size = System::Drawing::Size(85, 78);
			this->buttonMinus->TabIndex = 1;
			this->buttonMinus->Click += gcnew System::EventHandler(this, &UC_TEAMS::buttonMinus_Click);
			this->buttonMinus->MouseLeave += gcnew System::EventHandler(this, &UC_TEAMS::buttonMinus_MouseLeave);
			this->buttonMinus->MouseHover += gcnew System::EventHandler(this, &UC_TEAMS::buttonMinus_MouseHover);
			// 
			// buttonPlus
			// 
			this->buttonPlus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPlus->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonPlus.Image")));
			this->buttonPlus->Location = System::Drawing::Point(53, 6);
			this->buttonPlus->Margin = System::Windows::Forms::Padding(0);
			this->buttonPlus->Name = L"buttonPlus";
			this->buttonPlus->Size = System::Drawing::Size(88, 78);
			this->buttonPlus->TabIndex = 0;
			this->buttonPlus->Click += gcnew System::EventHandler(this, &UC_TEAMS::buttonPlus_Click);
			this->buttonPlus->MouseLeave += gcnew System::EventHandler(this, &UC_TEAMS::buttonPlus_MouseLeave);
			this->buttonPlus->MouseHover += gcnew System::EventHandler(this, &UC_TEAMS::buttonPlus_MouseHover);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::IndianRed;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 90);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(1260, 540);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// UC_TEAMS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Lime;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->SearchPanel);
			this->DoubleBuffered = true;
			this->Location = System::Drawing::Point(0, 90);
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"UC_TEAMS";
			this->Size = System::Drawing::Size(1260, 630);
			this->SearchPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
		void GenerateTeamButtons(int teamCount)
		{	
			flowLayoutPanel1->Controls->Clear();
			for (int i = 0; i < tour->get_team_count(); i++)
			{	
				Button^ button = gcnew Button();
				Team* team = tour->getTeam(i);
				button->Name = gcnew String(team->get_name().c_str());
				button->Text = gcnew String(team->get_name().c_str());
                button->ForeColor = System::Drawing::Color::FromArgb(0x37, 0x00, 0x3c);
				button->TextAlign = ContentAlignment::BottomLeft;
				button->Font = gcnew System::Drawing::Font("PremierSans-Heavy, Arial, Helvetica, sans-serif", 12, FontStyle::Bold);
				button->AutoSize = false;
				button->Padding = System::Windows::Forms::Padding(10, 0, 0, 30);
				button->Size = System::Drawing::Size(buttonWidth, buttonHeight);
				button->Margin = System::Windows::Forms::Padding(buttonMargin);
				button->BackgroundImage = GetImageResource(button->Name + "_Default");
				button->BackgroundImageLayout = ImageLayout::Stretch;
				button->MouseEnter += gcnew EventHandler(this, &UC_TEAMS::Button_MouseEnter);
				button->MouseLeave += gcnew EventHandler(this, &UC_TEAMS::Button_MouseLeave);
				button->MouseClick += gcnew MouseEventHandler(this, &UC_TEAMS::Button_MouseClick);
				if (i == tour->get_team_count() - 1)
				{	
					this->flowLayoutPanel1->ResumeLayout(false);
					flowLayoutPanel1->Controls->Add(button);
					this->flowLayoutPanel1->SuspendLayout();
				}
				else
				{
					flowLayoutPanel1->Controls->Add(button);
				}
			}
		}
		void UC_TEAMS_Load(Object^ sender, EventArgs^ e)
		{	
			this->flowLayoutPanel1->SuspendLayout();
			Console::WriteLine("Load");
			Form^ mainForm = this->FindForm(); // or can use this->Parent
			MenuStrip^ MAINBUTTON = dynamic_cast<MenuStrip^>(mainForm->Controls["MAINBUTTON"]);
			VScrollBar^ vScrollBar1 = dynamic_cast<VScrollBar^>(mainForm->Controls["vScrollBar1"]);
			this->Size = System::Drawing::Size(mainForm->ClientSize.Width - vScrollBar1->Width, mainForm->ClientSize.Height - MAINBUTTON->Height);
			flowLayoutPanel1->Size = System::Drawing::Size(this->Size.Width + 20, this->Size.Height - SearchPanel->Height);
			flowLayoutPanel1->Padding = System::Windows::Forms::Padding(buttonWidth / 3.5, 0, 0, 0);
			//panel1->Size = System::Drawing::Size(flowLayoutPanel1->Width - 20, flowLayoutPanel1->Height);
			flowLayoutPanel1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::UC_TEAMS::OnMouseWheel);
			int teamCount = tour->get_team_count();
			GenerateTeamButtons(teamCount);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
		}

		void OnMouseWheel(Object^ sender, MouseEventArgs^ e)
		{	
			FlowLayoutPanel^ flowPanel = dynamic_cast<FlowLayoutPanel^>(sender);
			Form^ mainForm = this->FindForm();
			VScrollBar^ vScrollBar1 = dynamic_cast<VScrollBar^>(mainForm->Controls["vScrollBar1"]);
			if (flowPanel != nullptr)
			{
				int numberOfTextLinesToMove = e->Delta * SystemInformation::MouseWheelScrollLines / 120;
				int numberOfPixelsToMove = numberOfTextLinesToMove * 20;
				int newValue = flowLayoutPanel1->VerticalScroll->Value - numberOfPixelsToMove;
				if (newValue < vScrollBar1->Minimum)
				{
					vScrollBar1->Value = vScrollBar1->Minimum;
				}
				else if (newValue > vScrollBar1->Maximum)
				{
					vScrollBar1->Value = vScrollBar1->Maximum;
				}
				else
				{
					vScrollBar1->Value = newValue;
				}
			}
		}
		void OnResize(Object^ sender, EventArgs^ e)
		{	
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			Form^ mainForm = this->FindForm(); 
			mainForm->SuspendLayout();
			System::Drawing::Rectangle^ workingArea = Screen::FromControl(mainForm)->WorkingArea;

			if (mainForm->WindowState == FormWindowState::Maximized || mainForm->Size.Width >= workingArea->Width)
			{	
				Console::WriteLine("Maximized");
				flowLayoutPanel1->Padding = System::Windows::Forms::Padding(buttonWidth / 2, 0, buttonWidth / 2, 0); //...
			}
			this->flowLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			mainForm->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->PerformLayout();
			mainForm->PerformLayout();
		}
		Image^ GetImageResource (String^ resourceName)
		{
			Assembly^ assembly = Assembly::GetExecutingAssembly();
			ResourceManager^ rm = gcnew ResourceManager("Form2.MyResource", assembly);
			Object^ resource = rm->GetObject(resourceName);
			if (resource == nullptr)
			{
				Console::WriteLine("Resource not found: " + resourceName);
			}
			if (resource->GetType() == array<Byte>::typeid)
			{
				array<Byte>^ bytes = (array<Byte>^)resource;
				System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(bytes);
				return Image::FromStream(ms);
			}
			return (Image^)resource;
		}
		void Button_MouseEnter(Object^ sender, EventArgs^ e)
		{
			Button^ button = (Button^)sender;
			button->BackgroundImage = GetImageResource(button->Name + "_Hover");
			button->ForeColor = System::Drawing::Color::White;
		}
		void Button_MouseLeave(Object^ sender, EventArgs^ e)
		{
			Button^ button = (Button^)sender;
			button->BackgroundImage = GetImageResource(button->Name + "_Default");
			button->ForeColor = System::Drawing::Color::FromArgb(0x37, 0x00, 0x3c);
		}
		void Button_MouseClick(Object^ sender, MouseEventArgs^ e)
		{
			if (isDeleteMode)
			{
				Button^ button = (Button^)sender;
				String^ teamName = button->Name;
				DialogResult result = MessageBox::Show("Are you sure you want to delete " + teamName + "?", "Delete Team", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
				if (result == System::Windows::Forms::DialogResult::Yes)
				{

				}
			}
		}
#pragma endregion

private: System::Void buttonPlus_Click(System::Object^ sender, System::EventArgs^ e) {


}
private: System::Void buttonMinus_Click(System::Object^ sender, System::EventArgs^ e) {

	DialogResult result = MessageBox::Show("You are in DELETE MODE! Click on a team to delete it", "DELETE MODE", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		isDeleteMode = true;
	}
	else
	{
		isDeleteMode = false;
	}
	if (isDeleteMode == true)
	{
	}
}
private: System::Void buttonPlus_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	buttonPlus->Size = System::Drawing::Size(95, 88);
}
private: System::Void buttonMinus_MouseHover(System::Object^ sender, System::EventArgs^ e) {
	buttonMinus->Size = System::Drawing::Size(95, 88);
}
private: System::Void buttonPlus_MouseLeave(System::Object^ sender, System::EventArgs^ e) {

	buttonPlus->Size = System::Drawing::Size(88, 78);
}
private: System::Void buttonMinus_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	buttonMinus->Size = System::Drawing::Size(85, 78);
}
};
}