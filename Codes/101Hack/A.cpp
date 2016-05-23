#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
	vector<pair<int, int> >wanbo;
	int beauty, difficult;

	for(int i=0; i<5; i++){
		cin >> beauty >> difficult;
		wanbo.push_back(make_pair(beauty, difficult));
	}

	sort(wanbo.begin(), wanbo.end());
	bool flag = true;
	int prevFirst = 0, prevSecond = 0;
	for(vector<pair<int, int> >::iterator it= wanbo.begin(); it != wanbo.end(); ++it){
		if(((it->first) <= prevFirst) && ((it->second) < prevSecond)){
			flag = false;
			break;
		}

		cout << prevFirst << " " << prevSecond << endl;
		prevFirst = it->first;
		prevSecond = it->second;
	}

	if(!flag)
		cout << "0" << endl;
	else
		cout << "1" << endl;
	return 0;
}