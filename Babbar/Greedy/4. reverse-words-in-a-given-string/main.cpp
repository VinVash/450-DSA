#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) { 
    vector<string> res;
    int i = 0, j = 0;
    
    while(true) {
        i = s.find(".");
        cout << i << endl;
        if(i == -1 && s.size() > 0) {
        	res.push_back(s);
            break;
        }
        res.push_back(s.substr(j, i));
        cout << s << endl;
        cout << s.substr(j, i) << endl;
        s = s.substr(i+1);
        j = 0;
    }
    
    string ans = "";
    
    for(int i = res.size()-1; i >= 0; i--) {
        ans += res[i];
        ans += ".";
    }

    ans = ans.substr(0, ans.size()-1);
        
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	string s = "i.like.this.program.very.much";

	string res = reverseWords(s);
	cout << "\n\n\n\n\n\n";
	cout << res << endl;

	return 0;
}