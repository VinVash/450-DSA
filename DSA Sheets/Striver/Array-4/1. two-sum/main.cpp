class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int n = nums[i];
            int complement = target - n;
            if (visited.count(complement)) { // find if it is present in map or not.
                return {visited[complement], i};
            }
            visited[n] = i;  // assume that each input would have exactly one solution
        }
        return {};
    }
};

// Success
// Details 
// Runtime: 6 ms, faster than 99.26% of C++ online submissions for Two Sum.
// Memory Usage: 10.9 MB, less than 31.86% of C++ online submissions for Two Sum.