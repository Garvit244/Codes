#include <bits/stdc++.h>
using namespace std;

int findIndex(int index, vector<int> A, int start, int end) {
	if (index > A[A.size() -1]) return -1;

	int result= -1;
	while(start <= end) {
		int mid = (start+end) >> 1;
		if(A[mid] > index) {
			result = A[mid];
			end = mid-1;
		}
		else
			start = mid+1;
	}
	return result;
}

inline void fastRead_int(int *a) {
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33) {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

inline void fastRead_string(char *str) {
    register char c=0;
    register int i = 0;
    while (c < 33)
        c = getchar_unlocked();
    while (c > 65) {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }
    str[i] = '\0';
}

static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}


int main() {
	std::ios_base::sync_with_stdio(false);
	int T;
	fastRead_int(&T);

	for (int index=1; index<=T; ++index) {
		string s;
		getline(cin, s);
		s = trim(s);
		// cout << "String: " << s.length() << endl;
		int length =s.length();
		vector< vector<int> > mapList(26);
		for(int i=0; i<length; i++) {
			int index = s[i]-'a';
			mapList[index].push_back(i);
		}
		int query;
		fastRead_int(&query);
		printf("Case %d:\n", index);

		while(query != 0) {
			// cout << "Query: " << query <<endl;
			string q;
			getline(cin, q);
			q = trim(q);
			// cout << "Query String: " << q.length()<< endl;
			int qlen = q.length();
			if(qlen == 0) {
				printf("YES\n");
			}
			else if(length == 0) {
				printf("NO\n");
			}
			else {
				bool result = true;
				int lastIndex = -1;
				for(int i=0; i< qlen; ++i) {
					vector<int> asd = mapList[q[i]-'a'];
					if(asd.empty()) {
						result = false;
						break;
					}
					if(i == 0)
						lastIndex = asd[0];
					else {
						if(asd[0] > lastIndex)
							lastIndex = asd[0];
						else {
							lastIndex = findIndex(lastIndex, asd, 0, asd.size()-1);
						}
						if(lastIndex == -1) {
							result = false;
							break;
						}
					}
					// cout << "lastIndex: " << lastIndex << endl;
				}
				
				if(result)
					printf("YES\n");
				else
					printf("NO\n");
			}
			query = query - 1;
		}
	}
	return 0;
}