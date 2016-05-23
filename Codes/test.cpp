#include <iostream>
# include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int a[100001],b[100001],c[200002],d[100001],t,n,m,k,i,j,x=0,y=0,sum=0;
	cin>>t;
	while(t!=0)
	{cin>>n>>k>>m;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	cin>>b[i];
	for(i=0;i<n;i++)
	d[i]=a[i]-b[i];
	sort(d,d+n);
	for(i=0;i<m+k;i++)
	cin>>c[i];
		sort(c,c+m+k);
	j=m+k-1;

	for(i=n-1;i>=0;i--)
	{
        while(d[i]-c[j]<0)
	       j--;
	
        if(((d[i] - c[j]) >= 0) && j>=0) {
            // cout << "d: " << d[i] << " c: " << c[j] << endl;
            d[i] -= c[j];
            j--;
        }
	}

	// for(j=0;j<n;j++)
 //    	cout<<d[j];
	
    for(j=0;j<n;j++)
	{sum+=d[j];
	}
	cout<<sum<<"\n";
	x=0;
	y=0;
	sum=0;
	t--;
	}
	return 0;
}