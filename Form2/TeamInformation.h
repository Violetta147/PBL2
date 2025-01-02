#pragma once
#include "include/Tournament.h"
#include "WrapperPlayer.h"
#include "TeamDataView.h"



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
	private: CustomControls::RJButton^ rjButton1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

		   Tournament* tour;
		   int TId;
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
			this->containerPanel = (gcnew System::Windows::Forms::Panel());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->rjButton1 = (gcnew CustomControls::RJButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->containerPanel->SuspendLayout();
			this->mainPanel->SuspendLayout();
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
			this->mainPanel->Controls->Add(this->rjButton1);
			this->mainPanel->Controls->Add(this->label3);
			this->mainPanel->Controls->Add(this->label2);
			this->mainPanel->Controls->Add(this->label1);
			this->mainPanel->Controls->Add(this->pictureBox1);
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->mainPanel->Location = System::Drawing::Point(0, 0);
			this->mainPanel->Margin = System::Windows::Forms::Padding(0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(1399, 293);
			this->mainPanel->TabIndex = 0;
			// 
			// rjButton1
			// 
			this->rjButton1->BackColor = System::Drawing::Color::Lavender;
			this->rjButton1->BackgroundColor = System::Drawing::Color::Lavender;
			this->rjButton1->BorderColor = System::Drawing::Color::PaleVioletRed;
			this->rjButton1->BorderRadius = 40;
			this->rjButton1->BorderSize = 0;
			this->rjButton1->FlatAppearance->BorderSize = 0;
			this->rjButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rjButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rjButton1->ForeColor = System::Drawing::Color::Black;
			this->rjButton1->Location = System::Drawing::Point(129, 241);
			this->rjButton1->Name = L"rjButton1";
			this->rjButton1->Padding = System::Windows::Forms::Padding(0, 15, 0, 0);
			this->rjButton1->Size = System::Drawing::Size(150, 77);
			this->rjButton1->TabIndex = 4;
			this->rjButton1->Text = L"SQUAD";
			this->rjButton1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->rjButton1->TextColor = System::Drawing::Color::Black;
			this->rjButton1->UseVisualStyleBackColor = false;
			this->rjButton1->Click += gcnew System::EventHandler(this, &TeamInformation::rjButton1_Click);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Lime;
			this->label3->Location = System::Drawing::Point(277, 101);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(108, 32);
			this->label3->TabIndex = 3;
			this->label3->Text = L"EST";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Lime;
			this->label2->Location = System::Drawing::Point(277, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(249, 60);
			this->label2->TabIndex = 2;
			this->label2->Text = L"TEAM NAME";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(79, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(168, 144);
			this->label1->TabIndex = 1;
			this->label1->Text = L"LOGO";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void rjButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	//open user control teamdataview
	TeamDataView^ teamDataView = gcnew TeamDataView(tour, TId);
	teamDataView->Dock = System::Windows::Forms::DockStyle::Fill;
	teamDataView->Location = System::Drawing::Point(0, this->mainPanel->ClientSize.Height);
	teamDataView->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom;
	containerPanel->Controls->Add(teamDataView);
}
	private: System::Void SetTeamName()
	{
		label2->Text = gcnew String(tour->getTeam(TId).getTName().c_str());
	}
};
}
