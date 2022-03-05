class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> tmp(n);
        string s(n, '.');
        for (int i = 0; i < n; ++i) 
            tmp[i] = s;
        vector<bool> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        func(0, res, tmp, leftRow, upperDiagonal, lowerDiagonal, n);
        return res;
    }
    
    void func(int col, vector<vector<string>> &res, vector<string> &tmp, vector<bool> &leftRow, vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal, int n) {
        if (col == n) {
            res.push_back(tmp);
            return;
        }
        
        for (int row = 0; row < n; ++row) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                tmp[row][col] = 'Q';
                leftRow[row] = true;
                lowerDiagonal[row + col] = true;
                upperDiagonal[n - 1 + col - row] = true;
                func(col + 1, res, tmp, leftRow, upperDiagonal, lowerDiagonal, n);
                tmp[row][col] = '.';
                leftRow[row] = false;
                lowerDiagonal[row + col] = false;
                upperDiagonal[n - 1 + col - row] = false;
            }
        }
    }
    
};
