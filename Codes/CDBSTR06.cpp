#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;

	while(T--){
		int N;
		cin >> N;

		int A[N];
		for(int i=0; i<N; i++)
			cin >> A[i];

		int startIndex=0, endIndex=0, maxSum=0, currSum=A[0];
		int finalStart=0, finalEnd=0;
		if(currSum < 0){
			currSum = 0;
			startIndex = 1;
			endIndex = 1;
		}
		for(int i=1; i<N; i++){
			if(A[i]>0){
				endIndex = i;
				currSum += A[i];
			}
			else{
				// cout << "currSum: " << currSum << endl;
				if(currSum > maxSum){
					maxSum = currSum;
					finalStart = startIndex;
					finalEnd = endIndex;
				}
				currSum = 0;
				startIndex =  i+1;
				endIndex = i+1;

			}
		}
		if(currSum > maxSum){
			maxSum = currSum;
			finalStart = startIndex;
			finalEnd = endIndex;
		}

		for(int i=finalStart; i<=finalEnd; i++)
			cout << A[i] << " ";
		cout << endl;
	}

	return 0; 
}