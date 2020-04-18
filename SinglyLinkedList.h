/*Copyright (c) 2016 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com
#Created by        : Narasimha Karumanchi
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any
#                    warranty; without even the implied warranty of
#                    merchantability or fitness for a particular purpose.
#Modified by Devon Mickels to hide the ADT of listNode head*/

#ifndef _SINGLYLINKEDLIST_H
#define _SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

// define the struct that contains a node in the linked list
typedef struct _listNode {
	char *data;		// Pointer to Team info record for the node
	struct _listNode *next;	// next pointer for the node
} ListNode_t, *ListNodePtr_t;

// define the struct that contains an instance of the Linked List
typedef struct _linkedList {
	ListNodePtr_t head;		// pointer to the head node of the list
} LinkedList_t, *LinkedListPtr_t;

LinkedListPtr_t createSinglyList(void);

int singlyListLength(LinkedListPtr_t list);

void insertInSinglyLinkedList(LinkedListPtr_t list, char *data, int pos);

void deleteNodeFromLinkedList(LinkedListPtr_t list, int pos);

void printSLList(LinkedListPtr_t list);

const char* getFromList(ListNodePtr_t list, int pos);

#endif
