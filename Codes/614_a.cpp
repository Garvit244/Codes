#include <iostream>
using namespace std;

int main() 
{
    unsigned long long l, r, k, a;
    cin >> l >> r >> k;
    a = 1;
   bool flag = false;

   	while(a < l)
   		a *= k;

   	while(a >= l && a<= r){
   		cout << a << " ";
   		flag = true;
   		if(r/a < k)
   			break;
	   	a *= k;

   	}
   	if(!flag)
   		cout << "-1";
    cout << endl;
    
    return 0;
}