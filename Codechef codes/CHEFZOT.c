#include<stdio.h>

int main()
{
	long long int N,i,len=0,product=1;
	scanf("%lld",&N);
	long long int A[N];
	long long int max=0;

	for(i=0;i<N;i++)
		scanf("%lld",&A[i]);

	for(i=0;i<N;i++)
	{
		product *=A[i];
		len++;
		if(product == 0)
		{
	//		printf("%lld ",len);
			if(len > max)
				max = len - 1;
			product = 1;
			len = 0;
		}
	}		
	
	if(len > max)
		max = len;
	printf("%lld\n",max);
	return 0;
}
