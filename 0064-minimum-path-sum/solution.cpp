class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        vector<int> prev(g[0].size(), 0);
        for (int i = 0; i < g.size(); ++i) {
            vector<int> cur(g[0].size(), 0);
            for (int j = 0; j < g[0].size(); ++j) {
                if (i == 0 && j == 0) cur[j] = g[i][j];
                else {
                    int up = g[i][j];
                    if (i > 0) up += prev[j];
                    else up += 1e9;
                    int left = g[i][j];
                    if (j > 0) left += cur[j - 1];
                    else left += 1e9;
                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[g[0].size() - 1];
    }
    
    // int func(int m, int n, vector<vector<int>> &g, vector<vector<int>> &dp) {
    //     if (m == 0 && n == 0) return g[m][n];
    //     if (m < 0 || n < 0) return INT_MAX/2;
    //     if (dp[m][n]) return dp[m][n];
    //     int up = g[m][n] + func(m - 1, n, g, dp);
    //     int left = g[m][n] + func(m, n - 1, g, dp);
    //     dp[m][n] = min(up, left);
    //     return dp[m][n];
    // }
    
};
