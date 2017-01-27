#ifndef LOG_H
#define LOG_H

#include <time.h>

typedef struct data_struct {
	struct timespec time;
	char* string;
} data_t;


int addmsg(char* msg);
void clearlog(void);
char *getlog(void);
int savelog(char *filename);

#endif
