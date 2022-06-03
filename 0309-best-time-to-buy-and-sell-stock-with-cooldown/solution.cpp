class Solution {
public:
   
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int> prev2(n + 2, 0);
        vector<int> prev1(n + 2, 0);
        vector<int> cur(n + 2, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            
            cur[1] = max(-p[i] + prev1[0], 0 + prev1[1]);
            cur[0] = max(p[i] + prev2[1],  0 + prev1[0]);
            
            prev2 = prev1;
            prev1 = cur;

        }
        return cur[1];
    }
};
