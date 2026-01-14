class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for(auto num: nums) {
            if(count == 0) {
                candidate = num;
            }
            
            if(num == candidate)
                count += 1;
            else
                count -= 1;
        }
        
        return candidate;
    }
};

// Boyer-Moore Voting Algorithm
// Success
// Details 
// Runtime: 20 ms, faster than 92.13% of C++ online submissions for Majority Element.
// Memory Usage: 19.3 MB, less than 99.95% of C++ online submissions for Majority Element.