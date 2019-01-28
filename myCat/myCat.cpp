#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define SIZE 255

int main(int argc, char **argv) {

	//If there isn't enough arguments
	if (argc < 2) {
		//User input variable
		char echo[SIZE];
		int x;
		//While User input isn't EOF command
		while ((x = scanf("%c", echo)) != EOF) {
			//Terminating any extra characters
			echo[x] = '\0';
			//Print user input
			printf("%s", echo);

		}
	} else {
		//File pointer
		FILE *fptr;
		char fileContents[500];
		//For all arguments other than executable
		for (int i = 1; i < argc; i++) {
			//Open file 
			fptr = fopen(argv[i], "r");
			//If file not found throw error
			if (fptr == NULL) {
				perror("File Could not be found");
			} else {
				//Read all contents until End Of File
				while (fscanf(fptr, "%s", fileContents) != EOF) {
					//Print entirety of file contents
					printf("%s ", fileContents);

				}
			}
			//New line for formatting file contents
			printf("\n");
		}
	}

}

