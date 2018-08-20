#ifndef QUEUE_H
#define QUEUE_H

typedef struct NODE {
	char *s;
	int depth;
	struct NODE* next;
} node;

typedef struct QUEUE {
	node *h;
	node *t;
} queue;

node* create_node(char *s, int d, node *next);
void free_node(node *n);
void q_insert(queue *q, node *n);
void q_delete(queue *q);
int q_empty(queue *q);
void q_free(queue *q);
node* q_peek(queue *q);

#endif