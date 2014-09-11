#include<stdio.h>

int main()
{
	long long int T;
	scanf("%lld",&T);
	
	while(T--)
	{
		long long int W,B;
		scanf("%lld %lld",&W,&B);
	
		if(B%2 == 0)	
			printf("0.000000\n");
		else
			printf("1.000000\n");
	}
	return 0;
}
