#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;

	while(T--){
		string X, Y;
		cin >> X >> Y;
		bool flag = false;
		if(X.length() != Y.length())
			cout << "No" << endl;
		else{
			for(int i=0; i<X.length(); i++){
				if((X[i] != Y[i])){
					if((X[i] != '?' && Y[i] == '?')  || (Y[i] != '?' && X[i] == '?'))
						flag = false;
					else{
						flag = true;
						break;
					}
				}
			}
		}
		if(flag)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}