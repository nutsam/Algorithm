class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy = 100000;
        for(int i = 0; i < prices.size(); ++i){
            buy = min(prices[i], buy);
            max_profit = max(max_profit, prices[i]-buy);
        }
        return max_profit;
    }
};