#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N, M, S;
		cin >> N >> M >> S;

		int strength[1006];
		for(int i=0; i<M; i++)
			cin >> strength[i];

		int dp[1004][1004]={0};
		int next = S + strength[0];
		int previous = S - strength[0];
		
		if(previous >=1)
			dp[previous][0] = 1;
		if(next <= N)
			dp[next][0] = 1;

		for(int i=1; i<M; i++) {
			for(int j=1; j<=N; j++) {
				if(dp[j][i-1] != 0) {
					int currentVal = dp[j][i-1]%MOD;
					next = j + strength[i];
					previous = j - strength[i];

					if(next <= N) 
						dp[next][i] = (dp[next][i] + currentVal)%MOD;

					if(previous >= 0) 
						dp[previous][i] = (dp[previous][i] + currentVal)%MOD;
				}
			}
		}

		for(int i=1; i<=N; i++) 
			cout << dp[i][M-1]%MOD << " ";
		
		cout << endl;
	}
	return 0;
}