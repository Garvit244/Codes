#include <iostream>
using namespace std;

bool isPowerOfTwo (int x)
{
  /* First x in the below expression is for the case when x is 0 */
  return x && (!(x&(x-1)));
}
 
int main(){
	int T;
	cin >> T;

	while(T--){
		long long int N;
		cin >> N;

		if(N == 1)
			cout << "2" << endl;
		else
		{
			if(isPowerOfTwo(N+1)){
				cout << N/2 << endl;
			}
			else{
				cout << "-1" << endl;
			}
		}
	}
	return 0;
}