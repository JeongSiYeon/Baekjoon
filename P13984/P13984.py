t = []
par_st = 0
tot_st = 0
minidx = 0
n, k = map(int, input().split())

for i in range(n):
	t.append(int(input()))

while(len(t) > 0):
	if(len(t) >= k):
		for i in range(k):
			min_value = min(t[0:k])
	else:
		for i in range(len(t)):
			min_value = min(t[0:len(t)])
	
	par_st = par_st + min_value
	tot_st = tot_st + par_st
	t.remove(min_value)
		
print(tot_st)