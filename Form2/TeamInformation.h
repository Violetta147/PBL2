#pragma once
#include "include/Tournament.h"
#include "include/Team.h"
#include "WrapperPlayer.h"

namespace Form2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for TeamInformation
	/// </summary>
	public ref class TeamInformation : public System::Windows::Forms::Form
	{
	public:
		TeamInformation(Tournament* tour)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//initialize years array
			years = gcnew array<String^>(4000 - 1900 + 1);

			for (int i = 1900; i <= 4000; i++) {
				years[i - 1900] = i.ToString();
			}
			foundedYearBox->Items->AddRange(years);
			//2024
			foundedYearBox->SelectedIndex = 124;
			this->tour = tour;
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




		   //array of years as string
		   array<String^>^ years;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ teamNameBox;
	private: System::Windows::Forms::TextBox^ abbreviationBox;
	private: System::Windows::Forms::TextBox^ stadiumBox;
	private: System::Windows::Forms::ComboBox^ foundedYearBox;

	private: System::Windows::Forms::Label^ playerHeader;
	public: Tournament* tour;
	private: System::Windows::Forms::Label^ label6;
	public:
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->abbreviationBox = (gcnew System::Windows::Forms::TextBox());
			this->stadiumBox = (gcnew System::Windows::Forms::TextBox());
			this->foundedYearBox = (gcnew System::Windows::Forms::ComboBox());
			this->teamNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->playerHeader = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1096, 518);
			this->tabControl1->TabIndex = 0;
			this->tabControl1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TeamInformation::tabControl1_MouseClick);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->tableLayoutPanel1);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1088, 492);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Team Information";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->BackColor = System::Drawing::Color::Red;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(652, 430);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(115, 39);
			this->label7->TabIndex = 2;
			this->label7->Text = L"CANCEL";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tableLayoutPanel1.BackgroundImage")));
			this->tableLayoutPanel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::OutsetDouble;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				19.84877F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				80.15123F)));
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->abbreviationBox, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->stadiumBox, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->foundedYearBox, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->teamNameBox, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1002, 414);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::LawnGreen;
			this->label2->Location = System::Drawing::Point(49, 142);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ABBREVIATION";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::LawnGreen;
			this->label3->Location = System::Drawing::Point(52, 245);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 23);
			this->label3->TabIndex = 2;
			this->label3->Text = L"STADIUM";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::LawnGreen;
			this->label4->Location = System::Drawing::Point(42, 348);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(118, 23);
			this->label4->TabIndex = 3;
			this->label4->Text = L"FOUNDED YEAR";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::LawnGreen;
			this->label1->Location = System::Drawing::Point(61, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TEAM NAME";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// abbreviationBox
			// 
			this->abbreviationBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->abbreviationBox->Location = System::Drawing::Point(206, 144);
			this->abbreviationBox->Name = L"abbreviationBox";
			this->abbreviationBox->Size = System::Drawing::Size(507, 20);
			this->abbreviationBox->TabIndex = 5;
			// 
			// stadiumBox
			// 
			this->stadiumBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->stadiumBox->Location = System::Drawing::Point(206, 246);
			this->stadiumBox->Name = L"stadiumBox";
			this->stadiumBox->Size = System::Drawing::Size(507, 20);
			this->stadiumBox->TabIndex = 6;
			// 
			// foundedYearBox
			// 
			this->foundedYearBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->foundedYearBox->FormattingEnabled = true;
			this->foundedYearBox->Location = System::Drawing::Point(206, 349);
			this->foundedYearBox->Name = L"foundedYearBox";
			this->foundedYearBox->Size = System::Drawing::Size(121, 21);
			this->foundedYearBox->TabIndex = 7;
			// 
			// teamNameBox
			// 
			this->teamNameBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->teamNameBox->Location = System::Drawing::Point(206, 42);
			this->teamNameBox->Name = L"teamNameBox";
			this->teamNameBox->Size = System::Drawing::Size(507, 20);
			this->teamNameBox->TabIndex = 4;
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->BackColor = System::Drawing::Color::Lime;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(281, 430);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(100, 39);
			this->label6->TabIndex = 1;
			this->label6->Text = L"OK";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Controls->Add(this->button1);
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Controls->Add(this->playerHeader);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1088, 492);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Players ";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Lime;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(8, 363);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 30);
			this->button1->TabIndex = 3;
			this->button1->Text = L"ADD TO LIST";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TeamInformation::button1_MouseClick);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(550, 31);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(530, 317);
			this->dataGridView2->TabIndex = 2;
			// 
			// playerHeader
			// 
			this->playerHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->playerHeader->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->playerHeader->Location = System::Drawing::Point(3, 3);
			this->playerHeader->Name = L"playerHeader";
			this->playerHeader->Size = System::Drawing::Size(1082, 25);
			this->playerHeader->TabIndex = 0;
			this->playerHeader->Text = L"AVAILABLE PLAYERS";
			this->playerHeader->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(8, 31);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(536, 317);
			this->dataGridView1->TabIndex = 4;
			// 
			// TeamInformation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1096, 591);
			this->Controls->Add(this->tabControl1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1260, 630);
			this->Name = L"TeamInformation";
			this->Text = L"TeamInformation";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion
