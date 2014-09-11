#include<stdio.h>

int main()
{
	long long int T;
	scanf("%lld",&T);
	
	while(T--)
	{
		long long int N,count=0,i;
		scanf("%lld",&N);
		
		char S[N];
		scanf("%s",S);
		for(i=0;i<N;i++)
			if(S[i] == '1')
				count++;

		printf("%lld\n",(count*(count+1)/2));
	}
	return 0;
}
