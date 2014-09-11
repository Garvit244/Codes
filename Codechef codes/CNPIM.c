#include<stdio.h>

int main()
{
    int t,n,nsot,i,j,l;
    int arr[2000],k;
    unsigned long long  sum1=0,sum2=0,sum=0;
    scanf("%d",&t);
    while(t--)
    {
        sum1=0;
        sum2=0;
        scanf("%d",&n);
        nsot=n/2;
        for(i=1;i<=nsot;i++)
        {
            arr[i]=i*(n-i);
            sum1=0;
                for(k=1;k<arr[i];k++)
                {
                    sum1=sum1+((arr[i] - 1) / k);
                }
            
			if(i==(n-i))
            	sum=sum1;
            else
            	sum=0;
         
            sum2=sum1+sum2;
        }
        printf("%llu\n",(2*sum2)-sum);
    }
}