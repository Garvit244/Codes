#include<stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		int N,i,count=0;
		scanf("%d",&N);
		
		int A[N];
		int B[100005]={0};
		
		for(i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			
			if(B[A[i]]!= 1)
			{
				B[A[i]] = 1;
				count++;	
			}		
		}
		
		printf("%d\n",count);
	}
	return 0;
}