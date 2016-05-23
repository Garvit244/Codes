#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}

int main(){
	int T;
	cin >> T;

	while(T--){
		int N, M;
		cin >> N >> M;

		int A[N];
		for(int i=0; i<N; i++)
			cin >> A[i];

		vector<int> set1;
		for(int i=0; i<N; i++)
			set1.push_back(countSetBits(A[i]));

		sort(set1.begin(), set1.end());

		int result = 0;
		for(int i=0; i<M; i++){
			result +=set1[N-1-i];
		}

		cout << result << endl;
	}
	return 0;
}