class Solution {
public:    
    bool static comp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }
    
    bool isValid(string &s1, string &s2) {
        if (size(s1) != size(s2) + 1) return false;
        int i = 0, j = 0;
        while (i < size(s1)) {
            if (j < size(s2) && s1[i] == s2[j]) i++, j++;
            else i++;
        }
        if (i == size(s1) && j == size(s2)) return true;
        else return false;
    }    
    
    int longestStrChain(vector<string>& words) {
        sort(begin(words), end(words), comp);
        int n = size(words);
        vector<int> dp(n, 1);
        int len = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isValid(words[i], words[j]) && 1 + dp[j] > dp[i])
                    dp[i] = 1 + dp[j];
            }
            len = max(len, dp[i]);
        }
        return len;
    }
};
