cost = []
digitN = []
N = int(input())

for i in range(N):
	cost.append(int(input()))
	j = 1
	while(cost[i] // (10**j) >= 1):
		j = j + 1
	digitN.append(j)
for i in range(N):
	print(digitN[i])

