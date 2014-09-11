#include<stdio.h>

int main()
{
	long long int T;
	scanf("%lld",&T);
	while(T--)
	{
		long long int N;
		scanf("%lld",&N);
		
		if(N%2 == 0)
			printf("Thankyou Shaktiman\n");
		else
			printf("Sorry Shaktiman\n");
	}
	return 0;
}
