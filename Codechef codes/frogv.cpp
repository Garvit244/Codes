#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define gc getchar_unlocked

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

struct Node
{
	long long int val;
	long long int connected;
};

bool compare(Node a, Node b)
{
	return a.val <= b.val;
}

long long int binarysearch(long long int first, long long int last, long long int search, Node array[100000])
{
	long long int middle = (first+last)/2;

	while( first <= last )
   	{
      if ( array[middle].val < search )
         first = middle + 1;    
      else if ( array[middle].val == search ) 
      {
         return middle;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   return -1;
}

int main()
{
	int N,K,P,i;
	scanint(N);
	scanint(K);
	scanint(P);

	long long int A[N];
	Node B[100000];

	for(i=0 ;i<N ;i++)
	{
		scanf("%lld ",&A[i]);
		B[i].val = A[i];
	}

	sort(B, B+N, compare);

	B[0].connected = 0;

	for(i=1 ;i<N ; i++)
	{
		if((B[i].val - B[i-1].val) <= K)
			B[i].connected = B[i-1].connected;
		else	
			B[i].connected = i;
	}

	for(i=0 ;i<P; i++)
	{
		int a,b;
		scanint(a);
		scanint(b);

		long long int startval = A[a-1];
		long long int endval = A[b-1];

		// printf("%lld %lld\n",startval,endval);
		if(startval == endval)
			printf("Yes\n");
		else
		{
			long long int startindex = binarysearch(0,N-1,startval,B);	
			long long int endindex = binarysearch(0,N-1,endval,B);

			// printf("startindex = %lld endindex = %lld\n",startindex,endindex);
			if(B[startindex].connected == B[endindex].connected)
				printf("Yes\n");
			else
				printf("No\n");	
		}
	}
	return 0;
}