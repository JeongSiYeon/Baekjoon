#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
int  pop     (Stack *pstack);
int  size    (Stack *pstack);
int  isEmpty (Stack *pstack);

int main(void)
{
    int i, j, T;

    scanf("%d%*c", &T);
    char *PS = (char *)calloc(T*51, sizeof(char));

    Stack judge_stack;

    int *result = (int *)calloc(T, sizeof(int));

    for(i = 0; i < T; i++)
    {
        // ith test case
        gets(&PS[i*51]);

        // Stack initialization
        init(&judge_stack);

        // VPS judgement
        for(j = i*51; j < i*51 + strlen(&PS[i*51]); j++)
        {
            if (PS[j] == '(')     
                push(&judge_stack, 1);

            else if(PS[j] == ')') 
                if(pop(&judge_stack) == -1)
                {
                    result[i] = -1;
                    break;
                }   
        }

        // If there are brackets left => 0, otherwise => 1
        if     (result[i] == 0 && size(&judge_stack) != 0) result[i] = -1;
        else if(result[i] == 0 && size(&judge_stack) == 0) result[i] =  1;
    }

    for(i = 0; i < T; i++)
    {
        if(result[i] == 1) printf("YES\n");
        else printf("NO\n");
    }
    
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

int pop    (Stack *pstack)
{
    int rData;
    Node *rNode;

    if(isEmpty(pstack))
        return -1;
    else
    {
        rData = pstack->head->data;
        rNode = pstack->head;

        pstack->head = pstack->head->next;
        free(rNode);

        return 1;
    }
}

int size    (Stack *pstack)
{
    int size = 0;
    Node *nptr = pstack->head;

    while(nptr != NULL)
    {
        size++;
        nptr = nptr->next;
    }

    return size;
}

int isEmpty(Stack *pstack)
{
    if(pstack->head == NULL)
        return 1;
    else
        return 0;
}