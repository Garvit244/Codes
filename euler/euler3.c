#include<stdio.h>
int main()
{
	long long int a =600851475143,i,largest;
	for(i=2;i*i<=a;i++)
	{
		while(a%i == 0)
		{
			a=a/i;
			largest=i;
		}
	}
	if(a > 1)
	{
		if(a > largest)
		 largest =a;
	}
	printf("%lld",largest);
	return 0;
}
