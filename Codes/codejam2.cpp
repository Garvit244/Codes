#include <bits/stdc++.h>
using namespace std;
#define L long long
vector<L> v;
L M=1e9+7;
int main()
{
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        string a,b;
        cin>>a>>b;
        int d=0;
        int n=a.length();
        int i;
        for(i=0;i<n;i++)
        {
            if(a[i]=='?'&&b[i]=='?')
            {
                a[i]='0';b[i]='0';
            }
            else if(a[i]=='?')
            {
                a[i]=b[i];
            }
            else if(b[i]=='?')
            {
                b[i]=a[i];
            }
            else if(a[i]!=b[i])
            {
                if(a[i]>b[i])
                    d=1;
                else
                    d=-1;
                break;
            }
        }
        if(d!=0)
        {
            if(d==1)
            {
                for(i++;i<n;i++)
                {
                    if(a[i]=='?'&&b[i]=='?')
                    {
                        a[i]='0';
                        b[i]='9';
                    }
                    else if(a[i]=='?')
                    {
                        a[i]='0';
                    }
                    else if(b[i]=='?')
                    {
                        b[i]='9';
                    }
                }
            }
            else
            {
                for(i++;i<n;i++)
                {
                    if(a[i]=='?'&&b[i]=='?')
                    {
                        a[i]='9';
                        b[i]='0';
                    }
                    else if(a[i]=='?')
                    {
                        a[i]='9';
                    }
                    else if(b[i]=='?')
                    {
                        b[i]='0';
                    }
                }
            }
        }
        cout<<"Case #"<<k<<": "<<a<<" "<<b<<endl;
    }
}
