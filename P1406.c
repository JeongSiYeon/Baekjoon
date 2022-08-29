#include <stdio.h>
#include <stdlib.h>

// 한 줄로 된 간단한 에디터 구현하기
// 영어 소문자만 기록 가능
// 최대 600 000자
// 커서: 문장의 맨 앞(첫 번째 문자의 왼쪽)
//       문장의 맨 뒤(마지막 문자의 오른쪽)
//       문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치
// 명령어
// L: 커서를 완쪽으로 한 칸 옮김(커서가 문장의 맨 앞이면 무시)
// D: 커서를 오른쪽으로 한 칸 옮김(커서가 문장의 맨 뒤이면 무시)
// B: 커서 왼쪽에 있는 문자 삭제(커서가 맨 앞이면 무시) 삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로
// P $: $라는 문자를 커서 왼쪽에 추가

// 초기에 편집기에 입력되어 있는 문자열이 주어지고
// 그 이후 입력한 명령어가 차례로 주어졌을 때, 모든 명령어를 수행하고 난 후
// 편집기에 입력되어 있는 문자열을 구한다.
// 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다.


int main(void)
{
    int i, M;
    char *string = (char *)calloc(100001, sizeof(char));
    
    // string input
    gets(string);

    // commandN: M (1 <= M <= 500 000)
    scanf("%d%*c", M); 
    char *command = (char *)calloc(M*4, sizeof(char));

    // command input
    for(i = 0; i < M; i++)
        gets(&command[i*4]);

    // command implement
    for(i = 0; i < M; i++)
        implement(&command[i*4]);
    
    // print string


    return 0;
}