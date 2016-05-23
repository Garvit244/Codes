#include <bits/stdc++.h>
using namespace std;
# define MOD 1000000007

int main() {
	int T;
	cin >> T;

	while(T--) {
		string s;
		cin >> s;

		int S[100005]={0};
		S[0]=1;
		int dp[100005]={0};
		int last[50]={0};
		for(int i=1; i<=s.length(); i++) {
			dp[i] = (S[i-1] - S[last[s[i-1]-65] - 1] + MOD)%MOD;
			S[i] = (S[i-1] + dp[i])%MOD;
			last[s[i-1]-65] = i; 
			// cout << "i: " << S[i] << endl;
		}

		cout << S[s.length()] << endl;
	}

	return 0;
}

/**
	ABCB
	1 2 4 8
	8-2=6 
	S: 1 2
	DP: 0 1
**/