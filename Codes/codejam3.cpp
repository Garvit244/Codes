#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,int> P;
typedef long long ll;
#define mp make_pair
#define fi first
#define sc second
#define INF 100000000
struct edge
{
	int to,cap,rev;
};
vector<edge>G[2100];
bool used[2100];

void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
int dfs(int v,int t,int f)
{ 
	if(v==t) return f;
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(!used[e.to] && e.cap>0)
		{ 
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0) 
			{ 
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t)
{ 
	int flow=0;
	while(1)
	{ 
		memset(used,0,sizeof(used));
		int f=dfs(s,t,INF);
		if(!f) return flow;
		flow+=f;
	}
}

int main(){
	int T; cin >> T;

	for(int test=0;test<T;test++){
		int n;
		string s[1005],t[1005]; cin >> n;
		map<string,int>L,R;
		for(int i=0;i<n;i++){
			cin >> s[i] >> t[i];
			L[s[i]]=0;
			R[t[i]]=0;
		}
		int V = 0;
		int nx = 1;
		for(map<string,int>::iterator it=L.begin();it!=L.end();it++){
			add_edge(2098,nx,1);
			it->sc = nx++;
		}
		V+=nx-1;
		nx=1;
		for(map<string,int>::iterator it=R.begin();it!=R.end();it++){
			add_edge(1050+nx,2099,1);
			it->sc = nx++;
		}
		V+=nx-1;
		for(int i=0;i<n;i++){
			add_edge(L[s[i]],R[t[i]]+1050,1);
		}
		V -= max_flow(2098,2099);
		cout << "Case #" << test+1 << ": ";
		cout << n-V << endl;
	}
	return 0;
}