# CSVParser
## <i>CSV Parse that makes use of a linked list algorithm in order to dynamically allocate space and store contents of a CSV file for runtime use.</i>  

### Setup and test

Download/clone contents to a directory and navigate to it and run:
```
make
```
View a test of this program in action with the included example
```
./csvParser < test.csv
```

### Usage

In order to use this, simply add contents to your directory and include:

```
#include "SinglyLinkedList.h"
#include "csvParser.h"
```

Parsing your CSV is as easy as adding
```
int row, col;
LinkedListPtr_t csv[COLUMNS]; //Allocates a place to store data
printf("\n")
parseCSV(csv, &col, &row); //Parse the CSV. Returns number of columns, rows and stores data in allocated list.
```

Reference data from your CSV using:
```
getStoredValue(LinkedListPtr_t csv, int colToGet, int rowToGet)
```
