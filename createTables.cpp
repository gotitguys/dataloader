#include <iostream>
#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include <cstring>

using namespace std;

void CreateTables(PGconn *conn);
void CreateCustomerTable(PGconn *conn);
void CreateProductsTable(PGconn *conn);

void CreateTables(PGconn *conn)
{
	CreateCustomerTable(conn);
	CreateProductsTable(conn);
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
