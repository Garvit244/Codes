#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	int A[N];
	for(int i=0; i<N; i++)
		cin >> A[i];

	map<int, int> count;
	int curr_count = A[0];
	int curr_max = 0;

	for(int i=1; i<N; i++) {
		curr_count = curr_count + A[i];
		if(count.find(curr_count) == count.end()) {
			count.insert(make_pair(curr_count, i));
			cout << "insert" << endl;
		} else {
			int value = count.at(curr_count);
			cout << "value " << value << endl;
			if(curr_max < (i-value))
				curr_max = (i-value);
		}
	}

	cout << curr_max << endl;

	return 0;
}

/**
	 0 1 2  3 4
	-1 0 1 -1 1

	-1 -> 0	
	0  -> 2
	-1 -> 3
	0  -> 4
	
**/