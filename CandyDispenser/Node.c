#include "Node.h"
#include <stddef.h> 

void initNode(Node* node, void* data) {
	if (node != NULL) {
		node->data = data;
		node->next = NULL;
	}
}