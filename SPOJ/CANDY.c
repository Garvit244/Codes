#include<stdio.h>

int main()
{	
	long long int n;
	
	while(scanf("%lld", &n) == 1 && n > 0)
	{
		long long int i,sum=0,diff,div,count=0;
	
		long long int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			sum += a[i];
		}	
		
		if(sum%n == 0)
		{
			div = sum/n;
			for(i=0;i<n;i++)
			{
				diff = div - a[i];
				if(diff > 0)
					count +=diff;
			}	
			printf("%lld\n",count);	
		}
		else
			printf("-1\n");
	}
	
	return 0;
}