#include<stdio.h>
#define size 55

int main()
{
	int N,Q,i;
	long long int K,count;
	scanf("%d",&N);
	long long int A[N],q;
	for(i=0;i<N;i++)
	{
		scanf("%lld",&A[i]);
	}
/*	printf("%ld",max);
	for(i=1;i<=max;i++)
	{
		printf("%ld",A[i]);	
	}*/
	scanf("%d",&Q);
	while(Q--)
	{
		count = 0;
		int j,l;
		scanf("%lld",&K);
		for(i=0;i<N;i++)
		{
			for(j=i;j<N;j++)
			{
				q = A[i];
				l = i;
				while(l<=j)
				{
					if(q > A[l])
						q = A[l];
					l++;
				}
					if(q == K)
						count++;
			}
		}			
		printf("%lld\n",count);
	}
	return 0;
}