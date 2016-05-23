#include <iostream>
using namespace std;


int main(){
	int N, K;
	cin >> N >> K;

	int A[N];
	for(int i=0; i<N; i++)
		cin >> A[i];

	int result = N;
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			bool flag = false;
			for(int k=i; k<j; k++)
				if(A[k]%A[j] == K)
					flag = true;
			if(!flag)
				result++;
			else
				break;
		}
	}

	cout <<result << endl;
	return 0;
}