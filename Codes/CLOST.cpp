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

int main(){
	int T;
	cin >> T;

	while(T--){
		int N, K;
		cin >> N >> K;

		char result[N];
		for(int i=0; i<N; i++)
			result[i] = '\0';
		while(K--){
			int x, y;
			cin >> x >> y;
			result[x] = '(';
			result[y] = ')';
		}

		int open=0;
		for(int i=0; i<N; i++){
			if(result[i] == '(')
				open++;
			else if(result[i] == ')')
				open--;
			else{
				if(open > 0 && result[i+1] != ')'){
					result[i] = ')';
					open--;
				}
				else{
					result[i] ='(';
					open++;
				}
			}
		}

		for(int i=0; i<N; i++)
			cout << result[i];
		cout << endl;
	}
	return 0;
}

/*
	(qqq())
*/