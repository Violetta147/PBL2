#pragma once
#include "include/Tournament.h"
#include "include/Team.h"
#include "include/Player.h"
#include "ImageHelper.h"
#include "CustomControl.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

inline void StringToStlWString2(System::String^ s, std::string& os)
{
	if (s == nullptr)
	{
		os.clear();
		return;
	}

	using namespace System::Runtime::InteropServices;

	// Convert to UTF-8 encoded unmanaged string
	IntPtr pUtf8 = Marshal::StringToHGlobalAnsi(s);
	try
	{
		const char* chars = static_cast<const char*>(pUtf8.ToPointer());
		os = chars; // Assign to std::string
	}
	finally
	{
		// Free unmanaged memory
		Marshal::FreeHGlobal(pUtf8);
	}
}

namespace Form2 {

	/// <summary>
	/// Summary for UC_PLAYERS
	/// </summary>
	public ref class UC_PLAYERS : public System::Windows::Forms::UserControl
	{
	public:
		UC_PLAYERS(Tournament* tournament)
		{
			this->tour = tournament;
			InitializeComponent();

			// Gắn các sự kiện cần thiết
			this->Load += gcnew System::EventHandler(this, &Form2::UC_PLAYERS::UC_PLAYERS_Load);
			this->Resize += gcnew EventHandler(this, &Form2::UC_PLAYERS::UC_PLAYERS_Resize);
			// Cải thiện hiệu suất render
			this->SetStyle(ControlStyles::DoubleBuffer | ControlStyles::UserPaint | ControlStyles::AllPaintingInWmPaint, true);
			this->UpdateStyles();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UC_PLAYERS()
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
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Panel^ FilterPanel;
	private: System::Windows::Forms::Panel^ searchPanel;
	private: System::Windows::Forms::TextBox^ searchTextBox;
	private: System::Windows::Forms::Button^ searchButton;
	private: System::Windows::Forms::Label^ Circular;
		   System::Collections::Generic::List<System::Windows::Forms::ComboBox^>^ dynamicComboBoxes;
		   Tournament* tour; // Tham chiếu tới đối tượng Tournament
		   System::Windows::Forms::Panel^ playerPanel;
		   TableLayoutPanel^ playerTable;
		   int startIndex = 0;
		   Button^ rev;
		   int isRev = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UC_PLAYERS::typeid));
			this->FilterPanel = (gcnew System::Windows::Forms::Panel());
			this->Circular = (gcnew System::Windows::Forms::Label());
			this->FilterPanel->SuspendLayout();
			this->SuspendLayout();
			this->dynamicComboBoxes = gcnew System::Collections::Generic::List<System::Windows::Forms::ComboBox^>();
			// 
			// FilterPanel
			// 
			this->FilterPanel->BackColor = System::Drawing::Color::IndianRed;
			this->FilterPanel->Controls->Add(this->Circular);
			this->FilterPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->FilterPanel->Location = System::Drawing::Point(0, 0);
			this->FilterPanel->Name = L"FilterPanel";
			this->FilterPanel->Size = System::Drawing::Size(1680, 103);
			this->FilterPanel->TabIndex = 0;
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
			this->Circular->Text = L"Reset Filter";
			this->Circular->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->Circular->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &UC_PLAYERS::Circular_MouseClick);
			this->FilterPanel->Controls->Add(this->Circular);
			// 
			// UC_PLAYERS
			// 
			this->playerPanel = (gcnew System::Windows::Forms::Panel());
			this->playerPanel->Dock = System::Windows::Forms::DockStyle::Fill; // Đặt để lấp đầy phần còn lại bên dưới FilterPanel
			this->playerPanel->AutoScroll = true; // Kích hoạt thanh cuộn nếu nội dung quá dài
			// Khởi tạo rankingTable
			this->playerTable = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->playerTable->Dock = System::Windows::Forms::DockStyle::None; // Căn trên cùng
			this->playerTable->AutoSize = true; // Tự động thay đổi kích thước theo nội dung
			this->playerTable->Visible = true;
	       

			this->Controls->Add(this->playerPanel);
			this->playerPanel->Controls->Add(this->playerTable);
			this->playerPanel->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &UC_PLAYERS::OnPlayerGridScroll);
			this->playerPanel->MouseWheel += gcnew MouseEventHandler(this, &UC_PLAYERS::OnMouseWheel);

			this->rev = gcnew Button();
			System::Drawing::Image^ Image = ImageHelper::GetImageResource("Reverse");
			System::Drawing::Image^ resizedImage = ResizeImage(Image, 25, 15);
			this->rev->Image = Image;
			this->rev->Size = System::Drawing::Size(70, 50);
			this->rev->Location = System::Drawing::Point(120, 12);
			this->rev->Click += gcnew EventHandler(this, &UC_PLAYERS::OnReverseClicked);
			this->rev->Visible = false;

			/*this->lbl = gcnew Label();
			this->lbl->Location = System::Drawing::Point(20, 0);
			this->lbl->Size = System::Drawing::Size(240, 65);
			this->lbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lbl->Visible = false;
			this->lbl->BackColor = System::Drawing::Color::Transparent;
			this->lbl->ForeColor = System::Drawing::Color::IndianRed;
			this->lbl->Font = gcnew System::Drawing::Font("Arial", 20, System::Drawing::FontStyle::Bold);
			this->lbl->Text = "PLAYERS";*/

			this->playerPanel->Controls->Add(this->rev);
			/*this->playerPanel->Controls->Add(this->lbl);*/
			/*this->Controls->Add(this->playerPanel);*/

			/*FilterPanel->Margin = Padding(0);
			FilterPanel->Padding = Padding(0);

			playerPanel->Margin = Padding(0);
			playerPanel->Padding = Padding(0);*/

			InitializeSearchBar();
			this->Controls->Add(this->FilterPanel);
			InitializeComboBox();

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Silver;
			this->DoubleBuffered = true;
			this->Location = System::Drawing::Point(0, 90);
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"UC_PLAYERS";
			this->Size = System::Drawing::Size(1680, 775);
			/*this->Controls->Add(this->FilterPanel);*/
			this->FilterPanel->ResumeLayout(false);
			/*this->lbl->BringToFront();*/
			this->rev->BringToFront();
			InitializeComboBox();
			this->ResumeLayout(false);

		}

		void InitializeSearchBar() {
			// Panel chứa TextBox và Button
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UC_PLAYERS::typeid));
			this->searchPanel = gcnew System::Windows::Forms::Panel();
			this->searchPanel->Size = System::Drawing::Size(400, 60); // Change width to 400
			this->searchPanel->Location = System::Drawing::Point(1200, 20);
			this->searchPanel->BackColor = System::Drawing::Color::White;
			this->searchPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

			// TextBox
			this->searchTextBox = gcnew System::Windows::Forms::TextBox();
			this->searchTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->searchTextBox->Font = gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Italic);
			this->searchTextBox->ForeColor = System::Drawing::Color::Gray;
			this->searchTextBox->Text = L"Search for a Player";
			this->searchTextBox->Location = System::Drawing::Point(20, 20);
			this->searchTextBox->Size = System::Drawing::Size(320, 20); // Adjust text box width according to the smaller panel size

			// Sự kiện KeyDown cho TextBox
			this->searchTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &UC_PLAYERS::searchTextBox_KeyDown);

			// Placeholder Effect cho TextBox
			this->searchTextBox->GotFocus += gcnew System::EventHandler(this, &UC_PLAYERS::SearchTextBox_GotFocus);
			this->searchTextBox->LostFocus += gcnew System::EventHandler(this, &UC_PLAYERS::SearchTextBox_LostFocus);

			// Button (biểu tượng kính lúp)
			this->searchButton = gcnew System::Windows::Forms::Button();
			this->searchButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->searchButton->FlatAppearance->BorderSize = 0;
			this->searchButton->Size = System::Drawing::Size(40, 40);
			this->searchButton->Location = System::Drawing::Point(350, 10); // Adjust the button's location based on the smaller panel
			this->searchButton->Cursor = System::Windows::Forms::Cursors::Hand;

			// Thêm hình ảnh cho Button
			System::Drawing::Image^ Image = ImageHelper::GetImageResource("Search");
			System::Drawing::Image^ resizedImage = ResizeImage(Image, 30, 30);
			this->searchButton->Image = resizedImage;

			// Sự kiện Click cho Button
			this->searchButton->Click += gcnew System::EventHandler(this, &UC_PLAYERS::searchButton_Click);

			// Thêm các thành phần vào Panel
			this->searchPanel->Controls->Add(this->searchTextBox);
			this->searchPanel->Controls->Add(this->searchButton);

			// Thêm Panel vào Form
			this->FilterPanel->Controls->Add(this->searchPanel);
			this->searchPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
				System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
		}


		// Placeholder Effect cho TextBox
		void SearchTextBox_GotFocus(System::Object^ sender, System::EventArgs^ e) {
			if (this->searchTextBox->Text == L"Search for a Player") {
				this->searchTextBox->Text = L"";
				this->searchTextBox->ForeColor = System::Drawing::Color::Black;
			}
		}

		void SearchTextBox_LostFocus(System::Object^ sender, System::EventArgs^ e) {
			if (this->searchTextBox->Text == L"") {
				this->searchTextBox->Text = L"Search for a Player";
				this->searchTextBox->ForeColor = System::Drawing::Color::Gray;
			}
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
#pragma endregion

	private: System::Void searchTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
			searchAction(); // Gọi hàm xử lý tìm kiếm chung
			e->SuppressKeyPress = true; // Ngăn tiếng "bíp" mặc định khi nhấn Enter
		}
	}

	private: System::Void searchAction() {
		// Lấy giá trị từ TextBox
		System::String^ searchText = this->searchTextBox->Text;
		std::string name;
		StringToStlWString2(searchText, name);
		std::vector<Player> temp = this->tour->CFplayers;
		this->tour->CFplayers = this->tour->search_by_name(temp, name);
		this->playerTable->Controls->Clear(); // Xóa tất cả các điều khiển trong bảng
		this->playerTable->RowStyles->Clear(); // Xóa các hàng
		this->playerTable->ColumnStyles->Clear(); // Xóa các cột
		this->playerTable->RowCount = 0; // Đặt lại số lượng hàng
		this->playerTable->ColumnCount = 8; // Đặt lại số lượng cột
		startIndex = 0;
		AddRowToTable("0", "0", "Player", "Club", "Nationality", "Position", "DOB", "Jersey", "Weight", "Height", true);
		LoadPlayers(startIndex);
		this->tour->CFplayers = temp;
	}

	private: System::Void searchButton_Click(System::Object^ sender, System::EventArgs^ e) {
		searchAction(); // Gọi hàm xử lý chung
	}
	private:
		// Sự kiện thay đổi kích thước
		void UC_PLAYERS_Resize(Object^ sender, EventArgs^ e)
		{
			this->SuspendLayout();
			// TODO: Tùy chỉnh layout ở đây nếu cần
			this->ResumeLayout(false);
			this->PerformLayout();
		}

		// Sự kiện khi UC_PLAYERS được load
		System::Void UC_PLAYERS_Load(System::Object^ sender, System::EventArgs^ e) {
			this->SuspendLayout();
			Form^ mainForm = this->FindForm();
			if (mainForm != nullptr)
			{
				MenuStrip^ MAINBUTTON = dynamic_cast<MenuStrip^>(mainForm->Controls["MAINBUTTON"]);
				if (MAINBUTTON != nullptr)
				{
					this->Size = System::Drawing::Size(mainForm->ClientSize.Width, mainForm->ClientSize.Height - MAINBUTTON->Height);
					this->Location = System::Drawing::Point(0, MAINBUTTON->Height);
					this->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
						System::Windows::Forms::AnchorStyles::Top |
						System::Windows::Forms::AnchorStyles::Bottom |
						System::Windows::Forms::AnchorStyles::Left |
						System::Windows::Forms::AnchorStyles::Right);
				}
			}
			this->ResumeLayout(false);
			this->PerformLayout();
		}
	private: System::Void InitializeComboBox() {
		// Danh sách các nhãn cho các ComboBox
		cli::array<String^>^ filterLabels = gcnew cli::array<String^> {
			"Filter by Clubs",
				"Filter by Attribute",
				"Filter by Age",
				"Filter by Born Year",
				"Filter by Position",
				"Filter by Nationailty"
		};

		// Vị trí Y ban đầu cho ComboBox
		int startX = 180;
		int spacing = 180; // Khoảng cách giữa các ComboBox

		for (int i = 0; i < filterLabels->Length; i++) {
			// Tạo nhãn (Label) cho ComboBox
			System::Windows::Forms::Label^ label = gcnew System::Windows::Forms::Label();
			label->BackColor = System::Drawing::Color::Transparent;
			label->Text = filterLabels[i];
			label->Location = System::Drawing::Point(startX + i * spacing, 30);
			label->Size = System::Drawing::Size(150, 20);
			this->FilterPanel->Controls->Add(label);

			// Tạo ComboBox mới
			System::Windows::Forms::ComboBox^ comboBox = gcnew System::Windows::Forms::ComboBox();
			comboBox->Location = System::Drawing::Point(startX + i * spacing, 50);
			comboBox->Name = L"FilterComboBox" + i;
			comboBox->Size = System::Drawing::Size(120, 50);
			comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

			comboBox->SuspendLayout();

			// Thêm các mục cho từng ComboBox
			if (i == 0) {
				comboBox->Items->Add("All Clubs");
				for (int i = 0; i < tour->get_team_count(); i++) {
					Team* team = tour->getTeam(i);
					String^ Name = gcnew String(team->get_name().c_str());
					comboBox->Items->Add(Name);
				}
			}
			else if (i == 1) {
				comboBox->Items->AddRange(gcnew cli::array<System::Object^> {
					"No filter", 
					"Height",
						"Weight",
						"Age"
				});
			}
			else if (i == 2) {
				comboBox->Items->Add("All Age");
				for (int i = 18; i < 40; i++) {
					String^ year = gcnew String(std::to_string(i).c_str());
					comboBox->Items->Add(i);
				}
			}
			else if (i == 3) {
				comboBox->Items->Add("All Year");
				for (int i = 0; i < 24; i++) {
					String^ year = gcnew String(std::to_string(2008 - i).c_str());
					comboBox->Items->Add(2008 - i);
				}
			}
			else if (i == 4) {
				comboBox->Items->AddRange(gcnew cli::array<System::Object^> {
					"All Positions",
						"Forward",
						"Midfielder",
						"Defender",
						"Goalkeeper"
				});
			}
			else {
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

			// Gán sự kiện thay đổi giá trị cho ComboBox
			comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &UC_PLAYERS::FilterComboBox_SelectedIndexChanged);

			// Thêm ComboBox vào FilterPanel
			this->FilterPanel->Controls->Add(comboBox);
			this->dynamicComboBoxes->Add(comboBox);
			comboBox->SelectedIndex = 0;
			comboBox->ResumeLayout();
		}
	}
	private: System::Void Circular_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		for each (System::Windows::Forms::ComboBox ^ comboBox in this->dynamicComboBoxes) {
			comboBox->SelectedIndex = 0;
		}
	}
	private: System::Void FilterComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		std::vector<Player> filteredPlayers = this->tour->getPlayers(); // Danh sách ban đầu
		this->playerTable->Controls->Clear(); // Xóa tất cả các điều khiển trong bảng
		this->playerTable->RowStyles->Clear(); // Xóa các hàng
		this->playerTable->ColumnStyles->Clear(); // Xóa các cột
		this->playerTable->RowCount = 0; // Đặt lại số lượng hàng
		this->playerTable->ColumnCount = 0; // Đặt lại số lượng cột

		this->playerTable->Visible = true;
		this->rev->Visible = true;
		/*this->lbl->Visible = true;*/
		startIndex = 0;

		for each (System::Windows::Forms::ComboBox ^ comboBox in this->dynamicComboBoxes) {
			String^ selectedFilter = comboBox->SelectedItem == nullptr ? "" : comboBox->SelectedItem->ToString();

			if (comboBox->Name == "FilterComboBox0") { // Lọc theo Stat
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
			else if (comboBox->Name == "FilterComboBox1") { // Lọc theo Club
				if (selectedFilter == "Height") {
					filteredPlayers = this->tour->list_players_by_height(filteredPlayers, Descending);
				}
				else if (selectedFilter == "Weight") {
					filteredPlayers = this->tour->list_players_by_weight(filteredPlayers, Descending);
				}
				else if (selectedFilter == "Age") {
					filteredPlayers = this->tour->list_players_by_age(filteredPlayers, Ascending);
				}
			}
			else if (comboBox->Name == "FilterComboBox2") { // Lọc theo Nationality
				if (selectedFilter != "All Age") {
					if (!String::IsNullOrEmpty(selectedFilter)) {
						int value = System::Int32::Parse(selectedFilter);
						filteredPlayers = tour->list_players_at_age(filteredPlayers, value);
					}
				}
			}
			else if (comboBox->Name == "FilterComboBox3") {
				if (selectedFilter != "All Year") {
					if (!String::IsNullOrEmpty(selectedFilter)) {
						int value = System::Int32::Parse(selectedFilter);
						filteredPlayers = tour->list_players_by_born_year(filteredPlayers, value);
					}
				}
			}
			else if (comboBox->Name == "FilterComboBox4") {
				if (selectedFilter != "All Positions") {
					if (!String::IsNullOrEmpty(selectedFilter)) {
						std::string pos;
						StringToStlWString2(selectedFilter, pos);
						filteredPlayers = tour->list_players_in_pos(filteredPlayers, pos);
					}
				}
			}
			else if (comboBox->Name == "FilterComboBox5") {
				if (selectedFilter != "All Nationality") {
					if (!String::IsNullOrEmpty(selectedFilter)) {
						std::string nation;
						StringToStlWString2(selectedFilter, nation);
						filteredPlayers = tour->list_players_by_nation(filteredPlayers, nation);
					}
				}
			}
		}

		// Cập nhật bảng xếp hạng
		/*this->playerTable->RowCount = 1;*/
		this->playerTable->ColumnCount = 8;

		this->tour->CFplayers = filteredPlayers;
		// Thêm hàng tiêu đề
		AddRowToTable("0", "0", "Player", "Club", "Nationality", "Position", "DOB", "Jersey", "Weight", "Height", true);
		LoadPlayers(startIndex);
	}

		   void AdjustTableLayout() {
			    //Đặt lại các tỷ lệ cột
			   this->playerTable->Location = Point(0, 0);  // Đặt vị trí của TableLayoutPanel về (0, 0)
			   this->playerTable->ColumnCount = 8;
			   this->playerTable->ColumnStyles->Clear();
			   this->playerTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 20));  //Name
			   this->playerTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 20));  //Team
			   this->playerTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 16));  //Nation
			   this->playerTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 10));  //Position
			   this->playerTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 10));  //DOB
			   this->playerTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 8));  //Jersey
			   this->playerTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 8));  //Weight
			   this->playerTable->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 8)); // Height


			   // Đặt lại các tỷ lệ hàng
			   int totalRows = this->playerTable->RowCount;
			   this->playerTable->RowStyles->Clear();
			   for (int i = 0; i < totalRows + 1; ++i) {
				   this->playerTable->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 70));
			   }

			    //Chừa lại 10% trống phía dưới
			   this->playerTable->Dock = DockStyle::Top;
		   }

		   void AddRowToTable(String^ cellID, String^ cellTID, String^ name, String^ team, String^ nation, 
			   String^ position, String^ DOB, String^ Jersey, String^ weight, String^ height, bool isHeader) {
			    //Suspend layout to prevent UI from redrawing after each change
			   this->playerTable->SuspendLayout();

			    //Tăng số lượng hàng
			   this->playerTable->RowCount++;

			    //Mảng chứa dữ liệu
			   array<String^>^ playerData = gcnew array<String^>{ name, team, nation, position, DOB, Jersey, weight, height };

			   for (int col = 0; col < playerData->Length; ++col) {
				   Label^ cell = gcnew Label();
				   cell->Dock = DockStyle::Fill;
				   cell->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				   cell->Margin = System::Windows::Forms::Padding(0);

				   if (isHeader) {
					    //Header: Font lớn, màu nền khác
					   cell->Font = gcnew System::Drawing::Font("Arial", 16, System::Drawing::FontStyle::Bold);
					   cell->BackColor = System::Drawing::Color::LightGray;
				   }
				   else {
					    //Nội dung: Font lớn hơn và nền trắng
					   cell->Font = gcnew System::Drawing::Font("Arial", 14, System::Drawing::FontStyle::Regular);
					   cell->BackColor = System::Drawing::Color::White;
				   }

				    //Text hoặc hình ảnh
				   if (col == 2 || col == 1 || col == 0) {  // Team or Nation columns
					   if (!isHeader) {
						   std::string resourceName;
						   if (col == 1 || col == 0) {  //Team
							   StringToStlWString2(team, resourceName);
							   resourceName += "_logo";
						   }
						   /*else if (col == 0) {
							   StringToStlWString(cellID, resourceName);
						   } */
						   else {  //Nation
							   StringToStlWString2(nation, resourceName);
						   }

						    //Get the resized image from the cache
						   System::Drawing::Image^ resizedImage;
						   if (col == 1 || col == 0) {
							   resizedImage = GetResizedImage(gcnew String(resourceName.c_str()), 30, 30);
							   if (col == 1)
								   cell->Name = cellTID;
							   else cell->Name = cellID;
							   if (col == 1) {
								   cell->MouseEnter += gcnew EventHandler(this, &UC_PLAYERS::OnMouseEnterTeam);
								   cell->MouseLeave += gcnew EventHandler(this, &UC_PLAYERS::OnMouseLeaveTeam);
								   cell->Click += gcnew EventHandler(this, &UC_PLAYERS::OnTeamClick);
							   }
							   else {
								   cell->MouseEnter += gcnew EventHandler(this, &UC_PLAYERS::OnMouseEnterPlayer);
								   cell->MouseLeave += gcnew EventHandler(this, &UC_PLAYERS::OnMouseLeavePlayer);
								   cell->Click += gcnew EventHandler(this, &UC_PLAYERS::OnPlayerClick);
							   }
						   }
						   else
							   resizedImage = GetResizedImage(gcnew String(resourceName.c_str()), 50, 30);

						   cell->Image = resizedImage;
						   cell->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
						   cell->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
						   cell->Text = "      " + playerData[col];
						   if (col == 2) {
							   cell->Text = "    " + cell->Text;
						   }
						   cell->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;

					   }
					   else {
						   cell->Text = playerData[col];
						   cell->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
					   }
				   }
				   else {
					    //Other columns show text
					   cell->Text = playerData[col];
					   cell->ForeColor = System::Drawing::Color::Black;
				   }

				   if (cell->Text->Length > 25) {
					   cell->Text = cell->Text->Substring(0, 20) + L"...";
				   }
				   cell->Paint += gcnew PaintEventHandler(this, &UC_PLAYERS::DrawCustomBorder);
				    //Thêm cell vào bảng
				   this->playerTable->Controls->Add(cell, col, this->playerTable->RowCount - 1);
			   }

			    //Chỉ điều chỉnh layout một lần sau khi thêm tất cả các hàng
			   AdjustTableLayout();

			   // Resume layout to refresh the UI
			   this->playerTable->ResumeLayout();
		   }

		   void DrawCustomBorder(Object^ object, PaintEventArgs^ e)
		   {
			   Label^ label = safe_cast<Label^>(object);
			   System::Drawing::Graphics^ g = e->Graphics;
			   System::Drawing::Pen^ topPen = gcnew System::Drawing::Pen(System::Drawing::Color::Gray, 0.2f);
			   System::Drawing::Pen^ bottomPen = gcnew System::Drawing::Pen(System::Drawing::Color::WhiteSmoke, 0.3f);

			   System::Drawing::Rectangle rect = label->ClientRectangle;

			   g->DrawLine(topPen, rect.Left, rect.Top, rect.Right, rect.Top);
			   g->DrawLine(bottomPen, rect.Left, rect.Bottom - 1, rect.Right, rect.Bottom - 1);
		   }

		   static System::Collections::Generic::Dictionary<String^, System::Drawing::Image^>^ resizedImageCache = gcnew System::Collections::Generic::Dictionary<String^, System::Drawing::Image^>();

		    //Function to resize image only if not cached
		   System::Drawing::Image^ GetResizedImage(String^ imageName, int width, int height) {
			    //Check if the resized image already exists in the cache
			   if (resizedImageCache->ContainsKey(imageName)) {
				    //Return the cached resized image
				   return resizedImageCache[imageName];
			   }

			   // Load the original image from resources
			   System::Drawing::Image^ originalImage = ImageHelper::GetImageResource(imageName);
			   if (originalImage == nullptr) {
				   originalImage = ImageHelper::GetImageResource("Unknown");
			   }

			    //Resize the image
			   System::Drawing::Image^ resizedImage = ResizeImage(originalImage, width, height);

			    //Cache the resized image for future use
			   resizedImageCache[imageName] = resizedImage;

			    //Return the resized image
			   return resizedImage;
		   }

		   void LoadPlayers(int start) {
			    //Tải dữ liệu cầu thủ từ danh sách hoặc cơ sở dữ liệu
			   std::vector<Player> player = this->tour->CFplayers;
			   if (startIndex >= player.size()) return;
			   int endIndex = start + 11;
			   if (start + 11 >= player.size()) {
				   endIndex = player.size();
			   }
			   for (int i = start; i < endIndex; i++) {
				   AddRowToTable(
					   gcnew String(player[i].getId().c_str()),
					   gcnew String(std::to_string(player[i].getTId()).c_str()),
					   gcnew String(player[i].get_Name().c_str()),
					   gcnew String(player[i].getTeam()->get_name().c_str()),
					   gcnew String(player[i].get_nation().c_str()),
					   gcnew String(player[i].getPosition().c_str()),
					   gcnew String(player[i].get_birth().c_str()),
					   gcnew String(std::to_string(player[i].getNum()).c_str()),
					   gcnew String(std::to_string(player[i].get_weight()).c_str()),
					   gcnew String(std::to_string(player[i].get_height()).c_str()),
					   false
				   );
			   }
			   startIndex += 11;
		   }

		   void OnPlayerGridScroll(Object^ sender, ScrollEventArgs^ e) {
			   int scrollableHeight = this->playerPanel->VerticalScroll->Maximum - this->playerPanel->VerticalScroll->LargeChange;

			   if (this->playerPanel->VerticalScroll->Value >= scrollableHeight) {
				   LoadPlayers(startIndex);
			   }
		   }

		   void OnMouseWheel(Object^ sender, MouseEventArgs^ e)
		   {
			   // Kiểm tra xem cuộn chuột có tới cuối panel hay không
			   int scrollableHeight = this->playerPanel->VerticalScroll->Maximum - this->playerPanel->VerticalScroll->LargeChange;

			   // Nếu cuộn chuột đi xuống và thanh cuộn gần đến cuối, load thêm người chơi
			   if (e->Delta < 0 && this->playerPanel->VerticalScroll->Value >= scrollableHeight)
			   {
				   LoadPlayers(startIndex);
			   }
		   }

		   void OnReverseClicked(Object^ sender, EventArgs^ e) {
			   this->playerTable->Controls->Clear(); // Xóa tất cả các điều khiển trong bảng
			   this->playerTable->RowStyles->Clear(); // Xóa các hàng
			   this->playerTable->ColumnStyles->Clear(); // Xóa các cột
			   this->playerTable->RowCount = 0; // Đặt lại số lượng hàng
			   this->playerTable->ColumnCount = 8; // Đặt lại số lượng cột
			   startIndex = 0;
			   std::vector<Player> temp = this->tour->CFplayers;
			   for (int i = 0, num = temp.size(); i < num; i++) {
				   this->tour->CFplayers[i] = temp[num - i - 1];
			   }
			   AddRowToTable("0", "0", "Player", "Club", "Nationality", "Position", "DOB", "Jersey", "Weight", "Height", true);
			   LoadPlayers(startIndex);
		   }

		   void OnMouseEnterPlayer(Object^ sender, EventArgs^ e)
		   {
			   Label^ label = safe_cast<Label^>(sender);
			   label->Font = gcnew System::Drawing::Font(
				   label->Font,
				   label->Font->Style | FontStyle::Bold
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
