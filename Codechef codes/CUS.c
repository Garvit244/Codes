#include<stdio.h>
#include<string.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int f,e,l;
		scanf("%d",&f);
		char fs[f][2];
		
		int i;
		for(i=0;i<f;i++)
			scanf("%s &s",&fs[i][0],&fs[i][1]);
		scanf("%d",&e);
		
		char es[e][2];
		for(i=0;i<e;i++)
			scanf("%s &s",&es[i][0],&es[i][1]);
			
		scanf("%d",&l);
		for(i=0;i<l;i++)
		{
			char s[l][2];
			scanf("%s %s",&s[l][0],&s[l][1]);
			int j,k,flag=0;
			int t=f;
			for(j=0;j<t;j++)
			{
				if(strcmp(s[l][0],fs[j][0]) == 0)
				{
					printf("Friends\n");
					flag=1;
				}
				else
				{
					fs[t++][0]=s[l][0];
					fs[t++][1]=s[l][1];	
				}
			}
			for(k=0;k<e;k++)
			{
				if(strcmp(s[l][0],es[i][0]) == 0)
				{
					printf("Enemy\n");
					flag=1;
				}
			}
			if(!flag)
				printf("Unidefined\n");
		}
	}
}