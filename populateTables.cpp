#include <iostream>
#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

void PopulateTables(PGconn *conn);
void PopulateAddressTable(PGconn *conn);
void PopulateContainsTable(PGconn *conn);
void PopulateCustomerTable(PGconn *conn);
void PopulateMakesTable(PGconn *conn);
void PopulateOrdersTable(PGconn *conn);
void PopulatePayforTable(PGconn *conn);
void PopulatePaymentTable(PGconn *conn);
void PopulatePlacesTable(PGconn *conn);
void PopulateProductsTable(PGconn *conn);
void PopulateReceivesTable(PGconn *conn);
void PopulateStatusTable(PGconn *conn);
void PopulateUpdatesTable(PGconn *conn);

extern PGconn *conn;

void PopulateTables(PGconn *conn)
{
	printf("\033[1;35m");
	PopulateAddressTable(conn);
	PopulateContainsTable(conn);
	PopulateCustomerTable(conn);
	PopulateMakesTable(conn);
	PopulateOrdersTable(conn);
	PopulatePayforTable(conn);
	PopulatePaymentTable(conn);
	PopulatePlacesTable(conn);
	PopulateProductsTable(conn);
	PopulateReceivesTable(conn);
	PopulateStatusTable(conn);
	PopulateUpdatesTable(conn);
}

void PopulateAddressTable(PGconn *conn)
{
	ifstream file("address.csv");
	printf("****BEGIN POPULATING address****\n");
	string cid, snum, sname, zip, city, state,type;
	while (file.good())
	{
		//need to check first line for reader to see if it is eof before if
		//statement
		getline (file, cid, ',');
		if ( !file.eof())
		{
			getline (file, snum, ',');
			getline (file, sname, ',');
			getline (file, zip, ',');
			getline (file, city, ',');
			getline (file, state, ',');
			getline (file, type);
			//cout << fname <<"\t" << middle_init << "\t" << lname <<
			//"\t"<< pword << "\t" << email << "\t" << phone << "\n" ;

			string insert = "INSERT INTO address (";
			insert += "Customer_id, street_num, street_name, ";
			insert += "zip, city, state, type) ";
			insert += "VALUES ('";
			insert += cid;
			insert += "','";
			insert += snum;
			insert += "','";
			insert += sname;
			insert += "','";
			insert += zip;
			insert += "','";
			insert += city;
			insert += "','";
			insert += state;
			insert += "','";
			insert += type;
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

void PopulateContainsTable(PGconn *conn)
{
	ifstream file("contains.csv");
	printf("****BEGIN POPULATING contains****\n");
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
	printf("****BEGIN POPULATING customer****\n");
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

void PopulateMakesTable(PGconn *conn)
{
	ifstream file("makes.csv");
	printf("****BEGIN POPULATING makes****\n");
	string id, num;
	while (file.good())
	{
		getline (file, id, ',');
		if ( !file.eof())
		{
			getline (file, num);

			string insert = "INSERT INTO makes (";
			insert += "Customer_id, card_num) ";
			insert += "VALUES ('";
			insert += id;
			insert += "','";
			insert += num;
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

void PopulateOrdersTable(PGconn *conn)
{
	ifstream file("orders.csv");
	printf("****BEGIN POPULATING orders****\n");
	string date, hour, minute, time;
	while (file.good())
	{
		getline (file, date, ',');
		if ( !file.eof())
		{
			getline (file, hour, ',');
			getline (file, minute);
			time = hour + ':' + minute;
			//cout << fname <<"\t" << middle_init << "\t" << lname <<
			//"\t"<< pword << "\t" << email << "\t" << phone << "\n" ;

			string insert = "INSERT INTO orders (";
			insert += "Order_num, Order_date, time) ";
			insert += "VALUES (DEFAULT,'";
			insert += date;
			insert += "','";
			insert += time;
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

void PopulatePayforTable(PGconn *conn)
{
	ifstream file("payfor.csv");
	printf("****BEGIN POPULATING payfor****\n");
	string id, num;
	while (file.good())
	{
		getline (file, id, ',');
		if ( !file.eof())
		{
			getline (file, num);

			string insert = "INSERT INTO payfor (";
			insert += "Order_num, card_num) ";
			insert += "VALUES ('";
			insert += id;
			insert += "','";
			insert += num;
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

void PopulatePaymentTable(PGconn *conn)
{
	ifstream file("payment.csv");
	printf("****BEGIN POPULATING payment****\n");
	string fname, mi, lname, card, exp, cvc, type, streetnum, streetname,zip, city, state;
	while (file.good())
	{
		//need to check first line for reader to see if it is eof before if
		//statement
		getline (file, fname, ',');
		if ( !file.eof())
		{
			getline (file, mi, ',');
			getline (file, lname, ',');
			getline (file, card, ',');
			getline (file, exp, ',');
			getline (file, cvc, ',');
			getline (file, type, ',');
			getline (file, streetnum, ',');
			getline (file, streetname, ',');
			getline (file, zip, ',');
			getline (file, city, ',');
			getline (file, state);

			string insert = "INSERT INTO payment (";
			insert += "fname, middle_init, lname, ";
			insert += "card_num, expiration, cvc, type, ";
			insert += "street_num, street_name, ";
			insert += "zip, city, state) ";
			insert += "VALUES ('";
			insert += fname;
			insert += "','";
			insert += mi;
			insert += "','";
			insert += lname;
			insert += "','";
			insert += card;
			insert += "','";
			insert += exp;
			insert += "','";
			insert += cvc;
			insert += "','";
			insert += type;
			insert += "','";
			insert += streetnum;
			insert += "','";
			insert += streetname;
			insert += "','";
			insert += zip;
			insert += "','";
			insert += city;
			insert += "','";
			insert += state;
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

void PopulatePlacesTable(PGconn *conn)
{
	ifstream file("places.csv");
	printf("****BEGIN POPULATING places****\n");
	string id, num;
	while (file.good())
	{
		getline (file, id, ',');
		if ( !file.eof())
		{
			getline (file, num);

			string insert = "INSERT INTO places (";
			insert += "Customer_id, Order_num) ";
			insert += "VALUES ('";
			insert += id;
			insert += "','";
			insert += num;
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
	printf("****BEGIN POPULATING products****\n");
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
	printf("****BEGIN POPULATING receives****\n");
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

void PopulateStatusTable(PGconn *conn)
{
	ifstream file("status.csv");
	printf("****BEGIN POPULATING status****\n");
	string status;
	while (file.good())
	{
		getline (file, status);
		if ( !file.eof())
		{
			string insert = "INSERT INTO status (";
			insert += "S_id, Status) ";
			insert += "VALUES (DEFAULT,'";
			insert += status;
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

void PopulateUpdatesTable(PGconn *conn)
{
	ifstream file("updates.csv");
	printf("****BEGIN POPULATING updates****\n");
	string hour, minute, id, order, time;
	while (file.good())
	{
		getline (file, hour, ',');
		if ( !file.eof())
		{
			getline (file, minute, ',');
			time = hour + ':' + minute;
			getline (file, id, ',');
			getline (file, order);

			string insert = "INSERT INTO updates (";
			insert += "Update_time, S_id, Order_num) ";
			insert += "VALUES ('";
			insert += time;
			insert += "','";
			insert += id;
			insert += "','";
			insert += order;
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

