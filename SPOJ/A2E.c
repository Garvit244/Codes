#include<stdio.h>

long long int gcd(long long int m,long long int n)
{
   		long long int temp = 0;
        if(m < n)
        {
                temp = m;
                m = n;
                n = temp;
        }
        while(n != 0)
        {
                temp = m % n;
                m = n;
                n = temp;
        }
        return m;
}

int main()
{
	long long int T;
	scanf("%lld",&T);
	while(T--)
	{
		long long int k,n,x1,y1,x2,y2,dx,dy,g;
		scanf("%lld %lld %lld %lld %lld %lld",&k,&n,&x1,&y1,&x2,&y2);
		g = gcd(k,n);
		dx = x1 > x2? x1 - x2 : x2 - x1;
		dy = y1 > y2? y1 - y2 : y2 - y1;
		if( g > 1)
		{
			if(dx%g || dy%g)
			{
				printf("NIE\n");
				continue;
			}
			
			dx /=g,dy /=g,k /=g,n/=g;
		}
		
		if(!(k&1) || !(n&1))
			printf("TAK\n");
		else if((dx&1) + (dy&1) == 1)
			printf("NIE\n");
		else	
			printf("TAK\n");
	}
	
	return 0;
}