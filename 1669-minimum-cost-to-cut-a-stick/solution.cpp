class Solution {
public:
    
    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        vector<vector<int>> dp(size + 2, vector<int> (size + 2, 0));
            
        cuts.emplace_back(n);
        cuts.insert(cuts.begin(), 0);
        
        sort(cuts.begin(), cuts.end());
        
        for (int i = size; i >= 1; --i) {
            for (int j = 1; j <= size; ++j) {
                
                if (i > j) continue;
                int _minCost = INT_MAX;

                for (int k = i; k <= j; ++k) {
                    
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    
                    _minCost = min(_minCost, cost);
                }
                dp[i][j] = _minCost;
            }
        }
        
        return dp[1][size];
    }
};
