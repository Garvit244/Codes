#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int MAXN = 5e6;
bool used[MAXN+1];

int main(){
    int N, M;
    cin >> N >> M;

    for (int i = 2; i <= MAXN && (N || M); i++) {
        if (i % 2 == 0 && i % 3 == 0 && N > 0 && M > 0) {
            used[i] = true;
            if (M >= N)
                 M--;
            else 
                N--;
        } else if (i % 2 == 0 && N > 0) {
            used[i] = true;
            N--;
        } else if (i % 3 == 0 && M > 0) {
            used[i] = true;
            M--;
        } 
    }

    for (int i = MAXN; i >= 1; i--) {
        if (used[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
