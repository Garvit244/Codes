#include <bits/stdc++.h>
using namespace std;

int dp[2023][2023];

int main() {
	string A, B;
	cin >> A >> B;

	int K;
	cin >> K;
	for(int i=0; i<=A.length(); i++)
		dp[i][0] = K*i;

	for(int j=0; j<=B.length(); j++)
		dp[0][j] = K*j;

	for(int i=1; i<=A.length(); i++)
		for(int j=1; j<=B.length(); j++)
			dp[i][j] = min((dp[i-1][j-1]+ (int)abs((double)(A[i - 1] - B[j - 1]))), min(dp[i-1][j], dp[i][j-1]+K));

	cout << dp[A.length()][B.length()] << endl;
	return 0;
}