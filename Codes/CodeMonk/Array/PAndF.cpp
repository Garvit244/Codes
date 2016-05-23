#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;

	while(T--){
		int N, cost;
		cin >> N >> cost;

		long long int A[N];
		for(int i=0; i<N; i++)
			cin >> A[i];

		bool flag = false;
		int prev = 0, currSum = 0;
		for(int i=0; i<N; i++){
			currSum += A[i];
			if(currSum == cost){
				flag = true;
				break;
			}
			else if(currSum > cost && prev < i-1){
				while(currSum > cost){
					currSum -= A[prev];
					prev++;
				}
			}
		}

		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" <<  endl;
	}

	return 0;
}