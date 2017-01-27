#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "log.h"

typedef struct list_struct {
	data_t item;
	struct list_struct *next;
} log_t;

static log_t* headptr = NULL;
static log_t* tailptr = NULL;

int addmsg(char* msg){
	if (headptr == NULL){
		headptr = malloc(sizeof (log_t));
//		clock_gettime(CLOCK_MONOTONIC, &((headptr->item).time));
		strcpy((headptr->item).string, msg);
		tailptr = headptr;
	}
	else{
		tailptr->next = malloc(sizeof (log_t));
		tailptr = tailptr->next;
//		clock_gettime(CLOCK_MONOTONIC, &((tailptr->item).time));
		strcpy((tailptr->item).string, msg);
	}
	return 0;
}

void clearlog(void) {
	log_t* temp;
	while(headptr != NULL){
		temp = headptr;
		headptr = headptr->next;
		free(temp);	
	}
}

char *getlog(void) {
	return NULL;
}

int savelog(char *filename) {
	return 0;
}
