#include <bits/stdc++.h>
using namespace std;

/**
		     	 1 0 1 1 0 1 0 1 1 1 0 1
	count_0:	 0 1 1 1 1 1 1 1 1 1 2 0   
	count_1:     1 1 2 3 2 3 1 2 3 4 4 
	index 		 

	1 1 0 1 0 1 0 0
	0 0 1 1 2 0 1 2
	1 2 2 3 3 1 1 1
**/

int main() {
	int A[] = {0, 0 ,1 , 0 , 0, 1 ,1 };

	int count_0 = 0, count_1 = 0;
	int index , last_index, position;
	int maximum = 0; bool flag = true;
	int n = sizeof(A)/sizeof(A[0]);
	for(int i=0; i<n; i++) {
		if(A[i] == 0)
			count_0++;
		else
			count_1++;
		cout << count_0 <<  " - " << count_1 << endl;
		if(count_0 == 1 && flag) {
			index = i; flag = false;
		}

		if(count_0 == 2 || (i == n-1)) {
			cout << "index " << index  << " i " << i << endl;

			if(count_1 > maximum) {
				maximum = count_1;
				position = index;
			}

			count_0 = 1;
			count_1 = i-index-1;
			index = i;
			
			cout << count_0 <<  " " << count_1 << endl;

		}
	}

	maximum += 1;
	cout << "maximum is: " << maximum << " index is: " << position << endl;
	return 0;
}