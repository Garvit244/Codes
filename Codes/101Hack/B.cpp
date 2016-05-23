#include <iostream>
using namespace std;

int main(){
	int N, Q;
	cin >> N >> Q;

	int A[N];
	int modulo0[N], modulo2[N];
	int count0=0; int count2=0;
	for(int i=0; i<N; i++){
		cin >> A[i];
		if(A[i] == 3)
			count0++;
		else if(A[i]%3 == 2)
			count2++;
		modulo0[i] = count0;
		modulo2[i] = count2;
	}

	while(Q--){
		int l, r;
		cin >> l >> r;
		if((modulo0[l-2]-modulo0[r-1])%2 == 1)
			cout << 0 << endl;
		else if((modulo2[l-2]-modulo2[r-1])%2 == 1)			
			cout << 2 << endl;
		else
			cout << 1 << endl;
	}
	return 0;
}