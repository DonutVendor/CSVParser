#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SinglyLinkedList.h"
#include "csvParser.h"

int main(){

  int row, col;
  LinkedListPtr_t csv[COLUMNS];
  printf("\n");
  parseCSV(csv, &col, &row);

  printf("Success: %d Cols & %d Rows\n", col, row);
  printf("Column 3, Row 1 Value: %s\n", getStoredValue(csv, 3, 1));
  printf("Column 2, Row 3 Value: %s\n", getStoredValue(csv, 2, 3));
  printf("Column 1, Row 4 Value: %s\n", getStoredValue(csv, 1, 4));
  printf("Column 1, Row 5 Value: %s\n", getStoredValue(csv, 1, 5));

  return 0;
}
