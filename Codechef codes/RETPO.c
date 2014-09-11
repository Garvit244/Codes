#include<stdio.h>
#define abs(x)  ( (x<0) ? -x : x )

int main()
{
	long long int T;
	scanf("%lld",&T);
	while(T--)
	{
		long long int x,y,result;
		scanf("%lld %lld",&x,&y);
		x = abs(x);
		y = abs(y);
		
		int flag=0;
		if (x == y)
			result = 2*x;
		else if(x<y)
		{
			y = (y-x);
			if(y%2 == 1)
				flag=1;
			result = (x<<1)+((y>>1)<<2);
			if(flag) 
				result +=1;
		}
		else
		{
			x = (x-y);
			if(x%2 == 1)
				flag=1;
			result = (y<<1)+((x>>1)<<2);
			if(flag)
				result += 3;
		}
		printf("%lld\n",result);
	}
	return 0;
}
