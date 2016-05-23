#include <iostream>
#include <vector>
 
#define REP(i,n) for (int i = 1; i <= n; i++)
 
using namespace std;
 
typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 2;
 
ll i1 = 1, i2 = 1, i0 = 1;
 
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}
 
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}
 
matrix fib(int N)
{
    
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;
    
    if (N == 1) { T[2][1] = 0; return T;}
 
    T = pow(T, N-1);
    
    return T;
}

#include <fstream>

int main()
{

int N, M, x, y;
cin >> N >> M;
 
matrix a[100001];
REP(i, N)  { cin >> x; a[i] = fib(x);}
REP(i, M)
{
    char c;
    cin >> c;
    if (c == 'Q')
        {
            cin >> x >> y;
            
            ll s0 = a[x][2][1];
            ll s1 = a[x][2][2];
            ll t;
            for (int i = x+1; i <= y; i++)
            {
 
                t = s1;
                s1 = (a[i][2][2] + s1 + s1*(a[i][2][2] + a[i][2][1]) + s0*a[i][2][2] ) % MOD;
                s0 = (a[i][2][1] + s0 + t*a[i][2][2] + s0*a[i][2][1]) % MOD;
 
            }
            cout << s1 << endl;
 
        } else
        {
            cin >> x >> y;
            a[x] = fib(y);
        }
    }
 
    return 0;
}