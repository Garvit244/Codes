#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << "1" << endl;
	cout << "3 1 1 2" << endl;
	cout << "3 3 3 4" << endl;
	cout << flush;
	int N;
	cin >> N;

	cout << "2" << endl;
	if(N == 0)
		cout << "5" << endl;
	else if(N == -1)
		cout << "4" << endl;
	else if(N == -2)
		cout << "3" << endl;
	else if(N == 1)
		cout << "2" << endl;
	else if(N == 2)
		cout << "1" << endl;
	cout << flush;
	return 0;
}