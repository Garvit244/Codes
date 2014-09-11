#include<stdio.h>

int main()
{
	long long int n;
	scanf("%lld",&n);
	
	if (n > 0 && !(n & (n-1)))
		printf("TAK\n");
	else
		printf("NIE\n");
	
	return 0;	
}