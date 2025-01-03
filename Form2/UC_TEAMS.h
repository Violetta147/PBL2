#pragma once
#include "include/Tournament.h"
#include "include/Team.h"
#include "ImageHelper.h"
#include "AddTeam.h"
#include "TeamInformation.h"
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
	private: System::Windows::Forms::Label^ label1;
	public: Tournament* tour;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UC_TEAMS::typeid));
			this->SearchPanel = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			this->SearchPanel->Controls->Add(this->label1);
			this->SearchPanel->Controls->Add(this->buttonMinus);
			this->SearchPanel->Controls->Add(this->buttonPlus);
			this->SearchPanel->Location = System::Drawing::Point(0, 0);
			this->SearchPanel->Margin = System::Windows::Forms::Padding(0);
			this->SearchPanel->Name = L"SearchPanel";
			this->SearchPanel->Size = System::Drawing::Size(1260, 90);
			this->SearchPanel->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(1161, 6);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 78);
			this->label1->TabIndex = 2;
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
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::SlateBlue;
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

		void GenerateTeamButtons()
		{	
			flowLayoutPanel1->Controls->Clear();
			Console::WriteLine(tour->get_team_count());
			for (int i = 1 ; i <= tour->getReq(); i++)
			{	
				Button^ button = gcnew Button();
				Team* team = tour->find_team_by_id(i);
				if (team == nullptr)
				{
					continue;
				}
				button->Tag = team->get_id();
				button->Name = gcnew String(team->get_name().c_str());
				button->Text = gcnew String(team->get_name().c_str());
                button->ForeColor = System::Drawing::Color::FromArgb(0x37, 0x00, 0x3c);
				button->TextAlign = ContentAlignment::BottomLeft;
				button->Font = gcnew System::Drawing::Font("PremierSans-Heavy, Arial, Helvetica, sans-serif", 12, FontStyle::Bold);
				button->AutoSize = false;
				button->Padding = System::Windows::Forms::Padding(10, 0, 0, 30);
				button->Size = System::Drawing::Size(buttonWidth, buttonHeight);
				button->Margin = System::Windows::Forms::Padding(buttonMargin);
				Image^ backGroundImage= ImageHelper::GetImageResource(button->Name + "_Default");
				if (backGroundImage != nullptr)
				{
					button->BackgroundImage = backGroundImage;
				}
				else
				{
					button->BackgroundImage = ImageHelper::GetImageResource("Unknown_Default");
				}
				button->BackgroundImageLayout = ImageLayout::Stretch;
				button->MouseEnter += gcnew EventHandler(this, &UC_TEAMS::Button_MouseEnter);
				button->MouseLeave += gcnew EventHandler(this, &UC_TEAMS::Button_MouseLeave);
				button->MouseClick += gcnew MouseEventHandler(this, &UC_TEAMS::Button_MouseClick);
				if (i == tour->getReq())
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
			int teamCount = tour->getReq();
			GenerateTeamButtons();
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
			else
			{
				Console::WriteLine("Normal");
				flowLayoutPanel1->Padding = System::Windows::Forms::Padding(buttonWidth / 3.5, 0, 0, 0);
			}
			this->flowLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			mainForm->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->PerformLayout();
			mainForm->PerformLayout();
		}
		void Button_MouseEnter(Object^ sender, EventArgs^ e)
		{
			Button^ button = (Button^)sender;
			//check if the resource is null
			if (ImageHelper::GetImageResource(button->Name + "_Hover") != nullptr)
			{
				button->BackgroundImage = ImageHelper::GetImageResource(button->Name + "_Hover");
				button->ForeColor = System::Drawing::Color::White;
			}
			else
			{
				button->BackgroundImage = ImageHelper::GetImageResource("Unknown_Hover");
				button->ForeColor = System::Drawing::Color::White;
			}
		}
		void Button_MouseLeave(Object^ sender, EventArgs^ e)
		{
			Button^ button = (Button^)sender;
			button->BackgroundImage = ImageHelper::GetImageResource(button->Name + "_Default");
			button->ForeColor = System::Drawing::Color::FromArgb(0x37, 0x00, 0x3c);
		}
		void Button_MouseClick(Object^ sender, MouseEventArgs^ e)
		{
			if (isDeleteMode == true)
			{
				Button^ button = (Button^)sender;
				String^ teamName = button->Name;
				DialogResult result = MessageBox::Show("Are you sure you want to delete " + teamName + "?", "Delete Team", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

				if (result == System::Windows::Forms::DialogResult::Yes)
				{
					// Delete the team from the tournament
					Team* team = tour->find_team_by_id(Convert::ToInt32(button->Tag));
					tour->delete_team(*team);
					GenerateTeamButtons();

					// Delete the associated image files
					String^ resourceDir = "C:\\Users\\LAPTOP T&T\\source\\repos\\Violetta147\\PBL2\\Form2\\Resources\\";

					try
					{
						// Safely dispose of the background image
						if (button->BackgroundImage != nullptr)
						{
							delete button->BackgroundImage; // Calls Dispose internally
							button->BackgroundImage = nullptr; // Clear the reference
						}

						// Construct file paths
						String^ defaultImage = System::IO::Path::Combine(resourceDir, teamName + "_Default.png");
						String^ hoverImage = System::IO::Path::Combine(resourceDir, teamName + "_Hover.png");

						// Attempt to delete files, fallback to renaming if deletion fails
						if (System::IO::File::Exists(defaultImage))
						{
							try
							{
								System::IO::File::Delete(defaultImage);
							}
							catch (Exception^)
							{
								// Rename the file as a fallback
								String^ renamedDefault = defaultImage + ".to_delete";
								System::IO::File::Move(defaultImage, renamedDefault);
							}
						}

						if (System::IO::File::Exists(hoverImage))
						{
							try
							{
								System::IO::File::Delete(hoverImage);
							}
							catch (Exception^)
							{
								// Rename the file as a fallback
								String^ renamedHover = hoverImage + ".to_delete";
								System::IO::File::Move(hoverImage, renamedHover);
							}
						}
					}
					catch (Exception^ ex)
					{
						Console::WriteLine("Error handling image files: " + ex->Message);
					}
				}
			}
			else
			{
				Button^ button = (Button^)sender;
				for each (auto team in tour->getTeams())
				{	
					if (team.get_id() == Convert::ToInt32(button->Tag))
					{
						Form^ teamInformation = gcnew TeamInformation(tour, team.get_id());
						teamInformation->ShowDialog();
					}
				}
			}
		}

#pragma endregion

private: System::Void buttonPlus_Click(System::Object^ sender, System::EventArgs^ e) {
	
	/*if (tour->get_team_count() == tour->getReq())
	{
		MessageBox::Show("NUMBER OF TEAMS LIMIT REACHED", "Cannot Add", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		MessageBox::Show("Please go to delete mode to delete a team", "Delete Mode", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}*/
	Form^ addTeam = gcnew AddTeam(tour);
	addTeam->ShowDialog();
	GenerateTeamButtons();
}
private: System::Void buttonMinus_Click(System::Object^ sender, System::EventArgs^ e) {
                
	if (isDeleteMode == true)
	{
		isDeleteMode = false;
		MessageBox::Show("You are out of DELETE MODE", "Out of Delete Mode", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
     State state = tour->getState();

	 if (state == GO || state == MID || state == AWAY || state == POS)
	{
		 MessageBox::Show("Cannot delete team during tournament is on going", "Cannot Delete", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		 return;
	}
	if (tour->get_team_count() == 0)
	{
		MessageBox::Show("There are no teams to delete", "No Teams", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	DialogResult result = MessageBox::Show("You are in DELETE MODE! Click on a team to delete it", "DELETE MODE", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		isDeleteMode = true;
	}
	else
	{ 
		isDeleteMode = false;
	}
}

};
}