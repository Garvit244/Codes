#include <bits/stdc++.h>
#include <string>     // std::string, std::to_string

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int i=1; i<=T; i++) {
		int N;
		cin >> N;
		int counter = 1;

		string all = "0123456789";
		if(N == 0)
			cout << "Case #" << i << ": INSOMNIA" <<endl;
		else {
			while(all != "") {
				string original = to_string(N*counter);
				for(int k=0; k<original.length(); k++){
					for(int j=0; j<all.length(); j++) {
						if(original[k] == all[j])
							all.erase(j ,1);
					}
				}
				counter++;
			}
			cout << "Case #" << i<< ": " << N*(counter-1) << endl;
		}
	}
	return 0;
}