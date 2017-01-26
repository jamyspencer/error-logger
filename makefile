CC=gcc 

buggycode: main.c loglib.c log.h
	$(CC)-o buggycode main.c loglib.c

