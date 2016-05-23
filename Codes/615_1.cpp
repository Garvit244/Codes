#include <bits/stdc++.h>
using namespace std;

int main() {
	int a1, a2;
	cin >> a1 >> a2;

	int count = 0;
	if(a1 == 1 && a2 == 1) {
		cout << "0" << endl;
		return 0;
	}
	while(a1!= 0 && a2!=0) {
		if(a1 < a2) {
			a1 = a1+1;
			a2 = a2 - 2;
			count++;
		}
		else {
			a2 = a2 + 1;
			a1 = a1 - 2;
			count++;
		}

		if(a1 == 0 || a2 == 0)
			break;
	}
	cout << count << endl;
	return 0;
}