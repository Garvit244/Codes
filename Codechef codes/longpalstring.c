#include<stdio.h>
#include<string.h>
#define size 10000

int longpalstr(char * str)
{
	int len=strlen(str);
	int result=1;
	int low,high,i;
		
	for(i=0;i<len;i++)
	{
		low = i-1;
		high = i;
		while(low >=0 && high <len && str[low] == str[high])
		{
			if(high-low+1 > result)
			{
				result = high-low+1;
			}
			low=low-1;
			high=high+1;
		}
		
		low = i-1;
		high = i+1;
		while(low >=0 && high < len && str[low] == str[high])
		{			
			if(high-low+1 > result)
			{
				result = high-low+1;
			}
			low=low-1;
			high=high+1;	
		}
	}
	
	return result;
}

int main()
{
	char str[size];
	scanf("%s",str);
	int result=longpalstr(str);
	printf("Longest Palindrome String is: %d\n",result);
	
	return 0;
}