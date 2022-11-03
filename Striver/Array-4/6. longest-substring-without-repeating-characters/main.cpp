class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        set<char> hash;
        int i = 0, j = 0;
        
        int maxi = 0;
        while(i < n && j < n) {
            if(hash.count(s[j])) {
                hash.erase(s[i]);
                i++;
            } else {
                hash.insert(s[j]);
                j = j + 1;
                maxi = max(maxi, j-i);
            }
        }
        
        return maxi;
    }
};

// Success
// Details 
// Runtime: 75 ms, faster than 19.96% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 13.3 MB, less than 18.33% of C++ online submissions for Longest Substring Without Repeating Characters.