#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int T;
	cin >> T;

	while(T--){
		int N;
		cin >> N;

		vector<int> A(N);
		int original[N];
		double result[N];

		for(int i=0; i<N; i++){
			cin >> original[i];
			A[i] = original[i];
		}

		sort(A.begin(), A.end());

		for(int i=N-1; i>=0; --i){	
			if(i%2 == 0){
				result[i] = (double)A[(i)/2];
			}
			else{
				result[i] = (double)(A[i/2] + A[(i/2)+1])/2;
			}
			// cout << "result " << result[i] << endl;
			A.erase(remove(A.begin(), A.end(), original[i]), A.end()); 
		}
		
		for(int i=0; i<N; i++)
			cout << result[i] << endl;
	}
	return 0;
}