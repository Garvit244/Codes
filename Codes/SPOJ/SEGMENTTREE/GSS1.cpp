#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 16;

struct segment_store {
	int sum;
	int maxv;
	int lsum;
	int rsum;
};

segment_store T[MAX<<1];
int A[MAX];

void build(int index, int start, int end) {
	if (start == end) {
		T[index].sum = T[index].maxv = T[index].lsum = T[index].rsum = A[start];
		return;
	}

	int mid = (start+end) >> 1, left = index << 1, right = left | 1;
	build(left, start, mid);
	build(right, mid+1, end);
	T[index].sum = T[left].sum + T[right].sum; 
	T[index].maxv = max(max(T[left].maxv, T[right].maxv), (T[left].rsum + T[right].lsum));
	T[index].lsum = max(T[left].lsum, T[left].sum + T[right].lsum);
	T[index].rsum = max(T[left].rsum + T[right].sum, T[right].rsum);
}

void query(segment_store &result, int index, int i, int j, int start, int end) {
	if(i == start && j == end) {
		result = T[index];
		return;
	}

	int mid = (i+j) >> 1, left = index << 1, right = left | 1;
	if(end <= mid)
		query(result, left, i, mid, start, end);
	else if(start > mid)
		query(result, right, mid + 1, j, start, end);
	else {
		segment_store LEFT, RIGHT;
		query(LEFT, left, i, mid, start, mid);
		query(RIGHT, right, mid+1, j, mid+1, end);

		result.maxv = max(max(LEFT.maxv, RIGHT.maxv), (LEFT.rsum +RIGHT.lsum));
		result.sum = LEFT.sum + RIGHT.sum;
		result.lsum = max(LEFT.lsum, LEFT.sum + RIGHT.lsum);
		result.rsum = max(RIGHT.rsum, LEFT.rsum + RIGHT.sum);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &A[i]);

	int M;
	scanf("%d", &M);
	build(1, 0, N-1);
	segment_store result;

	// for(int i=1; i<7; i++) {
	// 	cout << "Max: " << T[i].maxv << "Sum: " << T[i].sum << "Lsum: " << T[i].lsum << "Rsum: " << T[i].rsum << endl;
	// }
	while(M--) {
		int l, r;
		scanf("%d%d", &l, &r);
		query(result, 1, 0, N-1, --l, --r);
		printf("%d\n",result.maxv);
	}

	return 0;
}