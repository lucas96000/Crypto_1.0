#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define ALL_CHARS 36
#define T_ROWS    6
#define T_COLS    6
#define STR_MAX   200

//Append a char at the end of a string
void strAppend(char str[], char c){
  str[strlen(str)  ] = c;
  str[strlen(str)+1] = '\0';
}

//Randomize the array
void arrayShuffle(char array[]){
  srand(time(NULL)); // randomize seed

  for (int i = 0; i < ALL_CHARS - 1; i++){
    int j = i + rand() / (RAND_MAX / (ALL_CHARS - i) + 1);
    int aux = array[j];
    array[j] = array[i];
    array[i] = aux;
  }
}

//Fetch the randomized chars array into a matrix
void fetchArrayIntoMatrix(char matrix[][T_COLS], char array[]){
  int row = 0, col = 0;

  for(int i = 0; i < ALL_CHARS; i++){
    matrix[row][col] = array[i];

    col++;

    if(col == 6){
      ++row;
      col = 0;
    }
  }
}

//Returns the coordinate in char
char getCoordinateChar(int coordinate){
  char ADFGVXcoordinates[] = {'A','D','F','G','V','X'};
  char c = ADFGVXcoordinates[coordinate];

  return c;
}

//Select the key by the string length
void keySelect(char keys[][STR_MAX], char key[], int coorSize, int keysSize){
  for(int i = 0; i < keysSize; ++i){
    if(coorSize % strlen(keys[i]) == 0){
      strcpy(key, keys[i]);
    }
  }
}

//Returns the index of the char in the string
int getIndex(char str[], char val){
    int i = 0;

    while(i < strlen(str) && str[i] != val) ++i;

    return i;
}
