#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	int A[N];
	for(int i=0; i<N; i++)
		cin >> A[i];

	int curr = -1;
	long long int result = 1;
	for(int i=0; i<N; i++) {
		if(A[i]) {
			if(curr != -1)
				result *= i-curr;
			curr = i;
		}
	}

	if(curr == -1)
		cout << "0" << endl;
	else
		cout << result << endl;
	return 0;
}

/*
	1 0 1 1 0
	0 1 2 3 4
	1 0
*/