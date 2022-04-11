class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        int m = g.size(); 
        int n = g[0].size();
        vector<vector<int>> res(g);
        while (k--) {
            for (int i = 0; i < m; ++i) {
                for (int j = 1; j < n; ++j) {
                    res[i][j] = g[i][j - 1];
                }
            }
            
            for (int i = 0; i < m - 1; ++i) 
                res[i+1][0] = g[i][n - 1];
            res[0][0] = g[m - 1][n - 1];
            g = res;
            
        }
        return res;
    }
};
