#include <bits/stdc++.h>
using namespace std;

long long int findmax(int l, int r, long long int A[], long long int B[]) {
	long long int suma =0, sumb =0;
	for(int i=l; i<=r; i++) {
		suma = suma|A[i];
		sumb = sumb|B[i];
	}
	return sumb+suma;
}

int main() {
	int N;
	cin >> N;
	long long int A[N], B[N];
	long long int suma=0, sumb=0;

	for(int i=0; i<N; i++) {
		cin >> A[i];
		suma = suma|A[i];
	}

	for(int i=0; i<N; i++) {
		cin >> B[i];
		sumb = sumb|B[i];
	}

	long long int result = suma + sumb;

	cout << result << endl;
	return 0;
}