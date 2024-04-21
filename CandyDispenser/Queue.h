#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"


#define MAX_QUEUE_SIZE 100


typedef struct {
	Node nodes[MAX_QUEUE_SIZE];
	Node* front;
	Node* rear;
	int size;
}Queue;

void queueInit(Queue* queue);
void enqueue(Queue* queue, void* data);
void* dequeue(Queue* queue);
#endif