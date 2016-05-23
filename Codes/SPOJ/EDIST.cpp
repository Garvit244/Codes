#include <bits/stdc++.h>
using namespace std;

int editDistance(string A, string B, int N, int M) {
	int dp[N+1][M+1];

	for(int i=0; i<=N; i++) {
		for(int j=0; j<=M; j++) {
			if(i == 0)
				dp[i][j] = j;
			else if(j == 0)
				dp[i][j] = i;
			else if(A[i-1] == B[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
		}
	}
	return dp[N][M];
}

int main() {
	int T;
	cin >> T;

	while(T--) {
		string a, b;
		cin >> a >> b;

		cout << editDistance(a, b, a.length(), b.length()) << endl;
	}
	return 0;
}