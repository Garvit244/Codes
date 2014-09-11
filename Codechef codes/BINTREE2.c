#include<stdio.h>

int main()
{
	long long int N;
	scanf("%lld",&N);
	while(N--)
	{
		long long int n1,n2;
		scanf("%lld %lld",&n1,&n2);
		long long int cn1=0,cn2=0;
	//	printf("%lld %lld\n",cn1,cn2);
		
		while(n1 != n2)
		{
			if(n1 > n2)
			{
				n1=n1/2;
				cn1++;
			}
			else
			{
				n2=n2/2;
				cn2++;
			}
		}
		
		printf("%lld\n",cn1+cn2);
	}
	return 0;
}