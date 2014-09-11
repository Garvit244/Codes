#include<stdio.h>
#define abs(x) ((x)<0 ? -(x) : (x))

int main()
{
	long long int T;
	scanf("%lld",&T);
	
	while(T--)
	{
		long long int x,y;
		scanf("%lld %lld",&x,&y);
		
		int flag = 0;
			
		if(x >= 0)
		{
			if(x == 0 && y%2 == 0)
				flag=1;
			else if(y >= -(x-1) && y <= (x+1) && x%2 == 1)
				flag = 1;
			else if(abs(y)%2 == 0)
			{
				if(y < 0 && x <= abs(y)+1)
					flag = 1;
				if(y >0 && x <=(y-1))
					flag = 1;
			}	
		}
		else
		{
			if(y >= x && y <= -x && abs(x)%2 == 0)
				flag = 1;
			else if(abs(y)%2 == 0 && abs(x) <= abs(y))
				flag = 1;
		}
		
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}