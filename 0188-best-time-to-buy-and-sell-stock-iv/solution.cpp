class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<int> next(2*k + 1, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            for (int trn = 2*k - 1; trn >= 0; --trn) {
                
                if (trn % 2 == 0)
                    next[trn] = max(-p[i] + next[trn + 1], next[trn]);
                else
                    next[trn] = max(p[i] + next[trn + 1], next[trn]);
            }
        }
        return next[0];
    }         
};
