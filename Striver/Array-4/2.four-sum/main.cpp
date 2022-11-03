class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long long n = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for(long long i = 0; i < n; i++) {
            for(long long j = i+1; j < n; j++) {
                long long newtarget = target - nums[i] - nums[j];
                
                long long l = j+1, r = n-1;
                
                while(l < r) {
                    long long total = nums[l] + nums[r];
                    
                    if(total < newtarget) {
                        l++;
                    } else if(total > newtarget) {
                        r--;
                    } else {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        res.push_back(temp);
                        
                        while(l < r && nums[l] == temp[2])
                            l++;
                        while(l < r && nums[r] == temp[3])
                            r--;
                    }
                }
                
                while(j+1 < n && nums[j+1] == nums[j])
                    j++;
            }
            
            while(i+1 < n && nums[i+1] == nums[i])
                i++;
        }
        
        return res;
    }
};