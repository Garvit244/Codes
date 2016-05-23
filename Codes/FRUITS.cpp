#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--) {
		int N, M, K;
		cin >> N>> M >> K;
		int temp = abs(N-M);
		if(temp >K)
			cout << temp-K << endl;
		else
			cout << "0" << endl;
	}
	return 0;
}