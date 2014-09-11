#include<stdio.h>

int main()
{
	int T;
	long long int A,B,max,min;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld %lld",&A,&B);
		if(A < B)
			min = B;
		else
			min = A;
			
		max = A+B;
		printf("%lld %lld\n",min,max);	
	}
	return 0;
}