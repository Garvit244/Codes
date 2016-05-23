#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 1; i <= n; i++)
typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 2;
 
matrix mul(matrix A, matrix B){
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}
 
matrix pow(matrix A, int p){
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}
 
matrix fib(int N){
    
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;
    
    if (N == 1) { T[2][1] = 0; return T;}
 
    T = pow(T, N-1);
    
    return T;
}

int main() {
	int N, M;
	cin >> N >> M;
 
	matrix A[100001];
	REP(i, N) { 
		int x;
		cin >> x; 
		A[i] = fib(x);
	}
	
	for(int i=0; i<M; i++) {
	    char type;
 	  	cin >> type;
    	
    	int x, y;
    	if (type == 'Q') {
            cin >> x >> y;
            
            long long firstVal = A[x][2][1];
            long long secondVal = A[x][2][2];
           	long long temp;

            for (int i = x+1; i <= y; i++) {
                temp = secondVal;
                secondVal = (A[i][2][2] + secondVal + secondVal * (A[i][2][2] + A[i][2][1]) + firstVal * A[i][2][2] ) % MOD;
                firstVal = (A[i][2][1] + firstVal + temp * A[i][2][2] + firstVal * A[i][2][1]) % MOD;
            }

            cout << secondVal << endl;
 
        } else {
            cin >> x >> y;
            A[x] = fib(y);
        }
    }
    return 0;
}