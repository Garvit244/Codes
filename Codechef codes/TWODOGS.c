#include<stdio.h>
long long int T[500000],r[1000000];
long long int min=1000000;
int main()
{
	long long int N,K,i;
	scanf("%lld %lld",&N,&K);
	for(i=1;i<=N;i++)
		scanf("%lld",&T[i]);
	for(i=1;i<=1000000;i++)
		r[i]=1000000;
	
	for(i=1;i<=N;i++)
	{
		if(i<=N/2)
		{
			if(r[T[i]] > i)
				r[T[i]]=i;
		}
		if(i > N/2)
		{
				if(r[T[i]] > N-i+1)
				 r[T[i]]=N-i+1;
		}
	}
	for(i=1;i<=K/2;i++)
	{
		if(r[i]!=1000000)
		{
			if(i!=K-i)
			{
				if(r[i] > r[K-i] && r[i] < min)
					min = r[i];
				if(r[i] < r[K-i] && r[K-i] < min)
					min = r[K-i];
				if(r[i] == r[K-i] && r[i] < min)
					min = r[i];
			}
		}
	}
	if(min != 1000000)
		printf("%lld\n",min);
	else
		printf("-1\n");
	return 0;
}