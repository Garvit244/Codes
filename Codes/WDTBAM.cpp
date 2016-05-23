#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;

	while(T--){
		int N;
		cin >> N;

		string s1, s2;
		cin >> s1;
		cin >> s2;

		long long int W[N+2];
		for(int i=0; i<=N; i++)
			cin >> W[i];

		int count = 0;
		for(int i=0; i<N; i++)
			if(s1[i] == s2[i])
				count++;

		if(count == N)
			cout << W[N] << endl;
		else{
			long long int maxi = W[0];
			for(int i=1; i<=count; i++){
				if(maxi < W[i])
					maxi = W[i];
			}
			cout << maxi << endl;
		}
	}
	return 0;
}