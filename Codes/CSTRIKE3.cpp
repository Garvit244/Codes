#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main(){	
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;

	while(T--){
		int A[26] = {0};
		string name;
		cin >> name;
        int countOdd=0;

		for(int i=0; i<name.length(); i++){
			if(!A[name[i]-97])
				countOdd++;
			A[name[i]-97] = 1;
		}

		(countOdd%2 == 0)? printf("Terrorist\n"):printf("Counter Terrorist\n");			
	}
	return 0;
}