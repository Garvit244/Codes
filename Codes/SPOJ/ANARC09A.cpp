#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1) {
		string s;
		cin >> s;
		if(s[0] == '-')
			break;
		int testcasse = 1;
		int open=0, close=0;
		for(int i=0; i<s.length(); i++) {
			if(s[i] = '{')
				open++;
			else {
				open--;

				if(open < 0) {
					open = 1;
					close++;
				}
			}
		}
		cout << testcasse << ". " << close + open/2 << endl; 
		testcasse++;
	}
	return 0;
}