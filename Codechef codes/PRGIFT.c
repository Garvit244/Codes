#include<stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		int n,k,i,count=0;
		scanf("%d %d",&n,&k);
		
		int a[n];
		
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
			
		for(i=0;i<n;i++)
		{
			if(a[i]%2 == 0)
			{
				count++; 	
			}
		}
		if(k == 0 && count == n)
			printf("NO\n");
		else if(count < k)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}