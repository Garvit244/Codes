#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1) {
		int N;
		cin >> N;
		if(N == 0)
			return 0;

		set<string> insufficient;
		string st;
		for(int i=0; i<N; i++) {
			cin >> st;
			insufficient.insert(st);
		}

		while(1) {
			string accr;
			cin >> accr; 
			cin.ignore();
			string phrase; 
			getline(cin, phrase);

			if(phrase == "CASE")
				break;

			vector<string> words;
			istringstream iss(phrase);
			while(true) {
				string word;
				iss >> word;
				if(word == "")
					break;
				if(insufficient.find(word) == insufficient.end()) 
					words.push_back(word);
			}

			int dp[152][152], dp2[152][152];
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1;

			for(int i=0; i<words.size(); i++) {
				for(int j=0; j<accr.length(); j++) {
					int mx = min(accr.length()-j, words[i].length());

					for(int k=0; k<=words[i].length(); k++)
						dp2[k][0] = 1;

					for(int k=1; k<=mx; k++)
						dp2[0][k] = 0;

					for(int k=0; k<=words[i].length(); k++) {
						for(int l=0; l<mx; l++) {
							dp2[k+1][l+1] = dp2[k][l+1];
							if(words[i][k] == tolower(accr[j+l]))
								dp2[k+1][l+1] += dp2[k][l];	
						}
					}

					for(int k=1; k<=mx; k++)
						dp[i+1][j+k] += dp[i][j] * dp2[words[i].length()][k];
				}
			}

			if(dp[words.size()][accr.length()] == 0)
				cout << accr << " is not a valid abbreviation" << endl;
			else {
				 cout << accr << " can be formed in "<< dp[words.size()][accr.length()] << " ways" << endl;
			}
		}
	}	
}