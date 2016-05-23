#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long int Na, Nb;
	cin >> Na >> Nb;

	long long int k, m;
	cin >> k >> m;

	vector<long long int> A;
	vector<long long int> B;
	for(int i=0; i<Na; i++){
		long long int x;
		cin >> x;
		A.push_back(x);
	}
	
	for(int i=0; i<Nb; i++){
		long long int x;
		cin >> x;
		B.push_back(x);
	}

	if(A.size() < k)
		cout << "NO" << endl;
	else{
		long long int kmin = A[k-1];
		bool flag = false;
		int index = 0;
		for(index= 0; index< B.size(); index++){
			if(B[index] > kmin)
				break;
		}
		long long int count = B.size()-index;
		if(count >= m)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}