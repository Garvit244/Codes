#include <bits/stdc++.h>
#include <string>
using namespace std;
# define MOD 1000000007

int amazingness(string a) {
	set<int> s;
	int result=0;

	for(int i=0; i<a.length(); i++) {
		int val = 0;
		for(int j=i; j<a.length(); j++) {
			val ^= a[j];
			if(s.find(val) != s.end()) {
				result = (result +val)%MOD;
				s.insert(val);
			}
		}
	}
	return result;
}

int main() {
	int Q;
	cin >> Q;

	while(Q--) {
		int L, R;
		cin >> L >> R;
		int result=0;
		for(int i=L; i<=R; i++) {
			result  = (result + amazingness(to_string(i)))%MOD;
		}

		cout << result << endl;
	}
	return 0;
}