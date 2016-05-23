#include <bits/stdc++.h>
using namespace std;
int flag[2505];

int main() {
	int T;
	cin >> T;

	for(int index=1; index<=T; index++) {
		int N;
		cin >> N;

		int A[2*N][N];
		int till_max = 0;
		for(int i=0; i<2*N-1; i++) {
			for(int j=0; j<N; j++) {
				int num;
				cin >> num;
				A[i][j] = num;
				flag[num] = (flag[num]+1)%2;
				if(till_max < num)
					till_max = num;
			}
		}
		
		vector<int> result;
		for(int i=0; i<=till_max; i++)
			if(flag[i] == 1)
				result.push_back(i);
		
		for(int i=0; i<result.size(); i++)
			cout << result[i] << " ";
		cout << endl;
	}
	return 0;
}