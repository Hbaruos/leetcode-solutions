class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        int sell = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            }
            sell = prices[i] - buy;
            if (profit < sell) {
                profit = sell;
            }
        }
        return profit;
    }
};
