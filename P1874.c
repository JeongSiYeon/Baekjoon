#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int  size    (Stack *pstack);
int  isEmpty (Stack *pstack);
int  top     (Stack *pstack);

int main(void)
{    
    int n, i = 0, j = 1, op = 0;
    Stack stack;
    init(&stack);
   
    scanf("%d%*c", &n); // 1 <= n <= 100 000

    int  *sequence  = (int *) calloc(n+1, sizeof(int));
    char *operation = (char *)calloc(n*2+1, sizeof(char));
    
    for(i = 0; i < n; i++)
        scanf("%d%*c", &sequence[i]);
    
    for(i = 0; i < n; i++)
    {
        while(sequence[i] > top(&stack))
        {
            push(&stack, j++);
            operation[op++] = '+';
        }

        if(sequence[i] == top(&stack))
        {
            pop(&stack);
            operation[op++] = '-';
        }
        
        else
        {
            printf("NO\n");
            return 0;
        }
    }

    for(i = 0; i < strlen(operation); i++)
        printf("%c\n", operation[i]);

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
    Node *rNode = pstack->head;
    pstack->head = pstack->head->next;
    free(rNode);
}

int isEmpty(Stack *pstack)
{
    if(pstack->head == NULL)
        return 1;
    else
        return 0;
}

int top    (Stack *pstack)
{
    if(isEmpty(pstack))
        return -1;
    else
        return pstack->head->data;
}