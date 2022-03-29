class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        vector<int> prev(mat[0].size(), 0), cur(mat[0].size(), 0);

        for (int j = 0; j < mat[0].size(); ++j)
            prev[j] = mat[0][j];

        for (int i = 1; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                int d = mat[i][j] + prev[j];
                int ld = mat[i][j];
                if (j - 1 >= 0) ld += prev[j - 1];
                else ld += 1e8;
                int rd = mat[i][j];
                if (j + 1 < mat[0].size()) rd += prev[j + 1];
                else rd += 1e8;
                cur[j] = min(d, min(ld, rd));
            }
            prev = cur;
        }
        int _min = 1e8;
        for (int j = 0; j < mat[0].size(); ++j)
            _min = min(_min, prev[j]);
        return _min;

        
    }
};
