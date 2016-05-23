#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}


int main(){
	int T;
	cin >> T;

	while(T--){
		long long int N, H;
		scanf("%lld %lld", &N, &H);

		vector<long long>count(N);

		vector<long long>indexMarker(N+1);
		for(int i=0; i<=N; i++)
			indexMarker[i] = 0;

		for(int i=0; i< N; i++){
			int l, h;
			scanint(l);
			scanint(h);
			indexMarker[l]++;
			indexMarker[h+1]--;
		}		

		count[0] = indexMarker[0];
		for(int i=1; i<N; i++)
			count[i] = count[i-1]+indexMarker[i];

		long long int gapSum=0;
		for(int i=0; i<H; i++)
			gapSum += count[i];

		long long int result = gapSum;

		for(int i=H; i<N; i++){
			gapSum = gapSum - count[i-H] + count[i];
			if(gapSum > result)
				result = gapSum;
		}

		printf("%lld\n", (N*H) - result);
	}
	return 0;
}