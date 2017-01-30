CC=gcc 

buggycode: main.o loglib.o 
	$(CC)-o buggycode main.o loglib.o

%.o: %.c %.h
	$(CC) -o %.c

clean :
	rm buggycode *.txt
