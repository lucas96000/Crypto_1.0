#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define STR_MAX   200
#define ALL_CHARS 36
#define T_ROWS    6
#define T_COLS    6

void encrypt(char* filePath, char* keysPath){
  int fileSize, keysSize;

  fileSize = getFileDataLength(filePath); //file length
  char file[fileSize][STR_MAX];           //file data

  keysSize = getFileDataLength(keysPath); //file length
  char keys[keysSize][STR_MAX];           //file data

  char fileEncrypted[fileSize][STR_MAX]; //file data encrypted

  fillFileData(filePath, file);         //file data to encrypt
  fillFileData(keysPath, keys);         //keys

  char allChars[ALL_CHARS];
  initializeCharsArray(allChars);       //array if all chars

  char ADFGVXtable[T_ROWS][T_COLS];
  initializeADFGVXTable(ADFGVXtable, allChars); //matrix if the ADFGVX coordinates

  for(int i = 0; i < fileSize; ++i){         //foreach passing by all file's words to encrypt
    int wordLen    = strlen(file[i]);        //word length

    if(wordLen != 0){                        //check if the string is not null
      int coorLen    = (wordLen * 2) + 1;    //coordinate length

      char coordinates[coorLen];             //array with the word's ADFGCX coordinates

      getCoordinates(ADFGVXtable, file[i], coordinates);
      int coorSize = strlen(coordinates);

      char key[STR_MAX];                                   //key
      keySelect(keys, key, coorSize, keysSize); //select the key by the string length

      int keyLen    = strlen(key);          //key length
      int coorMrows = (coorSize / keyLen) + 1; //define coordinates matrix's row

      char coordinatesMatrix[keyLen][coorMrows+1];
      initializeCoordMatrix(coordinates, key, coorMrows, coordinatesMatrix);

      printf("%s\n", coordinates);

      printf("before sort\n");
      for(int i = 0; i < strlen(key); ++i){
        for(int j = 0 ; j < coorMrows; j++){
          printf("%c", coordinatesMatrix[i][j]);
        }
        printf("\n");
      }
      printf("\n");

      matrixAlphSort(key, coorMrows, coordinatesMatrix);

      printf("after sort\n");
      for(int k = 0; k < coorMrows; ++k){
        for(int j = 0 ; j < keyLen; j++){
          printf("%c", coordinatesMatrix[k][j]);
        }
        printf("\n");
      }
      printf("\n");
    }
  }
}

void decrypt(char* filePath, char* keysPath){
  int fileSize, keysSize;

  fileSize = getFileDataLength(filePath); //file length
  char file[fileSize][STR_MAX];           //file data

  keysSize = getFileDataLength(keysPath); //file length
  char keys[keysSize][STR_MAX];           //file data

  char fileEncrypted[fileSize][STR_MAX]; //file data encrypted

  fillFileData(filePath, file);         //file data to encrypt
  fillFileData(keysPath, keys);         //keys
}

void parameterUnknown(char* parameter){
  printf("parameter \"%s\" not recognized. \"--help\" to see all parameters.\n", parameter);
  exit(EXIT_FAILURE);
}

void notRecognized(){
  printf("parameters not recognized.\n");
  exit(EXIT_FAILURE);
}

void noParameters(){
  printf("Need parameters to execute.\n");
  exit(EXIT_FAILURE);
}

void help(){
  printf("\nparameters: [programName] [-trigger] [file-path] [keys-path]\n triggers:\n	-e to encrypt the txt file\n	-d to decrypt the txt file\n\n");
  exit(EXIT_SUCCESS);
}
