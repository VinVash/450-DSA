#include <bits/stdc++.h>
using namespace std;

void permute(vector<string> &temp, string s, string ans) {
    if(s.size() == 0) {
        temp.push_back(ans);
        return;
    }
    
    for(int i = 0; i < s.size(); i++) {
        char ch = s[i];
        string left_substr = s.substr(0, i);
        string right_substr = s.substr(i+1);
        string rest = left_substr + right_substr;
        permute(temp, rest, ans+ch);
    }
}

vector<string>find_permutation(string S) {
    vector<string> temp;
    
    permute(temp, S, "");
    set<string> stringset(temp.begin(), temp.end());
    
    vector<string> res(stringset.begin(), stringset.end());
    
    return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s; cin >> s;

	vector<string> res = find_permutation(s);

	for(auto i: res)
		cout << i << " ";
	cout << endl;

	return 0;
}