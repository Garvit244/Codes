#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	string S;
	cin >> S;
	long long int len = S.size();
	int start = S[0]-48;
	int last = S[len-1]-48;
	long long int arr[10]={0};
	long long int i,count=0;
	
	for(i=0;i<len;i++)
		arr[S[i]-48] = i;

	for(i=0;i<len;i++)
	{
		if(i != arr[i])
			count++;
		if(last == (S[i]-48))
			break;
		else
		{
			count++;
			i = arr[i];
		}
	}

	printf("%lld\n",count);
	return 0;
}
