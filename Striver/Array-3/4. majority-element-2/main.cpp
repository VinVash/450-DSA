class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> hmap;
        
        for(auto num: nums) {
            if(hmap[num] == 0)
                hmap[num] = 1;
            else
                hmap[num]++;
        }
        
        vector<int> ans;
        for(auto x: hmap) {
            if(x.second > n/3)
                ans.push_back(x.first);
        }
        
        return ans;
    }
};

// Success
// Details 
// Runtime: 38 ms, faster than 15.10% of C++ online submissions for Majority Element II.
// Memory Usage: 15.8 MB, less than 69.52% of C++ online submissions for Majority Element II.