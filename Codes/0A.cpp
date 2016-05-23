#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;

	long long int A[N];
	for(int i=0; i<N; i++)
		cin >>  A[i];

	int count, maxCount, max;
	count = maxCount= 1;
	max = A[0];

	for(int i=1; i<N; i++){
		if(A[i] >= max){
			count++;
		}
		else{
			if(maxCount < count)
				maxCount = count;
			count = 1;
		}
		max = A[i];
	}
	if(maxCount < count)			
		maxCount = count;
	cout << maxCount << endl;
	return 0;
}