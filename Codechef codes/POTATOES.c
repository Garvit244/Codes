#include<stdio.h>
#include<math.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,y,i,j,flag=0,result;
		scanf("%d %d",&x,&y);
		int sum = x+y;
		for(i=sum+1;i<2*sum;i++)
		{
			flag=0;
		//	printf("%d\n",i);
				for(j=2;j<=i/2;j++)
				{
					if(i%j == 0)
					{
						flag++;
						break;
					}	
				}

				if(flag==0)
				{
					result=i;	
					//printf("Result: %d\n",result);
					break;
				}
		}
		printf("%d\n",result-sum);
	}
	return 0;
}