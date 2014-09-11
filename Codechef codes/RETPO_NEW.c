#include<cstdio>
#define abs(x)  ( (x<0) ? -x : x )

#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
	long long int T;
	scanint(T)
	while(T--)
	{
		long long int x,y,result;
		scanint(x);
		scanint(y);
		x = abs(x);
		y = abs(y);
		
		int flag=0;
		if(x<y)
		{
			y = (y-x);
			if(y%2 == 1)
				result = (x<<1)+((y>>1)<<2) +1 ;
			else
				result = (x<<1)+((y>>1)<<2);
		}
		else
		{
			x = (x-y);
			if(x == 0)
				result = (y<<1);
			else
			{
				if(x%2 == 1)
					result = (y<<1)+((x>>1)<<2)+3;
			
				else
					result = (y<<1)+((x>>1)<<2);
			}
		}
		printf("%lld\n",result);
	}
	return 0;
}
