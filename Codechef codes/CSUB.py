T = int(raw_input())
while(T>0):
	N = int(raw_input())
	S = str(raw_input())
	count = 0

	for i in range(len(S)):
		if S[i] == '1':
			count = count+1

	print (count*(count+1))/2
	T = T-1
