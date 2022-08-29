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
RBnode NIL;//=(RBnode *)malloc(sizeof(RBnode));

void preOrder(RBnode *root)
{
    if(root==&NIL)
        return;
    
    printf("%d(%d) ",root->data, root->color);
    preOrder(root->left);
    preOrder(root->right);
}

RBnode *createNode_and_init(int data)
{
    RBnode *newNode;
    
    newNode=(RBnode *)malloc(sizeof(RBnode));
    newNode->data=data;
    newNode->count=0;
    newNode->color=RED;
    newNode->parent=&NIL;
    newNode->left=&NIL;
    newNode->right=&NIL;
    
    return newNode;
}

RBtree *createRBtree_and_init(void)
{
    RBtree *newRBtree;

    newRBtree=(RBtree *)malloc(sizeof(RBtree));
    newRBtree->root=&NIL;
     
    return newRBtree;
}

// Left-Rotation
RBnode *left_rotation(RBnode *target)
{
    // 언제 메모리를 할당해주어야 하고 언제는 안해도 되는거지?
    // 가리키기만할 때는 안해도 되고 멤버에 접근하거나 할때는 해야하나?
    RBnode *temp=&NIL;

    if(target->right->left != &NIL)
    {
        temp=target->right->left;
    }

    target->parent=target->right;
    target->right->left=target;
    target->right=&NIL;
    target->right=temp;

    return target->parent;
}


// Right-Rotation
RBnode *right_rotation(RBnode *target)
{
    RBnode *temp=(RBnode *)malloc(sizeof(RBnode));
    temp=&NIL;

    if(target->left->right != &NIL)
    {
        temp=target->left->right;
    }

    target->parent=target->left;
    target->left->right=target;
    target->left=&NIL;
    target->left=temp;

    return target->parent;
}

// RBinsertFixup
void RBInsertFixup(RBtree *pRBtree, RBnode *C)
{
    printf("fix [%d] start\n", C->data);

    int G_to_P, P_to_C, temp;
    RBnode *P, *U, *G, *attatch_to, *rotation_result, *temp_node;

    P=C->parent;
    if(P != &NIL)
        printf("parent: [%d]\n", P->data);
    
    // CASE1: root is red
    if(P==&NIL && C->color==RED)
    {
        printf("CASE 1: [%d] is now black\n", C->data);
        C->color=BLACK;
        return;
    }

    // CASE2: P is black(No problem->pass)
    if(P->color==BLACK)
    {
        printf("CASE 2\n");
        return;
    }
        

    G=C->parent->parent;
    printf("G: [%d]\n", G->data);

    if(G->data>P->data)
    {
        U=G->right;
        G_to_P=LEFT;
        if(U!= &NIL)
            printf("U: [%d]\n", U->data);
        printf("G_to_P: [LEFT]\n");
    }

    else if(G->data<P->data)
    {
        U=G->left;
        G_to_P=RIGHT;
        if(U!= &NIL)
            printf("U: [%d]\n", U->data);
        printf("G_to_P: [RIGHT]\n");
    }

    // P_to_C
    if(P->data<C->data)
    {
        P_to_C=RIGHT;
        printf("P_to_C: [RIGHT]\n");
    }

    else if(P->data>C->data)
    {
        P_to_C=LEFT;
        printf("P_to_C: [LEFT]\n");
    }

    // CASE3: Both P and U is red
    if(P->color==RED && U->color==RED)
    {
        printf("CASE 3\n");

        P->color=BLACK;
        U->color=BLACK;
        G->color=RED;

        printf("%d color: %d, %d color: %d, %d color: %d\n", P->data, P->color, U->data, U->color, G->data, G->color);

        RBInsertFixup(pRBtree, G);
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
            printf("case 4\n");
            if(G_to_P==LEFT) // P_to_C==RIGHT
            {
                // left rotation on P
                printf("left rotation on %d\n", P->data);
                G->left=left_rotation(P);
            }
            else if(G_to_P==RIGHT) // P_to_C==LEFT
            {
                // right rotation on P
                printf("right rotation on %d\n", P->data);
                G->right=right_rotation(P);
            }
            SWAP(P, C, temp_node);

            preOrder(pRBtree->root);  
            printf("\n");
       }

       

        // CASE 5
        printf("case 5\n");
       
        attatch_to=G->parent;

        printf("attatch to: %d\n", attatch_to->data);

        // P and G color change
        printf("color change before---G(%d): %d, P(%d): %d\n", G->data, G->color, P->data, P->color);
        SWAP(G->color, P->color, temp);
        printf("color change after---G(%d): %d, P(%d): %d\n", G->data, G->color, P->data, P->color);

        // rotation
        if(G_to_P==LEFT) // P_to_C==LEFT
        {
            // right rotation on G
            printf("RIGHT ROTATION on %d\n", G->data);
            rotation_result=right_rotation(G);
            printf("ratation result: %d\n", rotation_result->data);
        }

        else if(G_to_P==RIGHT) // P_to_C==RIGHT
        {
            // left rotation on G
            printf("LEFT ROTATION on %d\n", G->data);
            rotation_result=left_rotation(G);
            printf("ratation result: %d\n", rotation_result->data);
        }

        // attach
        if(attatch_to==&NIL)
        {
            printf("attatch to root\n");
            pRBtree->root=rotation_result;
            rotation_result->parent=&NIL;
        }

        else
        {
            if((G->data)<(G->parent->data))
            {
                printf("attatch to %d's left\n", attatch_to->data);
                attatch_to->left=rotation_result;
                rotation_result->parent=attatch_to;
            }

            else if((G->data)>(G->parent->data))
            {
                printf("attatch to %d's right\n", attatch_to->data);
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
    printf("INSERT: [%d]\n", data);

    if(pRBtree->root==&NIL)
    {
        pRBtree->root=newNode;

        // fix
        RBInsertFixup(pRBtree, newNode);

        return;
    }

    trav=pRBtree->root;
    printf("DATA: [%d]\n", data);
  
    while(1)
    {
        printf("LOC: [%d]\n", trav->data);
        if(trav->data==data)
        {
            (trav->count)++;
            return;
        }

        else if(trav->data>data)
        {
            printf("GO LEFT\n");

            if(trav->left==&NIL)
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
            printf("GO RIGHT\n");
            
            if(trav->right==&NIL)
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

    NIL.color=BLACK;

    RBtree *cardNums;
    cardNums=createRBtree_and_init();
    
    // 1 <= numOfCards <= 500 000
    scanf("%d%*c", &numOfCards); 
   
    // -10 000 000 <= cardNums <= 10 000 000
    for(i=0; i<numOfCards; i++) 
    {
        scanf("%d%*c", &key);
        RB_insert(cardNums, key); 
        preOrder(cardNums->root);  
        printf("\n"); 
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