#include<stdio.h>

int main()
{
	int t,n,m,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d\n",&n,&m);
		int a[n][m];
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf(" %c",&a[i][j]);
			}	
		}
		for(i=0;i<n;i++)
		{
			for(j=m-1;j>=0;j--)
			{
				printf("%c",a[i][j]);
			}	
			printf("\n");
		}	
	}
	return 0;
}