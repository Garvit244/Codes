#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	int T;
	cin >> T;

	while(T--)
	{
		string L1, L2;
		cin >> L1;
		cin >> L2;

		vector<int> A(L1.length() , 1000000);
		vector<int> B(L2.length() , 1000000);

		if(L1[0] == '.')
			A[0] = 0;
		if(L2[0] == '.')
			B[0] = 0;

		for(int i=1; i<L1.length(); i++){
			if(L1[i] == '.')
				A[i] = min(A[i-1], B[i-1]+1);
			if(L2[i] == '.')
				B[i] = min(B[i-1], A[i-1]+1);
		}

		long long int last_A = A[L1.length()-1];
		long long int last_B = B[L2.length()-1];
		long long int result = min(last_A, last_B);

		if(last_B >= 1000000 && last_A >= 1000000)
			cout << "No" << endl;
		else{
			cout << "Yes" << endl;
			cout << result << endl;
		}
	}
	return 0;
}