#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
typedef long long ll;


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int t; cin >> t;
    vector<char> s;
    unordered_map<char, int> mp;
    while(t--) {
    	mp.clear();
    	s.clear();
    	for(int i = 0; i < 4; i++) {
    		char x; cin >> x;
    		mp[x]++;
    	}
    	for(auto i: mp) {
    		s.emplace_back(i.first);
    	}

    	int n = mp.size();
    	switch(n) {
    	case 1:
    		cout << -1 << endl;
    		break;
    	case 2:
    		if(mp[s[0]] == mp[s[1]])
    			cout << 4 << endl;
    		else
    			cout << 6 << endl;
    		break;
    	case 3:
    		cout << 4 << endl;
    		break;
    	case 4:
    		cout << 4 << endl;
    	}

    }

	return 0;
}