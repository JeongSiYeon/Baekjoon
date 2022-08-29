#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define     TRUE     1
#define     FALSE    0

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

typedef struct _stack
{
    Node *head;
} Stack;

void init    (Stack *pstack);
void push    (Stack *pstack, int data);
void pop     (Stack *pstack);
void size    (Stack *pstack);
void isEmpty (Stack *pstack);
void top     (Stack *pstack);

void implement(char *command, Stack *pstack);


int main(void)
{
    int i, N;
    Stack stack;
    init(&stack);

    scanf("%d%*c", &N);  // 1 <= N <= 10 000
    char *command = (char *)calloc(12*N, sizeof(char));

    for(i = 0; i < N; i++)
        gets(&command[12*i]);    
 
    for(i = 0; i < N; i++)
        implement(&command[12*i], &stack);        

    return 0;
}

void init   (Stack *pstack)
{
    pstack->head =  NULL;
}

void push  (Stack *pstack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->head;

    pstack->head = newNode;
}

void pop    (Stack *pstack)
{
    int rData;
    Node *rNode;

    if(pstack->head == NULL)
        printf("-1\n");
    else
    {
        rData = pstack->head->data;
        rNode = pstack->head;

        pstack->head = pstack->head->next;
        free(rNode);

        printf("%d\n", rData);
    }
}

void size    (Stack *pstack)
{
    int size = 0;
    Node *nptr = pstack->head;

    while(nptr != NULL)
    {
        size++;
        nptr = nptr->next;
    }

    printf("%d\n", size);
}

void isEmpty(Stack *pstack)
{
    if(pstack->head == NULL)
        printf("1\n");
    else
        printf("0\n");
}

void top    (Stack *pstack)
{
    if(pstack->head == NULL)
        printf("-1\n");
    else
        printf("%d\n", pstack->head->data);
}

void implement(char *command, Stack *pstack)
{
    if(strstr(command, "push") != NULL)
        push( pstack, atoi(&command[5]) );
    
    else if(strstr(command, "pop") != NULL)
        pop(pstack);

    else if(strstr(command, "size") != NULL)
        size(pstack);
    
    else if(strstr(command, "empty") != NULL)
        isEmpty(pstack);

    else if(strstr(command, "top") != NULL)
        top(pstack);
}