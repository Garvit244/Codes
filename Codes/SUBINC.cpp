#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;

		long long int A[N];
		for(int i=0; i<N; i++)
			cin >> A[i];

		long long int count = 1, maxi = A[0], result=0;
		for(int i=1; i<N; i++){
			if(A[i] >= maxi){
				count++;
				maxi = A[i];
			}
			else{
				result += (count*(count+1)/2);
				maxi = A[i];
				count = 1;
			}
		}
		result += (count*(count+1))/2;
		cout << result << endl;
	}
	return 0;
}