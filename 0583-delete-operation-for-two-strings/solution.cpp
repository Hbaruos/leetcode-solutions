class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        vector<int> cur(n + 1, 0), prev(n + 1, 0);
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) cur[j] = 1 + prev[j - 1];
                else cur[j] = max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }
        
        int len = cur[n];
        return m + n - 2 * len;
    }
};
