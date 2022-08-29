#include <stdio.h>
#include <stdlib.h>

#define NOWHERE  0
#define LEFT     1
#define RIGHT    2

typedef int BTData;

typedef struct _BTNode
{
    int go;
    BTData data;
    struct _BTNode *left;
    struct _BTNode *right;
} BTNode;

BTNode *MakeBTNode(BTData data);
void NGE_input(BTNode *pNGE, BTData data);
void NGE_print(BTNode *pNGE);

int main(void)
{
    int i, numOfseries;
    BTData num;

    scanf("%d%*c", &numOfseries); 
    scanf("%d%*c", &num);

    // make NGE tree
    BTNode *NGE = MakeBTNode(num);
    for(i = 1; i < numOfseries; i++)
    {
        scanf("%d%*c", &num);   
        NGE_input(NGE, num);
    }

    // print NGE tree
    NGE_print(NGE);
    return 0;
}

BTNode *MakeBTNode(BTData data)
{
    BTNode *newNode = (BTNode *)malloc(sizeof(BTNode));
    newNode->go = NOWHERE;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void NGE_input(BTNode *pNGE, BTData data)
{
    if(pNGE == NULL) return;

    if(pNGE->go == LEFT)
        NGE_input(pNGE->left, data);
    else if(pNGE->go == RIGHT)
        NGE_input(pNGE->right, data);

    if(pNGE->right == NULL && pNGE->data < data)
    {
        BTNode *newNode = MakeBTNode(data);
        pNGE->right = newNode;
        if(pNGE->go == NOWHERE)
            pNGE->go = RIGHT;
    }
    else if(pNGE->right == NULL && pNGE->left == NULL && pNGE->data >= data)
    {
        BTNode *newNode = MakeBTNode(data);
        pNGE->left = newNode;
        if(pNGE->go == NOWHERE)
            pNGE->go = LEFT;
    }
}

void NGE_print(BTNode *pNGE)
{
    if(pNGE->right == NULL) printf("-1 ");
    else                    printf("%d ", pNGE->right->data);
    
    if     (pNGE->go == LEFT)  NGE_print(pNGE->left);
    else if(pNGE->go == RIGHT) NGE_print(pNGE->right);
    
    return;
}