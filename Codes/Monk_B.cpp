#include <iostream>
using namespace std;

// int bin(unsigned n)
// {
//     unsigned i;
//     for (i = 1 << 31; i > 0; i = i / 2)
//         (n & i)? return 1: return 0:
// }

int main(){
	int T;
	cin >> T;
	while(T--){
		long long int M, P;
		cin >> M >> P;

		int modM, modP;
		long long int result = 0;
		while(M !=0 || P != 0){
			modP = P%2;
			modM = M%2;

			if(modM != modP)
				result++;
			M /= 2;
			P /= 2;
		}

		cout << result << endl;
	}
	return 0;
}