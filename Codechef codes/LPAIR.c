#include<stdio.h>

int main()
{
	long int N,i,j;
	scanf("%ld",&N);
	long long int A[N][2],temp0,temp1,count=0,result=0;
	for(i=0;i<N;i++)
	{
		scanf("%lld %lld",&A[i][0],&A[i][1]);
	}
	
	for(i=N-2;i>=0;i--)
    {
    	for(j=0;j<=i;j++)
         	if(A[j][0] > A[j+1][0])
         	{
               temp0=A[j][0];
               temp1=A[j][1];
               A[j][0]=A[j+1][0];
               A[j][1]=A[j+1][1];
               A[j+1][0]=temp0;
               A[j+1][1]=temp1;
            }
    }
    long long int l=A[0][0],d=A[0][1];
    //printf("%lld %lld\n",l,d);
    for(i=1;i<N;i++)
    {
	    if(A[i][0] > l && A[i][1] < d)	
	    {
    		count++;	
    	}
   		l = A[i][0];
	    d = A[i][1];
    //	printf("count: %lld\n",count);
    	result+=count;
    }
    printf("%lld\n",result);
    return 0;
}