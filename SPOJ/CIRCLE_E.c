#include<stdio.h>
#include<math.h>

int main()
{
	long long int T;
	scanf("%lld",&T);
	while(T--)
	{
		double r1,r2,r3,r4;
		scanf("%lf %lf %lf",&r1,&r2,&r3);
		r1 = 1/r1;
		r2 = 1/r2;
		r3 = 1/r3;
		r4 = r1+r2+r3+2*sqrt(r1*r2+r1*r3+r2*r3);
		r4 = 1/r4;
		printf("%lf\n",r4);
	}
	return 0;
}