private: System::Void tabControl1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		
	BindingList<WrapperPlayer^>^ wrappedPlayers = gcnew BindingList<WrapperPlayer^>();
	for (int i = 0; i < tour->get_player_count(); i++)
	{
		Player player = tour->getPlayer(i);
		wrappedPlayers->Add(gcnew WrapperPlayer(&player));
	}

	dataGridView1->AutoGenerateColumns = false;

	// Manually add specific columns to display
	DataGridViewTextBoxColumn^ colPlayerID = gcnew DataGridViewTextBoxColumn();
	colPlayerID->HeaderText = "Player ID";
	colPlayerID->DataPropertyName = "PlayerID";
	dataGridView1->Columns->Add(colPlayerID);

	DataGridViewTextBoxColumn^ colPlayerName = gcnew DataGridViewTextBoxColumn();
	colPlayerName->HeaderText = "Player Name";
	colPlayerName->DataPropertyName = "PlayerName";
	dataGridView1->Columns->Add(colPlayerName);

	DataGridViewTextBoxColumn^ colPosition = gcnew DataGridViewTextBoxColumn();
	colPosition->HeaderText = "Position";
	colPosition->DataPropertyName = "Position";
	dataGridView1->Columns->Add(colPosition);

	DataGridViewTextBoxColumn^ colJerseyNum = gcnew DataGridViewTextBoxColumn();
	colJerseyNum->HeaderText = "Jersey Number";
	colJerseyNum->DataPropertyName = "JerseyNum";
	dataGridView1->Columns->Add(colJerseyNum);

	// Bind the data source
	dataGridView1->DataSource = wrappedPlayers;
}
private: System::Void button1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	BindingList<WrapperPlayer^>^ selectedPlayersForGrid2 = gcnew BindingList<WrapperPlayer^>();

	// Loop through selected rows in DataGridView1
	for each (DataGridViewRow ^ row in dataGridView1->SelectedRows) {

		WrapperPlayer^ selectedPlayer = safe_cast<WrapperPlayer^>(row->DataBoundItem);
		selectedPlayersForGrid2->Add(selectedPlayer);
		//hide the selected player from the available players
		dataGridView1->Rows->Remove(row);
	}
	dataGridView1->Refresh();
	dataGridView2->AutoGenerateColumns = false;
	DataGridViewTextBoxColumn^ colPlayerID = gcnew DataGridViewTextBoxColumn();
	colPlayerID->HeaderText = "Player ID";
	colPlayerID->DataPropertyName = "PlayerID";
	dataGridView2->Columns->Add(colPlayerID);

	DataGridViewTextBoxColumn^ colPlayerName = gcnew DataGridViewTextBoxColumn();
	colPlayerName->HeaderText = "Player Name";
	colPlayerName->DataPropertyName = "PlayerName";
	dataGridView2->Columns->Add(colPlayerName);

	DataGridViewTextBoxColumn^ colPosition = gcnew DataGridViewTextBoxColumn();
	colPosition->HeaderText = "Position";
	colPosition->DataPropertyName = "Position";
	dataGridView2->Columns->Add(colPosition);

	DataGridViewTextBoxColumn^ colJerseyNum = gcnew DataGridViewTextBoxColumn();
	colJerseyNum->HeaderText = "Jersey Number";
	colJerseyNum->DataPropertyName = "JerseyNum";
	dataGridView2->Columns->Add(colJerseyNum);

	dataGridView2->DataSource = selectedPlayersForGrid2;
}
};
}
