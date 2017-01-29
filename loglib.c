
#include <stdio.h>
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

data_t makeentry(char* msg){
	data_t temp;
	temp.err_msg = msg;
	clock_gettime(CLOCK_REALTIME, &(temp.time));
	addmsg(temp);
}

int addmsg(data_t data) { /* allocate node for data and add to end of list */
	log_t *newnode;
	int nodesize;
	nodesize = sizeof(log_t) + strlen(data.err_msg) + 1;

	if ((newnode = (log_t *)(malloc(nodesize))) == NULL){ /* couldn't add node */
		return -1;
	}
	newnode->item.time = data.time;
	newnode->item.err_msg = (char *)newnode + sizeof(log_t);
	strcpy(newnode->item.err_msg, data.err_msg);
	newnode->next = NULL;
	
	if (headptr == NULL){
		headptr = newnode;
	}
	else{
		tailptr->next = newnode;
	}

	tailptr = newnode;
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

int savelog(char* log_file_name, char* prg_name, char* spec_num) {
	FILE* file_write = fopen(log_file_name, "a");
	log_t* trav;

	if (headptr != NULL){
		trav = headptr;
	}
	else{
		printf("Error: Nothing to write.");
		return -1;
	}
	while (trav != NULL){
		fprintf(file_write, "%s%s%lu%09lu", prg_name, ": ", trav->item.time.tv_sec, trav->item.time.tv_nsec);
		fprintf(file_write, "%s%s%s%s\n", ": Error: nValue = ", spec_num, " - ", trav->item.err_msg);
		trav = trav->next;
	}
	

//	sprintf(temp.string, "%s%s%lu%09lu", filename, ": ", temp.time.tv_sec, temp.time.tv_nsec);
	return 0;
}
