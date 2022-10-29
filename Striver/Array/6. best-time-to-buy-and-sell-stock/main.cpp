class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int maxi = prices[0]; // we want to maximise sell, so name it as maxi.
        int buy = prices[0];
        
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            if(prices[i] > buy) {
                maxi = prices[i];
                ans = max(ans, maxi - buy);
            }
            
            if(prices[i] < buy)
                buy = prices[i];
        }
        
        return ans;
    }
};

// Success
// Details 
// Runtime: 151 ms, faster than 87.20% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 93.2 MB, less than 98.99% of C++ online submissions for Best Time to Buy and Sell Stock.