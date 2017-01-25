#include <stdio.h>
#include "log.h"

int main ( int argc, char *argv[] ){

	char* log_file_name = "logfile.txt";
	int special_number = 37;

	//check that there is the correct number of command line arguments
	if (argc < 1 || argc > 3){
		printf("Error: This program requires 0-2 command line arguments\n");
                return 1;
	}
	//command line argument functionality
	if (strcmp(argv[1], "-h") == 0){
		printf("%s\n", "-h\tHelp Menu\n-n\tSet special number\n-l\tSet log file name");
		return 0;
	}
	else if (strcmp(argv[1], "-l") == 0){
		if (argc == 3){
			log_file_name = argv[2];
		}
		else{
			printf("Error: when using the -l flag you have to include a file name\n");
			return 1;
		}
	}
	else if (strcmp(argv[1], "-n") == 0){
                if (argc == 3){
                        special_number = atoi(argv[2]);
                }
                else{
                        printf("Error: when using the -n flag you have to include a special number\n");
                        return 1;
                }
        }

	return 0; 
}
