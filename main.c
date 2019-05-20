/**
    created by Lucas Ferreira
        10/22/2017
            V: 1.0.1
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "headers/functions.h"
#include "headers/fl_proc.h"
#include "headers/crypto.h"
#include "headers/pgstruct.h"

#define PARAMETERS 4 /**parameters: [programName] [-trigger] [file-path] [keys-path]**/

int main(int argc, char* argv[]){
	switch(argc){
		case 1:
			noParameters();
			return EXIT_FAILURE;
		case 2:
			if(strcmp(argv[1], "--help") == 0){
				help();
				return EXIT_SUCCESS;
			} else{
				parameterUnknown(argv[1]);
				return EXIT_FAILURE;
			}

		case PARAMETERS:
			//trigger filter
			if (strcmp(argv[1], "-e") == 0){
				encrypt(argv[2], argv[3]);
			} else{
				if(strcmp(argv[1], "-d") == 0){
						decrypt(argv[2], argv[3]);
				} else{
					parameterUnknown(argv[1]);
					return EXIT_FAILURE;
				}
			}
			return EXIT_SUCCESS;
		default:
			notRecognized();
			return EXIT_FAILURE;
	}
}
