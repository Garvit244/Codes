#include<stdio.h>

long long int absolute(long long int a)
{
	if(a < 0)
	 	return -a;
	return a;	
}

int main()
{
	long long int T;
	scanf("%lld",&T);

	while(T--)
	{
		long long N,K,i,j;
		scanf("%lld %lld",&N,&K);
		long long int a[N];
		for(i=0;i<N;i++)
			scanf("%lld",&a[i]);
		
		long long int min,curr_min=4000000000,count;
		for(i=0;i<N-1;i++)
		{
			for(j=i+1;j<N;j++)
			{
				min = absolute(a[i]+a[j]-K);
				if(min < curr_min)
				{
					curr_min = min;
					count = 1;
				}
				else if(curr_min == min)
				{
	//				printf("i:%lld j:%lld\n",i,j);
					count++;
				}
			}
		}
		
		printf("%lld %lld\n",curr_min,count);	
	}
	return 0;
}
