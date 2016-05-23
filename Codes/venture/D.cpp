#include <bits/stdc++.h>
using namespace std;

int a[2010];
map<int, int> mp;
map<int, int>::iterator it;
int s[10010];
vector<pair<int, int> > v;
vector<pair<int, int> >::iterator low;
int ans[10010];

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first<b.first;
}

int main() {
	int i, j, n, k;
	cin >> n;

	for(i=0; i<n; ++i)
		scanf("%d", a+i);
	sort(a, a+n);

	for(i=0; i<n; ++i)
		for(j=i+1; j<n; ++j)
			mp[a[j]-a[i]]++;

	for(it=mp.begin(); it!=mp.end(); ++it)
		v.push_back(make_pair(it->first, it->second));
	
	sort(v.begin(), v.end(), cmp);
	for(i=0; i<(int)v.size(); ++i)
		for(j=i; j<(int)v.size(); ++j)
		{
			ans[v[i].first+v[j].first]+=(v[i].second)*(v[j].second);
		}

	s[0]=ans[0];
	for(i=1; i<=10000; ++i)
		s[i]=s[i-1]+ans[i];
	int qq=0;
	for(i=0; i<(int)v.size(); ++i)
		qq+=s[v[i].first-1];
	double fin=(double) qq;

	for(i=0; i<3; ++i)
		fin/=(double) n;
	printf("%.10f\n", fin);
	return 0;
}