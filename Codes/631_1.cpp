#include <bits/stdc++.h>
using namespace std;

/**
	3 1 0 
	2 0 0
	0 0 0
	1 3
	2 1
	2 2
**/
int result[5001][5001];
pair<int, int> row[5001];
pair<int, int> column[5001];

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	for(int i=0; i<K; i++) {
		long long int cas, r, a;
		cin >> cas >> r >> a;
		if(cas == 1) 
			row[r] = make_pair(i+1, a);
		else 
			column[r] = make_pair(i+1, a);
	}

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(row[i].first > column[j].first)
				result[i][j] = row[i].second;
			else
				result[i][j] = column[j].second;
		}
	}

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) 
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}	