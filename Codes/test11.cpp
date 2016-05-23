#include <bits/stdc++.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    
    int A[N];
    int t_max=0, t_min=INT_MAX;
    int count_A[20004]={0};
    for(int i=0; i<N; i++) {
        cin >> A[i];
        if(A[i] > t_max)
            t_max = A[i];
        if(A[i] < t_min)
            t_min = A[i];
        count_A[A[i]]++;   
    }
    
    int curr_max = t_min, result = 0;
    if(count_A[t_min] != 0) {
        if(count_A[t_min] != 1) {
            result += count_A[t_min]*t_min -t_min;
        }
    }
    
    // cout << result << endl;
    for(int i=t_min+1; i<=t_max; i++) {
        if(count_A[i] != 0) {
            if(count_A[i] == 1) {
                result += max(curr_max, i);
                curr_max = max(curr_max, i);
            }else {
                    result += max(curr_max, i);
                result += (count_A[i])*i - i;
                curr_max = i;
            }
        }
        // cout << count_A[i] << " " << result << endl;

    }  
    
    cout << result << endl;
    return 0;
}

/*
7
6 5 4 6 5 4 
  
0 4 4 4 5 8 8

*/