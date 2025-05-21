class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0], maxProfit=0;
        for (int i = 0; i < prices.size(); i++) {
            buyPrice = min(prices[i], buyPrice);
            maxProfit = max(maxProfit, prices[i] - buyPrice);
        }
        return maxProfit;
    }
};