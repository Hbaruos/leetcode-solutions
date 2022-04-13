class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int n1 = m.size(), n2 = n1 ? m[0].size() : 0;
        vector<int> ans(n1 * n2, 0);
        
        int rs = 0, cs = 0;
        int re = n1 - 1, ce = n2 - 1;
        int x = -1;
        
        while (rs <= re && cs <= ce) {
            
            for (int i = cs; i <= ce; ++i) 
                ans[++x] = m[rs][i];
            if (++rs > re) break;
            
            for (int i = rs; i <= re; ++i)
                ans[++x] = m[i][ce];
            if (--ce < cs) break;
            
            for (int i = ce; i >= cs; --i) 
                ans[++x] = m[re][i];
            if (--re < rs) break;
            
            for (int i = re; i >= rs; --i)
                ans[++x] = m[i][cs];
            if (++cs > ce) break;
        }
        return ans;
    }
};
