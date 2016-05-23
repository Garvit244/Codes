#include <bits/stdc++.h>
using namespace std;
map<int, long long int> dp;

long long int coins(int n) {
	if(n == 0)
		return 0;
	if(dp[n] != 0) 
		return dp[n];
	long long int di = coins(n/2) + coins(n/3) + coins(n/4);
	if(di > n)
		dp[n] = di;
	else
		dp[n] = n;

	return dp[n];
}

int main() {
	int n;

	while(scanf("%d", &n) == 1) {
		cout << coins(n) << endl;
	}
	return 0;
}