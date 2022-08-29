#include <stdio.h>
#include <stdlib.h>

// SWAP(list[i], list[j], temp)
// temp=list[i], list[i]=list[j], list[j]=temp
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))


// 정렬 대상인 list에 대하여 첫 번째 원소를 pivot으로 설정하고 이를 기준으로 pivot보다 작은 수들은 왼쪽에 있도록, pivot보다 큰 숫자들은 오른쪽에 있도록 pivot의 위치를 결정한다. 
int partition(int *list, int left, int right)
{

}


// low high 뭐 조건걸었을 때 정렬 대상 배열의 원소의 개수가 1이면    low는 오른쪽으로 튀어 나가고 high는 그자리를 지키므로 당연히 교차가 발생한다.
// 모든 경우들을 일일히 다 표현해줄 수 있겠지만 효율적으로 그런 모든 것들을 고려하였을 때 low>high로 표현된다.


// 정렬 대상인 list에 대해 partition함수에서 pivot의 위치를 반환받고 이를 기준으로 왼쪽 정렬대상 하나, 오른쪽 정렬 대상 하나 이렇게 2개의 정렬 대상을 만든다.
// 그리곤 2개의 정렬 대상에 대해서도 다시 pivot을 설정하고 2개의 정렬 대상으로 나눌 수 있도록 한다. (동일한 과정을 반복하는 것이기 때문에 재귀함수를 쓴다.)
// 재귀함수에서 제일 중요한 것은  

void quick_sort(int *list, int left, int right)
{
    // 왜 등호가 들어갈까? 처음에 들어갈 때, left와 right의 관계는 두 가지야: left==right or left<right
    // quick_sort를 한 번 거치고 나서 left와 right의 관계는 left는 1일건데 picotIDX-1은 몇이 나올 수 있을까? pivotIDX가 0이라면 -1, 1이라면 0이겠지? 2라면 1일거고
    // 그러면 먼저 -1이 나오는 경우를 생각해보자. pivot이 0인 경우야. 이 경우는 high가 0이었다는 것을 의미해. left는 당근 0이었을텐데 그치?
    // 근데 또 진짜 0인지느 모르지 근데 일단 기준을 0이라고 두자(이따가 다른 숫자로 바꾸 생각해도 결과는 동일할테지만)
    // 분명 right는 pivot이 아니니, pivot 뒤에 있었다가 글루

    // quick_sort(list, left, pivotIDX-1)
    // quick_sort(list, pivot+1, right)
    // 
    // 일단 언제까지 quick_sort에 집어 넣어야 할까?
    // """왼쪽이든, 오른쪽이든 정렬할 대상이 남아있을 때"""는 넣어야겠지
    // 정렬할 대상이 남아있다는 것은 무엇을 의미하지?
    // 원소가 하나 이상이라는 것을 의미하지
    // 아니 근데 피벗은 거기 위치가 올바르다는 것을 입증한건데 _ pivot _ 이면 그냥 여기는 정렬 끝난거잖아
    // 정렬이 언제 끝나지?
    // 

    // left: list의 가장 왼쪽
    // r
    
    if(left<=right)
    {
        // Divide
        int pivotIDX=partition(list, 0, );

        // Conquer
        quick_sort(list, left, pivotIDX-1);
        quick_sort(list, pivotIDX+1, right);
    }
}

int main(void)
{

    return 0;
}