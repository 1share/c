#include<stdio.h>
#include<stdlib.h>

typedef struct T T;

struct T {
	int n;
	T *left;
	T *right;
};

void convert(T *node, T **last) {
	if (NULL == node)
		return;
	
	T *c = node;

	if (c->left)
		convert(c->left, last);

	
	c->left = *last;

	if(*last != NULL)	
		(*last)->right = c;

	*last = c;

	if (c->right)
		convert(c->right, last);
}

T *my_convert(T *node){
	T *last = NULL;

	convert(node, &last);
	
	T *result = last;
	while(result->left != NULL) {
		result = result->left;
	}

	return result;
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

	T *result = my_convert(root);

	while(result){
		printf("%d ",result->n);
		result=result->right;
	}

}



