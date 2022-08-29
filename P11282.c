#include <stdio.h>
#include <locale.h>

int main(void)
{   
    
    int N, first_idx, second_idx, third_idx;
    scanf("%d%*c", &N);

    int character = 0xEAB080 + (N -1);

    setlocale(LC_ALL, "Korean"); // 가: 0xEAB080
    char str[] = {0xea, 0xb0, 0x80, 0};
    printf("%s", str);
   //  _westlocale(LC_ALL, L"Korean");

   // wchar_t unicodeStr[] = L"가";
   // wprintf(L"%X", unicodeStr);
    /*** 유니 코드를 통해 출력을 바로 하면 되겠다. 그러려면 utf-8을 이용해서 비트연산을 하자 ***/

    // 한글은 2 바이트 (short?) 
    // 문자열과 문자들 각각 저장은 다른것?
    // short first[60]  = {"ㄱㄲㄴㄷㄸㄹㅁㅂㅃㅅㅆㅇㅈㅉㅊㅋㅌㅍㅎ"};
    // char first[60] = "ㄱㄲㄴㄷㄸㄹㅁㅂㅃㅅㅆㅇㅈㅉㅊㅋㅌㅍㅎ";
    // printf("%c\n",first[0]);
    // short second[21][4] = {"ㅏㅐㅑㅒㅓㅔㅕ" "ㅖㅗㅘㅙㅚㅛㅜㅝㅞㅟㅠㅡㅢㅣ"};
    // char자료형만 인코딩을 자동으로 해주는 걸까?
    // char second[65]= "ㅏㅐㅑㅒㅓㅔㅕㅖㅗㅘㅙㅚㅛㅜㅝㅞㅟㅠㅡㅢㅣ";
    
    // 없음 주의
    // char third[85] = "   ㄱㄲㄳㄴㄵㄶㄷㄹㄺㄻㄼㄽㄾㄿㅀㅁㅂㅄㅅㅆㅇㅈㅊㅋㅌㅍㅎ";

    // 그냥 해당 인덱스만 뽑으면 안되는구나..
    
    /*
    first_idx  = 2 * (N / 588); 
    second_idx = 2 * ((N - 588 * first_idx) / 28); 
    third_idx  = 2 * (N - 588 * first_idx - 28 * second_idx);
    */
    // wchar_t wc = 0xAC00 + (N-1);
    // wprintf(L"UNICOE: %c\n", );
    // int result = 0xAC00 + (N-1);
    // printf("\uAC00");
    // , 0xAC00 + (N-1)

    // 한글은 한 글자가 3바이트이니끼 합치는게 좋겠다. 없음의 경우 주의해야 겠다. 그냥 공백으로 처리할까해
    // char result[7];
    // 배열 널로 초기화
    // for(int i = 0; i < 7; i++)
    //     result[i] = '\0';
    /*
    if(third_idx == 0)
    {
        strcpy(&result[0], &first[first_idx]);
        strcpy(&result[1], &second[second_idx]);
        printf("\nfirst_idx: %d / second_idx %d / third_idx: %d\n", first_idx, second_idx, third_idx);
        printf("%s\n", result);
    }
    else
    {
        strcpy(&result[0], &first[first_idx]);
        strcpy(&result[1], &second[second_idx]);
        strcpy(&result[2], &third[third_idx]);
        printf("\nfirst_idx: %d / second_idx %d / third_idx: %d\n", first_idx, second_idx, third_idx);
        printf("%s\n", result);
    }
    */
   
    
    
    
    return 0;
}