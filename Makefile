csvParser: main.o SinglyLinkedList.o csvParser.o
	gcc -o csvParser main.o csvParser.o SinglyLinkedList.o
main.o: main.c csvParser.c SinglyLinkedList.c
	gcc -c main.c csvParser.c SinglyLinkedList.c
csvParser.o: csvParser.c
	gcc -c csvParser.c
SinglyLinkedList.o: SinglyLinkedList.c
	gcc -c SinglyLinkedList.c
clean:
	rm csvParser.o SinglyLinkedList.o csvParser.exe main.o csvParser.h.gch SinglyLinkedList.h.gch
