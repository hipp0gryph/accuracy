#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

[STAThread]
int main(array<String^>^ arg) //������ ��� �����
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Accuracy::MyForm form;
	Application::Run(% form);
}
//������ ���� ��������
System::Void Accuracy::MyForm::button_clients_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->Rows->Clear();
	//����������� � ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=hotel.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//������ � ��
	dbConnection->Open(); //�������� ����������
	String^ query = "SELECT * FROM [Hotel]"; //������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //�������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); //���������� ������

	//�������� ������
	if (dbReader->HasRows == false)
	{
		MessageBox::Show("������ ���������� ������", "������");
	}
	else
	{
		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Name"], dbReader["Pass"], dbReader["City"], dbReader["DataConc"], dbReader["DataExp"], dbReader["Breakfast"], dbReader["Num_room"], dbReader["Phone_number"]);
		}
	}

	//�������� ����������
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}
//������ ������������
System::Void Accuracy::MyForm::button_regular_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->Rows->Clear();
	//����������� � ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=hotel.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//������ � ��
	dbConnection->Open(); //�������� ����������
	String^ query = "SELECT * FROM Hotel WHERE DATEDIFF('d',DataConc,DataExp) >= 5"; //������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //�������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); //���������� ������

	//�������� ������
	if (dbReader->HasRows == false)
	{
		MessageBox::Show("������ ���������� ������", "������");
	}
	else
	{
		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Name"], dbReader["Pass"], dbReader["City"], dbReader["DataConc"], dbReader["DataExp"], dbReader["Breakfast"], dbReader["Num_room"], dbReader["Phone_number"]);
		}
	}

	//�������� ����������
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}
//����� �� ���� ���������� ������
System::Void Accuracy::MyForm::button_empty_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����������� � ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Hotel.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//������ � ��
	dbConnection->Open(); //�������� ����������
	String^ query = "SELECT Num_room FROM Hotel WHERE NOT Num_room = ANY(SELECT Num_room FROM Hotel WHERE ID = ANY(SELECT ID FROM Hotel WHERE Cdate('" + textBox_empty->Text + "') BETWEEN Cdate(DataConc) AND Cdate(DataExp))) GROUP BY Num_room"; //������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //�������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); //���������� ������

	//�������� ������
	if (dbReader->HasRows == false)
	{
		MessageBox::Show("�� ������ ����� ��� ��������� �������. \n��������� ������������ ����� ������.", "���������� ������");
	}
	else
	{
		//dataGridView1->Rows->Clear();
		String^ txt;
		int kol_elem=0;
		while (dbReader->Read())
		{
			kol_elem++;
			txt =txt+"����� "+dbReader["Num_room"]->ToString() +"\n";
			//dataGridView1->Rows->Add(dbReader["Num_room"]);
		}
		MessageBox::Show("�� ������ ����� �������� "+kol_elem+" ������: \n" + txt , "���������� ������");
	}

	//�������� ����������
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}
//����� �� ���� ���������
System::Void Accuracy::MyForm::button_date_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����������� � ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Hotel.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//������ � ��
	dbConnection->Open(); //�������� ����������
	String^ query = "SELECT * FROM Hotel WHERE DataExp='" + textBox_date->Text + "'"; //������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //�������
	OleDbDataReader^ dbReader = dbComand->ExecuteReader(); //���������� ������

	//�������� ������
	if (dbReader->HasRows == false)
	{
		MessageBox::Show("�� ������ ���� ��� �� ������ ������. \n��������� ������������ ����� ������.", "���������� ������");
	}
	else
	{
		dataGridView1->Rows->Clear();
		while (dbReader->Read())
		{
			dataGridView1->Rows->Add(dbReader["ID"], dbReader["Name"], dbReader["Pass"], dbReader["City"], dbReader["DataConc"], dbReader["DataExp"], dbReader["Breakfast"], dbReader["Num_room"], dbReader["Phone_number"]);
		}
	}

	//�������� ����������
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}
//����������
System::Void Accuracy::MyForm::button_add_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����� ������ ��� ����������
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("�������� ���� ������ ��� ����������", "��������");
		return;
	}

	//��������� ������� ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	//�������� ������
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
		MessageBox::Show("���� ������� �� ��� ������", "������");
		return;
	}

	//���������� ������
	String^ ID = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ Name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ Pass = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
	String^ City = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
	String^ DataConc = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
	String^ DataExp = dataGridView1->Rows[index]->Cells[5]->Value->ToString();
	String^ Breakfast = dataGridView1->Rows[index]->Cells[6]->Value->ToString();
	String^ Num_room = dataGridView1->Rows[index]->Cells[7]->Value->ToString();
	String^ Phone_number = dataGridView1->Rows[index]->Cells[8]->Value->ToString();

	//����������� � ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Hotel.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//������ � ��
	dbConnection->Open(); //�������� ����������
	String^ query = "INSERT INTO [Hotel] VALUES ("+ ID +", '"+ Name +"'," + Pass + ", '" + City + "', '" + DataConc + "', '" + DataExp + "'," + Breakfast + "," + Num_room + ", '" + Phone_number + "')"; //������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //�������

	//���������� �������
	if (dbComand->ExecuteNonQuery() !=1) MessageBox::Show("������ ���������� �������", "������");
	else MessageBox::Show("������ ���������", "������");

	//�������� ����������
	dbConnection->Close();

	return System::Void();
}
//�������� �������
System::Void Accuracy::MyForm::button_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����� ������ ��� ��������
	if (dataGridView1->SelectedRows->Count != 1)
	{
		MessageBox::Show("�������� ���� ������ ��� ��������", "��������");
		return;
	}

	//��������� ������� ��������� ������
	int index = dataGridView1->SelectedRows[0]->Index;

	//���������� ������
	String^ ID = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	
	//����������� � ��
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=Hotel.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//������ � ��
	dbConnection->Open(); //�������� ����������
	String^ query = "DELETE FROM Hotel WHERE ID =" + ID; //������
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection); //�������

	//���������� �������
	if (dbComand->ExecuteNonQuery() != 1) MessageBox::Show("������ ���������� �������", "������");
	else MessageBox::Show("������ ���� �������", "������");

	//�������� ����������
	dbConnection->Close();

	return System::Void();
}

