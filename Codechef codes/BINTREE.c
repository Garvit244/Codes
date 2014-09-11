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
		long long int rn1l=n1/2,rn2r=(n2-1)/2,rn1r=(n1-1)/2,rn2l=n2/2;
		
		if((n1 == 1 && (n2 == 2 || n2 == 3)) || (n2 == 1 && (n1 == 2 || n1 == 3)))
			printf("1\n");
		else if((rn1l == rn2r || rn1r == rn2l) && ((n1%2 == 0 && (n2-1)%2 == 0) && n2 == n1+1))
		{
			printf("2\n");	
		}
		else
		{
			while(n1!=1)
			{
				if(n1%2 == 0)
				{
					n1=n1/2;
					cn1++;	
				}
				else
				{
					n1=(n1-1)/2;
					cn1++;
				}
			}
			
	//	printf("cn1: %lld\n",cn1);
		while(n2!=1)
		{
			if(n2%2 == 0)
			{
				n2=n2/2;
				cn2++;	
			}
			else
			{
				n2=(n2-1)/2;
				cn2++;
			}
		}
		
		printf("%lld\n",cn1+cn2);	
		}
	}
	return 0;
}