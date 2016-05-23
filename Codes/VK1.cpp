#include <bits/stdc++.h>
using namespace std;

int main() {
	long int N, ans = 0;
	scanf("%ld", &N);
	ans = (N/3)*2 + (N%3 > 0 ? 1 : 0);
	printf("%ld", ans);
	return 0;
}
