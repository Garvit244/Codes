#include <bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 2;

long long int tree[4*100005]={0};
long long int A[100005];

void build_tree(int node, int a, int b) {
    if(a > b) return;
    if(a == b) {tree[node] = A[a]; return;}
    build_tree(node*2, a, (a+b)/2);
    build_tree(node*2+1, 1+(a+b)/2, b);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}
 
void update_tree(int node, int a, int b, int i, int j, int value) {
    if(a > b || a > j || b < i) return;
    if(a == b) { tree[node] = value;return;}
    update_tree(node*2, a, (a+b)/2, i, j, value);
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
    tree[node] = (tree[node*2]+tree[node*2+1]);
}

ll query_tree(int node, int a, int b, int i, int j) {
    if(a > b || a > j || b < i) return 0;
    if(a >= i && b <= j) return tree[node];
    ll q1 = query_tree(node*2, a, (a+b)/2, i, j);
    ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
    ll res = (q1+q2);
    return res;
} 

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

// returns the N-th term of Fibonacci sequence
int fib(int N)
{
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = 1;
    F1[2] = 1;

    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;

    // raise T to the (N-1)th power
    if (N == 1)
        return 1;
    T = pow(T, N-1);

    // the answer is the first row of T . F1
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;

    long long int A[N+2];
    for(int i=1; i<=N; i++)
        cin >> A[i];

    while(M--){
        char type;
        int x, y;
        cin >> type >> x >> y;
        if(type == 'C') {
            x--;
            update_tree(1, 0, N-1, x,x, y);
            continue;
        }
        else { 
            long long int result = 0;
             ll tmp=query_tree(1, 0, N-1, 0, N-1);
            cout<<fib(tmp)%MOD<<endl;
        }
    }
    return 0;
}
