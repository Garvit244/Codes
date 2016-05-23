#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--) {
		int N;
		cin >> N;
		string s;
		cin >> s;

		int red=0, green=0, blue=0;
		for(int i=0; i<N; i++) {
			if(s[i] == 'R')
				red++;
			else if(s[i] == 'G')
				green++;
			else
				blue++;
		}

		cout << N - max(red, max(green, blue)) << endl;
	}
	return 0;
}