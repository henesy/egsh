#include <u.h>
#include <libc.h>
#include "shell.h"

// Create a new list
List
mklist()
{
	return (List){nil, 0};
}

// Append to a list
void
ladd(List* l, Proc* p)
{
	int i;
	Node* new = malloc(sizeof(Node));
	new->dat = (void*)p;
	new->next = nil;
	Node* n = l->root;
	//Node* prev = nil;
	
	if(l->size == 0){
		l->root = new;
		new->next = nil;
		l->size++;
		return;
	}

	for(i = 0; i < l->size; i++){
		if(i != l->size-1)
			n = n->next;
	}
	
	n->next = new;
	new->next = nil;
	l->size++;
	return;
	
}

// Search → delete from a list
int
ldel(List* l, void* tofind, int(*comp)(void *, void *))
{
	int i;
	Node* n = l->root;
	Node* prev = nil;
	
	if(l->size == 0){
		return false;
	}

	for(i = 0; i < l->size; i++){
		if((*comp)(n->dat, tofind)){
			if(l->size == 1){
				// 1 node
				free(n->dat);
				free(n);
				l->root = nil;
			}else if(i == 0){
				// 0 nodes
				l->root = n->next;
				free(n->dat);
				free(n);
			}else if(i == l->size-1){
				// We are the last node
				prev->next = nil;
				free(n->dat);
				free(n);
			}else{
				// this is probably unsafe
				prev->next = n->next;
				free(n->dat);
				free(n);
			}
			l->size--;
			return true;
		}
		
		if(i != l->size-1)
			n = n->next;
		prev = n;
			
	}
	return false;
}
