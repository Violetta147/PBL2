#pragma once
#include "include/Tournament.h"
#include "WrapperPlayer.h"
#include "NewPlayer.h"
#include "ImageHelper.h"
#include "CustomControl.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Form2 {

	/// <summary>
	/// Summary for TeamDataView
	/// </summary>
	public ref class TeamDataView : public System::Windows::Forms::UserControl
	{
	public:
		TeamDataView(Tournament* tour, int TID)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->tour = tour;
			this->TId = TID;
			// Load players and apply grouping
			LoadTeamPlayers();
			this->dataGridView1->RowPrePaint += gcnew System::Windows::Forms::DataGridViewRowPrePaintEventHandler(this, &TeamDataView::dataGridView1_RowPrePaint);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TeamDataView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: Tournament* tour;
	private: int TId;
	private: BindingList<WrapperPlayer^>^ playerList;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PlayerName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ JerseyNum;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ POS;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ GOAL;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ASSIST;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ REDCARD;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ YELLOWCARD;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MATCH;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ ISBAN;
	protected:

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->PID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PlayerName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->JerseyNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->POS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GOAL = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ASSIST = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->REDCARD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->YELLOWCARD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MATCH = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ISBAN = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::Silver;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::LawnGreen;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::ControlDark;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::ControlLightLight;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeight = 60;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->PID, this->PlayerName,
					this->JerseyNum, this->POS, this->GOAL, this->ASSIST, this->REDCARD, this->YELLOWCARD, this->MATCH, this->ISBAN
			});
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(0);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->RowHeadersVisible = false;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(1399, 498);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TeamDataView::dataGridView1_CellClick);
			// 
			// PID
			// 
			this->PID->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			this->PID->DefaultCellStyle = dataGridViewCellStyle2;
			this->PID->HeaderText = L"PLAYER ID";
			this->PID->Name = L"PID";
			this->PID->ReadOnly = true;
			this->PID->ToolTipText = L"###";
			this->PID->Width = 115;
			// 
			// PlayerName
			// 
			this->PlayerName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->PlayerName->HeaderText = L"NAME";
			this->PlayerName->Name = L"PlayerName";
			this->PlayerName->ReadOnly = true;
			// 
			// JerseyNum
			// 
			this->JerseyNum->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->JerseyNum->HeaderText = L"JERSEY";
			this->JerseyNum->Name = L"JerseyNum";
			this->JerseyNum->ReadOnly = true;
			this->JerseyNum->Width = 102;
			// 
			// POS
			// 
			this->POS->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->POS->FillWeight = 60;
			this->POS->HeaderText = L"POSITION";
			this->POS->Name = L"POS";
			this->POS->ReadOnly = true;
			// 
			// GOAL
			// 
			this->GOAL->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->GOAL->FillWeight = 30;
			this->GOAL->HeaderText = L"GOAL";
			this->GOAL->Name = L"GOAL";
			this->GOAL->ReadOnly = true;
			// 
			// ASSIST
			// 
			this->ASSIST->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ASSIST->FillWeight = 30;
			this->ASSIST->HeaderText = L"ASSIST";
			this->ASSIST->Name = L"ASSIST";
			this->ASSIST->ReadOnly = true;
			// 
			// REDCARD
			// 
			this->REDCARD->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->REDCARD->FillWeight = 30;
			this->REDCARD->HeaderText = L"RED CARD";
			this->REDCARD->Name = L"REDCARD";
			this->REDCARD->ReadOnly = true;
			// 
			// YELLOWCARD
			// 
			this->YELLOWCARD->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::White;
			this->YELLOWCARD->DefaultCellStyle = dataGridViewCellStyle3;
			this->YELLOWCARD->FillWeight = 30;
			this->YELLOWCARD->HeaderText = L"YELLOW CARD";
			this->YELLOWCARD->Name = L"YELLOWCARD";
			this->YELLOWCARD->ReadOnly = true;
			// 
			// MATCH
			// 
			this->MATCH->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->MATCH->FillWeight = 30;
			this->MATCH->HeaderText = L"MATCH PLAYED";
			this->MATCH->Name = L"MATCH";
			this->MATCH->ReadOnly = true;
			// 
			// ISBAN
			// 
			this->ISBAN->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->ISBAN->HeaderText = L"IS BAN";
			this->ISBAN->Name = L"ISBAN";
			this->ISBAN->ReadOnly = true;
			this->ISBAN->Width = 65;
			// 
			// TeamDataView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"TeamDataView";
			this->Size = System::Drawing::Size(1399, 498);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
		void LoadTeamPlayers()
		{	
			playerList = gcnew BindingList<WrapperPlayer^>();
			for (int i = 0; i < tour->get_player_count(); ++i)
			{
				if (tour->getPlayer(i).getTId() == TId)
				{
					playerList->Add(gcnew WrapperPlayer(&tour->getPlayer(i)));
				}
			}
			dataGridView1->AutoGenerateColumns = false;
			dataGridView1->Columns["PID"]->DataPropertyName = "PlayerID";
			dataGridView1->Columns["PlayerName"]->DataPropertyName = "PlayerName";
			dataGridView1->Columns["JerseyNum"]->DataPropertyName = "JerseyNum";
			dataGridView1->Columns["POS"]->DataPropertyName = "Position";
			dataGridView1->Columns["GOAL"]->DataPropertyName = "Goal";
			dataGridView1->Columns["ASSIST"]->DataPropertyName = "Assist";
			dataGridView1->Columns["REDCARD"]->DataPropertyName = "RedCard";
			dataGridView1->Columns["YELLOWCARD"]->DataPropertyName = "YellowCard";
			dataGridView1->Columns["MATCH"]->DataPropertyName = "Match";
			dataGridView1->Columns["ISBAN"]->DataPropertyName = "IsBan";
			dataGridView1->DataSource = playerList; 
		}
		void dataGridView1_RowPrePaint(Object^ sender, System::Windows::Forms::DataGridViewRowPrePaintEventArgs^ e)
		{	
			//retrieve the control in parent panel
			Form^ parentForm = dynamic_cast<Form^>(this->Parent->Parent);
			Console::WriteLine(parentForm->Name);
			if (parentForm != nullptr)
			{	
				Control^ control = parentForm->Controls->Find("mainPanel", true)[0];
				Console::WriteLine(control->Name);
				Label^ NameButton = dynamic_cast<Label^>(control->Controls->Find("label2", true)[0]);
				Console::WriteLine(NameButton->Name);
				//Set the color of header the same as the button back color
				this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = NameButton->BackColor;
				this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = NameButton->ForeColor;
				if (e->RowIndex % 2 == 0)
				{
					this->dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->BackColor = NameButton->BackColor;
					this->dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->ForeColor = NameButton->ForeColor;
				}
				else
				{
					this->dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->BackColor = *ImageHelper::LightenColor(NameButton->BackColor, 0.2f);
					this->dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->ForeColor = NameButton->ForeColor;
				}
			}
			else
			{	
				// Determine the alternating color
				Color primaryColor = Color::LightBlue;
				Color secondaryColor = Color::LightCyan;

				// Alternate rows
				if (e->RowIndex % 2 == 0)
				{
					this->dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->BackColor = primaryColor;
					this->dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->ForeColor = Color::Black;
				}
				else
				{
					this->dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->BackColor = secondaryColor;
					this->dataGridView1->Rows[e->RowIndex]->DefaultCellStyle->ForeColor = Color::Black;
				}
				this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = Color::LightGray;
				this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = Color::Black;
			}
		}

#pragma endregion
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) // Check if row is valid
		{
			//// Get the row information
			WrapperPlayer^ selectedPlayer = (WrapperPlayer^)dataGridView1->Rows[e->RowIndex]->DataBoundItem;

			//Open form
			NewPlayer^ newPlayer = gcnew NewPlayer(tour, selectedPlayer->TeamID + "|" + selectedPlayer->PlayerID);
			newPlayer->Owner = this->FindForm(); 
			newPlayer->FormClosed += gcnew FormClosedEventHandler(this, &TeamDataView::NewPlayer_FormClosed);
			newPlayer->ShowDialog();
		}
	}
	private: System::Void NewPlayer_FormClosed(System::Object ^ sender, FormClosedEventArgs ^ e) {
		LoadTeamPlayers();
	}
};
}
