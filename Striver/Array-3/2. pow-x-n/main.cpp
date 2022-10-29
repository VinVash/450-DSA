class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        
        long long nn = n;
        if(n < 0)
            nn = -1 * nn;
        
        while(nn) {
            if(nn % 2 == 0) {
                x = x * x;
                nn /= 2;
            } else {
                ans = ans * x;
                nn -= 1;
            }
        }
        
        if(n < 0)
            ans = (double)(1.0) / (double)(ans);
        
        return ans;
    }
};

// Success
// Details 
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
// Memory Usage: 5.8 MB, less than 96.26% of C++ online submissions for Pow(x, n).