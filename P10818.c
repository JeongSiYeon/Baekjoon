// python 
// 정수 N입력
// N개의 정수를 공백으로 구분해서 주어짐
// 모든 정수는 -1,000,000 보다 크거나 같고 1,000,000보다 작거나 같은 정수이다.

N = int(input());
num = list(map(int, input().split()))
maxN = num[0]
minN = num[0]
for i in num:
    if(minN > i)
     minN = i
    if(maxN < i)
      maxN = i


