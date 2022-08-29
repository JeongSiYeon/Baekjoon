#include <stdio.h>
#include <malloc.h>

#define BEF_PUSH 0
#define BEF_POP  1

typedef struct _node
{
    int data;
    struct _node* next;
} Node;

typedef struct _listStack
{
    Node *top;
    int size;
} Stack;

void StackInit(Stack *pstack);
int StackIsEmpty(Stack *pstack);

void push(Stack *pstack, int data);
int pop(Stack *pstack);

int size(Stack *pstack);
int Speek(Stack *pstack);


int main(void)
{
    // sol
    // () 등장 여부 먼저 처리, 잘린 쇠덩어리 개수 += 현재 쇠막대기 개수
    // '('이 등장하면 쇠막대기 개수++, ')'가 나오면 쇠막대기 개수--, 잘린 쇠덩어리 개수++

    // 레이저 인식처리, 막대기 시작과 끝 처리 등 과정이 끝나면 바로 처리해주는 것이 유리하므로
    // 스택 사용
    char data;
    int pieceN = 0, state = 0;

    Stack layout;
    StackInit(&layout);

    scanf("%c", &data);

    while(data != '\n')
    {
        if(data == ')' && state == BEF_PUSH)
        {
            pop(&layout);
            pieceN += size(&layout);
            state = BEF_POP;
        }

        else if(data == ')' && state == BEF_POP)
        {
            pop(&layout);
            pieceN ++;
        }
        
        else 
        {
            push(&layout, data);
            state = BEF_PUSH;
        }

        scanf("%c", &data);
    }

    printf("%d\n", pieceN);
    return 0;
}

void StackInit(Stack *pstack)
{
    pstack->top = NULL;
    pstack->size = 0;
}

int StackIsEmpty(Stack *pstack)
{
    if(pstack->top == NULL)
        return 1;
    else
        return 0;
}

void push(Stack *pstack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->top;
    pstack->top = newNode;

    (pstack->size)++;
}

int pop(Stack *pstack)
{
    if(StackIsEmpty(pstack))
    {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    Node *delNode = pstack->top;
    int rdata = delNode->data;

    pstack->top = pstack->top->next;
    free(delNode);

    (pstack->size)--;
    return rdata;
}

int size(Stack *pstack)
{
    return pstack->size;
}

int Speek(Stack *pstack)
{
    if(StackIsEmpty(pstack))
    {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    return pstack->top->data;
}