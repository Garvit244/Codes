#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;

	while(T--){
		long long int N;
		cin >> N;

		long long int result = 2;

		if(N == 1)
			cout << "1" << endl;
		else{
			long long int A= 2, B = 3;
			long long int C;

			while(B <= N){
				C = A;
				A = B;
				B += C;
				result++;
			}
			cout << result << endl;
		}
	}
	return 0;
}