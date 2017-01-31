/* Written by Jamy Spencer 30 Jan 2017 */
#ifndef LOG_H
#define LOG_H

#include <time.h>

typedef struct data_struct {
	struct timespec time;
	char* err_msg;
} data_t;

void LogErrEntry(char* msg, char* prg_name, char* spec_num);
int addmsg(data_t data);
void clearlog(void);
char* getlog(void);
int SaveLog(char* log_file_name);

#endif
