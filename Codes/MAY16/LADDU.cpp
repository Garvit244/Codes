#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		string s;
		cin >> N >> s;

		int result;
		int laddu=0;
		for(int i=0; i<N; i++) {
			string act;
			cin >> act;

			if(act =="TOP_CONTRIBUTOR")
				laddu += 300;
			else if(act == "CONTEST_WON") {
				int rank;
				cin >> rank;
				laddu += 300;
				if(rank <= 20)
					laddu += 20 - rank;
			} else if(act == "BUG_FOUND") {
				int serverity;
				cin >> serverity;
				laddu += serverity;
			} else if(act == "CONTEST_HOSTED")
				laddu += 50;
		}
		if(s == "INDIAN")
			result = laddu/200;
		else
			result = laddu/400;
		cout << result << endl;
	}
	return 0;
}