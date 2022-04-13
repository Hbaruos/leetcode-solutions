class Solution {
public:
    
    // same as partition with given difference
    
    int findTargetSumWays(vector<int>& n, int tar) {
        int sum = accumulate(n.begin(), n.end(), 0);
        if (sum - tar < 0 || (sum - tar) % 2) return false;
        return f(n, (sum - tar)/2); 
    }
    
    int f(vector<int> &n, int tar) {
        int m = n.size();
        vector<int> prev(tar + 1, 0), cur(tar + 1, 0);
        if (n[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        
        if (n[0] != 0 && n[0] <= tar) prev[n[0]] = 1;
        
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j <= tar; ++j) {
                int cnt = 0;
                if (n[i] <= j) cnt = prev[j - n[i]];
                int not_cnt = prev[j];
                
                cur[j] = cnt + not_cnt;
            }
            prev = cur;
        }
        return prev[tar];
    }
    
};
