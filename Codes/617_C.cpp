#include <bits/stdc++.h>
using namespace std;

struct point
{
    long long int x;
    long long int y;

    friend bool operator < (const point &p, const point &q) {
        return p.x < q.x;
    }
}A[2010];

long long int square(long long int x) { return x*x; }
int main() {
	int n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;

	int x, y;
	for(int i=1; i<=n; i++) {
		cin >> x >> y;
		A[i].x = square(x-x1) + square(y-y1);
		A[i].y = square(x-x2) + square(y-y2);
	}
	A[0].x = 0;
	sort(A+1, A+n+1);
	long long int mini = INT_MAX;

	for(int i = 0; i<=n; i++){
		long long int temp = 0;
		for(int j=i+1; j<=n; j++) {
			temp = max(temp, A[j].y);
		}
		mini = min(mini, A[i].x+temp);
	}
	cout << mini << endl;
	return 0;
}
