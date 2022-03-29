class Solution {
public:
    int cherryPickup(vector<vector<int>>& g) {
        int r = g.size();
        int c = g[0].size();
        
        // vector<vector<vector<int>>> prev(r, vector<vector<int>> (c, vector<int> (c, -1)));
       
        vector<vector<int>> prev(c, vector<int> (c, 0));
        vector<vector<int>> cur(c, vector<int> (c, 0));
        
        for (int j1 = 0; j1 < c; ++j1) {
            for (int j2 = 0; j2 < c; ++j2) {
                if (j1 == j2) prev[j1][j2] = g[r - 1][j1];
                else prev[j1][j2] = g[r-1][j1] + g[r-1][j2];
            }
        }
        
        for (int i = r - 2; i >= 0; --i) {
            for (int j1 = 0; j1 < c; ++j1) {
                for (int j2 = 0; j2 < c; ++j2) {
                    int _max = -1e8;
                    for (int dj1 = -1; dj1 <= +1; ++dj1) {
                        for (int dj2 = -1; dj2 <= +1; ++dj2) {
                            int value = 0;
                            if (j1 == j2) value = g[i][j1];
                            else value = g[i][j1] + g[i][j2];
                            if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)
                                value += prev[j1 + dj1][j2 + dj2];
                            else 
                                value += -1e8;
                            _max = max(_max, value);
                        }
                    }
                    cur[j1][j2] = _max;
                }
            }
            prev = cur;
        }
        return prev[0][c - 1];
        
    }
};
