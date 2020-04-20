#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SinglyLinkedList.h"
#include "csvParser.h"

/**
 * Returns the value stored in at a specific index in the parsed CSV file
 *
 * @param csv      (pointer to linked list) of the list you want to read from
 * @param column   (int) the column of the CSV you wish to read from
 * @param row      (int) the row of the CSV you wish to read from
 *
 */
const char* getStoredValue(LinkedListPtr_t *csv, int column, int row){
  char *temp = malloc(MAX_CELL_SIZE * sizeof(char));
  strcpy(temp, getFromList(csv[column -1]->head, row - 1));
  return temp;
  free(temp);
}

/**
 * Parses the CSV file passed in through STDIN and stored values in a given list
 *
 * @param csv      (pointer to linked list) of the list you want to write to
 * @param col      (int) Pointer to an int where you will store the amount of columns in the CSV
 * @param row      (int) Pointer to an int where you will store the amount of rows in the CSV
 *
 */
void parseCSV(LinkedListPtr_t *csv, int *col, int *row){

  int inQuotes = 0;
  int totalColumns = 0;
  int totalRows = 0;

  char line[1024];
  fgets(line, 1024, stdin); //Load first line

  //Determine the amount of columns in each row. This uses the first row as a basis for all the others
  for(int i = 0; i < strlen(line); i++){
    if(line[i] == '"'){
      if(inQuotes == 0) inQuotes = 1;
      else inQuotes = 0;
    }else if(line[i] == ',' && inQuotes == 0){
      totalColumns++;
    }
  }

  //Create the list for dynamically storing all reocrds
  for(int x = 0; x < totalColumns; x++){
    csv[x] = createSinglyList();
  }

  //Step through all rows and parse the data
  do
  {
    int curColumn = 0;
    int start_idx = 0;
    for(int i = 0; i < strlen(line); i++){
      if(line[i] == '"'){
        if(inQuotes == 0) inQuotes = 1;
        else inQuotes = 0;
      }else if(line[i] == ',' && inQuotes == 0){
        char *temp;
        memset(temp, 0, strlen(temp));
        strncpy(temp, line + start_idx, i - start_idx);

        insertInSinglyLinkedList(csv[curColumn], temp, singlyListLength(csv[curColumn]) + 1);
        curColumn++;
        start_idx = i + 1;
      }
    }
    totalRows++;
  }while (fgets(line, 1024, stdin));

  *col = totalColumns;
  *row = totalRows;

}
