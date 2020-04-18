#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SinglyLinkedList.h"
#include "csvParser.h"

const char* getStoredValue(LinkedListPtr_t *csv, int column, int row){
  char *temp = malloc(MAX_CELL_SIZE * sizeof(char));
  strcpy(temp, getFromList(csv[column -1]->head, row - 1));
  return temp;
  free(temp);
}

void parseCSV(LinkedListPtr_t *csv, int *col, int *row){

  int inQuotes = 0;
  int totalColumns = 0;
  int totalRows = 0;

  char line[1024];
  fgets(line, 1024, stdin); //void first line?
  for(int i = 0; i < strlen(line); i++){
    if(line[i] == '"'){
      if(inQuotes == 0) inQuotes = 1;
      else inQuotes = 0;
    }else if(line[i] == ',' && inQuotes == 0){
      totalColumns++;
    }
  }

  for(int x = 0; x < totalColumns; x++){
    csv[x] = createSinglyList();
  }

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
