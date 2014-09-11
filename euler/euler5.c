#include<stdio.h>
int main()
{
	int n = 100;
	long long int result;
	result = n*(n+1)*((3*n) + 2)*(n-1);
	result=result/12;
	printf("%lld",result);
	return 0 ;	
}
