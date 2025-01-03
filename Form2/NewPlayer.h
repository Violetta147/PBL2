#pragma once
#include "include/Tournament.h"
#include "WrapperPlayer.h"
#include "Ultility.h"
namespace Form2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for NewPlayer
	/// </summary>
	public ref class NewPlayer : public System::Windows::Forms::Form
	{
	public:
		NewPlayer(Tournament* tour, String^ TID)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//so the components like datagridview will load data before Load method so i need to have this->tour = tour; here
			this->tour = tour;
			this->TID = TID;
			this->Load += gcnew EventHandler(this, &NewPlayer::NewPlayer_Load);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NewPlayer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:




	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;

	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ AddButton;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
		   Tournament* tour;
		   String^ TID;
	public:	 BindingList<WrapperPlayer^>^ wrappedPlayers = gcnew BindingList<WrapperPlayer^>();
		  DataTable^ player_data_table;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnFirst;
	private: System::Windows::Forms::Button^ btnPrev;
	private: System::Windows::Forms::Button^ btnNext;
	private: System::Windows::Forms::Button^ btnLast;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ lblTotalRows;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ lblCurrentPage;

	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ lblTotalPages;

	private: const int pageSize = 20;
	private: int currentPageIndex = 1;
	private: int totalPages = 0;
	private: int totalRows = 0;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: CustomControls::RJButton^ rjButton1;
	private: System::Windows::Forms::ComboBox^ comboBox2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NewPlayer::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->btnFirst = (gcnew System::Windows::Forms::Button());
			this->btnPrev = (gcnew System::Windows::Forms::Button());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->btnLast = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lblTotalRows = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->lblCurrentPage = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->lblTotalPages = (gcnew System::Windows::Forms::Label());
			this->rjButton1 = (gcnew CustomControls::RJButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox1->Location = System::Drawing::Point(148, 19);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(296, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(4, 0);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 59);
			this->label1->TabIndex = 5;
			this->label1->Text = L"HUMAN ID";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(4, 118);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 59);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Last Name";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(4, 59);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(136, 59);
			this->label4->TabIndex = 8;
			this->label4->Text = L"First Name";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox2->Location = System::Drawing::Point(148, 78);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(296, 20);
			this->textBox2->TabIndex = 10;
			// 
			// textBox3
			// 
			this->textBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox3->Location = System::Drawing::Point(148, 137);
			this->textBox3->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(296, 20);
			this->textBox3->TabIndex = 11;
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(467, 41);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(779, 574);
			this->dataGridView1->TabIndex = 14;
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(148, 196);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(296, 21);
			this->comboBox1->TabIndex = 15;
			// 
			// label2
			// 
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(4, 177);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(136, 59);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Country";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->dateTimePicker1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->dateTimePicker1->CustomFormat = L"dd-MMM-yyyy";
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(148, 255);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(114, 20);
			this->dateTimePicker1->TabIndex = 17;
			this->dateTimePicker1->Value = System::DateTime(2024, 12, 28, 0, 0, 0, 0);
			// 
			// label5
			// 
			this->label5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(4, 236);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(136, 59);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Birthdate";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(4, 295);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(136, 59);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Weight";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox4
			// 
			this->textBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox4->Location = System::Drawing::Point(148, 314);
			this->textBox4->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(296, 20);
			this->textBox4->TabIndex = 21;
			// 
			// label7
			// 
			this->label7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(4, 354);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(136, 59);
			this->label7->TabIndex = 22;
			this->label7->Text = L"Height";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(4, 413);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(136, 59);
			this->label8->TabIndex = 25;
			this->label8->Text = L"TEAM";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label9
			// 
			this->label9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(4, 472);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(136, 59);
			this->label9->TabIndex = 26;
			this->label9->Text = L"POSITION";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// comboBox3
			// 
			this->comboBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Defender", L"Midfielder", L"Goalkeeper", L"Forward" });
			this->comboBox3->Location = System::Drawing::Point(148, 491);
			this->comboBox3->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(296, 21);
			this->comboBox3->TabIndex = 27;
			// 
			// label10
			// 
			this->label10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(4, 531);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(136, 62);
			this->label10->TabIndex = 28;
			this->label10->Text = L"JERSEY NUM";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox6
			// 
			this->textBox6->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBox6->Location = System::Drawing::Point(148, 552);
			this->textBox6->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(114, 20);
			this->textBox6->TabIndex = 29;
			// 
			// AddButton
			// 
			this->AddButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->AddButton->Location = System::Drawing::Point(783, 699);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(136, 76);
			this->AddButton->TabIndex = 30;
			this->AddButton->Text = L"ADD";
			this->AddButton->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(947, 699);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 76);
			this->button1->TabIndex = 31;
			this->button1->Text = L"UPDATE";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NewPlayer::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(1110, 699);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 76);
			this->button2->TabIndex = 32;
			this->button2->Text = L"DELETE";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				32.36607F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				67.63393F)));
			this->tableLayoutPanel1->Controls->Add(this->comboBox2, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->textBox7, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->label10, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->textBox6, 1, 9);
			this->tableLayoutPanel1->Controls->Add(this->label9, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->comboBox3, 1, 8);
			this->tableLayoutPanel1->Controls->Add(this->label7, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->label8, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->label6, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->dateTimePicker1, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->comboBox1, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox3, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox4, 1, 5);
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 198);
			this->tableLayoutPanel1->MaximumSize = System::Drawing::Size(448, 593);
			this->tableLayoutPanel1->MinimumSize = System::Drawing::Size(448, 593);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 10;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(448, 593);
			this->tableLayoutPanel1->TabIndex = 34;
			// 
			// comboBox2
			// 
			this->comboBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(148, 432);
			this->comboBox2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(296, 21);
			this->comboBox2->TabIndex = 31;
			// 
			// textBox7
			// 
			this->textBox7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox7->Location = System::Drawing::Point(148, 373);
			this->textBox7->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(296, 20);
			this->textBox7->TabIndex = 30;
			// 
			// btnFirst
			// 
			this->btnFirst->Location = System::Drawing::Point(796, 639);
			this->btnFirst->Name = L"btnFirst";
			this->btnFirst->Size = System::Drawing::Size(108, 32);
			this->btnFirst->TabIndex = 35;
			this->btnFirst->Text = L"FIRST";
			this->btnFirst->UseVisualStyleBackColor = true;
			this->btnFirst->Click += gcnew System::EventHandler(this, &NewPlayer::btnFirst_Click);
			// 
			// btnPrev
			// 
			this->btnPrev->Location = System::Drawing::Point(910, 639);
			this->btnPrev->Name = L"btnPrev";
			this->btnPrev->Size = System::Drawing::Size(108, 32);
			this->btnPrev->TabIndex = 36;
			this->btnPrev->Text = L"PREV";
			this->btnPrev->UseVisualStyleBackColor = true;
			this->btnPrev->Click += gcnew System::EventHandler(this, &NewPlayer::btnPrev_Click);
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(1024, 639);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(108, 32);
			this->btnNext->TabIndex = 37;
			this->btnNext->Text = L"NEXT";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Click += gcnew System::EventHandler(this, &NewPlayer::btnNext_Click);
			// 
			// btnLast
			// 
			this->btnLast->Location = System::Drawing::Point(1138, 639);
			this->btnLast->Name = L"btnLast";
			this->btnLast->Size = System::Drawing::Size(108, 32);
			this->btnLast->TabIndex = 38;
			this->btnLast->Text = L"LAST";
			this->btnLast->UseVisualStyleBackColor = true;
			this->btnLast->Click += gcnew System::EventHandler(this, &NewPlayer::btnLast_Click);
			// 
			// label11
			// 
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(467, 11);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(121, 26);
			this->label11->TabIndex = 39;
			this->label11->Text = L"Total Rows:";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblTotalRows
			// 
			this->lblTotalRows->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalRows->Location = System::Drawing::Point(576, 11);
			this->lblTotalRows->Name = L"lblTotalRows";
			this->lblTotalRows->Size = System::Drawing::Size(59, 26);
			this->lblTotalRows->TabIndex = 41;
			this->lblTotalRows->Text = L"0";
			this->lblTotalRows->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(1007, 11);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(121, 26);
			this->label12->TabIndex = 42;
			this->label12->Text = L"Page";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblCurrentPage
			// 
			this->lblCurrentPage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCurrentPage->Location = System::Drawing::Point(1106, 11);
			this->lblCurrentPage->Name = L"lblCurrentPage";
			this->lblCurrentPage->Size = System::Drawing::Size(33, 26);
			this->lblCurrentPage->TabIndex = 43;
			this->lblCurrentPage->Text = L"0";
			this->lblCurrentPage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label15
			// 
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(1134, 11);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(61, 26);
			this->label15->TabIndex = 44;
			this->label15->Text = L"of";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblTotalPages
			// 
			this->lblTotalPages->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalPages->Location = System::Drawing::Point(1191, 11);
			this->lblTotalPages->Name = L"lblTotalPages";
			this->lblTotalPages->Size = System::Drawing::Size(37, 26);
			this->lblTotalPages->TabIndex = 45;
			this->lblTotalPages->Text = L"0";
			this->lblTotalPages->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// rjButton1
			// 
			this->rjButton1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->rjButton1->BackgroundColor = System::Drawing::SystemColors::MenuBar;
			this->rjButton1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"rjButton1.BackgroundImage")));
			this->rjButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->rjButton1->BorderColor = System::Drawing::Color::PaleVioletRed;
			this->rjButton1->BorderRadius = 40;
			this->rjButton1->BorderSize = 0;
			this->rjButton1->FlatAppearance->BorderSize = 0;
			this->rjButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rjButton1->ForeColor = System::Drawing::Color::White;
			this->rjButton1->Location = System::Drawing::Point(88, 14);
			this->rjButton1->Name = L"rjButton1";
			this->rjButton1->Size = System::Drawing::Size(252, 181);
			this->rjButton1->TabIndex = 46;
			this->rjButton1->TextColor = System::Drawing::Color::White;
			this->rjButton1->UseVisualStyleBackColor = false;
			this->rjButton1->Click += gcnew System::EventHandler(this, &NewPlayer::rjButton1_Click);
			// 
			// NewPlayer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1288, 803);
			this->Controls->Add(this->rjButton1);
			this->Controls->Add(this->lblTotalPages);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->lblCurrentPage);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->lblTotalRows);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->btnLast);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->btnPrev);
			this->Controls->Add(this->btnFirst);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->dataGridView1);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1304, 842);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1304, 842);
			this->Name = L"NewPlayer";
			this->Text = L"NewPlayer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
		void InitializePlayers()
		{	
			if (!this->IdExist())
			{
				int count = tour->get_player_count();
				for (int i = 0; i < count; i++)
				{
					Player player = tour->getPlayer(i);
					wrappedPlayers->Add(gcnew WrapperPlayer(&player));
				}
			}
			else //If is on TEAM MODE
			{
				String^ PID = ExtractPID();
				int TID = Convert::ToInt32(ExtractTID());
				//can use team is tead of tour
				for (int i = 0; i < tour->get_player_count(); ++i)
				{	
					Player player = tour->getPlayer(i);
					if (player.getTId() == TID)
					{	
						wrappedPlayers->Add(gcnew WrapperPlayer(&player));
					}
				}
				AttachDataToControls();
				
			}

		}
		void InitializeTables()
		{	
			if (!this->IdExist())
			{
				player_data_table = gcnew DataTable();
				player_data_table->Columns->Add("PLAYER ID", String::typeid);
				player_data_table->Columns->Add("NAME", String::typeid);
				player_data_table->Columns->Add("JERSEY NUMBER", int::typeid); //maybe nullable
				player_data_table->Columns->Add("POSITION", String::typeid);
				player_data_table->Columns->Add("TEAM NAME", String::typeid);
				InitializePlayers();

				totalRows = wrappedPlayers->Count;
				totalPages = (int)Math::Ceiling((double)totalRows / pageSize);
				lblTotalPages->Text = totalPages.ToString();

				LoadPageData();
				InitializeComboBox2();
				InitializeComboBox1();


				dataGridView1->DataSource = player_data_table;
				player_data_table->DefaultView->Sort = "PLAYER ID ASC";
			}
			else
			{
				player_data_table = gcnew DataTable();
				player_data_table->Columns->Add("PLAYER ID", String::typeid);
				player_data_table->Columns->Add("NAME", String::typeid);
				player_data_table->Columns->Add("JERSEY NUMBER", int::typeid); //maybe nullable
				player_data_table->Columns->Add("POSITION", String::typeid);
				player_data_table->Columns->Add("GOALS", int::typeid);
				player_data_table->Columns->Add("ASSISTS", int::typeid);
				player_data_table->Columns->Add("RED CARDS", int::typeid);
				player_data_table->Columns->Add("YELLOW CARDS", int::typeid);
				player_data_table->Columns->Add("MATCH PLAYED", int::typeid);
				player_data_table->Columns->Add("IS BAN", bool::typeid);
				InitializePlayers();
				totalRows = wrappedPlayers->Count;
				totalPages = (int)Math::Ceiling((double)totalRows / pageSize);
				lblTotalPages->Text = totalPages.ToString();
				LoadPageData();
				InitializeComboBox2();
				InitializeComboBox1();
				dataGridView1->DataSource = player_data_table;
				//group rows player_data_table by POSITION(bad)
				player_data_table->DefaultView->Sort = "POSITION ASC";
			}	
		}
		void NewPlayer_Load(System::Object^ sender, System::EventArgs^ e)
		{	
			InitializeTables();
		}
		void LoadPageData()
		{
			player_data_table->Clear();
			int startIndex = (currentPageIndex - 1) * pageSize;
			int endIndex = Math::Min(startIndex + pageSize, totalRows);

			if (!this->IdExist())
			{
				for (int i = startIndex; i < endIndex; i++)
				{
					auto player = wrappedPlayers[i];
					player_data_table->Rows->Add(
						player->PlayerID,
						player->PlayerName,
						player->JerseyNum,
						player->Position,
						player->TeamName
					);
				}
			}
			else
			{
				for (int i = startIndex; i < endIndex; i++)
				{
					auto player = wrappedPlayers[i];
					player_data_table->Rows->Add(
						player->PlayerID,
						player->PlayerName,
						player->JerseyNum,
						player->Position,
						player->Goal,
						player->Assist,
						player->RedCard,
						player->YellowCard,
						player->Match,
						player->IsBan
					);
				}
			}

			UpdatePaginationLabels();
		}
		void UpdatePaginationLabels()
		{
			lblTotalRows->Text = totalRows.ToString();
			lblCurrentPage->Text = currentPageIndex.ToString();
			lblTotalPages->Text = totalPages.ToString();
		}
