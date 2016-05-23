#include <bits/stdc++.h>
using namespace std;
#define LENG 10010
long long int subset[LENG][LENG];

int isSubsetSum(long long int A[], int L, int R, int Sum)
{
    for (int i=L; i<=R; i++)
      subset[0][i] = 1;

    for (int i=1; i<=Sum; i++)
      subset[i][0] = 0;

     for (int i=1; i<=Sum; i++)
       for (int j=L; j<=R; j++){
         subset[i][j] = subset[i][j-1];
         if (i >= A[j-1])
           subset[i][j] = subset[i][j] || subset[i - A[j-1]][j-1];
       }
     return subset[Sum][R];
}

int main(){
	int N, Q;
	cin >> N >>Q;

	long long int W[N];
	for(int i=0; i<N; i++)
		cin >> W[i];

	while(Q--){
		int A, L, X, R, Wei;
		cin >> A;

		if(A == 1){
			cin >> L >> X;
			W[--L] = X;
		}
		else if(A == 2){
			cin >> L >> R;

			for(int i=L-1, j = R-1; i<=j; i++, j--){
				int temp = W[j];
				W[j] = W[i];
				W[i] = temp;
			}
		}
		else{
			cin >> L >> R >> Wei;
			if(isSubsetSum(W, L-1, R, Wei))
				cout << "Yes" << endl;
			else
				cout << "No" <<  endl;
		}
	}
	return 0;
}