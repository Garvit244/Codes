#include <bits/stdc++.h>
using namespace std;
int arr[250000];
bool bb[500][500];

int main(){
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    for(int i=0; i<N*N; i++)
        cin>>arr[i];

    if(N==1){
        cout<<arr[0] << endl;
        return 0;
    }
    sort(arr, arr+N*N);
    reverse(arr,arr+N*N);
    vector<int> result;
    result.push_back(arr[0]);
    result.push_back(arr[1]);

    map<int,int> tre;
    tre[__gcd(arr[0],arr[1])]++;

    for(int i=2; i<N*N; i++){
        if(!tre[arr[i]]){
            for(int j=0; j<result.size(); j++)
                tre[__gcd(arr[i],result[j])]++;
                tre[arr[i]]++;
                result.push_back(arr[i]);
        }else {
            for(int j=0;j<result.size()-1;j++)
                for(int k=j+1;k<result.size();k++)
                if(__gcd(result[j],result[k])==arr[i] && !bb[j][k]){
                    tre[arr[i]]--;
                    bb[j][k]=1;
                }
        }
    }
    for(int i=0;i<N;i++)
        cout<<result[i]<<" ";
    cout << endl;

    return 0;
}
