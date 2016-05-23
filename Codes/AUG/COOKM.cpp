#include <iostream>
#include <cstdio>
using namespace std;

bool isPowerOfTwo (int x)
{
  return x && (!(x&(x-1)));
}

int main(){
	int T;
	cin >> T;
	
	while(T--){
		int A, B;
		cin >> A >> B;
		int result = 0;

		if(A == B)
            result = 0;
        else{
            while(A != B){
                if(A>B){
                    A/= 2;
                    result++;
                }
                else{
                    if(isPowerOfTwo(A)){
                        while(A != B){
                            A *= 2;
                            result++;
                        }
                    }
                    else{
                        while(!isPowerOfTwo(A)){
                            A/= 2;
                            result++;
                        }
                    }
                }
            }
        }
        cout << result << endl;
	}
    return 0;
}

/*
CASE 1: A > B
    A is even
        12 2, 16 2
        log2(6)%2 != 0
            12/2 = 6
            6/2 = 3
            3 - 1/2 = 1
            1 * 2 = 2
        6 4
        6 = 2 + 1 - 2 = 1
 
 */
