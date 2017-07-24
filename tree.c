#include<stdio.h>
#include<stdlib.h>

#define PRE	1
#define MID	2
#define POST	3

typedef struct T T;

struct T {
	int n;
	T *left;
	T *right;
};


void my_print(T *root, int type) {

	if (root) {
		switch(type) {
			case PRE:
				printf("%d ",root->n);	
				my_print(root->left, 1);
				my_print(root->right,1);
				break;
			case MID:
				my_print(root->left, 2);
				printf("%d ",root->n);	
				my_print(root->right,2);
				break;
			case POST:
			default:
                                my_print(root->left, 3);
                                my_print(root->right,3);
				printf("%d ",root->n);	
				break;
		}
	}
}

int main() {
	
	T *root = malloc(sizeof(T *));
	root->n = 10;
	root->left = malloc(sizeof(T *));
	root->right = malloc(sizeof(T *));

	root->left->n = 6;
	root->right->n=14;

	root->left->left = malloc(sizeof(T *));
	root->left->right = malloc(sizeof(T *));

	root->left->left->n = 4;
	root->left->right->n = 8;

	root->right->left = malloc(sizeof(T *));
	root->right->right = malloc(sizeof(T *));

	root->right->left->n = 12;
	root->right->right->n = 16;

	my_print(root, 1);
	printf("\n");
	my_print(root, 2);
	printf("\n");
	my_print(root, 3);
	printf("\n");

}



