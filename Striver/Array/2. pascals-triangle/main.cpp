class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        
        vector<vector<int>> ans(n);
        
        for(int i = 0; i < n; i++) {
            ans[i].resize(i+1); // since the ith row has i columns in pascal triangle.
            
            ans[i][0] = ans[i][i] = 1;
            
            for(int j = 1; j < i; j++) {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        
        return ans;
    }
};

// Success
// Details 
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
// Memory Usage: 6.5 MB, less than 70.28% of C++ online submissions for Pascal's Triangle.