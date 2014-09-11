#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n, i, j;
		scanf("%lld",&n);
		
		long long int a[n],temp,count=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
			
		for(i=1;i< n;i++)
    	{
        	 for(j=0;j< n-1;j++)
         		if(a[j]>a[j+1])
               	{
               		temp=a[j];
               		a[j]=a[j+1];
               		a[j+1]=temp;
               	}
    	}
    	
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[j]!= a[i])
					count++;
			}
		}
		
		printf("%lld\n",count);
	}
	return 0;
}