#include <stdio.h>
#include "log.h"
#include <unistd.h>

int main ( int argc, char *argv[] ){

	char* log_file_name = "logfile.txt";
	int special_number = 37;
	int c;

	//check that there is the correct number of command line arguments

	while ( (c = getopt(argc, argv, "hl:n:012")) != -1) {
		switch(c){
		case '0':
		case '1':
		case '2':
		case 'h':
			printf("%s\n", "-h\tHelp Menu\n-n\tSet special number\n-l\tSet log file name");
			return 0;
			break;
		case 'l':
			log_file_name = argv[2];
			break;
		case 'n':
                        special_number = atoi(argv[2]);
			break;
                }
        }

	return 0;
}
