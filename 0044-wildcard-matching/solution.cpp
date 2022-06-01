class Solution {
public:
    
    int f(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (i == 0 && j == 0) return true;
        if (j == 0 && i > 0) return false;
        if (i == 0 && j > 0) { 
            for (int j1 = 1; j1 <= j; ++j1) 
                if (p[j1 - 1] != '*') return false;
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (p[j - 1] == s[i - 1] || p[j - 1] == '?') return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        if (p[j - 1] == '*') return dp[i][j] = f(i - 1, j, s, p, dp) | f(i, j - 1, s, p, dp);
        return dp[i][j] = 0;        
    }
    
    bool isMatch(string s, string p) {
        int x = s.size();
        int y = p.size();
        
        vector<vector<bool>> dp(x + 1, vector<bool> (y + 1, false));
        
        dp[0][0] = true;
        
        for (int i = 1; i <= x; ++i) dp[i][0] = false;
        for (int j = 1; j <= y; ++j) {
            int flag = true;
            for (int j1 = 1; j1 <= j; ++j1) {
                if (p[j1 - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*') dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                else dp[i][j] = false;
            }
        }
        
        return dp[x][y];
    }
};
