#include<stdio.h>
#include<string.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int N;
		char S[50005];
		scanf("%d %s",&N,S);
		printf("%c\n",S[strlen(S)-1]);
	}
	return 0;
}