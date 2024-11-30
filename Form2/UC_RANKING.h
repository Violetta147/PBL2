#pragma once
#include "include/Tournament.h"
#include "include/Team.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Resources;
using namespace System::Reflection;


namespace Form2 {

	/// <summary>
	/// Summary for UC_RANKING
	/// </summary>
	public ref class UC_RANKING : public System::Windows::Forms::UserControl
	{
	public:
		UC_RANKING(Tournament* tour)
		{
			InitializeComponent();

			this->Load += gcnew System::EventHandler(this, &Form2::UC_RANKING::UC_RANKING_Load);
			this->Resize += gcnew EventHandler(this, &UC_RANKING::UC_RANKING_Resize);
			this->SetStyle(ControlStyles::DoubleBuffer | ControlStyles::UserPaint | ControlStyles::AllPaintingInWmPaint, true);
			this->UpdateStyles();
			this->tour = tour;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UC_RANKING()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		bool isTableInitialized = false;
		System::ComponentModel::Container^ components;
		TableLayoutPanel^ tableLayoutPanel;
		Tournament* tour;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void InitializeComponent()
		{
			this->SuspendLayout();
			// 
			// UC_RANKING
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Name = L"UC_RANKING";
			this->Padding = System::Windows::Forms::Padding(100, 100, 0, 0);
			this->Size = System::Drawing::Size(992, 661);
			this->ResumeLayout(false);
		}

		void InitializeTableLayout()
		{
			if (isTableInitialized) return;
			isTableInitialized = true;

			this->tableLayoutPanel = gcnew System::Windows::Forms::TableLayoutPanel();
			this->tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel->RowCount = 1;
			this->tableLayoutPanel->ColumnCount = 10;
			this->tableLayoutPanel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel->AutoSize = true;
			this->Controls->Add(this->tableLayoutPanel);
		}

		void AddTableHeaders()
		{
			array<System::String^>^ headers = gcnew array<System::String^> {
				"Position", "Team", "Played", "Won", "Drawn", "Lost", "GF", "GA", "GD", "Points"
			};
			for (int i = 0; i < headers->Length; i++)
			{
				Label^ header = gcnew Label();
				header->Text = headers[i];
				header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				header->Dock = System::Windows::Forms::DockStyle::Fill;
				header->Font = gcnew System::Drawing::Font("Arial", 10, System::Drawing::FontStyle::Bold);
				this->tableLayoutPanel->Controls->Add(header, i, 0);
			}
		}

		void AddTeamData()
		{
			const std::vector<RankingEntry>& ranking = this->tour->getRanking();
			if (ranking.empty())
			{
				Console::WriteLine("No ranking data available.");
				return;
			}
			int row = 1;
			this->tableLayoutPanel->RowCount = ranking.size() + 1;
			for (const RankingEntry& entry : ranking)
			{
				array<System::String^>^ teamData = gcnew array<System::String^> {
					System::Convert::ToString(row), 
						gcnew System::String(entry.team->get_name().c_str()),  
						System::Convert::ToString(entry.team->get_matches()),  // Matches (converted from int to String^)
						System::Convert::ToString(entry.team->get_wins()),  // Wins (converted from int to String^)
						System::Convert::ToString(entry.team->get_ties()),  // Ties (converted from int to String^)
						System::Convert::ToString(entry.team->get_loses()),  // Loses (converted from int to String^)
						System::Convert::ToString(entry.goals),  // Assuming goals is an int and has a ToString() method
						System::Convert::ToString(entry.team->get_goal_conceded()),  // Goal conceded (converted from int to String^)
						System::Convert::ToString(entry.secondary_points),  // Assuming secondary_points is an int and has a ToString() method
						System::Convert::ToString(entry.points)  // Points (assuming points is an int)
				};

				for (int col = 0; col < teamData->Length; col++)
				{
					Label^ cell = gcnew Label();
					cell->Text = teamData[col];
					cell->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					cell->Dock = System::Windows::Forms::DockStyle::Fill;
					this->tableLayoutPanel->Controls->Add(cell, col, row);
				}
				row++;
			}
			for (int i = 1; i <= ranking.size(); i++)
			{
				this->tableLayoutPanel->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 100.0f / (ranking.size() + 1)));
			}
		}

		void UC_RANKING_Load(Object^ sender, EventArgs^ e)
		{
			Console::WriteLine("Load");
			this->SuspendLayout();
			InitializeTableLayout();
			AddTableHeaders();
			AddTeamData();
			this->tableLayoutPanel->ResumeLayout(false);
			this->ResumeLayout(false);
		}


		void UC_RANKING_Resize(Object^ sender, EventArgs^ e)
		{
			Console::WriteLine("Resizing");
			this->SuspendLayout();
			this->tableLayoutPanel->SuspendLayout();
			AdjustTableLayoutSize();
			this->tableLayoutPanel->ResumeLayout(false);
			this->ResumeLayout(false);
		}

		void AdjustTableLayoutSize()
		{
			int columnCount = this->tableLayoutPanel->ColumnCount;
			int rowCount = this->tableLayoutPanel->RowCount;

			for (int i = 0; i < columnCount; ++i)
			{
				this->tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent));
			}
			for (int i = 0; i < rowCount; ++i)
			{
				this->tableLayoutPanel->RowStyles->Add(gcnew RowStyle(SizeType::Percent));
			}
			for (int i = 0; i < columnCount; i++) {
				this->tableLayoutPanel->ColumnStyles[i]->Width = 100.0f / columnCount;
			}

			for (int i = 0; i < rowCount; i++) {
				this->tableLayoutPanel->RowStyles[i]->Height = 100.0f / rowCount;
			}
		}
#pragma endregion
	};
}

inline System::String^ IntToString(int value)
{
	return System::Convert::ToString(value);
}