#include <stdio.h>
#include <string.h>
#define size 10005
int min(int x, int y)
{
	return (x<y)?x:y;
}

int main() 
{
	int t, i, s1, s2, res;
    char a[size], b[size], ch;
	scanf("%d",&t);
	while(t--)
	{
		int count1[75]={0}, count2[75]={0};
		scanf("%s",a);
		scanf("%s",b);

		s1=strlen(a);
		s2=strlen(b);
 
		for(i=0; i<s1; i++)
			count1[a[i]-'0']++;
 
		for(i=0; i<s2; i++ )
			count2[b[i]-'0']++;
 
		res=0;
		for(i=0; i<75; i++)
			res+=min(count1[i],count2[i]);
 
		printf("%d\n",res);
	}
	return 0;
}