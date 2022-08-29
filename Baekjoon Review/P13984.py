# should complete a set of n problems
# can only hold keep the details from k problems
# t: the time will take to solve the ith problem

# strategy
# 1. read first k problems
# 2. choose a problem with the shortest time to solve
# 3. solve
# 4. still unsolved -> go to 2

# input
# n k (1 <= k <= n <= 300, integer)
n, k = map(int, input().split())
# t   (1 <= t <= 1,000,000, integer)

# output: the sum of submission times for all the problems, integer 
# 대충계산해도 최대가 30억 이상 int는 약 -21 ~ 21억 까지 가능-> python 사용

