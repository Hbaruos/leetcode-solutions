class Solution {
public:
    
    // int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    //     if (i == 0) return j;
    //     if (j == 0) return i;
    //     if (dp[i][j] != -1) return dp[i][j];
    //     if (s1[i] == s2[j]) return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
    //     return dp[i][j] = 1 + min(f(i, j - 1, s1, s2, dp), min(f(i - 1, j, s1, s2, dp), f(i - 1, j - 1, s1, s2, dp)));
    // }
    
    int minDistance(string s1, string s2) {
        int x = s1.size(), y = s2.size();
        vector<int> prev(y + 1, 0), cur(y + 1, 0);
        
        for (int i = 0; i <= y; ++i) prev[i] = i;   
        
        for (int i = 1; i <= x; ++i) {
            cur[0] = i;
            for (int j = 1; j <= y; ++j) {
                
                if (s1[i - 1] == s2[j - 1]) cur[j] = prev[j - 1];
                else cur[j] = 1 + min({cur[j - 1], prev[j], prev[j - 1]});
                
            }
            prev = cur;
        }
        
        return prev[y];
    }
};
