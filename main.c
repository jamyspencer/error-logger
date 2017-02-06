/* Written by Jamy Spencer 30 Jan 2017 */
#include <stdio.h>
#include "log.h"
#include <unistd.h>

int main ( int argc, char *argv[] ){

	char* log_file_name = "logfile.txt";
	char* spec_num = "37";
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
			log_file_name = optarg;
			break;
		case 'n':
			spec_num = optarg;
			break;
		case '?':
			return 1;
			break;
		}
	}

	addmsg(CreateErrMsg("Jumping Jack Flash got stuck in the mud", argv[0], spec_num));
	addmsg(CreateErrMsg("Error: Self Destruct Sequence Initiated", argv[0], spec_num));

	if (SaveLog(log_file_name) == -1){
		CreateErrMsg("Error Log Empty", argv[0], spec_num);
	}
	
	clearlog();
	return 0;
}
