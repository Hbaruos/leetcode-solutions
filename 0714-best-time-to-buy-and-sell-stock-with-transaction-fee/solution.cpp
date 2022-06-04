class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<int> prev(2, 0);  aheadnotbuy, aheadbuy
        // vector<int> cur(2, 0);   curnotbuy, curbuy
        int aheadNotBuy, aheadBuy, curBuy, curNotBuy;
        
        
        // prev[0] = prev[1] = 0;
        aheadNotBuy = aheadBuy = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            
            curBuy = max(-prices[i] - fee + aheadNotBuy, 
                                0 + aheadBuy);
            
            curNotBuy = max(prices[i] + aheadBuy,
                                0 + aheadNotBuy);
         
            // prev = cur;
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        // return prev[1];
        return aheadBuy;
    }  

};
