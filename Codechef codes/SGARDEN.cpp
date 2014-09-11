#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define mod 1000000007
long long int B[100001];

long long int find_lcm(long long int a, long long int b)
{
	long long int l ;
 	l = (((a*b)%mod) / ((__gcd(a,b)%mod)))%mod;
 	return l;
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		long long int N,i,index=1;
		scanf("%lld",&N);
		long long int A[N];

		for(i=1 ;i<=N; i++)
			scanf("%lld",&A[i]);

		
		for(i =1; i<=N; i++)
			B[i] = 0;

		long long int startindex = 1;
		long long int count = 0,result=1;
		i = 1;
		
		while(1)
		{
			B[i] = 1;
			if(A[i] == startindex)
			{
				
				count++;
				result = find_lcm(result%mod,count%mod);
				// printf("result: %lld\n",result );
				while(index <= N)
				{
					if(B[index] == 1)
						index++;
					else
						break;
				}

				startindex = index;

				if(startindex == N+1)
					break;
				else
					i = startindex;

				count = 0;
			}
			else
			{
				count++;
				B[i] = 1;
				i = A[i];
				// printf("count: %lld\n",count );
			}
		}

		printf("%lld\n",result%mod);
	}
	return 0;
}