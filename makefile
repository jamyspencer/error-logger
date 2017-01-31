# Written by Jamy Spencer 30 Jan 2017 
CC=gcc 
DEBUG_ARGS=-g

buggycode: main.o loglib.o 
	$(CC) -o buggycode main.o loglib.o

%.o: %.c %.h
	$(CC) -c %.c

clean :
	rm buggycode *.txt *.o
