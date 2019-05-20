#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define ALL_CHARS 36
#define T_ROWS    6
#define T_COLS    6

//insert all chars into the chars array
void initializeCharsArray(char CharsArray[]){
    int i, j;
    //insert the numbers in the array
    for(j = 48, i = 0; j <= 57; ++j, ++i){
        CharsArray[i] = (char) j;
    }
    //insert the letters in the array
    for(j = 65; j <= 90; ++j, ++i){
        CharsArray[i] = (char) j;
    }
}

//just initialize the ADFGVX table
void initializeADFGVXTable(char table[][T_COLS], char charsArray[]){
  arrayShuffle(charsArray);
  fetchArrayIntoMatrix(table, charsArray);
}

//get the coordinate to each word in the file and puts it into the coordinates array
void getCoordinates(char table[][T_COLS], char word[], char coordinates[]){
  int k = 0; //word index
  int c = 0; //coordinate index

  do{
    for(int i = 0; i < T_ROWS; ++i){   //table rows index
      for(int j = 0; j < T_COLS; ++j){ //table collumns index
        if(table[i][j] == word[k]){
          coordinates[c] = getCoordinateChar(i);
          ++c;
          coordinates[c] = getCoordinateChar(j);
          ++c;
        }
      }
    }

    ++k;
  } while(k < strlen(word));

  coordinates[c] = '\0';
}

//Fetch the coordinates array to coordinates matrix
void initializeCoordMatrix(char coordinates[], char key[], int coorMrows, char coordinatesMatrix[][coorMrows+1]){
  int c = 0;

  for(int j = 0; j <= coorMrows; ++j){
    for(int i = 0; i < strlen(key); ++i){
      if(j == 0){   //fill the first coll with the key
        coordinatesMatrix[i][j]     = key[i];
      } else{
        if(j < coorMrows){
          coordinatesMatrix[i][j]   = coordinates[c];
          ++c;

          if(i == (strlen(key) - 1)){
            c = strlen(key) * j;
          }
        } else{
          coordinatesMatrix[i][j] = '\0';
        }
      }
    }
  }
}

//Sort the code word alphabetically
void matrixAlphSort(char key[],  int coorMrows, char coordinatesMatrix[][coorMrows]){
  int keySize = strlen(key);
  int i, j;
  char* aux;

  for(i = 0; i < keySize; ++i) {
     for(j = 0; j < keySize - 1; ++j){
       if(coordinatesMatrix[i][0] < coordinatesMatrix[i][0]){
             strcpy(aux, coordinatesMatrix[i]);
             strcpy(coordinatesMatrix[i], coordinatesMatrix[i+1]);
             strcpy(coordinatesMatrix[i+1], aux);
      }
     }
  }
}
