#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){if(!b)return a;return gcd(b, a%b);}
bool bb[500][500];

int main(){
	int N;
	cin >> N;

	int A[N*N];
	for(int i=0; i<N*N; i++)
		cin >> A[i];

	if(N == 1)
		cout << A[0] << endl;
	else{
		sort(A, A+N*N);
		reverse(A, A+N*N);

		vector<int> result;
		result.push_back(A[0]);
		result.push_back(A[1]);
		map<int, int>comes;
		comes[gcd(A[0], A[1])]++;

		for(int i=2; i<N*N; i++){
			cout << A[i] << "bingo" << result.size() << endl; 
			if(!comes[A[i]]){
				for(int j=0; j<result.size(); j++){
					comes[gcd(A[i], result[j])]++;
					comes[A[i]]++;
					result.push_back(A[i]);
					// cout << "inside" << endl;
				}
			}
			else{
				for(int j=0; j<result.size()-1; j++){
					for(int k=j+1; k<result.size(); k++){
						if(gcd(result[j], result[k]) == A[i] && !bb[j][k]){
							comes[A[i]]--;
							bb[j][k] = 1;
						}
					}
				}
			}
		}

		for(int i=0; i<N; i++)
			cout << result[i] << " ";
		cout << endl;
	}
	return 0;
}