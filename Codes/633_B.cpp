#include <bits/stdc++.h>
using namespace std;

int findTrailingZeros(int  n){
    int count = 0;
    for (int i=5; n/i>=1; i *= 5)
          count += n/i;

    return count;
}

int main() {
	int m;
	cin >> m;
	vector<int> values;
	for(int i=5; i<10000000; i++) {
		int count = findTrailingZeros(i);			
		if(count == m)
			values.push_back(i);
		if(count > m)
			break;
	}
	
	if(values.size() == 0)
		cout << "0" << endl;
	else {
		cout << values.size() << endl;
		for(int i=0; i<values.size(); i++)
			cout << values[i] << " ";
		cout << endl;
	}
	return 0;
}