#include <stdio.h>
#include <malloc.h>

typedef Data int;

typedef struct _node
{
    Data data;
    struct _node *link;
} Node;

struct Stack
{
    Node *head;
};

void StackInit(Stack *pstack);
void push(Stack *pstack, Data data);
Data pop(Stack *pstack);
int IsStackEmpty(STack *Pstack);
Data peek(Stack *pstack);

int main(void)
{
    Stack string;
    StackInit(&string);

    char input;
    scanf("%c", &input);

    while(input != '\n')
    {
        push(&string, input);
        scanf("%c", &input);
    }
    
    // sorting: insertion sort를 하면 시간 복잡도에서 걸리고
    // 자료구조를 사용하자면 일반적으로 stack

    // input은 string으로 받아야 해 -> 그래야 주소값을 control해서 널값 전까지 뽑을 수 있어
    // 정렬한 결과를 stack에 저장해야 하나?

    // 뭐든 나보다 작은 것의 개수를 세기만 하면 돼
    

    /*
    n
    o
    o
    j
    k
    e
    a
    b
    */


    
    
    return 0;
}

void StackInit(Stack *pstack)
{
    pstack->head = NULL;
}

void push(Stack *pstack, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = pstack->head;
    pstack->head = newNode;
}

Data pop(Stack *pstack)
{
    Node *delNode;
    Data delData;

    if(IsStackEmpty(pstack))
    {
        printf("Stack Memory Error!\n");
        exit(-1);
    }
    
    delNode =  pstack->head;
    delData = delNode->Data;

    pstack->head = pstack->head->link;
    free(delNode);

    return delData;
}

int IsStackEmpty(STack *pstack)
{
    if(pstack->head == NULL)
        return 1;
    else
        return 0;
}

Data peek(Stack *pstack)
{
    return pstack->head->data;
}