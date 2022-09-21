#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 10 // 부등호 최대 나와봤자 9개, 그때에도 끝을 알려주기 위해 10은 반드시 0으로 비워둔다.

void print_increase(int start_point, int count);
void print_decrease(int start_point, int count);

int main(void)
{
    int i=0, j=0;
    char input_char;                            // < : 60, > : 62
    int input_int, print_int;
    int inequalityN, start_point;                      // 2 <= inequalityN <= 9
    char incre_decre_N[MAXNUM] = {0, };

    scanf("%d%*c", &inequalityN);             

    for(i = 0; i < inequalityN; i++) {
        scanf("%c%*c", &input_char);
        input_int = input_char - 61; // <:60-61 = -1, >:62-61 =+ 1

        if(incre_decre_N[j] * input_int >= 0) 
            incre_decre_N[j] += input_int;
    
        else 
            incre_decre_N[++j] += input_int;
    }

    if(incre_decre_N[0] > 0)
        incre_decre_N[0]++;
    else
        incre_decre_N[0]--;

    // 최댓값 구하기
    start_point=9-abs(incre_decre_N[0])+1;
    for(i=0; i <= j; i++) {
        if(incre_decre_N[i] < 0)
        {
            print_increase( start_point, abs(incre_decre_N[i]) );
            start_point -= abs(incre_decre_N[i])+1;
        }
        else
        {
            // start_point = 9, 3개 감소 목적, 여기서 2개 감소 -> 9 8
            print_decrease( start_point, abs(incre_decre_N[i])-1 );
            // 이후 3개 증가 -> print(4= start_point-abs(in_de[i])-abs(in_de[i+1])+1 ) 따라서 start_point: 4+1
            print_int = start_point-abs(incre_decre_N[i])-abs(incre_decre_N[i+1])+1;
            printf("%d", print_int);

            start_point = start_point - (abs(incre_decre_N[i])-1);
        }
    }

    printf("\n");

    //최솟값 구하기
    start_point=0;
    for(i=0; i <= j; i++) {
        if(incre_decre_N[i] < 0)
        {
            //printf("increase\n");
            // start_point = 0, 3개 증가 목적, 여기서 2개 증가 -> 0 1
            print_increase( start_point, abs(incre_decre_N[i])-1 );

            // 이후 3개 감소 -> print(5= start_point+abs(in_de[i])+abs(in_de[i+1])-1 ) 따라서 start_point: 5-1
            print_int = start_point+abs(incre_decre_N[i])+abs(incre_decre_N[i+1]) -1;
            printf("%d", print_int);
            start_point = print_int - 1;
        }
        else
        {
            //printf("decrease\n");
            print_decrease( start_point+abs(incre_decre_N[i])-1, abs(incre_decre_N[i]) );
            
            if(i == 0)
                start_point += abs(incre_decre_N[0]);
            else
                start_point += 2;
        }
        //printf("\nnow the start_point: %d\n", start_point);
    }
    return 0;
}

void print_increase(int start_point, int count)
{
    for(int i = start_point; i < start_point + count; i++) {
        printf("%d", i);
    }
}

void print_decrease(int start_point, int count)
{
    for(int i = start_point; i > start_point - count; i--) {
        printf("%d", i);
    }
}