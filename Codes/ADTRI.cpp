#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		bool flag = false;

		for(int i=N+1; i<2*N; i++){
			double l = sqrt(N*N-(i*i)/4);

			if(l > 0){
				if((l -(long long int)l) == 0){
					cout << "YES" << endl;
					flag= true;
					break;
				}
			}
		}

		if(!flag)
			cout << "NO" << endl;
	}
	return 0;	
}