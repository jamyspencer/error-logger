/* Written by Jamy Spencer 30 Jan 2017 */

#include <errno.h>
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

void LogErrEntry(char* msg, char* prg_name, char* spec_num){

	data_t temp;
	char buffer[200];

	perror(msg);
	clock_gettime(CLOCK_REALTIME, &(temp.time));
	sprintf(buffer, "%s%s%lu%09lu%s%s%s%s\n", prg_name, ": ", temp.time.tv_sec, temp.time.tv_nsec, ": Error: nValue = ", spec_num, " - ", msg);
	temp.err_msg = (char*) malloc (strlen(buffer) + 1);
	sprintf(temp.err_msg, "%s", buffer);
	addmsg(temp);
//	printf("%s\n", temp.err_msg);
	return;
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
//	printf("Error message stored in linked list: %s\n", tailptr->item.err_msg);
	return 0;
}

void clearlog(void) {
	log_t* temp;
	while(headptr != NULL){
		temp = headptr;
		headptr = headptr->next;
		free(temp->item.err_msg);
		free(temp);	
	}
}

char* getlog(void) {
	char* str;
	int size;

	log_t* trav;
	size = (strlen(headptr->item.err_msg) + 1);
	str = (char*) malloc (size);
	strcpy(str, headptr->item.err_msg);
	trav = headptr->next;
//	printf("%s", str);
//	printf("size of string: %d\n", size);

	while (trav != NULL){
		size += (strlen(trav->item.err_msg));
//		printf("size of string: %d\n", size); 
		str = (char*) realloc(str, size);
		sprintf(str + strlen(str), "%s", trav->item.err_msg);
		trav = trav->next;
//		printf("%s\n", str);
	}
	return str;
}

int SaveLog(char* log_file_name) {
	FILE* file_write = fopen(log_file_name, "a");

	if (headptr == NULL){
		errno = ENODATA;
		return -1;
	}
	char* str_out = getlog();
	fprintf(file_write, "%s", str_out);
	free(str_out);
	
	fclose(file_write);
	return 0;
}
