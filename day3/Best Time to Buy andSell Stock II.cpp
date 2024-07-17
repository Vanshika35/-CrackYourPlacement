class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int maxx = 0;
      int start = prices[0];
      int len = prices.size();
      for(int i =1; i < len; i++){
        if(start < prices[i]){
            maxx += prices[i] - start;  
        }
        start = prices[i];
      }
      return maxx;
    }
};