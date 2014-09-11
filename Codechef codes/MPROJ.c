#include<stdio.h>
long long int size[1000000],ripfactor[1000000];
int main()
{
	int t;
	scanf("%d",&t);
	long long int N,i,acut,rescount,resacut;
	long long int minsize,minripefactor,min;
	long long int count;
	
	while(t--)
	{
		count=0;
		scanf("%lld %lld %lld",&N,&minsize,&minripefactor);
			
		for(i=0;i<N;i++)
		{
			scanf("%lld %lld",&size[i],&ripfactor[i]);
			if((size[i] > minsize)||(ripfactor[i] > minripefactor))
			{
				count++;	
			}
		}
		scanf("%lld",&acut);
		
		rescount=count;
		resacut=acut;
		
		if(count < acut)
		{
			min = count;
		}
		else
		{
			min = acut;	
		}
		
		for(i=min;i>=1;i--)
		{
			if(acut%i == 0 && count%i == 0)
			{
				rescount = count/i;
				resacut = acut/i;
				break;
			}
		}
		
		//if(rescount == 0 || resacut == 0)
		//	printf("0\n");
		if(rescount == resacut)
			printf("1\n");
		else
			printf("%lld/%lld\n",rescount,resacut);
	}
	return 0;
}