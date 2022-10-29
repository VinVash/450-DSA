class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(m == 0) return false; // since there is no element in the matrix.
        
        int r1 = 0, r2 = m-1; // pointing to the first and the last row.
        while(r1 < r2) {
            int mid = (r1 + r2) / 2;
            if(matrix[mid][0] > target)
                r2 = mid-1;
            else if(matrix[mid][n-1] < target)
                r1 = mid+1;
            else {
                r1 = mid;
                break; // we have the row which contains the target.
            }
        }
        
        int c1 = 0, c2 = n-1;
        while(c1 <= c2) {
            int mid = (c1 + c2) / 2;
            
            if(matrix[r1][mid] < target)
                c1 = mid+1;
            else if(matrix[r1][mid] > target)
                c2 = mid-1;
            else
                return true;
        }
        
        return false; // if nothing has been returned till now.
    }
};

// Success
// Details 
// Runtime: 4 ms, faster than 84.10% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 9.5 MB, less than 78.38% of C++ online submissions for Search a 2D Matrix.