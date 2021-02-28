class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit=0;
        int minval=INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minval)
                minval = prices[i];
            else if (prices[i] - minval > profit)
                profit = prices[i] - minval;
        }        
        
        return profit;
    }
};