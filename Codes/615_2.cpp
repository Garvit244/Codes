#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	int A[N];
	int count[1005]={0};
	for(int i=0; i<N; i++) {
		cin >> A[i];
		count[A[i]]++;
	}

	vector<int> result;
	for(int i=0; i<1005; i++)
		if(count[i] > 0)
			result.push_back(count[i]);

	int sum = 0;
	sort(result.begin(), result.end());
	
	for(int i=0; i < result.size()-1; i++){
		sum += min(result[i+1],result[i]);
	}

	cout << sum << endl;
	return 0;
}