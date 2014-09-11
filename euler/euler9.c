#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
		for(a=1;a<1000/3;a++)
		{
			for(b=a;b<500;b++)
			{
				c=1000-a-b;
				if(((pow(a,2) + pow(b,2)) == (pow(c,2))))
					printf("%d\n",a*b*c);
			}
		}
	return 0;
}
