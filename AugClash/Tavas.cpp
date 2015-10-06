#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, K;
	cin >> N >> K;

	int A[N+1];
	memset(A, 0, sizeof(A));
	for(int i=2; i<=N; i++)
		if(!A[i])
			for(int j=i; j<=N; j+=i)
				A[j] +=i;

	int result = 0;
	for(int i=2; i<=N; i++)
		if(A[i] == K)
			result++;

	cout << result << endl;
	return 0;
}