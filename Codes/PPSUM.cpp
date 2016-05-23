#include <iostream>
using namespace std;

int t,n,d;

int main() {
	cin>>t;
	while(t--){
		cin>>d>>n;
		for(int i=0;i<d;i++){
			n=(n*(n+1))/2;
		}
		cout<<n<<endl;
	}
	return 0;
}