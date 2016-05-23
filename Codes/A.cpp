#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;

	int H[52] ={0}, V[52]= {0};
	vector<int> result;

	for(int i=0; i<N*N; i++){
		int h, v;
		cin >> h >> v;
		if((H[h] == 0) && (V[v] == 0))
		{
			H[h] = 1;
			V[v] = 1;
			result.push_back(i+1);
		}
	}
	for(int i=0; i<result.size(); i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}