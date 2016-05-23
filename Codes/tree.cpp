#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<(n);i++)
#define MAXN 100

 bool a[MAXN+2][MAXN+2];
 int main() 
 {
 	vector <string> clientCable;
 	vector <string> serverCable;
 	clientCable.push_back("NYN");
	clientCable.push_back("NNN");
 	clientCable.push_back("NYN");

 	serverCable.push_back("YN");
  	serverCable.push_back("YN");
 	serverCable.push_back("NY");

 	  int i,j,k,res;
  int n = clientCable.size(),m = serverCable[0].size();
  memset(a,0,sizeof(a));
  rep(i,n) rep(j,n) if(clientCable[i][j] == 'Y') a[i][j] = 1;
  rep(i,n) rep(j,m) if(serverCable[i][j] == 'Y') a[i][j+n] = 1;	
  rep(k,n) {
  	rep(i,n) {
  		rep(j,n) {
			 a[i][j] |= (a[i][k]&a[k][j]);//floyd warshall
  			 cout << a[i][j] << " ";
  			}
  			  		cout << endl;

  		}
  		cout << endl;
  	}

  res=n*m;
  rep(i,n) rep(j,m) {
   if(a[i][j+n] == 0) res--; //if no path to server, then no need to place a data gate
   else { //if we can find an intermediate node betwen the current node and server, we can use the gate for that node
    rep(k,n) if(k!=i && a[i][k] && a[k][j+n]) { res--; break;}
   }
  }
  return 0;
 }