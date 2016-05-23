#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i=1; i<=T; i++) {
		int count = 0;
		string A;
		cin >> A;
		for(int j= A.length()-1; j>=0; j--) {
			if(A[j] == '-') {
				A[j] = '+';
				count++;

				int k;
				for(k = j-1; k>=1; k--) {
					if(A[k] == '-'){
						A[k] = '+';
						continue;
					}
					else { 
						break;
					}
			    }
				j = k;
				for(int l=j; l>=0; l--) {
					if(A[l] == '+')
						A[l] = '-';
					else
						A[l] = '+';
				}
				j++;
			}
		}
		cout<<"Case #"<<i<<": "<<count<<"\n";
	}
	return 0;
}