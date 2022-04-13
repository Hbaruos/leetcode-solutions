class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int N = 0;
        vector<vector<int>> v(n, vector<int> (n, 0));
        
        int rs = 0, cs = 0;
        int re = n - 1, ce = n - 1;
        
        while (rs <= re && cs <= ce) {
            
            for (int i = cs; i <= ce; ++i) 
                v[rs][i] = ++N;
            rs++;

            for (int i = rs; i <= re; ++i) 
                v[i][ce] = ++N;
            ce--;

            for (int i = ce; i >= cs; --i) 
                v[re][i] = ++N;
            re--;

            for (int i = re; i >= rs; --i) 
                v[i][cs] = ++N;
            cs++;
        }
        return v;
    }
};
