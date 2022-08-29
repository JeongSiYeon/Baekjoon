#include <stdio.h>
#include <stdlib.h>

typedef struct _bstnode
{
    int data;
    int count;
    struct _bstnode *left;
    struct _bstnode *right;
} BSTNode;

typedef struct _binarySerachTree
{
    BSTNode *root;
} BST;

void BST_Init(BST *pBST)
{
    pBST->root=NULL;
}

void Node_Init(BSTNode *BSTNode)
{
    BSTNode->count=0;
    BSTNode->left=NULL;
    BSTNode->right=NULL;
}

void BST_insert(BST *pBST, int key)
{
    BSTNode *pNode = (BSTNode *)malloc(sizeof(BSTNode));
    Node_Init(pNode);

    BSTNode *newNode=(BSTNode *)malloc(sizeof(BSTNode));
    Node_Init(newNode);

    pNode=pBST->root;
    newNode->data=key;

    while(pNode != NULL)
    {
        if(pNode->data==key)
        {
            (pNode->count)++;
            break;
        }

        else if(pNode->data>key)
        {
            if(pNode->left==NULL)
                pNode->left=newNode;
            pNode=pNode->left;           
        }

        else if(pNode->data<key)
        {
            if(pNode->right==NULL)
                pNode->right=newNode;
            pNode=pNode->right;
        }
    }

    if(pBST->root==NULL)
        pBST->root=newNode;
}

int how_many_keys(BST *pBST, int key)
{
    int count=0;
    BSTNode *pNode=(BSTNode *)malloc(sizeof(BSTNode));
    pNode=pBST->root;

    while(pNode!=NULL)
    {
        if(pNode->data==key)
        {
            count=pNode->count;
            return count;
        }

        else if(pNode->data>key)
            pNode=pNode->left;

        else if(pNode->data<key)
            pNode=pNode->right;
    }

    return count;
}

int main(void)
{
    int i, key, numOfCards, numOfint, howManyExist;
    int *intNums;

    BST *pBST_cardNums=(BST *)malloc(sizeof(BST));
    BST_Init(pBST_cardNums);
    
    // 1 <= numOfCards <= 500 000
    scanf("%d%*c", &numOfCards); 
   
    // -10 000 000 <= cardNums <= 10 000 000
    for(i=0; i<numOfCards; i++) 
    {
        scanf("%d%*c", &key);
        BST_insert(pBST_cardNums, key);
    }
    
    // 1 <= numOfint <= 500 000
    scanf("%d%*c", &numOfint);
    intNums=(int *)malloc(sizeof(int)*numOfint);

    // -10 000 000 <= intNums <= 10 000 000
    for(i=0; i<numOfint; i++)
        scanf("%d%*c", &intNums[i]);
    
    for(i=0; i<numOfint; i++)
    {
        howManyExist=how_many_keys(pBST_cardNums, intNums[i]);
        printf("%d ", howManyExist);
    }
    return 0;
}