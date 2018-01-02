//program to populate postgres tables using csv files

#include <iostream>
#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

bool test = 0;

int main()
{
  PGconn *conn;
  PGresult *res; 
  int rec_count;
  int row;
  int col;

  conn = PQconnectdb("dbname=store port=5433 host=localhost user=store password=store");

  if (PQstatus(conn) == CONNECTION_BAD) {
    printf("Unable to connect to database\n");
  }

  else printf("Connection successful\n");

  //read customer csv and put in database
  ifstream file("customer.csv");
  //const char* fname, middle_init, lname, pword, email, phone;
  string fname, middle_init, lname, pword, email, phone;
  /*const char* insert = "INSERT INTO customer(Customer_id,\
    Fname,  Middle_init,Lname, Pword, Email, phone) \
    VALUES (DEFAULT,'"+ fname +"','"+ middle_init +\
    "','"+  lname+"','"+  pword +"','"+ \
    email+"','"+ phone +"')";*/

  while (file.good())
  {
    //need to check first line for reader to see if it is eof before if
    //statement
    getline (file, fname, ',');
    if (/*file.good() &&*/ !file.eof())
    {
      cout << fname << "\t";
      res = PQexec(conn, "INSERT INTO customer(Customer_id) VALUE(DEFAULT);");
      getline (file, middle_init, ',');
      cout << middle_init << "\t";
      getline (file, lname, ',');
      cout << lname << "\t";
      getline (file, pword, ',');
      cout << pword << "\t";
      getline (file, email, ',');
      cout << email << "\t";
      getline (file, phone);
      cout << phone << "\n" ;


      string insert = "INSERT INTO customer(Customer_id,\
        Fname,  Middle_init,Lname, Pword, Email, phone) \
        VALUES (DEFAULT,'"+ fname +"','"+ middle_init +\
        "','"+  lname+"','"+  pword +"','"+ \
        email+"','"+ phone +"')";
        res = PQexec(conn, insert.c_str());
    }
  }
  cout << "\n"; 
  file.close(); 

  //const char* copy = "COPY addresses FROM 'customer.csv' DELIMITER ',' CSV HEADER;";
  //res = PQexec(conn, copy);

  if(test){
    res = PQexec(conn,"select * from customer");

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
      printf("No data retrieved\n");
      //exit(0);
    }

    rec_count = PQntuples(res);

    printf("Program retrieved %d customers from database.\n", rec_count);

    for (row = 0; row<rec_count; row++) {
      for (col=0; col<6; col++) {
        printf("%s\t", PQgetvalue(res,row,col));
      }
      printf("\n");
    }
    PQclear(res);
  }

  //PQclear(res);

  PQfinish(conn);

  return 0;
}
