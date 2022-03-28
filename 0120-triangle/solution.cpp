class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<int> dp(n);
        
        for (int j = 0; j < n; ++j)
            dp[j] = t[n - 1][j];
        
        for (int i = n - 2; i >= 0; --i) {
            vector<int> cur(n);
            for (int j = i; j >= 0; --j) {
                int dwn = t[i][j] + dp[j];
                int diag = t[i][j] + dp[j + 1];
                cur[j] = min(dwn, diag);
            }
            dp = cur;
        }
        return dp[0];
    }
};