#pragma endregion
	private: System::Void btnFirst_Click(System::Object^ sender, System::EventArgs^ e) {
		if (currentPageIndex != 1) {
			currentPageIndex = 1;
			LoadPageData();
		}
	}
private: System::Void btnPrev_Click(System::Object^ sender, System::EventArgs^ e) {
	if (currentPageIndex > 1) {
		currentPageIndex--;
		LoadPageData();
	}
}
private: System::Void btnNext_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (currentPageIndex < totalPages) {
		currentPageIndex++;
		LoadPageData();
	}
}
	private: System::Void btnLast_Click(System::Object^ sender, System::EventArgs^ e) {
		if (currentPageIndex != totalPages) {
			currentPageIndex = totalPages;
			LoadPageData();
		}
}
	private:	   bool IdExist() {
		//compare null
		//TID|PID
		//extract TID and check if PID Exist by cutting
		if (TID->Contains("|"))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	private: String^ ExtractPID()
	{
		if (IdExist())
		{
			int index = TID->IndexOf("|");
			return TID->Substring(index + 1);
		}
		else
		{
			return TID;
		}
	}
	private: String^ ExtractTID()
	{
			int index = TID->IndexOf("|");
			return TID->Substring(0, index);
	}
		   private: System::Void AttachDataToControls()
		   {	
			   for each (WrapperPlayer ^ player in wrappedPlayers)
			   {
				   if (player->PlayerID == this->ExtractPID())
				   {	
					   textBox1->Text = player->CCCD;
					   textBox2->Text = player->getFirstName();
					   textBox3->Text = player->getLastName();
					   comboBox1->Text = player->Nation;
					   Ultility::SetDateTimePickerValue(this->dateTimePicker1, player->DateOfBirth);
					   textBox4->Text = player->Weight.ToString();
					   textBox7->Text = player->Height.ToString();
					   comboBox2->Text = player->TeamName;
					   comboBox3->Text = player->Position;
					   textBox6->Text = player->JerseyNum.ToString();
					   break;
				   }
			   }
			  
		   }
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	if (this->IdExist())
	{
		String^ PID = ExtractPID();
		int TID = Convert::ToInt32(ExtractTID());
		//check if the value of the player is the same as the value in the text box if not update and also check if the value is valid
		if (this->IdExist())
		{
			String^ PID = ExtractPID();
			int TID = Convert::ToInt32(ExtractTID());

			for each (WrapperPlayer ^ player in wrappedPlayers)
			{
				if (player->PlayerID == PID)
				{	
					std::string PIDStr;
					Ultility::StringToStlString(PID, PIDStr);
					player->CCCD = textBox1->Text;
					player->setFirstName(textBox2->Text);
					player->setLastName(textBox3->Text);
					player->Nation = comboBox1->Text;
					player->Position = comboBox3->Text;
					player->JerseyNum = Convert::ToInt32(textBox6->Text);


					//Update birthday
					std::string newBirthDateStr;
					String^ newBirthDate = dateTimePicker1->Value.ToString("dd-MM-yyyy");
					Ultility::StringToStlString(newBirthDate, newBirthDateStr);
					player->DateOfBirth = newBirthDate;
					
					if (comboBox2->SelectedItem != nullptr)
					{
						KeyValuePair<int, String^>^ selectedTeam = (KeyValuePair<int, String^>^)comboBox2->SelectedItem;
						player->TeamName = selectedTeam->Value;
						player->TeamID = selectedTeam->Key;
					}
					else
					{
						player->TeamName = "";
						player->TeamID = -1;
					}
					player->Weight = Convert::ToInt32(textBox4->Text);
					player->Height = Convert::ToInt32(textBox7->Text);
					//update player in native c++ and save to file
					std::string CCCDStr;
					std::string firstNameStr;
					std::string lastNameStr;
					std::string nationStr;
					std::string positionStr;
					std::string teamIDStr = std::to_string(player->TeamID);
					std::string weightStr = std::to_string(player->Weight);
					std::string heightStr = std::to_string(player->Height);
					std::string jerseyNumStr = std::to_string(player->JerseyNum);
					Ultility::StringToStlString(player->CCCD, CCCDStr);
					Ultility::StringToStlString(player->getFirstName(), firstNameStr);
					Ultility::StringToStlString(player->getLastName(), lastNameStr);
					Ultility::StringToStlString(player->Nation, nationStr);
					Ultility::StringToStlString(player->Position, positionStr);
					//update player in native c++ and save to file
					Player newInformation(CCCDStr, firstNameStr, lastNameStr, nationStr,
						newBirthDateStr, player->Height, player->Weight, PIDStr, player->JerseyNum, TID, positionStr);
					tour->edit_player(newInformation);
					//update player in managed c++
					InitializeTables();
					MessageBox::Show("Player information has been updated successfully!");
					break;  
				}
			}
		}
		else
		{
			MessageBox::Show("Player ID does not exist. You may not in TEAM MODE");
		}
	}
	
}
	private: System::Void InitializeComboBox2()
	   {
		   Dictionary<int, String^>^ teamList = gcnew Dictionary<int, String^>();
		   for (int i = 1; i <= tour->getReq(); i++)
		   {	
			   if (tour->find_team_by_id(i) == nullptr)
			   {
				   continue;
			   }
			   teamList->Add(i, gcnew String(tour->find_team_by_id(i)->get_name().c_str()));
		   }
		   BindingSource^ bindingSource = gcnew BindingSource();
		   bindingSource->DataSource = teamList;

		   comboBox2->DataSource = bindingSource;
		   comboBox2->DisplayMember = "Value";
		   comboBox2->ValueMember = "Key";
		   //check if ADD NEW TEAM MODE THEN ADD THE NAME OF NEW TEAM TO COMBOBOX
	   }
	   private: System::Void InitializeComboBox1()
	   {
		   comboBox1->Items->Clear();
		   Console::WriteLine("InitializeComboBox1");
		   System::IO::StreamReader^ sr = gcnew System::IO::StreamReader("C:/Users/LAPTOP T&T/source/repos/Violetta147/PBL2/Form2/file-handling/country.txt");
		   String^ line;
		   while ((line = sr->ReadLine()) != nullptr)
		   {
			   comboBox1->Items->Add(line);
		   }
		   sr->Close();
	   }
};
}
