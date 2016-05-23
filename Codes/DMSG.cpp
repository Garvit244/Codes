#include <bits/stdc++.h>
using namespace std;

int main() {
	int count[26] = {0};
	string s;
	cin >> s;

	for(int i=0; i<s.size(); i++)
		count[s[i]-97]++;

	if(count[11] && count[8] && count[4] && count[14] >=2 && count[21] && count[20] && count[24])
		cout << "happy" << endl;
	else
		cout << "sad" << endl;

	return 0;
}

