#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int T;
	cin >> T;
	while(T--) {
		long long int balls[3];
		for(int i=0; i<3; i++)
			cin >> balls[i];
		long long int K;
		cin >> K;

		sort(balls, balls+3);
		if(K <= balls[0])
			cout << (K-1)*3+1 << endl;
		else if(K <= balls[1])
			cout << balls[0] + (K-1)*2+1 << endl;
		else
			cout << balls[0] + balls[1] + K << endl;
	}

	return 0;
} 