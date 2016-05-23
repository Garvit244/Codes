#include <iostream>
// #include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;

		int A[N];
		for(int i=0; i<N; i++)
			cin >> A[i];

		int result = 1;
		int maxTillNow = A[0];
		for(int i=1; i<N; i++){
			if(A[i] < maxTillNow){
				result++;
				maxTillNow= A[i];
			}
		}
		cout << result << endl;
	}

	return 0;
}