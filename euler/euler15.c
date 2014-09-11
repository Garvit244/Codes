#include<stdio.h>
int main()
{
	long long int ans=1;
	int i;
	for(i=1;i<=20;i++)
	{
		ans=(ans*(4*i-2))/i;
	}
	printf("%lld",ans);
	return 0;
}
