all: ps loader main

loader: dataBase.cpp
	g++ dataBase.cpp -o loader -L/usr/lib -lpq

ps: psql.cpp
	g++ psql.cpp -o ps -L/usr/lib -lpq

main: main.cpp dropTables.cpp createTables.cpp populateTables.cpp
	g++ main.cpp dropTables.cpp createTables.cpp populateTables.cpp -o main -L/usr/lib -lpq
