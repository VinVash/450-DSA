class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n-1; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            while(i+1 < n && intervals[i+1][0] <= end) {
                end = intervals[i+1][1];
                i++;
            }
            
            vector<int> temp;
            temp.push_back(start);
            temp.push_back(end);
            ans.push_back(temp);
        }
        
        if(intervals[n-1][1] != ans[ans.size()-1][1])
            ans.push_back(intervals[n-1]);

         return ans;
    }
};