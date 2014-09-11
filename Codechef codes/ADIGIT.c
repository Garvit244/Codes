#include<stdio.h>
long long int a[10][100009]={0};
int main()
{
	long long int n,m,i,j,temp;
	scanf("%lld %lld",&n,&m);
	char s[n];
	scanf("%s",s);
	for(i=0;i<n;i++)
	{
		for(j=0;j<10;j++)
		{
			temp = j-s[i]+48;
			if(temp < 0)
				temp =(-1)*temp;
			a[j][i+1]=a[j][i]+temp;
		}
	}
	long long int k;
	for(i=0;i<m;i++)
	{
		scanf("%lld",&k);
		printf("%lld\n",a[s[k-1]-48][k-1]);
	}
	return 0;
}