#include<stdio.h>

int main()
{
	long int n,i;
	long long int temp=0;
	scanf("%ld",&n);
	long long int a[n];
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		temp+=a[i];
	//	i++;
	}
	for(i=1;i<=n;i++)
	{
		temp=temp-i;
	}			
	
	if(temp == 0)
		printf("YES");
	else
		printf("NO");
		
	return 0;
}