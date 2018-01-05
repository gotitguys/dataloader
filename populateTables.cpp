#include <iostream>
#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

void PopulateTables(PGconn *conn);
void PopulateContainsTable(PGconn *conn);
void PopulateCustomerTable(PGconn *conn);
void PopulateProductsTable(PGconn *conn);
void PopulateReceivesTable(PGconn *conn);

extern PGconn *conn;

void PopulateTables(PGconn *conn)
{
	PopulateContainsTable(conn);
	PopulateCustomerTable(conn);
	PopulateProductsTable(conn);
	PopulateReceivesTable(conn);
}

void PopulateContainsTable(PGconn *conn)
{
	ifstream file("contains.csv");
	string qty, date, price, order, pid;
	while (file.good())
	{
		getline (file, qty, ',');
		if ( !file.eof())
		{
			getline (file, date, ',');
			getline (file, price, ',');
			getline (file, order, ',');
			getline (file, pid);
			//cout << qty <<"\t" << date << "\t" << price <<
			//"\t"<< poid << "\t"<< pid << "\n" ;

			string insert = "INSERT INTO contains (";
			insert += "Qty_sold, date_sold , S_price, ";
			insert += "order_num, P_id) ";
			insert += "VALUES ('";
			insert += qty;
			insert += "','";
			insert += date;
			insert += "','";
			insert += price;
			insert += "','";
			insert += order;
			insert += "','";
			insert += pid;
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
			//cout << fname <<"\t" << middle_init << "\t" << lname <<
			//"\t"<< pword << "\t" << email << "\t" << phone << "\n" ;

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
		getline (file, cat, ',');
		if ( !file.eof())
		{
			getline (file, pname, ',');
			getline (file, sprice, ',');
			getline (file, pprice);
			//cout << cat <<"\t" << pname << "\t" << sprice <<
			//"\t"<< pprice  << "\n" ;

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

void PopulateReceivesTable(PGconn *conn)
{
	ifstream file("receives.csv");
	string qty, date, price, poid, pid;
	while (file.good())
	{
		getline (file, qty, ',');
		if ( !file.eof())
		{
			getline (file, date, ',');
			getline (file, price, ',');
			getline (file, poid, ',');
			getline (file, pid);
			//cout << qty <<"\t" << date << "\t" << price <<
			//"\t"<< poid << "\t"<< pid << "\n" ;

			string insert = "INSERT INTO receives (";
			insert += "Qty_received, datee , P_price, ";
			insert += "Po_id, P_id) ";
			insert += "VALUES ('";
			insert += qty;
			insert += "','";
			insert += date;
			insert += "','";
			insert += price;
			insert += "','";
			insert += poid;
			insert += "','";
			insert += pid;
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

