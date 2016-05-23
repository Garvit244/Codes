#include <bits/stdc++.h>
using namespace std;

int up[1000005];
int down[1000005];

int main() {
	int T;
	cin >> T;

	up[0] = 0;
	up[1] = 1;
	up[2] = 2;
	up[3] = 3;

	down[0] = 0;
	down[1] = 1;
	down[2] = 2;

	for(int i=4; i<=1000000; i++) {
		set<int> S;
		for(int j=i-1; j>=i-3; j--)
			S.insert(up[j]);

		int count = 0;
		while(true) {
			if(S.find(count) == S.end()) {
				up[i] = count;
				break;
			}
			else
				count++;
		}
	}

	for(int i=3; i<=1000000; i++) {
		set<int> S;
		for(int j=i-1; j>i-3; j--)
			S.insert(down[j]);

		int count = 0;
		while(true) {
			if(S.find(count) == S.end()) {
				down[i] = count;
				break;
			}
			else
				count++;
		}
	}

	while(T--) {
		int N, M;
		cin >> N >> M;
		int steps = up[N-1]^down[M-1];
		cout << steps << endl;
		if(!steps)
			cout << "Vanya" << endl;
		else
			cout << "Tuzik" << endl;
	}
	return 0;
}

/*
	up = 
	5 4
	4 1
	5 1
	5 3
	5 4

	2 2
	2 1
	2 2

	4 4
	4 1
	4 3
	4 4
*/