#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {  
	if(root == NULL || p == NULL || q == NULL)  
		return root;  
	if(p->val > root->val && q->val > root->val)  
		return lowestCommonAncestor1(root->right, p, q);  
	else if(p->val < root->val && q->val < root->val)  
		return lowestCommonAncestor1(root->left, p, q);  
	else  
		return root;  
}  


TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {  
	if(root == NULL)  
		return NULL;  
	if(root->val == p->val || root->val == q->val)
		return root;  
	TreeNode* leftReturn = lowestCommonAncestor2(root->left, p, q);  
	TreeNode* rightReturn = lowestCommonAncestor2(root->right, p, q);  
	if(leftReturn != NULL && rightReturn != NULL)  
		return root;  
	if(leftReturn != NULL)  
		return leftReturn;  
	if(rightReturn != NULL)  
		return rightReturn;  
}  


int main() {
	TreeNode *root = malloc(sizeof(TreeNode *));
	TreeNode *p = malloc(sizeof(TreeNode *));
	TreeNode *q = malloc(sizeof(TreeNode *));

	root->val = 10;
	root->left = malloc(sizeof(TreeNode *));
	root->left->val = 6;
	root->right = malloc(sizeof(TreeNode *));
	root->right->val = 14;

	root->left->left = malloc(sizeof(TreeNode *));
	root->left->left->val=4;
	root->left->right = malloc(sizeof(TreeNode *));
	root->left->right->val=8;

	root->right->left = malloc(sizeof(TreeNode *));
	root->right->left->val=12;
	root->right->right = malloc(sizeof(TreeNode *));
	root->right->right->val=16;


	p->val = 6;
	q->val = 16;
	printf("p:%d q:%d commonAncestor:%d\n", p->val, q->val, (lowestCommonAncestor1(root, p, q))->val);
	p->val = 12;
	q->val = 16;
	printf("p:%d q:%d commonAncestor:%d\n", p->val, q->val, (lowestCommonAncestor1(root, p, q))->val);
	p->val = 10;
	q->val = 14;
	printf("p:%d q:%d commonAncestor:%d\n", p->val, q->val, (lowestCommonAncestor1(root, p, q))->val);
	p->val = 16;
	q->val = 14;
	printf("p:%d q:%d commonAncestor:%d\n", p->val, q->val, (lowestCommonAncestor1(root, p, q))->val);
	printf("-----------------------------\n");

	root->val = 6;
	root->left = malloc(sizeof(TreeNode *));
	root->left->val = 4;
	root->right = malloc(sizeof(TreeNode *));
	root->right->val = 12;

	root->left->left = malloc(sizeof(TreeNode *));
	root->left->left->val=14;
	root->left->right = malloc(sizeof(TreeNode *));
	root->left->right->val=16;

	root->right->left = malloc(sizeof(TreeNode *));
	root->right->left->val=8;
	root->right->right = malloc(sizeof(TreeNode *));
	root->right->right->val=10;


	p->val = 4;
	q->val = 10;
	printf("p:%d q:%d commonAncestor:%d\n", p->val, q->val, (lowestCommonAncestor2(root, p, q))->val);
	p->val = 4;
	q->val = 14;
	printf("p:%d q:%d commonAncestor:%d\n", p->val, q->val, (lowestCommonAncestor2(root, p, q))->val);
	p->val = 10;
	q->val = 8;
	printf("p:%d q:%d commonAncestor:%d\n", p->val, q->val, (lowestCommonAncestor2(root, p, q))->val);
	p->val = 6;
	q->val = 8;
	printf("p:%d q:%d commonAncestor:%d\n", p->val, q->val, (lowestCommonAncestor2(root, p, q))->val);
}




