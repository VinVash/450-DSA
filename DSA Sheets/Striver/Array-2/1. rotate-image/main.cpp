class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i ; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

// Success
// Details 
// Runtime: 10 ms, faster than 7.11% of C++ online submissions for Rotate Image.
// Memory Usage: 7.2 MB, less than 33.64% of C++ online submissions for Rotate Image.