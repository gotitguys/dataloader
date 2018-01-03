#include <iostream>
#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

void PopulateTables(PGconn *conn);
void PopulateCustomerTable(PGconn *conn);
void PopulateProductsTable(PGconn *conn);

extern PGconn *conn;

void PopulateTables(PGconn *conn)
{
	PopulateCustomerTable(conn);
	PopulateProductsTable(conn);
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
			getline (file, middle_init, ',');
			getline (file, lname, ',');
			getline (file, pword, ',');
			getline (file, email, ',');
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

void PopulateProductsTable(PGconn *conn)
{
	ifstream file("products.csv");
	string cat, pname, sprice, pprice;
	while (file.good())
	{
		//need to check first line for reader to see if it is eof before if
		//statement
		getline (file, cat, ',');
		if ( !file.eof())
		{
			getline (file, pname, ',');
			getline (file, sprice, ',');
			getline (file, pprice);
			cout << cat <<"\t" << pname << "\t" << sprice <<
			"\t"<< pprice  << "\n" ;

			string insert = "INSERT INTO products (";
			insert += "P_id, Category, P_name, ";
			insert += "S_price, P_price) ";
			insert += "VALUES (DEFAULT,'";
			insert += cat;
			insert += "','";
			insert += pname;
			insert += "','";
			insert += sprice;
			insert += "','";
			insert += pprice;
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
