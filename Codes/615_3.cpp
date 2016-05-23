#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<long long int, long long int> > v;
	long long int arr[N];

	for(int i=0; i<N; i++) {
			long long int x, y;
			cin >> x >> y;
			arr[i] = x;
			v.push_back(make_pair(y, x));
	}

	sort(v.begin(),v.end());
	sort(arr, arr+N);
	long long int result = 0, len=1;
    for(int i=1; i<N; i++) {
        if (arr[i] == arr[i-1]) 
        	len++; 
        else {
        	result += len*(len-1)/2; 
        	len = 1;
        }
    }

    result += len*(len-1) /2;
    len = 1; 
    long long int common = 1;

    for (int i=1; i<N; i++){
        if (v[i].first == v[i-1].first) {
            if (v[i].second == v[i-1].second) 
               	common++;
            else {
               	result -= common *(common-1)/2;
               	common = 1;
            }
            len++;
        } else {
        	result += len*(len-1)/2; 
        	result -= common*(common-1)/2; 
        	len=1;
        	common=1;
        }
    }

    result += len*(len-1)/2;
    result -= common*(common-1)/2;

	cout << result << endl;
	return 0;
}