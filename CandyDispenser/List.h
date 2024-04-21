#pragma once
#ifndef LIST_H
#define LIST_H
#include "Queue.h"
#define MAX_LIST_SIZE 5

typedef struct {
	Node* next;
	Node* Header;
	int size;
}List;
void listInit(List* list);
void listAddQueue(List * list, Queue queue);
Queue* listGetQueue(List* list, int index);

#endif