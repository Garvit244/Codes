#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>
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
	long long int value;
	long long int freq;
};
string result;
int curr_index;
Node frequency[1000004];
map<long long int, long long int> count_eq;
int A[1000004];

long long int getGreaterThanK(long long int val){
	long long int sum=0;

	for(int i= curr_index-1; i>=0; i--){
		if(frequency[i].value <= val)
			return sum;
		sum += frequency[i].freq;
	}
	return sum;
}

long long int getLessThanK(long long int val){
	long long int sum=0;

	for(int i= 0; i<curr_index; i++){
		if(frequency[i].value >= val)
			return sum;
		sum += frequency[i].freq;
	}
	return sum;
}

int main(){
	int N, M;
	scanint(N);
	scanint(M);

	for(int i=0; i<N; i++)
		scanint(A[i]);

	int max_till_now;

	// cout << frequency[56].value << " " << frequency[56].freq << endl;
	for(int i=0; i<N; i++){
		max_till_now =  A[i];
		for(int j=i; j<N; j++){
			max_till_now = max(max_till_now, A[j]);
			count_eq[max_till_now]++;
		}
	}

	for(map<long long int , long long int>::iterator it=count_eq.begin(); it!=count_eq.end(); ++it){
		frequency[curr_index].value = it->first;
		frequency[curr_index].freq = it->second;

		curr_index++;
	}

	for(int i=0; i<curr_index; i++){
		cout << frequency[i].value << " " << frequency[i].freq << endl;
	}
	
	while(M--){
		char op, start;
		long long int val;
		long long int total =0;
		cin >> op;
		cin >> val;
		cin >> start;
		if(op == '<'){
			total = 0;
			// cout << "total: " << total << endl;
		}
		else if(op == '>'){
			total = 0;
			// cout << "total: " << total << endl;
		}
		else if(op == '='){
			total = count_eq[val];
		}

		if(total == 0){
			if(start == 'D') {
				result +="C";
			} else if(start == 'C') {
				result +="D";
			}
		} else {
			if(start == 'D') {
				if(total & 1) {
					result += "D";
				} else if(!(total & 1)) {
					result += "C";
				}
			} else if(start == 'C') {
				if(total & 1) {
					result += "C";
				} else if(!(total & 1)) {
					result += "D";
				}
			}
		}
	}
	cout << result << endl;
	return 0;
}