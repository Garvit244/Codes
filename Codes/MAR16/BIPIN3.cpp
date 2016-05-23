#include <bits/stdc++.h>
using namespace std;
# define MOD 1000000007	

long long int foo(long long int x, long long int y) {
	long long int  result = 1;
    while(y) {
        if (y%2 == 1)
           result = ((result*x)%MOD);
        
        y /= 2;
        x = ((x*x)%MOD);
    }
    return result%MOD;
}

int main() {
	int T;
	cin >> T;

	while(T--) {
		long long int N, K;
		cin >> N >> K;

		long long int result = 1;
		result = foo(K-1, N-1);
		// cout << "result : " << result << endl;
		cout << ((K*result)%MOD) << endl;
	}
	return 0;
}