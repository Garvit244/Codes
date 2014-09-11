#include<stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		int ni;
		scanf("%d",&ni);
		
		if(ni%2 == 0)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}