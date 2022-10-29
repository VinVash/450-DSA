class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int max_sum = nums[0];
        int curr = nums[0];
        for(int i = 1; i < n; i++) {
            if(curr < 0)
                curr = 0;
            curr += nums[i];
            if(curr > max_sum)
                max_sum = curr;
            
        }
        
        return max_sum;
        
    }
};

// Success
// Details 
// Runtime: 127 ms, faster than 87.68% of C++ online submissions for Maximum Subarray.
// Memory Usage: 67.7 MB, less than 90.59% of C++ online submissions for Maximum Subarray.