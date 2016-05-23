#include <bits/stdc++.h>
using namespace std;

int main() {

	while(true) {
		int L, N;
		cin >> L >> N;

		if(L == -1)
			break;

		int A[100003];
		string s;
		for(int i=0; i<N; i++) {
			cin >> s;
			A[i] = s.length() + 1;
		}

		// cout <<	 "asasa" << endl;
		int lo=0, hi = 26*N;
		L = min(L, N);

		while(lo != hi) {
			int mid = (lo + hi) >> 1;

			int noWords = 0;
			for(int i=0; i<L && noWords < N; i++) {
				int sumYet = 0;	

				while(noWords < N && ((sumYet+A[noWords]) <= mid)) {
					sumYet += A[noWords];
					++noWords;
				}	
			}

			// cout << "lo " << lo << endl;
			if(noWords < N)
				lo = mid+1;
			else
				hi = mid;
		}

		cout << lo-1 << endl;	
	}

	return 0;
}