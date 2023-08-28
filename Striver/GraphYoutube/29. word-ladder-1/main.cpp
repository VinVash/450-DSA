#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Time complexity: O(N * word.length * 26 * logN)

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
	
	queue<pair<string, int>> q;
	q.push({ startWord, 1 });
	unordered_set<string> st(wordList.begin(), wordList.end());
	st.erase(startWord);

	while(!q.empty()) {
		string word = q.front().first;
		int steps = q.front().second;
		q.pop();

		if(word == targetWord) return steps;

		for(int i = 0; i < word.size(); i++) {
			char original = word[i];

			for(char ch = 'a'; ch <= 'z'; ch++) {
				word[i] = ch;

				if(st.find(word) != st.end()) {
					st.erase(word);
					q.push({ word, steps+1 });
				}
			}
			word[i] = original;
		}
	}

	return 0;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}