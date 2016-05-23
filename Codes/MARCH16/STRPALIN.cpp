#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string A, B;
		cin >> A >> B;
		int count[26] = {0};

		for(int i=0; i<A.length(); i++) {
			count[A[i]-97]++;
		}

		bool flag = false;
		for(int i=0; i<B.length(); i++) {
			if(count[B[i]-97]) {
				flag = true;
				break;
			}
		}
		if(flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}