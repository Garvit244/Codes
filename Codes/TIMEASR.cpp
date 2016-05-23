#include <bits/stdc++.h>
using namespace std;

int main(){
	double angle[12][62] = {0};
	for(int i=0; i<12; i++)
		for(int j=0; j<60; j++){
			double calAngle = abs(30.0*i - (11.0*j)/2.0);
			angle[i][j] = min(360-calAngle, calAngle);
		}

	int T;
	cin >> T;
	while(T--){
		double A;
		cin >> A;

		for(int i=0; i<12; i++)
			for(int j=0; j<60; j++){
				if(abs(angle[i][j] - A) < (1.0/120))
					printf("%02d:%02d\n",i,j);
			}
	}
	return 0;
}