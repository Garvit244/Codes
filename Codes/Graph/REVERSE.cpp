#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006

struct comp {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

vector< pair<int, int> > graph[MAX];
int D[MAX];
priority_queue< pair<int, int>, vector< pair<int, int> >, comp > q;
bool visited[MAX];

int main() {
	int N, M;
	cin >> N >> M;

	int x, y;
	for(int i=0; i<M; i++) {
		cin >> x >> y;
		graph[x].push_back(make_pair(y, 0));
		graph[y].push_back(make_pair(x, 1));
	}

	for(int i=1; i<=N; i++) 
		D[i] = INT_MAX;

	D[1] = 0;
	q.push(make_pair(1, 0));

	while(!q.empty()) {
		int u = q.top().first;

		q.pop();
		if(visited[u])
			continue;
		for(int i=0; i<graph[u].size(); i++) {
			int first_vertex = graph[u][i].first;
			int second_vertex = graph[u][i].second;
			if(!visited[first_vertex] && D[first_vertex] > D[u] + second_vertex) {
				D[first_vertex] = D[u] + second_vertex;
				q.push(make_pair(first_vertex, D[first_vertex]));
			}

		visited[u] = true;
		}
	}

	if(D[N] == INT_MAX)
		cout << "-1" << endl;
	else
		cout << D[N] << endl;

	return 0;
}