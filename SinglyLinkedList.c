/*
 * SinglyLinkedList.c - Linked list source for storing and retrieving team info
 *
 * Originator: Narasimha Karumanchi
 * Author:  Devon Mickels
 *
 * This is the source code file that for functionality specific to the Team Info database that
 * is part of an ECE 361 homework assignment.
 *
 * This file, and its associated header file (including the functions that you
 * need to provide) are meant to be to provide a Linked List to your main()
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include "SinglyLinkedList.h"

/**
 * Allocates space for a new Linked list and returns pointer
 *
 * @returns         a pointer to the linked list
 */
LinkedListPtr_t createSinglyList(void) {
    LinkedListPtr_t S = (LinkedListPtr_t)malloc(sizeof(LinkedList_t));
    if(!S)
      return NULL;
		S->head = NULL;
    return S;
}

/**
 * Gets the length of a linked list
 *
 * @param list      (pointer to linked list) containing the list you want to get the length of
 *
 * @returns         the length of the linked list
 */
int singlyListLength(LinkedListPtr_t list){
	int count=0;
	ListNodePtr_t current=list->head;
	while(current!=NULL){
		count++;
		current=current->next;
	}
	return count;
}

/**
 * Inserts a team struct into the linked list
 *
 * @param list      (pointer to linked list) of the list you want to insert information
 * @param data      (pointer to team data) of the data you want to insert
 * @param pos       (int) of the position in the list you want to insert to
 *
 */
void insertInSinglyLinkedList(LinkedListPtr_t list, char *data, int pos){
	int k=1;
	ListNodePtr_t head = list->head;
	ListNodePtr_t q,p;
	ListNodePtr_t newNode=(ListNodePtr_t)malloc(sizeof(ListNode_t));
	if(!newNode){
		printf("Memory Error\n");
		return;
	}
	//newNode->data=data;
	newNode->data = malloc(strlen(data) * sizeof(char));
	strcpy(newNode->data, data);
	p=head;
	if(pos==1 || p==NULL){
		newNode->next=head;
		list->head=newNode;
	}
	else{
		while(p!=NULL && (k<pos)){
			k++;
			q=p;
			p=p->next;
		}
		newNode->next=q->next;
		q->next=newNode;
	}
}

/**
 * Deletes a team struct from a linked list
 *
 * @param list      (pointer to linked list) of the list you want to delete from
 * @param pos       (int) of the position in the list you want to delete
 *
 */
void deleteNodeFromLinkedList(LinkedListPtr_t list, int pos){
	int k=1;
	ListNodePtr_t p,q;
	p=list->head;
	if(list->head==NULL){
		printf("List Empty\n");
		return;
	}
	else if(pos==1){
		list->head=(list->head)->next;
		free(p);
	}
	else{
		while(p!=NULL && k<pos){
			k++;
			q=p;
			p=p->next;
		}
		if(p==NULL){
			printf("Position does not exist\n");
		}
		else{
			q->next=p->next;
			free(p);
		}
	}
}

/**
 * Returns a pointer to a team info struct given the position in the linked list.
 *
 * @param list      (pointer to linked list) of the list you want to get from
 * @param pos       (int) of the position in the list you want to get
 *
 * @returns         (pointer to team struct) of the information at that point
 */
const char* getFromList(ListNodePtr_t list, int pos){
  if(pos == 0)
    return list->data;

  return getFromList(list->next, pos - 1);
}
