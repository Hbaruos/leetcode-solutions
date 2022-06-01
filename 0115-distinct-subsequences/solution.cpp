class Solution {
public:   
    int numDistinct(string s, string t) {
        vector<vector<double>> dp(s.size() + 1, vector<double> (t.size() + 1, 0));
        vector<double> prev(t.size() + 1, 0);
        
        prev[0] = 1;
        
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = t.size(); j >= 1; --j) {
                
                if (s[i - 1] == t[j - 1]) prev[j] = prev[j - 1] + prev[j];
                else prev[j] = prev[j];
                
            }
        }
        return (int)prev[t.size()];
    }
};
