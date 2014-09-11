#include<stdio.h>
#include<math.h>
int divisor(int num)
{
		int i,res=0;
		int a = sqrt(num) + 1;
		for(i=1;i<a;i++)
		{
			if(num%i == 0)
				res+=2;
		}
		if(i*i == num)
			res--;
		return res;
}
int main()
{
	int num=0,j=1;;
	while(divisor(num) < 500)
	{
		num+=j;
		j++;
	}
	printf("%d",num);
}
