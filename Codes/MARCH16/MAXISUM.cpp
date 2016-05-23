#include <bits/stdc++.h>
using namespace std;

/**
	1 2 -3
	-2 3-5
		-2+6+15=19

	-1 3
	2 1
	-2+20=18
	2+9
**/

int main() {
	int T;
	cin >> T;

	while(T--) {
		long long int N, K;
		cin >> N >> K;

		long long int A[N], B[N];
		for(int i=0 ;i<N; i++)
			cin >> A[i];
		for(int i=0; i<N; i++)
			cin >> B[i];

		long long int max = -1, index;
		for(int i=0; i<N; i++) {
			long long int temp = B[i];

			if(temp <=0 && (temp*(-1)) > max) {
				max = temp*(-1);
				index = i;
			} else if(temp > 0) {
				if(temp > max) {
					max = temp;
					index = i;
				}
			}
		}

		long long int Al = A[index];
		long long int Bl = B[index];

		// cout << "Al " << Al << " Bl " << Bl << endl;
		if(Al >= 0 && Bl >= 0)
			A[index] += K;
		else if(Al <=0 && Bl <= 0)
			A[index] -= K;
		else if(Al < 0 && Bl > 0)
			A[index] +=K;
		else if(Al>0 && Bl<0)
			A[index] -= K;

		long long int result = 0;
		for(int i=0; i<N; i++)
			result += (A[i]*B[i]);

		cout << result << endl;
	}
	return 0;
}