#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		unsigned long long int N, M;
		cin >> N >> M;
		if((M == 1) && (N >2)) 
			cout << "No" << endl;
		else if((M == 1) && (N ==1)) 
			cout << "No" << endl;
		else if((N ==1) && (M>2))
			cout << "No" << endl;
		else if((M%2) && (N%2))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}