#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		float l[n];
		for(i=0;i<n;i++)
		{
			scanf("%f",&l[i]);
		}
		int sn,index;
		scanf("%d",&sn);
		char a[sn];
		float temp;
		
		for(i=0;i<sn;i++)
		{
			scanf("%s %f %d",&a[i],&temp,&index);
			float result;
		
			if(index > n)
			{
				printf("No\n");
			}
			else
			{
				result = temp+l[index-1];
			//	printf("%f\n",result);
				if(result > 90.00)
					printf("Yes\n");
				else
					printf("No\n");	
			}
		}
	}
	return 0;
}