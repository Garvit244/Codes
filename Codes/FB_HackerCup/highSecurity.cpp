#include <bits/stdc++.h>
using namespace std;

int guard;
char grid[2][10000];
bool isPlaceToPutGuard(int i, int j, int N) {
	if(grid[i][j] != '.')
		return false;
	if(j == 0)
		return grid[i][j+1] == 'X';
	if(j == N-1)
		return grid[i][j-1] == 'X';
	return grid[i][j+1] == 'X' && grid[i][j-1] == 'X';
}

bool guards(int i, int j, int N) {
	if(grid[i][j] != '.')
		return false;

	guard++;
	if(grid[1-i][j] != 'X')
		grid[1-i][j] = 'G';

	for(int k=j; k>=0 && grid[i][k] != 'X'; k--)
		grid[i][k] = 'G';
	for(int k=j; k<N && grid[i][k] != 'X'; k++)
		grid[i][k] = 'G';
	return true;
}

int main() {
	int T;
	cin >> T;

	for(int testCase = 1; testCase<= T; testCase++) {
		int N;
		cin >> N;

		guard= 0;
		for(int i=0; i<2; i++)
			for(int j=0; j<N; j++)
				cin >> grid[i][j];

		for(int i=0; i<2; i++) {
			for(int j=0; j<N; j++) {
				if(isPlaceToPutGuard(i, j, N)) {
					guards(1-i, j, N) || guards(i, j, N);
				}
			}
		}

		for (int i = 0; i < 2; ++i){
			for(int j=0; j<N; j++)
				if(grid[i][j] == '.')
					guards(i, j, N);
		}

  		cout << "Case #" << testCase << ": " << guard << endl;	
  }
  return 0;
}

