#include <iostream>
#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include <cstring>

using namespace std;

void DropTables(PGconn *conn);
void DropCustomerTable(PGconn *conn);
void DropProductsTable(PGconn *conn);

extern PGconn *conn;

void DropTables(PGconn *conn)
{
	DropCustomerTable(conn);
	DropProductsTable(conn);
}


void DropCustomerTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE customer");

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop customer table failed\n");
	}

	else printf("Drop customer table - successful\n");

	PQclear(res);
}

void DropProductsTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE products");

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop products table failed\n");
	}

	else printf("Drop products table - successful\n");

	PQclear(res);
}

