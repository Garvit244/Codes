#include <bits/stdc++.h>
using namespace std;

int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0);

	int N;	
	cin >> N; 

	int maxi = -1;
	int sum = 0;

	for(int i=1; i <= N; i++) {
		int x;
		cin >> x; 
		maxi = max(maxi,x);
		sum += x; 
	}		

	int sum -= 2*maxi; 
	int result = abs(sum) + 1; 
	cout << result << endl;

	return 0; 
}