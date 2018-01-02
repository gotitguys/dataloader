all: ps

ps: psql.cpp
	g++ psql.cpp -o ps -L/usr/lib -lpq
