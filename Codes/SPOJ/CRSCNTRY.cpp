#include <bits/stdc++.h>
using namespace std;

int getLCS(int A[], int B[], int N, int M) {
	int L[N+1][M+1];

	for(int i=0; i<=N; i++)
		L[i][0] = 0;
	for(int j=0; j<=M; j++)
		L[0][j] = 0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(A[i-1] == B[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	// cout << "MAX " << L[N][M];
	return L[N][M];
}

int main() {
	int D;
	cin >> D;

	while(D--) {
		int A[2001]; int temp=1, i=0;
		int m = 0;
		while(temp) {
			cin >> temp;
			A[i++] = temp;
		}

		while(1) {
			int tom[2001]; int t =1;
			cin >> temp;
			if(temp == 0)
				break;
			else {
				tom[0] = temp;
				temp = 1;
				while(temp) {
					cin >> temp;
					tom[t++] = temp;
				}
			}

			m = max(m, getLCS(A, tom, i-1, t-1));
		}

		cout << m << endl;
	}

	return 0;
}