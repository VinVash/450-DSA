#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    while(start <= end) {
        if(s.at(start++) != s.at(end--))
            return false;
    }
    
    return true;
}

void solveRec(string s, int index, vector<string> &path, vector<vector<string>> &res) {
    if(index == s.size()) {
        res.push_back(path);
        return;
    }
    
    for(int i = index; i < s.size(); i++) {
        if(isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));
            solveRec(s, i+1, path, res);
            path.pop_back(); // backtracking step.
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans; // declared the ans variable.
    
    vector<string> temp; // which stores different strings on every recursion.
    
    solveRec(s, 0, temp, ans);
    
    return ans;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    return 0;
}
