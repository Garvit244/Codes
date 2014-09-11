#include<stdio.h>
int main()
{
	int length=0,result=0;
	long num =1000000;
	long a[1000001];
	long i,j;
	for(j=1;j<num+1;j++)
		a[j]=1;
	for(i=2;i<num;i++)
	{
		long n=i;
		int count=0;
		while(n!=1 && n >=i)
		{
			count++;
			if(n%2 == 0)
				n = n/2;
			else
				n = 3*n+1;
		}
		a[i]=count+a[n];
		if(a[i] > length)
		{
			length=a[i];
			result = i;
		}
	}
	printf("%ld",result);
	return 0;
}
