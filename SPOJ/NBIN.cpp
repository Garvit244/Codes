#include<cstdio>
#include<iostream>
using namespace std;
#define size 72
long long int a[100];
	
void pre_compute()
{
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	a[4] = 7;
	int i=4;
	while(a[i] <= 1000000000000000LL)
	{
		i++;
		a[i] = a[i-1]+a[i-2]+1;	
	}
	
}
int find(long long int n)
{
    int low=0,high=size,mid;
    mid = (low + high)>>1;
    while(true)
    {
        mid = (low + high)>>1;
        if(a[mid] < n)
        {
            if(a[mid + 1] >n)
                return mid;
            else
                low = mid;
        }
        else
        {
            if(a[mid - 1] < n)
                return mid - 1;
            else
                high = mid;
        }
    }
}

void find_term(long long int n)
{
	int b[80];
	int pos = find(n);
	int max_pos = pos+1;
	int i;
	for(i=1;i<80;i++)
		b[i]=0;
 	b[pos+1]=1;
    long long int diff = n - a[pos] - 1;
    while(diff>0)
    {
        pos = find(diff);
        b[pos+1] = 1;
        diff = diff - a[pos] - 1;
    }
    for(i=max_pos;i>=1;i--)
        if(b[i])
            printf("1");
        else
            printf("0");	
}

int main()
{	
	pre_compute();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		find_term(n);
		printf("\n");
	}
	return 0;
}