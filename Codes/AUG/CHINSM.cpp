
#include <utility>
#include <string>
#include <complex>
#include <iostream>
#include <vector>
using namespace std;

bool compare(const pair<int,int>&i, const pair<int,int>&j){
    if(i.first != j.first)
	    return i.first < j.first;
	else
		return i.second > j.second;
}

template <class T,class S> struct pair_equal_to : binary_function <T,pair<T,S>,bool> {
  bool operator() (const T& y, const pair<T,S>& x) const
    {
        return x.first==y;
  }
};

int main(){
	int N, K;
	cin >> N >> K;

	int A[N];
	for(int i=0; i<N; i++)
		cin >> A[i];

	int result = N;
	int last=0;
	vector< pair<int, int> > badPairs;

	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			if(A[i]%A[j] == K){
				vector< pair <int, int> >::iterator it;
				it  = find_if(badPairs.begin(),badPairs.end(),bind1st(pair_equal_to<int,int>(),j));

			if(it != badPairs.end()){
				if((it->first == j) && (it->second+1 == i))
					badPairs.erase(it);
			}
			badPairs.push_back(make_pair(j, i));
			}
		}
	}

	sort(badPairs.begin(), badPairs.end(), compare);

	// for(int i=0; i<badPairs.size(); i++){
	// 	cout << badPairs[i].second << " " << badPairs[i].first << endl; 
	// }

	int min=badPairs[0].second;
	if(badPairs.size() != 0){
		result += badPairs[0].first - badPairs[0].second -1;

		// cout << "stsrting result: " << result << endl;
		for(int i=1; i<badPairs.size(); i++){
			result += (badPairs[i].first- badPairs[i].second - 1);

			// cout << "result after first if : " << result << endl;
			if(badPairs[i-1].first < badPairs[i].second)
				result += badPairs[i].second - badPairs[i-1].first;
			last = i;
			if(badPairs[i].second < min)
				min = badPairs[i].second;
			// cout << "result after second if: " << result << endl;
		}

		int temp = N-badPairs[last].first -1;
		result += (temp*(temp+1))/2;

		if(min != 0)
			result += (min*(min+1))/2;
	}
	else
		result = (N*(N+1))/2;
	
	cout << result << endl;
	return 0;
}

/**
	a b c d e
	5 3 2 3 1
	ab ad
**/