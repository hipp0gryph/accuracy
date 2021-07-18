#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

[STAThread]
int main(array<String^>^ arg) //основа для формы
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Accuracy::MyForm form;
	Application::Run(% form);
}
//Список всех клиентов
System::Void Accuracy::MyForm::button_clients_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->Rows->Clear();
	//Подключение к БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=hotel.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Запрос к БД
	dbConnection->Open(); //открытие соединения
	String^ query = "SELECT * FROM [Hotel]"; //запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); //считывание данных

	//Проверка данных
	if (dbReader->HasRows == false)
	{
		MessageBox::Show("Ошибка считывания данных", "Ошибка");
	}
	else
	{
		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Name"], dbReader["Pass"], dbReader["City"], dbReader["DataConc"], dbReader["DataExp"], dbReader["Breakfast"], dbReader["Num_room"], dbReader["Phone_number"]);
		}
	}

	//Закрытие соединения
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}
//Список долгожителей
System::Void Accuracy::MyForm::button_regular_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->Rows->Clear();
	//Подключение к БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=hotel.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Запрос к БД
	dbConnection->Open(); //открытие соединения
	String^ query = "SELECT * FROM Hotel WHERE DATEDIFF('d',DataConc,DataExp) >= 5"; //запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); //считывание данных

	//Проверка данных
	if (dbReader->HasRows == false)
	{
		MessageBox::Show("Ошибка считывания данных", "Ошибка");
	}
	else
	{
		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Name"], dbReader["Pass"], dbReader["City"], dbReader["DataConc"], dbReader["DataExp"], dbReader["Breakfast"], dbReader["Num_room"], dbReader["Phone_number"]);
		}
	}

	//Закрытие соединения
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}
//Поиск по дате свободного номера
System::Void Accuracy::MyForm::button_empty_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Подключение к БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Hotel.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Запрос к БД
	dbConnection->Open(); //открытие соединения
	String^ query = "SELECT Num_room FROM Hotel WHERE NOT Num_room = ANY(SELECT Num_room FROM Hotel WHERE ID = ANY(SELECT ID FROM Hotel WHERE Cdate('" + textBox_empty->Text + "') BETWEEN Cdate(DataConc) AND Cdate(DataExp))) GROUP BY Num_room"; //запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); //считывание данных

	//Проверка данных
	if (dbReader->HasRows == false)
	{
		MessageBox::Show("На данное число нет свободных номеров. \nПроверьте правильность ввода данных.", "Результаты поиска");
	}
	else
	{
		//dataGridView1->Rows->Clear();
		String^ txt;
		int kol_elem=0;
		while (dbReader->Read())
		{
			kol_elem++;
			txt =txt+"Номер "+dbReader["Num_room"]->ToString() +"\n";
			//dataGridView1->Rows->Add(dbReader["Num_room"]);
		}
		MessageBox::Show("На данное число свободны "+kol_elem+" номера: \n" + txt , "Результаты поиска");
	}

	//Закрытие соединения
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}
//Поиск по дате выселения
System::Void Accuracy::MyForm::button_date_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Подключение к БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Hotel.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Запрос к БД
	dbConnection->Open(); //открытие соединения
	String^ query = "SELECT * FROM Hotel WHERE DataExp='" + textBox_date->Text + "'"; //запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //команда
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); //считывание данных

	//Проверка данных
	if (dbReader->HasRows == false)
	{
		MessageBox::Show("На данную дату нет ни одного номера. \nПроверьте правильность ввода данных.", "Результаты поиска");
	}
	else
	{
		dataGridView1->Rows->Clear();
		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Name"], dbReader["Pass"], dbReader["City"], dbReader["DataConc"], dbReader["DataExp"], dbReader["Breakfast"], dbReader["Num_room"], dbReader["Phone_number"]);
		}
	}

	//Закрытие соединения
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}
//Добавление
System::Void Accuracy::MyForm::button_add_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Выбор строки для добавления
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите одну строку для добавления", "Внимание");
		return;
	}

	//Получение индекса выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	//Проверка данных
	if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[5]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[6]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[7]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[8]->Value == nullptr)
	{
		MessageBox::Show("Были введены не все данные", "Ошибка");
		return;
	}

	//Считывание данных
	String^ ID = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ Name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Pass = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ City = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ DataConc = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
	String^ DataExp = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
	String^ Breakfast = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
	String^ Num_room = dataGridView1->Rows[index]->Cells[7]->Value->ToString();
	String^ Phone_number = dataGridView1->Rows[index]->Cells[8]->Value->ToString();

	//Подключение к БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Hotel.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Запрос к БД
	dbConnection->Open(); //открытие соединения
	String^ query = "INSERT INTO [Hotel] VALUES ("+ ID +", '"+ Name +"'," + Pass + ", '" + City + "', '" + DataConc + "', '" + DataExp + "'," + Breakfast + "," + Num_room + ", '" + Phone_number + "')"; //запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //команда

	//Выполнение запроса
	if (dbComand->ExecuteNonQuery() !=1) MessageBox::Show("Ошибка выполнения запроса", "Ошибка");
	else MessageBox::Show("Данные добавлены", "Готово");

	//Закрытие соединения
	dbConnection->Close();

	return System::Void();
}
//Удаление клиента
System::Void Accuracy::MyForm::button_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Выбор строки для удаления
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("Выберите одну строку для удаления", "Внимание");
		return;
	}

	//Получение индекса выбранной строки
	int index = dataGridView1->SelectedRows[0]->Index;

	//Считывание данных
	String^ ID = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	
	//Подключение к БД
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Hotel.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//Запрос к БД
	dbConnection->Open(); //открытие соединения
	String^ query = "DELETE FROM Hotel WHERE ID =" + ID; //запрос
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //команда

	//Выполнение запроса
	if (dbComand->ExecuteNonQuery() != 1) MessageBox::Show("Ошибка выполнения запроса", "Ошибка");
	else MessageBox::Show("Данные были удалены", "Готово");

	//Закрытие соединения
	dbConnection->Close();

	return System::Void();
}