//������ ����
System::Void Accuracy::MyForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("������� ������������� ��� ������� ����� �������� ��������� � ��������� ���������� �� �������� �������������.\n \n��������� �����: \n-����������� ������ ������� ���������, �������� � ��������� ��� �������� ����� ������,\n-������������� ������ ���� �����������,\n-������������ ����� ��������� �������,\n-�������� ���������� � �����������, ������� ������ ������� �� ������������ ����,\n-�������� ���������� � ������������ ���������.","����������� ���������");
	return System::Void();
}

System::Void Accuracy::MyForm::����������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��� ��������� ������ ���� �������� �������� ������� ������ ���� ��������","�������� ������ ��������");
	return System::Void();
}

System::Void Accuracy::MyForm::��������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��� ��������� ������ ���������� �������� �������� ������� ������ ������������", "�������� ������ ������������");
	return System::Void();
}

System::Void Accuracy::MyForm::�����������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��� ���������� ������ ������� ����������: \n 1) ������ � ������ ������ ������� ��� ������ � ������� \n 2) �������� ��� ������ ��������� �������� \n 3) ������ ������ ��������� �������", "���������� ������ �������");
	return System::Void();
}

System::Void Accuracy::MyForm::���������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��� �������� ������� ����������: \n 1) �������� ��� ������, ������� ���������� ������� \n 2) ������ ������ �������� ������� \n 3) ����� ������ ������ ���� �������� ��� ���������� ������", "�������� �������");
	return System::Void();
}

System::Void Accuracy::MyForm::���������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��� ������ ���������� ������ ����������: \n 1) ������ ���� � ������� ���.��.���ջ � ������ ��� �������� �������� ���� ���������� \n 2) ������ ������ ������ ������", "����� ������");
	return System::Void();
}

System::Void Accuracy::MyForm::������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��� ������ �������� � ���������� �� ������������ ����, ����������: \n 1) ������ ���� � ������� ���.��.���ջ � ������ ��� �������� �������� ���� ���������� \n 2) ������ ������ ������ �� ����", "����� �� ���� ���������");
	return System::Void();
}
