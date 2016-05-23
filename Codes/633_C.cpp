#include <bits/stdc++.h>                                           
using namespace std;                                                
#define INF 99999999
#define LL   long long
#define LLU  long long unsigned int                                 
LLU hash1(const string &ss) {
    LLU hash = 0, c;
    int Len = ss.length();
    for(int i = 0;i<Len;i++){
    	c = (LLU)(ss[i]);
    	hash = ((hash << 5) + hash) ^ c;
    }
    return hash;
}

int N,M;
vector<string> words;
string s,t;
map<LLU,int> Map;

map<pair<int,LLU> , int> DP;
int taken[100005];
bool f = false;
int total = 0;

void call(int cur,int cnt,LLU hashVal){
	//cout << "Cur: "<<cur<<" cnt: "<<cnt<<" hash: "<<hashVal<<endl;

	pair<LLU,int> pr = make_pair(cur,hashVal);
	if(DP[pr] == 1) return;

	if(f == true) return;
	if(cur == N){
		if(Map[hashVal] != 0) {
			taken[cnt] = Map[hashVal];
			total = cnt+1;
			f = true;
		}
		return;
	}
	LL nHash = hashVal;
	LL c = (LLU)(s[cur]);
	nHash = ((nHash << 5) + nHash) ^ c; //New hash value;

	if(Map[hashVal] != 0){
		//2 Options:
		LL nHash = 0;
		LL c = (LLU)(s[cur]);
		nHash = ((nHash << 5) + nHash) ^ c; //New hash value;

		taken[cnt] = Map[hashVal];
		call(cur+1,cnt+1,nHash);
		if(f == true) return;

		nHash = hashVal;
		c = (LLU)(s[cur]);
		nHash = ((nHash << 5) + nHash) ^ c; //New hash value;

		call(cur+1,cnt,nHash);
		if(f == true) return;
	}else{
		LL nHash = hashVal;
		LL c = (LLU)(s[cur]);
		nHash = ((nHash << 5) + nHash) ^ c; //New hash value;

		call(cur+1,cnt,nHash);
		if(f == true) return;
	}

	DP[pr] = 1;
}

int main(){
	Map.clear();
	DP.clear();
	cin >> N >> s >> M;
	for(int z = 0;z<M;z++){
		cin >> t;s
		words.push_back(t);
		int i = 0,j = t.length()-1;
		while(i<j){
			swap(t[i],t[j]);
			i++;
			j--;
		}
		transform(t.begin(), t.end(), t.begin(), ::tolower);
		LLU hVal = hash1(t);
		Map[hVal] = z+1;
	}
	call(0,0,0);
	for(int i = 0;i<total;i++){
		int pos = taken[i]-1;
		if(i == 0){
			cout << words[pos];
		}else{
			cout << " " << words[pos];
		}
	}
	cout << endl;
}