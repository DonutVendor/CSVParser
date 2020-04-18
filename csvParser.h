#ifndef _CSV_PARSER_
#define _CSV_PARSER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SinglyLinkedList.h"
#include "csvParser.h"

#define COLUMNS 25 //If you have more columns in your CSV file, you will need to increase this
#define MAX_CELL_SIZE 512 //max amount of characters stored in a single cell

void parseCSV(LinkedListPtr_t *csv, int *col, int *row);
const char* getStoredValue(LinkedListPtr_t *csv, int column, int row);

#endif
