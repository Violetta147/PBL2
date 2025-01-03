#pragma once
#include "include/Tournament.h"
#include "WrapperPlayer.h"
#include "TeamDataView.h"
#include "ImageHelper.h"
#include "EditTeam.h"

namespace Form2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TeamInformation
	/// </summary>
	public ref class TeamInformation : public System::Windows::Forms::Form
	{
	public:
		TeamInformation(Tournament* tour, int TId)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->tour = tour;
			this->TId = TId;
			SetTeamName();
			SetTeamLogo();
			SetEstablishmentYear();
			SetMainPanelBGR();
			SetButtonColor();
			InitializeSlideTimer();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TeamInformation()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ containerPanel;
	private: System::Windows::Forms::Panel^ mainPanel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;

		   Tournament* tour;
		   int TId;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: CustomControls::RJButton^ rjButton1;
	private: CustomControls::RJButton^ rjButton2;
	private: System::Windows::Forms::Timer^ slideTimer;
	private: UserControl^ slidingControl;
	private: int targetX;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TeamInformation::typeid));
			this->containerPanel = (gcnew System::Windows::Forms::Panel());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->rjButton2 = (gcnew CustomControls::RJButton());
			this->rjButton1 = (gcnew CustomControls::RJButton());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->containerPanel->SuspendLayout();
			this->mainPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// containerPanel
			// 
			this->containerPanel->AutoScroll = true;
			this->containerPanel->AutoSize = true;
			this->containerPanel->BackColor = System::Drawing::Color::Gold;
			this->containerPanel->Controls->Add(this->mainPanel);
			this->containerPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->containerPanel->Location = System::Drawing::Point(0, 0);
			this->containerPanel->Margin = System::Windows::Forms::Padding(0);
			this->containerPanel->Name = L"containerPanel";
			this->containerPanel->Size = System::Drawing::Size(1399, 791);
			this->containerPanel->TabIndex = 0;
			// 
			// mainPanel
			// 
			this->mainPanel->BackColor = System::Drawing::Color::DarkGoldenrod;
			this->mainPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->mainPanel->Controls->Add(this->rjButton2);
			this->mainPanel->Controls->Add(this->rjButton1);
			this->mainPanel->Controls->Add(this->pictureBox2);
			this->mainPanel->Controls->Add(this->label3);
			this->mainPanel->Controls->Add(this->label2);
			this->mainPanel->Controls->Add(this->pictureBox1);
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->mainPanel->Location = System::Drawing::Point(0, 0);
			this->mainPanel->Margin = System::Windows::Forms::Padding(0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(1399, 293);
			this->mainPanel->TabIndex = 0;
			// 
			// rjButton2
			// 
			this->rjButton2->BackColor = System::Drawing::Color::GhostWhite;
			this->rjButton2->BackgroundColor = System::Drawing::Color::GhostWhite;
			this->rjButton2->BorderColor = System::Drawing::Color::Transparent;
			this->rjButton2->BorderRadius = 40;
			this->rjButton2->BorderSize = 0;
			this->rjButton2->FlatAppearance->BorderSize = 0;
			this->rjButton2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rjButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rjButton2->ForeColor = System::Drawing::Color::Black;
			this->rjButton2->Location = System::Drawing::Point(343, 243);
			this->rjButton2->Name = L"rjButton2";
			this->rjButton2->Padding = System::Windows::Forms::Padding(0, 15, 0, 0);
			this->rjButton2->Size = System::Drawing::Size(150, 72);
			this->rjButton2->TabIndex = 7;
			this->rjButton2->Text = L"EDIT TEAM";
			this->rjButton2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->rjButton2->TextColor = System::Drawing::Color::Black;
			this->rjButton2->UseVisualStyleBackColor = false;
			this->rjButton2->Click += gcnew System::EventHandler(this, &TeamInformation::rjButton2_Click);
			// 
			// rjButton1
			// 
			this->rjButton1->BackColor = System::Drawing::Color::GhostWhite;
			this->rjButton1->BackgroundColor = System::Drawing::Color::GhostWhite;
			this->rjButton1->BorderColor = System::Drawing::Color::Transparent;
			this->rjButton1->BorderRadius = 40;
			this->rjButton1->BorderSize = 0;
			this->rjButton1->FlatAppearance->BorderSize = 0;
			this->rjButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rjButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rjButton1->ForeColor = System::Drawing::Color::Black;
			this->rjButton1->Location = System::Drawing::Point(170, 243);
			this->rjButton1->Name = L"rjButton1";
			this->rjButton1->Padding = System::Windows::Forms::Padding(0, 15, 0, 0);
			this->rjButton1->Size = System::Drawing::Size(150, 72);
			this->rjButton1->TabIndex = 6;
			this->rjButton1->Text = L"SQUAD";
			this->rjButton1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->rjButton1->TextColor = System::Drawing::Color::Black;
			this->rjButton1->UseVisualStyleBackColor = false;
			this->rjButton1->Click += gcnew System::EventHandler(this, &TeamInformation::rjButton1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox2->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.ErrorImage")));
			this->pictureBox2->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.InitialImage")));
			this->pictureBox2->Location = System::Drawing::Point(72, 21);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(181, 150);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(276, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(161, 32);
			this->label3->TabIndex = 3;
			this->label3->Text = L"EST";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(276, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(249, 60);
			this->label2->TabIndex = 2;
			this->label2->Text = L"TEAM NAME";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackColor = System::Drawing::Color::GreenYellow;
			this->pictureBox1->Location = System::Drawing::Point(945, 21);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(454, 237);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// TeamInformation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1399, 791);
			this->Controls->Add(this->containerPanel);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"TeamInformation";
			this->Text = L"TeamInformation";
			this->containerPanel->ResumeLayout(false);
			this->mainPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void rjButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		TeamDataView^ teamDataView = gcnew TeamDataView(tour, TId);
		ReplaceUserControl(teamDataView);
	}
	private: System::Void SetTeamName()
	{
		label2->Text = gcnew String(tour->find_team_by_id(TId)->get_name().c_str());
		//set color for the label using the dominant color
		Color^ color = ImageHelper::GetDominantColor(( "Resources\\" + gcnew String(tour->find_team_by_id(TId)->get_name().c_str()) + "_BackGround") + ".png");
		label2->BackColor = *color;
		label2->ForeColor = *ImageHelper::GetContrastingColor(*color);
	}
	private: System::Void SetTeamLogo()
	{
		pictureBox2->BackgroundImage = ImageHelper::GetImageResource(gcnew String(tour->find_team_by_id(TId)->get_name().c_str()) + "_logo");
	}
	private: System::Void SetEstablishmentYear()
	{
		label3->Text = "EST:" + tour->find_team_by_id(TId)->get_founded_year().ToString();
		Color^ color = ImageHelper::GetDominantColor(("Resources\\" + gcnew String(tour->find_team_by_id(TId)->get_name().c_str()) + "_BackGround") + ".png");
		label3->BackColor = *color;
		label3->ForeColor = *ImageHelper::GetContrastingColor(*color);
	}
	private: System::Void SetMainPanelBGR()
	{
		mainPanel->BackgroundImage = ImageHelper::GetImageResource(gcnew String(tour->find_team_by_id(TId)->get_name().c_str()) + "_BackGround");
	}
	private: System::Void SetButtonColor()
	{
		Color^ color = ImageHelper::GetDominantColor(("Resources\\" + gcnew String(tour->find_team_by_id(TId)->get_name().c_str()) + "_BackGround") + ".png");
		rjButton1->BackColor = *color;
		rjButton1->BackgroundColor = *color;
		rjButton1->BorderColor = *color;
		rjButton1->ForeColor = *ImageHelper::GetContrastingColor(*color);
	}
	
	private: System::Void rjButton2_Click(System::Object^ sender, System::EventArgs^ e) {

		EditTeam^ editTeam = gcnew EditTeam();
		ReplaceUserControlWithAnimation(editTeam);
		
	}
	private: System::Void ReplaceUserControl(UserControl^ newControl)
	   {
		  
		   for (int i = containerPanel->Controls->Count - 1; i >= 0; i--)
		   {
			   Control^ control = containerPanel->Controls[i];

			  
			   if (dynamic_cast<UserControl^>(control))
			   {
				   
				   containerPanel->Controls->Remove(control);
				   delete control;
			   }
		   }
		   newControl->Dock = System::Windows::Forms::DockStyle::Fill;
		   newControl->Size = System::Drawing::Size(this->containerPanel->ClientSize.Width, this->containerPanel->ClientSize.Height - this->mainPanel->ClientSize.Height);
		   newControl->Location = System::Drawing::Point(0, this->mainPanel->ClientSize.Height);
		   newControl->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom;
		   containerPanel->Controls->Add(newControl);
	   }
	private: System::Void InitializeSlideTimer()
	   {
		   slideTimer = gcnew System::Windows::Forms::Timer();
		   slideTimer->Interval = 10; 
		   slideTimer->Tick += gcnew System::EventHandler(this, &TeamInformation::OnSlideTimerTick);
	   }
	private: System::Void OnSlideTimerTick(System::Object^ sender, System::EventArgs^ e)
		{
		if (slidingControl == nullptr)
		{
			slideTimer->Stop(); 
			return;
		}


		System::Drawing::Point currentLocation = slidingControl->Location;
		int newX = currentLocation.X - 20; 

	
		if (newX <= targetX)
		{
			newX = targetX; 
			slidingControl->Location = System::Drawing::Point(newX, currentLocation.Y); 
			slideTimer->Stop(); 
			slidingControl = nullptr; 
		}
		else
		{
			slidingControl->Location = System::Drawing::Point(newX, currentLocation.Y);
		}
		}
    private: System::Void ReplaceUserControlWithAnimation(UserControl^ newControl)
		{	
				if (slidingControl != nullptr)
				{
					containerPanel->Controls->Remove(slidingControl);  
					delete slidingControl; 
				}

			
			newControl->Dock = System::Windows::Forms::DockStyle::None;
			newControl->Size = System::Drawing::Size(this->containerPanel->ClientSize.Width / 2, this->containerPanel->ClientSize.Height - this->mainPanel->ClientSize.Height);
			newControl->Location = System::Drawing::Point(this->containerPanel->ClientSize.Width,
				this->mainPanel->ClientSize.Height); 
			newControl->Anchor = System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left;
			containerPanel->Controls->Add(newControl);

		
			slidingControl = newControl;
			if (slidingControl == nullptr)
			{
				throw gcnew System::Exception("Sliding control is null");
			}
			targetX = (this->containerPanel->ClientSize.Width - newControl->Width); 

	
			slideTimer->Start();
		}

};
}
