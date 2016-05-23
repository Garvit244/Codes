#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long int power(int x, int y) {
    int temp;
    if(y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return ((temp%MOD)*(temp%MOD))%MOD;
    else
        return (x*(temp%MOD)*(temp%MOD))%MOD;
}

int main() {
	int n, m;
	cin >> n >> m;
	set<pair<int, int> > x_y;
	set<pair<int, int> > rev_x_y;

	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		if(x != y) {
			x_y.insert(make_pair(x,y));
			rev_x_y.insert(make_pair(y,x));
		}
	}
	
	vector<pair<int, int> > v_intersection;
	set_intersection(x_y.begin(), x_y.end(),
                          rev_x_y.begin(), rev_x_y.end(),
                          std::back_inserter(v_intersection));

	int count = x_y.size() - (v_intersection.size()/2);
	cout << power(2,count) << endl;
	return 0;
}

/**
1 2 3 4 5
1 5
2 4
4 5
2 3

5 2 3 4 1
1 4 3 2 5
1 2 3 5 4
5 4 3 2 1
5 2 3 1 4
1 4 3 5 2
5 4 3 1 2

a b c d ab ac ad bc bd cd abc abd acd bcd abcd 
4
8

1 2
2 1

1 2
2 1

1 2
1 3
2 1
3 1

1 2 3
2 1 3
3 2 1
3 1 2

**/