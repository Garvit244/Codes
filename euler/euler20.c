#include<stdio.h>
long long int fact(int n)
{
	if(n==0) 
		return 1;
	else
	return (n*fact(n-1));
}

int sum(int n)
{
	int s=0;
	while(n)
	{
		s=s+n%10;
	n=n/10;
	}
	return s;
}

int main()
{
	int N;
	printf("%d\n", sum(fact(100)));
}
