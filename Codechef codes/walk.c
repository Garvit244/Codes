#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,i;
		scanf("%lld",&n);
		
		long long int w[n];	
		for(i=0;i<n;i++)
			scanf("%lld",&w[i]);
		
		long long result=0;
		for(i=n-1;i>=0;i--)
		{
			if(result >= w[i])
				result++;
			else
				result = w[i];
		}	
		
		printf("%lld\n",result);
	}
	return 0;
}