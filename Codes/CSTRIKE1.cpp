#include <iostream>
using namespace std;

bool isSubset(int A[], int N, int sum){
	cout << "a: " << A[0] << endl;
	if(sum == 0)
		return true;
	if (N == 0 && sum != 0)
 	    return false;
 	if(A[N-1] > sum)
 		return isSubset(A, N-1, sum);

 	return isSubset(A, N-1, sum) || isSubset(A, N-1, sum-A[N-1]);
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, sum = 0;
		cin >> N;

		int A[N];
		for(int i=0; i<N; i++){
			cin >> A[i];
			sum += A[i];
		}

		if(sum%2 != 0)
			cout << "NO" << endl;
		else{
			bool val = isSubset;
			cout << val << endl;
			if(val){
				cout << "YES" << endl;
			}
			else{
				cout << "Odd NO" << endl;
			}
		}
	}
	return 0;
}