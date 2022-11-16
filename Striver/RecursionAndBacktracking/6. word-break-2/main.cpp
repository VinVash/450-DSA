#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string> > mp;
unordered_set<string> dict;

void printResult(vector<string> A) {
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << '\n';
}

vector<string> combine(vector<string> prev, string word) {
    for (int i = 0; i < prev.size(); i++) {
        prev[i] += " " + word;
    }
    return prev;
}

vector<string> wordBreakUtil(string s) {  
    if (mp.find(s) != mp.end())
        return mp[s];
    vector<string> res;
     
    // If the whole word is a dictionary word then directly append into
    // the result array for the string
    if (dict.find(s) != dict.end())
        res.push_back(s);
     
    // Loop to iterate over the substring
    for (int i = 1; i < s.length(); i++) {
        string word = s.substr(i);
         
        // If the substring is present into the dictionary then recurse         for other substring of the string
        if (dict.find(word) != dict.end()) {
            string rem = s.substr(0, i);
            vector<string> prev = combine(wordBreakUtil(rem), word);
            res.insert(res.end(), prev.begin(), prev.end());
        }
    }
     
    // Store the subproblem in the map declared at the top.
    mp[s] = res;
    return res;
}

vector<string> wordBreak(string &s, vector<string> &dictionary) {
    mp.clear();
    dict.clear();
    dict.insert(dictionary.begin(), dictionary.end());
    return wordBreakUtil(s);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}