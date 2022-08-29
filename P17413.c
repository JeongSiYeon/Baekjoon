#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node
{
    char data;
    struct _node* next;
} Node;

typedef struct _listStack
{
    Node *top;
} Stack;

void StackInit(Stack *pstack);
int StackIsEmpty(Stack *pstack);

void push(Stack *pstack, char data);
int pop(Stack *pstack);


int main(void)
{
    int i;
    char ch;
    
    Stack word_stack;
    StackInit(&word_stack);

    // input string
    scanf("%c", &ch);
    while(ch != '\n')
    {
        if(ch == '<')
        {
            while(!StackIsEmpty(&word_stack))
            {
                printf("%c", pop(&word_stack));
            }

            while(ch != '>')
            {
                printf("%c", ch);
                scanf("%c", &ch);
            }
            printf("%c", ch);
        }

        else if(ch == ' ')
        {
            while(!StackIsEmpty(&word_stack))
            {
                printf("%c", pop(&word_stack));
            }
            printf(" ");
        }

        else
        {
            push(&word_stack, ch);
        }

        scanf("%c", &ch);
    }

    while(!StackIsEmpty(&word_stack))
    {
        printf("%c", pop(&word_stack));
    }

    return 0;
}


void StackInit(Stack *pstack)
{
    pstack->top = NULL;
}

int StackIsEmpty(Stack *pstack)
{
    if(pstack->top == NULL)
        return 1;
    else
        return 0;
}

void push(Stack *pstack, char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->top;
    pstack->top = newNode;
}

int pop(Stack *pstack)
{
    if(StackIsEmpty(pstack))
    {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    Node *delNode = pstack->top;
    char rdata = delNode->data;

    pstack->top = pstack->top->next;
    free(delNode);

    return rdata;
}