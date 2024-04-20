#pragma once
#ifndef NODE_H
#define NODE_h
typedef struct node {
	void* data;
	struct node* next;
}Node;
Node* createNode(void* data);

#endif