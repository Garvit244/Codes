#include <bits/stdc++.h>
using namespace std;

vector <string> result;
set <string> Found;

void solve(string s, int len) {
	for(int i=len-13; i>=5; --i) {
		for(int j=2; j<=3; j++) {
			string aux;
			if(i+j-1 > len)
				continue;

			for(int k=0; k<=j-1; k++)
				aux += s[i+k];

			if(Found.count(aux) == 0) {
				result.push_back(aux);
				Found.insert(aux);
			}
		}
	}
}

int main() {
   	string A;
   	cin >> A;
   	solve(A, A.length());
  
  	cout << result.size() << endl;
  	sort(result.begin(),result.end());
  	for(int i=0; i<result.size(); i++)
  		cout << result[i] << endl;
    return 0;
}