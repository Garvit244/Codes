#include<stdio.h>
int main()
{
	long long int a=1,b=2,sum=0;
	long long int even=2;
	while((a+b) < 4000000)
	{
		sum = a+b;
		a=b;
		b=sum;
		if(sum%2 == 0)
			even+=sum;
	}
	printf("%lld",even);
	return 0;
}
