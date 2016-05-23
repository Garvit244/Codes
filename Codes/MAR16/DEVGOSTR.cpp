#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int K, A;
		cin >> A >> K;

		string s;
		cin >> s;

		if(A == 1) {
			if(s.length() >= 3)
				cout << "0" << endl;
			else {
				int count = 0;
				for(int i=0; i<s.length(); i++)
					if(s[i] != 'a')
						count++;
				if(count <= K)
					cout << "1" << endl;
				else
					cout << "0" << endl;
			}
		}
	}
	return 0;
}