#include <bits/stdc++.h>
using namespace std;

int minVal(int x, int y) { return (x < y)? x: y; }

int RMQUtil(int *st, int ss, int se, int qs, int qe, int index) {
    if (qs <= ss && qe >= se)
        return st[index];
 
    if (se < qs || ss > qe)
        return INT_MAX;

    int mid = (ss+se)/ 2;
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
 
int RMQ(int *st, int n, int qs, int qe) {
    if (qs < 0 || qe > n-1 || qs > qe)
        return -1;
    
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int start, int end, int *st, int si) {
	if (start == end) {
        st[si] = arr[start];
        return arr[start];
    }
    int mid = (start+end)/2;
    st[si] =  minVal(constructSTUtil(arr, start, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, end, st, si*2+2));
    return st[si];
}

int *constructST(int arr[], int n) {
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
    int *st = new int[max_size]; 
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

int main() {
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;

	int A[N];
	for(int i=0; i<N; i++)
		cin >> A[i];

	int ans = 0;
	int *st = constructST(A, N);
	while(Q--) {
		int a, b, c ,d, k;
		cin >> a >> b >> c >> d >> k;

		// cout << "ans: " << ans << endl;
		int L = ((a * max(ans, 0) + b)%N) + 1;
		int R = ((c * max(ans, 0) + d)%N) + 1;

		if(L > R) {
			int temp = L;
			L = R;
			R = temp;
		}

		if(k == 1) {
			ans = RMQ(st, N, L-1, R-1);
			cout <<  ans << endl;
		} else {
			set<int> temp;
			set<int>::iterator it;

			// cout << "L: " << L << " R: " << R << endl;
			for(int i=L-1; i<R; i++) 
				temp.insert(A[i]);


			if(k > temp.size()) {
				ans = -1;
				cout << "-1" << endl;
			} else {
				int val;
				int count=0;
				// cout << "size: " << temp.size() << endl;
				for(it=temp.begin(); it!= temp.end(); ++it) {
					if(count == k)
						break;
					val = *it;
					count++;
					
				}
				ans = val;
				cout << ans << endl;
			} 
		}	
	}
	return 0;
}