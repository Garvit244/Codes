#include <bits/stdc++.h>
using namespace std;

int convert(string a){
	int k=a.size();
	int f=0;
	int gh=1;	
	for(int i=k-1;i>=0;i--){
   	f=f+((a[i]-'0')*gh);
    	gh=gh*10;
	}
	return f;
}

int main() {
	string a;
	string result = "";

	int current = 0, plus=0, minus=0;
	int number;
	while(cin >> a) {
		if(a == "+") {
			plus++;
			result.append(" + 1");
			// cout << "result" << result << endl;
		}
		else if(a == "-") {
			minus++;
			result.append(" - 1");
			// cout << "result" << result << endl;
		} else if(a == "?" || a == "=")
			continue;	
		else {
			number = convert(a);
			break;
			// cout << "number" << number << endl;
		}
	}	

	// cout << minus << endl;
	current = plus-minus;
	if(number == 1 && current == 0)
		cout << "Impossible" << endl;
	else if(plus == 0 && minus == 0) {
		cout << "Possible" << endl;
		cout << number << " = " << number << endl;
	} else if(current == 0 || (number-current) <= 0)
		cout << "Impossible" << endl;
	else {
		cout << "Possible" <<endl;
		cout << number-current << result;
		cout << " = " << number << endl;
	}
	
	return 0;
}