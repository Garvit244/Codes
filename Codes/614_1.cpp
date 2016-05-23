#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s,ans;
	bool flag,flag2;
	ans="1";
	cin >> n;
	int tmp=0;
	for(int i=0;i<n;++i){
		cin >> s;
		bool flag=false;
		int cnt=0,cnt2=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='1') ++cnt;
			if(s[i]!='1'&&s[i]!='0') flag=true;
			if(s[i]=='0') ++cnt2;
		}
		if(cnt>=2) flag=true;
		if(flag==true){
			ans=s;
			flag2=true;
		}
		if(flag==false){
			tmp+=cnt2;
		}
		if(s=="0"){
			cout << 0;
			return 0;
		}
	}
	if(!flag2){
		cout << 1;
		for(int i=0;i<tmp;++i) cout << 0;
			return 0;
	}
	for(int i=0;i<ans.size();++i) cout << ans[i];
	for(int i=0;i<tmp;++i) cout << 0;
	cout << endl;
}