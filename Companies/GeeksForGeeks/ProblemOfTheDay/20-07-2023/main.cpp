#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

// Non Repeating Character
/* 	Given a string S consisting of lowercase Latin Letters.
	Return the first non-repeating character in S. 
	If there is no non-repeating character, return '$'. */

char nonrepeatingCharacter(string S) {
	
   unordered_map<char, int> mp;
   for(auto ch: S) {
       mp[ch]++;
   }
   
   for(int i = 0; i < S.size(); i++) {
       if(mp[S[i]] == 1) {
           return S[i];
           break;
       }
   }
   
   return '$';
   
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}