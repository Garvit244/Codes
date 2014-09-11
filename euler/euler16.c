#include<stdio.h>
#include<math.h>
int main()
{
	int result=0;
	long int n;
	n=(long)pow(2,1000);
	printf("%d",n);
	while(n > 0)
	{
		result+=(int)(n%10);
		n/=10;
	}
	printf("%d",result);
	return 0;
}
