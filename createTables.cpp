#include <iostream>
#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include <cstring>

using namespace std;

void CreateTables(PGconn *conn);
void CreateAddressTable(PGconn *conn);
void CreateContainsTable(PGconn *conn);
void CreateCustomerTable(PGconn *conn);
void CreateOrdersTable(PGconn *conn);
void CreatePaymentTable(PGconn *conn);
void CreatePlacesTable(PGconn *conn);
void CreateProductsTable(PGconn *conn);
void CreateReceivesTable(PGconn *conn);

void CreateTables(PGconn *conn)
{
	CreateAddressTable(conn);
	CreateContainsTable(conn);
	CreateCustomerTable(conn);
	CreateOrdersTable(conn);
	CreatePaymentTable(conn);
	CreatePlacesTable(conn);
	CreateProductsTable(conn);
	CreateReceivesTable(conn);
}

void CreateAddressTable(PGconn *conn)
{
	string customerTable = "CREATE TABLE IF NOT EXISTS Address (";
	customerTable += " Customer_id integer NOT NULL,";
	customerTable += " Street_num integer NOT NULL,";
	customerTable += " Street_name VARCHAR(255) NOT NULL,";
	customerTable += " Zip integer NOT NULL,";
	customerTable += " City VARCHAR(255) NOT NULL,";
	customerTable += " State VARCHAR(2) NOT NULL,";
	customerTable += " Type int NOT NULL)";

	PGresult *res = PQexec(conn, customerTable.c_str());
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		printf("Create address table failed\n");
	}

	else printf("Create address table - successful\n");
}

void CreateContainsTable(PGconn *conn)
{
	string table = "CREATE TABLE IF NOT EXISTS Contains (";
	table += " Qty_sold integer NOT NULL,";
	table += " Date_sold date NOT NULL,";
	table += " S_price double precision NOT NULL,";
	table += " order_num SERIAL NOT NULL,";
	table += " P_id integer NOT NULL)";

	PGresult *res = PQexec(conn, table.c_str());
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		printf("Create contains table failed\n");
	}

	else printf("Create contains table - successful\n");	
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

void CreateOrdersTable(PGconn *conn)
{
	string customerTable = "CREATE TABLE IF NOT EXISTS orders (";
	customerTable += " Order_num SERIAL NOT NULL,";
	customerTable += " Order_date date NOT NULL,";
	customerTable += " Time time NOT NULL)";

	PGresult *res = PQexec(conn, customerTable.c_str());
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		printf("Create orders table failed\n");
	}

	else printf("Create orders table - successful\n");
}

void CreatePaymentTable(PGconn *conn)
{
	string customerTable = "CREATE TABLE IF NOT EXISTS Payment (";
	customerTable += " Fname VARCHAR(15) NOT NULL,";
	customerTable += " Middle_init VARCHAR(1) NULL,";
	customerTable += " Lname VARCHAR(20) NOT NULL,";
	customerTable += " Card_num VARCHAR(16) NOT NULL,";
	customerTable += " Expiration VARCHAR(5) NOT NULL,";
	customerTable += " Cvc VARCHAR(4) NULL,";
	customerTable += " Type VARCHAR(20) NOT NULL,";
	customerTable += " Street_num integer NOT NULL,";
	customerTable += " Street_name VARCHAR(255) NOT NULL,";
	customerTable += " Zip integer NOT NULL,";
	customerTable += " City VARCHAR(255) NOT NULL,";
	customerTable += " State VARCHAR(2) NOT NULL)";

	PGresult *res = PQexec(conn, customerTable.c_str());
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		printf("Create payment table failed\n");
	}

	else printf("Create payment table - successful\n");
}

void CreatePlacesTable(PGconn *conn)
{
	string customerTable = "CREATE TABLE IF NOT EXISTS Places (";
	customerTable += " Order_num int NOT NULL ,";
	customerTable += " Customer_id int NOT NULL)";

	PGresult *res = PQexec(conn, customerTable.c_str());
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		printf("Create places table failed\n");
	}

	else printf("Create places table - successful\n");
}


void CreateProductsTable(PGconn *conn)
{
	string table = "CREATE TABLE IF NOT EXISTS Products (";
	table += " P_id SERIAL NOT NULL,";
	table += " Category VARCHAR(15) NOT NULL,";
	table += " P_name VARCHAR(100) NOT NULL,";
	table += " S_price double precision NOT NULL,";
	table += " P_price double precision NOT NULL)";

	PGresult *res = PQexec(conn, table.c_str());
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		printf("Create products table failed\n");
	}

	else printf("Create products table - successful\n");
}

void CreateReceivesTable(PGconn *conn)
{
	string table = "CREATE TABLE IF NOT EXISTS Receives (";
	table += " Qty_received integer NOT NULL,";
	table += " Datee date NOT NULL,";
	table += " P_price double precision NOT NULL,";
	table += " Po_id integer NOT NULL,";
	table += " P_id integer NOT NULL)";

	PGresult *res = PQexec(conn, table.c_str());
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		printf("Create receives table failed\n");
	}

	else printf("Create receives table - successful\n");	
}
