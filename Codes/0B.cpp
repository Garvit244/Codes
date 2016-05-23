#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, D;
	cin >> N >> D;

	pair<long long int, long long int>A[N];
	long long int q, w;

	for(int i=0; i<N; i++){
		cin >> A[i].first >> A[i].second;
	}

	sort(A, A+N);
	long long int sum = A[0].second, maxSum = A[0].second, currSum=0, head = A[0].first;

	for(int i=1; i<N; i++){
		if((A[i].first -  A[i-1].first) < D){
			currSum = (A[i].first -  head);
			if(currSum < D)
				sum += A[i].second;
			else{
				sum = A[i].second;
				head = A[i].first;
			}
		}
		else{
			sum = A[i].second;
			head = A[i].first;
		}

		if(sum> maxSum)
			maxSum = sum;
	}

	cout << maxSum << endl;	
	return 0;
}