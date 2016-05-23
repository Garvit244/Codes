#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int N, K;
	
	while(1) {
		cin >> N >> K;
		if(N == -1 && K == -1) break;
		if(K <= 2) cout << "0" << endl;
		else {
			long long int k, p , q;
			k = (K-1)/2;
			p = k*K - (k*(k+1));
	
			if(N & 1)
				q = ((N-1)/2) * N;
			else
				q = (N/2) * (N-1);

			while(1) {
				long long int res = __gcd(p,q);
				if(res == 1)
					break;
				p /= res;
				q /= res;

				if(p == 1 || q == 1) break;
			}
			if(q == 1) cout << p << endl;
			else cout << p <<"/" << q << endl;
		}
	}

	return 0;
}