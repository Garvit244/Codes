#include <bits/stdc++.h>
using namespace std;

long long MultiplyMod(long long a, long long b, long long mod) {
    unsigned long long r = 0;
    a %= mod, b %= mod;
    while (b) {
        if (b & 1LL) r = (r + a) % mod;
        b >>= 1LL, a = ((unsigned long long) a << 1LL) % mod;
    }
    return r;
}

long long PowerMod(long long a, long long n, long long mod) {
    long long r = 1LL;
    while (n) {
        if (n & 1LL) r = MultiplyMod(r, a, mod);
        n >>= 1LL, a = MultiplyMod(a, a, mod);
    }
    return r;
}

bool isprime(long long n) {
    const int pn = 9, p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    for (int i = 0; i < pn; ++i)
        if (n % p[i] == 0) return n == p[i];
    if (n < p[pn - 1]) return 0;
    long long s = 0, t = n - 1LL;
    while (~t & 1LL)
        t >>= 1LL, ++s;
    for (int i = 0; i < pn; ++i) {
        long long pt = PowerMod(p[i], t, n);
        if (pt == 1LL) continue;
        bool ok = 0;
        for (int j = 0; j < s && !ok; ++j) {
            if (pt == n - 1LL) ok = 1;
            pt = MultiplyMod(pt, pt, n);
        }
        if (!ok) return 0;
    }
    return 1;
}

long long pt(long long b, long long e){
     if(e == 0LL)return 1LL;
     if(e == 1LL)return b;
     long long ans = pt(b,e>>1LL);
     return ans*ans*pt(b,e&1LL);
}

string convert(int n, long long R){
  string ans = "";
  for(int i = 0; i < n; i++){
       if(R&(1LL<<i)){
           ans = "1"+ans;
       }else ans = "0" + ans;
  }
  return ans;
}

long long divi(long long R){
   if((R%2LL) == 0LL)return 2;
   if((R%3LL) == 0LL)return 3;
   long long F = (long long)(sqrt((double)(R)) + 1e-7);
   for(long long i = 5; i <= F; i += 2){
         if((R%i)==0LL) return i;
   }
}

int main () {
     int n,T,J,K;
     cin>>T;-     for(int t = 1; t <= T; t++){
        cin>>n>>K;
        cout<<"Case #"<<t<<":"<<"\n";
        for(long long j = (1LL<<(n-1))+1LL; j < (1LL<<n); j += 2LL){
              bool FLAG = 0;
              vector<long long> V;
              for(int base = 2; base <= 10; base++){
                  long long sum = 0LL;
                  for(int h = 0; h < n; h++){
                      if(j&(1LL<<h)){
                           sum += pt(1LL*base,1LL*h);
                      }
                  }
                  if(isprime(sum)){
                      FLAG = 1;
                      break;
                  }else{
                      V.push_back(sum);
                  }
              }
              if(!FLAG){
                  cout<<convert(n,j)<<" ";
                  for(int i = 0; i < 9; i++){
                      cout<<divi(V[i]);
                      if(i+1 != 9)cout<<" ";
                  }
                  cout<<"\n";
                  K--;
                  if(!K)break;
              }
        }
     }
     return 0;
}