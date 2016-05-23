#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long F[100];
long long countD;

void fibonnaci() {
  F[0] = 1;
  F[1] = 2;
  for(int i=2; i<55; i++)
    F[i] = F[i-1] + F[i-2];
}

long long int countChefFib(int index, int K, long long int sumRemain) {
  if(index < 0) return 0;
  if(sumRemain > (F[index]*K)) return 0;
  if(sumRemain == 0 && K == 0) return 1;
  if(K == 0 || sumRemain < 0) return 0;
  return ((countChefFib(index, K-1, sumRemain-F[index])%MOD) + (countChefFib(index-1, K, sumRemain)%MOD));
}

int main() {
  fibonnaci();

  int Q;
  cin >> Q;
  while(Q--) {
    long long int X;
    int K;
    countD = 0;
    cin >> X >> K;
    cout << countChefFib(49, K, X) << endl; 
  }
  return 0;
}