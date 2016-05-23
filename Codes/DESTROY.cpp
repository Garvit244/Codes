#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N;
		cin >> N;

		long long int A[N];
		for(int i=0; i<N; i++){
			cin >> A[i];
		}
		sort(A, A+N);

		long long int count=0;
		for(int i=0; i<N/2; i++) {
			if(A[i] == A[N-i-1]) {
				count+=2;
			} else
				count++;
		}

		if(N%2 != 0) {
			count++;
		}

		cout << count << endl;
	}
	return 0;
}

/*
	1 1 2 3
	1 2 3
	1 1 1
	1 1 2 2 3 3 32 31 21
	1 1 1 2 2 2 3 3 3
*/