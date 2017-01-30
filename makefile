# Written by Jamy Spencer 30 Jan 2017 
CC=gcc 

buggycode: main.o loglib.o 
	$(CC)-o buggycode main.o loglib.o

%.o: %.c %.h
	$(CC) -o %.c

clean :
	rm buggycode *.txt *.o
