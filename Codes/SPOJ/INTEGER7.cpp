#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	unsigned long int a1, a2, b1, b2;
	cin >> a1 >> b1 >> a2 >> b2;

	for(unsigned long int i=0, j=1; ;i++, j++) {
		if (a1*i+b1 == a2*j+b2) {
			cout << i << " " << j << endl;
			break;
		} else if (a1*j+b1 == a2*i+b2) {
			cout << j << " " << i << endl;
			break;
		}
	}
	return 0;	
}