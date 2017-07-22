#include<stdio.h>
#include<stdlib.h>


typedef struct LIST  LIST;
struct LIST {
	int d;
	LIST *next;
};


LIST *reserve(LIST *head) {
	LIST *p;
	LIST *tmp;

	p = head->next;
	tmp = p->next;
	p->next = NULL;
	head->next = p;
	p = tmp;

	while(p) {
		tmp = p->next;
		p->next = head->next;
		head->next = p;
		p = tmp;
	}
	
	return head;
}

int main () {
	LIST *head = malloc(sizeof(LIST));

	LIST *node1 = malloc(sizeof(LIST));
	node1->d=1;
	head->next = node1;


	LIST *node2 = malloc(sizeof(LIST));
	node2->d=2;
	node1->next = node2;


	LIST *node3 = malloc(sizeof(LIST));
	node3->d=3;
	node2->next = node3;

	LIST *node4 = malloc(sizeof(LIST));
	node4->d=4;
	node3->next = node4;

	node4->next = NULL;


	LIST *p=head->next;
	while(p != NULL) {
		printf("%d\n", p->d);
		p = p->next;	
	}

	printf("----------\n");

	p=reserve(head);
	p=p->next;
	while(p != NULL) {
		printf("%d\n", p->d);
		p = p->next;	
	}
}

