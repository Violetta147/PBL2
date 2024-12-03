#pragma once
#include "include/Tournament.h"
#include "include/Team.h"
#include "ImageHelper.h"
#include "CustomControl.h"

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
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = false;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"UC_RANKING";
			this->Size = System::Drawing::Size(844, 487);
			this->ResumeLayout(false);

		}

		void InitializeTableLayout()
		{
			if (isTableInitialized) return;
			isTableInitialized = true;

			this->tableLayoutPanel = gcnew System::Windows::Forms::TableLayoutPanel();
			this->tableLayoutPanel->SuspendLayout();
			this->tableLayoutPanel->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel->RowCount = 1;
			this->tableLayoutPanel->ColumnCount = 10;
			this->tableLayoutPanel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::None;
			this->tableLayoutPanel->AutoSize = false;
			this->tableLayoutPanel->Size = this->ClientSize;
			this->tableLayoutPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel->Dock = DockStyle::None;
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
				if (i != 1)
					header->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				else
					header->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				header->BackColor = System::Drawing::Color::LightGray;
				header->ForeColor = System::Drawing::Color::Black;
				header->Margin = System::Windows::Forms::Padding(0);
				header->Dock = System::Windows::Forms::DockStyle::Fill;
				header->Font = gcnew System::Drawing::Font("Arial", 10, System::Drawing::FontStyle::Regular);
				header->Paint += gcnew PaintEventHandler(this, &UC_RANKING::DrawCustomBorder);
				this->tableLayoutPanel->Controls->Add(header, i, 0);
			}
		}

		void DrawCustomBorder(Object^ object, PaintEventArgs^ e)
		{
			Label^ label = safe_cast<Label^>(object);
			System::Drawing::Graphics^ g = e->Graphics;
			System::Drawing::Pen^ topPen = gcnew System::Drawing::Pen(System::Drawing::Color::Gray, 0.5);
			System::Drawing::Pen^ bottomPen = gcnew System::Drawing::Pen(System::Drawing::Color::DarkGray, 1.5);

			System::Drawing::Rectangle rect = label->ClientRectangle;

			g->DrawLine(topPen, rect.Left, rect.Top, rect.Right, rect.Top);
			g->DrawLine(bottomPen, rect.Left, rect.Bottom - 1, rect.Right, rect.Bottom - 1);
		}
		void AddTeamData()
		{
			const std::vector<RankingEntry>& ranking = this->tour->getRanking();
			if (ranking.empty())
			{
				MessageBox::Show("No ranking data available.", "No Data", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			int row = 1;
			this->tableLayoutPanel->RowCount = ranking.size() + 1;  // Add header row
			for (const RankingEntry& entry : ranking)
			{
				array<System::String^>^ teamData = gcnew array<System::String^> {
					System::Convert::ToString(row),
						gcnew System::String(entry.team->get_name().c_str()),
						System::Convert::ToString(entry.team->get_matches()),
						System::Convert::ToString(entry.team->get_wins()),
						System::Convert::ToString(entry.team->get_ties()),
						System::Convert::ToString(entry.team->get_loses()),
						System::Convert::ToString(entry.goals),
						System::Convert::ToString(entry.team->get_goal_conceded()),
						System::Convert::ToString(entry.secondary_points),
						System::Convert::ToString(entry.points)
				};
				for (int col = 0; col < teamData->Length; col++)
				{
					Label^ cell = gcnew Label();
					cell->Margin = System::Windows::Forms::Padding(0);
					cell->Text = teamData[col];
					cell->BackColor = System::Drawing::Color::WhiteSmoke;
					if (col == 0)
					{
						if (row == 1)
							cell->ForeColor = System::Drawing::Color::Gold;
						else if (row == 2)
							cell->ForeColor = System::Drawing::Color::Silver;
						else if (row == 3)
							cell->ForeColor = System::Drawing::Color::Firebrick;
						else
							cell->ForeColor = System::Drawing::Color::Gray;
					}
					else
					{
						if (col == 1 || col == teamData->Length - 1)
						{
							cell->ForeColor = System::Drawing::Color::Black;
						}
						else
							cell->ForeColor = System::Drawing::Color::Gray;
					}
					cell->Font = gcnew System::Drawing::Font("Arial", 12, System::Drawing::FontStyle::Bold);
					cell->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
						if (col == teamData->Length - 1)
							cell->Font = gcnew System::Drawing::Font("Arial", 10, System::Drawing::FontStyle::Bold);

					cell->Dock = System::Windows::Forms::DockStyle::Fill;
					cell->Paint += gcnew PaintEventHandler(this, &UC_RANKING::DrawCustomBorder);
					if (col == 1)
					{

						std::string resourceName = entry.team->get_name() + "_logo";
						cell->Image = ImageHelper::GetImageResource(gcnew String(resourceName.c_str()));
						cell->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
						cell->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
						cell->MouseEnter += gcnew EventHandler(this, &UC_RANKING::OnMouseEnterName);
						cell->MouseLeave += gcnew EventHandler(this, &UC_RANKING::OnMouseLeaveName);
						cell->Click += gcnew EventHandler(this, &UC_RANKING::OnNameClick);
					}	
						this->tableLayoutPanel->Controls->Add(cell, col, row);
				}

				row++;
			}

			// Add row styles dynamically based on the number of rows
			for (int i = 1; i <= ranking.size(); i++)
			{
				this->tableLayoutPanel->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 40));
			}
		}


		void UC_RANKING_Load(Object^ sender, EventArgs^ e)
		{
			if (!isTableInitialized) {
				this->SuspendLayout();
				InitializeTableLayout();
				this->tableLayoutPanel->AutoScroll = true;
				Form^ mainForm = this->FindForm();
				MenuStrip^ MAINBUTTON = dynamic_cast<MenuStrip^>(mainForm->Controls["MAINBUTTON"]);
				this->Size = System::Drawing::Size(mainForm->ClientSize.Width, mainForm->ClientSize.Height - MAINBUTTON->Height);
				this->Location = System::Drawing::Point(0, MAINBUTTON->Height);
				this->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
				AddTableHeaders();
				AddTeamData();
				AdjustTableLayoutSize();
				this->tableLayoutPanel->ResumeLayout(false);
				this->ResumeLayout(false);
				this->tableLayoutPanel->PerformLayout();
				this->PerformLayout();
				isTableInitialized = true;
			}
		}

		void UC_RANKING_Resize(Object^ sender, EventArgs^ e)
		{
			Console::WriteLine("Resizing");
			this->SuspendLayout();
			this->tableLayoutPanel->SuspendLayout();
			AdjustTableLayoutSize();
			this->tableLayoutPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->tableLayoutPanel->PerformLayout();
			this->PerformLayout();
		}


		void AdjustTableLayoutSize()
		{
			int columnCount = this->tableLayoutPanel->ColumnCount;
			int rowCount = this->tableLayoutPanel->RowCount;

			// Clear existing styles to avoid accumulation
			this->tableLayoutPanel->ColumnStyles->Clear();
			this->tableLayoutPanel->RowStyles->Clear();

			// Apply fixed percentage widths to columns
			for (int i = 0; i < columnCount; ++i)
			{
				if (i != 1)
					this->tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 100.0f / (columnCount + 1)));
				if (i == 1) {
					this->tableLayoutPanel->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 200.0f / (columnCount + 1)));
				}
			}

			// Apply fixed percentage heights to rows
			Console::WriteLine(this->tableLayoutPanel->Height);
			for (int i = 0; i <= rowCount; ++i)
			{
				this->tableLayoutPanel->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 50)); // +1 for header row //somhow change from 40 to 50 fix it
			}

			// Set the table layout to fixed size, but make sure it fits within UserControl
			this->tableLayoutPanel->AutoSize = false;
			this->tableLayoutPanel->MinimumSize = System::Drawing::Size(0, 0);  // Set minimum size if needed

			// Ensure that the table is resized based on the UserControl's size
			// If the number of rows is too large, allow scroll bar to appear
			this->tableLayoutPanel->Size = System::Drawing::Size(this->ClientSize);

			//this->tableLayoutPanel->AutoScroll = this->tableLayoutPanel->Height > this->ClientSize.Height;
		}

		void OnMouseEnterName(Object^ sender, EventArgs^ e)
		{
			Label^ label = safe_cast<Label^>(sender);
			label->Font = gcnew System::Drawing::Font(
				label->Font,
				label->Font->Style | FontStyle::Underline
			);
		}

		void OnMouseLeaveName(Object^ sender, EventArgs^ e)
		{
			Label^ label = safe_cast<Label^>(sender);
			label->Font = gcnew System::Drawing::Font("Arial", 12, System::Drawing::FontStyle::Bold);
		}

		void OnNameClick(Object^ sender, EventArgs^ e)
		{
			Label^ label = safe_cast<Label^>(sender);
			MessageBox::Show("You clicked on: " + label->Text);
		}

	};
}