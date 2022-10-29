class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int tortoise = nums[0];
        int hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[hare];
            hare = nums[hare];
            
            // hare = nums[nums[hare]]; // or do this
        } while(tortoise != hare);
        
        tortoise = nums[0];
        while(tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
    }
};

// Success
// Details 
// Runtime: 118 ms, faster than 94.76% of C++ online submissions for Find the Duplicate Number.
// Memory Usage: 61.1 MB, less than 99.43% of C++ online submissions for Find the Duplicate Number.