import sys
B1 = sys.stdin.readline()
B2 = sys.stdin.readline()

R = []
D1 = 0
D2 = 0

for i in range(len(B1)-1):
	D1 += (int(B1[i]) * (2 ** (len(B1) - 2 - i)))

for i in range(len(B2)-1):
	D2 += (int(B2[i]) * (2 ** (len(B2) - 2 - i)))

D = D1 * D2
while(D != 0):
	R.insert(0, D %2)
	D = D // 2

print(int(''.join(str(_) for _ in R)))