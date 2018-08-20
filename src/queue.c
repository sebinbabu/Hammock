#include <malloc.h>

#include "queue.h"

node* create_node(char *s, int d, node *next) {
	node *t = malloc(sizeof(node));
	t->s = s;
	t->depth = d;
	t->next = next;
	return t;
}

void free_node(node *n) {
	free(n->s);
	free(n);
}

void q_insert(queue *q, node* n) {
	if(q->h == NULL) {
		q->h = n;
		q->t = n;
	} else {
		q->t->next = n;
		q->t = n;
	}
}

void q_delete(queue *q) {
	node *t = q->h;
	if(t != NULL) {
		q->h = q->h->next;
		if(q->h == NULL)
			q->t = NULL;
		free_node(t);
	}

}

int q_empty(queue *q) {
	return q->h == NULL;
}

node* q_peek(queue *q) {
	return q->h;
}

void q_free(queue *q) {
	while(q->h != NULL)
		q_delete(q);
}