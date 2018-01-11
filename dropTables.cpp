#include <iostream>
#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include <cstring>

using namespace std;

void DropTables(PGconn *conn);

void DropAddressTable(PGconn *conn);
void DropContainsTable(PGconn *conn);
void DropCustomerTable(PGconn *conn);
void DropDistributorTable(PGconn *conn);
void DropInventoryTable(PGconn *conn);
void DropMakesTable(PGconn *conn);
void DropOrdersTable(PGconn *conn);
void DropP_orderTable(PGconn *conn);
void DropPayforTable(PGconn *conn);
void DropPaymentsTable(PGconn *conn);
void DropPlacesTable(PGconn *conn);
void DropProductsTable(PGconn *conn);
void DropReceivesTable(PGconn *conn);
void DropStatusTable(PGconn *conn);
void DropUpdatesTable(PGconn *conn);

extern PGconn *conn;

void DropTables(PGconn *conn)
{
	printf("\033[1;31m");
	DropAddressTable(conn);
	DropContainsTable(conn);
	DropCustomerTable(conn);
	DropDistributorTable(conn);
	DropInventoryTable(conn);
	DropOrdersTable(conn);
	DropMakesTable(conn);
	DropP_orderTable(conn);
	DropPayforTable(conn);
	DropPaymentsTable(conn);
	DropPlacesTable(conn);
	DropProductsTable(conn);
	DropReceivesTable(conn);
	DropStatusTable(conn);
	DropUpdatesTable(conn);
}

void DropAddressTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE address");
	printf("=============================================\n");
	printf("DROP TABLE ADDRESS\n");

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
}

void DropContainsTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE contains");
	printf("=============================================\n");
	printf("DROP TABLE CONTAINS\n");

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
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

void DropDistributorTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE distributor");
	printf("=============================================\n");
	printf("DROP TABLE DISTRIBUTOR\n");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
}

void DropInventoryTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE inventory");
	printf("=============================================\n");
	printf("DROP TABLE INVENTORY\n");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
}

void DropMakesTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE makes");
	printf("=============================================\n");
	printf("DROP TABLE MAKES\n");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
}

void DropOrdersTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE orders");
	printf("=============================================\n");
	printf("DROP TABLE ORDERS\n");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
}

void DropP_orderTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE p_order");
	printf("=============================================\n");
	printf("DROP TABLE P_order\n");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
}

void DropPayforTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE payfor");
	printf("=============================================\n");
	printf("DROP TABLE PAYFOR\n");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
}

void DropPaymentsTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE payment");
	printf("=============================================\n");
	printf("DROP TABLE PAYMENT\n");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
}

void DropPlacesTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE places");
	printf("=============================================\n");
	printf("DROP TABLE PLACES\n");
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

void DropStatusTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE status");
	printf("=============================================\n");
	printf("DROP TABLE STATUS\n");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
}

void DropUpdatesTable(PGconn *conn)
{
	PGresult *res = PQexec(conn, "DROP TABLE updates");
	printf("=============================================\n");
	printf("DROP TABLE UPDATES\n");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		printf("Drop table failed\n");
	}

	else printf("Drop table - successful\n");

	PQclear(res);
}








