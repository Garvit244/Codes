#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int sum1cycle = a + b + c + d;
	int sum2cycle = a + b + f;
	int sum3cycle = a + e + d;


	int result = min(sum1cycle, min(sum2cycle, sum3cycle));
	if(sum1cycle >0 && sum2cycle >0 && sum3cycle > 0)
		cout << "0" << endl;
	else if(result < 0)
		cout << (-1)* result << endl;
	else
		cout << "-1" << endl;

	return 0;
}


/**
	Cycles:
	a b c d 
	a b f
	a e d
**/