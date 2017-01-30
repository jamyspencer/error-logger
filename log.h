/* Written by Jamy Spencer 30 Jan 2017 */
#ifndef LOG_H
#define LOG_H

#include <time.h>

typedef struct data_struct {
	struct timespec time;
	char* err_msg;
} data_t;

data_t LogErrEntry(char* msg);
int addmsg(data_t data);
void clearlog(void);
char* getlog(void);
int SaveLog(char* log_file_name, char* prg_name, char* spec_num);

#endif
