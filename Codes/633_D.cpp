#include <bits/stdc++.h>
using namespace std;

int a, b, c, n;
int tab[1010];
typedef pair <int, int> PII;

map <int, int> all, used, first;

int main()
{
	cin >> n;
	int result = 2;
	for (int i=1; i<=n; ++i) cin >> tab[i], all[tab[i]]++, first[tab[i]] = i;
	for (int i=1; i<=n; ++i)
	  for (int j=1; j<=n; ++j)
	  {
	  	if (i == j) continue;
	  	used.clear();
	  	a = tab[i], b = tab[j];
	  	if (first[a] != i) continue;
	  	used[a]++; used[b]++;
	  	int dl = 2;
	  	while (1)
	  	{
	  		++dl;
	  		c = a + b;
	  		used[c]++;
	  		if (used[c] > all[c]) break;
	  		result = max(result, dl);
	  		a = b;
	  		b = c;
	  	}
	  }
	cout << result;
}