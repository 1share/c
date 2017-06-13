#include<stdio.h>
#include<stdlib.h>


typedef struct LIST  LIST;
struct LIST {
	int d;
	LIST *next;
};


LIST *reserve(LIST *l) {
	LIST *t;
	LIST *head = NULL;

	while(l!=NULL) {
		t = l->next;
		l->next=head;
		head=l;
		l=t;
	}

	return head;
}

int main () {
	LIST *head = malloc(sizeof(LIST));
	head->d=1;

	LIST *node1 = malloc(sizeof(LIST));
	node1->d=2;
	head->next = node1;


	LIST *node2 = malloc(sizeof(LIST));
	node2->d=3;
	node1->next = node2;


	LIST *node3 = malloc(sizeof(LIST));
	node3->d=4;
	node2->next = node3;

	LIST *node4 = malloc(sizeof(LIST));
	node4->d=5;
	node3->next = node4;

	node4->next = NULL;


	LIST *p=head;
	while(p != NULL) {
		printf("%d\n", p->d);
		p = p->next;	
	}

	printf("----------\n");

	p=reserve(head);
	while(p != NULL) {
		printf("%d\n", p->d);
		p = p->next;	
	}
}

