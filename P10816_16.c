/** C implementation for 
    Red-Black Tree Insertion **/

#include <stdio.h>
#include <stdlib.h>

#define RED   1
#define BLACK 0
#define LEFT  0
#define RIGHT 1

#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))

typedef struct _RBnode
{
    int data;  // data
    int count; // number of data
    int color; // 1-red, 0-black
    struct _RBnode *parent; // parent
    struct _RBnode *left;   // left-child
    struct _RBnode *right;  // right-child
} RBnode;

typedef struct _RBtree
{
    RBnode *root;
} RBtree;

// NIL 
// 전역변수? 지역변수? 정적변수?
// 초기화되는 전역변수? 초기화되지 않는 전역변수?
//RBnode NIL;//=(RBnode *)malloc(sizeof(RBnode));

RBnode *pNIL;

void preOrder(RBnode *root)
{
    if(root==pNIL)
        return;
    preOrder(root->left);
    preOrder(root->right);
}

RBnode *createNode_and_init(int data)
{
    RBnode *newNode;
    
    newNode=(RBnode *)malloc(sizeof(RBnode));
    newNode->data=data;
    newNode->count=1;
    newNode->color=RED;
    newNode->parent=pNIL;
    newNode->left=pNIL;
    newNode->right=pNIL;
    
    return newNode;
}

RBtree *createRBtree_and_init(void)
{
    RBtree *newRBtree;

    newRBtree=(RBtree *)malloc(sizeof(RBtree));
    newRBtree->root=pNIL;
     
    return newRBtree;
}

// Left-Rotation
RBnode *left_rotation(RBnode *target)
{
    // 언제 메모리를 할당해주어야 하고 언제는 안해도 되는거지?
    // 가리키기만할 때는 안해도 되고 멤버에 접근하거나 할때는 해야하나?
    RBnode *temp=pNIL;

    if(target->right->left != pNIL)
    {
        temp=target->right->left;
    }

    target->parent=target->right;
    target->right->left=target;
    target->right=pNIL;
    target->right=temp;

    return target->parent;
}


// Right-Rotation
RBnode *right_rotation(RBnode *target)
{
    RBnode *temp=(RBnode *)malloc(sizeof(RBnode));
    temp=pNIL;

    if(target->left->right != pNIL)
    {
        temp=target->left->right;
    }

    target->parent=target->left;
    target->left->right=target;
    target->left=pNIL;
    target->left=temp;

    return target->parent;
}

// RBinsertFixup
void RBInsertFixup(RBtree *pRBtree, RBnode *C)
{
    int G_to_P, P_to_C, temp;
    RBnode *P, *U, *G, *attatch_to, *rotation_result, *temp_node;

    P=C->parent;
    
    // CASE1: root is red
    if(P==pNIL && C->color==RED)
    {
        C->color=BLACK;
        return;
    }

    // CASE2: P is black(No problem->pass)
    if(P->color==BLACK)
        return;        

    G=C->parent->parent;

    if(G->data>P->data)
    {
        U=G->right;
        G_to_P=LEFT;
    }

    else if(G->data<P->data)
    {
        U=G->left;
        G_to_P=RIGHT;
    }

    // P_to_C
    if(P->data<C->data)
        P_to_C=RIGHT;

    else if(P->data>C->data)
        P_to_C=LEFT;

    // CASE3: Both P and U is red
    if(P->color==RED && U->color==RED)
    {
        P->color=BLACK;
        U->color=BLACK;
        G->color=RED;

        RBInsertFixup(pRBtree, G);
        return;
    }

    // CASE4: P is red but U is black
    //
    //     G                 G
    //    / \               / \
    //   P   U     or      U   P
    //    \                   /
    //     N                 N
                                   

   // CASE5: P is red but U is black
    
    //     G                 G
    //    / \               / \
    //   P   U     or      U   P
    //  /                       \
    // N                         N
                                   
    if(P->color==RED && U->color==BLACK)
    {
        // CASE 4 (to make CASE 5)
        if(G_to_P != P_to_C)
        {
            if(G_to_P==LEFT) // P_to_C==RIGHT
            {
                // left rotation on P
                G->left=left_rotation(P);
            }
            else if(G_to_P==RIGHT) // P_to_C==LEFT
            {
                // right rotation on P
                G->right=right_rotation(P);
            }
            SWAP(P, C, temp_node);
       }

        // CASE 5       
        attatch_to=G->parent;

        // P and G color change
        SWAP(G->color, P->color, temp);

        // rotation
        if(G_to_P==LEFT) // P_to_C==LEFT
        {
            // right rotation on G
            rotation_result=right_rotation(G);
        }

        else if(G_to_P==RIGHT) // P_to_C==RIGHT
        {
            // left rotation on G
            rotation_result=left_rotation(G);
        }

        // attach
        if(attatch_to==pNIL)
        {
            pRBtree->root=rotation_result;
            rotation_result->parent=pNIL;
        }

        else
        {
            if( (attatch_to->data)>(rotation_result->data) )
            {
                attatch_to->left=rotation_result;
                rotation_result->parent=attatch_to;
            }

            else
            {
                attatch_to->right=rotation_result;
                rotation_result->parent=attatch_to;
            }
        }
            
    }
    
}

void RB_insert(RBtree *pRBtree, int data)
{
    RBnode *newNode, *trav;

    newNode=createNode_and_init(data);

    if(pRBtree->root==pNIL)
    {
        pRBtree->root=newNode;

        // fix
        RBInsertFixup(pRBtree, newNode);

        return;
    }

    trav=pRBtree->root;
  
    while(1)
    {
        if(trav->data==data)
        {
            (trav->count)++;
            return;
        }

        else if(trav->data>data)
        {
            if(trav->left==pNIL)
            {
                trav->left=newNode;
                newNode->parent=trav;

                // fix
                RBInsertFixup(pRBtree, newNode);

                return;
            }
            trav=trav->left;
        }

        else if(trav->data<data)
        {            
            if(trav->right==pNIL)
            {
                trav->right=newNode;
                newNode->parent=trav;

                // fix
                RBInsertFixup(pRBtree, newNode);

                return;
            }
            trav=trav->right;
        }
    }
}

int how_many_keys(RBtree *RBtree, int key)
{
    int count=0;
    RBnode *pNode=RBtree->root;

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
    
    pNIL=(RBnode *)malloc(sizeof(RBnode));
    pNIL->color=BLACK;

    RBtree *cardNums;
    cardNums=createRBtree_and_init();
    
    // 1 <= numOfCards <= 500 000
    scanf("%d%*c", &numOfCards); 
   
    // -10 000 000 <= cardNums <= 10 000 000
    for(i=0; i<numOfCards; i++) 
    {
        scanf("%d%*c", &key);
        RB_insert(cardNums, key); 
    }
    
    // 1 <= numOfint <= 500 000
    scanf("%d%*c", &numOfint);
    intNums=(int *)malloc(sizeof(int)*numOfint);

    // -10 000 000 <= intNums <= 10 000 000
    for(i=0; i<numOfint; i++)
        scanf("%d%*c", &intNums[i]);
    
    for(i=0; i<numOfint; i++)
    {
        howManyExist=how_many_keys(cardNums, intNums[i]);
        printf("%d ", howManyExist);
    }
    return 0;
}