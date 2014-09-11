#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	long long int T;
	scanf("%lld",&T);
	while(T--)
	{
		long long int N,i,j,k,l,len;
		scanf("%lld",&N);
		char a[130][2];
		char c,p;
		memset(a,0,sizeof(a));
		for(i=0;i<N;i++)
		{
			cin >> c;
			cin >> p;	
			a[c][0] = '1';
			a[c][1] = p;			
		}
		
		string str;
		cin >> str;	
		
		for(j=0;j<str.length();j++)
		{
			if(a[str[j]][0] == '1')
				str[j] = a[str[j]][1];
		}	
		
		j=0;
		string res;
		l=0;
		
		int flag = 0;
		
		while(str[j] == '0')		
			j++;
			
		if(j == str.length())
			printf("0\n");
		else
		{
			res=str.substr(j,str.length());
			len = res.length();
			
			for(k=0;k<len;k++)
			{
				if(res[k] == '.')
					flag = 1;
			}
			
			if(flag)
			{
				j = len-1;
				while(res[j] == '0')
					j--;
				if(res[j] == '.')
					j--;
				res = res.substr(0,j+1);	
			}
			
			if(res == "")
				printf("0\n");
			else
				cout << res << "\n";		
		}
	}
	return 0;
}
