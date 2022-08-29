#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(void)
{
    int i = 0, wordN = 1;

    // input
    char *string = (char *)malloc(sizeof(char)*1000001);
    char *temp = (char *)malloc(sizeof(char)*1000001);
    gets(temp);

    // "string" starts with no whitespace 
    while(temp[i] == ' ') i++;
    strcpy(string, &temp[i]);

    i = 0;

    /* special case: wordN == 0 => jump*/
    /* general case: wordN  > 0 => in  */ 
    while(string[i] != '\0')
        if(string[i++] == ' ') wordN++;

    printf("%d\n", i ? (string[i-1] == ' ' ? wordN-1: wordN) : 0);
    /* general case */ 
    // 단어 개수: 1
    // (1) 공백+단어+공백+널 ----
    // (2) 공백+단어+널 ---------
    // (3) 단어+공백+널
    // (4) 단어+널

    // 단어 개수: 2
    // (1) 공백+단어+공백+단어+공백+널 ----
    // (2) 공백+단어+공백+단어+널   ------
    // (3) 단어+공백+단어+공백+널
    // (4) 단어+공백+단어+널

    // 단어 개수: 3개 이상
    // (1) 공백+단어+공백+단어+공백+단어+공백+널 ----
    // (2) 공백+단어+공백+단어+공백+단어+널 ----------
    // (3) 단어+공백+단어+공백+단어+공백+널
    // (4) 단어+공백+단어+공백+단어+널


    return 0;
}