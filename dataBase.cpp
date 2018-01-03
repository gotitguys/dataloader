//program to populate postgres tables using csv files
//making functions modular

#include <iostream>
#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

PGconn *ConnectDB();
void CloseConn(PGconn *conn);
void DropCustomerTable(PGconn *conn);
void CreateCustomerTable(PGconn *conn);
void PopulateCustomerTable(PGconn *conn);

bool test = 0;

int main()
{
	PGconn *conn = NULL;

	conn = ConnectDB();
	//PGresult *res; 
	DropCustomerTable(conn);
	CreateCustomerTable(conn);
	PopulateCustomerTable(conn);

	CloseConn(conn);

	return 0;
}

PGconn *ConnectDB()
{
	PGconn *conn = NULL;
	cout<<"In Database Connection function\n";
	conn = PQconnectdb("dbname=store port=5433 host=localhost user=store password=store");
	if (PQstatus(conn) == CONNECTION_BAD) {
		printf("Unable to connect to database\n");
	}

	else printf("Connection successful\n");

	return conn;
}

void CloseConn(PGconn *conn)
{
	PQfinish(conn);
	//getchar();
	//exit(1);
}

void DropCustomerTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE customer");

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop customer table failed\n");
		//PQclear(res);
		//CloseConn(conn);
	}

	else printf("Drop customer table - successful\n");

	PQclear(res);
}

void CreateCustomerTable(PGconn *conn)
{
	string customerTable = "CREATE TABLE IF NOT EXISTS Customer (";
	customerTable += " Customer_id SERIAL NOT NULL,";
	customerTable += " Fname VARCHAR(15) NOT NULL,";
	customerTable += " Middle_init VARCHAR(1) NULL,";
	customerTable += " Lname VARCHAR(20) NOT NULL,";
	customerTable += " Pword VARCHAR(20) NOT NULL,";
	customerTable += " Email VARCHAR(255) NOT NULL,";
	customerTable += " phone BIGINT NOT NULL)";


	PGresult *res = PQexec(conn, customerTable.c_str());
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		printf("Create customer table failed\n");
	}

	else printf("Create customer table - successful\n");

}

void PopulateCustomerTable(PGconn *conn)
{
	ifstream file("customer.csv");
	string fname, middle_init, lname, pword, email, phone;
	while (file.good())
	{
		//need to check first line for reader to see if it is eof before if
		//statement
		getline (file, fname, ',');
		if ( !file.eof())
		{
			//cout << fname << "\t";
			//res = PQexec(conn, "INSERT INTO customer(Customer_id) VALUE(DEFAULT);");
			getline (file, middle_init, ',');
			//cout << middle_init << "\t";
			getline (file, lname, ',');
			//cout << lname << "\t";
			getline (file, pword, ',');
			//cout << pword << "\t";
			getline (file, email, ',');
			//cout << email << "\t";
			getline (file, phone);
			cout << fname <<"\t" << middle_init << "\t" << lname <<
			"\t"<< pword << "\t" << email << "\t" << phone << "\n" ;

			string insert = "INSERT INTO customer (";
			insert += "Customer_id, Fname, Middle_init, ";
			insert += "Lname, Pword, Email, phone) ";
			insert += "VALUES (DEFAULT,'";
			insert += fname;
			insert += "','";
			insert += middle_init;
			insert += "','";
			insert += lname;
			insert += "','";
			insert += pword;
			insert += "','";
			insert += email;
			insert += "','";
			insert += phone;
			insert += "')";

			PGresult *res = PQexec(conn, insert.c_str());
			if  (PQresultStatus(res) != PGRES_COMMAND_OK)
				printf("Insert tuple from csv failed\n");

			PQclear(res);
		}
	}
	cout << "\n"; 
	file.close(); 
}

