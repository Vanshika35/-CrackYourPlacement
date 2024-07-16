class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int miniCost = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size();  i++){
            profit = max(profit, prices[i]-miniCost);
            miniCost=min(miniCost, prices[i]);
        }
        return profit;
    }
};