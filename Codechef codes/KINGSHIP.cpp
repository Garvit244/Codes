#include<stdio.h>

int main()
{
	int T,i;
	long long int N,min=0,result;
	scanf("%d",&T);
	while(T--)
	{
		result=0;
		scanf("%lld",&N);
		long long int P[N];
		for(i=0;i<N;i++)
		{
			scanf("%lld",&P[i]);	
		}
		min = P[0];
		for(i=1;i<N;i++)
		{
			if(P[i] < min)
				min = P[i];	
		}	
		//printf("minimum: %lld",min);
		for(i=0;i<N;i++)
		{
			if(P[i] != min)
				result+=P[i]*min; 
		}
		printf("%lld\n",result);
	}
	return 0;
}