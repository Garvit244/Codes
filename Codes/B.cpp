#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;

	vector<int> A;
	for(int i=0; i<N; i++){
		int x;
		cin >> x;
		A.push_back(x);
	}

	bool flag = true;
	int result = -1, count=0;

	while(count != N){
		result++;
		if(flag){
			for(int i =0; i<N; i++){
				if(A[i]<=count){
					count++;
					A[i] = 100002;
				}
			}
		}
		else{
			for(int i =N-1; i>=0; i--){
				if(A[i]<=count){
					count++;
					A[i] = 100002;
				}
			}
		}
		flag = !flag;
	}
	cout << result << endl;
	return 0;
}