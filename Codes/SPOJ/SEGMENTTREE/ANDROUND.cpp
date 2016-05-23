#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 15;

int A[MAX];
int T[MAX << 1];

void build(int index, int start, int end) {
	if (start == end) {
		T[index] = A[start];
		return; 
	}

	int mid = (start+end) >> 1, left = index << 1, right = left | 1;
	build(left, start, mid);
	build(right, mid+1, end);
	T[index] = T[left] & T[right];
}

int query(int index, int i, int j, int start, int end) {
	if(i == start && j == end)
		return T[index];
	int mid = (i+j) >> 1, left = index << 1, right = left | 1;

	if(end <= mid)
		return query(left, i, mid, start, end);
	else if(start > mid)
		return query(right, mid+1, j, start, end);
	else
		return query(left, i, mid, start, mid) & query(right, mid+1, j , mid+1, end); 
}

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N, K;
		cin >> N >> K;
		K = min(K, N-1);
		for(int i=0; i<N; i++)
			cin >> A[i];
		build(1, 0, N-1);

		for(int i=0; i<N; i++) {
			int start = (i-K+N) %N;
			int end = (i+K)%N;

			int result=-1;
			if(start < i)
				result &= query(1, 0, N-1, start, i);
			else
				result &= query(1, 0, N-1, 0, i) & query(1, 0, N-1, start, N-1);
			if(end > i) 
				result &= query(1, 0, N-1, i, end);
			else 
				result &= query(1, 0, N-1, i, N-1) & query(1, 0, N-1, 0, end);

			if(i) 
				printf(" "); 
			printf("%d", result);
		}
		cout << endl;
	}

	return 0;
}