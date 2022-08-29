#include <stdio.h>
#include <stdlib.h>

typedef char Data;

typedef struct _node
{
    Data data;
    struct _node *next;
} Node;

typedef struct _liststack
{
    Node *head;
} Stack;

void stackInit(Stack *pstack);
int StackIsEmpty(Stack *pstack);
void push(Stack *pstack, Data data);
Data pop(Stack *pstack);
Data peek(Stack *pstack);

void bracket_1 (Stack *pstack, char input);
void alpha     (char input);
void sum_of_sub(Stack *pstack, char input);
void mul_or_div(Stack *pstack, char input);
void bracket_2 (Stack *pstack);

int main(void)
{
    char input, value;
    Stack operator;
    stackInit(&operator); 

    scanf("%c", &input);
    while(input != '\n')
    {
        if(65 <= input && input <= 90)
            alpha(input);

        else
        {
            if( (input != ')') && ((&operator)->head == NULL || peek(&operator) == '(' || input == '(') )
                push(&operator, input);

            else if(input == '*' || input == '/')
                mul_or_div(&operator, input);

            else if(input == '+' || input == '-')
                sum_of_sub(&operator, input);

            else if(input == ')')
                bracket_2(&operator); 
        }             
        scanf("%c", &input);
    }

    while(!StackIsEmpty(&operator))
        value = pop(&operator);

    return 0;
}

void alpha (char input)
{
    printf("%c", input);
}

void sum_of_sub(Stack *pstack, char input)
{
    char value; 

    // (prioity) peek(&operator) > input
    if(peek(pstack) == '*' || peek(pstack) == '/')
    {
        while(!StackIsEmpty(pstack))
        {
            if(peek(pstack) == '(')
                break;
            value = pop(pstack);
        }
    }

    // (prioity) peek(&operator) == input
    else
        value = pop(pstack); 
                
    push(pstack, input);
}

void mul_or_div(Stack *pstack, char input)
{
    char value; 

    // (prioity) peek(&operator) == input
    if(peek(pstack) == '*' || peek(pstack) == '/')
        value = pop(pstack);
                    
    push(pstack, input);
}

void bracket_2 (Stack *pstack)
{
    char value;

    while(peek(pstack) != '(')
        value = pop(pstack);
    value = pop(pstack);
}


void stackInit(Stack *pstack)
{
    pstack->head = NULL;
}

int StackIsEmpty(Stack *pstack)
{
    if(pstack->head == NULL)
        return 1;
    else
        return 0;
}

void push(Stack *pstack, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->head;
    pstack->head = newNode;
}

Data pop(Stack *pstack)
{
    Node *delNode;
    Data rdata;

    if(StackIsEmpty(pstack))
    {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    delNode = pstack->head;
    rdata = delNode->data;
    pstack->head = pstack->head->next;

    free(delNode);

    if(rdata != '(')
        printf("%c", rdata);

    return rdata;
}

Data peek(Stack *pstack)
{
    if(StackIsEmpty(pstack))
        return 0;
    else
        return pstack->head->data;
}