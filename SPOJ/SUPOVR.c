#include<stdio.h>

int main()
{
	int wicket=0,strike=1;
	int non_striker =2;
	char run;
	int a[4]={0},i=0;
	
	while(i < 6)
	{
		scanf("%s",&run);
		
		if(wicket == 2)
			i = 5;
		else if(run == 'O' || run == 'o')
		{
			wicket +=1;
			strike = 3;
		}
		else if(run == 'W' || run == 'w' || run == 'N' || run == 'n')
			continue;
		else
		{
			a[strike] += (run-48);
			if((run-48)%2 == 1)
			{
				int temp = strike;
				strike = non_striker ;
				non_striker = temp;
				//printf("\nstrike:%d non_strike: %d A[0]:%d A[1]: %d ",strike,non_striker,a[1],a[2]);
			}
		}
		i++;
	}	
	
	for (i=1;i<4;i++)
		printf("%d\n",a[i]);
	
	return 0;
}