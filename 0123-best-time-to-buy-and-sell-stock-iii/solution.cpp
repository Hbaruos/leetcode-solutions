class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        // vector<vector<int>> dp(n + 1, vector<int> (4 + 1, 0));
        // vector<int> ahead(5, 0), cur(5, 0);
        vector<int> next(5, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            for (int trn = 3; trn >= 0; --trn) {
                
                if (trn == 0 || trn == 2)
                    next[trn] = max(-p[i] + next[trn + 1], next[trn]);
                else
                    next[trn] = max(p[i] + next[trn + 1], next[trn]);
            }
        }
        return next[0];
    }
};
