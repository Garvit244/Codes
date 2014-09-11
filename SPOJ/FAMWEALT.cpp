#include<iostream>
#include<cstdio>
using namespace std;

#define size 131072
double *tree;

void up(int x,double w)
{
	tree[x] = w;
	if(x==1)
		return;
	int parent = x>>1;
	if(x&1 && parent&1)
		up(parent,4*w);
	else	
		up(parent,2*w);	
}

void down(int x,double w)
{
	if(x >= size)
		return;
	tree[x] = w;
	
	int left_child = x<<1;
	double w1 = w/2;
	
	if(x&1)
	{
		down(left_child,w1);
		down(left_child+1,w1/2);	
	}
	else
	{
		down(left_child,w1);
		down(left_child+1,w1);	
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y,w,i;
		scanf("%i %i %i",&x,&y,&w);
		tree = new double[size];
		for(i=0;i<size;i++)
			tree[i]=0;	
			
		up(x,w);
		down(1,tree[1]);
		
		printf("%.6lf\n", tree[y]);
		delete[] tree;	
	}
	return 0;
}