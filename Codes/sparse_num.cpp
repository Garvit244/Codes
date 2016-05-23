#include <bits/stdc++.h>
using namespace std;

/**
	4   100
	5   101
	6   110
	7   111
	8   1000
	9   1001
	10  1010

	0 1 1 0
    1 1 0 1 1 0 
    0 0 0 0 0 1

    1 1 0 0 0 1 1 0
	0 0 1 0 0 0 0 1
**/

int main() {
	int N;
	cin >> N;

	std::vector<int> bits;
	while(N != 0) {
		bits.push_back(N&1);
		N >>= 1;
	}

	int last_index = 0;
	bits.push_back(0);
	for(int i = 1; i<bits.size()-1; i++) {
		if(bits[i] == 1 && bits[i-1] == 1 && bits[i+1] != 1) {
			bits[i+1] = 1;

			for(int j=last_index; j<=i; j++) {
				bits[j] = 0;
			}
			last_index = i+1;
		}
	}

	int result =0;
	for(int i=bits.size()-1; i>=0; i--) {
		if(bits[i]) {
			int power = pow(2,i);
			result += power;
		}
	}
	
	cout << result << endl;
	return 0;
}

