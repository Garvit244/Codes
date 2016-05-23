#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int C;
	int Z;
	int mark;
};

bool acompare(Node lhs, Node rhs) { return lhs.Z > rhs.Z; }

int main(){
	int T;
	cin >> T;

	while(T--){
		int N, M, K;
		cin >> N >> M >> K;

		int X[N];
		Node  che[M];
		for(int i=0; i<N; i++)
			cin >> X[i];

		for(int i=0; i<M; i++)
			cin >> che[i].C;

		for(int i=0; i<M; i++)
			cin >> che[i].Z;

		Node noCoprime[N];
		for(int i=0; i<N; i++){
			int gems=0;
			for(int j=0; j<M; j++){
				if((__gcd(X[i], che[j].C)) != 1)
					gems += che[j].Z;
			}

			noCoprime[i].C = X[i];
			noCoprime[i].Z = gems;
		}

		sort(noCoprime, noCoprime+N, acompare);
		int result = 0;

		if(K == 1)
			cout << noCoprime[0].Z << endl;
		else{
			for(int i=0; i<K; i++){
				cout << noCoprime[i].C << " " << noCoprime[i].Z << endl;
				for(int j=0; j<M; j++){
					if(!che[j].mark){
						if((__gcd(noCoprime[i].C, che[j].C)) != 1)
							result += che[j].Z;
					}
					che[j].mark = 1;
				}
			}
			cout << result << endl;
		}
	}

	return 0;
}