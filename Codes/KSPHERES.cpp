#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long int sequenceWitheachIndex[1005][1005]={0};
long long int countWithIndex[1005][1005] = {0};

int main(){
	int N, M, C;
	cin >> N >> M >> C;

	long long int U[1005]={0}, L[1005]={0};
	int maxi = -1, x;
	for(int i=0; i<N; i++){
		cin >> x;
		maxi = max(maxi, x);
		U[x]++;
	}
	for(int i=0; i<M; i++){
		cin >> x;
		maxi = max(maxi, x);
		L[x]++;
	}

	int sequence = min(min(N, M), C);
	long long int result[1005]={0};
	for(int i=1; i<= maxi; i++){
		if((U[i] != 0) && (L[i] != 0))
			sequenceWitheachIndex[1][i] = (U[i]*L[i])%MOD;

		countWithIndex[1][i] = sequenceWitheachIndex[1][i];

		countWithIndex[1][i] += countWithIndex[1][i-1];
		if(countWithIndex[1][i] > MOD)
			countWithIndex[1][i] %=MOD;
	}

	// for(int i=1; i<=maxi; i++)
	// 	cout << sequenceWitheachIndex[1][i] << " ";
	// cout << endl;

	// for(int i=1; i<=maxi; i++)
	// 	cout << countWithIndex[1][i] << " ";
	// cout << endl;


	for(int i=2; i<=sequence; i++){
		long long int count = 0;
		for(int j=i; j<=maxi; j++){
			long long int currCount = countWithIndex[i-1][j-1];
			sequenceWitheachIndex[i][j] = sequenceWitheachIndex[1][j] *currCount;
			if(sequenceWitheachIndex[i][j] > MOD)
				sequenceWitheachIndex[i][j] %= MOD;

			count += sequenceWitheachIndex[i][j];
			if(count > MOD)
				count %= MOD;
			countWithIndex[i][j] = sequenceWitheachIndex[i][j]+countWithIndex[i][j-1];
			if(countWithIndex[i][j] > MOD)
				countWithIndex[i][j]%= MOD;

			// cout << "count" << count << endl;
		}
		result[i] = count;
	}

	int i;
	for(i=1; i<=C; i++){
		if((i+1) > sequence)
			break;
		cout << result[i+1] << " ";
	}

	while(i<=C){
		cout << "0 ";
		i++;
	}
	cout << endl;
	return 0;
}