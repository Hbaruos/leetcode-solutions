class Solution {
public:
    int f(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) return 0;
        if (s1[i] == s2[j]) return dp[i][j] = 1 + f(s1, s2, i - 1, j - 1, dp);
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = 0 + max(f(s1, s2, i - 1, j, dp), f(s1, s2, i, j - 1, dp));
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        int i = s1.size(), j = s2.size();
        vector<vector<int>> dp(i, vector<int> (j, -1));
        return f(s1, s2, i - 1, j - 1, dp);
        
    }    
};
