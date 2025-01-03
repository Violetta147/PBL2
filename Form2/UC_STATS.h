#pragma once
#include "include/Tournament.h"
#include "include/Team.h"
#include "include/Player.h"
#include "ImageHelper.h"
#include "Ultility.h"
#include "CustomControl.h"

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Form2 {

	/// <summary>
	/// Summary for MyUserControl
	/// </summary>
	public ref class UC_STATS : public System::Windows::Forms::UserControl
	{
	public:
		UC_STATS(Tournament* tour)
		{
			InitializeComponent();

			this->Load += gcnew System::EventHandler(this, &Form2::UC_STATS::UC_STATS_Load);
			this->Resize += gcnew EventHandler(this, &UC_STATS::UC_STATS_Resize);
			this->SetStyle(ControlStyles::DoubleBuffer | ControlStyles::UserPaint | ControlStyles::AllPaintingInWmPaint, true);
			this->UpdateStyles();
			this->tour = tour;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UC_STATS()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ FilterPanel;
	protected:

	private: System::Windows::Forms::Label^ Circular;
	private: System::Windows::Forms::Label^ Player_stat;
		   bool isPlayerStatClicked = false;
	private: System::Windows::Forms::Label^ Team_stat;
		   bool isTeamStatClicked = false;
		   TableLayoutPanel^ rankingTable;
		   Button^ btnPrevious;
		   Button^ btnNext;
		   Button^ btnFirst;
		   Button^ btnLast;
		   Label^ lblPage;
		   int currentPage;
		   int itemsPerPage;
		   int numPage;
		   int t;
		   System::Collections::Generic::List<System::Windows::Forms::ComboBox^>^ dynamicComboBoxes;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::Windows::Forms::Panel^ rankingPanel;
		System::ComponentModel::Container^ components;
		Tournament* tour;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void ClearDynamicComboBoxes() {
			for each (System::Windows::Forms::ComboBox ^ comboBox in this->dynamicComboBoxes) {
				if (comboBox->Parent != nullptr) {
					comboBox->Parent->Controls->Remove(comboBox);
				}
			}
			this->dynamicComboBoxes->Clear();
		}


		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UC_STATS::typeid));
			this->FilterPanel = (gcnew System::Windows::Forms::Panel());
			this->Team_stat = (gcnew System::Windows::Forms::Label());
			this->Player_stat = (gcnew System::Windows::Forms::Label());
			this->Circular = (gcnew System::Windows::Forms::Label());
			this->FilterPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// FilterPanel
			// 
			this->FilterPanel->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->FilterPanel->Controls->Add(this->Team_stat);
			this->FilterPanel->Controls->Add(this->Player_stat);
			this->FilterPanel->Controls->Add(this->Circular);
			this->FilterPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->FilterPanel->Location = System::Drawing::Point(0, 0);
			this->FilterPanel->Name = L"FilterPanel";
			this->FilterPanel->Size = System::Drawing::Size(1680, 103);
			this->FilterPanel->TabIndex = 0;
			// 
			// Team_stat
			// 
			// Khởi tạo rankingPanel

			this->rankingPanel = (gcnew System::Windows::Forms::Panel());
			this->rankingPanel->Dock = System::Windows::Forms::DockStyle::Fill; // Đặt để lấp đầy phần còn lại bên dưới FilterPanel
			this->rankingPanel->AutoScroll = false; // Kích hoạt thanh cuộn nếu nội dung quá dài

			// Khởi tạo rankingTable
			this->rankingTable = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->rankingTable->Dock = System::Windows::Forms::DockStyle::Top; // Căn trên cùng
			this->rankingTable->AutoSize = false; // Tự động thay đổi kích thước theo nội dung

			// Thêm rankingTable vào rankingPanel
			this->rankingPanel->Controls->Add(this->rankingTable);

			// Thêm rankingPanel và FilterPanel vào UC_STATS
			this->Controls->Add(this->rankingPanel);
			this->Controls->Add(this->FilterPanel);


			this->Team_stat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->Team_stat->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->Team_stat->ForeColor = System::Drawing::Color::Black;
			this->Team_stat->Location = System::Drawing::Point(366, 63);
			this->Team_stat->Name = L"Team_stat";
			this->Team_stat->Size = System::Drawing::Size(158, 40);
			this->Team_stat->TabIndex = 2;
			this->Team_stat->Tag = L"0";
			this->Team_stat->Text = L"Teams Stats";
			this->Team_stat->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Team_stat->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &UC_STATS::Team_stat_MouseClick);
			this->Team_stat->MouseLeave += gcnew System::EventHandler(this, &UC_STATS::Team_stat_MouseLeave);
			this->Team_stat->MouseHover += gcnew System::EventHandler(this, &UC_STATS::Team_stat_MouseHover);
			// 
			// Player_stat
			// 
			this->Player_stat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Player_stat->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->Player_stat->ForeColor = System::Drawing::Color::Black;
			this->Player_stat->Location = System::Drawing::Point(172, 63);
			this->Player_stat->Name = L"Player_stat";
			this->Player_stat->Size = System::Drawing::Size(158, 40);
			this->Player_stat->TabIndex = 1;
			this->Player_stat->Tag = L"0";
			this->Player_stat->Text = L"Players Stats";
			this->Player_stat->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Player_stat->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &UC_STATS::Player_stat_MouseClick);
			this->Player_stat->MouseLeave += gcnew System::EventHandler(this, &UC_STATS::Player_stat_MouseLeave);
			this->Player_stat->MouseHover += gcnew System::EventHandler(this, &UC_STATS::Player_stat_MouseHover);
			// 
			// Circular
			// 
			this->Circular->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->Circular->BackColor = System::Drawing::Color::Transparent;
			this->Circular->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Circular->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Circular.Image")));
			this->Circular->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Circular->Location = System::Drawing::Point(22, 14);
			this->Circular->Name = L"Circular";
			this->Circular->Size = System::Drawing::Size(120, 80);
			this->Circular->TabIndex = 0;
			this->Circular->Text = L"Reset filter";
			this->Circular->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->Circular->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &UC_STATS::Circular_MouseClick);

			//// TableLayoutPanel để hiển thị bảng xếp hạng
			this->rankingTable = gcnew TableLayoutPanel();
			this->rankingTable->BackColor = System::Drawing::Color::AliceBlue;
			this->rankingTable->Location = System::Drawing::Point(0, 103);
			this->rankingTable->Size = System::Drawing::Size(this->ClientSize.Width, this->ClientSize.Height - 103);
			this->rankingTable->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::None;
			this->rankingTable->AutoSize = false;
			this->rankingTable->AutoScroll = true;
			this->rankingTable->Visible = false;
			this->rankingTable->Size = this->ClientSize;
			this->rankingTable->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->rankingTable->Dock = DockStyle::Fill;

			//// Nút Previous
			this->btnPrevious = gcnew Button();
			this->btnPrevious->Text = "Previous";
			this->btnPrevious->Size = System::Drawing::Size(150, 40);
			this->btnPrevious->Location = System::Drawing::Point(150, 12);
			this->btnPrevious->Click += gcnew EventHandler(this, &UC_STATS::OnPreviousClicked);
			this->btnPrevious->Visible = false;

			//// Nút First
			this->btnFirst = gcnew Button();
			this->btnFirst->Text = "First";
			this->btnFirst->Size = System::Drawing::Size(120, 40);
			this->btnFirst->Location = System::Drawing::Point(20, 12);
			this->btnFirst->Click += gcnew EventHandler(this, &UC_STATS::OnFirstClicked);
			this->btnFirst->Visible = false;

			//// Nút Next
			this->btnNext = gcnew Button();
			this->btnNext->Text = "Next";
			this->btnNext->Location = System::Drawing::Point(450, 12);
			this->btnNext->Size = System::Drawing::Size(150, 40);
			this->btnNext->Click += gcnew EventHandler(this, &UC_STATS::OnNextClicked);
			this->btnNext->Visible = false;

			//// Nút Next
			this->btnLast = gcnew Button();
			this->btnLast->Text = "Last";
			this->btnLast->Location = System::Drawing::Point(610, 12);
			this->btnLast->Size = System::Drawing::Size(120, 40);
			this->btnLast->Click += gcnew EventHandler(this, &UC_STATS::OnLastClicked);
			this->btnLast->Visible = false;

			//// Label hiển thị trang hiện tại
			this->lblPage = gcnew Label();
			this->lblPage->Location = System::Drawing::Point(300, 12);
			this->lblPage->Size = System::Drawing::Size(150, 40);
			this->lblPage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblPage->Visible = false;
			this->lblPage->ForeColor = System::Drawing::Color::MediumBlue;
			this->lblPage->Font = gcnew System::Drawing::Font("Arial", 12, System::Drawing::FontStyle::Italic);
			this->lblPage->BackColor = System::Drawing::Color::AliceBlue;

			//// Thêm các thành phần vào Form
			this->rankingPanel->Controls->Add(this->rankingTable);
			this->rankingPanel->Controls->Add(this->btnPrevious);
			this->rankingPanel->Controls->Add(this->btnNext);
			this->rankingPanel->Controls->Add(this->btnLast);
			this->rankingPanel->Controls->Add(this->btnFirst);
			this->rankingPanel->Controls->Add(this->lblPage);

			//// Khởi tạo giá trị
			this->currentPage = 0;
			this->numPage = 0;
			this->itemsPerPage = 10;
			this->dynamicComboBoxes = gcnew System::Collections::Generic::List<System::Windows::Forms::ComboBox^>();


			// 
			// UC_STATS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Silver;
			this->Controls->Add(this->FilterPanel);
			this->AutoScroll = false;
			this->DoubleBuffered = true;
			this->Location = System::Drawing::Point(0, 90);
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"UC_STATS";
			this->Size = System::Drawing::Size(1680, 775);
			this->Load += gcnew System::EventHandler(this, &UC_STATS::UC_STATS_Load);
			this->FilterPanel->ResumeLayout(false);
			this->ResumeLayout(false);

			this->btnNext->BringToFront();
			this->btnPrevious->BringToFront();
			this->btnFirst->BringToFront();
			this->btnLast->BringToFront();
			this->lblPage->BringToFront();
		}

		void UC_STATS_Resize(Object^ sender, EventArgs^ e)
		{
			Console::WriteLine("Resizing");
			this->SuspendLayout();
			/*if (this->rankingPanel->ClientSize.Width > 0) {
				this->rankingTable->Width = this->rankingPanel->ClientSize.Width;
			}*/
			if (isPlayerStatClicked == true) {
				AdjustRankingPlayerTableLayout();
			}
			if (isTeamStatClicked == true) {
				AdjustRankingTeamTableLayout();
			}
			this->ResumeLayout(false);
			/*this->tableLayoutPanel->PerformLayout();*/
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void UC_STATS_Load(System::Object^ sender, System::EventArgs^ e) {
		this->SuspendLayout();
		Form^ mainForm = this->FindForm();
		this->rankingTable->AutoScroll = true;
		MenuStrip^ MAINBUTTON = dynamic_cast<MenuStrip^>(mainForm->Controls["MAINBUTTON"]);
		this->Size = System::Drawing::Size(mainForm->ClientSize.Width, mainForm->ClientSize.Height - MAINBUTTON->Height);
		this->Location = System::Drawing::Point(0, MAINBUTTON->Height);
		this->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
		this->ResumeLayout(false);
		this->PerformLayout();
	}
	private: System::Void Team_stat_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Xóa các bộ lọc cũ nếu đã có
		// Xóa các bộ lọc cũ nếu đã có
		if (isTeamStatClicked == true) return;
		currentPage = 0;

		ClearDynamicComboBoxes();
		ClearPanelFromX(this->FilterPanel, 600);
		this->rankingTable->Controls->Clear(); // Xóa tất cả các điều khiển trong bảng
		this->rankingTable->RowStyles->Clear(); // Xóa các hàng
		this->rankingTable->ColumnStyles->Clear(); // Xóa các cột
		this->rankingTable->RowCount = 0; // Đặt lại số lượng hàng
		this->rankingTable->ColumnCount = 0; // Đặt lại số lượng cột
		isPlayerStatClicked = false;
		isTeamStatClicked = true;
		this->Player_stat->BackColor = System::Drawing::SystemColors::InactiveCaption;
		this->Player_stat->ForeColor = System::Drawing::Color::Black;
		System::Windows::Forms::Label^ label1 = dynamic_cast<System::Windows::Forms::Label^>(this->Player_stat);
		if (label1->Height - 40 > 0) {
			label1->Top += 40;
			label1->Height -= 40;
		}

		// Change Player stat
		this->Team_stat->BackColor = System::Drawing::SystemColors::HotTrack;
		this->Team_stat->ForeColor = System::Drawing::Color::Black;
		System::Windows::Forms::Label^ label2 = dynamic_cast<System::Windows::Forms::Label^>(sender);
		label2->Top -= 40;
		label2->Height += 40;

		// Danh sách các nhãn cho các ComboBox
		cli::array<String^>^ filterLabels = gcnew cli::array<String^> {
			"Filter by Stat Type"
		};

		// Vị trí Y ban đầu cho ComboBox
		int startX = 500;
		int spacing = 160; // Khoảng cách giữa các ComboBox

		for (int i = 0; i < filterLabels->Length; i++) {
			// Tạo nhãn (Label) cho ComboBox
			System::Windows::Forms::Label^ label = gcnew System::Windows::Forms::Label();
			label->BackColor = System::Drawing::Color::Transparent;
			label->Text = filterLabels[i];
			label->Location = System::Drawing::Point(startX + i * spacing, 20);
			label->Size = System::Drawing::Size(100, 20);
			this->FilterPanel->Controls->Add(label);

			// Tạo ComboBox mới
			System::Windows::Forms::ComboBox^ comboBox = gcnew System::Windows::Forms::ComboBox();
			comboBox->Location = System::Drawing::Point(startX + i * spacing, 40);
			comboBox->Name = L"FilterComboBox" + i;
			comboBox->Size = System::Drawing::Size(120, 50);
			comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

			comboBox->SuspendLayout();

			// Thêm các mục cho từng ComboBox
			if (i == 0) {
				comboBox->Items->AddRange(gcnew cli::array<System::Object^> {
					"Goals Scored",
						"Goals Conceded",
						"Wins",
						"Loses"
				});
			}

			// Gán sự kiện thay đổi giá trị cho ComboBox
			comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &UC_STATS::FilterComboBox_SelectedIndexChanged);

			// Thêm ComboBox vào FilterPanel
			this->FilterPanel->Controls->Add(comboBox);
			this->dynamicComboBoxes->Add(comboBox);
			comboBox->SelectedIndex = 0;
			comboBox->ResumeLayout();
		}
	}
	private: System::Void Team_stat_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		if (isTeamStatClicked == false) {
			this->Team_stat->BackColor = System::Drawing::SystemColors::HotTrack;
			System::Windows::Forms::Label^ label = dynamic_cast<System::Windows::Forms::Label^>(sender);

			System::Drawing::FontStyle style = label->Font->Style;

			if ((style & System::Drawing::FontStyle::Bold) == static_cast<System::Drawing::FontStyle>(0)) {
				style = style | System::Drawing::FontStyle::Bold;
			}

			if ((style & System::Drawing::FontStyle::Italic) == static_cast<System::Drawing::FontStyle>(0)) {
				style = style | System::Drawing::FontStyle::Italic;
			}
			label->Font = gcnew System::Drawing::Font(label->Font, style);
		}
	}
	private: System::Void Team_stat_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		if (isTeamStatClicked == true) return;
		this->Team_stat->BackColor = System::Drawing::SystemColors::InactiveCaption;
		System::Windows::Forms::Label^ label = dynamic_cast<System::Windows::Forms::Label^>(sender);

		System::Drawing::FontStyle style = label->Font->Style;

		if ((style & System::Drawing::FontStyle::Bold) == static_cast<System::Drawing::FontStyle>(0)) {
		}
		else {
			style = style & ~System::Drawing::FontStyle::Bold;
		}

		if ((style & System::Drawing::FontStyle::Italic) == static_cast<System::Drawing::FontStyle>(0)) {
		}
		else {
			style = style & ~System::Drawing::FontStyle::Bold;
		}
		label->Font = gcnew System::Drawing::Font(label->Font, style);
	}
	private: System::Void Player_stat_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Xóa các bộ lọc cũ nếu đã có
		if (isPlayerStatClicked == true) return;
		currentPage = 0;
		ClearDynamicComboBoxes();
		ClearPanelFromX(this->FilterPanel, 600);
		this->rankingTable->Controls->Clear(); // Xóa tất cả các điều khiển trong bảng
		this->rankingTable->RowStyles->Clear(); // Xóa các hàng
		this->rankingTable->ColumnStyles->Clear(); // Xóa các cột
		this->rankingTable->RowCount = 0; // Đặt lại số lượng hàng
		this->rankingTable->ColumnCount = 0; // Đặt lại số lượng cột
		isPlayerStatClicked = true;
		isTeamStatClicked = false;
		this->Team_stat->BackColor = System::Drawing::SystemColors::InactiveCaption;
		this->Team_stat->ForeColor = System::Drawing::Color::Black;
		System::Windows::Forms::Label^ label1 = dynamic_cast<System::Windows::Forms::Label^>(this->Team_stat);
		if (label1->Height - 40 > 0) {
			label1->Top += 40;
			label1->Height -= 40;
		}

		// Change Player stat
		this->Player_stat->BackColor = System::Drawing::SystemColors::HotTrack;
		this->Player_stat->ForeColor = System::Drawing::Color::Black;
		System::Windows::Forms::Label^ label2 = dynamic_cast<System::Windows::Forms::Label^>(sender);
		label2->Top -= 40;
		label2->Height += 40;

		// Danh sách các nhãn cho các ComboBox
		cli::array<String^>^ filterLabels = gcnew cli::array<String^> {
			"Filter by Stat Type",
				"Filter by Clubs",
				"Filter by Nationality",
				"Filter by Position"
		};

		// Vị trí Y ban đầu cho ComboBox
		int startX = 500;
		int spacing = 160; // Khoảng cách giữa các ComboBox

		for (int i = 0; i < filterLabels->Length; i++) {
			// Create Label
			System::Windows::Forms::Label^ label = gcnew System::Windows::Forms::Label();
			label->BackColor = System::Drawing::Color::Transparent;
			label->Text = filterLabels[i];
			label->Location = System::Drawing::Point(startX + i * spacing, 20);
			label->Size = System::Drawing::Size(100, 20);
			this->FilterPanel->Controls->Add(label);

			// Create ComboBox
			System::Windows::Forms::ComboBox^ comboBox = gcnew System::Windows::Forms::ComboBox();
			comboBox->Location = System::Drawing::Point(startX + i * spacing, 40);
			comboBox->Name = L"FilterComboBox" + i;
			comboBox->Size = System::Drawing::Size(120, 50);
			comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

			comboBox->SuspendLayout();
			if (i == 0) {
				comboBox->Items->AddRange(gcnew cli::array<System::Object^> {
					"Goals", "Assists", "Red Cards", "Yellow Cards", "Clean Sheets"
				});
			}
			else if (i == 1) {
				comboBox->Items->Add("All Clubs");
				for (int i = 0; i < tour->get_team_count(); i++) {
					Team* team = tour->getTeam(i);
					String^ Name = gcnew String(team->get_name().c_str());
					comboBox->Items->Add(Name);
				}
			}
			else if (i == 2) {
				try {
					System::IO::StreamReader^ sr = gcnew System::IO::StreamReader("country.txt");
					String^ line;
					comboBox->Items->Add("All Nationality");
					while ((line = sr->ReadLine()) != nullptr) {
						comboBox->Items->Add(line);
					}
					sr->Close();
				}
				catch (Exception^ ex) {
					MessageBox::Show("Error reading file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else if (i == 3) {
				comboBox->Items->AddRange(gcnew cli::array<System::Object^> {
					"All Positions", "Forward", "Midfielder", "Defender", "Goalkeeper"
				});
			}
			comboBox->ResumeLayout();

			// Attach Event Handler After Initialization
			comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &UC_STATS::FilterComboBox_SelectedIndexChanged);
			comboBox->SelectedIndex = 0;

			this->FilterPanel->Controls->Add(comboBox);
			this->dynamicComboBoxes->Add(comboBox);
		}
	}
	private: System::Void Player_stat_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		if (isPlayerStatClicked == false) {
			this->Player_stat->BackColor = System::Drawing::SystemColors::HotTrack;
			System::Windows::Forms::Label^ label = dynamic_cast<System::Windows::Forms::Label^>(sender);

			System::Drawing::FontStyle style = label->Font->Style;

			if ((style & System::Drawing::FontStyle::Bold) == static_cast<System::Drawing::FontStyle>(0)) {
				style = style | System::Drawing::FontStyle::Bold;
			}

			if ((style & System::Drawing::FontStyle::Italic) == static_cast<System::Drawing::FontStyle>(0)) {
				style = style | System::Drawing::FontStyle::Italic;
			}
			label->Font = gcnew System::Drawing::Font(label->Font, style);
		}
	}
	private: System::Void Player_stat_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		if (isPlayerStatClicked == true) return;
		this->Player_stat->BackColor = System::Drawing::SystemColors::InactiveCaption;
		System::Windows::Forms::Label^ label = dynamic_cast<System::Windows::Forms::Label^>(sender);

		System::Drawing::FontStyle style = label->Font->Style;

		if ((style & System::Drawing::FontStyle::Bold) == static_cast<System::Drawing::FontStyle>(0)) {
		}
		else {
			style = style & ~System::Drawing::FontStyle::Bold;
		}

		if ((style & System::Drawing::FontStyle::Italic) == static_cast<System::Drawing::FontStyle>(0)) {
		}
		else {
			style = style & ~System::Drawing::FontStyle::Bold;
		}
		label->Font = gcnew System::Drawing::Font(label->Font, style);
	}
	private: System::Void Circular_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		for each (System::Windows::Forms::ComboBox ^ comboBox in this->dynamicComboBoxes) {
			comboBox->SelectedIndex = 0;
		}
	}
	private: System::Void FilterComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (isPlayerStatClicked == true) {
			std::vector<Player> filteredPlayers = this->tour->getPlayers(); // Danh sách ban đầu
			this->rankingTable->Controls->Clear(); // Xóa tất cả các điều khiển trong bảng
			this->rankingTable->RowStyles->Clear(); // Xóa các hàng
			this->rankingTable->ColumnStyles->Clear(); // Xóa các cột
			this->rankingTable->RowCount = 0; // Đặt lại số lượng hàng
			this->rankingTable->ColumnCount = 0; // Đặt lại số lượng cột

			this->rankingTable->Visible = true;
			this->btnNext->Visible = true;
			this->lblPage->Visible = true;
			this->btnPrevious->Visible = true;
			this->btnFirst->Visible = true;
			this->btnLast->Visible = true;
			t = 0;
			currentPage = 0;
			// Duyệt qua tất cả các ComboBox động
			for each (System::Windows::Forms::ComboBox ^ comboBox in this->dynamicComboBoxes) {
				String^ selectedFilter = comboBox->SelectedItem == nullptr ? "" : comboBox->SelectedItem->ToString();

				if (comboBox->Name == "FilterComboBox0") { // Lọc theo Stat
					if (selectedFilter == "Goals") {
						filteredPlayers = this->tour->list_player_by_goal(filteredPlayers, Descending);
						t = 0;
					}
					else if (selectedFilter == "Assists") {
						filteredPlayers = this->tour->list_player_by_assist(filteredPlayers, Descending);
						t = 1;
					}
					else if (selectedFilter == "Red Cards") {
						filteredPlayers = this->tour->list_player_by_rc(filteredPlayers, Descending);
						t = 2;
					}
					else if (selectedFilter == "Yellow Cards") {
						filteredPlayers = this->tour->list_player_by_yc(filteredPlayers, Descending);
						t = 3;
					}
					else if (selectedFilter == "Clean Sheets") {
						filteredPlayers = this->tour->list_gk_by_cs(filteredPlayers, Descending);
						t = 4;
					}
				}
				else if (comboBox->Name == "FilterComboBox1") { // Lọc theo Club
					std::vector<Player> tempPlayers;
					if (selectedFilter != "All Clubs")
					{
						for (int i = 0; i < tour->get_team_count(); i++) {
							Team* team = tour->getTeam(i);
							String^ teamName = gcnew String(team->get_name().c_str());
							if (selectedFilter == teamName) {
								tempPlayers = tour->list_players_by_team(filteredPlayers, team->get_id());
								break;
							}
						}
						filteredPlayers = tempPlayers; // Cập nhật danh sách đã lọc
					}
				}
				else if (comboBox->Name == "FilterComboBox2") { // Lọc theo Nationality
					if (selectedFilter != "All Nationality") {
						if (!String::IsNullOrEmpty(selectedFilter)) {
							std::string nation;
							Ultility::StringToStlString(selectedFilter, nation);
							filteredPlayers = tour->list_players_by_nation(filteredPlayers, nation);
						}
					}
				}
				else if (comboBox->Name == "FilterComboBox3") {
					if (selectedFilter != "All Positions") {
						if (!String::IsNullOrEmpty(selectedFilter)) {
							std::string pos;
							Ultility::StringToStlString(selectedFilter, pos);
							filteredPlayers = tour->list_players_in_pos(filteredPlayers, pos);
						}
					}
				}
			}

			// Cập nhật bảng xếp hạng
			this->rankingTable->Controls->Clear();
			this->rankingTable->RowCount = 1;
			this->rankingTable->ColumnCount = 6;

			// Thêm hàng tiêu đề
			AddRowToTablePlayer("0", "0", "Rank", "Player", "Club", "Nationality", "Position", "Stat", "Match", true);

			// Tính toán phạm vi dữ liệu của trang hiện tại
			this->tour->CFplayers = filteredPlayers;
			this->numPage = ceil(filteredPlayers.size() / itemsPerPage);
			this->lblPage->Visible = true;
			this->lblPage->Text = "Page " + (currentPage + 1).ToString() + "/" + numPage.ToString();
			this->lblPage->BringToFront();
			int startIndex = currentPage * itemsPerPage;
			int endIndex = Math::Min(startIndex + itemsPerPage, static_cast<int>(filteredPlayers.size()));

			// Thêm các cầu thủ đã lọc vào bảng
			for (int i = startIndex; i < endIndex; i++) {
				Player player = filteredPlayers[i];
				int statValue = 0;
				switch (t) {
				case 0: statValue = player.getGoals(); break;
				case 1: statValue = player.getAssists(); break;
				case 2: statValue = player.getRedCards(); break;
				case 3: statValue = player.getYellowCards(); break;
				case 4: statValue = player.getCleanSheets(); break;
				default: break;
				}
				AddRowToTablePlayer(
					gcnew String(player.getId().c_str()),
					gcnew String(std::to_string(player.getTId()).c_str()),
					gcnew String(std::to_string(i + 1).c_str()) + ".",  // Chuyển đổi số thành System::String^
					gcnew String(player.get_Name().c_str()),
					gcnew String(player.getTeam()->get_name().c_str()),
					gcnew String(player.get_nation().c_str()),
					gcnew String(player.getPosition().c_str()),
					gcnew String(std::to_string(statValue).c_str()),
					gcnew String(std::to_string(player.getMatch()).c_str()),
					false
				);
			}
		}
		else {
			std::vector<Team> filteredTeams = this->tour->getTeams(); // Danh sách ban đầu
			this->rankingTable->Controls->Clear(); // Xóa tất cả các điều khiển trong bảng
			this->rankingTable->RowStyles->Clear(); // Xóa các hàng
			this->rankingTable->ColumnStyles->Clear(); // Xóa các cột
			this->rankingTable->RowCount = 0; // Đặt lại số lượng hàng
			this->rankingTable->ColumnCount = 0; // Đặt lại số lượng cột

			this->rankingTable->Visible = true;
			this->btnNext->Visible = true;
			this->lblPage->Visible = true;
			this->btnPrevious->Visible = true;
			t = 0;
			// Duyệt qua tất cả các ComboBox động
			for each (System::Windows::Forms::ComboBox ^ comboBox in this->dynamicComboBoxes) {
				String^ selectedFilter = comboBox->SelectedItem == nullptr ? "" : comboBox->SelectedItem->ToString();

				if (comboBox->Name == "FilterComboBox0") { // Lọc theo Stat
					if (selectedFilter == "Goals Scored") {
						filteredTeams = this->tour->list_teams_by_goal_scored(Descending);
						t = 0;
					}
					else if (selectedFilter == "Goals Conceded") {
						filteredTeams = this->tour->list_teams_by_goal_conceded(Descending);
						t = 1;
					}
					else if (selectedFilter == "Wins") {
						filteredTeams = this->tour->list_teams_by_wins(Descending);
						t = 2;
					}
					else if (selectedFilter == "Loses") {
						filteredTeams = this->tour->list_teams_by_loses(Descending);
						t = 3;
					}
				}
			}

			// Cập nhật bảng xếp hạng
			this->rankingTable->Controls->Clear();
			this->rankingTable->RowCount = 1;
			this->rankingTable->ColumnCount = 3;

			// Thêm hàng tiêu đề
			AddRowToTableTeam("0", "Rank", "Club", "Stat", true);

			// Tính toán phạm vi dữ liệu của trang hiện tại
			this->tour->CFteams = filteredTeams;
			this->numPage = ceil(filteredTeams.size() / itemsPerPage);
			this->lblPage->Visible = true;
			this->lblPage->Text = "Page " + gcnew String(std::to_string(currentPage + 1).c_str()) + "/" + gcnew String(std::to_string(numPage).c_str());
			this->lblPage->BringToFront();
			int startIndex = currentPage * itemsPerPage;
			int endIndex = Math::Min(startIndex + itemsPerPage, static_cast<int>(filteredTeams.size()));

			// Thêm các cầu thủ đã lọc vào bảng
			for (int i = startIndex; i < endIndex; i++) {
				Team team = filteredTeams[i];
				int statValue = 0;
				switch (t) {
				case 0: statValue = team.get_goal_scored(); break;
				case 1: statValue = team.get_goal_conceded(); break;
				case 2: statValue = team.get_wins(); break;
				case 3: statValue = team.get_loses(); break;
				default: break;
				}
				AddRowToTableTeam(
					gcnew String(std::to_string(team.get_id()).c_str()),
					gcnew String(std::to_string(i + 1).c_str()),  // Chuyển đổi số thành System::String^
					gcnew String(team.get_name().c_str()),
					gcnew String(std::to_string(statValue).c_str()),
					false
				);
			}
		}
	}


	private: void ClearPanelFromX(System::Windows::Forms::Panel^ panel, int startX) {
		for (int i = panel->Controls->Count - 1; i >= 0; i--) {
			System::Windows::Forms::Control^ control = panel->Controls[i];
			if (control->Location.X >= startX) {
				panel->Controls->Remove(control);
			}
		}
	}


	private:
		void AdjustRankingPlayerTableLayout() {
			// Đặt lại các tỷ lệ cột
			this->rankingTable->ColumnCount = 7;
			this->rankingTable->ColumnStyles->Clear();
			this->rankingTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 10)); // Rank
			this->rankingTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 15)); // Name
			this->rankingTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 25)); // Team
			this->rankingTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 20)); // Nation
			this->rankingTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 10)); // Position
			this->rankingTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 10)); // Stat
			this->rankingTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 10)); // Match

			// Đặt lại các tỷ lệ hàng
			int totalRows = this->rankingTable->RowCount;
			this->rankingTable->RowStyles->Clear();
			for (int i = 0; i < totalRows + 1; ++i) {
				this->rankingTable->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 100.0f / totalRows));
			}

			// Chừa lại 10% trống phía dưới
			this->rankingTable->Dock = DockStyle::Top;
			this->rankingTable->Height = this->Height * 0.88; // Chiều cao 90% màn hình
		}

		void AdjustRankingTeamTableLayout() {
			// Đặt lại các tỷ lệ cột
			this->rankingTable->ColumnCount = 3;
			this->rankingTable->ColumnStyles->Clear();
			this->rankingTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 20)); // Rank
			this->rankingTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 50)); // Name
			this->rankingTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 30)); // Stat

			// Đặt lại các tỷ lệ hàng
			int totalRows = this->rankingTable->RowCount;
			this->rankingTable->RowStyles->Clear();
			for (int i = 0; i < totalRows; ++i) {
				this->rankingTable->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 100.0f / (totalRows)));
			}

			// Chừa lại 10% trống phía dưới
			this->rankingTable->Dock = DockStyle::Top;
			this->rankingTable->Height = this->Height * 0.88; // Chiều cao 90% màn hình
		}

		// A static cache to hold the resized images for reuse
		static System::Collections::Generic::Dictionary<String^, System::Drawing::Image^>^ resizedImageCache = gcnew System::Collections::Generic::Dictionary<String^, System::Drawing::Image^>();

		// Function to resize image only if not cached
		System::Drawing::Image^ GetResizedImage(String^ imageName, int width, int height) {
			// Check if the resized image already exists in the cache
			if (resizedImageCache->ContainsKey(imageName)) {
				// Return the cached resized image
				return resizedImageCache[imageName];
			}

			// Load the original image from resources
			System::Drawing::Image^ originalImage = ImageHelper::GetImageResource(imageName);
			if (originalImage == nullptr) {
				originalImage = ImageHelper::GetImageResource("Unknown");
			}

			// Resize the image
			System::Drawing::Image^ resizedImage = ResizeImage(originalImage, width, height);

			// Cache the resized image for future use
			resizedImageCache[imageName] = resizedImage;

			// Return the resized image
			return resizedImage;
		}

		// Modify your AddRowToTablePlayer function to use the GetResizedImage function
		void AddRowToTablePlayer(String^ cellID, String^ cellTID, String^ rank, String^ name, String^ team, String^ nation, String^ position, String^ stat, String^ match, bool isHeader) {
			// Suspend layout to prevent UI from redrawing after each change
			this->rankingTable->SuspendLayout();

			// Tăng số lượng hàng
			this->rankingTable->RowCount++;

			// Mảng chứa dữ liệu
			array<String^>^ playerData = gcnew array<String^>{ rank, name, team, nation, position, stat, match };

			for (int col = 0; col < playerData->Length; ++col) {
				Label^ cell = gcnew Label();
				cell->Dock = DockStyle::Fill;
				cell->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				cell->Margin = System::Windows::Forms::Padding(0);

				if (isHeader) {
					// Header: Font lớn, màu nền khác
					cell->Font = gcnew System::Drawing::Font("Arial", 16, System::Drawing::FontStyle::Bold);
					cell->BackColor = System::Drawing::Color::LightGray;
				}
				else {
					// Nội dung: Font lớn hơn và nền trắng
					cell->Font = gcnew System::Drawing::Font("Arial", 14, System::Drawing::FontStyle::Regular);
					cell->BackColor = System::Drawing::Color::White;
				}

				// Text hoặc hình ảnh
				if (col == 2 || col == 3) {  // Team or Nation columns
					if (!isHeader) {
						std::string resourceName;
						if (col == 2) { // Team
							Ultility::StringToStlString(team, resourceName);
							resourceName += "_logo";
						}
						else { // Nation
							Ultility::StringToStlString(nation, resourceName);
						}

						// Get the resized image from the cache
						System::Drawing::Image^ resizedImage;
						if (col == 2) {
							resizedImage = GetResizedImage(gcnew String(resourceName.c_str()), 30, 30);
							cell->Name = cellTID;
							cell->MouseEnter += gcnew EventHandler(this, &UC_STATS::OnMouseEnterTeam);
							cell->MouseLeave += gcnew EventHandler(this, &UC_STATS::OnMouseLeaveTeam);
							cell->Click += gcnew EventHandler(this, &UC_STATS::OnTeamClick);
						}
						else
							resizedImage = GetResizedImage(gcnew String(resourceName.c_str()), 50, 30);

						cell->Image = resizedImage;
						cell->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
						cell->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
						cell->Text = "          " + playerData[col];
						cell->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;

					}
					else {
						cell->Text = playerData[col];
						cell->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
						if (!isHeader)
							cell->Click += gcnew EventHandler(this, &UC_STATS::OnPlayerClick);
					}
				}
				else {
					// Other columns show text
					cell->Text = playerData[col];
					cell->ForeColor = System::Drawing::Color::Black;
					if (col == 1 && !isHeader) {
						cell->Name = cellID;
						cell->MouseEnter += gcnew EventHandler(this, &UC_STATS::OnMouseEnterPlayer);
						cell->MouseLeave += gcnew EventHandler(this, &UC_STATS::OnMouseLeavePlayer);
						cell->Click += gcnew EventHandler(this, &UC_STATS::OnTeamClick);
					}
					if (col == 1) {
						cell->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
					}
				}

				// Thêm cell vào bảng
				this->rankingTable->Controls->Add(cell, col, this->rankingTable->RowCount - 1);
			}

			// Chỉ điều chỉnh layout một lần sau khi thêm tất cả các hàng
			AdjustRankingPlayerTableLayout();

			// Resume layout to refresh the UI
			this->rankingTable->ResumeLayout();
		}

		System::Drawing::Image^ ResizeImage(System::Drawing::Image^ image, int width, int height) {
			if (image == nullptr) {
				throw gcnew System::ArgumentNullException("image", "Image cannot be null");
			}
			System::Drawing::Bitmap^ resizedImage = gcnew System::Drawing::Bitmap(width, height);
			System::Drawing::Graphics^ graphics = System::Drawing::Graphics::FromImage(resizedImage);
			graphics->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic;
			graphics->DrawImage(image, 0, 0, width, height);
			delete graphics;
			return resizedImage;
		}

		void AddRowToTableTeam(String^ ID, String^ rank, String^ name, String^ stat, bool isHeader) {
			// Suspend layout to prevent UI from redrawing after each change
			this->rankingTable->SuspendLayout();

			// Tăng số lượng hàng
			this->rankingTable->RowCount++;

			// Mảng chứa dữ liệu
			array<String^>^ teamData = gcnew array<String^>{ rank, name, stat };

			for (int col = 0; col < teamData->Length; ++col) {
				Label^ cell = gcnew Label();
				cell->Dock = DockStyle::Fill;
				cell->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				cell->Margin = System::Windows::Forms::Padding(0);

				if (isHeader) {
					// Header: Font lớn, màu nền khác
					cell->Font = gcnew System::Drawing::Font("Arial", 16, System::Drawing::FontStyle::Bold);
					cell->BackColor = System::Drawing::Color::LightGray;
				}
				else {
					// Nội dung: Font lớn hơn và nền trắng
					cell->Font = gcnew System::Drawing::Font("Arial", 14, System::Drawing::FontStyle::Regular);
					cell->BackColor = System::Drawing::Color::White;
				}

				// Text hoặc hình ảnh
				if (col == 1) {  // Team columns
					if (!isHeader) {
						std::string resourceName;
						// Team
						Ultility::StringToStlString(name, resourceName);
						resourceName += "_logo";

						// Get the resized image from the cache
						System::Drawing::Image^ resizedImage;
						resizedImage = GetResizedImage(gcnew String(resourceName.c_str()), 30, 30);

						cell->Name = ID;
						cell->Image = resizedImage;
						cell->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
						cell->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
						cell->Text = "          " + teamData[col];
						cell->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
						cell->MouseEnter += gcnew EventHandler(this, &UC_STATS::OnMouseEnterTeam);
						cell->MouseLeave += gcnew EventHandler(this, &UC_STATS::OnMouseLeaveTeam);
						cell->Click += gcnew EventHandler(this, &UC_STATS::OnTeamClick);
					}
					else {
						/*cell->Text = teamData[col];*/
						cell->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
					}
				}
				else {
					// Other columns show text
					cell->Text = teamData[col];
					cell->ForeColor = System::Drawing::Color::Black;
					if (col == 1) {
						cell->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
						cell->Name = ID;
					}
				}

				// Thêm cell vào bảng
				this->rankingTable->Controls->Add(cell, col, this->rankingTable->RowCount - 1);
			}

			// Chỉ điều chỉnh layout một lần sau khi thêm tất cả các hàng
			AdjustRankingTeamTableLayout();

			// Resume layout to refresh the UI
			this->rankingTable->ResumeLayout();

		}

		void OnFirstClicked(Object^ sender, EventArgs^ e) {
			if (currentPage != 0) {
				currentPage = 0;
				if (isPlayerStatClicked == true) {
					UpdatePagePlayer();
				}
				else {
					UpdatePageTeam();
				}
			}
		}

		void OnPreviousClicked(Object^ sender, EventArgs^ e) {
			if (currentPage > 0) {
				currentPage--;
				if (isPlayerStatClicked == true) {
					UpdatePagePlayer();
				}
				else {
					UpdatePageTeam();
				}
			}
		}

		void OnNextClicked(Object^ sender, EventArgs^ e) {
			if (currentPage + 1 <= numPage) {
				currentPage++;
				if (isPlayerStatClicked == true) {
					UpdatePagePlayer();
				}
				else {
					UpdatePageTeam();
				}
			}
		}

		void OnLastClicked(Object^ sender, EventArgs^ e) {
			if (currentPage + 1 != numPage) {
				currentPage = numPage - 1;
				if (isPlayerStatClicked == true) {
					UpdatePagePlayer();
				}
				else {
					UpdatePageTeam();
				}
			}
		}

		void UpdatePageTeam() {
			this->rankingTable->Controls->Clear(); // Xóa tất cả các điều khiển trong bảng
			this->rankingTable->RowStyles->Clear(); // Xóa các hàng
			this->rankingTable->ColumnStyles->Clear();
			this->rankingTable->RowCount = 0;
			this->rankingTable->ColumnCount = 0;

			this->rankingTable->Controls->Clear();
			this->rankingTable->RowCount = 1;
			this->rankingTable->ColumnCount = 3;

			// Thêm hàng tiêu đề
			AddRowToTableTeam("0", "Rank", "Club", "Stat", true);

			// Tính toán phạm vi dữ liệu của trang hiện tại
			std::vector<Team> filteredTeams = this->tour->CFteams;
			this->lblPage->Text = "Page " + gcnew String(std::to_string(currentPage + 1).c_str()) + "/" + gcnew String(std::to_string(numPage).c_str());
			this->lblPage->BringToFront();
			int startIndex = currentPage * itemsPerPage;
			int endIndex = Math::Min(startIndex + itemsPerPage, static_cast<int>(filteredTeams.size()));

			// Thêm các cầu thủ đã lọc vào bảng
			for (int i = startIndex; i < endIndex; i++) {
				Team team = filteredTeams[i];
				int statValue = 0;
				switch (t) {
				case 0: statValue = team.get_goal_scored(); break;
				case 1: statValue = team.get_goal_conceded(); break;
				case 2: statValue = team.get_wins(); break;
				case 3: statValue = team.get_loses(); break;
				default: break;
				}
				AddRowToTableTeam(
					gcnew String(std::to_string(team.get_id()).c_str()),
					gcnew String(std::to_string(i + 1).c_str()),  // Chuyển đổi số thành System::String^
					gcnew String(team.get_name().c_str()),
					gcnew String(std::to_string(statValue).c_str()),
					false
				);
			}
		}

		void UpdatePagePlayer() {
			this->rankingTable->Controls->Clear(); // Xóa tất cả các điều khiển trong bảng
			this->rankingTable->RowStyles->Clear(); // Xóa các hàng
			this->rankingTable->ColumnStyles->Clear();
			this->rankingTable->RowCount = 0;
			this->rankingTable->ColumnCount = 0;
			this->rankingTable->RowCount = 1;
			this->rankingTable->ColumnCount = 6;

			// Thêm hàng tiêu đề
			AddRowToTablePlayer("0", "0", "Rank", "Player", "Club", "Nationality", "Position", "Stat", "Match", true);

			// Tính toán phạm vi dữ liệu của trang hiện tại
			std::vector<Player> filteredPlayers = this->tour->CFplayers;
			this->lblPage->Text = "Page " + (currentPage + 1).ToString() + "/" + numPage.ToString();
			this->lblPage->BringToFront();
			int startIndex = currentPage * itemsPerPage;
			int endIndex = Math::Min(startIndex + itemsPerPage, static_cast<int>(filteredPlayers.size()));

			// Thêm các cầu thủ đã lọc vào bảng
			for (int i = startIndex; i < endIndex; i++) {
				Player player = filteredPlayers[i];
				int statValue = 0;
				switch (t) {
				case 0: statValue = player.getGoals(); break;
				case 1: statValue = player.getAssists(); break;
				case 2: statValue = player.getRedCards(); break;
				case 3: statValue = player.getYellowCards(); break;
				case 4: statValue = player.getCleanSheets(); break;
				default: break;
				}
				AddRowToTablePlayer(
					gcnew String(player.getId().c_str()),
					gcnew String(std::to_string(player.getTId()).c_str()),
					gcnew String(std::to_string(i + 1).c_str()) + ".",  // Chuyển đổi số thành System::String^
					gcnew String(player.get_Name().c_str()),
					gcnew String(player.getTeam()->get_name().c_str()),
					gcnew String(player.get_nation().c_str()),
					gcnew String(player.getPosition().c_str()),
					gcnew String(std::to_string(statValue).c_str()),
					gcnew String(std::to_string(player.getMatch()).c_str()),
					false
				);
			}
		}

		void OnMouseEnterPlayer(Object^ sender, EventArgs^ e)
		{
			Label^ label = safe_cast<Label^>(sender);
			label->Font = gcnew System::Drawing::Font(
				label->Font,
				label->Font->Style | FontStyle::Underline
			);
			label->Cursor = Cursors::Hand;
		}

		void OnMouseEnterTeam(Object^ sender, EventArgs^ e)
		{
			Label^ label = safe_cast<Label^>(sender);
			label->Font = gcnew System::Drawing::Font(
				label->Font,
				label->Font->Style | FontStyle::Bold
			);
			label->Cursor = Cursors::Hand;
		}

		void OnMouseLeavePlayer(Object^ sender, EventArgs^ e)
		{
			Label^ label = safe_cast<Label^>(sender);
			label->Font = gcnew System::Drawing::Font("Arial", 14, System::Drawing::FontStyle::Regular);
			label->Cursor = Cursors::Default;
		}

		void OnMouseLeaveTeam(Object^ sender, EventArgs^ e)
		{
			Label^ label = safe_cast<Label^>(sender);
			label->Font = gcnew System::Drawing::Font("Arial", 14, System::Drawing::FontStyle::Regular);
			label->Cursor = Cursors::Default;
		}

		void OnPlayerClick(Object^ sender, EventArgs^ e)
		{
			Label^ label = safe_cast<Label^>(sender);
			MessageBox::Show("You clicked on: " + label->Name);
		}

		void OnTeamClick(Object^ sender, EventArgs^ e)
		{
			Label^ label = safe_cast<Label^>(sender);
			MessageBox::Show("You clicked on: " + label->Name);
		}
	};

}

