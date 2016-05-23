#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	while(1) {
		cin >> s;
		if(s[0] == '0')
			break;

		int dp[5002] ={0};
		dp[0] = 1;

		for(int i=1; i<s.length(); i++) {
			if(s[i] - '0')
				dp[i] = dp[i-1];
			int temp = (s[i-1]-'0')*10 + (s[i] - '0');
			if(temp > 9 && temp <=26)
				if((i-2) > 0)
					dp[i] += dp[i-2]; 
				else
					dp[i]++;
		}

		cout << dp[s.length() -1] << endl;
	}
	return 0;
}