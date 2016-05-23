#include <bits/stdc++.h>
using namespace std;
int H[100005], R[100005];
unsigned long long W, L;

bool checkCorrextMonth(unsigned long long x, int N) {
	unsigned long long int totalWoods=0;

	for(int i=0; i<N; i++) {
		unsigned long long currSum = H[i] + (R[i] * x);
		if(currSum >= L)
			totalWoods += currSum;
		if(totalWoods >= W)
			return true;
	}
	return false;
}

int main() {
	int N;
	cin >> N >> W >> L;

	for(int i=0; i<N; i++) 
		cin >> H[i] >> R[i];

	unsigned long long result=0;
	unsigned long long x=0, y=W;
	while(x <= y && x>=0 && y<= W) {
		unsigned long long mid = (x+y) >> 1;
		if(!checkCorrextMonth(mid, N)) 
			x = mid + 1;
		else {
			result = mid;
			y = mid-1; 
		}
	}
	cout << result << endl;
	return 0;
}