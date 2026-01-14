class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<pair<int, int>> points;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    points.push_back(make_pair(i, j));
                }
            }
        }
        
        for(auto pt: points) {
            int x = pt.first;
            int y = pt.second;
            
            for(int l = 0; l < m; l++)
                matrix[l][y] = 0;
            
            for(int k = 0; k < n; k++)
                matrix[x][k] = 0;
        }
    }
};

// Success
// Details 
// Runtime: 31 ms, faster than 45.64% of C++ online submissions for Set Matrix Zeroes.
// Memory Usage: 13.3 MB, less than 55.28% of C++ online submissions for Set Matrix Zeroes.