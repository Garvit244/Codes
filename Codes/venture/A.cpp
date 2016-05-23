#include <bits/stdc++.h>
using namespace std;

 
vector<char>v;

bool checkReach(int start, int end) {
    int up = 0;
    int right = 0;
    for(int i = start; i <= end; i++) {
        if(v[i] == 'U'){
            up++;
        } else if(v[i] == 'D') {
            up--;
        } else if(v[i] == 'R') {
            right++;
        }  else {
            right--;
        }
    }
    
    if(up == 0 && right == 0) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
           // trace2(i, j);
            if(checkReach(i, j)) {
             //   trace2(i, j);
                ans++;
            }
        
        }
    }
    cout<<ans<<endl;
}