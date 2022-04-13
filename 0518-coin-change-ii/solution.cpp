class Solution {
public:
    int change(int amt, vector<int>& c) {
        vector<vector<int>> dp(c.size(), vector<int> (amt + 1, -1));
        vector<int> prev(amt + 1, 0), cur(amt + 1, 0);
        
        for (int i = 0; i <= amt; ++i)
            prev[i] = (i % c[0] == 0);
        
        for (int i = 1; i < c.size(); ++i) {
            for (int j = 0; j <= amt; ++j) {
                int cnt = 0;
                if (j >= c[i]) cnt = cur[j - c[i]];
                int not_cnt = prev[j];
                cur[j] = cnt + not_cnt;
            }
            prev = cur;
        }       
        return prev[amt];
    }
    
};
