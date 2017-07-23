#include<stdio.h>
#include<stdlib.h>

typedef struct BinaryTreeNode BinaryTreeNode;

struct BinaryTreeNode
{
    int        m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};


void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
    if (pNode == NULL)
        return;

    BinaryTreeNode *pCurrent = pNode;
if (pCurrent->m_pLeft != NULL)
        ConvertNode(pNode->m_pLeft, pLastNodeInList);


    pCurrent->m_pLeft = *pLastNodeInList;
    if (*pLastNodeInList != NULL)
        (*pLastNodeInList)->m_pRight = pCurrent;


    *pLastNodeInList = pCurrent;

    if (pCurrent->m_pRight != NULL)
        ConvertNode(pNode->m_pRight, pLastNodeInList);
    
}

BinaryTreeNode* Convert(BinaryTreeNode* pRoot)
{
    BinaryTreeNode* pLastNodeInList = NULL;
    ConvertNode(pRoot, &pLastNodeInList);



    BinaryTreeNode* pHeadOfList = pLastNodeInList;
    while (pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL)
        pHeadOfList = pHeadOfList->m_pLeft;

    return pHeadOfList;
}


int main() {

	BinaryTreeNode *root = malloc(sizeof(BinaryTreeNode *));

	root->m_nValue = 10;
	root->m_pLeft = malloc(sizeof(BinaryTreeNode *));
	root->m_pLeft->m_nValue = 6;
	root->m_pRight = malloc(sizeof(BinaryTreeNode *));
	root->m_pRight->m_nValue = 14;

	root->m_pLeft->m_pLeft = malloc(sizeof(BinaryTreeNode *));
	root->m_pLeft->m_pLeft->m_nValue=4;
	root->m_pLeft->m_pRight = malloc(sizeof(BinaryTreeNode *));
	root->m_pLeft->m_pRight->m_nValue=8;

	root->m_pRight->m_pLeft = malloc(sizeof(BinaryTreeNode *));
	root->m_pRight->m_pLeft->m_nValue=12;
	root->m_pRight->m_pRight = malloc(sizeof(BinaryTreeNode *));
	root->m_pRight->m_pRight->m_nValue=16;

	BinaryTreeNode *pHeadOfList = Convert(root);

	while(pHeadOfList){
		printf("%d ",pHeadOfList->m_nValue);
		pHeadOfList = pHeadOfList->m_pRight;
	}



}

