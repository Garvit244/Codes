#include<stdio.h>
#include<math.h>
int prime(long n)
{
	int i,val=1;
	int a = sqrt(n)+1;
	for(i=2;i<a;i++)
		if(n%i == 0)
			val=0;
	return val;	
}

int main()
{
	long a=2,ans;
	int count=0;
	while(count <= 10001)
	{
		if(prime(a))
		{
			count++;
			ans=a;
		}
		a++;
	}
	printf("%ld",a);
	return 0;
}
