#pragma once

namespace Accuracy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:









	private: System::Windows::Forms::Button^ button_clients;
	private: System::Windows::Forms::Button^ button_regular;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::Button^ button_empty;
	private: System::Windows::Forms::TextBox^ textBox_empty;


	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button_date;
	private: System::Windows::Forms::TextBox^ textBox_date;


	private: System::Windows::Forms::Label^ label2;










	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fAQПоДействиямToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ просмотрСпискаКлиентовToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ просмотрПостоянныхКлиентовToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ добавлениеНовогоКлиентаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ поискКлиентовОпределенногоОкругаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ поискКлиентовСДоговоромИстекающимНаОпределеннуюДатуToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::ToolStripMenuItem^ удалениеКлиентаToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID_client;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Company_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Contact_person;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Phone_number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ District;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID_contract;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Contract_conclusion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Contract_expiration;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number_of_contract;
















































	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID_client = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Company_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Contact_person = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Phone_number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->District = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ID_contract = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Contract_conclusion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Contract_expiration = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Number_of_contract = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button_clients = (gcnew System::Windows::Forms::Button());
			this->button_regular = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_empty = (gcnew System::Windows::Forms::Button());
			this->textBox_empty = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button_date = (gcnew System::Windows::Forms::Button());
			this->textBox_date = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fAQПоДействиямToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->просмотрСпискаКлиентовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->просмотрПостоянныхКлиентовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->добавлениеНовогоКлиентаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удалениеКлиентаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->поискКлиентовОпределенногоОкругаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->поискКлиентовСДоговоромИстекающимНаОпределеннуюДатуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->ID_client,
					this->Company_name, this->Contact_person, this->Phone_number, this->District, this->ID_contract, this->Contract_conclusion, this->Contract_expiration,
					this->Number_of_contract
			});
			this->dataGridView1->Location = System::Drawing::Point(18, 150);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(910, 386);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::DataGridView1_CellContentClick);
			// 
			// ID_client
			// 
			this->ID_client->HeaderText = L"ID";
			this->ID_client->MinimumWidth = 6;
			this->ID_client->Name = L"ID_client";
			this->ID_client->Width = 43;
			// 
			// Company_name
			// 
			this->Company_name->HeaderText = L"ФИО";
			this->Company_name->MinimumWidth = 6;
			this->Company_name->Name = L"Company_name";
			this->Company_name->Width = 59;
			// 
			// Contact_person
			// 
			this->Contact_person->HeaderText = L"Паспорт";
			this->Contact_person->MinimumWidth = 6;
			this->Contact_person->Name = L"Contact_person";
			this->Contact_person->Width = 75;
			// 
			// Phone_number
			// 
			this->Phone_number->HeaderText = L"Город";
			this->Phone_number->MinimumWidth = 6;
			this->Phone_number->Name = L"Phone_number";
			this->Phone_number->Width = 62;
			// 
			// District
			// 
			this->District->HeaderText = L"Дата заселения";
			this->District->MinimumWidth = 6;
			this->District->Name = L"District";
			this->District->Width = 105;
			// 
			// ID_contract
			// 
			this->ID_contract->HeaderText = L"Дата выселения";
			this->ID_contract->MinimumWidth = 6;
			this->ID_contract->Name = L"ID_contract";
			this->ID_contract->Width = 107;
			// 
			// Contract_conclusion
			// 
			this->Contract_conclusion->HeaderText = L"Наличие завтрака";
			this->Contract_conclusion->MinimumWidth = 6;
			this->Contract_conclusion->Name = L"Contract_conclusion";
			this->Contract_conclusion->Width = 114;
			// 
			// Contract_expiration
			// 
			this->Contract_expiration->HeaderText = L"Номер комнаты";
			this->Contract_expiration->MinimumWidth = 6;
			this->Contract_expiration->Name = L"Contract_expiration";
			this->Contract_expiration->Width = 105;
			// 
			// Number_of_contract
			// 
			this->Number_of_contract->HeaderText = L"Телефон";
			this->Number_of_contract->MinimumWidth = 6;
			this->Number_of_contract->Name = L"Number_of_contract";
			this->Number_of_contract->Width = 77;
			// 
			// button_clients
			// 
			this->button_clients->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_clients->Location = System::Drawing::Point(4, 22);
			this->button_clients->Margin = System::Windows::Forms::Padding(2);
			this->button_clients->Name = L"button_clients";
			this->button_clients->Size = System::Drawing::Size(148, 32);
			this->button_clients->TabIndex = 1;
			this->button_clients->Text = L"Все клиенты";
			this->button_clients->UseVisualStyleBackColor = true;
			this->button_clients->Click += gcnew System::EventHandler(this, &MyForm::button_clients_Click);
			// 
			// button_regular
			// 
			this->button_regular->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_regular->Location = System::Drawing::Point(4, 67);
			this->button_regular->Margin = System::Windows::Forms::Padding(2);
			this->button_regular->Name = L"button_regular";
			this->button_regular->Size = System::Drawing::Size(148, 32);
			this->button_regular->TabIndex = 2;
			this->button_regular->Text = L"Долгожители";
			this->button_regular->UseVisualStyleBackColor = true;
			this->button_regular->Click += gcnew System::EventHandler(this, &MyForm::button_regular_Click);
			// 
			// button_add
			// 
			this->button_add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_add->Location = System::Drawing::Point(4, 22);
			this->button_add->Margin = System::Windows::Forms::Padding(2);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(148, 32);
			this->button_add->TabIndex = 3;
			this->button_add->Text = L"Добавить клиента";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::button_add_Click);
			// 
			// button_empty
			// 
			this->button_empty->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_empty->Location = System::Drawing::Point(188, 24);
			this->button_empty->Margin = System::Windows::Forms::Padding(2);
			this->button_empty->Name = L"button_empty";
			this->button_empty->Size = System::Drawing::Size(112, 32);
			this->button_empty->TabIndex = 4;
			this->button_empty->Text = L"Поиск номера";
			this->button_empty->UseVisualStyleBackColor = true;
			this->button_empty->Click += gcnew System::EventHandler(this, &MyForm::button_empty_Click);
			// 
			// textBox_empty
			// 
			this->textBox_empty->Location = System::Drawing::Point(4, 35);
			this->textBox_empty->Margin = System::Windows::Forms::Padding(2);
			this->textBox_empty->Name = L"textBox_empty";
			this->textBox_empty->Size = System::Drawing::Size(177, 21);
			this->textBox_empty->TabIndex = 5;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_regular);
			this->groupBox1->Controls->Add(this->button_clients);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(9, 30);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(158, 109);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Просмотр списков";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button_date);
			this->groupBox2->Controls->Add(this->textBox_date);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->button_empty);
			this->groupBox2->Controls->Add(this->textBox_empty);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(365, 30);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(309, 109);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Поиски по дате выселения и свободных номеров";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &MyForm::groupBox2_Enter);
			// 
			// button_date
			// 
			this->button_date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_date->Location = System::Drawing::Point(188, 70);
			this->button_date->Margin = System::Windows::Forms::Padding(2);
			this->button_date->Name = L"button_date";
			this->button_date->Size = System::Drawing::Size(112, 32);
			this->button_date->TabIndex = 9;
			this->button_date->Text = L"Поиск по дате";
			this->button_date->UseVisualStyleBackColor = true;
			this->button_date->Click += gcnew System::EventHandler(this, &MyForm::button_date_Click);
			// 
			// textBox_date
			// 
			this->textBox_date->Location = System::Drawing::Point(4, 80);
			this->textBox_date->Margin = System::Windows::Forms::Padding(2);
			this->textBox_date->Name = L"textBox_date";
			this->textBox_date->Size = System::Drawing::Size(177, 21);
			this->textBox_date->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(2, 64);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Введите дату выселения";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(2, 19);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Введите дату заселения";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->оПрограммеToolStripMenuItem,
					this->fAQПоДействиямToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(946, 24);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(164, 20);
			this->оПрограммеToolStripMenuItem->Text = L"Возможности программы";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::оПрограммеToolStripMenuItem_Click);
			// 
			// fAQПоДействиямToolStripMenuItem
			// 
			this->fAQПоДействиямToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->просмотрСпискаКлиентовToolStripMenuItem,
					this->просмотрПостоянныхКлиентовToolStripMenuItem, this->добавлениеНовогоКлиентаToolStripMenuItem, this->удалениеКлиентаToolStripMenuItem,
					this->поискКлиентовОпределенногоОкругаToolStripMenuItem, this->поискКлиентовСДоговоромИстекающимНаОпределеннуюДатуToolStripMenuItem
			});
			this->fAQПоДействиямToolStripMenuItem->Name = L"fAQПоДействиямToolStripMenuItem";
			this->fAQПоДействиямToolStripMenuItem->Size = System::Drawing::Size(85, 20);
			this->fAQПоДействиямToolStripMenuItem->Text = L"Инструкция";
			this->fAQПоДействиямToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fAQПоДействиямToolStripMenuItem_Click);
			// 
			// просмотрСпискаКлиентовToolStripMenuItem
			// 
			this->просмотрСпискаКлиентовToolStripMenuItem->Name = L"просмотрСпискаКлиентовToolStripMenuItem";
			this->просмотрСпискаКлиентовToolStripMenuItem->Size = System::Drawing::Size(255, 22);
			this->просмотрСпискаКлиентовToolStripMenuItem->Text = L"Просмотр списка клиентов";
			this->просмотрСпискаКлиентовToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::просмотрСпискаКлиентовToolStripMenuItem_Click);
			// 
			// просмотрПостоянныхКлиентовToolStripMenuItem
			// 
			this->просмотрПостоянныхКлиентовToolStripMenuItem->Name = L"просмотрПостоянныхКлиентовToolStripMenuItem";
			this->просмотрПостоянныхКлиентовToolStripMenuItem->Size = System::Drawing::Size(230, 22);
			this->просмотрПостоянныхКлиентовToolStripMenuItem->Text = L"Просмотр Долгожителей";
			this->просмотрПостоянныхКлиентовToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::просмотрДолгожителейToolStripMenuItem_Click);
			// 
			// добавлениеНовогоКлиентаToolStripMenuItem
			// 
			this->добавлениеНовогоКлиентаToolStripMenuItem->Name = L"добавлениеНовогоКлиентаToolStripMenuItem";
			this->добавлениеНовогоКлиентаToolStripMenuItem->Size = System::Drawing::Size(255, 22);
			this->добавлениеНовогоКлиентаToolStripMenuItem->Text = L"Добавление нового клиента";
			this->добавлениеНовогоКлиентаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::добавлениеНовогоКлиентаToolStripMenuItem_Click);
			// 
			// удалениеКлиентаToolStripMenuItem
			// 
			this->удалениеКлиентаToolStripMenuItem->Name = L"удалениеКлиентаToolStripMenuItem";
			this->удалениеКлиентаToolStripMenuItem->Size = System::Drawing::Size(255, 22);
			this->удалениеКлиентаToolStripMenuItem->Text = L"Удаление клиента";
			this->удалениеКлиентаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::удалениеКлиентаToolStripMenuItem_Click);
			// 
			// поискКлиентовОпределенногоОкругаToolStripMenuItem
			// 
			this->поискКлиентовОпределенногоОкругаToolStripMenuItem->Name = L"поискКлиентовОпределенногоОкругаToolStripMenuItem";
			this->поискКлиентовОпределенногоОкругаToolStripMenuItem->Size = System::Drawing::Size(255, 22);
			this->поискКлиентовОпределенногоОкругаToolStripMenuItem->Text = L"Поиск свободного номера";
			this->поискКлиентовОпределенногоОкругаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::поискСвободногоНомераToolStripMenuItem_Click);
			// 
			// поискКлиентовСДоговоромИстекающимНаОпределеннуюДатуToolStripMenuItem
			// 
			this->поискКлиентовСДоговоромИстекающимНаОпределеннуюДатуToolStripMenuItem->Name = L"поискКлиентовСДоговоромИстекающимНаОпределеннуюДатуToolStripMenuItem";
			this->поискКлиентовСДоговоромИстекающимНаОпределеннуюДатуToolStripMenuItem->Size = System::Drawing::Size(255, 22);
			this->поискКлиентовСДоговоромИстекающимНаОпределеннуюДатуToolStripMenuItem->Text = L"Поиск по дате выселения";
			this->поискКлиентовСДоговоромИстекающимНаОпределеннуюДатуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ПоискДатыВыселенияToolStripMenuItem_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button_delete);
			this->groupBox3->Controls->Add(this->button_add);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->Location = System::Drawing::Point(188, 30);
			this->groupBox3->Margin = System::Windows::Forms::Padding(2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(2);
			this->groupBox3->Size = System::Drawing::Size(158, 109);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Действия со списком";
			// 
			// button_delete
			// 
			this->button_delete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_delete->Location = System::Drawing::Point(4, 67);
			this->button_delete->Margin = System::Windows::Forms::Padding(2);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(148, 32);
			this->button_delete->TabIndex = 4;
			this->button_delete->Text = L"Удалить клиента";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &MyForm::button_delete_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(946, 547);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Accuracy";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	} //лишнее
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
} //лишнее
private: System::Void button_clients_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_regular_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_empty_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_date_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void fAQПоДействиямToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void просмотрСпискаКлиентовToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void просмотрДолгожителейToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void добавлениеНовогоКлиентаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void поискСвободногоНомераToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ПоискДатыВыселенияToolStripMenuItem_Click(System::Object^ sender,
	System::EventArgs^ e);
private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void удалениеКлиентаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void DataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
};
}
