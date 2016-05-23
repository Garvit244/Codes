#include <bits/stdc++.h>
using namespace std;
 
float d,h,v,e;
 float pi = 3.14159265358;
int main() {
	cin >> d >> h >> v >> e;
	e*=pi*(d/2)*(d/2);
	e-=v;
	if(e>=0) {
		cout<<"NO" << endl;
	} else {
		cout<<"YES"<<endl;
		h*=pi*(d/2)*(d/2);
		e=-e;
		cout<<(double)h/e<<endl;
	}
	return 0;
}