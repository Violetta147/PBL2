#pragma once
#include "include/Tournament.h"
#include "NewPlayer.h"
#include "Ultility.h"
#include "include/Coach.h"

namespace Form2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Resources;

	/// <summary>
	/// Summary for AddTeam
	/// </summary>
	public ref class AddTeam : public System::Windows::Forms::Form
	{
	public:
		AddTeam(Tournament* tour)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			InitializeYearComboBox();
			this->tour = tour;
			PopulateUnusedIDsToComboBox();
			InitializeCoaches();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddTeam()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::ComboBox^ foundedYearBox;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
		   array<String^>^ years;
	public: Tournament* tour;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	public:	 BindingList<WrapperPlayer^>^ wrappedPlayers = gcnew BindingList<WrapperPlayer^>();
	private: DataTable^ sourceTable;
	private: DataTable^ targetTable;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ btnFinish;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: DataTable^ coachTable;
	private: System::Windows::Forms::Button^ btnChooseLogo;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   String^ logoFilePath1;
		   String^ logoFilePath2;
		   bool stateLoaded = false;
	private: System::Windows::Forms::Button^ btnChooseLogo2;

	private: System::Windows::Forms::PictureBox^ pictureBox2;



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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btnChooseLogo = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->foundedYearBox = (gcnew System::Windows::Forms::ComboBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnFinish = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnChooseLogo2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 22);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(879, 504);
			this->tabControl1->TabIndex = 0;
			this->tabControl1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AddTeam::tabControl1_MouseClick);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->pictureBox2);
			this->tabPage1->Controls->Add(this->btnChooseLogo2);
			this->tabPage1->Controls->Add(this->btnChooseLogo);
			this->tabPage1->Controls->Add(this->pictureBox1);
			this->tabPage1->Controls->Add(this->dataGridView3);
			this->tabPage1->Controls->Add(this->comboBox1);
			this->tabPage1->Controls->Add(this->foundedYearBox);
			this->tabPage1->Controls->Add(this->textBox4);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(871, 478);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// btnChooseLogo
			// 
			this->btnChooseLogo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnChooseLogo->Location = System::Drawing::Point(22, 326);
			this->btnChooseLogo->Name = L"btnChooseLogo";
			this->btnChooseLogo->Size = System::Drawing::Size(103, 84);
			this->btnChooseLogo->TabIndex = 13;
			this->btnChooseLogo->Text = L"ChooseImgDefault";
			this->btnChooseLogo->UseVisualStyleBackColor = true;
			this->btnChooseLogo->Click += gcnew System::EventHandler(this, &AddTeam::btnChooseLogo_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(148, 287);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(257, 149);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Location = System::Drawing::Point(481, 20);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->Size = System::Drawing::Size(369, 253);
			this->dataGridView3->TabIndex = 11;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(154, 20);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 10;
			// 
			// foundedYearBox
			// 
			this->foundedYearBox->FormattingEnabled = true;
			this->foundedYearBox->Location = System::Drawing::Point(154, 252);
			this->foundedYearBox->Name = L"foundedYearBox";
			this->foundedYearBox->Size = System::Drawing::Size(121, 21);
			this->foundedYearBox->TabIndex = 9;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(154, 192);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(305, 20);
			this->textBox4->TabIndex = 8;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(154, 138);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(154, 78);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(305, 20);
			this->textBox2->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::LawnGreen;
			this->label5->Location = System::Drawing::Point(25, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 23);
			this->label5->TabIndex = 4;
			this->label5->Text = L"TEAM ID";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::LawnGreen;
			this->label4->Location = System::Drawing::Point(25, 250);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(114, 23);
			this->label4->TabIndex = 3;
			this->label4->Text = L"FOUNDED YEAR";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::LawnGreen;
			this->label3->Location = System::Drawing::Point(25, 190);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 23);
			this->label3->TabIndex = 2;
			this->label3->Text = L"STADIUM";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::LawnGreen;
			this->label2->Location = System::Drawing::Point(25, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ABBREVIATION";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::LawnGreen;
			this->label1->Location = System::Drawing::Point(25, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TEAM NAME";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->button1);
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(871, 478);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(371, 382);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(118, 55);
			this->button3->TabIndex = 4;
			this->button3->Text = L"ADD NEW PLAYER";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AddTeam::button3_MouseClick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(586, 382);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(118, 55);
			this->button2->TabIndex = 3;
			this->button2->Text = L"DELETE FROM LIST";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AddTeam::button2_MouseClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(156, 382);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(118, 55);
			this->button1->TabIndex = 2;
			this->button1->Text = L"ADD TO LIST";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AddTeam::button1_MouseClick);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(456, 25);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(386, 296);
			this->dataGridView2->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(33, 25);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(385, 296);
			this->dataGridView1->TabIndex = 0;
			// 
			// btnFinish
			// 
			this->btnFinish->BackColor = System::Drawing::Color::LawnGreen;
			this->btnFinish->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFinish->Location = System::Drawing::Point(148, 532);
			this->btnFinish->Name = L"btnFinish";
			this->btnFinish->Size = System::Drawing::Size(131, 62);
			this->btnFinish->TabIndex = 1;
			this->btnFinish->Text = L"FINISH";
			this->btnFinish->UseVisualStyleBackColor = false;
			this->btnFinish->Click += gcnew System::EventHandler(this, &AddTeam::btnFinish_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::Color::Crimson;
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold));
			this->btnCancel->Location = System::Drawing::Point(601, 532);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(122, 62);
			this->btnCancel->TabIndex = 2;
			this->btnCancel->Text = L"CANCEL";
			this->btnCancel->UseVisualStyleBackColor = false;
			this->btnCancel->Click += gcnew System::EventHandler(this, &AddTeam::btnCancel_Click);
			// 
			// btnChooseLogo2
			// 
			this->btnChooseLogo2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnChooseLogo2->Location = System::Drawing::Point(444, 326);
			this->btnChooseLogo2->Name = L"btnChooseLogo2";
			this->btnChooseLogo2->Size = System::Drawing::Size(106, 84);
			this->btnChooseLogo2->TabIndex = 14;
			this->btnChooseLogo2->Text = L"ChooseImgHover";
			this->btnChooseLogo2->UseVisualStyleBackColor = true;
			this->btnChooseLogo2->Click += gcnew System::EventHandler(this, &AddTeam::btnChooseLogo2_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(593, 287);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(257, 149);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 15;
			this->pictureBox2->TabStop = false;
			// 
			// AddTeam
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(916, 606);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnFinish);
			this->Controls->Add(this->tabControl1);
			this->Name = L"AddTeam";
			this->Text = L"AddTeam";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
		void InitializeYearComboBox()
		{
			years = gcnew array<String^>(3000 - 1700 + 1);
			for (int i = 1700; i <= 3000; i++)
			{
				years[i - 1700] = i.ToString();
			}
			foundedYearBox->Items->AddRange(years);
			foundedYearBox->SelectedIndex = 124;
		}
		void PopulateUnusedIDsToComboBox()
		{
			int team_required_temp = tour->getReq();
			array<bool>^ idMask = gcnew array<bool>(team_required_temp + 1);//auto set to false

			for each (auto team in tour->getTeams())
			{
				int id = team.get_id();
				idMask[id] = true;
			}

			for (int i = 1; i <= team_required_temp; i++)
			{
				if (!idMask[i])
				{
					comboBox1->Items->Add(i.ToString());
				}
			}
			if (comboBox1->Items->Count > 0)
			comboBox1->SelectedIndex = 0; //doesn't need check count > 0 cuz must have check before
		}
		void InitializePlayers()
		{	
				int count = tour->get_player_count();
				for (int i = 0; i < count; i++)
				{
					Player player = tour->getPlayer(i);
					if (player.getTId() == -1 || player.getTeam() == nullptr)
						wrappedPlayers->Add(gcnew WrapperPlayer(&player));
				}
		}
		void InitializeTables()
		{	
				sourceTable = gcnew DataTable();
				sourceTable->Columns->Add("SELECT", bool::typeid);
				sourceTable->Columns->Add("PLAYER ID", String::typeid);
				sourceTable->Columns->Add("NAME", String::typeid);
				sourceTable->Columns->Add("JERSEY NUMBER", int::typeid); //maybe nullable
				sourceTable->Columns->Add("POSITION", String::typeid);

				for each (auto player in wrappedPlayers)
				{
					sourceTable->Rows->Add(false, player->PlayerID, player->PlayerName, player->JerseyNum, player->Position);
				}

				dataGridView1->DataSource = sourceTable;

				targetTable = gcnew DataTable();
				targetTable->Columns->Add("SELECT", bool::typeid);
				targetTable->Columns->Add("PLAYER ID", String::typeid);
				targetTable->Columns->Add("NAME", String::typeid);
				targetTable->Columns->Add("JERSEY NUMBER", int::typeid); //maybe nullable
				targetTable->Columns->Add("POSITION", String::typeid);

				dataGridView2->DataSource = targetTable;
				targetTable->DefaultView->Sort = "PLAYER ID ASC";
				sourceTable->DefaultView->Sort = "PLAYER ID ASC";
		}
		void InitializeCoaches()
		{
			coachTable = gcnew DataTable();
			coachTable->Columns->Add("SELECT", bool::typeid);
			coachTable->Columns->Add("COACH ID", String::typeid);
			coachTable->Columns->Add("NAME", String::typeid);

			for (int i = 0; i < tour->get_coach_count(); i++)
			{	
				Coach* coach = tour->getCoach(i);
				if (coach->get_TId() == -1 || coach->get_team() == nullptr)
				coachTable->Rows->Add(false, gcnew String(coach->get_id().c_str()), gcnew String(coach->get_Name().c_str()));
			}
			coachTable->DefaultView->Sort = "COACH ID ASC";
			dataGridView3->DataSource = coachTable;		
		}
		private: System::Void tabControl1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (!stateLoaded)
			{
				InitializePlayers();
				InitializeTables();
				stateLoaded = true;
			}
}

