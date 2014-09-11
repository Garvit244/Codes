#include<stdio.h>

int numberoftwo(int n)
{
	if(n < 2)
		return 0;
	
	int result=0;
	int MSB,remain;
	int temp1=1,temp2=10;
	
	while(temp2 < n)
	{
		temp1 *= 10;
		temp2 *= 10;
	}
	
	MSB = n/temp1;
	remain = n%temp1;
	
	if(MSB > 2)
	{
		result=result+temp1;
	}
	else if(MSB == 2)
	{
		result +=remain+1;
	}
	
	result+=MSB*numberoftwo(temp1);
	result+=numberoftwo(remain);
	
	return result;
}

int main()
{
	int N;
	scanf("%d",&N);
	int result=numberoftwo(N);
	printf("Number of 2's between 0 and n are: %d\n",result);
	
	return 0;
}