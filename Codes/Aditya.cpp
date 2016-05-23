#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define LLD long long int
/* Vector */
#define v(x) vector<x>
#define pb(x) push_back(x)

/* Pair and Map */
#define pii(x, y) pair<x, y>
#define mp(x, y) make_pair(x, y)
#define cmap map<char, int>
#define imap map<int, int>
#define lmap map<long long int, long long int>
#define smap map<long long int, string> 

/* Loops */
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define ROF(i, a, b) for(int i=a; i>=b; --i)

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define si(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define fillWithN(a, n) memset(a, n, sizeof(a))
const int maxn = 1e6 + 100;

bool compare(const pair<int, int>&i, const pair<int, int>&j){
    return i.second < j.second;
}

int main(){
	int T;
	cin >> T;
	v(pii(int, int)) clas;
	for(int i=0; i<T; i++) {
		/* code */
		int A, B;
		cin >> A >> B;
		clas.pb(mp(A, B));
	}

	sort(clas.begin(), clas.end(), compare);

	// for(int i=0; i<T; i++){
	// 	cout << clas[i].first << " " << clas[i].second << endl;
	// }

	int result = 1;
	int curr = clas[0].second;
	for(int i=1; i<T; i++){
		if(clas[i].first >= curr){
			result++;
			curr = clas[i].second;
		}
	}
	cout << result << endl;
	return 0;
}