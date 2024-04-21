#include "queue.h"
#include "Node.h"
#include <stddef.h> 
#include <stdlib.h>

void queueInit(Queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}

void enqueue(Queue* queue, void* data){
	if(queue->size >= MAX_QUEUE_SIZE){
		printf("The queue is full");
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	initNode(newNode, data);
	if (queue->front == NULL && queue->rear == NULL)
	{
		queue->front = queue->rear = newNode;
	}
	else {
		queue->rear->next =  newNode;
		queue->rear = newNode;
	}
	queue->size++;
}
void* dequeue(Queue* queue) {
	if (queue->front == NULL) {
		printf("The queue is empty.\n");
		return NULL;
	}

	Node* nodeToRemove = queue->front;
	void* data = queue->front->data;
	queue->front = nodeToRemove->next;
	free(nodeToRemove);
	queue->size--;

	return data;
}