#pragma endregion
private: System::Void button1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	for (int i = sourceTable->Rows->Count - 1; i >= 0; i--)
	{
		DataRow^ row = sourceTable->Rows[i];
		if (Convert::ToBoolean(row["SELECT"]))
		{
			targetTable->Rows->Add(row->ItemArray);
			sourceTable->Rows->Remove(row);
		}
	}
	//Sort targetTable
	dataGridView1->Refresh();
	dataGridView2->Refresh();
}
private: System::Void button2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	//add selected rows from targetTable to sourceTable
	for (int i = targetTable->Rows->Count - 1; i >= 0; i--)
	{
		DataRow^ row = targetTable->Rows[i];
		if (Convert::ToBoolean(row["SELECT"]))
		{
			sourceTable->Rows->Add(row->ItemArray);
			targetTable->Rows->Remove(row);
		}
	}

	//Sort targetTable
	dataGridView1->Refresh();
	dataGridView2->Refresh();
}
private: System::Void button3_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Form^ addPlayer = gcnew NewPlayer(tour);
	addPlayer->ShowDialog();
}
private: System::Void btnFinish_Click(System::Object^ sender, System::EventArgs^ e) {

	if (textBox2->Text == "" || textBox3->Text == "" || textBox4->Text == "")
	{
		MessageBox::Show("Please fill all fields", "Missing Fields", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (comboBox1->SelectedIndex == -1)
	{
		MessageBox::Show("Please select a team id", "Missing Fields", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (foundedYearBox->SelectedIndex == -1)
	{
		MessageBox::Show("Please select a founded year", "Missing Fields", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (targetTable->Rows->Count == 0)
	{
		MessageBox::Show("Please add players to the team", "Missing Players", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	String^ team_name = textBox2->Text;
	String^ abbreviation = textBox3->Text;
	String^ stadium = textBox4->Text;
	int team_id = Convert::ToInt32(comboBox1->SelectedItem->ToString());
	int founded_year = Convert::ToInt32(foundedYearBox->SelectedItem->ToString());

	std::string team_name_string;
	std::string abbreviation_string;
	std::string stadium_string;

	Ultility::StringToStlString(team_name, team_name_string);
	Ultility::StringToStlString(abbreviation, abbreviation_string);
	Ultility::StringToStlString(stadium, stadium_string);

	//create team
	Team* team = new Team(team_id, team_name_string, abbreviation_string, stadium_string, founded_year);
	//add players to team
	for (int i = 0; i < targetTable->Rows->Count; i++)
	{
		DataRow^ row = targetTable->Rows[i];
		String^ player_id = row["PLAYER ID"]->ToString();
		std::string player_id_string;
		Ultility::StringToStlString(player_id, player_id_string);
		Player* player = tour->find_player_by_id(player_id_string);
		team->add_player(player);
		player->setTeam(team);
		player->setTId(team_id);
	}
	//add coach to team
	for (int i = 0; i < coachTable->Rows->Count; i++)
	{
		DataRow^ row = coachTable->Rows[i];
		if (Convert::ToBoolean(row["SELECT"]))
		{
			String^ coach_id = row["COACH ID"]->ToString();
			std::string coach_id_string;
			Ultility::StringToStlString(coach_id, coach_id_string);
			Coach* coach = tour->find_coach_by_id(coach_id_string);
			team->add_coach(coach);
			coach->set_team(team);
			coach->set_TId(team_id);
		}
	}
	tour->addTeam(*team);
	tour->write_player();
	tour->write_coach();
	tour->write_team();
	if (logoFilePath1 != nullptr)
	{
		String^ resourceDir = "Resources\\";
		String^ newFileName = resourceDir + gcnew String(team->get_name().c_str()) + "_Default.png";
		System::IO::File::Copy(logoFilePath1, newFileName, true);
	}
	if (logoFilePath2 != nullptr)
	{
		String^ resourceDir = "Resources\\";
		String^ newFileName2 = resourceDir + gcnew String(team->get_name().c_str()) + "_Hover.png";
		System::IO::File::Copy(logoFilePath2, newFileName2, true);
	}
	this->Close();
}
private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnChooseLogo_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
	openFileDialog->Filter = "Image Files(*.BMP;*.JPG;*.GIF;*.PNG)|*.BMP;*.JPG;*.GIF;*.PNG|All files (*.*)|*.*";
	openFileDialog->FilterIndex = 1;
	openFileDialog->RestoreDirectory = true;


	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		logoFilePath1 = openFileDialog->FileName;
		pictureBox1->Image = Image::FromFile(logoFilePath1);
	}
}
private: System::Void btnChooseLogo2_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
	openFileDialog->Filter = "Image Files(*.BMP;*.JPG;*.GIF;*.PNG)|*.BMP;*.JPG;*.GIF;*.PNG|All files (*.*)|*.*";
	openFileDialog->FilterIndex = 1;
	openFileDialog->RestoreDirectory = true;

	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		logoFilePath2 = openFileDialog->FileName;
		pictureBox2->Image = Image::FromFile(logoFilePath2);
	}
}
};
}
