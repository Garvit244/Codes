#include <bits/stdc++.h>
using namespace std;

bool exist(int N, int size, int A[], int cows) {
	int cowCount = 1;
	int lastIndex = A[0];
	for(int i=1; i<size; i++) {
		if((A[i] - lastIndex) >= N) {
			cowCount++;
		if(cowCount == cows)
			return true;
		lastIndex = A[i];
		}
	}
	return false;
}

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N, C;
		cin >> N >> C;

		int A[N];
		for(int i=0; i<N; i++)
			cin >> A[i];

		sort(A, A+N);
		int start=0, end = A[N-1];

		while(start < end) {
			int mid = (start+end)/2;
			if(exist(mid, N, A, C))
				start = mid + 1;
			else
				end = mid;
		}

		cout << start-1 << endl;
	}

	return 0;
}

/*
	Cows: 3
	1 2 4 8 9
	s e m
	0 9 4
	0 4 2
	3 4 3
	4 4 4
	start = 0	end = 9     mid = 5 less than mid 

*/