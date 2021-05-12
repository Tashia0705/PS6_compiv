CC = g++ 
CFLAGS = -std=c++17 -Wall -Werror -pedantic
LFLAGS = -lboost_regex -lboost_date_time

all: ps6

ps6: main.o
	$(CC) -o $@ main.o $(LFLAGS)

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f ps6 *.o