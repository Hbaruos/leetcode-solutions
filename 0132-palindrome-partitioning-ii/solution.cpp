class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--]) return false;
        return true;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int minPartition = INT_MAX;

            for (int j = i; j < n; ++j) {
                if (isPalindrome(s, i, j)) {
                    int partition = 1 + dp[j + 1]; 
                    minPartition = min(minPartition, partition);
                }
            }
            dp[i] = minPartition;
        }
        
        return dp[0] - 1;
    }
};
