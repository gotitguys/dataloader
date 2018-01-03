//program to populate postgres tables using csv files
//making functions modular

#include <iostream>
#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include <cstring>

using namespace std;

PGconn *ConnectDB();
void CloseConn(PGconn *conn);

extern void DropTables(PGconn *conn);
extern void CreateTables(PGconn *conn);
extern void PopulateTables(PGconn *conn);

bool test = 0;
PGconn *conn = NULL;

int main()
{
	conn = ConnectDB();
	
	DropTables(conn);
	CreateTables(conn);
	PopulateTables(conn);

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
}

