#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string S) {
    int n = S.size();
    
    int l = 0, r = n-1;
    
    while(l < r) {
        if(S[l] != S[r])
            return 0;
            
           l++; r--;
    }
    return 1;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    string s; cin >> s;

    cout << isPalindrome(s) << endl;


	return 0;
}