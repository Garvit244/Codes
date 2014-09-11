#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n,i;
		scanf("%lld",&n);
		long long int A[n],B[n];
		
		for(i=0;i<n;i++)	
			scanf("%lld",&A[i]);
		
		
		long long int j=n-1,k=0;	
		sort(A,A+n);
		
		i=0;
		
		for(i=0;i<n/2;i++)
		{
			B[k] = A[i];
			k++;
			B[k] = A[j];
			k++;
			j--;		
		}
		
		if(n%2 != 0)
			B[k] = A[i];
			
		for(i=0;i<n;i++)	
			printf("%lld ",B[i]);
			
		printf("\n");
	}
	return 0;
}