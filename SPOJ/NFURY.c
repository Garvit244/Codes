#include<stdio.h>
#include<math.h>

int main()
{
	long long int T,i,j;

	int a[1002];
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	
	for(i=4;i<1001;i++)
	{
		long long int max =10000;
		int square_root = (int)sqrt(i);
		int remaining = i - (square_root*square_root);
		
		if(remaining == 0)
			a[i]=1;
		else
		{
			for(j=1;j<=i/2;j++)
			{
				if(a[j]+a[i-j] < max)
				{
					max = a[j]+a[i-j];
	//				printf("max: %lld",max);
				}
			}
			a[i] = max;
		}
	}
	
	scanf("%lld",&T);

	while(T--)
	{
		int A;
		scanf("%d",&A);
		
		printf("%d\n",a[A]);	
	}

	return 0;
}
