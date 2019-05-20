#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define STR_MAX 200

int getFileDataLength(char* filePath){
  FILE* f = fopen(filePath, "r"); //open the file
  int fileDataLen = 0;

  if(f != NULL){           //verify
    while(!feof(f)){       //foreach the file data
      char c = fgetc(f);   //get char

      if(c == EOF){
        if(ferror(f)){
          perror("was not possible to read the file.");
          fclose(f);
        }
        continue;
      }

      if(c == ' ' || c == '\n'){
        ++fileDataLen;
      }
    }

    fclose(f);

    return fileDataLen;
  } else{
    printf("No such file or directory.\n");
    exit(EXIT_FAILURE);
  }
}

void fillFileData(char* filePath, char data[][STR_MAX]){
  FILE* f = fopen(filePath, "r"); //open the file

  if(f != NULL){                  //verify
    int i = 0, j = 0;             //index

    while(!feof(f)){              //foreach the file data
      char c = fgetc(f);          //get char

      if(c == EOF){
        if(ferror(f)){
          perror("was not possible to read the file.\n");
          fclose(f);
        }
        continue;
      }

      if(c == ' ' || c == '\n'){
        data[i][j] = '\0';
        ++i;
        j = 0;
      } else{
        data[i][j] = toupper(c);
        ++j;
      }
    }

    data[i][j-1] = '\0';

    fclose(f);
  } else{
    printf("No such file or directory.\n");
    exit(EXIT_FAILURE);
  }
}

void matrixToFile(char matrix[][STR_MAX], int matrixSize, FILE* file){
  if(file != NULL){
    for(int i = 0; i < matrixSize; ++i)
        fputs(matrix[i], file);

    fclose(file);
  } else{
      printf("Error to generate the file.\n");
      exit(EXIT_FAILURE);
  }
}
