octalN = list(map(int, list(input())))

# special case: 0
if (octalN[0] == 0):
	print(0)
	exit()

# oct -> bin
ret = ""
oct2bin = ['000', '001', '010', '011', '100', '101', '100', '111'] # 3의 배수 

for i in octalN:
	ret += oct2bin[i]

print(int(ret))