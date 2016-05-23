#include <bits/stdc++.h>
using namespace std;
int A[100003]={0};

int main() {
	int N;
	cin >> N;

	int x;
	for(int i=0; i<N; i++) {
		cin >> x;
		A[x]++;
	}
	
	for(int i=0; i<=N; i++){
		if(A[i] == 0)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}