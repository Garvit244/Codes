#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int N,K,S,i,j;
		scanf("%lld %lld %lld",&N,&K,&S);
		long long int A[N],B[N];
	
		for(i=0;i<N;i++)
		{
				scanf("%lld",&A[i]);
				B[i]=A[i];
		}
		
		sort(B,B+N);
		
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(A[j] == B[i])
				{
					printf("%lld ",j+1);
					A[j] = -1;
				}
			}
		}
		printf("\n");
	}
	return 0;
}