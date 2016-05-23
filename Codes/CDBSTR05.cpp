#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T;
	cin >> T;

	while(T--){
		int N;
		cin >> N;

		long long int A[N];
		for(int i=0; i<N; i++)
			cin >> A[i];
		sort(A, A+N);

		long long int result = 0;
		for(int i=0; i<N; i++){
			result += (A[N-1-i]*(N-1-i) - A[N-1-i]*i);
		}
		cout << result << endl;
	}
	return 0;
}