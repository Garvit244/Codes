#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;

	while(T--){
		int N;
		cin >> N;

		int A[N];
		int min =INT_MAX;
		for(int i=0; i<N; i++){
			cin >> A[i];	
			if(A[i] < min)
				min = A[i];
		}

		cout << min*(1LL)*(N-1) << endl;
	}
	return 0;
}