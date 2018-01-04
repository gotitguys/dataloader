#include <iostream>
#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include <cstring>

using namespace std;

void DropTables(PGconn *conn);

void DropCustomerTable(PGconn *conn);
void DropProductsTable(PGconn *conn);
void DropReceivesTable(PGconn *conn);

extern PGconn *conn;

void DropTables(PGconn *conn)
{
	DropCustomerTable(conn);
	DropProductsTable(conn);
	DropReceivesTable(conn);
}

void DropCustomerTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE customer");
	printf("=============================================\n");
	printf("DROP TABLE CUSTOMER\n");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
}

void DropProductsTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE products");
	printf("=============================================\n");
	printf("DROP TABLE PRODUCTS\n");

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
}

void DropReceivesTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE recieves");
	printf("=============================================\n");
	printf("DROP TABLE RECIEVES\n");

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);

	res = PQexec(conn, "DROP TABLE receives");
	printf("=============================================\n");
	printf("DROP TABLE RECEIVES\n");

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	printf("**********NOTE:************\n");
	printf(" making sure receives table is spelled correctly\n");
	
	PQclear(res);
}

