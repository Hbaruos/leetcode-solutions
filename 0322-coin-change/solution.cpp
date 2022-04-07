class Solution {
public:
    int coinChange(vector<int>& c, int amt) {
        vector<int> prev(amt + 1, 0), cur(amt + 1, 0);
        for (int i = 0; i <= amt; ++i) {
            if (i % c[0]) prev[i] = 1e9;
            else prev[i] = i / c[0];
        }
            
        for (int i = 1; i < c.size(); ++i) {
            for (int j = 1; j <= amt; ++j) {
                int pick = INT_MAX;
                if (j >= c[i]) pick = 1 + cur[j - c[i]];
                int n_pick = 0 + prev[j];
                cur[j] = min(pick, n_pick);
            }
            prev = cur;
        }
        int ans = prev[amt];
        if (ans >= 1e9) return -1;
        return ans;
    }    
};
