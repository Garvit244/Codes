#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

unsigned long long power(unsigned long long a,unsigned long long b)
{
	unsigned long long x=1,y=a;
	while(b>0)
	{
		if(b&1)
		{
			x=(x*y)%MOD;
		}
		y=(y*y)%MOD;
		b=b/2;
	}
	return x;
}

int main() {
	int T;
	scanf("%d", &T);

	while(T--) {
		unsigned long long int N, X, M, result=0;
		scanf("%llu %llu %llu", &N, &X, &M);
		unsigned long long int A[N], product[X], inv_MOD[X];

		for(int i=0; i<N; i++)
			scanf("%llu", &A[i]);

		product[0] = 1;
		inv_MOD[0] = 1;
		inv_MOD[1] = 1;

		for(int i=1; i<X; i++) {
			product[i] = ((product[i-1]%MOD) * ((M+i-1)%MOD)) %MOD;
			// cout << product[i] << endl;
		}

		for(int i=2; i<X; i++) {
			inv_MOD[i] = (inv_MOD[i-1]* power(i, MOD-2))%MOD;
			// cout << "inv " << inv_MOD[i] << endl;
		}
		for(int i=0; i<X; i++) {
			result =  (result + ((A[X-i-1]%MOD) * (((product[i]%MOD) * (inv_MOD[i]%MOD))%MOD)%MOD))%MOD;
			// cout << "result " << result << endl;
		}

		printf("%llu\n", result);
	}
	return 0;
}