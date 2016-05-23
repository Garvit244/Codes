#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int N;
	cin >> N;

	if(N%7 == 0)
		cout << (N/7)*2<<" "<<(N/7)*2 << endl;
	else {
		int rem = N%7;
		int temp = N/7;
		cout << temp*2<<" "<<temp*2+2 << endl;
	}
	return 0;
}