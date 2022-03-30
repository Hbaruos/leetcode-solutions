class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> dp(N, vector<int> (N, INT_MIN));
        dp[0][0] = grid[0][0];

        for (int t = 1; t <= 2*N - 2; ++t) {
            vector<vector<int>> dp2(N, vector<int> (N, INT_MIN));

            for (int i =max(0, t-(N-1)); i <= min(N-1, t); ++i) {
                for (int j = max(0, t-(N-1)); j <= min(N-1, t); ++j) {
                    if (grid[i][t-i] == -1 || grid[j][t-j] == -1) continue;
                    int val = grid[i][t-i];
                    if (i != j) val += grid[j][t-j];
                    for (int pi = i-1; pi <= i; ++pi)
                        for (int pj = j-1; pj <= j; ++pj)
                            if (pi >= 0 && pj >= 0)
                                dp2[i][j] = max(dp2[i][j], dp[pi][pj] + val);
                }
            }
            dp = dp2;
        }
        return max(0, dp[N-1][N-1]);
    }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         return max(0, f(0, 0, 0, 0, g, g.size(), g[0].size()));
//     }
    
//     int f(int i1, int i2, int j1, int j2, vector<vector<int>> &g, int r, int c) {
//         if (i1 >=r || i2 >= r || j1 >= c || j2 >= c || g[i1][j1] == -1 || g[i2][j2] == -1) return -1e8;
//         if (i1 ==  r - 1 && j1 == c - 1) return g[i1][j1];
//         if (i2 == r - 1 && j2 == c - 1) return g[i2][j2];
//         int value = 0;
//         if (i1 == i2 && j1 == j2) value = g[i1][j1];
//         else value = g[i1][j1] + g[i2][j2];
//         value += max(max(f(i1 + 1, i2 + 1, j1, j2, g, r, c), f(i1 + 1, i2, j1, j2 + 1, g, r, c)), max(f(i1, i2 + 1, j1 + 1, j2, g, r, c), f(i1, i2, j1 + 1, j2 + 1, g, r, c)));
//         return value;
    
//         return f(0, 0, 0, g, g.size(), g[0].size());
                
//     }
    
//     int f(int i, int j1, int j2, vector<vector<int>> &g, int r, int c) {
//         if (i >= r || j1 >= c || j2 >= c || g[i][j1] == -1 || g[i][j2] == -1) return -1e8;
//         if (i == r - 1) {
//             if (j1 == j2) return g[i][j1];
//             else return g[i][j1] + g[i][j2];
//         }
//         int _max = -1e8;
//         for (int di = 0; di <= 1; ++di) {
//             for (int dj1 = 0; dj1 <= 1; ++dj1) {
//                 for (int dj2 = 0; dj2 <= 1; ++dj2) {
//                     int val = 0;
//                     if (j1 == j2) val = g[i][j1];
//                     else val = g[i][j1] + g[i][j2];
//                     val += f(i + di, j1 + dj1, j2 + dj2, g, r, c);
//                     _max = max(_max, val);
//                 }
//             }
            
//         }
//         return _max;
        
//     }
    
};