//Пункты меню
System::Void Accuracy::MyForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Система предназначена для ведения учета клиентов гостиницы и получения информации по запросам пользователей.\n \nПрограмма может: \n-формировать список жителей гостиницы, добавляя в имеющийся или создавая новый список,\n-просматривать список всех проживающих,\n-осуществлять поиск свободных номеров,\n-получать информацию о проживающих, которые должны выехать на определенную дату,\n-получать информацию о долгожителях гостиницы.","Возможности программы");
	return System::Void();
}

System::Void Accuracy::MyForm::просмотрСпискаКлиентовToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Для просмотра списка всех клиентов компании нажмите кнопку «Все клиенты»","Просмотр списка клиентов");
	return System::Void();
}

System::Void Accuracy::MyForm::просмотрДолгожителейToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Для просмотра списка постоянных клиентов компании нажмите кнопку «Долгожители»", "Просмотр списка Долгожителей");
	return System::Void();
}

System::Void Accuracy::MyForm::добавлениеНовогоКлиентаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Для добавления нового клиента необходимо: \n 1) Ввести в пустую строку таблицы все данные о клиенте \n 2) Выделить всю строку введенных значений \n 3) Нажать кнопку «Добавить клиента»", "Добавление нового клиента");
	return System::Void();
}

System::Void Accuracy::MyForm::удалениеКлиентаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Для удаления клиента необходимо: \n 1) Выделить всю строку, которую необходимо удалить \n 2) Нажать кнопку «Удалить клиента» \n 3) Снова нажать кнопку «Все клиенты» для обновления списка", "Удаление клиента");
	return System::Void();
}

System::Void Accuracy::MyForm::поискСвободногоНомераToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Для поиска свободного номера необходимо: \n 1) Ввести дату в формате «ХХ.ХХ.ХХХХ» в строку под надписью «Введите дату заселения» \n 2) Нажать кнопку «Поиск номера»", "Поиск номера");
	return System::Void();
}

System::Void Accuracy::MyForm::ПоискДатыВыселенияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Для поиска клиентов с выселением на определенную дату, необходимо: \n 1) Ввести дату в формате «ХХ.ХХ.ХХХХ» в строку под надписью «Введите дату выселения» \n 2) Нажать кнопку «Поиск по дате»", "Поиск по дате выселения");
	return System::Void();
}
