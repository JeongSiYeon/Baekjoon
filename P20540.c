#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 0;
    char MBTI_I[8][5] = {"ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP"};
	char MBTI_E[8][5] = {"ENFP", "ENTP", "ESTP", "ESFP", "ENFJ", "ENTJ", "ESTJ", "ESFJ"};
    
    char Y_MBTI[5];
    scanf("%s", Y_MBTI);
    
    if(Y_MBTI[0] == 'E')
    {
        while(strcmp(Y_MBTI, MBTI_E[i]) != 0)
        {
            i++;
        }
        printf("%s", MBTI_I[i]);
    }

    else
    {
        while(strcmp(Y_MBTI, MBTI_I[i]) != 0)
        {
            i++;
        }
        printf("%s", MBTI_E[i]);
    }
    return 0;
}