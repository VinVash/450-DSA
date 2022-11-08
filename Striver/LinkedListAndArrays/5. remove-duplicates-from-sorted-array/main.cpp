int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    
    int i = 0;
    int j = i;
    
    int org = nums[0];
    int count = 0;
    
    while(j < n) {
        while(j+1 < n && nums[j+1] == org)
            j++;
        count++;
        nums[i] = nums[j];
        i++; j++;
        org = nums[j];
    }
    
    return count;
    
}