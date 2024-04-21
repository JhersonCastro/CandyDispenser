#include "list.h"
#include <stdio.h>
#include	<stdio.h>
#include "Candy.h"

void listInit(List* list) {
	list->size = 0;
	list->Header = NULL;
	list->next = NULL;
}

void listAddQueue(List* list,Queue queue){
	if(list->size >= MAX_LIST_SIZE){
		printf("List is full, cammot add more queues");
		return;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	initNode(newNode, &queue);

	if (list->Header == NULL) {
		list->Header = newNode;
	}
	else {
		Node* temp = list->Header;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	//((Candy*)dequeue(((Queue*)newNode->data)))->name;
	list->size++;
}

Queue* listGetQueue(List* list, int index) {
	if (index < 1 || index > list->size ) {

	}
	Node* temp = list->Header;
	for (int i = 1; i < index; i++)
	{
		temp= temp->next;
	}
	return ((Queue*)temp->data);
}