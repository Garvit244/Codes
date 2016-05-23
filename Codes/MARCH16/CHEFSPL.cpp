#include <bits/stdc++.h>
using namespace std;

/***
	  0 1 2 3 4 5 6
	  a b a b a b c
mid = 3 	
**/
int main() {
	std::ios_base::sync_with_stdio(false);
	int D;
	cin >> D;

	while(D--) {
		string str;
		cin >> str;

		bool flag = true;
		int start=0, end=str.length(), count=0;
		if(str.length() == 1) {
			flag = false;
		} else if(str.length()%2 == 0) {
			int mid = end/2;
			for(int i=0; i<mid; i++) {
				if(str[i] != str[mid+i]) {
					flag = false;
					break;
				}
			}
		} else {
			int mid = end/2;
			int start = 0, end = mid;

            cout << "mid " << mid << endl;
			while((start < mid) && (end != str.length())) {
				cout << "First half index start " << start << " end " << end << endl;
				if(str[start] != str[end]) {
                    cout << "First half start " << str[start] << " end " << str[end] << endl;
					end++;
					count++;
					if(count > 1) {
						flag = false;
						break;
					}
				} else {
					cout << "First half equal start " << start << " end " << end << endl;
					start++;
					end++;
				}
			}

			cout << "count From first half " << count << endl;
			if(count <= 1) {
				flag = true;
			} else {
				flag = true;
				count = 0;
				start = 0;
				mid = mid+1;
				end = mid;
				while((start < mid) && (end != str.length())) {
					if(str[start] != str[end]) {
						cout << "Second half start " << str[start] << " end " << str[end] << endl;
						start++;
						count++;
						if(count > 1) {
							flag = false;
							break;
						}
					} else {
					cout << "Second half equal start " << start << " end " << end << endl;
						start++;
						end++;
					}
				}
                cout << "count from Second half: " << count << endl;
			}
			if(count > 1) {
				flag = false;
			}
		}

		if(!flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}