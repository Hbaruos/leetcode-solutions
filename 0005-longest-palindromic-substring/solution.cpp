class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(size(s), vector<int> (size(s), 0));
        int l = 0, r = 1;    
        
        for (int i = 0; i < size(s); ++i)
            dp[i][i] = 1;
            
        for (int i = 0; i < size(s) - 1; ++i)
            if (s[i] == s[i + 1])
                dp[i][i + 1] = 1, l = i, r = 2;
                
        for (int j = 2; j < size(s); ++j) {
            for (int i = 0; i < size(s) - j; ++i) {
                
                int left = i;
                int right = i + j;
                
                if (s[left] == s[right] && dp[left + 1][right - 1]) {
                    dp[left][right] = 1; l = i; r = j + 1;
                }   
            }
        }
        return s.substr(l, r);
    }
};
